#!/usr/bin/env node
import * as path from 'node:path';
import { fileURLToPath } from 'node:url';
import { CWriter } from './c-writer';
import { checkConstNonConstConflicts, checkFieldAccessorConflicts, checkMethodTypeNameConflicts, checkMultiLevelPointers, checkValueReturns } from './checks';
import { isTypeExcluded, loadExclusions } from './exclusions';
import { generateArrays, generateTypes } from './ir-generator';
import { extractTypes } from './type-extractor';
import type { ClassOrStruct } from './types';
import { toSnakeCase } from './types';

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

    // Build inheritance relationships including template classes
    const supertypes = buildSupertypesMap(allExtractedTypes.filter(t => t.kind !== 'enum') as ClassOrStruct[], types.filter(t => t.kind !== 'enum') as ClassOrStruct[]);

    console.log('Built supertypes map with', Object.keys(supertypes).length, 'entries');
    for (const [child, supertypeList] of Object.entries(supertypes)) {
        if (child.includes('constraint')) {
            console.log(`  ${child} -> [${supertypeList.join(', ')}]`);
        }
    }

    // Build subtypes map (opposite of supertypes)  
    const subtypes = buildSubtypesMap(supertypes);
    
    return { cTypes, cEnums, cArrayTypes, supertypes, subtypes };
}

/** Build supertypes map for inheritance relationships, including template classes */
function buildSupertypesMap(allTypes: (ClassOrStruct)[], nonTemplateTypes: (ClassOrStruct)[]): Record<string, string[]> {
    const supertypes: Record<string, string[]> = {};
    const typeMap = new Map<string, ClassOrStruct>();

    // Build type lookup map from all types (including templates)
    for (const type of allTypes) {
        typeMap.set(type.name, type);
    }

    // Build non-template type lookup for C names
    const nonTemplateMap = new Map<string, ClassOrStruct>();
    for (const type of nonTemplateTypes) {
        nonTemplateMap.set(type.name, type);
    }

    // For each non-template type, find all non-template ancestors
    for (const type of nonTemplateTypes) {
        const classType = type;
        const cName = `spine_${toSnakeCase(classType.name)}`;
        const supertypeList = findNonTemplateSupertypes(classType, typeMap, nonTemplateMap);

        if (supertypeList.length > 0) {
            supertypes[cName] = supertypeList;
        }
    }

    return supertypes;
}

/** Find all non-template supertypes for a given type */
function findNonTemplateSupertypes(type: ClassOrStruct, typeMap: Map<string, ClassOrStruct>, nonTemplateMap: Map<string, ClassOrStruct>): string[] {
    const visited = new Set<string>();
    const supertypes: string[] = [];

    function traverse(currentType: ClassOrStruct) {
        if (visited.has(currentType.name)) return;
        visited.add(currentType.name);

        if (!currentType.superTypes) return;

        for (const superTypeName of currentType.superTypes) {
            // Extract base type name from templated types like "ConstraintGeneric<...>"
            const baseTypeName = superTypeName.split('<')[0];
            const superType = typeMap.get(baseTypeName);
            if (!superType) continue;

            // If this supertype is not a template and has bindings, add it to supertypes
            if (!superType.isTemplate && nonTemplateMap.has(superType.name)) {
                const cName = `spine_${toSnakeCase(superType.name)}`;
                if (!supertypes.includes(cName)) {
                    supertypes.push(cName);
                }
            }

            // Continue traversing up the chain (through templates too)
            traverse(superType);
        }
    }

    traverse(type);
    return supertypes;
}

/** Build subtypes map from supertypes data */
function buildSubtypesMap(supertypes: Record<string, string[]>): Record<string, string[]> {
    const subtypes: Record<string, string[]> = {};
    
    // For each type and its supertypes, add this type to each supertype's subtypes list
    for (const [childType, supertypeList] of Object.entries(supertypes)) {
        for (const supertype of supertypeList) {
            if (!subtypes[supertype]) {
                subtypes[supertype] = [];
            }
            if (!subtypes[supertype].includes(childType)) {
                subtypes[supertype].push(childType);
            }
        }
    }
    
    return subtypes;
}

async function main() {
    // Check if we should just export JSON for debugging
    if (process.argv.includes('--export-json')) {
        // Suppress console output during generation
        const originalLog = console.log;
        console.log = () => {};

        const { cTypes, cEnums, cArrayTypes, supertypes, subtypes } = await generate();

        // Restore console.log and output JSON
        console.log = originalLog;
        console.log(JSON.stringify({ cTypes, cEnums, cArrayTypes, supertypes, subtypes }, null, 2));
        return;
    }

    // Generate C types and enums
    const { cTypes, cEnums, cArrayTypes, supertypes, subtypes } = await generate();

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