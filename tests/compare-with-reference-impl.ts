#!/usr/bin/env npx tsx

import { execSync } from 'child_process';
import * as fs from 'fs';
import * as path from 'path';
import { promisify } from 'util';

const writeFile = promisify(fs.writeFile);
const mkdir = promisify(fs.mkdir);

// Parse command line arguments
const args = process.argv.slice(2);
if (args.length < 2) {
    console.error('Usage: compare-with-reference-impl.ts <skeleton-path> <atlas-path> [animation-name]');
    process.exit(1);
}

const [skeletonPath, atlasPath, animationName] = args;

// Get absolute paths
const absoluteSkeletonPath = path.resolve(skeletonPath);
const absoluteAtlasPath = path.resolve(atlasPath);

// Script paths
const scriptDir = path.dirname(new URL(import.meta.url).pathname);
const rootDir = path.dirname(scriptDir);
const outputDir = path.join(scriptDir, 'output');

interface RuntimeConfig {
    name: string;
    buildCheck: () => boolean;
    build: () => void;
    run: () => string;
}

// Runtime configurations
const runtimes: RuntimeConfig[] = [
    {
        name: 'java',
        buildCheck: () => {
            const classPath = path.join(rootDir, 'spine-libgdx/spine-libgdx-tests/build/classes/java/main/com/esotericsoftware/spine/DebugPrinter.class');
            return fs.existsSync(classPath);
        },
        build: () => {
            console.log('  Building Java runtime...');
            execSync('./gradlew :spine-libgdx-tests:build', {
                cwd: path.join(rootDir, 'spine-libgdx'),
                stdio: 'inherit'
            });
        },
        run: () => {
            const args = animationName 
                ? `${absoluteSkeletonPath} ${absoluteAtlasPath} ${animationName}`
                : `${absoluteSkeletonPath} ${absoluteAtlasPath}`;
            const output = execSync(
                `./gradlew -q :spine-libgdx-tests:runDebugPrinter -Pargs="${args}"`,
                {
                    cwd: path.join(rootDir, 'spine-libgdx'),
                    encoding: 'utf8'
                }
            );
            // Find the start of actual output and return everything from there
            const lines = output.split('\n');
            const startIndex = lines.findIndex(line => line === '=== SKELETON DATA ===');
            if (startIndex !== -1) {
                return lines.slice(startIndex).join('\n').trim();
            }
            // Fallback to full output if marker not found
            return output.trim();
        }
    },
    {
        name: 'cpp',
        buildCheck: () => {
            const execPath = path.join(rootDir, 'spine-cpp/build/debug-printer');
            return fs.existsSync(execPath);
        },
        build: () => {
            console.log('  Building C++ runtime...');
            execSync('./build.sh clean', {
                cwd: path.join(rootDir, 'spine-cpp/'),
                stdio: 'inherit'
            });
        },
        run: () => {
            return execSync(
                `./build/debug-printer "${absoluteSkeletonPath}" "${absoluteAtlasPath}" "${animationName}"`,
                {
                    cwd: path.join(rootDir, 'spine-cpp'),
                    encoding: 'utf8'
                }
            ).trim();
        }
    },
    {
        name: 'c',
        buildCheck: () => {
            const execPath = path.join(rootDir, 'spine-c/build/debug-printer');
            return fs.existsSync(execPath);
        },
        build: () => {
            console.log('  Building C runtime...');
            execSync('./build.sh', {
                cwd: path.join(rootDir, 'spine-c/'),
                stdio: 'inherit'
            });
        },
        run: () => {
            return execSync(
                `./build/debug-printer "${absoluteSkeletonPath}" "${absoluteAtlasPath}" "${animationName}"`,
                {
                    cwd: path.join(rootDir, 'spine-c'),
                    encoding: 'utf8'
                }
            ).trim();
        }
    },
    {
        name: 'ts',
        buildCheck: () => true, // No build needed
        build: () => {}, // No build needed
        run: () => {
            return execSync(
                `npx tsx tests/DebugPrinter.ts "${absoluteSkeletonPath}" "${absoluteAtlasPath}" "${animationName}"`,
                {
                    cwd: path.join(rootDir, 'spine-ts/spine-core'),
                    encoding: 'utf8'
                }
            ).trim();
        }
    }
];

async function main() {
    // Ensure output directory exists
    await mkdir(outputDir, { recursive: true });

    console.log('Comparing DebugPrinter outputs for:');
    console.log(`  Skeleton: ${absoluteSkeletonPath}`);
    console.log(`  Atlas: ${absoluteAtlasPath}`);
    console.log(`  Animation: ${animationName}`);
    console.log('');

    // Run all runtimes and collect outputs
    const outputs: Record<string, string> = {};

    for (const runtime of runtimes) {
        console.log(`Running ${runtime.name.toUpperCase()} DebugPrinter...`);

        try {
            // Build if needed
            if (!runtime.buildCheck()) {
                runtime.build();
            }

            // Run and capture output
            const output = runtime.run();
            outputs[runtime.name] = output;

            // Save output to file
            await writeFile(path.join(outputDir, `${runtime.name}.txt`), output);

            console.log('  Done.');
        } catch (error) {
            console.error(`  Error: ${error instanceof Error ? error.message : JSON.stringify(error)}`);
            outputs[runtime.name] = `Error: ${error instanceof Error ? error.message : JSON.stringify(error)}`;
        }
    }

    console.log('');
    console.log('Comparing outputs...');
    console.log('');

    // Compare outputs
    const reference = 'java';
    let allMatch = true;

    for (const runtime of runtimes) {
        if (runtime.name !== reference) {
            process.stdout.write(`Comparing ${reference} vs ${runtime.name}: `);

            if (outputs[reference] === outputs[runtime.name]) {
                console.log('✓ MATCH');
            } else {
                console.log('✗ DIFFER');
                allMatch = false;

                // Show first few differences
                const refLines = outputs[reference].split('\n');
                const runtimeLines = outputs[runtime.name].split('\n');
                const maxLines = Math.max(refLines.length, runtimeLines.length);
                let diffCount = 0;

                console.log('  First differences:');
                for (let i = 0; i < maxLines && diffCount < 5; i++) {
                    if (refLines[i] !== runtimeLines[i]) {
                        diffCount++;
                        console.log(`    Line ${i + 1}:`);
                        if (refLines[i] !== undefined) {
                            console.log(`      - ${refLines[i]}`);
                        }
                        if (runtimeLines[i] !== undefined) {
                            console.log(`      + ${runtimeLines[i]}`);
                        }
                    }
                }

                if (diffCount === 0 && refLines.length !== runtimeLines.length) {
                    console.log(`    Different number of lines: ${refLines.length} vs ${runtimeLines.length}`);
                }

                // Save outputs for manual diff
                console.log(`  Full outputs saved to: ${outputDir}/`);
            }
        }
    }

    console.log('');
    if (allMatch) {
        console.log('✓ All outputs match!');
        process.exit(0);
    } else {
        console.log(`✗ Outputs differ. Check the output files in ${outputDir}/`);
        process.exit(1);
    }
}

// Run main function
main().catch(error => {
    console.error('Error:', error);
    process.exit(1);
});