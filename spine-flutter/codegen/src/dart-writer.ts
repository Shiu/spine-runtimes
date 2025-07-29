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
			return `//${line.substring(4).replace(/\*+/g, '')}`;
		} else if (index === array.length - 1 && (line.startsWith(' ****') || line.trim() === '*/')) {
			return `//${line.substring(line.indexOf('*') + 1).replace(/\*+/g, '').replace(/\//g, '')}`;
		} else if (line.startsWith(' ****') || line.trim() === '*/') {
			return `// ${line.substring(4)}`;
		} else if (line.startsWith(' * ')) {
			return `// ${line.substring(3)}`;
		} else if (line.startsWith(' *')) {
			return `//${line.substring(2)}`;
		} else {
			return line;
		}
	})
	.join('\n');

// Internal data model interfaces (from spec)
interface DartClass {
	name: string;                    // Dart class name (e.g., "Animation")
	type: 'concrete' | 'abstract' | 'interface';
	inheritance: {
		extends?: string;              // Single parent class
		implements: string[];          // Multiple interfaces (replaces mixins)
	};
	imports: string[];              // All required imports
	members: DartMember[];          // All class members
	hasRtti: boolean;               // Whether this class needs RTTI switching
	needsPackageFfi: boolean;       // Whether to import package:ffi
}

interface DartMember {
	type: 'constructor' | 'method' | 'getter' | 'setter' | 'static_method';
	name: string;                   // Dart member name
	dartReturnType: string;         // Dart return type
	parameters: DartParameter[];    // Parameters (excluding 'self')
	isOverride: boolean;           // Whether to add @override
	implementation: string;         // The actual Dart code body
	cMethodName?: string;          // Original C method name (for reference)
}

interface DartParameter {
	name: string;
	dartType: string;
	cType: string;                 // Original C type for conversion
}

interface DartEnum {
	name: string;
	values: DartEnumValue[];
}

interface DartEnumValue {
	name: string;
	value: number;
}

/** New Dart writer with clean architecture - following the specification exactly */
export class DartWriter {
	private enumNames = new Set<string>();
	private classMap = new Map<string, CClassOrStruct>(); // name -> class
	private inheritance: Record<string, { extends?: string, mixins: string[] }> = {};
	private isInterface: Record<string, boolean> = {};
	private supertypes: Record<string, string[]> = {}; // for RTTI switching

	constructor (private outputDir: string) {
		this.cleanOutputDirectory();
	}

	private cleanOutputDirectory (): void {
		if (fs.existsSync(this.outputDir)) {
			console.log(`[NEW] Cleaning ${this.outputDir}...`);
			fs.rmSync(this.outputDir, { recursive: true, force: true });
		}
		fs.mkdirSync(this.outputDir, { recursive: true });
	}

	// Step 1: Transform C types to clean Dart model (from spec)
	private transformToDartModel (
		cTypes: CClassOrStruct[],
		cEnums: CEnum[],
		inheritance: Record<string, { extends?: string, mixins: string[] }>,
		isInterface: Record<string, boolean>,
		supertypes: Record<string, string[]>
	): { classes: DartClass[], enums: DartEnum[] } {

		// Store data for reference
		this.inheritance = inheritance;
		this.isInterface = isInterface;
		this.supertypes = supertypes;

		for (const cType of cTypes) {
			this.classMap.set(cType.name, cType);
		}

		for (const cEnum of cEnums) {
			this.enumNames.add(cEnum.name);
		}

		console.log('[NEW] Transforming to Dart model...');

		const dartClasses: DartClass[] = [];
		const dartEnums: DartEnum[] = [];

		// Transform enums
		for (const cEnum of cEnums) {
			dartEnums.push(this.transformEnum(cEnum));
		}

		// Transform classes in dependency order
		const sortedTypes = this.sortByInheritance(cTypes);
		for (const cType of sortedTypes) {
			dartClasses.push(this.transformClass(cType));
		}

		return { classes: dartClasses, enums: dartEnums };
	}

	// Step 2: Generate Dart code from clean model (from spec)
	private generateDartCode (dartClass: DartClass): string {
		const lines: string[] = [];

		// Header (same for all)
		lines.push(this.generateHeader());

		// Imports (unified logic)
		lines.push(...this.generateImports(dartClass.imports, dartClass.needsPackageFfi, dartClass.hasRtti));

		// Class declaration (unified)
		lines.push(this.generateClassDeclaration(dartClass));

		// Class body (same template for all types)
		if (dartClass.type === 'interface') {
			lines.push(...this.generateInterfaceBody(dartClass));
		} else {
			lines.push(...this.generateClassBody(dartClass));
		}

		lines.push('}');

		return lines.join('\n');
	}

	// Step 3: Write files
	async writeAll (
		cTypes: CClassOrStruct[],
		cEnums: CEnum[],
		cArrayTypes: CClassOrStruct[],
		inheritance: Record<string, { extends?: string, mixins: string[] }> = {},
		isInterface: Record<string, boolean> = {},
		supertypes: Record<string, string[]> = {}
	): Promise<void> {
		console.log('[NEW] Starting new Dart writer...');

		// Step 1: Transform to clean model
		const { classes, enums } = this.transformToDartModel(cTypes, cEnums, inheritance, isInterface, supertypes);

		// Step 2 & 3: Generate and write files
		console.log('[NEW] Writing enum files...');
		for (const dartEnum of enums) {
			const content = this.generateEnumCode(dartEnum);
			const fileName = `${toSnakeCase(dartEnum.name)}.dart`;
			const filePath = path.join(this.outputDir, fileName);
			fs.writeFileSync(filePath, content);
		}

		console.log('[NEW] Writing class files...');
		for (const dartClass of classes) {
			const content = this.generateDartCode(dartClass);
			const fileName = `${toSnakeCase(dartClass.name)}.dart`;
			const filePath = path.join(this.outputDir, fileName);
			fs.writeFileSync(filePath, content);
		}

		// Generate arrays.dart (crucial - this was missing!)
		console.log('[NEW] Writing arrays.dart...');
		await this.writeArraysFile(cArrayTypes);

		// Write main export file
		await this.writeExportFile(classes, enums);

		console.log('[NEW] New dart writer completed!');
	}

	// Class type resolution (from spec)
	private determineClassType (cType: CClassOrStruct): 'concrete' | 'abstract' | 'interface' {
		if (this.isInterface[cType.name]) return 'interface';
		if (cType.cppType.isAbstract) return 'abstract';
		return 'concrete';
	}

	// Inheritance resolution - Use implements instead of mixins (from spec)
	private resolveInheritance (cType: CClassOrStruct): { extends?: string, implements: string[] } {
		const inheritanceInfo = this.inheritance[cType.name];
		return {
			extends: inheritanceInfo?.extends ? this.toDartTypeName(inheritanceInfo.extends) : undefined,
			implements: (inheritanceInfo?.mixins || []).map(mixin => this.toDartTypeName(mixin)) // Convert mixins to implements
		};
	}

	private transformEnum (cEnum: CEnum): DartEnum {
		return {
			name: this.toDartTypeName(cEnum.name),
			values: cEnum.values.map((value, index) => ({
				name: this.toDartEnumValueName(value.name, cEnum.name),
				// C enums without explicit values are implicitly numbered 0, 1, 2, etc.
				value: value.value !== undefined ? Number.parseInt(value.value) : index
			}))
		};
	}

	private transformClass (cType: CClassOrStruct): DartClass {
		const dartName = this.toDartTypeName(cType.name);
		const classType = this.determineClassType(cType);
		const inheritance = this.resolveInheritance(cType);

		return {
			name: dartName,
			type: classType,
			inheritance,
			imports: this.collectImports(cType),
			members: this.processMembers(cType, classType),
			hasRtti: this.hasRttiMethod(cType),
			needsPackageFfi: this.needsStringConversions(cType)
		};
	}

	// Unified Method Processing (from spec)
	private processMembers (cType: CClassOrStruct, classType: 'concrete' | 'abstract' | 'interface'): DartMember[] {
		const members: DartMember[] = [];

		// Add constructors for concrete classes only
		if (classType === 'concrete') {
			for (const constr of cType.constructors) {
				members.push(this.createConstructor(constr, cType));
			}
		}

		// Add destructor as dispose method for concrete classes
		if (classType === 'concrete' && cType.destructor) {
			members.push(this.createDisposeMethod(cType.destructor, cType));
		}

		// Process methods with unified logic - Apply SAME logic for ALL class types
		const validMethods = cType.methods.filter(method => {
			if (this.hasRawPointerParameters(method)) {
				return false;
			}
			if (this.isMethodInherited(method, cType)) {
				return false;
			}
			return true;
		});

		const renumberedMethods = this.renumberMethods(validMethods, cType.name);

		// Create a map of overloaded setter methods for isSetter to check
		const overloadedSetters = this.findOverloadedSetters(renumberedMethods);

		for (const methodInfo of renumberedMethods) {
			const { method, renamedMethod } = methodInfo;
			members.push(this.processMethod(method, cType, classType, renamedMethod, overloadedSetters));
		}

		return members;
	}

	private processMethod (method: CMethod, cType: CClassOrStruct, classType: 'concrete' | 'abstract' | 'interface', renamedMethod?: string, overloadedSetters?: Set<string>): DartMember {
		// Apply SAME logic for ALL class types (concrete, abstract, interface) - from spec
		if (this.isGetter(method)) {
			return this.createGetter(method, cType, classType, renamedMethod);
		} else if (this.isSetter(method, overloadedSetters)) {
			return this.createSetter(method, cType, classType, renamedMethod);
		} else {
			return this.createMethod(method, cType, classType, renamedMethod);
		}
	}

	// Unified getter detection for ALL classes (from spec)
	private isGetter (method: CMethod): boolean {
		return (method.name.includes('_get_') && method.parameters.length === 1) ||
			(method.returnType === 'bool' && method.parameters.length === 1 &&
				(method.name.includes('_has_') || method.name.includes('_is_') || method.name.includes('_was_')));
	}

	private isSetter (method: CMethod, overloadedSetters?: Set<string>): boolean {
		const isBasicSetter = method.returnType === 'void' &&
			method.parameters.length === 2 &&
			method.name.includes('_set_');

		if (!isBasicSetter) return false;

		// If this setter has overloads (multiple methods with same base name),
		// don't generate it as a setter - generate as regular method instead
		if (overloadedSetters?.has(method.name)) {
			return false;
		}

		return true;
	}

	private findOverloadedSetters (renumberedMethods: Array<{ method: CMethod, renamedMethod?: string }>): Set<string> {
		const setterBasenames = new Map<string, string[]>();

		// Group setter methods by their base name
		for (const methodInfo of renumberedMethods) {
			const method = methodInfo.method;
			if (method.returnType === 'void' &&
				method.parameters.length === 2 &&
				method.name.includes('_set_')) {

				// Extract base name by removing numbered suffix
				const match = method.name.match(/^(.+?)_(\d+)$/);
				const baseName = match ? match[1] : method.name;

				if (!setterBasenames.has(baseName)) {
					setterBasenames.set(baseName, []);
				}
				setterBasenames.get(baseName)?.push(method.name);
			}
		}

		// Find setters that have multiple methods with the same base name
		const overloadedSetters = new Set<string>();
		for (const [_baseName, methodNames] of setterBasenames) {
			if (methodNames.length > 1) {
				// Multiple setters with same base name - mark all as overloaded
				for (const methodName of methodNames) {
					overloadedSetters.add(methodName);
				}
			}
		}

		return overloadedSetters;
	}

	private createDisposeMethod (destructor: CMethod, cType: CClassOrStruct): DartMember {
		const implementation = `SpineBindings.bindings.${destructor.name}(_ptr);`;

		return {
			type: 'method',
			name: 'dispose',
			dartReturnType: 'void',
			parameters: [],
			isOverride: false,
			implementation,
			cMethodName: destructor.name
		};
	}

	private createConstructor (constr: CMethod, cType: CClassOrStruct): DartMember {
		const dartClassName = this.toDartTypeName(cType.name);
		const params = constr.parameters.map(p => ({
			name: p.name,
			dartType: this.toDartParameterType(p),
			cType: p.cType
		}));

		const args = constr.parameters.map(p => this.convertDartToC(p.name, p)).join(', ');
		const implementation = `final ptr = SpineBindings.bindings.${constr.name}(${args});
    return ${dartClassName}.fromPointer(ptr);`;

		return {
			type: 'constructor',
			name: this.getConstructorName(constr, cType),
			dartReturnType: dartClassName,
			parameters: params,
			isOverride: false,
			implementation,
			cMethodName: constr.name
		};
	}

	private createGetter (method: CMethod, cType: CClassOrStruct, classType: 'concrete' | 'abstract' | 'interface', renamedMethod?: string): DartMember {
		const propertyName = renamedMethod || this.extractPropertyName(method.name, cType.name);
		const dartReturnType = this.toDartReturnType(method.returnType, method.returnTypeNullable);

		// Interface methods have no implementation (from spec)
		let implementation = '';
		if (classType !== 'interface') {
			implementation = `final result = SpineBindings.bindings.${method.name}(_ptr);
    ${this.generateReturnConversion(method.returnType, 'result', method.returnTypeNullable)}`;
		}

		// Check if this is an override
		const isOverride = this.isMethodOverride(method, cType);

		return {
			type: 'getter',
			name: propertyName,
			dartReturnType,
			parameters: [],
			isOverride,
			implementation,
			cMethodName: method.name
		};
	}

	private createSetter (method: CMethod, cType: CClassOrStruct, classType: 'concrete' | 'abstract' | 'interface', renamedMethod?: string): DartMember {
		let propertyName = renamedMethod || this.extractPropertyName(method.name, cType.name);
		const param = method.parameters[1]; // First param is self
		const dartParam = {
			name: 'value',
			dartType: this.toDartParameterType(param),
			cType: param.cType
		};

		// Handle numeric suffixes in setter names (only when no renamed method provided)
		if (!renamedMethod) {
			const match = propertyName.match(/^(\w+)_(\d+)$/);
			if (match) {
				propertyName = `${match[1]}${match[2]}`;
			} else if (/^\d+$/.test(propertyName)) {
				propertyName = `set${propertyName}`;
			}
		}

		// Interface methods have no implementation (from spec)
		let implementation = '';
		if (classType !== 'interface') {
			implementation = `SpineBindings.bindings.${method.name}(_ptr, ${this.convertDartToC('value', param)});`;
		}

		const isOverride = this.isMethodOverride(method, cType);

		return {
			type: 'setter',
			name: propertyName,
			dartReturnType: 'void',
			parameters: [dartParam],
			isOverride,
			implementation,
			cMethodName: method.name
		};
	}

	private createMethod (method: CMethod, cType: CClassOrStruct, classType: 'concrete' | 'abstract' | 'interface', renamedMethod?: string): DartMember {
		let methodName = renamedMethod || this.toDartMethodName(method.name, cType.name);
		const dartReturnType = this.toDartReturnType(method.returnType, method.returnTypeNullable);

		// Check if this is a static method
		const isStatic = method.parameters.length === 0 ||
			(method.parameters[0].name !== 'self' &&
				!method.parameters[0].cType.startsWith(cType.name));

		// Rename static rtti method to avoid conflict with getter
		if (isStatic && methodName === 'rtti') {
			methodName = 'rttiStatic';
		}

		// Parameters (skip 'self' parameter for instance methods)
		const paramStartIndex = isStatic ? 0 : 1;
		const params = method.parameters.slice(paramStartIndex).map(p => ({
			name: p.name,
			dartType: this.toDartParameterType(p),
			cType: p.cType
		}));

		// Interface methods have no implementation (from spec)
		// Exception: rttiStatic() needs implementation even in interfaces
		let implementation = '';
		if (classType !== 'interface' || methodName === 'rttiStatic') {
			const args = method.parameters.map((p, i) => {
				if (!isStatic && i === 0) return '_ptr'; // self parameter
				return this.convertDartToC(p.name, p);
			}).join(', ');

			if (method.returnType === 'void') {
				implementation = `SpineBindings.bindings.${method.name}(${args});`;
			} else {
				implementation = `final result = SpineBindings.bindings.${method.name}(${args});
    ${this.generateReturnConversion(method.returnType, 'result', method.returnTypeNullable)}`;
			}
		}

		const isOverride = this.isMethodOverride(method, cType);

		return {
			type: isStatic ? 'static_method' : 'method',
			name: methodName,
			dartReturnType,
			parameters: params,
			isOverride,
			implementation,
			cMethodName: method.name
		};
	}

	// Code generation methods (from spec)

	private generateHeader (): string {
		return `${LICENSE_HEADER}

// AUTO GENERATED FILE, DO NOT EDIT.`;
	}

	private generateImports (imports: string[], needsPackageFfi: boolean, hasRtti: boolean): string[] {
		const lines: string[] = [];

		lines.push('');
		lines.push("import 'dart:ffi';");

		if (needsPackageFfi) {
			lines.push("import 'package:ffi/ffi.dart';");
		}

		lines.push("import 'spine_dart_bindings_generated.dart';");
		lines.push("import '../spine_bindings.dart';");

		if (hasRtti) {
			lines.push("import 'rtti.dart';");
		}

		// Add other imports
		for (const importFile of imports.sort()) {
			if (!['rtti.dart'].includes(importFile)) { // Skip duplicates
				lines.push(`import '${importFile}';`);
			}
		}

		return lines;
	}

	// Class declaration generation (from spec)
	private generateClassDeclaration (dartClass: DartClass): string {
		let declaration = '';

		if (dartClass.type === 'interface') {
			declaration = `abstract class ${dartClass.name}`;
		} else {
			declaration = `class ${dartClass.name}`;
			if (dartClass.type === 'abstract') {
				declaration = `abstract ${declaration}`;
			}
		}

		// Inheritance
		if (dartClass.inheritance.extends) {
			declaration += ` extends ${dartClass.inheritance.extends}`;
		}

		// Implements clause
		const implementsClasses: string[] = [];

		// Add interfaces
		implementsClasses.push(...dartClass.inheritance.implements);

		if (implementsClasses.length > 0) {
			declaration += ` implements ${implementsClasses.join(', ')}`;
		}

		return `
/// ${dartClass.name} wrapper
${declaration} {`;
	}

	private generateInterfaceBody (dartClass: DartClass): string[] {
		const lines: string[] = [];

		// Add nativePtr getter for interfaces that can be used as method parameters
		// This allows the generated code to call .nativePtr.cast() on interface instances
		lines.push('  Pointer get nativePtr;');

		// Generate abstract method signatures for interfaces
		for (const member of dartClass.members) {
			lines.push(this.generateInterfaceMember(member));
		}

		return lines;
	}

	// Class body generation (from spec)
	private generateClassBody (dartClass: DartClass): string[] {
		const lines: string[] = [];

		// Pointer field (only for concrete/abstract classes)
		const cTypeName = this.toCTypeName(dartClass.name);
		lines.push(`  final Pointer<${cTypeName}_wrapper> _ptr;`);
		lines.push('');

		// Constructor
		lines.push(this.generatePointerConstructor(dartClass));
		lines.push('');

		// Native pointer getter
		lines.push('  /// Get the native pointer for FFI calls');
		lines.push('  Pointer get nativePtr => _ptr;');
		lines.push('');

		// Members
		for (const member of dartClass.members) {
			lines.push(this.generateMember(member));
			lines.push('');
		}

		return lines;
	}

	private generatePointerConstructor (dartClass: DartClass): string {
		if (dartClass.inheritance.extends) {
			return `  ${dartClass.name}.fromPointer(this._ptr) : super.fromPointer(_ptr.cast());`;
		} else {
			return `  ${dartClass.name}.fromPointer(this._ptr);`;
		}
	}

	private generateInterfaceMember (member: DartMember): string {
		const params = member.parameters.map(p => `${p.dartType} ${p.name}`).join(', ');

		switch (member.type) {
			case 'getter':
				return `  ${member.dartReturnType} get ${member.name};`;
			case 'setter':
				return `  set ${member.name}(${params});`;
			case 'method':
				return `  ${member.dartReturnType} ${member.name}(${params});`;
			case 'static_method':
				// Special case: rttiStatic() needs implementation even in abstract classes
				if (member.name === 'rttiStatic') {
					return `  static ${member.dartReturnType} ${member.name}(${params}) {
    ${member.implementation}
  }`;
				} else {
					return `  static ${member.dartReturnType} ${member.name}(${params});`;
				}
			default:
				return '';
		}
	}

	// Member generation (from spec)
	private generateMember (member: DartMember): string {
		const override = member.isOverride ? '@override\n  ' : '  ';

		switch (member.type) {
			case 'constructor':
				return this.generateConstructorMember(member);
			case 'getter':
				return `${override}${member.dartReturnType} get ${member.name} {
    ${member.implementation}
  }`;
			case 'setter': {
				const param = member.parameters[0];
				return `${override}set ${member.name}(${param.dartType} ${param.name}) {
    ${member.implementation}
  }`;
			}
			case 'method':
			case 'static_method': {
				const params = member.parameters.map(p => `${p.dartType} ${p.name}`).join(', ');
				const static_ = member.type === 'static_method' ? 'static ' : '';
				return `${override}${static_}${member.dartReturnType} ${member.name}(${params}) {
    ${member.implementation}
  }`;
			}
			default:
				return '';
		}
	}

	private generateConstructorMember (member: DartMember): string {
		const params = member.parameters.map(p => `${p.dartType} ${p.name}`).join(', ');
		const factoryName = member.name === member.dartReturnType ? '' : `.${member.name}`;

		return `  factory ${member.dartReturnType}${factoryName}(${params}) {
    ${member.implementation}
  }`;
	}

	private generateEnumCode (dartEnum: DartEnum): string {
		const lines: string[] = [];

		lines.push(this.generateHeader());
		lines.push('');
		lines.push(`/// ${dartEnum.name} enum`);
		lines.push(`enum ${dartEnum.name} {`);

		// Write enum values
		for (let i = 0; i < dartEnum.values.length; i++) {
			const value = dartEnum.values[i];
			const comma = i < dartEnum.values.length - 1 ? ',' : ';';
			lines.push(`  ${value.name}(${value.value})${comma}`);
		}

		lines.push('');
		lines.push(`  const ${dartEnum.name}(this.value);`);
		lines.push('  final int value;');
		lines.push('');
		lines.push(`  static ${dartEnum.name} fromValue(int value) {`);
		lines.push('    return values.firstWhere(');
		lines.push('      (e) => e.value == value,');
		lines.push(`      orElse: () => throw ArgumentError('Invalid ${dartEnum.name} value: \$value'),`);
		lines.push('    );');
		lines.push('  }');
		lines.push('}');

		return lines.join('\n');
	}

	// Generate arrays.dart file (this was missing!)
	private async writeArraysFile (cArrayTypes: CClassOrStruct[]): Promise<void> {
		const lines: string[] = [];

		lines.push(this.generateHeader());
		lines.push('');
		lines.push("import 'dart:ffi';");
		lines.push("import 'package:ffi/ffi.dart';");
		lines.push("import 'spine_dart_bindings_generated.dart';");
		lines.push("import '../spine_bindings.dart';");
		lines.push("import '../native_array.dart';");

		// Collect all imports needed for all array types
		const imports = new Set<string>();
		for (const arrayType of cArrayTypes) {
			const elementType = this.extractArrayElementType(arrayType.name);
			if (!this.isPrimitiveArrayType(elementType)) {
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

		// Add RTTI import if needed
		if (Array.from(imports).some(imp => {
			const arrayType = cArrayTypes.find(at => imp.includes(toSnakeCase(this.extractArrayElementType(at.name))));
			if (arrayType) {
				const elementType = this.extractArrayElementType(arrayType.name);
				const cElementType = `spine_${toSnakeCase(elementType)}`;
				const cClass = this.classMap.get(cElementType);
				return cClass && this.isAbstract(cClass);
			}
			return false;
		})) {
			lines.push("import 'rtti.dart';");
		}

		// Add sorted imports
		for (const imp of Array.from(imports).sort()) {
			lines.push(imp);
		}

		// Generate all array classes in one file (from spec)
		for (const arrayType of cArrayTypes) {
			lines.push('');
			lines.push(...this.generateArrayClassLines(arrayType));
		}

		const filePath = path.join(this.outputDir, 'arrays.dart');
		fs.writeFileSync(filePath, lines.join('\n'));
	}

	// Array generation (proper implementation from old writer)
	private generateArrayClassLines (arrayType: CClassOrStruct): string[] {
		const lines: string[] = [];
		const dartClassName = this.toDartTypeName(arrayType.name);
		const elementType = this.extractArrayElementType(arrayType.name);

		lines.push(`/// ${dartClassName} wrapper`);
		lines.push(`class ${dartClassName} extends NativeArray<${this.toDartElementType(elementType)}> {`);

		// Generate typed constructor - arrays use the array wrapper type
		const arrayWrapperType = `${arrayType.name}_wrapper`;
		lines.push(`  ${dartClassName}.fromPointer(Pointer<${arrayWrapperType}> ptr) : super(ptr);`);
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
				lines.push('    // NOTE: This will not compile due to C API bug - buffer() returns int instead of Pointer');
				lines.push('    return buffer.cast<Int64>()[index];');
			} else {
				// For object types, the buffer contains pointers
				const dartElementType = this.toDartTypeName(`spine_${toSnakeCase(elementType)}`);
				const cElementType = `spine_${toSnakeCase(elementType)}`;
				const cClass = this.classMap.get(cElementType);

				if (cClass && this.isAbstract(cClass)) {
					// Use RTTI to determine concrete type for abstract classes - handle null case
					lines.push(`    if (buffer[index].address == 0) return null;`);
					const rttiCode = this.generateRttiBasedInstantiation(dartElementType, 'buffer[index]', cClass);
					lines.push(`    ${rttiCode}`);
				} else {
					// For array elements, check if the pointer is null
					lines.push(`    return buffer[index].address == 0 ? null : ${dartElementType}.fromPointer(buffer[index]);`);
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
			// Create a copy of the parameter with nullable flag for proper conversion
			const nullableParam = { ...param, isNullable: !this.isPrimitiveArrayType(elementType) };
			const convertedValue = this.convertDartToC('value', nullableParam);
			lines.push(`    SpineBindings.bindings.${setMethod.name}(nativePtr.cast(), index, ${convertedValue});`);
			lines.push('  }');
		}

		lines.push('}');

		return lines;
	}

	private extractArrayElementType (arrayTypeName: string): string {
		// spine_array_animation -> animation
		// spine_array_int -> int
		const match = arrayTypeName.match(/spine_array_(.+)/);
		if (match) {
			const rawType = match[1];
			// For primitive types, return the raw type
			if (['int', 'float', 'bool', 'unsigned_short', 'property_id'].includes(rawType)) {
				return rawType;
			}
			// For object types, return the raw type (will be converted later)
			return rawType;
		}
		return 'dynamic';
	}

	private toDartElementType (elementType: string): string {
		// Handle pointer types
		if (elementType.endsWith('*')) {
			const baseType = elementType.slice(0, -1).trim();
			return `${this.toDartTypeName(`spine_${toSnakeCase(baseType)}`)}?`;
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

		// For object types, convert to PascalCase and make nullable since arrays can contain null pointers
		return `${this.toPascalCase(elementType)}?`;
	}

	private isPrimitiveArrayType (elementType: string): boolean {
		return ['int', 'float', 'bool', 'unsigned_short', 'property_id'].includes(elementType.toLowerCase());
	}

	// Helper methods

	private sortByInheritance (cTypes: CClassOrStruct[]): CClassOrStruct[] {
		const sorted: CClassOrStruct[] = [];
		const processed = new Set<string>();

		const processClass = (cType: CClassOrStruct) => {
			if (processed.has(cType.name)) {
				return;
			}

			// Process concrete parent first (skip interfaces)
			const inheritanceInfo = this.inheritance[cType.name];
			if (inheritanceInfo?.extends) {
				const parent = this.classMap.get(inheritanceInfo.extends);
				if (parent) {
					processClass(parent);
				}
			}

			// Process interface dependencies
			for (const interfaceName of inheritanceInfo?.mixins || []) {
				const interfaceClass = this.classMap.get(interfaceName);
				if (interfaceClass) {
					processClass(interfaceClass);
				}
			}

			sorted.push(cType);
			processed.add(cType.name);
		};

		for (const cType of cTypes) {
			processClass(cType);
		}

		return sorted;
	}

	private hasRttiMethod (cType: CClassOrStruct): boolean {
		return cType.methods.some(m => m.name === `${cType.name}_rtti` && m.parameters.length === 0);
	}

	private collectImports (cType: CClassOrStruct): string[] {
		const imports = new Set<string>();
		const currentTypeName = this.toDartTypeName(cType.name);
		const currentFileName = `${toSnakeCase(currentTypeName)}.dart`;

		// Add parent class import if needed
		const parentName = this.inheritance[cType.name]?.extends;
		if (parentName) {
			const parentDartName = this.toDartTypeName(parentName);
			imports.add(`${toSnakeCase(parentDartName)}.dart`);
		}

		// Add interface imports
		for (const interfaceName of this.inheritance[cType.name]?.mixins || []) {
			const interfaceDartName = this.toDartTypeName(interfaceName);
			const interfaceFileName = `${toSnakeCase(interfaceDartName)}.dart`;
			if (interfaceFileName !== currentFileName) {
				imports.add(interfaceFileName);
			}
		}

		// Collect from methods and constructors
		let hasArrays = false;
		for (const method of [...cType.methods, ...cType.constructors]) {
			if (this.hasRawPointerParameters(method)) continue;

			// Return type
			if (method.returnType.startsWith('spine_array_')) {
				hasArrays = true;
			} else if (method.returnType.startsWith('spine_')) {
				const cleanType = method.returnType.replace('*', '').trim();
				if (!this.isPrimitive(cleanType)) {
					const typeName = this.toDartTypeName(cleanType);
					const fileName = `${toSnakeCase(typeName)}.dart`;
					if (fileName !== currentFileName) {
						imports.add(fileName);
					}

					// If return type is abstract, add imports for all concrete subclasses
					// that could be referenced in the RTTI-based switch statement
					const cClass = this.classMap.get(cleanType);
					if (cClass && this.isAbstract(cClass)) {
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
				if (param.name === 'self') continue;

				if (param.cType.startsWith('spine_array_')) {
					hasArrays = true;
				} else if (this.enumNames.has(param.cType)) {
					const enumType = this.toDartTypeName(param.cType);
					imports.add(`${toSnakeCase(enumType)}.dart`);
				} else if (param.cType.startsWith('spine_')) {
					const cleanType = param.cType.replace('*', '').trim();
					if (!this.isPrimitive(cleanType)) {
						const typeName = this.toDartTypeName(cleanType);
						const fileName = `${toSnakeCase(typeName)}.dart`;
						if (fileName !== currentFileName) {
							imports.add(fileName);
						}
					}
				}
			}
		}

		if (hasArrays) {
			imports.add('arrays.dart');
		}

		return Array.from(imports).sort();
	}

	private isPrimitive (type: string): boolean {
		return ['float', 'double', 'int', 'bool', 'size_t', 'int32_t', 'uint32_t'].includes(type);
	}

	private isMethodOverride (method: CMethod, cType: CClassOrStruct): boolean {
		// Static methods cannot be overridden in Dart
		const isStatic = method.parameters.length === 0 ||
			(method.parameters[0].name !== 'self' &&
				!method.parameters[0].cType.startsWith(cType.name));

		if (isStatic) {
			return false;
		}

		// Check if this method exists in parent classes or interfaces
		const parentName = this.inheritance[cType.name]?.extends;
		if (parentName) {
			const parent = this.classMap.get(parentName);
			if (parent) {
				const methodSuffix = this.getMethodSuffix(method.name, cType.name);
				const parentMethodName = `${parentName}_${methodSuffix}`;
				if (parent.methods.some(m => m.name === parentMethodName)) {
					return true;
				}
			}
		}

		// Check interfaces
		for (const interfaceName of this.inheritance[cType.name]?.mixins || []) {
			const interfaceClass = this.classMap.get(interfaceName);
			if (interfaceClass) {
				const methodSuffix = this.getMethodSuffix(method.name, cType.name);
				const interfaceMethodName = `${interfaceName}_${methodSuffix}`;
				if (interfaceClass.methods.some(m => m.name === interfaceMethodName)) {
					return true;
				}
			}
		}

		return false;
	}

	// Utility methods - keeping from previous implementation

	private toDartTypeName (cTypeName: string): string {
		if (cTypeName.startsWith('spine_')) {
			const name = cTypeName.slice(6);
			return this.toPascalCase(name);
		}
		return this.toPascalCase(cTypeName);
	}

	private toCTypeName (dartTypeName: string): string {
		return `spine_${toSnakeCase(dartTypeName)}`;
	}

	private toDartMethodName (cMethodName: string, cTypeName: string): string {
		const prefix = `${cTypeName}_`;
		if (cMethodName.startsWith(prefix)) {
			return this.toCamelCase(cMethodName.slice(prefix.length));
		}
		return this.toCamelCase(cMethodName);
	}

	private toDartEnumValueName (cValueName: string, cEnumName: string): string {
		const enumNameUpper = cEnumName.toUpperCase();

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

		if (cEnumName === 'spine_mix_direction' && ['in', 'out'].includes(enumValue)) {
			return `direction${this.toPascalCase(enumValue)}`;
		}

		return enumValue;
	}

	private toDartReturnType (cType: string, nullable?: boolean): string {
		let baseType: string;
		if (cType === 'void') return 'void';
		if (cType === 'char*' || cType === 'char *' || cType === 'const char*' || cType === 'const char *') baseType = 'String';
		else if (cType === 'float' || cType === 'double') baseType = 'double';
		else if (cType === 'int' || cType === 'size_t' || cType === 'int32_t' || cType === 'uint32_t') baseType = 'int';
		else if (cType === 'bool') baseType = 'bool';
		// Handle primitive pointer types
		else if (cType === 'void*' || cType === 'void *') baseType = 'Pointer<Void>';
		else if (cType === 'float*' || cType === 'float *') baseType = 'Pointer<Float>';
		else if (cType === 'uint32_t*' || cType === 'uint32_t *') baseType = 'Pointer<Uint32>';
		else if (cType === 'uint16_t*' || cType === 'uint16_t *') baseType = 'Pointer<Uint16>';
		else if (cType === 'int*' || cType === 'int *') baseType = 'Pointer<Int32>';
		else baseType = this.toDartTypeName(cType);
		
		return nullable ? `${baseType}?` : baseType;
	}

	private toDartParameterType (param: CParameter): string {
		if (param.cType === 'char*' || param.cType === 'char *' || param.cType === 'const char*' || param.cType === 'const char *') {
			return 'String';
		}
		// Handle void* parameters as Pointer<Void>
		if (param.cType === 'void*' || param.cType === 'void *') {
			return 'Pointer<Void>';
		}
		return this.toDartReturnType(param.cType, param.isNullable);
	}

	private convertDartToC (dartValue: string, param: CParameter): string {
		if (param.cType === 'char*' || param.cType === 'char *' || param.cType === 'const char*' || param.cType === 'const char *') {
			return `${dartValue}.toNativeUtf8().cast<Char>()`;
		}

		if (this.enumNames.has(param.cType)) {
			if (param.isNullable) {
				return `${dartValue}?.value ?? 0`;
			}
			return `${dartValue}.value`;
		}

		if (param.cType.startsWith('spine_')) {
			if (param.isNullable) {
				return `${dartValue}?.nativePtr.cast() ?? Pointer.fromAddress(0)`;
			}
			return `${dartValue}.nativePtr.cast()`;
		}

		return dartValue;
	}

	private generateReturnConversion (cReturnType: string, resultVar: string, nullable?: boolean): string {
		if (cReturnType === 'char*' || cReturnType === 'char *' || cReturnType === 'const char*' || cReturnType === 'const char *') {
			if (nullable) {
				return `return ${resultVar}.address == 0 ? null : ${resultVar}.cast<Utf8>().toDartString();`;
			}
			return `return ${resultVar}.cast<Utf8>().toDartString();`;
		}

		if (this.enumNames.has(cReturnType)) {
			const dartType = this.toDartTypeName(cReturnType);
			if (nullable) {
				return `return ${resultVar} == 0 ? null : ${dartType}.fromValue(${resultVar});`;
			}
			return `return ${dartType}.fromValue(${resultVar});`;
		}

		if (cReturnType.startsWith('spine_array_')) {
			const dartType = this.toDartTypeName(cReturnType);
			if (nullable) {
				return `return ${resultVar}.address == 0 ? null : ${dartType}.fromPointer(${resultVar});`;
			}
			return `return ${dartType}.fromPointer(${resultVar});`;
		}

		if (cReturnType.startsWith('spine_')) {
			const dartType = this.toDartTypeName(cReturnType);
			const cClass = this.classMap.get(cReturnType);
			
			if (nullable) {
				if (cClass && this.isAbstract(cClass)) {
					return `if (${resultVar}.address == 0) return null;
    ${this.generateRttiBasedInstantiation(dartType, resultVar, cClass)}`;
				}
				return `return ${resultVar}.address == 0 ? null : ${dartType}.fromPointer(${resultVar});`;
			} else {
				if (cClass && this.isAbstract(cClass)) {
					return this.generateRttiBasedInstantiation(dartType, resultVar, cClass);
				}
				return `return ${dartType}.fromPointer(${resultVar});`;
			}
		}

		return `return ${resultVar};`;
	}

	private generateRttiBasedInstantiation (abstractType: string, resultVar: string, abstractClass: CClassOrStruct): string {
		const lines: string[] = [];

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

	private getConcreteSubclasses (abstractClassName: string): string[] {
		const concreteSubclasses: string[] = [];

		for (const [childName, supertypeList] of Object.entries(this.supertypes || {})) {
			if (supertypeList.includes(abstractClassName)) {
				const childClass = this.classMap.get(childName);
				if (childClass && !this.isAbstract(childClass)) {
					concreteSubclasses.push(childName);
				}
			}
		}

		return concreteSubclasses;
	}

	private isAbstract (cType: CClassOrStruct): boolean {
		return cType.cppType.isAbstract === true;
	}

	private getConstructorName (constr: CMethod, cType: CClassOrStruct): string {
		const dartClassName = this.toDartTypeName(cType.name);
		const cTypeName = this.toCTypeName(dartClassName);
		let constructorName = constr.name.replace(`${cTypeName}_create`, '');

		if (constructorName) {
			if (/^\d+$/.test(constructorName)) {
				if (cType.name === 'spine_color' && constr.name === 'spine_color_create2') {
					constructorName = 'fromRGBA';
				} else if (constr.parameters.length > 0) {
					const firstParamType = constr.parameters[0].cType.replace('*', '').trim();
					if (firstParamType === cType.name) {
						constructorName = 'from';
					} else {
						constructorName = `variant${constructorName}`;
					}
				} else {
					constructorName = `variant${constructorName}`;
				}
			} else if (constructorName.startsWith('_')) {
				constructorName = this.toCamelCase(constructorName.slice(1));
			}
		}

		return constructorName || dartClassName;
	}

	private extractPropertyName (methodName: string, typeName: string): string {
		const prefix = `${typeName}_`;
		let name = methodName.startsWith(prefix) ? methodName.slice(prefix.length) : methodName;

		if (name.startsWith('get_')) {
			name = name.slice(4);
		} else if (name.startsWith('set_')) {
			name = name.slice(4);
		}

		if (name === 'update_cache') {
			return 'updateCacheList';
		}

		const typeNames = ['int', 'float', 'double', 'bool', 'string'];
		if (typeNames.includes(name.toLowerCase())) {
			return `${this.toCamelCase(name)}Value`;
		}

		return this.toCamelCase(name);
	}

	private hasRawPointerParameters (method: CMethod): boolean {
		for (const param of method.parameters) {
			if (this.isRawPointer(param.cType)) {
				return true;
			}
		}
		return false;
	}

	private isRawPointer (cType: string): boolean {
		if (cType === 'char*' || cType === 'char *' || cType === 'const char*' || cType === 'const char *') {
			return false;
		}

		if (cType.includes('*')) {
			const cleanType = cType.replace('*', '').trim();
			if (!cleanType.startsWith('spine_')) {
				return true;
			}
		}

		return false;
	}

	private isMethodInherited (method: CMethod, cType: CClassOrStruct): boolean {
		const parentName = this.inheritance[cType.name]?.extends;
		if (!parentName) {
			return false;
		}

		const parent = this.classMap.get(parentName);
		if (!parent) {
			return false;
		}

		const methodSuffix = this.getMethodSuffix(method.name, cType.name);

		// Don't consider dispose methods as inherited - they're type-specific
		if (methodSuffix === 'dispose') {
			return false;
		}

		const parentMethodName = `${parentName}_${methodSuffix}`;

		const hasInParent = parent.methods.some(m => m.name === parentMethodName);
		if (hasInParent) {
			return true;
		}

		return this.isMethodInherited(method, parent);
	}

	private getMethodSuffix (methodName: string, typeName: string): string {
		const prefix = `${typeName}_`;
		if (methodName.startsWith(prefix)) {
			return methodName.slice(prefix.length);
		}
		return methodName;
	}

	private renumberMethods (methods: CMethod[], typeName: string): Array<{ method: CMethod, renamedMethod?: string }> {
		const result: Array<{ method: CMethod, renamedMethod?: string }> = [];

		const methodGroups = new Map<string, CMethod[]>();

		for (const method of methods) {
			const match = method.name.match(/^(.+?)_(\d+)$/);
			if (match) {
				const baseName = match[1];
				if (!methodGroups.has(baseName)) {
					methodGroups.set(baseName, []);
				}
				methodGroups.get(baseName)!.push(method);
			} else {
				result.push({ method });
			}
		}

		for (const [baseName, groupedMethods] of methodGroups) {
			if (groupedMethods.length === 1) {
				const method = groupedMethods[0];
				const dartMethodName = this.toDartMethodName(baseName, typeName);
				result.push({ method, renamedMethod: dartMethodName });
			} else {
				groupedMethods.sort((a, b) => {
					const aNum = parseInt(a.name.match(/_(\d+)$/)![1]);
					const bNum = parseInt(b.name.match(/_(\d+)$/)![1]);
					return aNum - bNum;
				});

				for (let i = 0; i < groupedMethods.length; i++) {
					const method = groupedMethods[i];
					const newNumber = i + 1;
					const currentNumber = parseInt(method.name.match(/_(\d+)$/)![1]);
					const baseDartName = this.toDartMethodName(baseName, typeName);

					if (i === 0) {
						// First method in the group - remove the number
						result.push({ method, renamedMethod: baseDartName });
					} else if (newNumber !== currentNumber) {
						// Need to renumber
						result.push({ method, renamedMethod: `${baseDartName}${newNumber}` });
					} else {
						// Number is correct, no renamed method needed
						result.push({ method });
					}
				}
			}
		}

		return result;
	}

	private needsStringConversions (cType: CClassOrStruct): boolean {
		for (const method of [...cType.methods, ...cType.constructors]) {
			if (method.returnType === 'char*' || method.returnType === 'char *' ||
				method.returnType === 'const char*' || method.returnType === 'const char *') {
				return true;
			}

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
					return true;
				}
			}
		}

		return false;
	}

	private async writeExportFile (classes: DartClass[], enums: DartEnum[]): Promise<void> {
		const lines: string[] = [];

		lines.push(LICENSE_HEADER);
		lines.push('');
		lines.push('// AUTO GENERATED FILE, DO NOT EDIT.');
		lines.push('');
		lines.push('// Export all generated types');
		lines.push('');

		// Export enums
		if (enums.length > 0) {
			lines.push('// Enums');
			for (const dartEnum of enums) {
				lines.push(`export '${toSnakeCase(dartEnum.name)}.dart';`);
			}
			lines.push('');
		}

		// Export classes
		if (classes.length > 0) {
			lines.push('// Classes');
			for (const dartClass of classes) {
				lines.push(`export '${toSnakeCase(dartClass.name)}.dart';`);
			}
			lines.push('');
		}

		// Export arrays
		lines.push('// Arrays');
		lines.push(`export 'arrays.dart';`);

		const filePath = path.join(path.dirname(path.dirname(this.outputDir)), 'lib/generated/api.dart');
		fs.writeFileSync(filePath, lines.join('\n'));
	}

	private toPascalCase (str: string): string {
		return str.split('_')
			.map(word => word.charAt(0).toUpperCase() + word.slice(1))
			.join('');
	}

	private toCamelCase (str: string): string {
		const pascal = this.toPascalCase(str);
		return pascal.charAt(0).toLowerCase() + pascal.slice(1);
	}
}