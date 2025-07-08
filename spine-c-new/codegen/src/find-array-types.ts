import * as fs from 'fs';
import * as path from 'path';

// Load the spine-cpp types
const typesJson = JSON.parse(fs.readFileSync(path.join(__dirname, '../spine-cpp-types.json'), 'utf8'));

// Set to store unique Array<T> types
const arrayTypes = new Set<string>();

// Function to extract Array<T> from a type string
function extractArrayTypes(typeStr: string | undefined) {
    if (!typeStr) return;
    
    // Find all Array<...> patterns
    const regex = /Array<([^>]+)>/g;
    let match;
    while ((match = regex.exec(typeStr)) !== null) {
        arrayTypes.add(match[0]); // Full Array<T> string
    }
}

// Process all types
for (const header of Object.keys(typesJson)) {
    for (const type of typesJson[header]) {
        if (!type.members) continue;
        
        for (const member of type.members) {
            // Check return types
            extractArrayTypes(member.returnType);
            
            // Check field types
            extractArrayTypes(member.type);
            
            // Check parameter types
            if (member.parameters) {
                for (const param of member.parameters) {
                    extractArrayTypes(param.type);
                }
            }
        }
    }
}

// Sort and display results
const sortedArrayTypes = Array.from(arrayTypes).sort();

console.log(`Found ${sortedArrayTypes.length} Array specializations:\n`);

// Group by element type
const primitiveArrays: string[] = [];
const pointerArrays: string[] = [];

for (const arrayType of sortedArrayTypes) {
    const elementType = arrayType.match(/Array<(.+)>/)![1];
    
    if (elementType.includes('*')) {
        pointerArrays.push(arrayType);
    } else {
        primitiveArrays.push(arrayType);
    }
}

console.log('Primitive Arrays:');
for (const type of primitiveArrays) {
    console.log(`  ${type}`);
}

console.log('\nPointer Arrays:');
for (const type of pointerArrays) {
    console.log(`  ${type}`);
}

// Generate C type names
console.log('\nC Type Names:');
console.log('\nPrimitive Arrays:');
for (const type of primitiveArrays) {
    const elementType = type.match(/Array<(.+)>/)![1];
    const cType = elementType === 'float' ? 'float' : 
                  elementType === 'int' ? 'int32_t' :
                  elementType === 'unsigned short' ? 'uint16_t' :
                  elementType;
    console.log(`  ${type} -> spine_array_${cType.replace(/ /g, '_')}`);
}

console.log('\nPointer Arrays:');
for (const type of pointerArrays) {
    const elementType = type.match(/Array<(.+?)\s*\*/)![1].trim();
    // Remove 'class ' prefix if present
    const cleanType = elementType.replace(/^class\s+/, '');
    // Convert to snake case
    const snakeCase = cleanType.replace(/([A-Z])/g, '_$1').toLowerCase().replace(/^_/, '');
    console.log(`  ${type} -> spine_array_${snakeCase}`);
}