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
            !isMethodExcluded(type.name, m.name, this.exclusions, m)
        );
        
        // Check for const/non-const method pairs
        const methodGroups = new Map<string, Member[]>();
        for (const method of methods) {
            const key = method.name + '(' + (method.parameters?.map(p => p.type).join(',') || '') + ')';
            if (!methodGroups.has(key)) {
                methodGroups.set(key, []);
            }
            methodGroups.get(key)!.push(method);
        }
        
        // Collect all errors before failing
        const errors: string[] = [];
        
        // Report errors for duplicate methods with different signatures
        for (const [signature, group] of methodGroups) {
            if (group.length > 1) {
                // Check if we have different return types (const vs non-const overloading)
                const returnTypes = new Set(group.map(m => m.returnType));
                if (returnTypes.size > 1) {
                    let error = `\nERROR: Type '${type.name}' has multiple versions of method '${group[0].name}' with different return types:\n`;
                    error += `This is likely a const/non-const overload pattern in C++ which cannot be represented in C.\n\n`;
                    
                    for (const method of group) {
                        const source = method.fromSupertype ? ` (inherited from ${method.fromSupertype})` : '';
                        error += `  - ${method.returnType || 'void'} ${method.name}()${source}\n`;
                    }
                    error += `\nC++ pattern detected:\n`;
                    error += `  T& ${group[0].name}()         { return member; }  // for non-const objects\n`;
                    error += `  const T& ${group[0].name}() const { return member; }  // for const objects\n`;
                    error += `\nThis pattern provides const-correctness in C++ but cannot be represented in C.\n`;
                    error += `Consider:\n`;
                    error += `  1. Only exposing the const version in the C API\n`;
                    error += `  2. Renaming one of the methods in C++\n`;
                    error += `  3. Adding the method to exclusions.txt\n`;
                    
                    errors.push(error);
                }
            }
        }
        
        // If we have errors, throw them all at once
        if (errors.length > 0) {
            console.error("=".repeat(80));
            console.error("CONST/NON-CONST METHOD CONFLICTS FOUND");
            console.error("=".repeat(80));
            for (const error of errors) {
                console.error(error);
            }
            console.error("=".repeat(80));
            console.error(`Total conflicts found: ${errors.length}`);
            console.error("=".repeat(80));
            throw new Error(`Cannot generate C API due to ${errors.length} const/non-const overloaded method conflicts.`);
        }
        
        // For now, continue with the unique methods
        const uniqueMethods = methods;
        
        const cTypeName = `spine_${toSnakeCase(type.name)}`;
        
        // Track method names to detect overloads
        const methodCounts = new Map<string, number>();
        for (const method of uniqueMethods) {
            const count = methodCounts.get(method.name) || 0;
            methodCounts.set(method.name, count + 1);
        }
        
        // Track how many times we've seen each method name
        const methodSeenCounts = new Map<string, number>();
        
        for (const method of uniqueMethods) {
            // Handle getters
            if (method.name.startsWith('get') && (!method.parameters || method.parameters.length === 0)) {
                const propName = method.name.substring(3);
                
                // Check if return type is Vector
                if (method.returnType && method.returnType.includes('Vector<')) {
                    // For Vector types, only generate collection accessors
                    this.generateCollectionAccessors(type, method, propName, declarations, implementations);
                } else if (method.name === 'getRTTI') {
                    // Special handling for getRTTI - make it static
                    const funcName = toCFunctionName(type.name, 'get_rtti');
                    const returnType = 'spine_rtti';
                    
                    declarations.push(`SPINE_C_EXPORT ${returnType} ${funcName}();`);
                    
                    implementations.push(`${returnType} ${funcName}() {`);
                    implementations.push(`    return (spine_rtti) &${type.name}::rtti;`);
                    implementations.push(`}`);
                    implementations.push('');
                } else {
                    // For non-Vector types, generate regular getter
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
                // Check if this is an overloaded method
                const isOverloaded = (methodCounts.get(method.name) || 0) > 1;
                const seenCount = methodSeenCounts.get(method.name) || 0;
                methodSeenCounts.set(method.name, seenCount + 1);
                
                // Generate function name with suffix for overloads
                let funcName = toCFunctionName(type.name, method.name);
                
                // Check for naming conflicts with type names
                if (method.name === 'pose' && type.name === 'Bone') {
                    // Rename bone_pose() method to avoid conflict with spine_bone_pose type
                    funcName = toCFunctionName(type.name, 'update_pose');
                }
                
                if (isOverloaded && seenCount > 0) {
                    // Add parameter count suffix for overloaded methods
                    const paramCount = method.parameters ? method.parameters.length : 0;
                    funcName = `${funcName}_${paramCount}`;
                }
                
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
        } else if (elementType === 'float') {
            cElementType = 'float';
        } else if (elementType === 'uint8_t') {
            cElementType = 'uint8_t';
        } else if (elementType === 'String') {
            cElementType = 'const utf8 *';
        } else if (elementType === 'PropertyId') {
            cElementType = 'int32_t';  // PropertyId is just an int
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
        
        // Handle const vs non-const vectors
        if (method.isConst || method.returnType!.includes('const')) {
            // For const vectors, we need to copy the data or use data() method
            implementations.push(`    auto& vec = _obj->get${propName}();`);
            implementations.push(`    if (vec.size() == 0) return nullptr;`);
            implementations.push(`    return (${cElementType} *) &vec[0];`);
        } else {
            implementations.push(`    return (${cElementType} *) _obj->get${propName}().buffer();`);
        }
        
        implementations.push(`}`);
        implementations.push('');
    }
    
    private generateMethodCall(objName: string, method: Member, args?: string): string {
        let call = `${objName}->${method.name}(${args || ''})`;
        
        // Handle return type conversions
        if (method.returnType) {
            if (method.returnType === 'const String &' || method.returnType === 'String') {
                call = `(const utf8 *) ${call}.buffer()`;
            } else if (method.returnType === 'const RTTI &' || method.returnType === 'RTTI &') {
                // RTTI needs special handling - return as opaque pointer
                call = `(spine_rtti) &${call}`;
            } else if (method.returnType.includes('*')) {
                const cType = toCTypeName(method.returnType);
                call = `(${cType}) ${call}`;
            } else if (method.returnType === 'Color &' || method.returnType === 'const Color &') {
                call = `(spine_color) &${call}`;
            } else if (method.returnType.includes('&')) {
                // For reference returns, take the address
                const cType = toCTypeName(method.returnType);
                call = `(${cType}) &${call}`;
            } else if (!this.isPrimitiveType(method.returnType) && !this.isEnumType(method.returnType)) {
                // For non-primitive value returns (e.g., BoneLocal), take the address
                const cType = toCTypeName(method.returnType);
                call = `(${cType}) &${call}`;
            } else if (this.isEnumType(method.returnType)) {
                // Cast enum return values
                const cType = toCTypeName(method.returnType);
                call = `(${cType}) ${call}`;
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
        } else if (param.type.includes('&') && !param.type.includes('const')) {
            // Non-const reference parameters need to dereference the C pointer
            const baseType = param.type.replace(/\s*&\s*$/, '').trim();
            value = `*((${baseType}*) ${valueName})`;
        } else if (this.isEnumType(param.type)) {
            // Cast enum types
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
                } else if (param.type.includes('&')) {
                    // Handle reference types
                    const isConst = param.type.startsWith('const');
                    const baseType = param.type.replace(/^(?:const\s+)?(.+?)\s*&$/, '$1').trim();
                    
                    // Non-const references to primitive types are output parameters - just pass the pointer
                    if (!isConst && ['float', 'int', 'double', 'bool'].includes(baseType)) {
                        callExpr = `*${param.name}`;
                    } else {
                        // Const references and non-primitive types need dereferencing
                        callExpr = `*(${baseType}*) ${param.name}`;
                    }
                } else if (this.isEnumType(param.type)) {
                    // Cast enum types
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
        if (returnType === 'bool') return 'false';
        if (returnType.includes('int') || returnType === 'float' || returnType === 'double' || returnType === 'size_t') return '0';
        // Check if it's an enum type (spine_* types that are not pointers)
        if (returnType.startsWith('spine_') && !returnType.includes('*')) {
            // Cast 0 to the enum type
            return `(${returnType}) 0`;
        }
        return 'nullptr';
    }
    
    private isEnumType(type: string): boolean {
        // List of known enum types in spine-cpp
        const enumTypes = [
            'EventType', 'Format', 'TextureFilter', 'TextureWrap',
            'AttachmentType', 'BlendMode', 'Inherit', 'MixBlend',
            'MixDirection', 'Physics', 'PositionMode', 'Property',
            'RotateMode', 'SequenceMode', 'SpacingMode'
        ];
        return enumTypes.includes(type);
    }
    
    private isPrimitiveType(type: string): boolean {
        return ['int', 'float', 'double', 'bool', 'size_t', 'int32_t', 'uint32_t', 
                'int16_t', 'uint16_t', 'uint8_t', 'void'].includes(type);
    }
}