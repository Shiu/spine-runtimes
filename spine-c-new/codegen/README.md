# Spine C API Code Generator

This TypeScript-based code generator automatically creates a C wrapper API for the Spine C++ runtime. It parses the spine-cpp headers and generates a complete C API with opaque types, following systematic type conversion rules.

## Table of Contents

1. [Overview](#overview)
2. [Architecture](#architecture)
3. [Type System](#type-system)
4. [File Structure](#file-structure)
5. [Generation Process](#generation-process)
6. [Key Design Decisions](#key-design-decisions)
7. [Exclusion System](#exclusion-system)
8. [Array Specializations](#array-specializations)
9. [Type Conversion Rules](#type-conversion-rules)
10. [Running the Generator](#running-the-generator)

## Overview

The generator creates a C API that wraps the spine-cpp C++ runtime, allowing C programs to use Spine functionality. Key features:

- **Opaque Types**: All C++ classes are exposed as opaque pointers in C
- **Automatic Memory Management**: Generates create/dispose functions
- **Method Wrapping**: Converts C++ methods to C functions with proper type conversion
- **Array Specializations**: Generates concrete array types for all Array<T> usage
- **Systematic Type Handling**: Uses categorized type conversion instead of ad-hoc rules

## Architecture

### Core Components

```
codegen/
├── src/
│   ├── index.ts                    # Main entry point
│   ├── types.ts                    # Type definitions and conversion
│   ├── exclusions.ts               # Exclusion system
│   ├── type-extractor.ts           # Automatic type extraction
│   ├── array-scanner.ts            # Array specialization scanner
│   ├── file-writer.ts              # File generation
│   └── generators/
│       ├── opaque-type-generator.ts    # Opaque type declarations
│       ├── constructor-generator.ts    # Create/dispose functions
│       ├── method-generator.ts         # Method wrappers
│       ├── enum-generator.ts           # Enum conversions
│       └── array-generator.ts          # Array specializations
├── exclusions.txt                  # Types/methods to exclude
└── spine-cpp-types.json           # Extracted type information
```

### Data Flow

1. **Type Extraction**: `extract-spine-cpp-types.js` parses C++ headers → `spine-cpp-types.json`
2. **Loading**: Generator loads JSON and exclusions
3. **Filtering**: Excludes types based on rules (templates, abstracts, manual exclusions)
4. **Generation**: Each generator processes types and creates C code
5. **Writing**: Files are written to `src/generated/`

## Type System

### Type Categories

The generator classifies all C++ types into systematic categories:

1. **Primitives**: `int`, `float`, `double`, `bool`, `char`, `void`, `size_t`
   - Direct mapping (e.g., `bool` → `bool`)

2. **Special Types**: String, function pointers, PropertyId
   - `String` → `const utf8 *`
   - `void *` → `spine_void`
   - `PropertyId` → `int64_t` (typedef'd to long long)

3. **Arrays**: `Array<T>` specializations
   - Generated as `spine_array_<element_type>`
   - Full API for each specialization

4. **Pointers**: Type followed by `*`
   - Primitive pointers stay as-is (`float *`)
   - Class pointers become opaque (`Bone *` → `spine_bone`)

5. **References**: Type followed by `&`
   - Const references: treated as value parameters
   - Non-const primitive references: output parameters (`float &` → `float *`)
   - Class references: converted to opaque types

6. **Enums**: Known spine enums
   - Prefixed with `spine_` and converted to snake_case

7. **Classes**: All other types
   - Assumed to be spine classes, converted to `spine_<snake_case>`

### Opaque Type Pattern

All C++ classes are exposed as opaque pointers:

```c
// In types.h
SPINE_OPAQUE_TYPE(spine_bone)  // Expands to typedef struct spine_bone_wrapper* spine_bone

// In implementation
spine_bone spine_bone_create() {
    return (spine_bone) new (__FILE__, __LINE__) Bone();
}
```

## File Structure

### Generated Files

- **types.h**: Forward declarations for all types
  - All opaque type declarations
  - Includes for all enum headers
  - Includes arrays.h at the bottom

- **arrays.h/arrays.cpp**: Array specializations
  - Generated for all Array<T> found in spine-cpp
  - Complete API for each specialization

- **<type>.h/.cpp**: One pair per type
  - Header contains function declarations
  - Source contains implementations

- **spine-c.h**: Main header that includes everything

### Include Order

The main spine-c.h includes files in this order:
1. base.h (basic definitions)
2. types.h (all forward declarations)
3. extensions.h (custom functionality)
4. All generated type headers

This ensures all types are declared before use.

## Generation Process

### 1. Type Extraction

The generator automatically runs `extract-spine-cpp-types.js` if:
- `spine-cpp-types.json` doesn't exist
- Any spine-cpp header is newer than the JSON file

This script:
- Parses all spine-cpp headers using tree-sitter
- Extracts complete type information including inherited members
- Resolves template inheritance
- Marks abstract classes and templates

### 2. Type Filtering

Types are excluded if they are:
- **Templates**: Detected by `isTemplate` field
- **Abstract**: Have unimplemented pure virtual methods
- **Internal utilities**: Array, String, HashMap, etc.
- **Manually excluded**: Listed in exclusions.txt

### 3. Code Generation

For each included type:

#### Constructors
- Generates `spine_<type>_create()` for default constructor
- Generates `spine_<type>_create_with_<params>()` for parameterized constructors
- Always generates `spine_<type>_dispose()` for cleanup

#### Methods
- Getters: `spine_<type>_get_<property>()`
- Setters: `spine_<type>_set_<property>()`
- Other methods: `spine_<type>_<method_name>()`
- Special handling for:
  - Vector return types (generate collection accessors)
  - RTTI methods (made static)
  - Const/non-const overloads (reported as errors)

#### Arrays
- Scans all types for Array<T> usage
- Generates specializations for each unique T
- Filters out template placeholders (T, K)
- Warns about problematic types (String, nested arrays)

## Key Design Decisions

### 1. Why Opaque Types?

C doesn't support classes or inheritance. Opaque pointers:
- Hide implementation details
- Prevent direct struct access
- Allow polymorphism through base type pointers
- Match C convention for handles

### 2. Why Generate Array Specializations?

C can't have template types. Options were:
1. Use `void *` everywhere (loses type safety)
2. Generate specializations (chosen approach)

Benefits:
- Type safety in C
- Better API documentation
- Prevents casting errors

### 3. Why Systematic Type Classification?

Original code had many special cases. Systematic approach:
- Reduces bugs from missed cases
- Makes behavior predictable
- Easier to maintain
- Clear rules for each category

### 4. Why Exclude Const Methods?

C doesn't have const-correctness. When C++ has:
```cpp
T& getValue();              // for non-const objects
const T& getValue() const;  // for const objects
```

C can only have one function name. We exclude const versions and expose non-const.

### 5. Why Static RTTI Methods?

RTTI objects are singletons in spine-cpp. Making getRTTI() static:
- Reflects actual usage (Type::rtti)
- Avoids unnecessary object parameter
- Cleaner API

## Exclusion System

### exclusions.txt Format

```
# Exclude entire types
type: SkeletonClipping
type: Triangulator

# Exclude specific methods
method: AnimationState::setListener
method: AnimationState::addListener

# Exclude const versions specifically
method: BoneData::getSetupPose const
```

### Exclusion Rules

1. **Type exclusions**: Entire type and all methods excluded
2. **Method exclusions**: Specific methods on otherwise included types
3. **Const-specific**: Can exclude just const or non-const version

## Array Specializations

### Scanning Process

1. Examines all members of non-excluded types
2. Extracts Array<T> patterns from:
   - Return types
   - Parameter types
   - Field types
3. Cleans element types (removes class/struct prefix)
4. Categorizes as primitive/enum/pointer

### Generated API

For each Array<T>, generates:
```c
// Creation
spine_array_float spine_array_float_create();
spine_array_float spine_array_float_create_with_capacity(int32_t capacity);
void spine_array_float_dispose(spine_array_float array);

// Element access
float spine_array_float_get(spine_array_float array, int32_t index);
void spine_array_float_set(spine_array_float array, int32_t index, float value);

// Array methods (auto-generated from Array type)
size_t spine_array_float_size(spine_array_float array);
void spine_array_float_clear(spine_array_float array);
void spine_array_float_add(spine_array_float array, float value);
// ... etc
```

### Special Cases

- **String arrays**: Warned but skipped (should use const char**)
- **Nested arrays**: Warned and skipped (Array<Array<T>>)
- **PropertyId**: Treated as int64_t, not enum

## Type Conversion Rules

### toCTypeName Function

Implements systematic type conversion:

1. **Remove namespace**: Strip any `spine::` prefix
2. **Check primitives**: Direct mapping via table
3. **Check special types**: String, void*, function pointers
4. **Check arrays**: Convert Array<T> to spine_array_*
5. **Check pointers**: Handle based on pointed-to type
6. **Check references**: Handle based on const-ness
7. **Check enums**: Known enum list
8. **Default to class**: Assume spine type

### Method Parameter Conversion

- **Input parameters**: C++ type to C type
- **Output parameters**: Non-const references become pointers
- **String parameters**: Create String objects from const char*
- **Enum parameters**: Cast to C++ enum type

### Return Value Conversion

- **Strings**: Return buffer() as const char*
- **References**: Take address and cast
- **Enums**: Cast to C enum type
- **Arrays**: Return as specialized array type

## Running the Generator

### Prerequisites

```bash
npm install
```

### Build and Run

```bash
npm run build  # Compile TypeScript
node dist/index.js  # Run generator
```

### What Happens

1. Checks if type extraction needed (file timestamps)
2. Runs extraction if needed
3. Loads types and exclusions
4. Filters types based on rules
5. Generates code for each type
6. Writes all files to src/generated/
7. Updates main spine-c.h

### Output

- Generates ~150 .h/.cpp file pairs
- Creates arrays.h with ~30 specializations
- All files include proper license headers
- Organized by type for easy navigation

## Maintenance

### Adding New Types

1. No action needed - automatically detected from spine-cpp

### Excluding Types/Methods

1. Add to exclusions.txt
2. Regenerate

### Changing Type Mappings

1. Update toCTypeName in types.ts
2. Follow systematic categories

### Debugging

- Check spine-cpp-types.json for extracted data
- Look for warnings in console output
- Verify exclusions are applied correctly
- Check generated files for correctness