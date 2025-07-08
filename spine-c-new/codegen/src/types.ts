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
    isConst?: boolean;  // For excluding specifically const or non-const versions
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
    // Remove any spine:: namespace prefix first
    cppType = cppType.replace(/^spine::/, '');
    
    // Category 1: Primitives (including void)
    const primitiveMap: { [key: string]: string } = {
        'void': 'void',
        'bool': 'bool',
        'char': 'char',
        'int': 'int32_t',
        'int32_t': 'int32_t',
        'unsigned int': 'uint32_t',
        'uint32_t': 'uint32_t',
        'short': 'int16_t',
        'int16_t': 'int16_t',
        'unsigned short': 'uint16_t',
        'uint16_t': 'uint16_t',
        'long long': 'int64_t',
        'int64_t': 'int64_t',
        'unsigned long long': 'uint64_t',
        'uint64_t': 'uint64_t',
        'float': 'float',
        'double': 'double',
        'size_t': 'size_t',
        'uint8_t': 'uint8_t'
    };
    
    if (primitiveMap[cppType]) {
        return primitiveMap[cppType];
    }
    
    // Category 2: Special types
    if (cppType === 'String' || cppType === 'const String' || cppType === 'const char *') {
        return 'const utf8 *';
    }
    if (cppType === 'void *') {
        return 'spine_void';
    }
    if (cppType === 'DisposeRendererObject') {
        return 'spine_dispose_renderer_object';
    }
    if (cppType === 'TextureLoader' || cppType === 'TextureLoader *') {
        return 'spine_texture_loader';
    }
    if (cppType === 'PropertyId') {
        return 'int64_t'; // PropertyId is typedef'd to long long
    }
    
    // Category 3: Arrays - must check before pointers/references
    const arrayMatch = cppType.match(/^(?:const\s+)?Array<(.+?)>\s*(?:&|\*)?$/);
    if (arrayMatch) {
        const elementType = arrayMatch[1].trim();
        
        // Map element types to C array type suffixes
        let typeSuffix: string;
        
        // Handle primitives
        if (elementType === 'float') typeSuffix = 'float';
        else if (elementType === 'int') typeSuffix = 'int32';
        else if (elementType === 'unsigned short') typeSuffix = 'uint16';
        else if (elementType === 'bool') typeSuffix = 'bool';
        else if (elementType === 'char') typeSuffix = 'char';
        else if (elementType === 'size_t') typeSuffix = 'size';
        else if (elementType === 'PropertyId') typeSuffix = 'property_id';
        // Handle pointer types - remove * and convert
        else if (elementType.endsWith('*')) {
            const cleanType = elementType.slice(0, -1).trim();
            typeSuffix = toSnakeCase(cleanType);
        }
        // Handle everything else (enums, classes)
        else {
            typeSuffix = toSnakeCase(elementType);
        }
        
        return `spine_array_${typeSuffix}`;
    }
    
    // Category 4: Pointers
    const pointerMatch = cppType.match(/^(.+?)\s*\*$/);
    if (pointerMatch) {
        const baseType = pointerMatch[1].trim();
        
        // Primitive pointers stay as-is
        if (primitiveMap[baseType]) {
            const mappedType = primitiveMap[baseType];
            // For numeric types, use the mapped type
            return mappedType === 'void' ? 'void *' : `${mappedType} *`;
        }
        
        // char* becomes utf8*
        if (baseType === 'char' || baseType === 'const char') {
            return 'utf8 *';
        }
        
        // Class pointers
        return `spine_${toSnakeCase(baseType)}`;
    }
    
    // Category 5: References
    const refMatch = cppType.match(/^(?:const\s+)?(.+?)\s*&$/);
    if (refMatch) {
        const baseType = refMatch[1].trim();
        const isConst = cppType.includes('const ');
        
        // Special cases
        if (baseType === 'String') return 'const utf8 *';
        if (baseType === 'RTTI') return 'spine_rtti';
        
        // Non-const references to primitives become pointers (output parameters)
        if (!isConst && primitiveMap[baseType]) {
            const mappedType = primitiveMap[baseType];
            return mappedType === 'void' ? 'void *' : `${mappedType} *`;
        }
        
        // Const references and class references - recurse without the reference
        return toCTypeName(baseType);
    }
    
    // Category 6: Known enums
    const knownEnums = [
        'MixBlend', 'MixDirection', 'BlendMode', 'AttachmentType', 'EventType',
        'Format', 'TextureFilter', 'TextureWrap', 'Inherit', 'Physics',
        'PositionMode', 'Property', 'RotateMode', 'SequenceMode', 'SpacingMode'
    ];
    
    if (knownEnums.includes(cppType)) {
        return `spine_${toSnakeCase(cppType)}`;
    }
    
    // Category 7: Classes (default case)
    // Assume any remaining type is a spine class
    return `spine_${toSnakeCase(cppType)}`;
}