#!/usr/bin/env node
import * as path from 'node:path';
import * as fs from 'node:fs/promises';
import { fileURLToPath } from 'node:url';
import { generate } from '../../../spine-c/codegen/src/index.js';
import { SwiftWriter } from './swift-writer.js';

const __dirname = path.dirname(fileURLToPath(import.meta.url));

async function main() {
    console.log('Generating Swift bindings from spine-c...');
    
    // Get the C intermediate representation from spine-c-codegen
    const { cTypes, cEnums, cArrayTypes, inheritance, supertypes, subtypes, isInterface } = await generate();
    
    // Create the Swift writer
    const writer = new SwiftWriter(
        cTypes,
        cEnums,
        cArrayTypes,
        inheritance,
        isInterface,
        supertypes,
        subtypes
    );
    
    // Prepare output directory
    const outputDir = path.join(__dirname, '..', '..', 'Sources', 'SpineSwift', 'Generated');
    await fs.mkdir(outputDir, { recursive: true });
    
    // Read license header
    const licenseHeaderPath = path.join(__dirname, '..', '..', '..', 'LICENSE');
    const licenseHeader = await fs.readFile(licenseHeaderPath, 'utf-8');
    
    // Generate Swift code
    await writer.generate({
        outputDir,
        licenseHeader
    });
    
    console.log('Swift bindings generation complete!');
}

main().catch(error => {
    console.error('Error:', error);
    process.exit(1);
});