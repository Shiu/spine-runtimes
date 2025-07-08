#!/usr/bin/env node
import * as fs from 'fs';
import * as path from 'path';
import { Type, Member, SpineTypes, toSnakeCase } from './types';
import { loadExclusions, isTypeExcluded, isMethodExcluded } from './exclusions';
import { loadRttiBases } from './rtti';
import { OpaqueTypeGenerator } from './generators/opaque-type-generator';
import { ConstructorGenerator } from './generators/constructor-generator';
import { MethodGenerator } from './generators/method-generator';
import { EnumGenerator } from './generators/enum-generator';
import { RttiGenerator } from './generators/rtti-generator';
import { FileWriter } from './file-writer';

async function main() {
    console.log('Loading type information...');
    
    // Load all necessary data
    const typesJson = JSON.parse(fs.readFileSync(path.join(__dirname, '../all-spine-types.json'), 'utf8')) as SpineTypes;
    const exclusions = loadExclusions(path.join(__dirname, '../exclusions.txt'));
    const rttiBases = loadRttiBases(path.join(__dirname, '../rtti-bases.txt'));
    
    // Flatten all types from all headers into a single array
    const allTypes: Type[] = [];
    for (const header of Object.keys(typesJson)) {
        allTypes.push(...typesJson[header]);
    }
    
    // Filter out excluded types
    const includedTypes = allTypes.filter(type => !isTypeExcluded(type.name, exclusions));
    
    // Separate classes and enums
    const classes = includedTypes.filter(t => t.kind === 'class' || t.kind === 'struct');
    const enums = includedTypes.filter(t => t.kind === 'enum');
    
    console.log(`Found ${classes.length} classes/structs and ${enums.length} enums to generate`);
    
    // Initialize generators
    const opaqueTypeGen = new OpaqueTypeGenerator();
    const constructorGen = new ConstructorGenerator();
    const methodGen = new MethodGenerator(exclusions);
    const enumGen = new EnumGenerator();
    const rttiGen = new RttiGenerator(rttiBases, allTypes);
    const fileWriter = new FileWriter(path.join(__dirname, '../../src/generated'));
    
    // Generate code for each type
    for (const type of classes) {
        console.log(`Generating ${type.name}...`);
        
        const headerContent: string[] = [];
        const sourceContent: string[] = [];
        
        // Add includes
        headerContent.push('#include "../custom.h"');
        headerContent.push('');
        
        sourceContent.push(`#include "${toSnakeCase(type.name)}.h"`);
        sourceContent.push('#include <spine/spine.h>');
        sourceContent.push('');
        sourceContent.push('using namespace spine;');
        sourceContent.push('');
        
        // Generate opaque type
        headerContent.push(opaqueTypeGen.generate(type));
        headerContent.push('');
        
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
        
        // Check if this type needs RTTI
        if (rttiGen.needsRtti(type)) {
            const rtti = rttiGen.generateForType(type);
            if (rtti.declarations.length > 0) {
                headerContent.push(...rtti.declarations);
                sourceContent.push(...rtti.implementations);
            }
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
    
    // Generate main header file
    await fileWriter.writeMainHeader(classes, enums);
    
    console.log('Code generation complete!');
}

main().catch(error => {
    console.error('Error:', error);
    process.exit(1);
});