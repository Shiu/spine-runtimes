import { Type, toSnakeCase } from '../types';
import { getTypeHierarchy, getLeafTypes } from '../rtti';
import { GeneratorResult } from './constructor-generator';

export class RttiGenerator {
    constructor(
        private rttiBases: Set<string>,
        private allTypes: Type[]
    ) {}
    
    needsRtti(type: Type): boolean {
        const hierarchy = getTypeHierarchy(type, this.allTypes);
        return hierarchy.some(t => this.rttiBases.has(t));
    }
    
    generateForType(baseType: Type): GeneratorResult {
        const declarations: string[] = [];
        const implementations: string[] = [];
        
        // Only generate RTTI for base types in rttiBases
        if (!this.rttiBases.has(baseType.name)) {
            return { declarations, implementations };
        }
        
        const leafTypes = getLeafTypes(baseType.name, this.allTypes);
        const baseSnake = toSnakeCase(baseType.name);
        const enumName = `spine_${baseSnake}_type`;
        
        // Add forward declarations for all leaf types
        for (const leafType of leafTypes) {
            const leafTypeName = `spine_${toSnakeCase(leafType.name)}`;
            declarations.push(`struct ${leafTypeName}_wrapper;`);
            declarations.push(`typedef struct ${leafTypeName}_wrapper *${leafTypeName};`);
        }
        declarations.push('');
        
        // Generate enum
        declarations.push(`typedef enum ${enumName} {`);
        leafTypes.forEach((type, index) => {
            const enumValue = `SPINE_TYPE_${baseSnake.toUpperCase()}_${toSnakeCase(type.name).toUpperCase()}`;
            declarations.push(`    ${enumValue} = ${index}${index < leafTypes.length - 1 ? ',' : ''}`);
        });
        declarations.push(`} ${enumName};`);
        declarations.push('');
        
        // Generate is_type method
        const isTypeFunc = `spine_${baseSnake}_is_type`;
        declarations.push(`SPINE_C_EXPORT spine_bool ${isTypeFunc}(spine_${baseSnake} obj, ${enumName} type);`);
        
        implementations.push(`spine_bool ${isTypeFunc}(spine_${baseSnake} obj, ${enumName} type) {`);
        implementations.push(`    if (!obj) return 0;`);
        implementations.push(`    ${baseType.name} *_obj = (${baseType.name} *) obj;`);
        implementations.push(`    `);
        implementations.push(`    switch (type) {`);
        
        leafTypes.forEach((type, index) => {
            const enumValue = `SPINE_TYPE_${baseSnake.toUpperCase()}_${toSnakeCase(type.name).toUpperCase()}`;
            implementations.push(`        case ${enumValue}:`);
            implementations.push(`            return _obj->getRTTI().instanceOf(${type.name}::rtti);`);
        });
        
        implementations.push(`    }`);
        implementations.push(`    return 0;`);
        implementations.push(`}`);
        implementations.push('');
        
        // Generate cast methods for each leaf type
        for (const leafType of leafTypes) {
            const castFunc = `spine_${baseSnake}_as_${toSnakeCase(leafType.name)}`;
            const returnType = `spine_${toSnakeCase(leafType.name)}`;
            
            declarations.push(`SPINE_C_EXPORT ${returnType} ${castFunc}(spine_${baseSnake} obj);`);
            
            implementations.push(`${returnType} ${castFunc}(spine_${baseSnake} obj) {`);
            implementations.push(`    if (!obj) return nullptr;`);
            implementations.push(`    ${baseType.name} *_obj = (${baseType.name} *) obj;`);
            implementations.push(`    if (!_obj->getRTTI().instanceOf(${leafType.name}::rtti)) return nullptr;`);
            implementations.push(`    return (${returnType}) obj;`);
            implementations.push(`}`);
            implementations.push('');
        }
        
        return { declarations, implementations };
    }
}