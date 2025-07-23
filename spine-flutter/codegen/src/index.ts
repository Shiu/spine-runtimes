#!/usr/bin/env node
import { execSync } from 'node:child_process';
import * as fs from 'node:fs';
import * as path from 'node:path';
import { fileURLToPath } from 'node:url';
import { generate } from '../../../spine-c/codegen/src/index.js';
import { DartWriter } from './dart-writer.js';

const __dirname = path.dirname(fileURLToPath(import.meta.url));

async function generateFFIBindings(spineCDir: string): Promise<void> {
    console.log('Finding all header files...');
    const generatedDir = path.join(spineCDir, 'src/generated');
    const headerFiles = fs.readdirSync(generatedDir)
        .filter(f => f.endsWith('.h'))
        .map(f => path.join('src/spine-c/src/generated', f))
        .sort();

    console.log(`Found ${headerFiles.length} header files`);

    // Generate ffigen.yaml configuration
    console.log('Generating ffigen.yaml configuration...');
    const ffigenConfig = `# Run with \`dart run ffigen --config ffigen.yaml\`.
name: SpineFlutterBindings
description: |
  Bindings for Spine C headers.

  Regenerate bindings with \`dart run ffigen --config ffigen.yaml\`.
output: 'lib/generated/spine_flutter_bindings_generated.dart'
llvm-path:
    - '/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/'
headers:
  entry-points:
    - 'src/spine-c/include/spine-c.h'
    - 'src/spine-c/src/base.h'
    - 'src/spine-c/src/extensions.h'
${headerFiles.map(h => `    - '${h}'`).join('\n')}
  include-directives:
    - 'src/spine-c/include/spine-c.h'
    - 'src/spine-c/src/base.h'
    - 'src/spine-c/src/extensions.h'
${headerFiles.map(h => `    - '${h}'`).join('\n')}
compiler-opts:
  - '-Isrc/spine-c/include'
  - '-Isrc/spine-c/src'
  - '-Isrc/spine-c/src/generated'
  - '-xc'
  - '-std=c99'
functions:
  include:
    - 'spine_.*'
structs:
  include:
    - 'spine_.*'
enums:
  include:
    - 'spine_.*'
typedefs:
  include:
    - 'spine_.*'
preamble: |
  // ignore_for_file: always_specify_types, constant_identifier_names
  // ignore_for_file: camel_case_types
  // ignore_for_file: non_constant_identifier_names
comments:
  style: any
  length: full
`;

    const ffigenPath = path.join(__dirname, '../../ffigen.yaml');
    fs.writeFileSync(ffigenPath, ffigenConfig);

    // Run ffigen to generate bindings
    console.log('Running ffigen...');
    try {
        execSync('dart run ffigen --config ffigen.yaml', {
            cwd: path.join(__dirname, '../..'),
            stdio: 'inherit'
        });
    } catch (error) {
        console.error('Failed to run ffigen:', error);
        throw error;
    }

    // Check if bindings were generated successfully
    const bindingsPath = path.join(__dirname, '../../lib/generated/spine_flutter_bindings_generated.dart');
    if (!fs.existsSync(bindingsPath)) {
        throw new Error('Failed to generate bindings');
    }

    // Replace dart:ffi import with ffi_proxy.dart
    console.log('Replacing dart:ffi import with ffi_proxy.dart...');
    let content = fs.readFileSync(bindingsPath, 'utf8');
    content = content.replace("import 'dart:ffi' as ffi;", "import '../../ffi_proxy.dart' as ffi;");
    fs.writeFileSync(bindingsPath, content);

    // Clean up ffigen.yaml
    console.log('Cleaning up ffigen.yaml...');
    fs.unlinkSync(ffigenPath);

    console.log('✅ FFI bindings generated successfully!');
}

async function main() {
    console.log('Generating Spine Flutter bindings and wrappers...\n');

    try {
        // Step 1: Generate C intermediate representation using spine-c codegen
        console.log('Step 1: Generating C intermediate representation...');
        const { cTypes, cEnums, cArrayTypes } = await generate();
        console.log(`Generated ${cTypes.length} C types, ${cEnums.length} enums, and ${cArrayTypes.length} array types\n`);

        // Step 2: Write Dart wrapper classes
        console.log('Step 2: Writing Dart wrapper classes...');
        const outputDir = path.join(__dirname, '../../lib/generated');
        const dartWriter = new DartWriter(outputDir);
        await dartWriter.writeAll(cTypes, cEnums, cArrayTypes);
        console.log();

        // Step 3: Generate FFI bindings using ffigen
        console.log('Step 3: Generating FFI bindings...');
        const spineCDir = path.join(__dirname, '../../src/spine-c');
        await generateFFIBindings(spineCDir);

        console.log('\n✅ All code generation completed successfully!');
    } catch (error) {
        console.error('\n❌ Error:', error);
        process.exit(1);
    }
}

main();