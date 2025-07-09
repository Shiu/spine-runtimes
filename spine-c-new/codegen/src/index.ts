#!/usr/bin/env node
import * as fs from 'fs';
import * as path from 'path';
import { Type, Member, SpineTypes, toSnakeCase, Exclusion } from './types';
import { loadExclusions, isTypeExcluded, isMethodExcluded } from './exclusions';
import { ConstructorGenerator } from './generators/constructor-generator';
import { MethodGenerator } from './generators/method-generator';
import { EnumGenerator } from './generators/enum-generator';
import { ArrayGenerator } from './generators/array-generator';
import { FileWriter } from './file-writer';
import { extractTypes, loadTypes } from './type-extractor';
import { scanArraySpecializations } from './array-scanner';

/**
 * Checks for methods that have both const and non-const versions with different return types.
 * This is a problem for C bindings because C doesn't support function overloading.
 *
 * In C++, you can have:
 *   T& getValue();              // for non-const objects
 *   const T& getValue() const;  // for const objects
 *
 * But in C, we can only have one function with a given name, so we need to detect
 * and report these conflicts.
 *
 * @param classes - Array of class/struct types to check
 * @param exclusions - Exclusion rules to skip specific methods
 * @returns Array of conflicts found, or exits if conflicts exist
 */
function checkConstNonConstConflicts(classes: Type[], exclusions: Exclusion[]): void {
    const conflicts: Array<{ type: string, method: string }> = [];

    for (const type of classes) {
        if (type.members === undefined) {
            continue;
        }

        // Get all non-static methods first
        const allMethods = type.members?.filter(m => m.kind === 'method').filter(m => !m.isStatic);

        if (allMethods) {
            const methodGroups = new Map<string, Array<Member & { kind: 'method' }>>();
            for (const method of allMethods) {
                if (method.name === 'getSetupPose') {
                    console.log(`Skipping excluded method: ${type.name}::${method.name}${method.isConst ? ' const' : ''}`);
                }
                // Skip if this specific const/non-const version is excluded
                if (isMethodExcluded(type.name, method.name, exclusions, method)) {
                    continue;
                }
                const key = method.name + '(' + (method.parameters?.map(p => p.type).join(',') || '') + ')';
                if (!methodGroups.has(key)) {
                    methodGroups.set(key, []);
                }
                methodGroups.get(key)!.push(method);
            }

            for (const [signature, group] of methodGroups) {
                if (group.length > 1) {
                    const returnTypes = new Set(group.map(m => m.returnType));
                    if (returnTypes.size > 1) {
                        conflicts.push({ type: type.name, method: group[0].name });
                    }
                }
            }
        }
    }

    // If we found conflicts, report them all and exit
    if (conflicts.length > 0) {
        console.error("\n" + "=".repeat(80));
        console.error("SUMMARY OF ALL CONST/NON-CONST METHOD CONFLICTS");
        console.error("=".repeat(80));
        console.error(`\nFound ${conflicts.length} method conflicts across the codebase:\n`);

        for (const conflict of conflicts) {
            console.error(`  - ${conflict.type}::${conflict.method}()`);
        }

        console.error("\nThese methods have both const and non-const versions in C++ which cannot");
        console.error("be represented in the C API. You need to either:");
        console.error("  1. Add these to exclusions.txt");
        console.error("  2. Modify the C++ code to avoid const/non-const overloading");
        console.error("=".repeat(80) + "\n");

        process.exit(1);
    }
}

/**
 * Checks for multi-level pointers in method signatures and errors if found
 */
function checkMultiLevelPointers(types: Type[]) {
    const errors: {type: string, member: string, signature: string}[] = [];

    // Helper to check if a type has multi-level pointers
    function hasMultiLevelPointers(typeStr: string): boolean {
        // First check the outer type (after removing template content)
        let outerType = typeStr;
        
        // Extract all template contents for separate checking
        const templateContents: string[] = [];
        let depth = 0;
        let templateStart = -1;
        
        for (let i = 0; i < typeStr.length; i++) {
            if (typeStr[i] === '<') {
                if (depth === 0) {
                    templateStart = i + 1;
                }
                depth++;
            } else if (typeStr[i] === '>') {
                depth--;
                if (depth === 0 && templateStart !== -1) {
                    templateContents.push(typeStr.substring(templateStart, i));
                    templateStart = -1;
                }
            }
        }
        
        // Remove all template content from outer type
        outerType = outerType.replace(/<[^>]+>/g, '<>');
        
        // Check outer type for consecutive pointers
        if (/\*\s*\*/.test(outerType)) {
            return true;
        }
        
        // Recursively check template contents
        for (const content of templateContents) {
            if (hasMultiLevelPointers(content)) {
                return true;
            }
        }
        
        return false;
    }

    for (const type of types) {
        if (!type.members) continue;

        for (const member of type.members) {
            if (member.kind === 'method') {
                // Check return type
                if (hasMultiLevelPointers(member.returnType)) {
                    errors.push({
                        type: type.name,
                        member: member.name,
                        signature: `return type: ${member.returnType}`
                    });
                }

                // Check parameters
                if (member.parameters) {
                    for (const param of member.parameters) {
                        if (hasMultiLevelPointers(param.type)) {
                            errors.push({
                                type: type.name,
                                member: member.name,
                                signature: `parameter '${param.name}': ${param.type}`
                            });
                        }
                    }
                }
            } else if (member.kind === 'field') {
                // Check field type
                if (hasMultiLevelPointers(member.type)) {
                    errors.push({
                        type: type.name,
                        member: member.name,
                        signature: `field type: ${member.type}`
                    });
                }
            }
        }
    }

    // If we found multi-level pointers, report them and exit
    if (errors.length > 0) {
        console.error("\n" + "=".repeat(80));
        console.error("MULTI-LEVEL POINTER ERROR");
        console.error("=".repeat(80));
        console.error(`\nFound ${errors.length} multi-level pointer usage(s) which are not supported:\n`);

        for (const error of errors) {
            console.error(`  - ${error.type}::${error.member} - ${error.signature}`);
        }

        console.error("\nMulti-level pointers (e.g., char**, void***) cannot be represented in the C API.");
        console.error("You need to either:");
        console.error("  1. Refactor the C++ code to avoid multi-level pointers");
        console.error("  2. Exclude these types/methods in exclusions.txt");
        console.error("=".repeat(80) + "\n");

        process.exit(1);
    }
}

async function main() {
    // Extract types if needed
    extractTypes();

    console.log('Loading type information...');

    // Load all necessary data
    const typesJson = loadTypes() as SpineTypes;
    const exclusions = loadExclusions(path.join(__dirname, '../exclusions.txt'));

    // Flatten all types from all headers into a single array
    const allTypes: Type[] = [];
    for (const header of Object.keys(typesJson)) {
        allTypes.push(...typesJson[header]);
    }

    // Create a map of all types for easy lookup
    const typeMap = new Map<string, Type>();
    for (const type of allTypes) {
        typeMap.set(type.name, type);
    }


    // Filter types: only exclude templates and manually excluded types
    const includedTypes = allTypes.filter(type => {
        if (isTypeExcluded(type.name, exclusions)) {
            return false;
        }

        // Only exclude template types
        if (type.isTemplate === true) {
            console.log(`Auto-excluding template type: ${type.name}`);
            return false;
        }

        // Include everything else (including abstract types)
        return true;
    });

    // Separate classes and enums
    const classes = includedTypes.filter(t => t.kind === 'class' || t.kind === 'struct');
    const enums = includedTypes.filter(t => t.kind === 'enum');

    console.log(`Found ${classes.length} classes/structs and ${enums.length} enums to generate`);

    // Check for const/non-const conflicts
    checkConstNonConstConflicts(classes, exclusions);

    // Check for multi-level pointers
    checkMultiLevelPointers(includedTypes);

    // Create a set of valid type names for type checking
    const validTypes = new Set<string>(includedTypes.map(t => t.name));

    // Initialize generators
    const constructorGen = new ConstructorGenerator(validTypes);
    const methodGen = new MethodGenerator(exclusions, validTypes);
    const enumGen = new EnumGenerator();
    const fileWriter = new FileWriter(path.join(__dirname, '../../src/generated'));


    // Generate code for each type
    for (const type of classes) {
        console.log(`Generating ${type.name}...`);

        const headerContent: string[] = [];
        const sourceContent: string[] = [];

        // Source includes
        sourceContent.push(`#include "${toSnakeCase(type.name)}.h"`);
        sourceContent.push('#include <spine/spine.h>');
        sourceContent.push('');
        sourceContent.push('using namespace spine;');
        sourceContent.push('');

        // Opaque type is already in types.h, don't generate it here

        // Generate constructors
        const constructors = constructorGen.generate(type);
        if (constructors.declarations.length > 0) {
            headerContent.push(...constructors.declarations);
            sourceContent.push(...constructors.implementations);
        }

        // Generate methods
        const methods = methodGen.generate(type);
        if (methods.declarations.length > 0) {
            headerContent.push(...methods.declarations);
            sourceContent.push(...methods.implementations);
        }

        // Write files
        await fileWriter.writeType(type.name, headerContent, sourceContent);
    }

    // Generate enum files
    for (const enumType of enums) {
        console.log(`Generating enum ${enumType.name}...`);
        const enumCode = enumGen.generate(enumType);
        await fileWriter.writeEnum(enumType.name, enumCode);
    }

    // Generate Array specializations
    console.log('\nScanning for Array specializations...');
    const arraySpecs = scanArraySpecializations(includedTypes);
    console.log(`Found ${arraySpecs.length} array specializations to generate`);

    if (arraySpecs.length > 0) {
        console.log('\nGenerating arrays.h/arrays.cpp...');
        const arrayGen = new ArrayGenerator(typesJson);
        const { header, source } = arrayGen.generate(arraySpecs);

        // Write arrays.h and arrays.cpp
        await fileWriter.writeArrays(header, source);
    }

    // Generate types.h file (includes arrays.h)
    await fileWriter.writeTypesHeader(classes, enums);

    // Generate main header file
    await fileWriter.writeMainHeader(classes, enums);

    console.log('Code generation complete!');
}

main().catch(error => {
    console.error('Error:', error);
    process.exit(1);
});