import { Type, toSnakeCase } from '../types';

export class EnumGenerator {
    generate(enumType: Type): string[] {
        const lines: string[] = [];
        const enumName = `spine_${toSnakeCase(enumType.name)}`;
        
        lines.push(`typedef enum ${enumName} {`);
        
        if (enumType.values) {
            for (let i = 0; i < enumType.values.length; i++) {
                const value = enumType.values[i];
                const cName = `SPINE_${toSnakeCase(enumType.name).toUpperCase()}_${toSnakeCase(value.name).toUpperCase()}`;
                
                if (value.value !== undefined) {
                    lines.push(`    ${cName} = ${value.value}${i < enumType.values.length - 1 ? ',' : ''}`);
                } else {
                    lines.push(`    ${cName}${i < enumType.values.length - 1 ? ',' : ''}`);
                }
            }
        }
        
        lines.push(`} ${enumName};`);
        
        return lines;
    }
}