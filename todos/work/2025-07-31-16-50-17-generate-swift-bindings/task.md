# Generate bindings for Swift from spine-c
**Status:** InProgress
**Agent PID:** 83687

## Original Todo
Generate bindings for Swift from spine-c generate() like dart-writer.ts

## Description
Create a TypeScript-based Swift bindings generator that uses the spine-c codegen infrastructure to generate idiomatic Swift code. The generator will replace the existing Python-based generator and produce type-safe Swift wrappers around the spine-c API, similar to how the Dart generator works. It will generate classes with proper inheritance hierarchy, nullability annotations, memory management, and maintain compatibility with the existing Swift API while adding modern Swift features.

Read [analysis.md](./analysis.md) in full for analysis results and context.

## Implementation Plan
- [x] Create the Swift codegen package structure (spine-ios/codegen/)
   - Set up TypeScript project with package.json, tsconfig.json
   - Add dependency on spine-c-codegen package
   - Create src/index.ts as entry point
   - Create src/swift-writer.ts for Swift code generation

- [x] Implement SwiftWriter class (spine-ios/codegen/src/swift-writer.ts)
   - Use DartWriter as reference for structure but implement Swift-specific patterns
   - Map C types to Swift types (OpaquePointer, String, Bool, etc.)
   - Handle nullability with Swift optionals
   - Generate proper class/protocol inheritance

- [x] Generate Swift classes from CIR
   - Concrete classes with NSObject inheritance and @objc annotations
   - Abstract classes with proper subclass requirements
   - Protocols for interface types (like Constraint, Update)
   - Proper memory management with deinit methods

- [x] Generate Swift enums
   - Use Swift enums with raw values for C enums
   - Add fromValue static methods for reverse lookup
   - Generate proper case names from C enum values

- [x] Generate array wrapper types
   - Create Swift array wrapper classes for each spine_array_* type
   - Implement subscript operators and collection protocols
   - Handle memory ownership and disposal

- [x] Handle RTTI-based instantiation
   - Generate switch statements for abstract type instantiation
   - Map C++ class names to Swift concrete types
   - Handle unknown types gracefully

- [x] Generate method implementations
   - Convert C function calls to Swift methods
   - Handle method overloading (numbered C methods)
   - Generate computed properties for getter/setter pairs
   - Add proper null checking and optional unwrapping

- [x] Create output file structure
   - Generate individual .swift files per type
   - Create Arrays.swift for all array types
   - Create Enums.swift for all enum types
   - Generate main exports file

- [x] Add build integration
   - Create build script to run the generator
   - Update spine-ios Package.swift to include generated files

- [x] Create minimal test package (spine-ios/test/) inspired by spine-flutter/test
   - Minimal Package.swift for quick iteration
   - Test harness without full spine-ios dependencies
   - Basic examples to verify generated bindings work

- [x] Test the generated code
   - Verify compilation with Swift compiler
   - Test against the minimal test package
   - Ensure backward compatibility with existing API

- [x] User test: Generate Swift bindings and verify they compile and work correctly in the test package

## SpineSwift Module Implementation - COMPLETED & TODO

### Current Module Structure (COMPLETED)
We successfully restructured the spine-ios modules into three clean layers:

1. **SpineC** (✅ WORKING)
   - Location: `spine-ios/Sources/SpineC/`
   - Contains: Symlinks to spine-c and spine-cpp
   - Purpose: Compiles C/C++ sources, exposes C API to Swift
   - Status: Fully functional, tests pass

2. **SpineSwift** (⚠️ PARTIAL - has Objective-C conflicts)
   - Location: `spine-ios/Sources/SpineSwift/`
   - Contains:
     - `Generated/` - All generated Swift bindings from codegen
     - `Extensions/` - Platform-agnostic helper functions
   - Purpose: Swift bindings + high-level API (like spine_dart.dart)
   - Status: Generated but has Objective-C selector conflicts

3. **SpineiOS** (✅ RESTRUCTURED)
   - Location: `spine-ios/Sources/SpineiOS/`
   - Contains: iOS-specific UI components only
   - Files: SpineUIView, SpineController, SkeletonDrawableWrapper, etc.
   - Purpose: iOS-specific rendering and UI integration
   - Status: Cleaned up, old Generated folder removed

### What We Accomplished
- [x] Created proper module separation (SpineC, SpineSwift, SpineiOS)
- [x] Set up SpineC with symlinks to spine-c and spine-cpp
- [x] Updated Package.swift with correct target dependencies
- [x] Updated codegen to output to SpineSwift/Generated
- [x] Generated Swift bindings with proper imports
- [x] Created SpineSwift.swift with basic helper functions (loadAtlas, loadSkeletonData)
- [x] Removed SpineModule (redundant re-export module)
- [x] Fixed test package to use SpineC directly
- [x] Created skeleton_drawable_test.swift ported from Dart
- [x] Cleaned up test folder structure (removed accidental spine-ios subfolder)
- [x] Test successfully runs using SpineC module

### Known Issues
1. **SpineSwift has Objective-C selector conflicts**
   - Methods like `copy()` conflict with NSObject
   - Constructor `init(_:)` conflicts in inheritance hierarchies
   - Need to either rename methods or remove @objc annotations

2. **Swift Package Manager limitation**
   - Cannot mix C/C++ and Swift in same target
   - Must keep SpineC and SpineSwift as separate modules

### TODO - High Priority
- [ ] Fix Objective-C selector conflicts in generated Swift code
   - Option 1: Rename conflicting methods (e.g., copy -> copyAttachment)
   - Option 2: Remove @objc annotations where not needed
   - Option 3: Use different selector names with @objc(customName:)

- [ ] Complete SpineSwift high-level API (port from spine_dart.dart)
   - [ ] SkeletonDrawable class
   - [ ] AnimationStateEventManager
   - [ ] Bounds and Vector types
   - [ ] Skin extensions (getEntries)
   - [ ] BonePose coordinate transformations
   - [ ] Animation state listener management

- [ ] Update skeleton_drawable_test to use SpineSwift API
   - Currently uses SpineC directly
   - Should test the high-level Swift API once working

### File Locations Reference
- Codegen: `spine-ios/codegen/src/swift-writer.ts`
- Generated output: `spine-ios/Sources/SpineSwift/Generated/`
- Test package: `spine-ios/test/`
- Test source: `spine-ios/test/src/skeleton_drawable_test.swift`

### Important Notes
- The test currently imports SpineC directly and works perfectly
- VS Code may show "no such module SpineC" but builds work fine (IDE issue)
- Generated files are in SpineSwift, NOT in SpineiOS
- SpineiOS should only contain iOS-specific UI components
- The symlinks in SpineC point to ../../../spine-c and ../../../spine-cpp