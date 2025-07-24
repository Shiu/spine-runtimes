import * as fs from 'node:fs';
import * as path from 'node:path';
import { fileURLToPath } from 'node:url';
import type { CClassOrStruct, CEnum, CMethod, CParameter } from '../../../spine-c/codegen/src/c-types.js';
import { toSnakeCase } from '../../../spine-c/codegen/src/types.js';

const __dirname = path.dirname(fileURLToPath(import.meta.url));
const LICENSE_HEADER = fs.readFileSync(path.join(__dirname, '../../../spine-cpp/src/spine/Skeleton.cpp'), 'utf8')
    .split('\n')
    .slice(0, 28)
    .map((line, index, array) => {
        // Convert C++ block comment format to Dart line comment format
        if (index === 0 && line.startsWith('/****')) {
            // First line: remove asterisks
            return '//' + line.substring(4).replace(/\*+/g, '');
        } else if (index === array.length - 1 && (line.startsWith(' ****') || line.trim() === '*/')) {
            // Last line: remove asterisks, use // not ///
            return '//' + line.substring(line.indexOf('*') + 1).replace(/\*+/g, '').replace(/\//g, '');
        } else if (line.startsWith(' ****') || line.trim() === '*/') {
            return '// ' + line.substring(4);
        } else if (line.startsWith(' * ')) {
            return '// ' + line.substring(3);
        } else if (line.startsWith(' *')) {
            return '//' + line.substring(2);
        } else {
            return line;
        }
    })
    .join('\n');

/** Generates Dart wrapper files from C intermediate representation */
export class DartWriter {
    private enumNames = new Set<string>();
    private inheritanceMap = new Map<string, string>(); // child -> parent
    private classMap = new Map<string, CClassOrStruct>(); // name -> class

    constructor(private outputDir: string) {
        this.cleanOutputDirectory();
    }

    private cleanOutputDirectory(): void {
        if (fs.existsSync(this.outputDir)) {
            console.log(`Cleaning ${this.outputDir}...`);
            fs.rmSync(this.outputDir, { recursive: true, force: true });
        }
        fs.mkdirSync(this.outputDir, { recursive: true });
    }

    /** Build inheritance relationships and class mapping */
    private buildInheritanceInfo(cTypes: CClassOrStruct[]): void {
        // Build class map
        for (const cType of cTypes) {
            this.classMap.set(cType.name, cType);
        }

        // Build inheritance map (child -> immediate parent)
        for (const cType of cTypes) {
            if (cType.cppType.superTypes && cType.cppType.superTypes.length > 0) {
                // Find the immediate parent (most specific supertype)
                let immediateParent: string | null = null;
                
                for (const superType of cType.cppType.superTypes) {
                    const parentCName = `spine_${toSnakeCase(superType)}`;
                    // Check if this parent exists in our class list
                    if (this.classMap.has(parentCName)) {
                        // Use the first valid supertype as immediate parent
                        // (In most cases there's only one direct parent)
                        if (!immediateParent) {
                            immediateParent = parentCName;
                        }
                    }
                }
                
                if (immediateParent) {
                    this.inheritanceMap.set(cType.name, immediateParent);
                }
            }
        }
    }

    /** Sort classes by inheritance dependency (base classes first) */
    private sortByInheritance(cTypes: CClassOrStruct[]): CClassOrStruct[] {
        const sorted: CClassOrStruct[] = [];
        const processed = new Set<string>();
        
        const processClass = (cType: CClassOrStruct) => {
            if (processed.has(cType.name)) {
                return;
            }
            
            // Process parent first
            const parentName = this.inheritanceMap.get(cType.name);
            if (parentName) {
                const parent = this.classMap.get(parentName);
                if (parent) {
                    processClass(parent);
                }
            }
            
            // Then process this class
            sorted.push(cType);
            processed.add(cType.name);
        };
        
        // Process all classes
        for (const cType of cTypes) {
            processClass(cType);
        }
        
        return sorted;
    }

    /** Check if a class is abstract */
    private isAbstract(cType: CClassOrStruct): boolean {
        return cType.cppType.isAbstract === true;
    }

    /** Get parent class name for inheritance */
    private getParentClass(cType: CClassOrStruct): string | null {
        return this.inheritanceMap.get(cType.name) || null;
    }

    /** Get root parent class name (for accessing static bindings) */
    private getRootParent(cType: CClassOrStruct): string {
        let current = cType.name;
        while (this.inheritanceMap.has(current)) {
            current = this.inheritanceMap.get(current)!;
        }
        return current;
    }

    /** Check if a method is inherited from a parent class */
    private isMethodInherited(method: CMethod, cType: CClassOrStruct): boolean {
        // Find if this method exists in any parent class
        const parentName = this.getParentClass(cType);
        if (!parentName) {
            return false;
        }
        
        const parent = this.classMap.get(parentName);
        if (!parent) {
            return false;
        }
        
        // Check if parent has this method (by looking at the method name pattern)
        const methodSuffix = this.getMethodSuffix(method.name, cType.name);
        const parentMethodName = `${parentName}_${methodSuffix}`;
        
        const hasInParent = parent.methods.some(m => m.name === parentMethodName);
        if (hasInParent) {
            return true;
        }
        
        // Recursively check parent's parents
        return this.isMethodInherited(method, parent);
    }

    /** Extract method suffix from full method name */
    private getMethodSuffix(methodName: string, typeName: string): string {
        const prefix = `${typeName}_`;
        if (methodName.startsWith(prefix)) {
            return methodName.slice(prefix.length);
        }
        return methodName;
    }

    async writeAll(cTypes: CClassOrStruct[], cEnums: CEnum[], cArrayTypes: CClassOrStruct[]): Promise<void> {
        // Collect enum names first
        for (const cEnum of cEnums) {
            this.enumNames.add(cEnum.name);
        }

        // Build inheritance information
        this.buildInheritanceInfo(cTypes);

        // Sort classes by inheritance dependency (base classes first)
        const sortedTypes = this.sortByInheritance(cTypes);

        // Write enums
        for (const cEnum of cEnums) {
            await this.writeEnum(cEnum);
        }

        // Write wrapper classes in dependency order
        for (const cType of sortedTypes) {
            await this.writeClass(cType);
        }

        // Write all array specializations in a single file
        await this.writeArrays(cArrayTypes);

        // Write main export file
        await this.writeExportFile(cTypes, cEnums, cArrayTypes);

        // Run dart fix to clean up generated code
        await this.runDartFix();
    }


    private async writeEnum(cEnum: CEnum): Promise<void> {
        const lines: string[] = [];
        const dartName = this.toDartTypeName(cEnum.name);

        lines.push(LICENSE_HEADER);
        lines.push('');
        lines.push('// AUTO GENERATED FILE, DO NOT EDIT.');
        lines.push('');
        lines.push(`/// ${dartName} enum`);
        lines.push(`enum ${dartName} {`);

        // Write enum values
        for (let i = 0; i < cEnum.values.length; i++) {
            const value = cEnum.values[i];
            const dartValueName = this.toDartEnumValueName(value.name, cEnum.name);
            const comma = i < cEnum.values.length - 1 ? ',' : ';';

            if (value.value !== undefined) {
                lines.push(`  ${dartValueName}(${value.value})${comma}`);
            } else {
                lines.push(`  ${dartValueName}(${i})${comma}`);
            }
        }

        lines.push('');
        lines.push(`  const ${dartName}(this.value);`);
        lines.push('  final int value;');
        lines.push('');
        lines.push(`  static ${dartName} fromValue(int value) {`);
        lines.push('    return values.firstWhere(');
        lines.push('      (e) => e.value == value,');
        lines.push(`      orElse: () => throw ArgumentError('Invalid ${dartName} value: \$value'),`);
        lines.push('    );');
        lines.push('  }');
        lines.push('}');

        const fileName = `${toSnakeCase(dartName)}.dart`;
        const filePath = path.join(this.outputDir, fileName);
        fs.writeFileSync(filePath, lines.join('\n'));
    }

    private async writeClass(cType: CClassOrStruct): Promise<void> {
        const lines: string[] = [];
        const dartClassName = this.toDartTypeName(cType.name);

        lines.push(LICENSE_HEADER);
        lines.push('');
        lines.push('// AUTO GENERATED FILE, DO NOT EDIT.');
        lines.push('');
        lines.push("import 'dart:ffi';");
        
        // Check if we need package:ffi for string conversions
        const needsPackageFfi = this.needsStringConversions(cType);
        if (needsPackageFfi) {
            lines.push("import 'package:ffi/ffi.dart';");
        }
        
        lines.push("import 'spine_flutter_bindings_generated.dart';");
        lines.push("import '../spine_bindings.dart';");

        // Check if this class has an rtti method
        const hasRttiMethod = cType.methods.some(m => m.name === `${cType.name}_rtti` && m.parameters.length === 0);
        if (hasRttiMethod) {
            lines.push("import 'rtti.dart';");
        }

        // Add parent class import if needed
        const parentName = this.getParentClass(cType);
        if (parentName) {
            const parentDartName = this.toDartTypeName(parentName);
            lines.push(`import '${toSnakeCase(parentDartName)}.dart';`);
        }

        // Collect all imports needed (arrays, enums, and other types)
        const allImports = this.collectAllImports(cType);
        for (const importFile of allImports) {
            // Skip rtti.dart if we already added it above
            if (importFile === 'rtti.dart' && hasRttiMethod) {
                continue;
            }
            // Skip parent class import if we already added it above
            if (parentName) {
                const parentDartName = this.toDartTypeName(parentName);
                if (importFile === `${toSnakeCase(parentDartName)}.dart`) {
                    continue;
                }
            }
            lines.push(`import '${importFile}';`);
        }

        lines.push('');
        lines.push(`/// ${dartClassName} wrapper`);
        
        // Build class declaration with inheritance
        let classDeclaration = `class ${dartClassName}`;
        if (this.isAbstract(cType)) {
            classDeclaration = `abstract ${classDeclaration}`;
        }
        
        if (parentName) {
            const parentDartName = this.toDartTypeName(parentName);
            classDeclaration += ` extends ${parentDartName}`;
        } else {
            classDeclaration += ` implements Finalizable`;
        }
        
        lines.push(`${classDeclaration} {`);
        
        // Every class has its own typed pointer field
        lines.push(`  final Pointer<${cType.name}_wrapper> _ptr;`);
        lines.push('');

        // Constructor from pointer
        if (parentName) {
            // Derived class - initialize own pointer and call super constructor with cast
            lines.push(`  ${dartClassName}.fromPointer(this._ptr) : super.fromPointer(_ptr.cast());`);
        } else {
            // Base class - set the pointer directly  
            lines.push(`  ${dartClassName}.fromPointer(this._ptr);`);
        }
        
        lines.push('');
        lines.push('  /// Get the native pointer for FFI calls');
        lines.push(`  Pointer get nativePtr => _ptr;`);
        lines.push('');

        // Write constructors (only for concrete classes)
        if (!this.isAbstract(cType)) {
            for (const constr of cType.constructors) {
                lines.push(this.writeConstructor(dartClassName, constr, cType));
                lines.push('');
            }
        }

        // Filter out methods with raw pointer parameters and inherited methods
        const validMethods = cType.methods.filter(method => {
            if (this.hasRawPointerParameters(method)) {
                console.log(`  Skipping method ${cType.name}::${method.name}: has raw pointer parameters`);
                return false;
            }
            if (this.isMethodInherited(method, cType)) {
                console.log(`  Skipping method ${cType.name}::${method.name}: inherited from parent`);
                return false;
            }
            return true;
        });

        // Renumber methods that need it
        const renumberedMethods = this.renumberMethods(validMethods, cType.name);

        // Write methods
        for (const methodInfo of renumberedMethods) {
            const { method, renamedMethod } = methodInfo;
            
            // Special case: SlotPose hasDarkColor should be a getter
            if (cType.name === 'spine_slot_pose' && method.name === 'spine_slot_pose_has_dark_color') {
                lines.push(this.writeGetter(cType, method, 'hasDarkColor'));
            } else if (this.isGetter(method)) {
                lines.push(this.writeGetter(cType, method, renamedMethod));
            } else if (this.isSetter(method)) {
                lines.push(this.writeSetter(cType, method, renamedMethod));
            } else {
                lines.push(this.writeMethod(cType, method, renamedMethod));
            }
            lines.push('');
        }

        // Write dispose method if destructor exists
        if (cType.destructor) {
            lines.push('  void dispose() {');
            lines.push(`    SpineBindings.bindings.${cType.destructor.name}(_ptr);`);
            lines.push('  }');
        }

        lines.push('}');

        const fileName = `${toSnakeCase(dartClassName)}.dart`;
        const filePath = path.join(this.outputDir, fileName);
        fs.writeFileSync(filePath, lines.join('\n'));
    }

    private async writeArrays(cArrayTypes: CClassOrStruct[]): Promise<void> {
        const lines: string[] = [];
        
        lines.push(LICENSE_HEADER);
        lines.push('');
        lines.push('// AUTO GENERATED FILE, DO NOT EDIT.');
        lines.push('');
        lines.push("import 'dart:ffi';");
        lines.push("import 'package:ffi/ffi.dart';");
        lines.push("import 'spine_flutter_bindings_generated.dart';");
        lines.push("import '../spine_bindings.dart';");
        lines.push("import '../native_array.dart';");
        
        // Collect all imports needed for all array types
        const imports = new Set<string>();
        for (const arrayType of cArrayTypes) {
            const elementType = this.extractArrayElementType(arrayType.name);
            if (!this.isPrimitive(elementType) && !['int', 'float', 'bool', 'unsigned_short', 'property_id'].includes(elementType.toLowerCase())) {
                imports.add(`import '${toSnakeCase(elementType)}.dart';`);
                
                // If this element type is abstract, we need to import all its concrete subclasses too
                const cElementType = `spine_${toSnakeCase(elementType)}`;
                const cClass = this.classMap.get(cElementType);
                if (cClass && this.isAbstract(cClass)) {
                    const concreteSubclasses = this.getConcreteSubclasses(cElementType);
                    for (const subclass of concreteSubclasses) {
                        const dartSubclass = this.toDartTypeName(subclass);
                        imports.add(`import '${toSnakeCase(dartSubclass)}.dart';`);
                    }
                }
            }
        }
        
        // Add sorted imports
        for (const imp of Array.from(imports).sort()) {
            lines.push(imp);
        }
        
        // Generate each array class
        for (const arrayType of cArrayTypes) {
            lines.push('');
            lines.push(...this.generateArrayClass(arrayType));
        }
        
        const filePath = path.join(this.outputDir, 'arrays.dart');
        fs.writeFileSync(filePath, lines.join('\n'));
    }
    
    private generateArrayClass(arrayType: CClassOrStruct): string[] {
        const lines: string[] = [];
        const dartClassName = this.toDartTypeName(arrayType.name);
        const elementType = this.extractArrayElementType(arrayType.name);
        

        lines.push(`/// Array of ${elementType} elements`);
        lines.push(`class ${dartClassName} extends NativeArray<${this.toDartElementType(elementType)}> {`);
        // Generate typed constructor - arrays use the array wrapper type
        const arrayWrapperType = `${arrayType.name}_wrapper`;
        lines.push(`  ${dartClassName}.fromPointer(Pointer<${arrayWrapperType}> super.ptr);`);
        lines.push('');

        // Find size and buffer methods
        const sizeMethod = arrayType.methods.find(m => m.name.endsWith('_size') && !m.name.endsWith('_set_size'));
        const bufferMethod = arrayType.methods.find(m => m.name.endsWith('_buffer'));
        const setMethod = arrayType.methods.find(m => m.name.endsWith('_set') && m.parameters.length === 3); // self, index, value

        if (sizeMethod) {
            lines.push('  @override');
            lines.push('  int get length {');
            lines.push(`    return SpineBindings.bindings.${sizeMethod.name}(nativePtr.cast());`);
            lines.push('  }');
            lines.push('');
        }

        if (bufferMethod) {
            lines.push('  @override');
            lines.push(`  ${this.toDartElementType(elementType)} operator [](int index) {`);
            lines.push('    if (index < 0 || index >= length) {');
            lines.push('      throw RangeError.index(index, this, \'index\');');
            lines.push('    }');
            
            lines.push(`    final buffer = SpineBindings.bindings.${bufferMethod.name}(nativePtr.cast());`);

            // Handle different element types
            if (elementType === 'int') {
                lines.push('    return buffer.cast<Int32>()[index];');
            } else if (elementType === 'float') {
                lines.push('    return buffer.cast<Float>()[index];');
            } else if (elementType === 'bool') {
                lines.push('    return buffer.cast<Int32>()[index] != 0;');
            } else if (elementType === 'unsigned_short') {
                lines.push('    return buffer.cast<Uint16>()[index];');
            } else if (elementType === 'property_id') {
                // PropertyId buffer returns int instead of Pointer<Int64> due to C codegen bug
                // This will cause a compile error, but it's a known issue with the C API
                lines.push('    // NOTE: This will not compile due to C API bug - buffer() returns int instead of Pointer');
                lines.push('    return buffer.cast<Int64>()[index];');
            } else {
                // For object types, the buffer contains pointers
                const dartElementType = this.toDartTypeName(`spine_${toSnakeCase(elementType)}`);
                const cElementType = `spine_${toSnakeCase(elementType)}`;
                const cClass = this.classMap.get(cElementType);
                
                if (cClass && this.isAbstract(cClass)) {
                    // Use RTTI to determine concrete type for abstract classes
                    const rttiCode = this.generateRttiBasedInstantiation(dartElementType, 'buffer[index]', cClass);
                    lines.push(`    ${rttiCode}`);
                } else {
                    lines.push(`    return ${dartElementType}.fromPointer(buffer[index]);`);
                }
            }

            lines.push('  }');
            lines.push('');
        }

        // Override []= if there's a set method
        if (setMethod) {
            lines.push('  @override');
            lines.push(`  void operator []=(int index, ${this.toDartElementType(elementType)} value) {`);
            lines.push('    if (index < 0 || index >= length) {');
            lines.push('      throw RangeError.index(index, this, \'index\');');
            lines.push('    }');
            
            // Convert value to C type
            const param = setMethod.parameters[2]; // The value parameter
            const convertedValue = this.convertDartToC('value', param);
            lines.push(`    SpineBindings.bindings.${setMethod.name}(nativePtr.cast(), index, ${convertedValue});`);
            lines.push('  }');
        }

        lines.push('}');
        
        return lines;
    }

    private async writeExportFile(cTypes: CClassOrStruct[], cEnums: CEnum[], cArrayTypes: CClassOrStruct[]): Promise<void> {
        const lines: string[] = [];

        lines.push(LICENSE_HEADER);
        lines.push('');
        lines.push('// AUTO GENERATED FILE, DO NOT EDIT.');
        lines.push('');
        lines.push('// Export all generated types');
        lines.push('');

        lines.push(`export 'native_array.dart';`);
        lines.push('');

        // Export enums
        if (cEnums.length > 0) {
            lines.push('// Enums');
            for (const cEnum of cEnums) {
                const dartName = this.toDartTypeName(cEnum.name);
                lines.push(`export 'generated/${toSnakeCase(dartName)}.dart';`);
            }
            lines.push('');
        }

        // Export classes
        if (cTypes.length > 0) {
            lines.push('// Classes');
            for (const cType of cTypes) {
                const dartName = this.toDartTypeName(cType.name);
                lines.push(`export 'generated/${toSnakeCase(dartName)}.dart';`);
            }
            lines.push('');
        }
        
        // Export arrays
        if (cArrayTypes.length > 0) {
            lines.push('// Arrays');
            lines.push(`export 'generated/arrays.dart';`);
        }

        const filePath = path.join(path.dirname(path.dirname(this.outputDir)), 'spine_flutter.dart');
        fs.writeFileSync(filePath, lines.join('\n'));
    }

    // Helper methods

    private writeConstructor(dartClassName: string, constr: CMethod, cType: CClassOrStruct): string {
        const lines: string[] = [];

        const params = constr.parameters.map(p => {
            const dartType = this.toDartParameterType(p);
            return `${dartType} ${p.name}`;
        }).join(', ');

        const args = constr.parameters.map(p => {
            return this.convertDartToC(p.name, p);
        }).join(', ');

        // Determine constructor name suffix
        const cTypeName = `spine_${toSnakeCase(dartClassName)}`;
        let constructorName = constr.name.replace(`${cTypeName}_create`, '');

        // Handle numeric suffixes and special cases
        if (constructorName) {
            // If it's just a number, handle it generically
            if (/^\d+$/.test(constructorName)) {
                // Special case for Color::create2 specifically
                if (cType.name === 'spine_color' && constr.name === 'spine_color_create2') {
                    constructorName = 'fromRGBA';
                }
                // For other numbered constructors, look at parameters to generate a name
                else if (constr.parameters.length > 0) {
                    // If first param is the same type as what we're constructing, it's likely a copy/from constructor
                    const firstParamType = constr.parameters[0].cType.replace('*', '').trim();
                    if (firstParamType === cType.name) {
                        constructorName = 'from';
                    } else {
                        // Otherwise use a generic variant name
                        constructorName = `variant${constructorName}`;
                    }
                } else {
                    constructorName = `variant${constructorName}`;
                }
            } else if (constructorName.startsWith('_')) {
                // Handle underscored names (e.g., create_with_data -> withData)
                constructorName = this.toCamelCase(constructorName.slice(1));
            }
        }

        const factoryName = constructorName ? `.${constructorName}` : '';

        lines.push(`  factory ${dartClassName}${factoryName}(${params}) {`);
        lines.push(`    final ptr = SpineBindings.bindings.${constr.name}(${args});`);
        lines.push(`    return ${dartClassName}.fromPointer(ptr);`);
        lines.push('  }');

        return lines.join('\n');
    }

    private writeMethod(cType: CClassOrStruct, method: CMethod, renamedMethod?: string): string {
        const lines: string[] = [];
        const dartReturnType = this.toDartReturnType(method.returnType);
        let methodName = renamedMethod || this.toDartMethodName(method.name, cType.name);

        // Skip if this is handled as getter/setter
        if (this.isGetter(method) || this.isSetter(method)) {
            return '';
        }

        // Check if this is a static method (no self parameter)
        const isStatic = method.parameters.length === 0 ||
                        (method.parameters[0].name !== 'self' &&
                         !method.parameters[0].cType.startsWith(cType.name));

        // Rename static rtti method to avoid conflict with getter
        if (isStatic && methodName === 'rtti') {
            methodName = 'rttiStatic';
        }

        // Parameters (skip 'self' parameter for instance methods)
        const paramStartIndex = isStatic ? 0 : 1;
        const params = method.parameters.slice(paramStartIndex).map(p => {
            const dartType = this.toDartParameterType(p);
            return `${dartType} ${p.name}`;
        }).join(', ');

        // Arguments
        const args = method.parameters.map((p, i) => {
            if (!isStatic && i === 0) return '_ptr'; // self parameter
            return this.convertDartToC(p.name, p);
        }).join(', ');

        // Generate method signature with appropriate modifier
        const methodSignature = isStatic ? `  static ${dartReturnType} ${methodName}` : `  ${dartReturnType} ${methodName}`;

        lines.push(`${methodSignature}(${params}) {`);

        // Always use the global bindings
        const bindingsRef = 'SpineBindings.bindings';

        if (method.returnType === 'void') {
            lines.push(`    ${bindingsRef}.${method.name}(${args});`);
        } else {
            lines.push(`    final result = ${bindingsRef}.${method.name}(${args});`);
            lines.push(`    ${this.generateReturnConversion(method.returnType, 'result')}`);
        }

        lines.push('  }');

        return lines.join('\n');
    }

    private writeGetter(cType: CClassOrStruct, method: CMethod, renamedMethod?: string): string {
        const lines: string[] = [];
        const propertyName = renamedMethod || this.extractPropertyName(method.name, cType.name);
        const dartReturnType = this.toDartReturnType(method.returnType);
        lines.push(`  ${dartReturnType} get ${propertyName} {`);
        lines.push(`    final result = SpineBindings.bindings.${method.name}(_ptr);`);
        lines.push(`    ${this.generateReturnConversion(method.returnType, 'result')}`);
        lines.push('  }');

        return lines.join('\n');
    }

    private writeSetter(cType: CClassOrStruct, method: CMethod, renamedMethod?: string): string {
        const lines: string[] = [];
        let propertyName = renamedMethod || this.extractPropertyName(method.name, cType.name);
        const param = method.parameters[1]; // First param is self
        const dartType = this.toDartParameterType(param);

        // Handle numeric suffixes in setter names
        const match = propertyName.match(/^(\w+)_(\d+)$/);
        if (match) {
            // Convert property_2 to property2
            propertyName = `${match[1]}${match[2]}`;
        } else if (/^\d+$/.test(propertyName)) {
            // If property name is just a number, prefix with 'set'
            propertyName = `set${propertyName}`;
        }

        lines.push(`  set ${propertyName}(${dartType} value) {`);
        lines.push(`    SpineBindings.bindings.${method.name}(_ptr, ${this.convertDartToC('value', param)});`);
        lines.push('  }');

        return lines.join('\n');
    }

    private isGetter(method: CMethod): boolean {
        // Traditional getter with _get_ in name
        if (method.name.includes('_get_') && method.parameters.length === 1) {
            return true;
        }
        
        // Boolean methods that start with 'has_' or 'is_' and take only self parameter
        if (method.returnType === 'bool' && method.parameters.length === 1) {
            if (method.name.includes('_has_') || method.name.includes('_is_')) {
                return true;
            }
        }
        
        return false;
    }

    private isSetter(method: CMethod): boolean {
        // Must return void and have 2 parameters (self + value)
        if (method.returnType !== 'void' || method.parameters.length !== 2) {
            return false;
        }
        
        // Traditional setter with _set_ in name
        if (method.name.includes('_set_')) {
            return true;
        }
        
        return false;
    }

    private extractPropertyName(methodName: string, typeName: string): string {
        // Remove type prefix and get/set
        const prefix = `${typeName}_`;
        let name = methodName.startsWith(prefix) ? methodName.slice(prefix.length) : methodName;

        if (name.startsWith('get_')) {
            name = name.slice(4);
        } else if (name.startsWith('set_')) {
            name = name.slice(4);
        }

        // Special case: if the property name is "update_cache", rename to "updateCacheList"
        // to avoid collision with the updateCache() method
        if (name === 'update_cache') {
            return 'updateCacheList';
        }

        // Special case: if property name is a type name, suffix with 'Value'
        const typeNames = ['int', 'float', 'double', 'bool', 'string'];
        if (typeNames.includes(name.toLowerCase())) {
            return `${this.toCamelCase(name)}Value`;
        }

        return this.toCamelCase(name);
    }

    private toDartTypeName(cTypeName: string): string {
        // spine_animation -> Animation
        if (cTypeName.startsWith('spine_')) {
            const name = cTypeName.slice(6);
            return this.toPascalCase(name);
        }
        return this.toPascalCase(cTypeName);
    }

    private toDartMethodName(cMethodName: string, cTypeName: string): string {
        // spine_animation_apply -> apply
        const prefix = `${cTypeName}_`;
        if (cMethodName.startsWith(prefix)) {
            return this.toCamelCase(cMethodName.slice(prefix.length));
        }
        return this.toCamelCase(cMethodName);
    }

    private toDartEnumValueName(cValueName: string, cEnumName: string): string {
        // SPINE_BLEND_MODE_NORMAL -> normal
        const enumNameUpper = cEnumName.toUpperCase();

        // Try different prefix patterns
        const prefixes = [
            `SPINE_${enumNameUpper}_`,
            `${enumNameUpper}_`,
            'SPINE_'
        ];

        let name = cValueName;
        for (const prefix of prefixes) {
            if (name.startsWith(prefix)) {
                name = name.slice(prefix.length);
                break;
            }
        }

        const enumValue = this.toCamelCase(name.toLowerCase());
        
        // Special case for MixDirection enum - prefix with 'direction'
        if (cEnumName === 'spine_mix_direction' && ['in', 'out'].includes(enumValue)) {
            return `direction${this.toPascalCase(enumValue)}`;
        }
        
        return enumValue;
    }

    private toDartReturnType(cType: string): string {
        if (cType === 'void') return 'void';
        // Handle char* with or without spaces
        if (cType === 'char*' || cType === 'char *' || cType === 'const char*' || cType === 'const char *') return 'String';
        if (cType === 'float' || cType === 'double') return 'double';
        if (cType === 'int' || cType === 'size_t' || cType === 'int32_t' || cType === 'uint32_t') return 'int';
        if (cType === 'bool') return 'bool';

        // Handle enum types
        if (this.enumNames.has(cType)) {
            return this.toDartTypeName(cType);
        }

        // Handle array types
        if (cType.startsWith('spine_array_')) {
            return this.toDartTypeName(cType);
        }

        // Handle other spine types
        if (cType.startsWith('spine_')) {
            return this.toDartTypeName(cType);
        }

        return 'dynamic';
    }

    private toDartParameterType(param: CParameter): string {
        // Handle output parameters (non-const references that become pointers)
        if (param.isOutput) {
            const baseType = param.cType.replace('*', '').trim();
            return `Pointer<${this.getPrimitiveFFIType(baseType + '*')}>`;
        }

        // String parameters should stay as String, not dynamic (handle with or without spaces)
        if (param.cType === 'char*' || param.cType === 'char *' || param.cType === 'const char*' || param.cType === 'const char *') {
            return 'String';
        }

        return this.toDartReturnType(param.cType);
    }

    private toDartElementType(elementType: string): string {
        // Handle pointer types
        if (elementType.endsWith('*')) {
            const baseType = elementType.slice(0, -1).trim();
            return this.toDartTypeName(`spine_${toSnakeCase(baseType)}`);
        }

        // For primitive types, return the Dart type directly
        if (elementType === 'int' || elementType === 'int32_t' || elementType === 'uint32_t' || elementType === 'size_t') {
            return 'int';
        }
        if (elementType === 'unsigned_short') {
            return 'int';  // Dart doesn't have unsigned short, use int
        }
        if (elementType === 'property_id' || elementType === 'int64_t') {
            return 'int';  // PropertyId is int64_t which maps to int in Dart
        }
        if (elementType === 'float' || elementType === 'double') {
            return 'double';
        }
        if (elementType === 'bool') {
            return 'bool';
        }

        // For object types that are already in PascalCase (from extractArrayElementType)
        // just return them as-is
        return elementType;
    }

    private getPrimitiveFFIType(cType: string): string {
        switch (cType) {
            case 'float*': return 'Float';
            case 'double*': return 'Double';
            case 'int*': return 'Int';
            case 'bool*': return 'Bool';
            default: return 'Void';
        }
    }

    private convertDartToC(dartValue: string, param: CParameter): string {
        // Handle char* with or without spaces
        if (param.cType === 'char*' || param.cType === 'char *' || param.cType === 'const char*' || param.cType === 'const char *') {
            return `${dartValue}.toNativeUtf8().cast<Char>()`;
        }

        // Check if it's an enum type
        if (this.enumNames.has(param.cType)) {
            return `${dartValue}.value`;
        }

        // Check if it's an array type - arrays use _nativeArray
        if (param.cType.startsWith('spine_array_')) {
            return `${dartValue}.nativePtr.cast()`;
        }

        // Regular spine types have nativePtr
        if (param.cType.startsWith('spine_')) {
            return `${dartValue}.nativePtr.cast()`;
        }

        return dartValue;
    }

    private generateReturnConversion(cReturnType: string, resultVar: string): string {
        // Handle char* with or without spaces
        if (cReturnType === 'char*' || cReturnType === 'char *' || cReturnType === 'const char*' || cReturnType === 'const char *') {
            return `return ${resultVar}.cast<Utf8>().toDartString();`;
        }

        // Handle enum types
        if (this.enumNames.has(cReturnType)) {
            const dartType = this.toDartTypeName(cReturnType);
            return `return ${dartType}.fromValue(${resultVar});`;
        }

        if (cReturnType.startsWith('spine_array_')) {
            const dartType = this.toDartTypeName(cReturnType);
            return `return ${dartType}.fromPointer(${resultVar});`;
        }

        if (cReturnType.startsWith('spine_')) {
            const dartType = this.toDartTypeName(cReturnType);
            const cClass = this.classMap.get(cReturnType);
            if (cClass && this.isAbstract(cClass)) {
                // Use RTTI to determine concrete type and instantiate correctly
                return this.generateRttiBasedInstantiation(dartType, resultVar, cClass);
            }
            return `return ${dartType}.fromPointer(${resultVar});`;
        }

        return `return ${resultVar};`;
    }

    private generateRttiBasedInstantiation(abstractType: string, resultVar: string, abstractClass: CClassOrStruct): string {
        const lines: string[] = [];
        
        // Get concrete subclasses for this abstract class
        const concreteSubclasses = this.getConcreteSubclasses(abstractClass.name);
        
        if (concreteSubclasses.length === 0) {
            return `throw UnsupportedError('Cannot instantiate abstract class ${abstractType} from pointer - no concrete subclasses found');`;
        }
        
        lines.push(`final rtti = SpineBindings.bindings.${abstractClass.name}_get_rtti(${resultVar});`);
        lines.push(`final className = SpineBindings.bindings.spine_rtti_get_class_name(rtti).cast<Utf8>().toDartString();`);
        lines.push(`switch (className) {`);
        
        for (const subclass of concreteSubclasses) {
            const dartSubclass = this.toDartTypeName(subclass);
            lines.push(`  case '${subclass}':`);
            lines.push(`    return ${dartSubclass}.fromPointer(${resultVar}.cast());`);
        }
        
        lines.push(`  default:`);
        lines.push(`    throw UnsupportedError('Unknown concrete type: \$className for abstract class ${abstractType}');`);
        lines.push(`}`);
        
        return lines.join('\n    ');
    }

    private getConcreteSubclasses(abstractClassName: string): string[] {
        const concreteSubclasses: string[] = [];
        
        // Find all classes that inherit from this abstract class
        for (const [childName, parentName] of this.inheritanceMap.entries()) {
            if (parentName === abstractClassName) {
                const childClass = this.classMap.get(childName);
                if (childClass && !this.isAbstract(childClass)) {
                    concreteSubclasses.push(childName);
                } else {
                    // Recursively check for concrete subclasses
                    concreteSubclasses.push(...this.getConcreteSubclasses(childName));
                }
            }
        }
        
        return concreteSubclasses;
    }

    private collectAllImports(cType: CClassOrStruct): Set<string> {
        const imports = new Set<string>();
        const currentTypeName = this.toDartTypeName(cType.name);
        const currentFileName = `${toSnakeCase(currentTypeName)}.dart`;

        // Collect from methods (return types and parameters)
        // Only consider methods that will actually be generated (skip raw pointer methods)
        let hasArrays = false;
        for (const method of cType.methods) {
            // Skip methods with raw pointer parameters - they won't be generated
            if (this.hasRawPointerParameters(method)) {
                continue;
            }
            // Return type
            if (method.returnType.startsWith('spine_array_')) {
                hasArrays = true;
            }
            // Check for spine types in return types (including pointer types)
            else if (method.returnType.startsWith('spine_')) {
                const cleanType = method.returnType.replace('*', '').trim();
                if (!this.isPrimitive(cleanType)) {
                    const typeName = this.toDartTypeName(cleanType);
                    const fileName = `${toSnakeCase(typeName)}.dart`;
                    // Skip self-imports
                    if (fileName !== currentFileName) {
                        imports.add(fileName);
                    }
                    
                    // If this return type is abstract, we need to import all its concrete subclasses too
                    const returnClass = this.classMap.get(cleanType);
                    if (returnClass && this.isAbstract(returnClass)) {
                        const concreteSubclasses = this.getConcreteSubclasses(cleanType);
                        for (const subclass of concreteSubclasses) {
                            const dartSubclass = this.toDartTypeName(subclass);
                            const subclassFileName = `${toSnakeCase(dartSubclass)}.dart`;
                            if (subclassFileName !== currentFileName) {
                                imports.add(subclassFileName);
                            }
                        }
                    }
                }
            }

            // Parameters
            for (const param of method.parameters) {
                // Skip self parameter
                if (param.name === 'self') continue;

                // Arrays
                if (param.cType.startsWith('spine_array_')) {
                    hasArrays = true;
                }
                // Enums
                else if (this.enumNames.has(param.cType)) {
                    const enumType = this.toDartTypeName(param.cType);
                    imports.add(`${toSnakeCase(enumType)}.dart`);
                }
                // Other spine types (handle both pointer and non-pointer types)
                else if (param.cType.startsWith('spine_')) {
                    const cleanType = param.cType.replace('*', '').trim();
                    if (!this.isPrimitive(cleanType)) {
                        const typeName = this.toDartTypeName(cleanType);
                        const fileName = `${toSnakeCase(typeName)}.dart`;
                        // Skip self-imports
                        if (fileName !== currentFileName) {
                            imports.add(fileName);
                        }
                    }
                }
            }
        }

        // Collect from constructors
        for (const constr of cType.constructors) {
            for (const param of constr.parameters) {
                // Arrays
                if (param.cType.startsWith('spine_array_')) {
                    hasArrays = true;
                }
                // Enums
                else if (this.enumNames.has(param.cType)) {
                    const enumType = this.toDartTypeName(param.cType);
                    imports.add(`${toSnakeCase(enumType)}.dart`);
                }
                // Other spine types (but not primitives)
                else if (param.cType.startsWith('spine_') && !param.cType.includes('*')) {
                    const typeName = this.toDartTypeName(param.cType);
                    const fileName = `${toSnakeCase(typeName)}.dart`;
                    // Skip self-imports
                    if (fileName !== currentFileName) {
                        imports.add(fileName);
                    }
                }
            }
        }
        
        // Add arrays.dart import if any arrays are used
        if (hasArrays) {
            imports.add('arrays.dart');
        }

        return imports;
    }

    private extractArrayElementType(arrayTypeName: string): string {
        // spine_array_animation -> Animation
        // spine_array_int -> int
        const match = arrayTypeName.match(/spine_array_(.+)/);
        if (match) {
            const rawType = match[1];
            // For primitive types, return the raw type
            if (['int', 'float', 'bool', 'unsigned_short', 'property_id'].includes(rawType)) {
                return rawType;
            }
            // For object types, convert to PascalCase
            return this.toPascalCase(rawType);
        }
        return 'dynamic';
    }

    private isPrimitive(type: string): boolean {
        return ['float', 'double', 'int', 'bool', 'size_t', 'int32_t', 'uint32_t'].includes(type);
    }

    private hasRawPointerParameters(method: CMethod): boolean {
        // Check return type
        if (this.isRawPointer(method.returnType)) {
            return true;
        }

        // Check parameters
        for (const param of method.parameters) {
            if (this.isRawPointer(param.cType)) {
                return true;
            }
        }

        return false;
    }

    private isRawPointer(cType: string): boolean {
        // String types are allowed
        if (cType === 'char*' || cType === 'char *' || cType === 'const char*' || cType === 'const char *') {
            return false;
        }

        // Check if it's a pointer type (ends with * or contains *)
        if (cType.includes('*')) {
            // If it's not a spine type pointer, it's a raw pointer
            const cleanType = cType.replace('*', '').trim();
            if (!cleanType.startsWith('spine_')) {
                return true;
            }
        }

        return false;
    }

    private renumberMethods(methods: CMethod[], typeName: string): Array<{method: CMethod, renamedMethod?: string}> {
        const result: Array<{method: CMethod, renamedMethod?: string}> = [];
        
        // Group methods by their base name (without numeric suffix)
        const methodGroups = new Map<string, CMethod[]>();
        
        for (const method of methods) {
            // Extract base name without numeric suffix
            const match = method.name.match(/^(.+?)_(\d+)$/);
            if (match) {
                const baseName = match[1];
                if (!methodGroups.has(baseName)) {
                    methodGroups.set(baseName, []);
                }
                methodGroups.get(baseName)!.push(method);
            } else {
                // Method without numeric suffix
                result.push({ method });
            }
        }
        
        // Process grouped methods
        for (const [baseName, groupedMethods] of methodGroups) {
            if (groupedMethods.length === 1) {
                // Only one method left in the group - remove the numeric suffix
                const method = groupedMethods[0];
                const dartMethodName = this.toDartMethodName(baseName, typeName);
                result.push({ method, renamedMethod: dartMethodName });
            } else {
                // Multiple methods - renumber them starting from 1 (or keep special names)
                groupedMethods.sort((a, b) => {
                    const aNum = parseInt(a.name.match(/_(\d+)$/)![1]);
                    const bNum = parseInt(b.name.match(/_(\d+)$/)![1]);
                    return aNum - bNum;
                });
                
                for (let i = 0; i < groupedMethods.length; i++) {
                    const method = groupedMethods[i];
                    const newNumber = i + 1;
                    const currentNumber = parseInt(method.name.match(/_(\d+)$/)![1]);
                    
                    if (newNumber !== currentNumber) {
                        // Need to renumber
                        const baseDartName = this.toDartMethodName(baseName, typeName);
                        result.push({ method, renamedMethod: `${baseDartName}${newNumber}` });
                    } else {
                        // Number is correct
                        result.push({ method });
                    }
                }
            }
        }
        
        return result;
    }

    private toPascalCase(str: string): string {
        return str.split('_')
            .map(word => word.charAt(0).toUpperCase() + word.slice(1))
            .join('');
    }

    private toCamelCase(str: string): string {
        const pascal = this.toPascalCase(str);
        return pascal.charAt(0).toLowerCase() + pascal.slice(1);
    }

    private needsStringConversions(cType: CClassOrStruct): boolean {
        // Check if any method has string parameters or return types
        for (const method of cType.methods) {
            // Check return type
            if (method.returnType === 'char*' || method.returnType === 'char *' || 
                method.returnType === 'const char*' || method.returnType === 'const char *') {
                return true;
            }
            
            // Check parameters
            for (const param of method.parameters) {
                if (param.cType === 'char*' || param.cType === 'char *' || 
                    param.cType === 'const char*' || param.cType === 'const char *') {
                    return true;
                }
            }
            
            // Check if method returns abstract types (which use RTTI and need Utf8)
            if (method.returnType.startsWith('spine_')) {
                const cleanType = method.returnType.replace('*', '').trim();
                const returnClass = this.classMap.get(cleanType);
                if (returnClass && this.isAbstract(returnClass)) {
                    return true; // RTTI switch uses Utf8 conversion
                }
            }
        }

        // Check constructors
        for (const constr of cType.constructors) {
            for (const param of constr.parameters) {
                if (param.cType === 'char*' || param.cType === 'char *' || 
                    param.cType === 'const char*' || param.cType === 'const char *') {
                    return true;
                }
            }
        }

        return false;
    }

    private async runDartFix(): Promise<void> {
        const { spawn } = await import('node:child_process');
        
        return new Promise((resolve, reject) => {
            console.log('Running dart fix --apply on generated code...');
            
            const dartFix = spawn('dart', ['fix', '--apply', this.outputDir], {
                stdio: 'inherit'
            });
            
            dartFix.on('close', (code) => {
                if (code === 0) {
                    console.log('✓ Dart fix completed successfully');
                    resolve();
                } else {
                    console.warn(`⚠ Dart fix exited with code ${code}`);
                    resolve(); // Don't fail the build if dart fix fails
                }
            });
            
            dartFix.on('error', (error) => {
                console.warn(`⚠ Failed to run dart fix: ${error.message}`);
                resolve(); // Don't fail the build if dart fix fails
            });
        });
    }
}