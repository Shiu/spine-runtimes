import { Type, Member, toSnakeCase, toCFunctionName, toCTypeName } from '../types';

export interface GeneratorResult {
    declarations: string[];
    implementations: string[];
}

export class ConstructorGenerator {
    generate(type: Type): GeneratorResult {
        const declarations: string[] = [];
        const implementations: string[] = [];
        
        if (!type.members) return { declarations, implementations };
        
        const constructors = type.members.filter(m => m.kind === 'constructor');
        const cTypeName = `spine_${toSnakeCase(type.name)}`;
        
        // Skip constructor generation for abstract types
        if (!type.isAbstract) {
            // Generate create functions for each constructor
            let constructorIndex = 0;
            for (const constructor of constructors) {
            const funcName = this.getCreateFunctionName(type.name, constructor, constructorIndex);
            const params = this.generateParameters(constructor);
            
            // Declaration
            declarations.push(`SPINE_C_EXPORT ${cTypeName} ${funcName}(${params.declaration});`);
            
            // Implementation
            implementations.push(`${cTypeName} ${funcName}(${params.declaration}) {`);
            implementations.push(`    ${type.name} *obj = new (__FILE__, __LINE__) ${type.name}(${params.call});`);
            implementations.push(`    return (${cTypeName}) obj;`);
            implementations.push(`}`);
            implementations.push('');
            
                constructorIndex++;
            }
        }
        
        // Always generate dispose function
        declarations.push(`SPINE_C_EXPORT void ${cTypeName}_dispose(${cTypeName} obj);`);
        
        implementations.push(`void ${cTypeName}_dispose(${cTypeName} obj) {`);
        implementations.push(`    if (!obj) return;`);
        implementations.push(`    delete (${type.name} *) obj;`);
        implementations.push(`}`);
        implementations.push('');
        
        return { declarations, implementations };
    }
    
    private getCreateFunctionName(typeName: string, constructor: Member, index: number): string {
        const baseName = `spine_${toSnakeCase(typeName)}_create`;
        
        if (!constructor.parameters || constructor.parameters.length === 0) {
            return baseName;
        }
        
        if (index === 0) {
            return baseName;
        }
        
        // Generate name based on parameter types
        const paramNames = constructor.parameters
            .map(p => this.getParamTypeSuffix(p.type))
            .join('_');
        
        return `${baseName}_with_${paramNames}`;
    }
    
    private getParamTypeSuffix(type: string): string {
        if (type.includes('float')) return 'float';
        if (type.includes('int')) return 'int';
        if (type.includes('bool')) return 'bool';
        if (type.includes('String') || type.includes('char')) return 'string';
        
        // Extract class name from pointers/references
        const match = type.match(/(?:const\s+)?(\w+)(?:\s*[*&])?/);
        if (match) {
            return toSnakeCase(match[1]);
        }
        
        return 'param';
    }
    
    private generateParameters(constructor: Member): { declaration: string; call: string } {
        if (!constructor.parameters || constructor.parameters.length === 0) {
            return { declaration: 'void', call: '' };
        }
        
        const declParts: string[] = [];
        const callParts: string[] = [];
        
        for (const param of constructor.parameters) {
            const cType = toCTypeName(param.type);
            declParts.push(`${cType} ${param.name}`);
            
            // Convert C type back to C++ for the call
            let callExpr = param.name;
            if (param.type === 'const String &' || param.type === 'String') {
                callExpr = `String(${param.name})`;
            } else if (param.type.includes('*')) {
                callExpr = `(${param.type}) ${param.name}`;
            } else if (param.type.includes('&')) {
                // Handle reference types - need to dereference the pointer
                const baseType = param.type.replace(/^(?:const\s+)?(.+?)\s*&$/, '$1').trim();
                callExpr = `*(${baseType}*) ${param.name}`;
            }
            
            callParts.push(callExpr);
        }
        
        return {
            declaration: declParts.join(', '),
            call: callParts.join(', ')
        };
    }
}