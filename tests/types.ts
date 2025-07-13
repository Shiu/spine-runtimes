// Shared types for the Spine serializer generator

// Match lsp-cli's Supertype interface
export interface Supertype {
    name: string;
    typeArguments?: string[];
}

// Match lsp-cli's SymbolInfo interface (we call it Symbol for backward compatibility)
export interface Symbol {
    name: string;
    kind: string;
    file: string;
    preview: string;
    documentation?: string;
    typeParameters?: string[];
    supertypes?: Supertype[];
    children?: Symbol[];
    // We don't need range and definition for our use case
}

export interface LspOutput {
    language: string;
    directory: string;
    symbols: Symbol[];
}

export interface ClassInfo {
    className: string;
    superTypes: string[]; // Just the names for backward compatibility
    superTypeDetails?: Supertype[]; // Full details with type arguments
    getters: GetterInfo[];
    fields: FieldInfo[];
    file: string;
    isAbstract: boolean;
    isInterface: boolean;
    isEnum: boolean;
    typeParameters?: string[]; // The class's own type parameters
    enumValues?: string[]; // For enums
    concreteImplementations?: string[]; // For abstract classes/interfaces - only leaf concrete types
    allImplementations?: string[]; // For abstract classes/interfaces - includes intermediate abstract types
}

export interface GetterInfo {
    methodName: string;
    returnType: string;
}

export interface FieldInfo {
    fieldName: string;
    fieldType: string;
    isFinal: boolean;
}

export interface PropertyInfo {
    name: string;
    type: string;
    isGetter: boolean;
    inheritedFrom?: string; // Which class this property was inherited from
    excluded: boolean; // Whether this property should be excluded from serialization
}

export interface AnalysisResult {
    classMap: Map<string, ClassInfo>;
    accessibleTypes: Set<string>;
    abstractTypes: Map<string, string[]>; // abstract type -> concrete implementations
    allTypesToGenerate: Set<string>; // all types that need write methods
    typeProperties: Map<string, PropertyInfo[]>; // type -> all properties (including inherited)
}