#!/usr/bin/env node
import * as path from 'node:path';
import { fileURLToPath } from 'node:url';
import { CWriter } from './c-writer';
import { checkConstNonConstConflicts, checkFieldAccessorConflicts, checkMethodTypeNameConflicts, checkMultiLevelPointers, checkValueReturns } from './checks';
import { isTypeExcluded, loadExclusions } from './exclusions';
import { generateArrays, generateTypes } from './ir-generator';
import { extractTypes } from './type-extractor';
import type { ClassOrStruct } from './types';

const __dirname = path.dirname(fileURLToPath(import.meta.url));

export async function generate() {
    // Load all exclusions
    const exclusions = loadExclusions(path.join(__dirname, '../exclusions.txt'));

    // Extract ALL types from spine-cpp first (needed for inheritance checking)
    const allExtractedTypes = extractTypes();
    allExtractedTypes.sort((a, b) => a.name.localeCompare(b.name));

    // Then filter out excluded and template types
    let arrayType: ClassOrStruct | undefined;
    const types = allExtractedTypes.filter(type => {
        // Store the Array type, needed for array specializations
        if (type.name === 'Array' && type.kind !== 'enum') {
            arrayType = type as ClassOrStruct;
        }

        if (isTypeExcluded(type.name, exclusions)) {
            console.log(`Excluding type due to exclusions.txt: ${type.name}`);
            return false;
        }

        // Only exclude template types
        if (type.kind !== 'enum' && type.isTemplate === true) {
            console.log(`Auto-excluding template type: ${type.name}`);
            return false;
        }

        // Include everything else (including abstract types)
        return true;
    });

    if (!arrayType) {
        throw new Error('Array type not found in types');
    }

    // Separate classes and enums
    const classes = types.filter(t => t.kind !== "enum");
    const enums = types.filter(t => t.kind === 'enum');

    console.log(`Found ${classes.length} classes/structs and ${enums.length} enums to generate`);

    // Check for const/non-const conflicts
    checkConstNonConstConflicts(classes, exclusions);

    // Check for multi-level pointers
    checkMultiLevelPointers(classes);

    // Check for field accessor conflicts
    checkFieldAccessorConflicts(classes, exclusions);

    // Check for method/type name conflicts
    checkMethodTypeNameConflicts(classes, allExtractedTypes, exclusions);

    // Check for methods returning objects by value
    checkValueReturns(classes, allExtractedTypes, exclusions);

    // Generate C intermediate representation for classes, enums and arrays
    const { cTypes, cEnums } = await generateTypes(types, exclusions, allExtractedTypes);
    const cArrayTypes = await generateArrays(types, arrayType, exclusions);
    return { cTypes, cEnums, cArrayTypes };
}

async function main() {
    // Generate C types and enums
    const { cTypes, cEnums, cArrayTypes } = await generate();

    // Write all files to disk
    const cWriter = new CWriter(path.join(__dirname, '../../src/generated'));
    await cWriter.writeAll(cTypes, cEnums, cArrayTypes);

    console.log('Code generation complete!');
}

if (import.meta.url === `file://${process.argv[1]}`) {
    // Run the main function if this file is executed directly
    main().catch(error => {
        console.error('Error during code generation:', error);
        process.exit(1);
    });
}