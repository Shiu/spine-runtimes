import { Type, Member, toSnakeCase, toCFunctionName, toCTypeName, Exclusion } from '../types';
import { isMethodExcluded } from '../exclusions';
import { GeneratorResult } from './constructor-generator';

export class MethodGenerator {
    constructor(private exclusions: Exclusion[]) {}
    
    generate(type: Type): GeneratorResult {
        const declarations: string[] = [];
        const implementations: string[] = [];
        
        if (!type.members) return { declarations, implementations };
        
        const methods = type.members.filter(m => 
            m.kind === 'method' && 
            !m.isStatic &&
            !isMethodExcluded(type.name, m.name, this.exclusions)
        );
        
        const cTypeName = `spine_${toSnakeCase(type.name)}`;
        
        for (const method of methods) {
            // Handle getters
            if (method.name.startsWith('get') && (!method.parameters || method.parameters.length === 0)) {
                const propName = method.name.substring(3);
                const funcName = toCFunctionName(type.name, method.name);
                const returnType = toCTypeName(method.returnType || 'void');
                
                declarations.push(`SPINE_C_EXPORT ${returnType} ${funcName}(${cTypeName} obj);`);
                
                implementations.push(`${returnType} ${funcName}(${cTypeName} obj) {`);
                implementations.push(`    if (!obj) return ${this.getDefaultReturn(returnType)};`);
                implementations.push(`    ${type.name} *_obj = (${type.name} *) obj;`);
                
                const callExpr = this.generateMethodCall('_obj', method);
                implementations.push(`    return ${callExpr};`);
                implementations.push(`}`);
                implementations.push('');
                
                // Generate collection accessors if return type is Vector
                if (method.returnType && method.returnType.includes('Vector<')) {
                    this.generateCollectionAccessors(type, method, propName, declarations, implementations);
                }
            }
            // Handle setters
            else if (method.name.startsWith('set') && method.parameters && method.parameters.length === 1) {
                const funcName = toCFunctionName(type.name, method.name);
                const paramType = toCTypeName(method.parameters[0].type);
                
                declarations.push(`SPINE_C_EXPORT void ${funcName}(${cTypeName} obj, ${paramType} value);`);
                
                implementations.push(`void ${funcName}(${cTypeName} obj, ${paramType} value) {`);
                implementations.push(`    if (!obj) return;`);
                implementations.push(`    ${type.name} *_obj = (${type.name} *) obj;`);
                
                const callExpr = this.generateSetterCall('_obj', method, 'value');
                implementations.push(`    ${callExpr};`);
                implementations.push(`}`);
                implementations.push('');
            }
            // Handle other methods
            else {
                const funcName = toCFunctionName(type.name, method.name);
                const returnType = toCTypeName(method.returnType || 'void');
                const params = this.generateMethodParameters(cTypeName, method);
                
                declarations.push(`SPINE_C_EXPORT ${returnType} ${funcName}(${params.declaration});`);
                
                implementations.push(`${returnType} ${funcName}(${params.declaration}) {`);
                implementations.push(`    if (!obj) return ${this.getDefaultReturn(returnType)};`);
                implementations.push(`    ${type.name} *_obj = (${type.name} *) obj;`);
                
                const callExpr = this.generateMethodCall('_obj', method, params.call);
                if (returnType === 'void') {
                    implementations.push(`    ${callExpr};`);
                } else {
                    implementations.push(`    return ${callExpr};`);
                }
                implementations.push(`}`);
                implementations.push('');
            }
        }
        
        return { declarations, implementations };
    }
    
    private generateCollectionAccessors(type: Type, method: Member, propName: string, 
                                      declarations: string[], implementations: string[]) {
        const cTypeName = `spine_${toSnakeCase(type.name)}`;
        const propSnake = toSnakeCase(propName);
        const vectorMatch = method.returnType!.match(/Vector<(.+?)>/);
        if (!vectorMatch) return;
        
        const elementType = vectorMatch[1].trim().replace(/\s*\*$/, '');
        let cElementType: string;
        if (elementType === 'int') {
            cElementType = 'int32_t';
        } else {
            cElementType = `spine_${toSnakeCase(elementType)}`;
        }
        
        // Get count function
        const getCountFunc = `spine_${toSnakeCase(type.name)}_get_num_${propSnake}`;
        declarations.push(`SPINE_C_EXPORT int32_t ${getCountFunc}(${cTypeName} obj);`);
        
        implementations.push(`int32_t ${getCountFunc}(${cTypeName} obj) {`);
        implementations.push(`    if (!obj) return 0;`);
        implementations.push(`    ${type.name} *_obj = (${type.name} *) obj;`);
        implementations.push(`    return (int32_t) _obj->get${propName}().size();`);
        implementations.push(`}`);
        implementations.push('');
        
        // Get array function
        const getArrayFunc = `spine_${toSnakeCase(type.name)}_get_${propSnake}`;
        declarations.push(`SPINE_C_EXPORT ${cElementType} *${getArrayFunc}(${cTypeName} obj);`);
        
        implementations.push(`${cElementType} *${getArrayFunc}(${cTypeName} obj) {`);
        implementations.push(`    if (!obj) return nullptr;`);
        implementations.push(`    ${type.name} *_obj = (${type.name} *) obj;`);
        implementations.push(`    return (${cElementType} *) _obj->get${propName}().buffer();`);
        implementations.push(`}`);
        implementations.push('');
    }
    
    private generateMethodCall(objName: string, method: Member, args?: string): string {
        let call = `${objName}->${method.name}(${args || ''})`;
        
        // Handle return type conversions
        if (method.returnType) {
            if (method.returnType === 'const String &' || method.returnType === 'String') {
                call = `(const utf8 *) ${call}.buffer()`;
            } else if (method.returnType === 'const spine::RTTI &' || method.returnType === 'const RTTI &') {
                // RTTI needs special handling - return as opaque pointer
                call = `(spine_rtti) &${call}`;
            } else if (method.returnType.includes('*')) {
                const cType = toCTypeName(method.returnType);
                call = `(${cType}) ${call}`;
            } else if (method.returnType === 'Color &' || method.returnType === 'const Color &') {
                call = `(spine_color) &${call}`;
            }
        }
        
        return call;
    }
    
    private generateSetterCall(objName: string, method: Member, valueName: string): string {
        const param = method.parameters![0];
        let value = valueName;
        
        // Convert from C type to C++
        if (param.type === 'const String &' || param.type === 'String') {
            value = `String(${valueName})`;
        } else if (param.type.includes('Vector<')) {
            // Vector types are passed as void* and need to be cast back
            value = `(${param.type}) ${valueName}`;
        } else if (param.type.includes('*')) {
            value = `(${param.type}) ${valueName}`;
        }
        
        return `${objName}->${method.name}(${value})`;
    }
    
    private generateMethodParameters(objTypeName: string, method: Member): { declaration: string; call: string } {
        const declParts = [`${objTypeName} obj`];
        const callParts: string[] = [];
        
        if (method.parameters) {
            for (const param of method.parameters) {
                const cType = toCTypeName(param.type);
                declParts.push(`${cType} ${param.name}`);
                
                // Convert C type back to C++ for the call
                let callExpr = param.name;
                if (param.type === 'const String &' || param.type === 'String') {
                    callExpr = `String(${param.name})`;
                } else if (param.type.includes('Vector<')) {
                    // Vector types are passed as void* and need to be cast back
                    callExpr = `(${param.type}) ${param.name}`;
                } else if (param.type.includes('*')) {
                    callExpr = `(${param.type}) ${param.name}`;
                }
                
                callParts.push(callExpr);
            }
        }
        
        return {
            declaration: declParts.join(', '),
            call: callParts.join(', ')
        };
    }
    
    private getDefaultReturn(returnType: string): string {
        if (returnType === 'void') return '';
        if (returnType === 'spine_bool') return '0';
        if (returnType.includes('int') || returnType === 'float' || returnType === 'double') return '0';
        return 'nullptr';
    }
}