#!/usr/bin/env node
import * as fs from 'node:fs';
import * as path from 'node:path';
import { fileURLToPath } from 'node:url';
import { extractTypes } from './type-extractor';
import type { ClassOrStruct, Method, Type } from './types';

const __dirname = path.dirname(fileURLToPath(import.meta.url));

/**
 * Checks if a type string represents a pointer to a class instance
 */
function isPointerToClass(typeStr: string, allTypes: Type[]): boolean {
    // Remove const, references, and whitespace
    const cleanType = typeStr.replace(/\bconst\b/g, '').replace(/&/g, '').trim();
    
    // Check if it ends with * (pointer)
    if (!cleanType.endsWith('*')) {
        return false;
    }
    
    // Extract the base type (remove the *)
    const baseType = cleanType.replace(/\*+$/, '').trim();
    
    // Check if the base type is a class/struct in our type list
    return allTypes.some(type => 
        type.kind !== 'enum' && type.name === baseType
    );
}

/**
 * Checks if a type string represents a class instance (for return types)
 */
function isClassType(typeStr: string, allTypes: Type[]): boolean {
    // Remove const, references, and whitespace  
    const cleanType = typeStr.replace(/\bconst\b/g, '').replace(/&/g, '').replace(/\*/g, '').trim();
    
    // Check if the base type is a class/struct in our type list
    return allTypes.some(type => 
        type.kind !== 'enum' && type.name === cleanType
    );
}

/**
 * Analyzes all methods to find those with nullable inputs or outputs
 */
function analyzeNullableMethods(): void {
    console.log('Extracting type information...');
    const allTypes = extractTypes();
    
    const nullableMethods: Array<{
        filename: string;
        line: number;
        signature: string;
        reason: string;
    }> = [];
    
    // Process each type
    for (const type of allTypes) {
        if (type.kind === 'enum') continue;
        
        const classType = type as ClassOrStruct;
        if (!classType.members) continue;
        
        // Get the source file name relative to the nullable file location
        const filename = `../../spine-cpp/include/spine/${classType.name}.h`;
        
        // Process each method
        for (const member of classType.members) {
            if (member.kind !== 'method') continue;
            
            const method = member as Method;
            const signature = buildMethodSignature(classType.name, method);
            
            // Check return type - if it returns a pointer to a class
            if (method.returnType) {
                const cleanReturnType = method.returnType.replace(/\bconst\b/g, '').trim();
                if (isPointerToClass(cleanReturnType, allTypes)) {
                    nullableMethods.push({
                        filename,
                        line: method.loc.line,
                        signature,
                        reason: `returns nullable pointer: ${method.returnType}`
                    });
                }
            }
            
            // Check parameters - if any parameter is a pointer to a class
            if (method.parameters) {
                for (const param of method.parameters) {
                    if (isPointerToClass(param.type, allTypes)) {
                        nullableMethods.push({
                            filename,
                            line: method.loc.line,
                            signature,
                            reason: `takes nullable parameter '${param.name}': ${param.type}`
                        });
                        break; // Only report once per method
                    }
                }
            }
        }
    }
    
    // Sort by filename and line
    nullableMethods.sort((a, b) => {
        if (a.filename !== b.filename) {
            return a.filename.localeCompare(b.filename);
        }
        return a.line - b.line;
    });
    
    // Write results to nullable.md file
    const outputPath = path.join(__dirname, '../nullable.md');
    
    const instructions = `# Spine C++ Nullability Cleanup

## Instructions

**Phase 1: Enrich nullable.md (if implementations not yet inlined)**
If checkboxes don't contain concrete implementations:
1. Use parallel Task agents to find implementations (agents do NOT write to file)
2. Each agent researches 10-15 methods and returns structured data:
   \`\`\`
   METHOD: [method signature]
   CPP_HEADER: [file:line] [declaration]
   CPP_IMPL: [file:line] [implementation code]
   JAVA_IMPL: [file:line] [java method code]
   ---
   \`\`\`
3. Collect all agent results and do ONE MultiEdit to update nullable.md
4. Inline implementations BELOW each existing checkbox (keep original checkbox text):
   \`\`\`
   - [ ] [keep original checkbox line exactly as is]
     **C++ Implementation:**
     \`\`\`cpp
     // Header: [file:line]
     [declaration]
     // Implementation: [file:line] 
     [implementation body]
     \`\`\`
     **Java Implementation:**
     \`\`\`java
     // [file:line]
     [java method body]
     \`\`\`
   \`\`\`

**Phase 2: Review and Update**
For each unchecked checkbox (now with implementations inlined):
1. **Present both implementations** from the checkbox
2. **Ask if we need to change the C++ signature** based on Java nullability patterns (y/n)
3. **Make changes if needed**
   - Change the signature in the header file
   - Update the implementation in the corresponding .cpp file
   - Run \`../../spine-cpp/build.sh\` to confirm the changes compile successfully
4. **Confirm changes**
   - Summarize what was changed
   - Ask for confirmation that the changes are correct (y/n)
   - If yes, check the checkbox and move to the next unchecked item

## Methods to Review

`;

    const methodsList = nullableMethods.map(m => 
        `- [ ] [${m.filename}:${m.line}](${m.filename}#L${m.line}) ${m.signature} // ${m.reason}`
    ).join('\n');
    
    fs.writeFileSync(outputPath, instructions + methodsList + '\n');
    
    console.log(`Found ${nullableMethods.length} methods with nullable inputs/outputs`);
    console.log(`Results written to: ${outputPath}`);
    
    // Print summary statistics
    const byReason = new Map<string, number>();
    for (const method of nullableMethods) {
        const reasonType = method.reason.startsWith('returns') ? 'nullable return' : 'nullable parameter';
        byReason.set(reasonType, (byReason.get(reasonType) || 0) + 1);
    }
    
    console.log('\nSummary:');
    for (const [reason, count] of byReason) {
        console.log(`  ${reason}: ${count} methods`);
    }
}

/**
 * Builds a method signature string
 */
function buildMethodSignature(className: string, method: Method): string {
    const params = method.parameters?.map(p => `${p.type} ${p.name}`).join(', ') || '';
    const constStr = method.isConst ? ' const' : '';
    return `${method.returnType || 'void'} ${className}::${method.name}(${params})${constStr}`;
}

// Main execution
if (import.meta.url === `file://${process.argv[1]}`) {
    try {
        analyzeNullableMethods();
    } catch (error) {
        console.error('Error during analysis:', error);
        process.exit(1);
    }
}