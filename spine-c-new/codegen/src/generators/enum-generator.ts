import { Type, toSnakeCase } from '../types';

export class EnumGenerator {
    generate(enumType: Type): string[] {
        const lines: string[] = [];
        const enumName = `spine_${toSnakeCase(enumType.name)}`;
        
        lines.push(`typedef enum ${enumName} {`);
        
        if (enumType.values) {
            for (let i = 0; i < enumType.values.length; i++) {
                const value = enumType.values[i];
                // Remove redundant enum name prefix from value name if present
                let valueName = value.name;
                if (valueName.toLowerCase().startsWith(enumType.name.toLowerCase())) {
                    valueName = valueName.substring(enumType.name.length);
                    // Remove leading underscore if present after removing prefix
                    if (valueName.startsWith('_')) {
                        valueName = valueName.substring(1);
                    }
                }
                const cName = `SPINE_${toSnakeCase(enumType.name).toUpperCase()}_${toSnakeCase(valueName).toUpperCase()}`;
                
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