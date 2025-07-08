export interface Parameter {
    name: string;
    type: string;
    defaultValue?: string;
}

export interface Member {
    kind: 'field' | 'method' | 'constructor' | 'destructor';
    name: string;
    type?: string; // For fields
    returnType?: string; // For methods
    parameters?: Parameter[];
    isStatic?: boolean;
    isVirtual?: boolean;
    isPure?: boolean;
    isConst?: boolean;
    fromSupertype?: string; // Indicates this member was inherited
}

export interface EnumValue {
    name: string;
    value?: string;
}

export interface Type {
    name: string;
    kind: 'class' | 'struct' | 'enum';
    loc?: {
        line: number;
        col: number;
    };
    superTypes?: string[];
    members?: Member[];
    values?: EnumValue[]; // For enums
    isAbstract?: boolean;
    isTemplate?: boolean;
    templateParams?: string[];
}

export interface SpineTypes {
    [header: string]: Type[];
}

export interface Exclusion {
    kind: 'type' | 'method';
    typeName: string;
    methodName?: string;
}

export function toSnakeCase(name: string): string {
    // Handle acronyms and consecutive capitals
    let result = name.replace(/([A-Z]+)([A-Z][a-z])/g, '$1_$2');
    // Insert underscore before capital letters
    result = result.replace(/([a-z\d])([A-Z])/g, '$1_$2');
    return result.toLowerCase();
}

export function toCFunctionName(typeName: string, methodName: string): string {
    return `spine_${toSnakeCase(typeName)}_${toSnakeCase(methodName)}`;
}

export function toCTypeName(cppType: string): string {
    // Handle basic types
    if (cppType === 'float') return 'float';
    if (cppType === 'double') return 'double';
    if (cppType === 'int' || cppType === 'int32_t') return 'int32_t';
    if (cppType === 'unsigned int' || cppType === 'uint32_t') return 'uint32_t';
    if (cppType === 'short' || cppType === 'int16_t') return 'int16_t';
    if (cppType === 'unsigned short' || cppType === 'uint16_t') return 'uint16_t';
    if (cppType === 'bool') return 'spine_bool';
    if (cppType === 'void') return 'void';
    if (cppType === 'size_t') return 'spine_size_t';
    if (cppType === 'const char *' || cppType === 'String' || cppType === 'const String &') return 'const utf8 *';
    
    // Handle RTTI type specially
    if (cppType === 'const spine::RTTI &' || cppType === 'RTTI &' || cppType === 'const RTTI &') return 'spine_rtti';
    
    // Handle Vector types FIRST before checking for pointers - these should be converted to void* in C API
    const vectorMatch = cppType.match(/Vector<(.+?)>/);
    if (vectorMatch) {
        const elementType = vectorMatch[1].trim();
        // Special case for Vector<int> - use int32_t*
        if (elementType === 'int') {
            return 'int32_t *';
        }
        // For now, use void* for other vector parameters since we can't expose templates
        return 'void *';
    }
    
    // Handle pointers
    const pointerMatch = cppType.match(/^(.+?)\s*\*$/);
    if (pointerMatch) {
        const baseType = pointerMatch[1].trim();
        return `spine_${toSnakeCase(baseType)}`;
    }
    
    // Handle references
    const refMatch = cppType.match(/^(?:const\s+)?(.+?)\s*&$/);
    if (refMatch) {
        const baseType = refMatch[1].trim();
        if (baseType === 'String') return 'const utf8 *';
        if (baseType === 'RTTI' || baseType === 'spine::RTTI') return 'spine_rtti';
        return toCTypeName(baseType);
    }
    
    // Handle enum types from spine namespace
    const enumTypes = ['MixBlend', 'MixDirection', 'BlendMode', 'AttachmentType', 'EventType', 
                      'Format', 'TextureFilter', 'TextureWrap', 'Inherit', 'Physics', 
                      'PositionMode', 'Property', 'RotateMode', 'SequenceMode', 'SpacingMode'];
    for (const enumType of enumTypes) {
        if (cppType === enumType || cppType === `spine::${enumType}`) {
            return `spine_${toSnakeCase(enumType)}`;
        }
    }
    
    // Default: assume it's a spine type
    return `spine_${toSnakeCase(cppType)}`;
}