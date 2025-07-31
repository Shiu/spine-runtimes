# Generate bindings for Swift from spine-c
**Status:** InProgress
**Agent PID:** 43132

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

- [ ] Generate Swift classes from CIR
   - Concrete classes with NSObject inheritance and @objc annotations
   - Abstract classes with proper subclass requirements
   - Protocols for interface types (like Constraint, Update)
   - Proper memory management with deinit methods

- [ ] Generate Swift enums
   - Use Swift enums with raw values for C enums
   - Add fromValue static methods for reverse lookup
   - Generate proper case names from C enum values

- [ ] Generate array wrapper types
   - Create Swift array wrapper classes for each spine_array_* type
   - Implement subscript operators and collection protocols
   - Handle memory ownership and disposal

- [ ] Handle RTTI-based instantiation
   - Generate switch statements for abstract type instantiation
   - Map C++ class names to Swift concrete types
   - Handle unknown types gracefully

- [ ] Generate method implementations
   - Convert C function calls to Swift methods
   - Handle method overloading (numbered C methods)
   - Generate computed properties for getter/setter pairs
   - Add proper null checking and optional unwrapping

- [ ] Create output file structure
   - Generate individual .swift files per type
   - Create Arrays.swift for all array types
   - Create Enums.swift for all enum types
   - Generate main exports file

- [ ] Add build integration
   - Create build script to run the generator
   - Update spine-ios Package.swift to include generated files

- [ ] Create minimal test package (spine-ios/test/) inspired by spine-flutter/test
   - Minimal Package.swift for quick iteration
   - Test harness without full spine-ios dependencies
   - Basic examples to verify generated bindings work

- [ ] Test the generated code
   - Verify compilation with Swift compiler
   - Test against the minimal test package
   - Ensure backward compatibility with existing API

- [ ] User test: Generate Swift bindings and verify they compile and work correctly in the test package

## Notes
[Implementation notes]