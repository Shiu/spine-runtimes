#!/usr/bin/env tsx

import * as fs from 'fs';
import * as path from 'path';
import { fileURLToPath } from 'url';
import { parse } from 'java-parser';
import type { ClassInfo } from './types';

const __dirname = path.dirname(fileURLToPath(import.meta.url));

function addReferenceVersionsForWriteMethods(cpp: string): string {
    // Find all writeXXX(XXX* obj) methods
    const writeMethodRegex = /    void (write\w+)\((\w+)\* obj\) \{/g;
    const referenceMethods = [];

    let match;
    while ((match = writeMethodRegex.exec(cpp)) !== null) {
        const methodName = match[1];
        const typeName = match[2];
        console.log(`Found method: ${methodName}(${typeName}* obj)`);

        // Generate reference version that calls pointer version
        const refMethod = `    void ${methodName}(const ${typeName}& obj) {
        ${methodName}(const_cast<${typeName}*>(&obj));
    }`;
        referenceMethods.push(refMethod);
    }

    console.log(`Found ${referenceMethods.length} writeXXX methods, adding reference versions`);

    // Insert before }; // class SkeletonSerializer
    const marker = '}; // class SkeletonSerializer';
    const insertPos = cpp.lastIndexOf(marker);
    if (insertPos === -1) {
        throw new Error('Could not find class end marker');
    }

    const referenceMethodsText = '\n' + referenceMethods.join('\n\n') + '\n\n';
    const before = cpp.substring(0, insertPos);
    const after = cpp.substring(insertPos);

    cpp = before + referenceMethodsText + after;

    return cpp;
}

function transformJavaToCppAST(javaCode: string): string {
    // Parse Java code into AST
    const ast = parse(javaCode);
    
    // Load analysis data to get enum information
    const analysisFile = path.resolve(__dirname, '..', 'output', 'analysis-result.json');
    const analysisData = JSON.parse(fs.readFileSync(analysisFile, 'utf8'));
    const classMap = new Map<string, ClassInfo>(analysisData.classMap);
    
    // Build enum mappings: Java enum name -> C++ enum values
    const enumMappings = new Map<string, Map<string, string>>();
    
    for (const [className, classInfo] of classMap) {
        if (classInfo.isEnum && classInfo.enumValues) {
            const shortName = className.split('.').pop()!;
            const valueMap = new Map<string, string>();
            
            for (const javaValue of classInfo.enumValues) {
                // Convert Java enum value to C++ enum value
                // e.g. "setup" -> "MixBlend_Setup", "first" -> "MixBlend_First"  
                const cppValue = `${shortName}_${javaValue.charAt(0).toUpperCase() + javaValue.slice(1)}`;
                valueMap.set(javaValue, cppValue);
            }
            
            enumMappings.set(shortName, valueMap);
        }
    }

    // Define custom function implementations for C++-specific cases
    const customFunctions = new Map<string, string>();
    
    // Custom writeColor - Color fields are public without _ prefix
    customFunctions.set('writeColor', `    void writeColor(Color* obj) {
        if (obj == nullptr) {
            _json.writeNull();
        } else {
            _json.writeObjectStart();
            _json.writeName("r");
            _json.writeValue(obj->r);
            _json.writeName("g");
            _json.writeValue(obj->g);
            _json.writeName("b");
            _json.writeValue(obj->b);
            _json.writeName("a");
            _json.writeValue(obj->a);
            _json.writeObjectEnd();
        }
    }`);
    
    // Custom writeSkinEntry - takes C++ AttachmentMap::Entry instead of Java SkinEntry
    customFunctions.set('writeSkinEntry', `    void writeSkinEntry(Skin::AttachmentMap::Entry* obj) {
        _json.writeObjectStart();
        _json.writeName("type");
        _json.writeValue("SkinEntry");
        _json.writeName("slotIndex");
        _json.writeValue((int)obj->_slotIndex);
        _json.writeName("name");
        _json.writeValue(obj->_name);
        _json.writeName("attachment");
        writeAttachment(obj->_attachment);
        _json.writeObjectEnd();
    }`);
    
    // Custom writeSkin - matches Java output exactly
    customFunctions.set('writeSkin', `    void writeSkin(Skin* obj) {
        if (_visitedObjects.containsKey(obj)) {
            _json.writeValue("<circular>");
            return;
        }
        _visitedObjects.put(obj, true);

        _json.writeObjectStart();
        _json.writeName("type");
        _json.writeValue("Skin");

        _json.writeName("attachments");
        _json.writeArrayStart();
        Skin::AttachmentMap::Entries entries = obj->getAttachments();
        while (entries.hasNext()) {
            Skin::AttachmentMap::Entry& entry = entries.next();
            writeSkinEntry(&entry);
        }
        _json.writeArrayEnd();

        _json.writeName("bones");
        _json.writeArrayStart();
        for (size_t i = 0; i < obj->getBones().size(); i++) {
            BoneData* item = obj->getBones()[i];
            writeBoneData(item);
        }
        _json.writeArrayEnd();

        _json.writeName("constraints");
        _json.writeArrayStart();
        for (size_t i = 0; i < obj->getConstraints().size(); i++) {
            ConstraintData* item = obj->getConstraints()[i];
            writeConstraintData(item);
        }
        _json.writeArrayEnd();

        _json.writeName("name");
        _json.writeValue(obj->getName());

        _json.writeName("color");
        writeColor(&obj->getColor());

        _json.writeObjectEnd();
    }`);

    // For now, start with the regex approach but fix the specific for-loop issue
    let cpp = javaCode;

    // Remove package declaration and imports
    cpp = cpp.replace(/^package .*;$/m, '');
    cpp = cpp.replace(/^import .*;$/gm, '');

    // Add C++ header
    const header = `#ifndef Spine_SkeletonSerializer_h
#define Spine_SkeletonSerializer_h

#include <spine/spine.h>
#include "JsonWriter.h"
#include <stdio.h>
#include <stdlib.h>

namespace spine {
`;

    // Transform class declaration
    cpp = cpp.replace(/public class SkeletonSerializer \{/, 'class SkeletonSerializer {');

    // Transform field declarations - add JsonWriter as member
    cpp = cpp.replace(/private final Set<Object> visitedObjects = new HashSet<>\(\);[\s]*private JsonWriter json;/, 'private:\n    HashMap<void*, bool> _visitedObjects;\n    JsonWriter _json;\n\npublic:\n    SkeletonSerializer() {}\n    ~SkeletonSerializer() {}');

    // Transform method signatures - return String not const String&
    cpp = cpp.replace(/public String serialize(\w+)\((\w+) (\w+)\) \{/g,
        'String serialize$1($2* $3) {');

    // Update the method bodies to use member JsonWriter
    cpp = cpp.replace(/visitedObjects\.clear\(\);/g, '_visitedObjects.clear();');
    cpp = cpp.replace(/json = new JsonWriter\(\);/g, '_json = JsonWriter();');
    cpp = cpp.replace(/json\.close\(\);/g, '_json.close();');
    cpp = cpp.replace(/return json\.getString\(\);/g, 'return _json.getString();');

    // Transform private methods - remove dots from type names (Animation.AlphaTimeline -> AlphaTimeline)
    cpp = cpp.replace(/private void write(\w+)\(([\w.]+) obj\) \{/g, function(match, methodName, typeName) {
        // Remove namespace/class prefix (e.g., Animation.AlphaTimeline -> AlphaTimeline)
        const simpleName = typeName.includes('.') ? typeName.split('.').pop() : typeName;
        return `void write${methodName}(${simpleName}* obj) {`;
    });

    // Add private: section before first write method
    cpp = cpp.replace(/(\n)(    void writeAnimation)/, '\nprivate:\n$2');

    // Transform object access
    cpp = cpp.replace(/visitedObjects\.contains\(obj\)/g, '_visitedObjects.containsKey(obj)');
    cpp = cpp.replace(/visitedObjects\.add\(obj\)/g, '_visitedObjects.put(obj, true)');

    // Transform method calls
    cpp = cpp.replace(/obj\.get(\w+)\(\)/g, 'obj->get$1()');
    cpp = cpp.replace(/json\.write/g, '_json.write');

    // Transform field access from obj.field to obj->field
    // Match any valid Java identifier (including $ and _) but not method calls
    cpp = cpp.replace(/obj\.([a-zA-Z_$][a-zA-Z0-9_$]*)\b(?!\()/g, 'obj->$1');

    // Fix C++ field access for underscore-prefixed fields
    // C++ private fields are prefixed with underscore but Java fields are not
    // Transform obj->field to obj->_field for ALL field accesses (not method calls)
    cpp = cpp.replace(/obj->([a-zA-Z][a-zA-Z0-9]*)\b(?!\()/g, 'obj->_$1');

    // Transform null checks and array/collection operations
    cpp = cpp.replace(/== null/g, '== nullptr');
    cpp = cpp.replace(/!= null/g, '!= nullptr');
    cpp = cpp.replace(/\.size/g, '.size()');
    cpp = cpp.replace(/\.get\((\w+)\)/g, '[$1]');

    // Remove null checks for C++-specific methods that always return references
    // BoundingBoxAttachment.getBones(), ClippingAttachment.getBones(), 
    // MeshAttachment.getBones(), MeshAttachment.getEdges()
    const noNullCheckMethods = ['getBones', 'getEdges'];
    
    for (const method of noNullCheckMethods) {
        // Remove if (obj.getMethod() == null) { json.writeNull(); } else { ... }
        const nullCheckPattern = new RegExp(
            `\\s*if \\(obj->${method}\\(\\) == nullptr\\) \\{[^}]*json\\.writeNull\\(\\);[^}]*\\} else \\{([^}]*)\\}`,
            'gs'
        );
        cpp = cpp.replace(nullCheckPattern, '$1');
        
        // Also handle the simpler pattern without else
        const simpleNullPattern = new RegExp(
            `\\s*if \\(obj->${method}\\(\\) == nullptr\\) \\{[^}]*json\\.writeNull\\(\\);[^}]*\\}`,
            'gs'
        );
        cpp = cpp.replace(simpleNullPattern, '');
    }

    // FIXED: Transform for-each loops properly with complete blocks
    // This handles the complete for-each block, not just the declaration
    cpp = cpp.replace(/for \(([\w.]+) (\w+) : obj->get(\w+)\(\)\) \{\s*([^}]+)\s*\}/g, function(match, typeName, varName, getter, body) {
        const simpleName = typeName.includes('.') ? typeName.split('.').pop() : typeName;
        // Special case for getPropertyIds which returns PropertyId not String
        if (getter === 'PropertyIds') {
            return `for (size_t i = 0; i < obj->get${getter}().size(); i++) {\n            PropertyId ${varName} = obj->get${getter}()[i];\n            ${body.trim()}\n        }`;
        }
        // lowercase = primitive type (no pointer), uppercase = class type (pointer)
        const isPointer = simpleName[0] === simpleName[0].toUpperCase();
        const cppType = isPointer ? `${simpleName}*` : simpleName;
        const accessor = (simpleName === 'String') ? `const String&` : cppType;
        return `for (size_t i = 0; i < obj->get${getter}().size(); i++) {\n            ${accessor} ${varName} = obj->get${getter}()[i];\n            ${body.trim()}\n        }`;
    });

    // Transform ALL remaining ranged for loops to indexed loops
    cpp = cpp.replace(/for \(([\w&*\s]+) (\w+) : ([^)]+)\) \{\s*([^}]+)\s*\}/g, function(match, type, varName, container, body) {
        const cleanType = type.trim();
        // lowercase = primitive type (no pointer), uppercase = class type (pointer)
        const isPointer = cleanType[0] === cleanType[0].toUpperCase();
        const cppType = isPointer ? `${cleanType}*` : cleanType;
        return `for (size_t i = 0; i < ${container}.size(); i++) {\n            ${cppType} ${varName} = ${container}[i];\n            ${body.trim()}\n        }`;
    });

    // Handle simpler for-each patterns
    cpp = cpp.replace(/for \(int i = 0; i < ([\w>()-]+)\.size; i\+\+\) {/g,
        'for (size_t i = 0; i < $1.size(); i++) {');

    // Special case for DeformTimeline::getVertices() which returns Array<Array<float>>
    cpp = cpp.replace(/for \(float\[\] (\w+) : obj->getVertices\(\)\) \{\s*([^}]+)\s*\}/g,
        'for (size_t i = 0; i < obj->getVertices().size(); i++) {\n            Array<float>& $1 = obj->getVertices()[i];\n            $2\n        }');

    // Also handle the pattern without obj-> prefix
    cpp = cpp.replace(/for \(float\[\] (\w+) : (\w+)\.getVertices\(\)\) \{\s*([^}]+)\s*\}/g,
        'for (size_t i = 0; i < $2->getVertices().size(); i++) {\n            Array<float>& $1 = $2->getVertices()[i];\n            $3\n        }');

    // Special case for other nested arrays like DrawOrderTimeline::getDrawOrders()
    cpp = cpp.replace(/for \(int\[\] (\w+) : obj->getDrawOrders\(\)\) \{\s*([^}]+)\s*\}/g,
        'for (size_t i = 0; i < obj->getDrawOrders().size(); i++) {\n            Array<int>& $1 = obj->getDrawOrders()[i];\n            $2\n        }');

    // Fix remaining array syntax that wasn't caught by the above
    cpp = cpp.replace(/for \(([\w]+)\[\]/g, 'for (Array<$1>&');

    // Transform instanceof and casts - remove dots from type names
    cpp = cpp.replace(/obj instanceof ([\w.]+)/g, function(match, typeName) {
        const simpleName = typeName.includes('.') ? typeName.split('.').pop() : typeName;
        return `obj->getRTTI().instanceOf(${simpleName}::rtti)`;
    });
    cpp = cpp.replace(/\(([\w.]+)\) obj/g, function(match, typeName) {
        const simpleName = typeName.includes('.') ? typeName.split('.').pop() : typeName;
        return `(${simpleName}*)obj`;
    });

    // Transform RuntimeException to fprintf + exit
    cpp = cpp.replace(/throw new RuntimeException\("([^"]+)"\);/g,
        'fprintf(stderr, "Error: $1\\n"); exit(1);');
    cpp = cpp.replace(/throw new RuntimeException\("([^"]*)" \+ obj->getClass\(\)\.getName\(\)\);/g,
        'fprintf(stderr, "Error: $1\\n"); exit(1);');

    // Remove class prefixes from type references, but not method calls
    // This handles AnimationState.TrackEntry, TransformConstraintData.FromProperty, etc.
    // But preserves obj.method() calls
    cpp = cpp.replace(/\b([A-Z]\w*)\.([A-Z]\w+)\b/g, '$2');

    // Replace enum .name() calls with switch statements
    cpp = cpp.replace(/obj->get(\w+)\(\)\.name\(\)/g, (match, methodName) => {
        // Extract enum type from method name (e.g. getMixBlend -> MixBlend)
        const enumType = methodName.replace(/^get/, '');
        const enumMap = enumMappings.get(enumType);
        
        if (enumMap && enumMap.size > 0) {
            // Generate switch statement
            let switchCode = `[&]() -> String {\n`;
            switchCode += `        switch(obj->get${methodName}()) {\n`;
            
            for (const [javaValue, cppValue] of enumMap) {
                switchCode += `            case ${cppValue}: return "${javaValue}";\n`;
            }
            
            switchCode += `            default: return "unknown";\n`;
            switchCode += `        }\n`;
            switchCode += `    }()`;
            
            return switchCode;
        }
        
        // Fallback if we don't have enum mapping
        return `String::valueOf((int)obj->get${methodName}())`;
    });

    // Fix some common patterns
    cpp = cpp.replace(/\.length\(\)/g, '.size()');
    cpp = cpp.replace(/new /g, '');

    // Remove any trailing extra braces before adding proper C++ ending
    cpp = cpp.replace(/\n\s*\}\s*$/, '');

    // Add proper C++ ending
    cpp += '\n}; // class SkeletonSerializer\n\n} // namespace spine\n\n#endif\n';

    // Prepend header
    cpp = header + cpp;

    // Clean up multiple empty lines
    cpp = cpp.replace(/\n{3,}/g, '\n\n');

    // Replace auto-generated functions with custom implementations
    for (const [functionName, customImpl] of customFunctions) {
        // Find and replace the auto-generated function
        const functionPattern = new RegExp(
            `    void ${functionName}\\([^{]*\\{[\\s\\S]*?^    \\}$`,
            'gm'
        );
        
        if (cpp.match(functionPattern)) {
            cpp = cpp.replace(functionPattern, customImpl);
            console.log(`Replaced auto-generated ${functionName} with custom implementation`);
        }
    }

    // Post-process: Add reference versions for all write methods
    cpp = addReferenceVersionsForWriteMethods(cpp);

    return cpp;
}

function main() {
    try {
        // Check if java-parser is installed
        try {
            require.resolve('java-parser');
        } catch (e) {
            console.error('java-parser package not found. Please install it with:');
            console.error('npm install java-parser');
            process.exit(1);
        }

        // Read the Java SkeletonSerializer
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

        if (!fs.existsSync(javaFile)) {
            console.error(`Java SkeletonSerializer not found at: ${javaFile}`);
            console.error('Please run generate-java-serializer.ts first');
            process.exit(1);
        }

        const javaCode = fs.readFileSync(javaFile, 'utf-8');

        // Transform to C++ using AST approach
        const cppCode = transformJavaToCppAST(javaCode);

        // Write the C++ file
        const cppFile = path.resolve(
            __dirname,
            '..',
            'spine-cpp',
            'tests',
            'SkeletonSerializer.h'
        );

        fs.mkdirSync(path.dirname(cppFile), { recursive: true });
        fs.writeFileSync(cppFile, cppCode);

        console.log(`Generated C++ serializer using AST approach: ${cppFile}`);
        console.log('This version should have proper for-loop structure');

    } catch (error: any) {
        console.error('Error:', error.message);
        process.exit(1);
    }
}

main();