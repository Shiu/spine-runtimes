import * as fs from 'node:fs/promises';
import * as path from 'node:path';
import type { CClassOrStruct, CEnum, CMethod, CParameter } from '../../../spine-c/codegen/src/c-types.js';

export interface SwiftGenerationOptions {
    outputDir: string;
    licenseHeader: string;
}

interface SwiftClass {
    name: string;
    cType: CClassOrStruct;
    isAbstract: boolean;
    isInterface: boolean;
    parentClass?: string;
    protocols: string[];
    methods: SwiftMethod[];
    properties: SwiftProperty[];
    constructors: SwiftConstructor[];
}

interface SwiftMethod {
    name: string;
    cMethod: CMethod;
    parameters: SwiftParameter[];
    returnType: string;
    isStatic: boolean;
    implementation: string;
}

interface SwiftParameter {
    name: string;
    type: string;
    cParam: CParameter;
}

interface SwiftProperty {
    name: string;
    type: string;
    isReadOnly: boolean;
    getter?: SwiftMethod;
    setter?: SwiftMethod;
}

interface SwiftConstructor {
    parameters: SwiftParameter[];
    implementation: string;
}

export class SwiftWriter {
    private cTypes: CClassOrStruct[];
    private cEnums: CEnum[];
    private cArrayTypes: CClassOrStruct[];
    private inheritance: Map<string, InheritanceInfo>;
    private isInterface: Map<string, boolean>;
    private supertypes: Map<string, Set<string>>;
    private subtypes: Map<string, Set<string>>;
    private swiftClasses: Map<string, SwiftClass> = new Map();

    constructor(
        cTypes: CClassOrStruct[],
        cEnums: CEnum[],
        cArrayTypes: CClassOrStruct[],
        inheritance: any,
        isInterface: any,
        supertypes: any,
        subtypes: any
    ) {
        this.cTypes = cTypes;
        this.cEnums = cEnums;
        this.cArrayTypes = cArrayTypes;
        this.inheritance = new Map(Object.entries(inheritance || {}));
        this.isInterface = new Map(Object.entries(isInterface || {}));
        this.supertypes = new Map(Object.entries(supertypes || {}).map(([k, v]) => [k, new Set(v as string[])]));
        this.subtypes = new Map(Object.entries(subtypes || {}).map(([k, v]) => [k, new Set(v as string[])]));
    }

    async generate(options: SwiftGenerationOptions): Promise<void> {
        console.log('Generating Swift bindings...');

        // Process all C types to create Swift class models
        for (const cType of this.cTypes) {
            this.processType(cType);
        }

        // Generate individual Swift files for each type
        for (const [typeName, swiftClass] of this.swiftClasses) {
            await this.generateClassFile(swiftClass, options);
        }

        // Generate enum file
        await this.generateEnumsFile(options);

        // Generate arrays file
        await this.generateArraysFile(options);

        // Generate main exports file
        await this.generateExportsFile(options);

        console.log('Swift bindings generation complete!');
    }

    private processType(cType: CClassOrStruct): void {
        const swiftName = this.getSwiftClassName(cType.name);
        const inheritanceInfo = this.inheritance.get(cType.name);
        const isAbstract = cType.cppType?.abstract || false;
        const isInterface = this.isInterface.get(cType.name) || false;

        const swiftClass: SwiftClass = {
            name: swiftName,
            cType: cType,
            isAbstract,
            isInterface,
            parentClass: inheritanceInfo?.extends ? this.getSwiftClassName(inheritanceInfo.extends) : undefined,
            protocols: inheritanceInfo?.im?.map(m => this.getSwiftClassName(m)) || [],
            methods: [],
            properties: [],
            constructors: []
        };

        // Process constructors
        for (const ctor of cType.constructors) {
            swiftClass.constructors.push(this.processConstructor(ctor, cType));
        }

        // Process methods and detect properties
        const getterSetterMap = new Map<string, { getter?: CMethod, setter?: CMethod }>();

        for (const method of cType.methods) {
            // Check if it's a getter/setter pattern
            const getterMatch = method.name.match(/^get(.+)$/);
            const setterMatch = method.name.match(/^set(.+)$/);

            if (getterMatch && method.parameters.length === 0) {
                const propName = this.lowercaseFirst(getterMatch[1]);
                const prop = getterSetterMap.get(propName) || {};
                prop.getter = method;
                getterSetterMap.set(propName, prop);
            } else if (setterMatch && method.parameters.length === 1) {
                const propName = this.lowercaseFirst(setterMatch[1]);
                const prop = getterSetterMap.get(propName) || {};
                prop.setter = method;
                getterSetterMap.set(propName, prop);
            } else {
                // Regular method
                swiftClass.methods.push(this.processMethod(method, cType));
            }
        }

        // Create properties from getter/setter pairs
        for (const [propName, { getter, setter }] of getterSetterMap) {
            if (getter) {
                swiftClass.properties.push({
                    name: propName,
                    type: this.mapReturnType(getter.returnType, getter.returnTypeNullable),
                    isReadOnly: !setter,
                    getter: getter ? this.processMethod(getter, cType) : undefined,
                    setter: setter ? this.processMethod(setter, cType) : undefined
                });
            }
        }

        this.swiftClasses.set(cType.name, swiftClass);
    }

    private processConstructor(ctor: any, cType: CClassOrStruct): SwiftConstructor {
        const params = (ctor.parameters || []).map((p: CParameter) => this.processParameter(p));
        return {
            parameters: params,
            implementation: this.generateConstructorImplementation(ctor, cType)
        };
    }

    private processMethod(method: CMethod, cType: CClassOrStruct): SwiftMethod {
        // Filter out 'self' parameter which is always the first one for instance methods
        const params = method.parameters.filter(p => p.name !== 'self').map(p => this.processParameter(p));
        return {
            name: this.getSwiftMethodName(method.name, cType.name),
            cMethod: method,
            parameters: params,
            returnType: this.mapReturnType(method.returnType, method.returnTypeNullable),
            isStatic: method.isStatic || false,
            implementation: this.generateMethodImplementation(method, cType)
        };
    }

    private processParameter(param: CParameter): SwiftParameter {
        return {
            name: this.sanitizeParameterName(param.name),
            type: this.mapParameterType(param.cType, param.isNullable),
            cParam: param
        };
    }

    private generateConstructorImplementation(ctor: any, cType: CClassOrStruct): string {
        // TODO: Generate actual implementation
        return '';
    }

    private generateMethodImplementation(method: CMethod, cType: CClassOrStruct): string {
        // TODO: Generate actual implementation
        return '';
    }

    private async generateClassFile(swiftClass: SwiftClass, options: SwiftGenerationOptions): Promise<void> {
        const filePath = path.join(options.outputDir, `${swiftClass.name}.swift`);
        const content = this.generateClassContent(swiftClass, options);
        await fs.writeFile(filePath, content, 'utf-8');
    }

    private generateClassContent(swiftClass: SwiftClass, options: SwiftGenerationOptions): string {
        const lines: string[] = [];

        // Add license header as comment
        lines.push(...options.licenseHeader.split('\n').map(line => `// ${line}`));
        lines.push('');

        // Imports
        lines.push('import Foundation');
        lines.push('import SpineC');
        lines.push('');

        // Class declaration
        const inheritance = this.buildInheritanceDeclaration(swiftClass);
        lines.push(`@objc(Spine${swiftClass.name})`);
        lines.push(`@objcMembers`);
        lines.push(`public ${swiftClass.isAbstract ? 'class' : 'final class'} ${swiftClass.name}${inheritance} {`);

        // Internal wrapper property
        lines.push(`    internal let wrappee: ${swiftClass.cType.name}`);
        lines.push('');

        // Internal init
        lines.push(`    internal init(_ wrappee: ${swiftClass.cType.name}) {`);
        lines.push('        self.wrappee = wrappee');
        if (swiftClass.parentClass && !swiftClass.isInterface) {
            lines.push('        super.init(wrappee)');
        } else {
            lines.push('        super.init()');
        }
        lines.push('    }');
        lines.push('');

        // isEqual and hash
        if (!swiftClass.parentClass || swiftClass.parentClass === 'NSObject') {
            lines.push('    public override func isEqual(_ object: Any?) -> Bool {');
            lines.push(`        guard let other = object as? ${swiftClass.name} else { return false }`);
            lines.push('        return self.wrappee == other.wrappee');
            lines.push('    }');
            lines.push('');
            lines.push('    public override var hash: Int {');
            lines.push('        var hasher = Hasher()');
            lines.push('        hasher.combine(self.wrappee)');
            lines.push('        return hasher.finalize()');
            lines.push('    }');
            lines.push('');
        }

        // Add public constructors
        if (!swiftClass.isAbstract && swiftClass.constructors.length > 0) {
            for (const ctor of swiftClass.constructors) {
                lines.push(...this.generateConstructor(ctor, swiftClass));
                lines.push('');
            }
        }

        // Add properties
        for (const prop of swiftClass.properties) {
            lines.push(...this.generateProperty(prop, swiftClass));
            lines.push('');
        }

        // Add methods
        for (const method of swiftClass.methods) {
            lines.push(...this.generateMethod(method, swiftClass));
            lines.push('');
        }

        // Add destructor if concrete class
        if (!swiftClass.isAbstract && swiftClass.cType.destructor) {
            lines.push('    deinit {');
            lines.push(`        ${swiftClass.cType.destructor.name}(wrappee)`);
            lines.push('    }');
        }

        lines.push('}');

        return lines.join('\n');
    }

    private buildInheritanceDeclaration(swiftClass: SwiftClass): string {
        const parts: string[] = [];

        if (swiftClass.parentClass) {
            parts.push(swiftClass.parentClass);
        } else if (!swiftClass.isInterface) {
            parts.push('NSObject');
        }

        if (swiftClass.protocols.length > 0) {
            parts.push(...swiftClass.protocols);
        }

        return parts.length > 0 ? `: ${parts.join(', ')}` : '';
    }

    private async generateEnumsFile(options: SwiftGenerationOptions): Promise<void> {
        const filePath = path.join(options.outputDir, 'Enums.swift');
        const lines: string[] = [];

        // Add license header
        lines.push(...options.licenseHeader.split('\n').map(line => `// ${line}`));
        lines.push('');
        lines.push('import Foundation');
        lines.push('import SpineC');
        lines.push('');

        // Generate each enum
        for (const cEnum of this.cEnums) {
            lines.push(`public typealias ${this.getSwiftClassName(cEnum.name)} = ${cEnum.name}`);
        }

        await fs.writeFile(filePath, lines.join('\n'), 'utf-8');
    }

    private async generateArraysFile(options: SwiftGenerationOptions): Promise<void> {
        const filePath = path.join(options.outputDir, 'Arrays.swift');
        const lines: string[] = [];

        // Add license header
        lines.push(...options.licenseHeader.split('\n').map(line => `// ${line}`));
        lines.push('');
        lines.push('import Foundation');
        lines.push('import SpineC');
        lines.push('');

        // Generate array wrapper classes
        for (const arrayType of this.cArrayTypes) {
            lines.push(...this.generateArrayClass(arrayType));
            lines.push('');
        }

        await fs.writeFile(filePath, lines.join('\n'), 'utf-8');
    }

    private async generateExportsFile(options: SwiftGenerationOptions): Promise<void> {
        const filePath = path.join(options.outputDir, 'Spine.Generated.swift');
        const lines: string[] = [];

        // Add license header
        lines.push(...options.licenseHeader.split('\n').map(line => `// ${line}`));
        lines.push('');
        lines.push('// This file exports all generated types');
        lines.push('');

        await fs.writeFile(filePath, lines.join('\n'), 'utf-8');
    }

    private mapCTypeToSwift(cType: string | undefined): string {
        if (!cType) return 'Void';

        const typeMap: Record<string, string> = {
            'void': 'Void',
            'spine_bool': 'Bool',
            'bool': 'Bool',
            'int': 'Int32',
            'int32_t': 'Int32',
            'uint32_t': 'UInt32',
            'int16_t': 'Int16',
            'uint16_t': 'UInt16',
            'int64_t': 'Int64',
            'uint64_t': 'UInt64',
            'float': 'Float',
            'double': 'Double',
            'const char *': 'String?',
            'char *': 'String?',
            'const utf8 *': 'String?',
            'utf8 *': 'String?',
            'float *': 'UnsafeMutablePointer<Float>?',
            'int *': 'UnsafeMutablePointer<Int32>?',
            'int32_t *': 'UnsafeMutablePointer<Int32>?',
        };

        // Check if it's already in the map
        if (typeMap[cType]) {
            return typeMap[cType];
        }

        // Handle spine types
        if (cType.startsWith('spine_')) {
            // It's a spine type - map to Swift class
            const swiftType = this.getSwiftClassName(cType);
            return swiftType;
        }

        // Handle pointer types
        if (cType.endsWith('*')) {
            // It's a pointer to something
            const baseType = cType.slice(0, -1).trim();
            if (baseType.startsWith('spine_')) {
                // Pointer to spine type
                const swiftType = this.getSwiftClassName(baseType);
                return swiftType + '?';
            } else {
                // Generic pointer
                return 'OpaquePointer?';
            }
        }

        return cType;
    }

    private mapReturnType(cType: string | undefined, isNullable: boolean): string {
        if (!cType) return 'Void';

        const baseType = this.mapCTypeToSwift(cType);

        // Handle spine type pointers
        if (cType.startsWith('spine_') && cType.endsWith('*')) {
            const typeName = cType.slice(0, -1).trim(); // Remove pointer
            const swiftType = this.getSwiftClassName(typeName);
            return isNullable ? `${swiftType}?` : swiftType;
        }

        return baseType;
    }

    private mapParameterType(cType: string | undefined, isNullable: boolean): string {
        return this.mapReturnType(cType, isNullable);
    }

    private getSwiftClassName(cTypeName: string): string {
        // Remove spine_ prefix and convert to PascalCase
        const name = cTypeName.replace(/^spine_/, '');
        return name.split('_')
            .map(part => part.charAt(0).toUpperCase() + part.slice(1))
            .join('');
    }

    private getSwiftMethodName(cMethodName: string, cTypeName: string): string {
        // Remove the type prefix (e.g., spine_skeleton_update -> update)
        let name = cMethodName;
        if (name.startsWith(cTypeName + '_')) {
            name = name.substring(cTypeName.length + 1);
        }

        // Handle numbered methods (e.g., setSkin_1 -> setSkin)
        name = name.replace(/_\d+$/, '');

        // Convert snake_case to camelCase
        const parts = name.split('_');
        if (parts.length > 1) {
            name = parts[0] + parts.slice(1).map(p => p.charAt(0).toUpperCase() + p.slice(1)).join('');
        }

        return name;
    }

    private lowercaseFirst(str: string): string {
        return str.charAt(0).toLowerCase() + str.slice(1);
    }

    private sanitizeParameterName(name: string): string {
        // Swift reserved words that need escaping
        const reserved = ['in', 'var', 'let', 'func', 'class', 'struct', 'enum', 'protocol', 'extension'];
        return reserved.includes(name) ? `\`${name}\`` : name;
    }

    private isNullableType(cType: string): boolean {
        // Pointers can be null
        return cType.includes('*');
    }

    private generateConstructor(ctor: SwiftConstructor, swiftClass: SwiftClass): string[] {
        const lines: string[] = [];

        // Generate parameter list
        const params = ctor.parameters.map(p => `${p.name}: ${p.type}`).join(', ');

        lines.push(`    public convenience init(${params}) {`);

        // Generate C function call
        const cParams = ctor.parameters.map(p => {
            if (p.type.endsWith('?') && p.type !== 'String?') {
                // It's an optional spine type
                return `${p.name}?.wrappee ?? nil`;
            } else if (p.type === 'String?') {
                return p.name;
            } else if (this.isSpineType(p.type)) {
                return `${p.name}.wrappee`;
            } else {
                return p.name;
            }
        }).join(', ');

        lines.push(`        let ptr = ${swiftClass.cType.constructors[0].name}(${cParams})`);
        lines.push('        self.init(ptr)');
        lines.push('    }');

        return lines;
    }

    private generateProperty(prop: SwiftProperty, swiftClass: SwiftClass): string[] {
        const lines: string[] = [];

        if (prop.isReadOnly) {
            // Read-only property
            lines.push(`    public var ${prop.name}: ${prop.type} {`);
            if (prop.getter) {
                lines.push(...this.generatePropertyGetter(prop.getter, swiftClass));
            }
            lines.push('    }');
        } else {
            // Read-write property
            lines.push(`    public var ${prop.name}: ${prop.type} {`);
            lines.push('        get {');
            if (prop.getter) {
                lines.push(...this.generatePropertyGetter(prop.getter, swiftClass).map(l => '    ' + l));
            }
            lines.push('        }');
            lines.push('        set {');
            if (prop.setter) {
                lines.push(...this.generatePropertySetter(prop.setter, swiftClass).map(l => '    ' + l));
            }
            lines.push('        }');
            lines.push('    }');
        }

        return lines;
    }

    private generatePropertyGetter(method: SwiftMethod, swiftClass: SwiftClass): string[] {
        const lines: string[] = [];
        const returnType = method.returnType;

        if (returnType === 'Void') {
            lines.push(`        ${method.cMethod.name}(wrappee)`);
        } else if (returnType === 'String?') {
            lines.push(`        let result = ${method.cMethod.name}(wrappee)`);
            lines.push('        return result != nil ? String(cString: result!) : nil');
        } else if (returnType === 'Bool') {
            lines.push(`        return ${method.cMethod.name}(wrappee) != 0`);
        } else if (this.isSpineType(returnType)) {
            const isOptional = returnType.endsWith('?');
            const baseType = isOptional ? returnType.slice(0, -1) : returnType;

            lines.push(`        let result = ${method.cMethod.name}(wrappee)`);
            if (isOptional) {
                lines.push(`        return result != nil ? ${baseType}(result!) : nil`);
            } else {
                lines.push(`        return ${baseType}(result)`);
            }
        } else {
            lines.push(`        return ${method.cMethod.name}(wrappee)`);
        }

        return lines;
    }

    private generatePropertySetter(method: SwiftMethod, swiftClass: SwiftClass): string[] {
        const lines: string[] = [];
        const param = method.parameters[0];

        let paramValue = 'newValue';
        if (param.type === 'String?') {
            paramValue = 'newValue?.cString(using: .utf8)';
        } else if (param.type === 'Bool') {
            paramValue = 'newValue ? 1 : 0';
        } else if (this.isSpineType(param.type)) {
            if (param.type.endsWith('?')) {
                paramValue = 'newValue?.wrappee';
            } else {
                paramValue = 'newValue.wrappee';
            }
        }

        lines.push(`        ${method.cMethod.name}(wrappee, ${paramValue})`);

        return lines;
    }

    private generateMethod(method: SwiftMethod, swiftClass: SwiftClass): string[] {
        const lines: string[] = [];

        // Generate parameter list
        const params = method.parameters.map(p => `${p.name}: ${p.type}`).join(', ');
        const funcDecl = method.isStatic ? 'public static func' : 'public func';

        lines.push(`    ${funcDecl} ${method.name}(${params})${method.returnType !== 'Void' ? ' -> ' + method.returnType : ''} {`);

        // Generate method body
        const cParams = [
            !method.isStatic ? 'wrappee' : '',
            ...method.parameters.map(p => {
                if (p.type === 'String?') {
                    return `${p.name}?.cString(using: .utf8)`;
                } else if (p.type === 'Bool') {
                    return `${p.name} ? 1 : 0`;
                } else if (this.isSpineType(p.type)) {
                    if (p.type.endsWith('?')) {
                        return `${p.name}?.wrappee`;
                    } else {
                        return `${p.name}.wrappee`;
                    }
                } else {
                    return p.name;
                }
            })
        ].filter(p => p !== '').join(', ');

        if (method.returnType === 'Void') {
            lines.push(`        ${method.cMethod.name}(${cParams})`);
        } else if (method.returnType === 'String?') {
            lines.push(`        let result = ${method.cMethod.name}(${cParams})`);
            lines.push('        return result != nil ? String(cString: result!) : nil');
        } else if (method.returnType === 'Bool') {
            lines.push(`        return ${method.cMethod.name}(${cParams}) != 0`);
        } else if (this.isSpineType(method.returnType)) {
            const isOptional = method.returnType.endsWith('?');
            const baseType = isOptional ? method.returnType.slice(0, -1) : method.returnType;

            lines.push(`        let result = ${method.cMethod.name}(${cParams})`);
            if (isOptional) {
                lines.push(`        return result != nil ? ${baseType}(result!) : nil`);
            } else {
                lines.push(`        return ${baseType}(result)`);
            }
        } else {
            lines.push(`        return ${method.cMethod.name}(${cParams})`);
        }

        lines.push('    }');

        return lines;
    }

    private isSpineType(type: string): boolean {
        const baseType = type.endsWith('?') ? type.slice(0, -1) : type;
        // Check if it's one of our generated Swift classes
        return Array.from(this.swiftClasses.values()).some(c => c.name === baseType);
    }

    private generateArrayClass(arrayType: CClassOrStruct): string[] {
        const lines: string[] = [];
        const swiftClassName = this.getSwiftClassName(arrayType.name);
        const elementType = this.extractArrayElementType(arrayType.name);

        lines.push(`/// ${swiftClassName} wrapper class`);
        lines.push(`@objc(Spine${swiftClassName})`);
        lines.push(`@objcMembers`);
        lines.push(`public final class ${swiftClassName}: NSObject {`);
        lines.push(`    internal let ptr: OpaquePointer`);
        lines.push(`    private let ownsMemory: Bool`);
        lines.push('');

        // Constructor
        lines.push(`    internal init(fromPointer ptr: OpaquePointer, ownsMemory: Bool = false) {`);
        lines.push(`        self.ptr = ptr`);
        lines.push(`        self.ownsMemory = ownsMemory`);
        lines.push(`        super.init()`);
        lines.push(`    }`);
        lines.push('');

        // Factory constructors
        const createMethod = arrayType.constructors?.find(m => m.name === `${arrayType.name}_create`);
        const createWithCapacityMethod = arrayType.constructors?.find(m => m.name === `${arrayType.name}_create_with_capacity`);

        if (createMethod) {
            lines.push(`    /// Create a new empty array`);
            lines.push(`    public convenience init() {`);
            lines.push(`        let ptr = ${createMethod.name}()`);
            lines.push(`        self.init(fromPointer: ptr, ownsMemory: true)`);
            lines.push(`    }`);
            lines.push('');
        }

        if (createWithCapacityMethod) {
            lines.push(`    /// Create a new array with the specified initial capacity`);
            lines.push(`    public convenience init(capacity: Int32) {`);
            lines.push(`        let ptr = ${createWithCapacityMethod.name}(capacity)`);
            lines.push(`        self.init(fromPointer: ptr, ownsMemory: true)`);
            lines.push(`    }`);
            lines.push('');
        }

        // Native pointer accessor
        lines.push(`    public var nativePtr: OpaquePointer { ptr }`);
        lines.push('');

        // Length property
        const sizeMethod = arrayType.methods.find(m => m.name.endsWith('_size') && !m.name.endsWith('_set_size'));
        if (sizeMethod) {
            lines.push(`    public var count: Int32 {`);
            lines.push(`        return ${sizeMethod.name}(ptr)`);
            lines.push(`    }`);
            lines.push('');
        }

        // Subscript operators
        const bufferMethod = arrayType.methods.find(m => m.name.endsWith('_buffer'));
        const setMethod = arrayType.methods.find(m => m.name.endsWith('_set') && m.parameters.length === 3);

        if (bufferMethod) {
            const swiftElementType = this.mapArrayElementTypeToSwift(elementType);
            lines.push(`    public subscript(index: Int32) -> ${swiftElementType} {`);
            lines.push(`        get {`);
            lines.push(`            precondition(index >= 0 && index < count, "Index out of bounds")`);
            lines.push(`            let buffer = ${bufferMethod.name}(ptr)`);

            if (this.isPrimitiveArrayType(elementType)) {
                // Handle primitive types
                if (elementType === 'int') {
                    lines.push(`            return buffer!.assumingMemoryBound(to: Int32.self)[Int(index)]`);
                } else if (elementType === 'float') {
                    lines.push(`            return buffer!.assumingMemoryBound(to: Float.self)[Int(index)]`);
                } else if (elementType === 'bool') {
                    lines.push(`            return buffer!.assumingMemoryBound(to: Int32.self)[Int(index)] != 0`);
                } else if (elementType === 'unsigned_short') {
                    lines.push(`            return buffer!.assumingMemoryBound(to: UInt16.self)[Int(index)]`);
                } else if (elementType === 'property_id') {
                    lines.push(`            return buffer!.assumingMemoryBound(to: Int64.self)[Int(index)]`);
                }
            } else {
                // Handle object types - need to convert pointer to Swift class
                const swiftType = this.getSwiftClassName(`spine_${elementType}`);
                lines.push(`            let elementPtr = buffer!.assumingMemoryBound(to: OpaquePointer?.self)[Int(index)]`);
                lines.push(`            return elementPtr == nil ? nil : ${swiftType}(fromPointer: elementPtr!)`);
            }

            lines.push(`        }`);

            // Setter if available
            if (setMethod) {
                lines.push(`        set {`);
                lines.push(`            precondition(index >= 0 && index < count, "Index out of bounds")`);

                if (this.isPrimitiveArrayType(elementType)) {
                    lines.push(`            ${setMethod.name}(ptr, index, newValue)`);
                } else {
                    lines.push(`            ${setMethod.name}(ptr, index, newValue?.nativePtr)`);
                }

                lines.push(`        }`);
            }

            lines.push(`    }`);
            lines.push('');
        }

        // Add method
        const addMethod = arrayType.methods.find(m => m.name.endsWith('_add') && !m.name.endsWith('_add_all'));
        if (addMethod) {
            const swiftElementType = this.mapArrayElementTypeToSwift(elementType);
            lines.push(`    /// Adds a value to the end of this array`);
            lines.push(`    public func add(_ value: ${swiftElementType}) {`);

            if (this.isPrimitiveArrayType(elementType)) {
                lines.push(`        ${addMethod.name}(ptr, value)`);
            } else {
                lines.push(`        ${addMethod.name}(ptr, value?.nativePtr)`);
            }

            lines.push(`    }`);
            lines.push('');
        }

        // Clear method
        const clearMethod = arrayType.methods.find(m => m.name.endsWith('_clear') && !m.name.endsWith('_clear_and_add_all'));
        if (clearMethod) {
            lines.push(`    /// Removes all elements from this array`);
            lines.push(`    public func removeAll() {`);
            lines.push(`        ${clearMethod.name}(ptr)`);
            lines.push(`    }`);
            lines.push('');
        }

        // Remove at method
        const removeAtMethod = arrayType.methods.find(m => m.name.endsWith('_remove_at'));
        if (removeAtMethod) {
            lines.push(`    /// Removes the element at the specified index`);
            lines.push(`    public func remove(at index: Int32) {`);
            lines.push(`        precondition(index >= 0 && index < count, "Index out of bounds")`);
            lines.push(`        ${removeAtMethod.name}(ptr, index)`);
            lines.push(`    }`);
            lines.push('');
        }

        // Set size method
        const setSizeMethod = arrayType.methods.find(m => m.name.endsWith('_set_size'));
        if (setSizeMethod) {
            lines.push(`    /// Sets the size of this array`);
            lines.push(`    public func resize(to newSize: Int32) {`);

            if (this.isPrimitiveArrayType(elementType)) {
                let defaultValue = '0';
                if (elementType === 'float') defaultValue = '0.0';
                else if (elementType === 'bool') defaultValue = 'false';
                lines.push(`        ${setSizeMethod.name}(ptr, newSize, ${defaultValue})`);
            } else {
                lines.push(`        ${setSizeMethod.name}(ptr, newSize, nil)`);
            }

            lines.push(`    }`);
            lines.push('');
        }

        // Ensure capacity method
        const ensureCapacityMethod = arrayType.methods.find(m => m.name.endsWith('_ensure_capacity'));
        if (ensureCapacityMethod) {
            lines.push(`    /// Ensures the array has at least the specified capacity`);
            lines.push(`    public func ensureCapacity(_ capacity: Int32) {`);
            lines.push(`        ${ensureCapacityMethod.name}(ptr, capacity)`);
            lines.push(`    }`);
            lines.push('');
        }

        // Deinit for memory management
        lines.push(`    deinit {`);
        lines.push(`        if ownsMemory {`);
        const disposeMethod = arrayType.destructors?.[0];
        if (disposeMethod) {
            lines.push(`            ${disposeMethod.name}(ptr)`);
        }
        lines.push(`        }`);
        lines.push(`    }`);

        lines.push(`}`);

        return lines;
    }

    private extractArrayElementType(arrayTypeName: string): string {
        // spine_array_animation -> animation
        // spine_array_int -> int
        const match = arrayTypeName.match(/spine_array_(.+)/);
        if (match) {
            return match[1];
        }
        return 'Any';
    }

    private mapArrayElementTypeToSwift(elementType: string): string {
        if (this.isPrimitiveArrayType(elementType)) {
            if (elementType === 'int') return 'Int32';
            if (elementType === 'float') return 'Float';
            if (elementType === 'bool') return 'Bool';
            if (elementType === 'unsigned_short') return 'UInt16';
            if (elementType === 'property_id') return 'Int64';
        }

        // For object types, make them optional since arrays can contain nulls
        const swiftType = this.getSwiftClassName(`spine_${elementType}`);
        return swiftType + '?';
    }

    private isPrimitiveArrayType(elementType: string): boolean {
        return ['int', 'float', 'bool', 'unsigned_short', 'property_id'].includes(elementType);
    }
}