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
        output.push(`${indent}if (${expression} == null) {`);
        output.push(`${indent}    json.writeNull();`);
        output.push(`${indent}} else {`);
        output.push(`${indent}    json.writeArrayStart();`);
        output.push(`${indent}    for (${innerType} item : ${expression}) {`);
        generateWriteValue(output, 'item', innerType, indent + '        ', abstractTypes, classMap);
        output.push(`${indent}    }`);
        output.push(`${indent}    json.writeArrayEnd();`);
        output.push(`${indent}}`);
        return;
    }
    
    if (type === 'IntArray' || type === 'FloatArray') {
        output.push(`${indent}if (${expression} == null) {`);
        output.push(`${indent}    json.writeNull();`);
        output.push(`${indent}} else {`);
        output.push(`${indent}    json.writeArrayStart();`);
        output.push(`${indent}    for (int i = 0; i < ${expression}.size; i++) {`);
        output.push(`${indent}        json.writeValue(${expression}.get(i));`);
        output.push(`${indent}    }`);
        output.push(`${indent}    json.writeArrayEnd();`);
        output.push(`${indent}}`);
        return;
    }
    
    if (type.endsWith('[]')) {
        const elemType = type.slice(0, -2);
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
        return;
    }
    
    // Special cases for libGDX types
    if (type === 'Color') {
        output.push(`${indent}writeColor(json, ${expression});`);
        return;
    }
    
    if (type === 'TextureRegion') {
        output.push(`${indent}writeTextureRegion(json, ${expression});`);
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
        output.push(`${indent}    write${shortType}(json, ${expression});`);
        output.push(`${indent}}`);
    } else {
        output.push(`${indent}write${shortType}(json, ${expression});`);
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
    
    // Add all abstract types that are referenced
    for (const [abstractType] of abstractTypes) {
        typesNeedingMethods.add(abstractType);
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
            
            // Add the type if it's a class
            if (propType.match(/^[A-Z]/)) {
                typesNeedingMethods.add(propType);
                
                // Also check if it's an abstract type in classMap
                let found = false;
                for (const [fullName, info] of classMap) {
                    if (fullName === propType || fullName.split('.').pop() === propType) {
                        if (info.isAbstract || info.isInterface) {
                            typesNeedingMethods.add(fullName);
                        }
                        found = true;
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
    javaOutput.push('import java.io.Writer;');
    javaOutput.push('import java.io.IOException;');
    javaOutput.push('import java.util.Locale;');
    javaOutput.push('import java.util.Set;');
    javaOutput.push('import java.util.HashSet;');
    javaOutput.push('');
    javaOutput.push('public class SkeletonSerializer {');
    javaOutput.push('    private final Set<Object> visitedObjects = new HashSet<>();');
    javaOutput.push('');
    
    // Generate main entry methods
    javaOutput.push('    public void serializeSkeletonData(SkeletonData data, Writer writer) throws IOException {');
    javaOutput.push('        visitedObjects.clear();');
    javaOutput.push('        JsonWriter json = new JsonWriter(writer);');
    javaOutput.push('        writeSkeletonData(json, data);');
    javaOutput.push('        json.close();');
    javaOutput.push('    }');
    javaOutput.push('');
    javaOutput.push('    public void serializeSkeleton(Skeleton skeleton, Writer writer) throws IOException {');
    javaOutput.push('        visitedObjects.clear();');
    javaOutput.push('        JsonWriter json = new JsonWriter(writer);');
    javaOutput.push('        writeSkeleton(json, skeleton);');
    javaOutput.push('        json.close();');
    javaOutput.push('    }');
    javaOutput.push('');
    javaOutput.push('    public void serializeAnimationState(AnimationState state, Writer writer) throws IOException {');
    javaOutput.push('        visitedObjects.clear();');
    javaOutput.push('        JsonWriter json = new JsonWriter(writer);');
    javaOutput.push('        writeAnimationState(json, state);');
    javaOutput.push('        json.close();');
    javaOutput.push('    }');
    javaOutput.push('');
    
    // Generate write methods for all types
    const generatedMethods = new Set<string>();
    
    for (const typeName of Array.from(typesNeedingMethods).sort()) {
        const classInfo = classMap.get(typeName);
        if (!classInfo) continue;
        
        const shortName = typeName.split('.').pop()!;
        
        // Skip if already generated (handle name collisions)
        if (generatedMethods.has(shortName)) continue;
        generatedMethods.add(shortName);
        
        // Use full class name for inner classes
        const className = typeName.includes('.') ? typeName : shortName;
        
        javaOutput.push(`    private void write${shortName}(JsonWriter json, ${className} obj) throws IOException {`);
        
        if (classInfo.isEnum) {
            // Handle enums
            javaOutput.push('        json.writeValue(obj.name());');
        } else if (classInfo.isAbstract || classInfo.isInterface) {
            // Handle abstract types with instanceof chain
            const implementations = classInfo.concreteImplementations || [];
            if (implementations.length === 0) {
                javaOutput.push('        json.writeNull(); // No concrete implementations');
            } else {
                let first = true;
                for (const impl of implementations) {
                    const implShortName = impl.split('.').pop()!;
                    const implClassName = impl.includes('.') ? impl : implShortName;
                    
                    if (first) {
                        javaOutput.push(`        if (obj instanceof ${implClassName}) {`);
                        first = false;
                    } else {
                        javaOutput.push(`        } else if (obj instanceof ${implClassName}) {`);
                    }
                    javaOutput.push(`            write${implShortName}(json, (${implClassName}) obj);`);
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
            
            // Write properties
            for (const prop of properties) {
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
    javaOutput.push('    private void writeColor(JsonWriter json, Color color) throws IOException {');
    javaOutput.push('        if (color == null) {');
    javaOutput.push('            json.writeNull();');
    javaOutput.push('        } else {');
    javaOutput.push('            json.writeObjectStart();');
    javaOutput.push('            json.writeName("r");');
    javaOutput.push('            json.writeValue(color.r);');
    javaOutput.push('            json.writeName("g");');
    javaOutput.push('            json.writeValue(color.g);');
    javaOutput.push('            json.writeName("b");');
    javaOutput.push('            json.writeValue(color.b);');
    javaOutput.push('            json.writeName("a");');
    javaOutput.push('            json.writeValue(color.a);');
    javaOutput.push('            json.writeObjectEnd();');
    javaOutput.push('        }');
    javaOutput.push('    }');
    javaOutput.push('');
    
    javaOutput.push('    private void writeTextureRegion(JsonWriter json, TextureRegion region) throws IOException {');
    javaOutput.push('        if (region == null) {');
    javaOutput.push('            json.writeNull();');
    javaOutput.push('        } else {');
    javaOutput.push('            json.writeObjectStart();');
    javaOutput.push('            json.writeName("u");');
    javaOutput.push('            json.writeValue(region.getU());');
    javaOutput.push('            json.writeName("v");');
    javaOutput.push('            json.writeValue(region.getV());');
    javaOutput.push('            json.writeName("u2");');
    javaOutput.push('            json.writeValue(region.getU2());');
    javaOutput.push('            json.writeName("v2");');
    javaOutput.push('            json.writeValue(region.getV2());');
    javaOutput.push('            json.writeName("width");');
    javaOutput.push('            json.writeValue(region.getRegionWidth());');
    javaOutput.push('            json.writeName("height");');
    javaOutput.push('            json.writeValue(region.getRegionHeight());');
    javaOutput.push('            json.writeObjectEnd();');
    javaOutput.push('        }');
    javaOutput.push('    }');
    javaOutput.push('');
    
    // Add JsonWriter inner class
    javaOutput.push('    private static class JsonWriter {');
    javaOutput.push('        private final Writer writer;');
    javaOutput.push('        private int depth = 0;');
    javaOutput.push('        private boolean needsComma = false;');
    javaOutput.push('');
    javaOutput.push('        JsonWriter(Writer writer) {');
    javaOutput.push('            this.writer = writer;');
    javaOutput.push('        }');
    javaOutput.push('');
    javaOutput.push('        void writeObjectStart() throws IOException {');
    javaOutput.push('            writeCommaIfNeeded();');
    javaOutput.push('            writer.write("{");');
    javaOutput.push('            depth++;');
    javaOutput.push('            needsComma = false;');
    javaOutput.push('        }');
    javaOutput.push('');
    javaOutput.push('        void writeObjectEnd() throws IOException {');
    javaOutput.push('            depth--;');
    javaOutput.push('            if (needsComma) {');
    javaOutput.push('                writer.write("\\n");');
    javaOutput.push('                writeIndent();');
    javaOutput.push('            }');
    javaOutput.push('            writer.write("}");');
    javaOutput.push('            needsComma = true;');
    javaOutput.push('        }');
    javaOutput.push('');
    javaOutput.push('        void writeArrayStart() throws IOException {');
    javaOutput.push('            writeCommaIfNeeded();');
    javaOutput.push('            writer.write("[");');
    javaOutput.push('            depth++;');
    javaOutput.push('            needsComma = false;');
    javaOutput.push('        }');
    javaOutput.push('');
    javaOutput.push('        void writeArrayEnd() throws IOException {');
    javaOutput.push('            depth--;');
    javaOutput.push('            if (needsComma) {');
    javaOutput.push('                writer.write("\\n");');
    javaOutput.push('                writeIndent();');
    javaOutput.push('            }');
    javaOutput.push('            writer.write("]");');
    javaOutput.push('            needsComma = true;');
    javaOutput.push('        }');
    javaOutput.push('');
    javaOutput.push('        void writeName(String name) throws IOException {');
    javaOutput.push('            writeCommaIfNeeded();');
    javaOutput.push('            writer.write("\\n");');
    javaOutput.push('            writeIndent();');
    javaOutput.push('            writer.write("\\"" + name + "\\": ");');
    javaOutput.push('            needsComma = false;');
    javaOutput.push('        }');
    javaOutput.push('');
    javaOutput.push('        void writeValue(String value) throws IOException {');
    javaOutput.push('            writeCommaIfNeeded();');
    javaOutput.push('            if (value == null) {');
    javaOutput.push('                writer.write("null");');
    javaOutput.push('            } else {');
    javaOutput.push('                writer.write("\\"" + escapeString(value) + "\\"");');
    javaOutput.push('            }');
    javaOutput.push('            needsComma = true;');
    javaOutput.push('        }');
    javaOutput.push('');
    javaOutput.push('        void writeValue(float value) throws IOException {');
    javaOutput.push('            writeCommaIfNeeded();');
    javaOutput.push('            writer.write(String.format(Locale.US, "%.6f", value).replaceAll("0+$", "").replaceAll("\\\\.$", ""));');
    javaOutput.push('            needsComma = true;');
    javaOutput.push('        }');
    javaOutput.push('');
    javaOutput.push('        void writeValue(int value) throws IOException {');
    javaOutput.push('            writeCommaIfNeeded();');
    javaOutput.push('            writer.write(String.valueOf(value));');
    javaOutput.push('            needsComma = true;');
    javaOutput.push('        }');
    javaOutput.push('');
    javaOutput.push('        void writeValue(boolean value) throws IOException {');
    javaOutput.push('            writeCommaIfNeeded();');
    javaOutput.push('            writer.write(String.valueOf(value));');
    javaOutput.push('            needsComma = true;');
    javaOutput.push('        }');
    javaOutput.push('');
    javaOutput.push('        void writeNull() throws IOException {');
    javaOutput.push('            writeCommaIfNeeded();');
    javaOutput.push('            writer.write("null");');
    javaOutput.push('            needsComma = true;');
    javaOutput.push('        }');
    javaOutput.push('');
    javaOutput.push('        void close() throws IOException {');
    javaOutput.push('            writer.write("\\n");');
    javaOutput.push('            writer.flush();');
    javaOutput.push('        }');
    javaOutput.push('');
    javaOutput.push('        private void writeCommaIfNeeded() throws IOException {');
    javaOutput.push('            if (needsComma) {');
    javaOutput.push('                writer.write(",");');
    javaOutput.push('            }');
    javaOutput.push('        }');
    javaOutput.push('');
    javaOutput.push('        private void writeIndent() throws IOException {');
    javaOutput.push('            for (int i = 0; i < depth; i++) {');
    javaOutput.push('                writer.write("  ");');
    javaOutput.push('            }');
    javaOutput.push('        }');
    javaOutput.push('');
    javaOutput.push('        private String escapeString(String str) {');
    javaOutput.push('            return str.replace("\\\\", "\\\\\\\\")');
    javaOutput.push('                    .replace("\\"", "\\\\\\"")');
    javaOutput.push('                    .replace("\\b", "\\\\b")');
    javaOutput.push('                    .replace("\\f", "\\\\f")');
    javaOutput.push('                    .replace("\\n", "\\\\n")');
    javaOutput.push('                    .replace("\\r", "\\\\r")');
    javaOutput.push('                    .replace("\\t", "\\\\t");');
    javaOutput.push('        }');
    javaOutput.push('    }');
    javaOutput.push('}');
    
    return javaOutput.join('\n');
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
        
        // Generate Java serializer
        const javaCode = generateJavaSerializer(analysisData);
        
        // Write the Java file
        const javaFile = path.join(
            path.dirname(process.cwd()), 
            'spine-libgdx', 
            'spine-libgdx', 
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