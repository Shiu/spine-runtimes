#!/usr/bin/env tsx

import * as fs from 'fs';
import * as path from 'path';
import type { ClassInfo, PropertyInfo } from './types';

interface SerializedAnalysisResult {
    classMap: [string, ClassInfo][];
    accessibleTypes: string[];
    abstractTypes: [string, string[]][];
    allTypesToGenerate: string[];
    typeProperties: [string, PropertyInfo[]][];
}

function generateClaudePrompt(analysisData: SerializedAnalysisResult): string {
    const output: string[] = [];
    
    // Convert arrays back to Maps
    const classMap = new Map(analysisData.classMap);
    const abstractTypes = new Map(analysisData.abstractTypes);
    const typeProperties = new Map(analysisData.typeProperties);
    
    output.push('# Spine Java Serialization Methods to Generate');
    output.push('');
    output.push('You need to generate writeXXX() methods for the SkeletonSerializer class.');
    output.push('Each method should serialize all properties accessible via getter methods.');
    output.push('');
    output.push('## Task: Port the Java SkeletonSerializer to Other Runtimes');
    output.push('');
    output.push('A complete Java SkeletonSerializer has been generated at:');
    output.push('`spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/utils/SkeletonSerializer.java`');
    output.push('');
    output.push('Port this serializer to:');
    output.push('- **C++**: Create `SkeletonSerializer.h/cpp` in `spine-cpp/src/spine/`');
    output.push('- **C**: Create `spine_skeleton_serializer.h/c` in `spine-c/src/spine/`');
    output.push('- **TypeScript**: Create `SkeletonSerializer.ts` in `spine-ts/spine-core/src/`');
    output.push('');
    output.push('## Important Porting Notes');
    output.push('');
    output.push('1. **Language Differences**:');
    output.push('   - Java uses getter methods (`getName()`), TypeScript may use properties (`.name`)');  
    output.push('   - C uses function calls (`spBoneData_getName()`)');
    output.push('   - Adapt to each language\'s idioms');
    output.push('2. **Type Checking**:');
    output.push('   - Java uses `instanceof`');
    output.push('   - C++ uses custom RTTI (`object->getRTTI().instanceOf()`)');
    output.push('   - C uses type fields or function pointers');
    output.push('   - TypeScript uses `instanceof`');
    output.push('3. **Collections**:');
    output.push('   - Java uses `Array<T>`, `IntArray`, `FloatArray`');
    output.push('   - C++ uses `Vector<T>`');
    output.push('   - C uses arrays with size fields');
    output.push('   - TypeScript uses arrays `T[]`');
    output.push('');
    output.push('## Types Reference');
    output.push('');
    
    // First emit abstract types that need instanceof delegation
    for (const [className, classInfo] of classMap) {
        if ((classInfo.isAbstract || classInfo.isInterface) && classInfo.concreteImplementations && classInfo.concreteImplementations.length > 0) {
            output.push(`### ${className} (${classInfo.isInterface ? 'interface' : 'abstract'})`);
            if (classInfo.superTypes.length > 0) {
                output.push(`Extends: ${classInfo.superTypes.join(', ')}`);
            }
            output.push('');
            output.push('This is an abstract class. Generate a write' + className.split('.').pop() + '() method that checks instanceof for these concrete implementations:');
            for (const impl of classInfo.concreteImplementations.sort()) {
                output.push(`- ${impl}`);
            }
            output.push('');
            output.push('Example implementation:');
            output.push('```java');
            output.push(`private void write${className.split('.').pop()}(JsonWriter json, ${className.split('.').pop()} obj) throws IOException {`);
            const first = classInfo.concreteImplementations[0];
            if (first) {
                const shortName = first.split('.').pop()!;
                output.push(`    if (obj instanceof ${shortName}) {`);
                output.push(`        write${shortName}(json, (${shortName}) obj);`);
                output.push('    } // ... etc for all concrete types');
                output.push('    else {');
                output.push(`        throw new RuntimeException("Unknown ${className.split('.').pop()} type: " + obj.getClass().getName());`);
                output.push('    }');
            }
            output.push('}');
            output.push('```');
            output.push('');
        }
    }
    
    // Then emit concrete types
    const sortedTypes = Array.from(analysisData.allTypesToGenerate).sort();
    
    for (const typeName of sortedTypes) {
        const classInfo = classMap.get(typeName)!;
        
        output.push(`### ${typeName}`);
        if (classInfo && classInfo.superTypes.length > 0) {
            output.push(`Extends: ${classInfo.superTypes.join(', ')}`);
        }
        output.push('');
        
        const properties = typeProperties.get(typeName) || [];
        const getters = properties.filter(p => p.isGetter);
        const fields = properties.filter(p => !p.isGetter);
        
        if (getters.length > 0 || fields.length > 0) {
            if (fields.length > 0) {
                output.push('Public fields:');
                output.push('```java');
                for (const field of fields) {
                    output.push(`${field.name} // ${field.type}`);
                }
                output.push('```');
                output.push('');
            }
            
            if (getters.length > 0) {
                output.push('Getters to serialize:');
                output.push('```java');
                for (const getter of getters) {
                    output.push(`${getter.name} // returns ${getter.type}`);
                }
                output.push('```');
            }
        } else {
            output.push('*No properties found*');
        }
        output.push('');
    }
    
    return output.join('\n');
}

async function main() {
    try {
        // Read analysis result
        const analysisFile = path.join(process.cwd(), 'output', 'analysis-result.json');
        if (!fs.existsSync(analysisFile)) {
            console.error('Analysis result not found. Run analyze-java-api.ts first.');
            process.exit(1);
        }
        
        const analysisData: SerializedAnalysisResult = JSON.parse(fs.readFileSync(analysisFile, 'utf8'));
        
        // Generate Claude prompt
        const prompt = generateClaudePrompt(analysisData);
        
        // Write the prompt file
        const outputFile = path.join(process.cwd(), 'output', 'port-serializer-to-other-runtimes.md');
        fs.writeFileSync(outputFile, prompt);
        
        console.log(`Claude prompt written to: ${outputFile}`);
        
    } catch (error: any) {
        console.error('Error:', error.message);
        process.exit(1);
    }
}

// Allow running as a script or importing the function
if (import.meta.url === `file://${process.argv[1]}`) {
    main();
}

export { generateClaudePrompt };