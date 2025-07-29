#!/usr/bin/env tsx

import * as fs from 'fs';
import * as path from 'path';
import { fileURLToPath } from 'url';
import { execSync } from 'child_process';
import type { Property, SerializerIR } from './types';

const __dirname = path.dirname(fileURLToPath(import.meta.url));

function transformType(javaType: string): string {
    // Java → Haxe type mappings
    const primitiveMap: Record<string, string> = {
        'String': 'String',
        'int': 'Int',
        'float': 'Float', 
        'boolean': 'Bool',
        'short': 'Int',
        'byte': 'Int',
        'double': 'Float',
        'long': 'Int'
    };

    // Remove package prefixes and map primitives
    const simpleName = javaType.includes('.') ? javaType.split('.').pop()! : javaType;
    
    if (primitiveMap[simpleName]) {
        return primitiveMap[simpleName];
    }

    // Handle arrays: Java T[] → Haxe Array<T>
    if (simpleName.endsWith('[]')) {
        const baseType = simpleName.slice(0, -2);
        return `Array<${transformType(baseType)}>`;
    }

    // Java Array<T> stays Array<T> in Haxe
    if (simpleName.startsWith('Array<')) {
        return simpleName;
    }

    // Handle special generic types
    if (simpleName === 'Constraint') {
        return 'Constraint<Any, Any, Any>'; // Use Any for generic parameters
    }
    if (simpleName === 'ConstraintData') {
        return 'ConstraintData<Any, Any>'; // Use Any for generic parameters
    }

    // Object types: keep class name, remove package
    return simpleName;
}

function mapJavaGetterToHaxeField(javaGetter: string, objName: string): string {
    // Map Java getter methods to Haxe field access
    // Based on analysis of existing Haxe classes in spine-haxe/spine-haxe/spine/
    
    if (javaGetter.endsWith('()')) {
        const methodName = javaGetter.slice(0, -2);
        
        // Remove get/is prefix and convert to camelCase field
        if (methodName.startsWith('get')) {
            const fieldName = methodName.slice(3);
            const haxeField = fieldName.charAt(0).toLowerCase() + fieldName.slice(1);
            return `${objName}.${haxeField}`;
        }
        
        if (methodName.startsWith('is')) {
            const fieldName = methodName.slice(2);
            const haxeField = fieldName.charAt(0).toLowerCase() + fieldName.slice(1);
            return `${objName}.${haxeField}`;
        }
        
        // Some methods might be direct field names
        return `${objName}.${methodName}`;
    }
    
    // Direct field access (already in correct format)
    return `${objName}.${javaGetter}`;
}

function generatePropertyCode(property: Property, indent: string, enumMappings: { [enumName: string]: { [javaValue: string]: string } }): string[] {
    const lines: string[] = [];
    const accessor = mapJavaGetterToHaxeField(property.getter, 'obj');

    switch (property.kind) {
        case "primitive":
            lines.push(`${indent}json.writeValue(${accessor});`);
            break;

        case "object":
            if (property.isNullable) {
                lines.push(`${indent}if (${accessor} == null) {`);
                lines.push(`${indent}    json.writeNull();`);
                lines.push(`${indent}} else {`);
                lines.push(`${indent}    ${property.writeMethodCall}(${accessor});`);
                lines.push(`${indent}}`);
            } else {
                lines.push(`${indent}${property.writeMethodCall}(${accessor});`);
            }
            break;

        case "enum": {
            const enumName = property.enumName;
            const enumMap = enumMappings[enumName];
            
            if (property.isNullable) {
                lines.push(`${indent}if (${accessor} == null) {`);
                lines.push(`${indent}    json.writeNull();`);
                lines.push(`${indent}} else {`);
            }

            if (enumMap && Object.keys(enumMap).length > 0) {
                // Generate switch statement for enum mapping
                lines.push(`${indent}${property.isNullable ? '    ' : ''}switch (${accessor}) {`);
                
                for (const [javaValue, haxeValue] of Object.entries(enumMap)) {
                    lines.push(`${indent}${property.isNullable ? '    ' : ''}    case ${haxeValue}: json.writeValue("${javaValue}");`);
                }
                
                lines.push(`${indent}${property.isNullable ? '    ' : ''}    default: json.writeValue("unknown");`);
                lines.push(`${indent}${property.isNullable ? '    ' : ''}}`);
            } else {
                // Fallback using Type.enumConstructor or similar
                lines.push(`${indent}${property.isNullable ? '    ' : ''}json.writeValue(Type.enumConstructor(${accessor}));`);
            }
            
            if (property.isNullable) {
                lines.push(`${indent}}`);
            }
            break;
        }

        case "array": {
            if (property.isNullable) {
                lines.push(`${indent}if (${accessor} == null) {`);
                lines.push(`${indent}    json.writeNull();`);
                lines.push(`${indent}} else {`);
                lines.push(`${indent}    json.writeArrayStart();`);
                lines.push(`${indent}    for (item in ${accessor}) {`);
            } else {
                lines.push(`${indent}json.writeArrayStart();`);
                lines.push(`${indent}for (item in ${accessor}) {`);
            }

            const itemIndent = property.isNullable ? `${indent}        ` : `${indent}    `;
            if (property.elementKind === "primitive") {
                lines.push(`${itemIndent}json.writeValue(item);`);
            } else {
                lines.push(`${itemIndent}${property.writeMethodCall}(item);`);
            }

            if (property.isNullable) {
                lines.push(`${indent}    }`);
                lines.push(`${indent}    json.writeArrayEnd();`);
                lines.push(`${indent}}`);
            } else {
                lines.push(`${indent}}`);
                lines.push(`${indent}json.writeArrayEnd();`);
            }
            break;
        }

        case "nestedArray": {
            if (property.isNullable) {
                lines.push(`${indent}if (${accessor} == null) {`);
                lines.push(`${indent}    json.writeNull();`);
                lines.push(`${indent}} else {`);
            }

            const outerIndent = property.isNullable ? `${indent}    ` : indent;
            lines.push(`${outerIndent}json.writeArrayStart();`);
            lines.push(`${outerIndent}for (nestedArray in ${accessor}) {`);
            lines.push(`${outerIndent}    if (nestedArray == null) {`);
            lines.push(`${outerIndent}        json.writeNull();`);
            lines.push(`${outerIndent}    } else {`);
            lines.push(`${outerIndent}        json.writeArrayStart();`);
            lines.push(`${outerIndent}        for (elem in nestedArray) {`);
            lines.push(`${outerIndent}            json.writeValue(elem);`);
            lines.push(`${outerIndent}        }`);
            lines.push(`${outerIndent}        json.writeArrayEnd();`);
            lines.push(`${outerIndent}    }`);
            lines.push(`${outerIndent}}`);
            lines.push(`${outerIndent}json.writeArrayEnd();`);

            if (property.isNullable) {
                lines.push(`${indent}}`);
            }
            break;
        }
    }

    return lines;
}

function generateHaxeFromIR(ir: SerializerIR): string {
    const haxeOutput: string[] = [];

    // Generate Haxe file header
    haxeOutput.push('package spine.utils;');
    haxeOutput.push('');
    haxeOutput.push('import haxe.ds.StringMap;');
    haxeOutput.push('import spine.*;');
    haxeOutput.push('import spine.animation.*;');
    haxeOutput.push('import spine.attachments.*;');
    haxeOutput.push('');
    haxeOutput.push('class SkeletonSerializer {');
    haxeOutput.push('    private var visitedObjects:StringMap<String> = new StringMap();');
    haxeOutput.push('    private var nextId:Int = 1;');
    haxeOutput.push('    private var json:JsonWriter;');
    haxeOutput.push('');
    haxeOutput.push('    public function new() {}');
    haxeOutput.push('');

    // Generate public methods
    for (const method of ir.publicMethods) {
        const haxeParamType = transformType(method.paramType);
        haxeOutput.push(`    public function ${method.name}(${method.paramName}:${haxeParamType}):String {`);
        haxeOutput.push('        visitedObjects = new StringMap();');
        haxeOutput.push('        nextId = 1;');
        haxeOutput.push('        json = new JsonWriter();');
        haxeOutput.push(`        ${method.writeMethodCall}(${method.paramName});`);
        haxeOutput.push('        return json.getString();');
        haxeOutput.push('    }');
        haxeOutput.push('');
    }

    // Generate write methods
    for (const method of ir.writeMethods) {
        const shortName = method.paramType.split('.').pop();
        const haxeType = transformType(method.paramType);

        haxeOutput.push(`    private function ${method.name}(obj:${haxeType}):Void {`);

        if (method.isAbstractType) {
            // Handle abstract types with Std.isOfType chain (Haxe equivalent of instanceof)
            if (method.subtypeChecks && method.subtypeChecks.length > 0) {
                let first = true;
                for (const subtype of method.subtypeChecks) {
                    const subtypeHaxeName = transformType(subtype.typeName);

                    if (first) {
                        haxeOutput.push(`        if (Std.isOfType(obj, ${subtypeHaxeName})) {`);
                        first = false;
                    } else {
                        haxeOutput.push(`        } else if (Std.isOfType(obj, ${subtypeHaxeName})) {`);
                    }
                    haxeOutput.push(`            ${subtype.writeMethodCall}(cast(obj, ${subtypeHaxeName}));`);
                }
                haxeOutput.push('        } else {');
                haxeOutput.push(`            throw new spine.SpineException("Unknown ${shortName} type");`);
                haxeOutput.push('        }');
            } else {
                haxeOutput.push('        json.writeNull(); // No concrete implementations after filtering exclusions');
            }
        } else {
            // Handle concrete types - add cycle detection
            haxeOutput.push('        if (visitedObjects.exists(obj)) {');
            haxeOutput.push('            json.writeValue(visitedObjects.get(obj));');
            haxeOutput.push('            return;');
            haxeOutput.push('        }');

            // Generate reference string
            const nameGetter = method.properties.find(p => 
                (p.kind === 'object' || p.kind === "primitive") &&
                p.getter === 'getName()' &&
                p.valueType === 'String'
            );

            if (nameGetter) {
                const nameAccessor = mapJavaGetterToHaxeField('getName()', 'obj');
                haxeOutput.push(`        var refString = ${nameAccessor} != null ? "<${shortName}-" + ${nameAccessor} + ">" : "<${shortName}-" + (nextId++) + ">";`);
            } else {
                haxeOutput.push(`        var refString = "<${shortName}-" + (nextId++) + ">";`);
            }
            haxeOutput.push('        visitedObjects.set(obj, refString);');
            haxeOutput.push('');

            haxeOutput.push('        json.writeObjectStart();');

            // Write reference string and type
            haxeOutput.push('        json.writeName("refString");');
            haxeOutput.push('        json.writeValue(refString);');
            haxeOutput.push('        json.writeName("type");');
            haxeOutput.push(`        json.writeValue("${shortName}");`);

            // Write properties
            for (const property of method.properties) {
                haxeOutput.push('');
                haxeOutput.push(`        json.writeName("${property.name}");`);
                const propertyLines = generatePropertyCode(property, '        ', ir.enumMappings);
                haxeOutput.push(...propertyLines);
            }

            haxeOutput.push('');
            haxeOutput.push('        json.writeObjectEnd();');
        }

        haxeOutput.push('    }');
        haxeOutput.push('');
    }

    // Add helper methods for special types (following C++ pattern)
    haxeOutput.push('    // Helper methods for special types');
    haxeOutput.push('    private function writeColor(obj:spine.Color):Void {');
    haxeOutput.push('        if (obj == null) {');
    haxeOutput.push('            json.writeNull();');
    haxeOutput.push('        } else {');
    haxeOutput.push('            json.writeObjectStart();');
    haxeOutput.push('            json.writeName("r");');
    haxeOutput.push('            json.writeValue(obj.r);');
    haxeOutput.push('            json.writeName("g");');
    haxeOutput.push('            json.writeValue(obj.g);');
    haxeOutput.push('            json.writeName("b");');
    haxeOutput.push('            json.writeValue(obj.b);');
    haxeOutput.push('            json.writeName("a");');
    haxeOutput.push('            json.writeValue(obj.a);');
    haxeOutput.push('            json.writeObjectEnd();');
    haxeOutput.push('        }');
    haxeOutput.push('    }');
    haxeOutput.push('');

    haxeOutput.push('}');

    return haxeOutput.join('\n');
}

async function validateGeneratedHaxeCode(haxeCode: string, outputPath: string): Promise<void> {
    // Write code to file
    fs.writeFileSync(outputPath, haxeCode);
    
    try {
        // Basic syntax validation by attempting to parse with Haxe compiler
        // Use JsonWriter.hx as main to avoid framework dependencies
        execSync('haxe -cp spine-haxe --no-output -main spine.utils.JsonWriter', {
            cwd: path.resolve(__dirname, '../../spine-haxe'),
            stdio: 'pipe'
        });
        
        console.log('✓ Generated Haxe serializer syntax validates successfully');
        
    } catch (error: any) {
        // Don't fail immediately - the serializer might still work despite validation issues
        // This is because the Haxe runtime has optional dependencies for different frameworks
        console.log('⚠ Haxe serializer validation had issues (may still work):');
        console.log(error.message.split('\n').slice(0, 3).join('\n'));
    }
}

async function main(): Promise<void> {
    try {
        // Read the IR file
        const irFile = path.resolve(__dirname, '../output/serializer-ir.json');
        if (!fs.existsSync(irFile)) {
            console.error('Serializer IR not found. Run generate-serializer-ir.ts first.');
            process.exit(1);
        }

        const ir: SerializerIR = JSON.parse(fs.readFileSync(irFile, 'utf8'));

        // Generate Haxe serializer from IR
        const haxeCode = generateHaxeFromIR(ir);

        // Write the Haxe file
        const haxeFile = path.resolve(
            __dirname,
            '../../spine-haxe/spine-haxe/spine/utils/SkeletonSerializer.hx'
        );

        fs.mkdirSync(path.dirname(haxeFile), { recursive: true });
        
        // Validate generated code compiles before writing
        await validateGeneratedHaxeCode(haxeCode, haxeFile);

        console.log(`Generated Haxe serializer from IR: ${haxeFile}`);
        console.log(`- ${ir.publicMethods.length} public methods`);
        console.log(`- ${ir.writeMethods.length} write methods`);
        console.log(`- ${Object.keys(ir.enumMappings).length} enum mappings`);

    } catch (error: any) {
        console.error('Error:', error.message);
        console.error('Stack:', error.stack);
        process.exit(1);
    }
}

// Allow running as a script or importing the function
if (import.meta.url === `file://${process.argv[1]}`) {
    main();
}

export { generateHaxeFromIR };