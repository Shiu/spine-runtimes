# Dart FFI Wrapper Generator

## Overview

A TypeScript-based code generator that extends the existing `spine-c/codegen` system to automatically generate clean, type-safe Dart wrapper classes over the raw FFI bindings. This eliminates the need for manual wrapper implementation while providing a native Dart API experience.

## Architecture

```
spine-cpp (C++ source)
    ↓ (existing type-extractor.ts)
spine-cpp-types.json (type definitions)
    ↓ (existing ir-generator.ts + c-writer.ts)
spine-c (C bindings: .h/.c files)
    ↓ (ffigen via generate_bindings.sh)
spine_flutter_bindings_generated.dart (raw FFI)
    ↓ (NEW: dart-generator.ts)
spine_flutter.dart (clean Dart API)
```

## Key Insights

### 1. Derivation vs Parsing
Instead of parsing the generated FFI bindings, we **derive** what ffigen produces using the same C type information that generates the headers. This works because ffigen follows predictable transformation rules:

### 2. Predictable Disposal Pattern
All C types follow a consistent disposal pattern (`spine_type_name` → `spine_type_name_dispose`), so we can derive disposal function names automatically instead of storing them.

### 3. Array Properties vs Regular Getters
C functions that return `spine_array_*` types become special **Array<T> properties** in Dart, requiring different generation logic than primitive getters.

### FFigen Transformation Rules

| C Code | Generated Dart FFI |
|--------|-------------------|
| `SPINE_C_API float spine_animation_get_duration(spine_animation self);` | `double spine_animation_get_duration(Pointer<spine_animation_wrapper> self)` |
| `SPINE_C_API void spine_animation_dispose(spine_animation self);` | `void spine_animation_dispose(Pointer<spine_animation_wrapper> self)` |
| `typedef enum { BLEND_NORMAL, BLEND_ADDITIVE } spine_blend_mode;` | `enum spine_blend_mode { BLEND_NORMAL(0), BLEND_ADDITIVE(1) }` |
| `SPINE_OPAQUE_TYPE(spine_animation)` | `typedef struct spine_animation_wrapper { char _dummy; } spine_animation_wrapper; typedef spine_animation_wrapper *spine_animation;` |
| `spine_array_timeline spine_animation_get_timelines(spine_animation self);` | `Pointer<spine_array_timeline_wrapper> spine_animation_get_timelines(Pointer<spine_animation_wrapper> self)` → **Array<Timeline> property** |

## Generator Components

### 1. Type Mapping System (`dart-types.ts`)

Defines the structure for Dart wrapper types:

```typescript
interface DartClass {
  name: string;                    // "Animation"
  cName: string;                   // "spine_animation" 
  nativeType: string;              // "Pointer<spine_animation_wrapper>"
  constructors: DartConstructor[];
  methods: DartMethod[];
  getters: DartGetter[];
  setters: DartSetter[];
  arrays: DartArrayGetter[];       // Properties that return Array<T> (e.g., animation.timelines)
}

interface DartMethod {
  name: string;                    // "apply"
  cFunctionName: string;           // "spine_animation_apply"
  returnType: DartType;
  parameters: DartParameter[];
  isStatic?: boolean;
}

interface DartGetter {
  name: string;                    // "duration"
  cFunctionName: string;           // "spine_animation_get_duration"
  returnType: DartType;
}

interface DartSetter {
  name: string;                    // "duration"
  cFunctionName: string;           // "spine_animation_set_duration"
  parameterType: DartType;
}

interface DartArrayGetter {
  name: string;                    // "timelines" (Dart property name)
  elementType: string;             // "Timeline" (element type inside Array<T>)
  cArrayType: string;              // "spine_array_timeline" (C array type returned)
  cGetterName: string;             // "spine_animation_get_timelines" (C function to call)
}

interface DartConstructor {
  cFunctionName: string;           // "spine_animation_create"
  parameters: DartParameter[];
}

interface DartParameter {
  name: string;
  type: DartType;
  cType: string;                   // Original C type for conversion
}

interface DartType {
  dart: string;                    // "double", "String", "Animation"
  isNullable?: boolean;
  isNative?: boolean;              // true for primitives, false for wrapper classes
}

interface DartEnum {
  name: string;                    // "BlendMode"
  cName: string;                   // "spine_blend_mode"
  values: DartEnumValue[];
}

interface DartEnumValue {
  name: string;                    // "normal"
  cName: string;                   // "SPINE_BLEND_MODE_NORMAL"  
  value: number;
}
```

### 2. Type Mapping Rules (`dart-type-mapper.ts`)

Converts C types to Dart types:

```typescript
class DartTypeMapper {
  // Maps C types to Dart types
  private static readonly TYPE_MAP: Record<string, DartType> = {
    'float': { dart: 'double', isNative: true },
    'double': { dart: 'double', isNative: true },
    'int': { dart: 'int', isNative: true },
    'bool': { dart: 'bool', isNative: true },
    'char*': { dart: 'String', isNative: true },
    'const char*': { dart: 'String', isNative: true },
    'void': { dart: 'void', isNative: true },
    'spine_skeleton': { dart: 'Skeleton', isNative: false },
    'spine_animation': { dart: 'Animation', isNative: false },
    // ... more mappings
  };

  static mapCTypeToDart(cType: string): DartType {
    // Handle pointers
    if (cType.endsWith('*')) {
      const baseType = cType.slice(0, -1).trim();
      const mapped = this.TYPE_MAP[baseType];
      return mapped ? { ...mapped, isNullable: true } : this.mapSpineType(baseType);
    }
    
    // Handle direct mappings
    return this.TYPE_MAP[cType] || this.mapSpineType(cType);
  }

  private static mapSpineType(cType: string): DartType {
    if (cType.startsWith('spine_')) {
      // spine_animation -> Animation
      const dartName = toPascalCase(cType.replace('spine_', ''));
      return { dart: dartName, isNative: false };
    }
    
    // Default to dynamic for unknown types
    return { dart: 'dynamic', isNative: false };
  }
}
```

### 3. Naming Convention Utilities (`dart-naming.ts`)

Handles C to Dart naming conversions:

```typescript
export function toPascalCase(snakeCase: string): string {
  return snakeCase
    .split('_')
    .map(word => word.charAt(0).toUpperCase() + word.slice(1).toLowerCase())
    .join('');
}

export function toCamelCase(snakeCase: string): string {
  const pascal = toPascalCase(snakeCase);
  return pascal.charAt(0).toLowerCase() + pascal.slice(1);
}

export function extractMethodName(cFunctionName: string, className: string): string {
  // spine_animation_get_duration -> getDuration
  // spine_animation_set_duration -> setDuration
  // spine_animation_apply -> apply
  
  const prefix = `spine_${toSnakeCase(className)}_`;
  if (!cFunctionName.startsWith(prefix)) {
    throw new Error(`Function ${cFunctionName} doesn't match expected prefix ${prefix}`);
  }
  
  const methodPart = cFunctionName.slice(prefix.length);
  return toCamelCase(methodPart);
}

export function isGetter(methodName: string): boolean {
  return methodName.startsWith('get_');
}

export function isSetter(methodName: string): boolean {
  return methodName.startsWith('set_');
}

export function extractPropertyName(methodName: string): string {
  // get_duration -> duration
  // set_duration -> duration
  if (methodName.startsWith('get_') || methodName.startsWith('set_')) {
    return methodName.slice(4);
  }
  return methodName;
}
```

### 4. Dart Code Generator (`dart-writer.ts`)

Generates the actual Dart wrapper files:

```typescript
export class DartWriter {
  constructor(private outputDir: string, private bindingsImport: string) {}

  async writeClass(dartClass: DartClass): Promise<void> {
    const lines: string[] = [];
    
    // File header
    lines.push("// AUTO GENERATED FILE, DO NOT EDIT.");
    lines.push("// Generated by spine-c dart-wrapper generator");
    lines.push("");
    lines.push(`import '${this.bindingsImport}';`);
    lines.push("import 'dart:ffi';");
    lines.push("import 'array.dart';");
    lines.push("");
    
    // Class declaration
    lines.push(`class ${dartClass.name} {`);
    lines.push(`  final ${dartClass.nativeType} _ptr;`);
    lines.push(`  final SpineFlutterBindings _bindings;`);
    lines.push("");
    
    // Private constructor
    lines.push(`  ${dartClass.name}._(this._ptr, this._bindings);`);
    lines.push("");
    
    // Public constructors
    for (const constructor of dartClass.constructors) {
      lines.push(this.writeConstructor(dartClass, constructor));
      lines.push("");
    }
    
    // Getters
    for (const getter of dartClass.getters) {
      lines.push(this.writeGetter(getter));
    }
    
    // Setters  
    for (const setter of dartClass.setters) {
      lines.push(this.writeSetter(setter));
    }
    
    // Array getters
    for (const arrayGetter of dartClass.arrays) {
      lines.push(this.writeArrayGetter(arrayGetter));
    }
    
    // Methods
    for (const method of dartClass.methods) {
      lines.push(this.writeMethod(method));
      lines.push("");
    }
    
    // Disposal method (derived from class name)
    lines.push(`  void dispose() => _bindings.${dartClass.cName}_dispose(_ptr);`);
    
    lines.push("}");
    
    // Write to file
    const fileName = `${toSnakeCase(dartClass.name)}.dart`;
    const filePath = path.join(this.outputDir, fileName);
    await fs.writeFile(filePath, lines.join('\n'));
  }

  private writeConstructor(dartClass: DartClass, constructor: DartConstructor): string {
    const params = constructor.parameters.map(p => 
      `${p.type.dart} ${p.name}`
    ).join(', ');
    
    const args = constructor.parameters.map(p => 
      this.convertDartToC(p.name, p.type, p.cType)
    ).join(', ');
    
    return [
      `  factory ${dartClass.name}.create(SpineFlutterBindings bindings${params ? ', ' + params : ''}) {`,
      `    final ptr = bindings.${constructor.cFunctionName}(${args});`,
      `    return ${dartClass.name}._(ptr, bindings);`,
      `  }`
    ].join('\n');
  }

  private writeGetter(getter: DartGetter): string {
    if (getter.returnType.isNative) {
      return `  ${getter.returnType.dart} get ${getter.name} => _bindings.${getter.cFunctionName}(_ptr);`;
    } else {
      return [
        `  ${getter.returnType.dart} get ${getter.name} {`,
        `    final ptr = _bindings.${getter.cFunctionName}(_ptr);`,
        `    return ${getter.returnType.dart}._(ptr, _bindings);`,
        `  }`
      ].join('\n');
    }
  }

  private writeSetter(setter: DartSetter): string {
    const conversion = this.convertDartToC('value', setter.parameterType, '');
    return `  set ${setter.name}(${setter.parameterType.dart} value) => _bindings.${setter.cFunctionName}(_ptr, ${conversion});`;
  }

  private writeArrayGetter(arrayGetter: DartArrayGetter): string {
    return [
      `  Array<${arrayGetter.elementType}> get ${arrayGetter.name} {`,
      `    final array = _bindings.${arrayGetter.cGetterName}(_ptr);`,
      `    return Array.create<${arrayGetter.elementType}>(array, _bindings, ${arrayGetter.elementType}._);`,
      `  }`
    ].join('\n');
  }

  private writeMethod(method: DartMethod): string {
    const params = method.parameters.map(p => 
      `${p.type.dart} ${p.name}`
    ).join(', ');
    
    const args = ['_ptr', ...method.parameters.map(p => 
      this.convertDartToC(p.name, p.type, p.cType)
    )].join(', ');
    
    if (method.returnType.dart === 'void') {
      return [
        `  void ${method.name}(${params}) {`,
        `    _bindings.${method.cFunctionName}(${args});`,
        `  }`
      ].join('\n');
    } else if (method.returnType.isNative) {
      return [
        `  ${method.returnType.dart} ${method.name}(${params}) {`,
        `    return _bindings.${method.cFunctionName}(${args});`,
        `  }`
      ].join('\n');
    } else {
      return [
        `  ${method.returnType.dart} ${method.name}(${params}) {`,
        `    final ptr = _bindings.${method.cFunctionName}(${args});`,
        `    return ${method.returnType.dart}._(ptr, _bindings);`,
        `  }`
      ].join('\n');
    }
  }

  private convertDartToC(dartValue: string, dartType: DartType, cType: string): string {
    if (dartType.isNative) {
      // Handle string conversion
      if (dartType.dart === 'String') {
        return `${dartValue}.toNativeUtf8().cast<Char>()`;
      }
      return dartValue;
    } else {
      // Wrapper class - extract the pointer
      return `${dartValue}._ptr`;
    }
  }
}
```

### 5. Generic Array Implementation (`dart-array-writer.ts`)

Generates a single reusable Array class:

```typescript
export class DartArrayWriter {
  async writeArrayClass(outputDir: string): Promise<void> {
    const content = `
// AUTO GENERATED FILE, DO NOT EDIT.
// Generated by spine-c dart-wrapper generator

import 'dart:collection';
import 'dart:ffi';
import 'spine_flutter_bindings_generated.dart';

class Array<T> extends ListBase<T> {
  final Pointer _nativeArray;
  final SpineFlutterBindings _bindings;
  final T Function(Pointer) _elementFactory;
  final String _arrayTypeName;

  Array._(
    this._nativeArray,
    this._bindings,
    this._elementFactory,
    this._arrayTypeName,
  );

  static Array<T> create<T>(
    Pointer nativeArray,
    SpineFlutterBindings bindings,
    T Function(Pointer) elementFactory,
  ) {
    final typeName = T.toString().toLowerCase();
    return Array._(nativeArray, bindings, elementFactory, 'spine_array_\$typeName');
  }

  @override
  int get length {
    // Use dynamic function lookup based on type
    switch (_arrayTypeName) {
      case 'spine_array_timeline':
        return _bindings.spine_array_timeline_get_size(_nativeArray.cast());
      case 'spine_array_bone_data':
        return _bindings.spine_array_bone_data_get_size(_nativeArray.cast());
      case 'spine_array_slot_data':
        return _bindings.spine_array_slot_data_get_size(_nativeArray.cast());
      // Add more cases as needed
      default:
        throw UnsupportedError('Unknown array type: \$_arrayTypeName');
    }
  }

  @override
  T operator [](int index) {
    if (index < 0 || index >= length) {
      throw RangeError.index(index, this);
    }

    Pointer elementPtr;
    switch (_arrayTypeName) {
      case 'spine_array_timeline':
        elementPtr = _bindings.spine_array_timeline_get(_nativeArray.cast(), index);
        break;
      case 'spine_array_bone_data':
        elementPtr = _bindings.spine_array_bone_data_get(_nativeArray.cast(), index);
        break;
      case 'spine_array_slot_data':
        elementPtr = _bindings.spine_array_slot_data_get(_nativeArray.cast(), index);
        break;
      // Add more cases as needed
      default:
        throw UnsupportedError('Unknown array type: \$_arrayTypeName');
    }

    return _elementFactory(elementPtr);
  }

  @override
  void operator []=(int index, T value) {
    throw UnsupportedError('Array is read-only');
  }

  @override
  set length(int newLength) {
    throw UnsupportedError('Array is read-only');
  }
}
`;

    const filePath = path.join(outputDir, 'array.dart');
    await fs.writeFile(filePath, content.trim());
  }
}
```

### 6. Enum Generator (`dart-enum-writer.ts`)

Generates Dart enum wrappers:

```typescript
export class DartEnumWriter {
  async writeEnum(dartEnum: DartEnum, outputDir: string): Promise<void> {
    const lines: string[] = [];
    
    // File header
    lines.push("// AUTO GENERATED FILE, DO NOT EDIT.");
    lines.push("// Generated by spine-c dart-wrapper generator");
    lines.push("");
    
    // Enum declaration
    lines.push(`enum ${dartEnum.name} {`);
    
    // Enum values
    for (let i = 0; i < dartEnum.values.length; i++) {
      const value = dartEnum.values[i];
      const comma = i < dartEnum.values.length - 1 ? ',' : '';
      lines.push(`  ${value.name}(${value.value})${comma}`);
    }
    
    lines.push("");
    lines.push("  const ${dartEnum.name}(this.value);");
    lines.push("  final int value;");
    lines.push("");
    
    // From native conversion
    lines.push(`  static ${dartEnum.name} fromNative(int value) {`);
    lines.push("    switch (value) {");
    for (const value of dartEnum.values) {
      lines.push(`      case ${value.value}: return ${dartEnum.name}.${value.name};`);
    }
    lines.push(`      default: throw ArgumentError('Unknown ${dartEnum.name} value: \$value');`);
    lines.push("    }");
    lines.push("  }");
    lines.push("}");
    
    // Write to file
    const fileName = `${toSnakeCase(dartEnum.name)}.dart`;
    const filePath = path.join(outputDir, fileName);
    await fs.writeFile(filePath, lines.join('\n'));
  }
}
```

### 7. Main Generator Orchestrator (`dart-generator.ts`)

Coordinates the entire generation process:

```typescript
import { CClassOrStruct, CEnum, CArrayType } from './c-types';
import { DartClass, DartEnum } from './dart-types';
import { DartTypeMapper } from './dart-type-mapper';
import { DartWriter } from './dart-writer';
import { DartEnumWriter } from './dart-enum-writer';
import { DartArrayWriter } from './dart-array-writer';
import { extractMethodName, isGetter, isSetter, extractPropertyName } from './dart-naming';

export class DartGenerator {
  private typeMapper = new DartTypeMapper();
  private writer: DartWriter;
  private enumWriter = new DartEnumWriter();
  private arrayWriter = new DartArrayWriter();

  constructor(
    private cTypes: CClassOrStruct[],
    private cEnums: CEnum[],
    private cArrayTypes: CArrayType[],
    private outputDir: string,
    private bindingsImport: string = 'spine_flutter_bindings_generated.dart'
  ) {
    this.writer = new DartWriter(outputDir, bindingsImport);
  }

  async generateAll(): Promise<void> {
    // Ensure output directory exists
    await fs.mkdir(this.outputDir, { recursive: true });

    console.log(`Generating ${this.cTypes.length} Dart wrapper classes...`);
    
    // Generate wrapper classes
    for (const cType of this.cTypes) {
      const dartClass = this.convertCTypeToDartClass(cType);
      await this.writer.writeClass(dartClass);
      console.log(`Generated: ${dartClass.name}`);
    }

    console.log(`Generating ${this.cEnums.length} Dart enums...`);
    
    // Generate enums
    for (const cEnum of this.cEnums) {
      const dartEnum = this.convertCEnumToDartEnum(cEnum);
      await this.enumWriter.writeEnum(dartEnum, this.outputDir);
      console.log(`Generated enum: ${dartEnum.name}`);
    }

    // Generate generic Array class
    await this.arrayWriter.writeArrayClass(this.outputDir);
    console.log('Generated: Array<T>');

    console.log('Dart wrapper generation complete!');
  }

  private convertCTypeToDartClass(cType: CClassOrStruct): DartClass {
    const className = toPascalCase(cType.name.replace('spine_', ''));
    
    // Separate getters, setters, and regular methods
    const getters: DartGetter[] = [];
    const setters: DartSetter[] = [];
    const methods: DartMethod[] = [];
    const constructors: DartConstructor[] = [];
    const arrays: DartArrayGetter[] = [];

    for (const method of cType.methods) {
      const methodName = extractMethodName(method.name, cType.name);
      
      if (method.name.includes('_create')) {
        // Constructor
        constructors.push({
          cFunctionName: method.name,
          parameters: method.parameters.slice(0, -1).map(p => ({
            name: p.name,
            type: this.typeMapper.mapCTypeToDart(p.type),
            cType: p.type
          }))
        });
      } else if (isGetter(methodName)) {
        // Getter
        const propertyName = extractPropertyName(methodName);
        const returnType = this.typeMapper.mapCTypeToDart(method.returnType);
        
        // Check if this is an array getter
        if (method.returnType.startsWith('spine_array_')) {
          const elementType = this.extractArrayElementType(method.returnType);
          arrays.push({
            name: propertyName,
            elementType,
            cArrayType: method.returnType,
            cGetterName: method.name
          });
        } else {
          getters.push({
            name: propertyName,
            cFunctionName: method.name,
            returnType
          });
        }
      } else if (isSetter(methodName)) {
        // Setter
        const propertyName = extractPropertyName(methodName);
        const paramType = this.typeMapper.mapCTypeToDart(method.parameters[1].type);
        setters.push({
          name: propertyName,
          cFunctionName: method.name,
          parameterType: paramType
        });
      } else {
        // Regular method
        methods.push({
          name: methodName,
          cFunctionName: method.name,
          returnType: this.typeMapper.mapCTypeToDart(method.returnType),
          parameters: method.parameters.slice(1).map(p => ({
            name: p.name,
            type: this.typeMapper.mapCTypeToDart(p.type),
            cType: p.type
          }))
        });
      }
    }

    return {
      name: className,
      cName: cType.name,
      nativeType: `Pointer<${cType.name}_wrapper>`,
      constructors,
      methods,
      getters,
      setters,
      arrays
    };
  }

  private convertCEnumToDartEnum(cEnum: CEnum): DartEnum {
    return {
      name: toPascalCase(cEnum.name.replace('spine_', '')),
      cName: cEnum.name,
      values: cEnum.values.map(value => ({
        name: toCamelCase(value.name.replace(/^SPINE_.*?_/, '')),
        cName: value.name,
        value: value.value
      }))
    };
  }

  private extractArrayElementType(arrayType: string): string {
    // spine_array_timeline -> Timeline
    // spine_array_bone_data -> BoneData
    const match = arrayType.match(/spine_array_(.+)/);
    if (!match) throw new Error(`Invalid array type: ${arrayType}`);
    
    return toPascalCase(match[1]);
  }
}
```

### 8. Integration with Existing Codegen (`index.ts` modifications)

Extend the existing main function:

```typescript
// Add to existing imports
import { DartGenerator } from './dart-generator';

// Add to existing main() function after C generation
async function main() {
    // ... existing C generation code ...

    // Write all C files to disk
    const cWriter = new CWriter(path.join(__dirname, '../../src/generated'));
    await cWriter.writeAll(cTypes, cEnums, cArrayTypes);

    console.log('C code generation complete!');

    // NEW: Generate Dart wrappers
    const dartOutputDir = path.join(__dirname, '../../../lib/src/generated');
    const dartGenerator = new DartGenerator(
        cTypes,
        cEnums, 
        cArrayTypes,
        dartOutputDir
    );
    
    await dartGenerator.generateAll();

    console.log('All code generation complete!');
}
```

## Generated Output Structure

After running the generator, the output structure will be:

```
lib/
├── spine_flutter.dart                    # Main export file
├── spine_flutter_bindings_generated.dart # Raw FFI bindings (from ffigen)
└── src/
    └── generated/
        ├── array.dart                    # Generic Array<T> implementation
        ├── animation.dart                # Animation wrapper class
        ├── skeleton.dart                 # Skeleton wrapper class
        ├── bone_data.dart               # BoneData wrapper class
        ├── blend_mode.dart              # BlendMode enum
        └── ...                          # More generated classes and enums
```

## Usage Examples

### Before (Manual FFI Usage)
```dart
// Raw FFI - error-prone and verbose
final skeletonDataPtr = bindings.spine_skeleton_data_create_from_file('skeleton.json'.toNativeUtf8().cast());
final bonesArrayPtr = bindings.spine_skeleton_data_get_bones(skeletonDataPtr);
final numBones = bindings.spine_skeleton_data_get_num_bones(skeletonDataPtr);

for (int i = 0; i < numBones; i++) {
  final bonePtr = bindings.spine_array_bone_data_get(bonesArrayPtr, i);
  final namePtr = bindings.spine_bone_data_get_name(bonePtr);
  final name = namePtr.cast<Utf8>().toDartString();
  print('Bone: $name');
}

bindings.spine_skeleton_data_dispose(skeletonDataPtr);
```

### After (Generated Wrapper Usage)
```dart
// Clean, type-safe API
final skeletonData = SkeletonData.fromFile(bindings, 'skeleton.json');
final bones = skeletonData.bones;  // Array<BoneData>

for (final bone in bones) {  // Natural Dart iteration
  print('Bone: ${bone.name}');  // Direct property access
}

skeletonData.dispose();  // Clean disposal
```

### Advanced Usage
```dart
// Complex operations made simple
final skeleton = Skeleton.create(bindings, skeletonData);
final animState = AnimationState.create(bindings, animStateData);

// Arrays work like native Dart Lists
final animations = skeleton.data.animations;
final firstAnim = animations[0];
final animCount = animations.length;

// Functional programming support
final animNames = animations.map((a) => a.name).toList();
final longAnims = animations.where((a) => a.duration > 5.0).toList();

// Enum usage
skeleton.setSkin('goblin');
animState.setAnimation(0, firstAnim, true);
animState.setMixByName('idle', 'walk', 0.2);

// Chaining operations
skeleton.data.bones
  .where((bone) => bone.parent != null)
  .forEach((bone) => print('Child bone: ${bone.name}'));
```

## Build Integration

### 1. Update `generate_bindings.sh`

Add Dart wrapper generation to the existing script:

```bash
#!/bin/bash

# ... existing FFI generation code ...

# Generate Dart wrappers
echo "Generating Dart wrapper classes..."
cd src/spine-c/codegen
npm run generate-dart

echo "✅ All code generation completed!"
```

### 2. Add npm script to `spine-c/codegen/package.json`

```json
{
  "scripts": {
    "build": "tsc",
    "generate": "npm run build && node dist/index.js",
    "generate-dart": "npm run build && node dist/index.js --dart-only",
    "test": "echo \"Error: no test specified\" && exit 1"
  }
}
```

### 3. Update `pubspec.yaml` dependencies

The generated code will require:

```yaml
dependencies:
  flutter:
    sdk: flutter
  ffi: ^2.1.0
  # ... existing dependencies
```

## Benefits

### 1. **Developer Experience**
- **Type Safety**: Compile-time checking prevents FFI pointer errors
- **IDE Support**: Full autocomplete, documentation, and refactoring
- **Familiar API**: Uses standard Dart patterns (getters, setters, Lists)
- **Memory Safety**: Automatic lifetime management with dispose patterns

### 2. **Performance**
- **Zero Copy**: Arrays provide lazy access to native data
- **Minimal Overhead**: Thin wrappers over FFI calls
- **Batch Operations**: Array operations can be optimized in native code

### 3. **Maintainability**
- **Automatic Updates**: Changes to C++ API automatically flow through
- **Consistent Patterns**: All classes follow the same conventions
- **Documentation**: Generated code includes comprehensive docs
- **Testing**: Type-safe API makes unit testing straightforward

### 4. **Reliability**
- **No Manual Coding**: Eliminates human error in wrapper implementation
- **Validated Generation**: Uses proven C type information
- **Comprehensive Coverage**: Every C function gets a Dart wrapper

## Implementation Timeline

### Phase 1: Core Infrastructure (1-2 weeks)
- [ ] Set up TypeScript generator project structure
- [ ] Implement basic type mapping system
- [ ] Create simple class generator for basic types
- [ ] Test with a few example classes (Animation, Skeleton)

### Phase 2: Array Support (1 week)
- [ ] Implement generic Array<T> class
- [ ] Add array detection and generation logic
- [ ] Test array functionality with timeline/bone arrays

### Phase 3: Enum Support (3-5 days)
- [ ] Add enum detection and generation
- [ ] Implement enum value mapping
- [ ] Test with BlendMode and other enums

### Phase 4: Advanced Features (1 week)
- [ ] Add constructor detection and generation
- [ ] Implement property getter/setter pairing
- [ ] Add disposal pattern detection
- [ ] Memory management best practices

### Phase 5: Integration & Polish (3-5 days)
- [ ] Integrate with existing build pipeline
- [ ] Add comprehensive documentation
- [ ] Create migration guide from manual FFI
- [ ] Performance testing and optimization

### Phase 6: Testing & Validation (1 week)
- [ ] Unit tests for all generated wrappers
- [ ] Integration tests with actual Spine files
- [ ] Performance benchmarks vs raw FFI
- [ ] Documentation and examples

**Total Estimated Time: 4-6 weeks**

## Future Enhancements

### 1. **Advanced Memory Management**
- Automatic disposal when objects go out of scope
- Reference counting for shared objects
- Memory leak detection in debug mode

### 2. **Performance Optimizations**
- Cached property access
- Batch array operations
- Native collection implementations

### 3. **Developer Tools**
- Debug visualizations for Spine objects
- Memory usage monitoring
- Performance profiling integration

### 4. **API Enhancements**
- Async/Future support for long operations
- Stream-based event handling
- Reactive programming patterns

This comprehensive generator will transform the Spine Flutter experience from low-level FFI manipulation to a clean, type-safe, and performant Dart API that feels native to the Flutter ecosystem.