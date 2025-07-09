export interface Parameter {
    name: string;
    type: string;
}

export type Field = {
    kind: 'field';
    name: string;
    type: string;
    isStatic?: boolean;
    fromSupertype?: string;
}

export type Method = {
    kind: 'method';
    name: string;
    returnType: string;
    parameters?: Parameter[];
    isStatic?: boolean;
    isVirtual?: boolean;
    isPure?: boolean;
    isConst?: boolean;
    fromSupertype?: string;
}

export type Constructor = {
    kind: 'constructor';
    name: string;
    parameters?: Parameter[];
    fromSupertype?: string;
}

export type Destructor = {
    kind: 'destructor';
    name: string;
    isVirtual?: boolean;
    isPure?: boolean;
    fromSupertype?: string;
};

export type Member =
    | Field
    | Method
    | Constructor
    | Destructor

export type Enum = {
    kind: 'enum';
    name: string;
    values: EnumValue[];
}

export interface EnumValue {
    name: string;
    value?: string;
}

export interface ClassOrStruct {
    name: string;
    kind: 'class' | 'struct';
    loc?: {
        line: number;
        col: number;
    };
    superTypes?: string[];
    members?: Member[];
    isAbstract?: boolean;
    isTemplate?: boolean;
    templateParams?: string[];
}

export type Type = ClassOrStruct | Enum;

export interface SpineTypes {
    [header: string]: Type[];
}

export type Exclusion =
    | {
        kind: 'type';
        typeName: string;
    }
    | {
        kind: 'method';
        typeName: string;
        methodName: string;
        isConst?: boolean;  // Whether the method is const (e.g., void foo() const), NOT whether return type is const
    };

export interface ArraySpecialization {
    cppType: string;           // e.g. "Array<float>"
    elementType: string;       // e.g. "float"
    cTypeName: string;         // e.g. "spine_array_float"
    cElementType: string;      // e.g. "float" or "spine_animation"
    isPointer: boolean;
    isEnum: boolean;
    isPrimitive: boolean;
    sourceMember: Member;
}

/**
 * Converts a PascalCase or camelCase name to snake_case.
 *
 * @param name The name to convert
 * @returns The snake_case version
 *
 * Examples:
 * - "AnimationState" → "animation_state"
 * - "getRTTI" → "get_rtti"
 * - "IKConstraint" → "ik_constraint"
 */
export function toSnakeCase(name: string): string {
    // Handle acronyms and consecutive capitals
    let result = name.replace(/([A-Z]+)([A-Z][a-z])/g, '$1_$2');
    // Insert underscore before capital letters
    result = result.replace(/([a-z\d])([A-Z])/g, '$1_$2');
    return result.toLowerCase();
}

/**
 * Generates a C function name from a type and method name.
 *
 * @param typeName The C++ class name
 * @param methodName The method name
 * @returns The C function name
 *
 * Examples:
 * - ("Skeleton", "updateCache") → "spine_skeleton_update_cache"
 * - ("AnimationState", "apply") → "spine_animation_state_apply"
 */
export function toCFunctionName(typeName: string, methodName: string): string {
    return `spine_${toSnakeCase(typeName)}_${toSnakeCase(methodName)}`;
}

/**
 * Checks if a type is a primitive by tokenizing and checking if ALL tokens start with lowercase.
 * Examples:
 * - "int" → true
 * - "const char*" → true (all tokens: "const", "char*" start lowercase)
 * - "unsigned int" → true (all tokens start lowercase)
 * - "Array<float>" → false (starts uppercase)
 * - "const Array<float>&" → false ("Array" starts uppercase)
 */
export function isPrimitive(cppType: string): boolean {
    const tokens = cppType.split(/\s+/);
    return tokens.every(token => {
        // Remove any trailing punctuation like *, &
        const cleanToken = token.replace(/[*&]+$/, '');
        return cleanToken.length > 0 && /^[a-z]/.test(cleanToken);
    });
}

/**
 * Converts a C++ type to its corresponding C type.
 *
 * @param cppType The C++ type to convert
 * @param validTypes Set of valid type names (classes and enums) from filtered types
 * @returns The C type
 * @throws Error if the type is not recognized
 *
 * Examples:
 * - Primitives: "int" → "int", "const float*" → "const float*"
 * - String types: "String" → "const char*", "const String&" → "const char*"
 * - Arrays: "Array<float>" → "spine_array_float"
 * - Class pointers: "Bone*" → "spine_bone"
 * - Class references: "const Color&" → "spine_color"
 * - Non-const primitive refs: "float&" → "float*" (output parameter)
 */
export function toCTypeName(cppType: string, validTypes: Set<string>): string {
    // Remove extra spaces and normalize
    const normalizedType = cppType.replace(/\s+/g, ' ').trim();

    // Primitives - pass through unchanged
    if (isPrimitive(normalizedType)) {
        return normalizedType;
    }

    // Special type: String
    if (normalizedType === 'String' || normalizedType === 'const String' ||
        normalizedType === 'String&' || normalizedType === 'const String&') {
        return 'const char*';
    }

    // PropertyId is a typedef
    if (normalizedType === 'PropertyId') {
        return 'int64_t';
    }

    // Arrays - must check before pointers/references
    const arrayMatch = normalizedType.match(/^(?:const\s+)?Array<(.+?)>\s*(?:&|\*)?$/);
    if (arrayMatch) {
        const elementType = arrayMatch[1].trim();

        // For primitive element types, use the type name with spaces replaced by underscores
        if (isPrimitive(elementType)) {
            return `spine_array_${elementType.replace(/\s+/g, '_')}`;
        }

        // For pointer types, remove the * and convert
        if (elementType.endsWith('*')) {
            const baseType = elementType.slice(0, -1).trim();
            return `spine_array_${toSnakeCase(baseType)}`;
        }

        // For class/enum types
        return `spine_array_${toSnakeCase(elementType)}`;
    }

    // Pointers
    const pointerMatch = normalizedType.match(/^(.+?)\s*\*$/);
    if (pointerMatch) {
        const baseType = pointerMatch[1].trim();

        // Primitive pointers stay as-is
        if (isPrimitive(baseType)) {
            return normalizedType;
        }

        // Class pointers become opaque types
        return `spine_${toSnakeCase(baseType)}`;
    }

    // References
    const refMatch = normalizedType.match(/^((?:const\s+)?(.+?))\s*&$/);
    if (refMatch) {
        const fullBaseType = refMatch[1].trim();
        const baseType = refMatch[2].trim();
        const isConst = fullBaseType.startsWith('const ');

        // Non-const references to primitives become pointers (output parameters)
        if (!isConst && isPrimitive(baseType)) {
            return `${baseType}*`;
        }

        // Const references and class references - recurse without the reference
        return toCTypeName(baseType, validTypes);
    }

    // Function pointers - for now, just error
    if (normalizedType.includes('(') && normalizedType.includes(')')) {
        throw new Error(`Function pointer types not yet supported: ${normalizedType}`);
    }

    // Everything else should be a class or enum type
    // Check if it's a valid type
    if (!validTypes.has(normalizedType)) {
        throw new Error(`Unknown type: ${normalizedType}. Not a primitive and not in the list of valid types.`);
    }

    return `spine_${toSnakeCase(normalizedType)}`;
}