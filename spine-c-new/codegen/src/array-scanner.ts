import { Type, SpineTypes } from './types';
import { isTypeExcluded } from './exclusions';

export interface ArraySpecialization {
    cppType: string;           // e.g. "Array<float>"
    elementType: string;       // e.g. "float"
    cTypeName: string;         // e.g. "spine_array_float"
    cElementType: string;      // e.g. "float" or "spine_animation"
    isPointer: boolean;
    isEnum: boolean;
    isPrimitive: boolean;
}

/**
 * Scans all spine-cpp types to find Array<T> specializations
 * Only includes arrays from non-excluded types
 */
export function scanArraySpecializations(typesJson: SpineTypes, exclusions: any[], enumTypes: Set<string>): ArraySpecialization[] {
    const arrayTypes = new Set<string>();
    const warnings: string[] = [];

    // Extract Array<T> from a type string
    function extractArrayTypes(typeStr: string | undefined) {
        if (!typeStr) return;

        const regex = /Array<([^>]+)>/g;
        let match;
        while ((match = regex.exec(typeStr)) !== null) {
            arrayTypes.add(match[0]);
        }
    }

    // Process all types
    for (const header of Object.keys(typesJson)) {
        for (const type of typesJson[header]) {
            // Skip excluded types and template types
            if (isTypeExcluded(type.name, exclusions) || type.isTemplate) {
                continue;
            }

            if (!type.members) continue;

            for (const member of type.members) {
                switch (member.kind) {
                    case 'method':
                        extractArrayTypes(member.returnType);
                        if (member.parameters) {
                            for (const param of member.parameters) {
                                extractArrayTypes(param.type);
                            }
                        }
                        break;
                    case 'field':
                        extractArrayTypes(member.type);
                        break;
                    default:
                        break;
                }
            }
        }
    }

    // Convert to specializations
    const specializations: ArraySpecialization[] = [];

    for (const arrayType of arrayTypes) {
        const elementMatch = arrayType.match(/Array<(.+)>$/);
        if (!elementMatch) continue;

        const elementType = elementMatch[1].trim();

        // Skip template placeholders
        if (elementType === 'T' || elementType === 'K') {
            continue;
        }

        // Handle nested arrays - emit warning
        if (elementType.startsWith('Array<')) {
            warnings.push(`Skipping nested array: ${arrayType} - manual handling required`);
            continue;
        }

        // Handle String arrays - emit warning
        if (elementType === 'String') {
            warnings.push(`Skipping String array: ${arrayType} - should be fixed in spine-cpp`);
            continue;
        }

        // Determine type characteristics
        const isPointer = elementType.endsWith('*');
        let cleanElementType = isPointer ? elementType.slice(0, -1).trim() : elementType;

        // Remove "class " or "struct " prefix if present
        cleanElementType = cleanElementType.replace(/^(?:class|struct)\s+/, '');
        const isEnum = enumTypes.has(cleanElementType) || cleanElementType === 'PropertyId';
        const isPrimitive = !isPointer && !isEnum &&
            ['int', 'float', 'double', 'bool', 'char', 'unsigned short', 'size_t'].includes(cleanElementType);

        // Generate C type names
        let cTypeName: string;
        let cElementType: string;

        if (isPrimitive) {
            // Map primitive types
            const typeMap: { [key: string]: string } = {
                'int': 'int32_t',
                'unsigned short': 'uint16_t',
                'float': 'float',
                'double': 'double',
                'bool': 'bool',
                'char': 'char',
                'size_t': 'size_t'
            };
            cElementType = typeMap[cleanElementType] || cleanElementType;
            cTypeName = `spine_array_${cElementType.replace(/_t$/, '')}`;
        } else if (isEnum) {
            // Handle enums
            if (cleanElementType === 'PropertyId') {
                cElementType = 'int64_t'; // PropertyId is typedef long long
                cTypeName = 'spine_array_property_id';
            } else {
                // Convert enum name to snake_case
                const snakeCase = cleanElementType.replace(/([A-Z])/g, '_$1').toLowerCase().replace(/^_/, '');
                cElementType = `spine_${snakeCase}`;
                cTypeName = `spine_array_${snakeCase}`;
            }
        } else if (isPointer) {
            // Handle pointer types
            const snakeCase = cleanElementType.replace(/([A-Z])/g, '_$1').toLowerCase().replace(/^_/, '');
            cElementType = `spine_${snakeCase}`;
            cTypeName = `spine_array_${snakeCase}`;
        } else {
            // Unknown type - skip
            warnings.push(`Unknown array element type: ${elementType}`);
            continue;
        }

        specializations.push({
            cppType: arrayType,
            elementType: elementType,
            cTypeName: cTypeName,
            cElementType: cElementType,
            isPointer: isPointer,
            isEnum: isEnum,
            isPrimitive: isPrimitive
        });
    }

    // Print warnings
    if (warnings.length > 0) {
        console.log('\nArray Generation Warnings:');
        for (const warning of warnings) {
            console.log(`  - ${warning}`);
        }
        console.log('');
    }

    // Sort by C type name for consistent output
    specializations.sort((a, b) => a.cTypeName.localeCompare(b.cTypeName));

    return specializations;
}