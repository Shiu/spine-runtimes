#!/usr/bin/env tsx

import * as fs from 'fs';
import * as path from 'path';
import { fileURLToPath } from 'url';
import type { ClassInfo, PropertyInfo } from './types';

const __dirname = path.dirname(fileURLToPath(import.meta.url));

function loadExclusions(): { types: Set<string>, methods: Map<string, Set<string>>, fields: Map<string, Set<string>> } {
    const exclusionsPath = path.resolve(__dirname, 'java-exclusions.txt');
    const types = new Set<string>();
    const methods = new Map<string, Set<string>>();
    const fields = new Map<string, Set<string>>();
    
    if (!fs.existsSync(exclusionsPath)) {
        return { types, methods, fields };
    }
    
    const content = fs.readFileSync(exclusionsPath, 'utf-8');
    const lines = content.split('\n');
    
    for (const line of lines) {
        const trimmed = line.trim();
        if (!trimmed || trimmed.startsWith('#')) continue;
        
        const parts = trimmed.split(/\s+/);
        if (parts.length < 2) continue;
        
        const [type, className, property] = parts;
        
        switch (type) {
            case 'type':
                types.add(className);
                break;
            case 'method':
                if (property) {
                    if (!methods.has(className)) {
                        methods.set(className, new Set());
                    }
                    methods.get(className)!.add(property);
                }
                break;
            case 'field':
                if (property) {
                    if (!fields.has(className)) {
                        fields.set(className, new Set());
                    }
                    fields.get(className)!.add(property);
                }
                break;
        }
    }
    
    return { types, methods, fields };
}

interface SerializedAnalysisResult {
    classMap: [string, ClassInfo][];
    accessibleTypes: string[];
    abstractTypes: [string, string[]][];
    allTypesToGenerate: string[];
    typeProperties: [string, PropertyInfo[]][];
}

function generateWriteValue(output: string[], expression: string, type: string, indent: string, abstractTypes: Map<string, string[]>, classMap: Map<string, ClassInfo>) {
    // Handle null annotations
    const isNullable = type.includes('@Null');
    type = type.replace(/@Null\s+/g, '').trim();

    // Primitive types
    if (['String', 'int', 'float', 'boolean', 'short', 'byte', 'double', 'long'].includes(type)) {
        output.push(`${indent}json.writeValue(${expression});`);
        return;
    }

    // Check if it's an enum - need to handle both short and full names
    let classInfo = classMap.get(type);
    if (!classInfo && !type.includes('.')) {
        // Try to find by short name
        for (const [fullName, info] of classMap) {
            if (fullName.split('.').pop() === type) {
                classInfo = info;
                break;
            }
        }
    }

    if (classInfo?.isEnum) {
        if (isNullable) {
            output.push(`${indent}if (${expression} == null) {`);
            output.push(`${indent}    json.writeNull();`);
            output.push(`${indent}} else {`);
            output.push(`${indent}    json.writeValue(${expression}.name());`);
            output.push(`${indent}}`);
        } else {
            output.push(`${indent}json.writeValue(${expression}.name());`);
        }
        return;
    }

    // Arrays
    if (type.startsWith('Array<')) {
        const innerType = type.match(/Array<(.+?)>/)![1].trim();
        if (isNullable) {
            output.push(`${indent}if (${expression} == null) {`);
            output.push(`${indent}    json.writeNull();`);
            output.push(`${indent}} else {`);
            output.push(`${indent}    json.writeArrayStart();`);
            output.push(`${indent}    for (${innerType} item : ${expression}) {`);
            generateWriteValue(output, 'item', innerType, indent + '        ', abstractTypes, classMap);
            output.push(`${indent}    }`);
            output.push(`${indent}    json.writeArrayEnd();`);
            output.push(`${indent}}`);
        } else {
            output.push(`${indent}json.writeArrayStart();`);
            output.push(`${indent}for (${innerType} item : ${expression}) {`);
            generateWriteValue(output, 'item', innerType, indent + '    ', abstractTypes, classMap);
            output.push(`${indent}}`);
            output.push(`${indent}json.writeArrayEnd();`);
        }
        return;
    }

    if (type === 'IntArray' || type === 'FloatArray') {
        if (isNullable) {
            output.push(`${indent}if (${expression} == null) {`);
            output.push(`${indent}    json.writeNull();`);
            output.push(`${indent}} else {`);
            output.push(`${indent}    json.writeArrayStart();`);
            output.push(`${indent}    for (int i = 0; i < ${expression}.size; i++) {`);
            output.push(`${indent}        json.writeValue(${expression}.get(i));`);
            output.push(`${indent}    }`);
            output.push(`${indent}    json.writeArrayEnd();`);
            output.push(`${indent}}`);
        } else {
            output.push(`${indent}json.writeArrayStart();`);
            output.push(`${indent}for (int i = 0; i < ${expression}.size; i++) {`);
            output.push(`${indent}    json.writeValue(${expression}.get(i));`);
            output.push(`${indent}}`);
            output.push(`${indent}json.writeArrayEnd();`);
        }
        return;
    }

    if (type.endsWith('[]')) {
        const elemType = type.slice(0, -2);
        if (isNullable) {
            output.push(`${indent}if (${expression} == null) {`);
            output.push(`${indent}    json.writeNull();`);
            output.push(`${indent}} else {`);
            output.push(`${indent}    json.writeArrayStart();`);
            // Handle nested arrays (like float[][])
            if (elemType.endsWith('[]')) {
                const nestedType = elemType.slice(0, -2);
                output.push(`${indent}    for (${elemType} nestedArray : ${expression}) {`);
                output.push(`${indent}        if (nestedArray == null) {`);
                output.push(`${indent}            json.writeNull();`);
                output.push(`${indent}        } else {`);
                output.push(`${indent}            json.writeArrayStart();`);
                output.push(`${indent}            for (${nestedType} elem : nestedArray) {`);
                output.push(`${indent}                json.writeValue(elem);`);
                output.push(`${indent}            }`);
                output.push(`${indent}            json.writeArrayEnd();`);
                output.push(`${indent}        }`);
                output.push(`${indent}    }`);
            } else {
                output.push(`${indent}    for (${elemType} item : ${expression}) {`);
                generateWriteValue(output, 'item', elemType, indent + '        ', abstractTypes, classMap);
                output.push(`${indent}    }`);
            }
            output.push(`${indent}    json.writeArrayEnd();`);
            output.push(`${indent}}`);
        } else {
            output.push(`${indent}json.writeArrayStart();`);
            // Handle nested arrays (like float[][])
            if (elemType.endsWith('[]')) {
                const nestedType = elemType.slice(0, -2);
                output.push(`${indent}for (${elemType} nestedArray : ${expression}) {`);
                output.push(`${indent}    json.writeArrayStart();`);
                output.push(`${indent}    for (${nestedType} elem : nestedArray) {`);
                output.push(`${indent}        json.writeValue(elem);`);
                output.push(`${indent}    }`);
                output.push(`${indent}    json.writeArrayEnd();`);
                output.push(`${indent}}`);
            } else {
                output.push(`${indent}for (${elemType} item : ${expression}) {`);
                generateWriteValue(output, 'item', elemType, indent + '    ', abstractTypes, classMap);
                output.push(`${indent}}`);
            }
            output.push(`${indent}json.writeArrayEnd();`);
        }
        return;
    }

    // Special cases for libGDX types
    if (type === 'Color') {
        output.push(`${indent}writeColor(${expression});`);
        return;
    }

    if (type === 'TextureRegion') {
        output.push(`${indent}writeTextureRegion(${expression});`);
        return;
    }

    // Handle objects
    const shortType = type.split('.').pop()!;

    // Check if this type exists in classMap (for abstract types that might not be in generated methods)
    let foundInClassMap = classMap.has(type);
    if (!foundInClassMap && !type.includes('.')) {
        // Try to find by short name
        for (const [fullName, info] of classMap) {
            if (fullName.split('.').pop() === type) {
                foundInClassMap = true;
                // If it's abstract/interface, we need the instanceof chain
                if (info.isAbstract || info.isInterface) {
                    type = fullName; // Use full name for abstract types
                }
                break;
            }
        }
    }

    if (isNullable) {
        output.push(`${indent}if (${expression} == null) {`);
        output.push(`${indent}    json.writeNull();`);
        output.push(`${indent}} else {`);
        output.push(`${indent}    write${shortType}(${expression});`);
        output.push(`${indent}}`);
    } else {
        output.push(`${indent}write${shortType}(${expression});`);
    }
}

function generateJavaSerializer(analysisData: SerializedAnalysisResult): string {
    const javaOutput: string[] = [];

    // Convert arrays back to Maps
    const classMap = new Map(analysisData.classMap);
    const abstractTypes = new Map(analysisData.abstractTypes);
    const typeProperties = new Map(analysisData.typeProperties);

    // Collect all types that need write methods
    const typesNeedingMethods = new Set<string>();

    // Add all types from allTypesToGenerate
    for (const type of analysisData.allTypesToGenerate) {
        typesNeedingMethods.add(type);
    }

    // Add all abstract types that are referenced (but not excluded)
    const exclusions = loadExclusions();
    for (const [abstractType] of abstractTypes) {
        if (!exclusions.types.has(abstractType)) {
            typesNeedingMethods.add(abstractType);
        }
    }

    // Add types referenced in properties
    for (const [typeName, props] of typeProperties) {
        if (!typesNeedingMethods.has(typeName)) continue;

        for (const prop of props) {
            let propType = prop.type.replace(/@Null\s+/g, '').trim();

            // Extract type from Array<Type>
            const arrayMatch = propType.match(/Array<(.+?)>/);
            if (arrayMatch) {
                propType = arrayMatch[1].trim();
            }

            // Extract type from Type[]
            if (propType.endsWith('[]')) {
                propType = propType.slice(0, -2);
            }

            // Skip primitives and special types
            if (['String', 'int', 'float', 'boolean', 'short', 'byte', 'double', 'long',
                 'Color', 'TextureRegion', 'IntArray', 'FloatArray'].includes(propType)) {
                continue;
            }

            // Add the type if it's a class (but not excluded)
            if (propType.match(/^[A-Z]/)) {
                if (!exclusions.types.has(propType)) {
                    typesNeedingMethods.add(propType);
                }

                // Also check if it's an abstract type in classMap
                for (const [fullName, info] of classMap) {
                    if (fullName === propType || fullName.split('.').pop() === propType) {
                        if (info.isAbstract || info.isInterface && !exclusions.types.has(fullName)) {
                            typesNeedingMethods.add(fullName);
                        }
                        break;
                    }
                }
            }
        }
    }

    // Generate Java file header
    javaOutput.push('package com.esotericsoftware.spine.utils;');
    javaOutput.push('');
    javaOutput.push('import com.esotericsoftware.spine.*;');
    javaOutput.push('import com.esotericsoftware.spine.Animation.*;');
    javaOutput.push('import com.esotericsoftware.spine.AnimationState.*;');
    javaOutput.push('import com.esotericsoftware.spine.BoneData.Inherit;');
    javaOutput.push('import com.esotericsoftware.spine.Skin.SkinEntry;');
    javaOutput.push('import com.esotericsoftware.spine.PathConstraintData.*;');
    javaOutput.push('import com.esotericsoftware.spine.TransformConstraintData.*;');
    javaOutput.push('import com.esotericsoftware.spine.attachments.*;');
    javaOutput.push('import com.badlogic.gdx.graphics.Color;');
    javaOutput.push('import com.badlogic.gdx.graphics.g2d.TextureRegion;');
    javaOutput.push('import com.badlogic.gdx.utils.Array;');
    javaOutput.push('import com.badlogic.gdx.utils.IntArray;');
    javaOutput.push('import com.badlogic.gdx.utils.FloatArray;');
    javaOutput.push('');

    javaOutput.push('import java.util.Locale;');
    javaOutput.push('import java.util.Set;');
    javaOutput.push('import java.util.HashSet;');
    javaOutput.push('');
    javaOutput.push('public class SkeletonSerializer {');
    javaOutput.push('    private final Set<Object> visitedObjects = new HashSet<>();');
    javaOutput.push('    private JsonWriter json;');
    javaOutput.push('');

    // Generate main entry methods
    javaOutput.push('    public String serializeSkeletonData(SkeletonData data) {');
    javaOutput.push('        visitedObjects.clear();');
    javaOutput.push('        json = new JsonWriter();');
    javaOutput.push('        writeSkeletonData(data);');
    javaOutput.push('        json.close();');
    javaOutput.push('        return json.getString();');
    javaOutput.push('    }');
    javaOutput.push('');
    javaOutput.push('    public String serializeSkeleton(Skeleton skeleton) {');
    javaOutput.push('        visitedObjects.clear();');
    javaOutput.push('        json = new JsonWriter();');
    javaOutput.push('        writeSkeleton(skeleton);');
    javaOutput.push('        json.close();');
    javaOutput.push('        return json.getString();');
    javaOutput.push('    }');
    javaOutput.push('');
    javaOutput.push('    public String serializeAnimationState(AnimationState state) {');
    javaOutput.push('        visitedObjects.clear();');
    javaOutput.push('        json = new JsonWriter();');
    javaOutput.push('        writeAnimationState(state);');
    javaOutput.push('        json.close();');
    javaOutput.push('        return json.getString();');
    javaOutput.push('    }');
    javaOutput.push('');

    // Generate write methods for all types
    const generatedMethods = new Set<string>();

    for (const typeName of Array.from(typesNeedingMethods).sort()) {
        const classInfo = classMap.get(typeName);
        if (!classInfo) continue;
        
        // Skip enums - they are handled inline with .name() calls
        if (classInfo.isEnum) continue;

        const shortName = typeName.split('.').pop()!;

        // Skip if already generated (handle name collisions)
        if (generatedMethods.has(shortName)) continue;
        generatedMethods.add(shortName);

        // Use full class name for inner classes
        const className = typeName.includes('.') ? typeName : shortName;

        javaOutput.push(`    private void write${shortName}(${className} obj) {`);

        if (classInfo.isEnum) {
            // Handle enums
            javaOutput.push('        json.writeValue(obj.name());');
        } else if (classInfo.isAbstract || classInfo.isInterface) {
            // Handle abstract types with instanceof chain
            const implementations = classInfo.concreteImplementations || [];
            
            // Filter out excluded types from implementations
            const exclusions = loadExclusions();
            const filteredImplementations = implementations.filter(impl => {
                return !exclusions.types.has(impl);
            });
            
            if (filteredImplementations.length === 0) {
                javaOutput.push('        json.writeNull(); // No concrete implementations after filtering exclusions');
            } else {
                let first = true;
                for (const impl of filteredImplementations) {
                    const implShortName = impl.split('.').pop()!;
                    const implClassName = impl.includes('.') ? impl : implShortName;

                    if (first) {
                        javaOutput.push(`        if (obj instanceof ${implClassName}) {`);
                        first = false;
                    } else {
                        javaOutput.push(`        } else if (obj instanceof ${implClassName}) {`);
                    }
                    javaOutput.push(`            write${implShortName}((${implClassName}) obj);`);
                }
                javaOutput.push('        } else {');
                javaOutput.push(`            throw new RuntimeException("Unknown ${shortName} type: " + obj.getClass().getName());`);
                javaOutput.push('        }');
            }
        } else {
            // Handle concrete types
            const properties = typeProperties.get(typeName) || [];

            // Add cycle detection
            javaOutput.push('        if (visitedObjects.contains(obj)) {');
            javaOutput.push('            json.writeValue("<circular>");');
            javaOutput.push('            return;');
            javaOutput.push('        }');
            javaOutput.push('        visitedObjects.add(obj);');
            javaOutput.push('');

            javaOutput.push('        json.writeObjectStart();');

            // Write type field
            javaOutput.push('        json.writeName("type");');
            javaOutput.push(`        json.writeValue("${shortName}");`);

            // Write properties (skip excluded ones)
            for (const prop of properties) {
                if (prop.excluded) {
                    javaOutput.push(`        // Skipping excluded property: ${prop.name}`);
                    continue;
                }
                
                const propName = prop.isGetter ?
                    prop.name.replace('get', '').replace('()', '').charAt(0).toLowerCase() +
                    prop.name.replace('get', '').replace('()', '').slice(1) :
                    prop.name;

                javaOutput.push('');
                javaOutput.push(`        json.writeName("${propName}");`);
                const accessor = prop.isGetter ? `obj.${prop.name}` : `obj.${prop.name}`;
                generateWriteValue(javaOutput, accessor, prop.type, '        ', abstractTypes, classMap);
            }

            javaOutput.push('');
            javaOutput.push('        json.writeObjectEnd();');
        }

        javaOutput.push('    }');
        javaOutput.push('');
    }

    // Add helper methods
    javaOutput.push('    private void writeColor(Color obj) {');
    javaOutput.push('        if (obj == null) {');
    javaOutput.push('            json.writeNull();');
    javaOutput.push('        } else {');
    javaOutput.push('            json.writeObjectStart();');
    javaOutput.push('            json.writeName("r");');
    javaOutput.push('            json.writeValue(obj.r);');
    javaOutput.push('            json.writeName("g");');
    javaOutput.push('            json.writeValue(obj.g);');
    javaOutput.push('            json.writeName("b");');
    javaOutput.push('            json.writeValue(obj.b);');
    javaOutput.push('            json.writeName("a");');
    javaOutput.push('            json.writeValue(obj.a);');
    javaOutput.push('            json.writeObjectEnd();');
    javaOutput.push('        }');
    javaOutput.push('    }');
    javaOutput.push('');

    javaOutput.push('    private void writeTextureRegion(TextureRegion obj) {');
    javaOutput.push('        if (obj == null) {');
    javaOutput.push('            json.writeNull();');
    javaOutput.push('        } else {');
    javaOutput.push('            json.writeObjectStart();');
    javaOutput.push('            json.writeName("u");');
    javaOutput.push('            json.writeValue(obj.getU());');
    javaOutput.push('            json.writeName("v");');
    javaOutput.push('            json.writeValue(obj.getV());');
    javaOutput.push('            json.writeName("u2");');
    javaOutput.push('            json.writeValue(obj.getU2());');
    javaOutput.push('            json.writeName("v2");');
    javaOutput.push('            json.writeValue(obj.getV2());');
    javaOutput.push('            json.writeName("width");');
    javaOutput.push('            json.writeValue(obj.getRegionWidth());');
    javaOutput.push('            json.writeName("height");');
    javaOutput.push('            json.writeValue(obj.getRegionHeight());');
    javaOutput.push('            json.writeObjectEnd();');
    javaOutput.push('        }');
    javaOutput.push('    }');
    javaOutput.push('}');

    return javaOutput.join('\n');
}

async function main() {
    try {
        // Read analysis result
        const analysisFile = path.resolve(__dirname, '..', 'output', 'analysis-result.json');
        if (!fs.existsSync(analysisFile)) {
            console.error('Analysis result not found. Run analyze-java-api.ts first.');
            process.exit(1);
        }

        const analysisData: SerializedAnalysisResult = JSON.parse(fs.readFileSync(analysisFile, 'utf8'));

        // Generate Java serializer
        const javaCode = generateJavaSerializer(analysisData);

        // Write the Java file
        const javaFile = path.resolve(
            __dirname,
            '..',
            'spine-libgdx',
            'spine-libgdx-tests',
            'src',
            'com',
            'esotericsoftware',
            'spine',
            'utils',
            'SkeletonSerializer.java'
        );

        fs.mkdirSync(path.dirname(javaFile), { recursive: true });
        fs.writeFileSync(javaFile, javaCode);

        console.log(`Generated Java serializer: ${javaFile}`);

    } catch (error: any) {
        console.error('Error:', error.message);
        process.exit(1);
    }
}

// Allow running as a script or importing the function
if (import.meta.url === `file://${process.argv[1]}`) {
    main();
}

export { generateJavaSerializer };