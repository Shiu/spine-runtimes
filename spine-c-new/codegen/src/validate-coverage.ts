#!/usr/bin/env node
import * as fs from 'fs';
import * as path from 'path';
import { Type, SpineTypes } from './types';
import { loadExclusions, isTypeExcluded } from './exclusions';

function main() {
    console.log('Validating type coverage...\n');
    
    // Load all necessary data
    const typesJson = JSON.parse(fs.readFileSync(path.join(__dirname, '../all-spine-types.json'), 'utf8')) as SpineTypes;
    const exclusions = loadExclusions(path.join(__dirname, '../exclusions.txt'));
    
    // Flatten all types
    const allTypes: Type[] = [];
    for (const header of Object.keys(typesJson)) {
        allTypes.push(...typesJson[header]);
    }
    
    // Categorize types
    const classes = allTypes.filter(t => t.kind === 'class' || t.kind === 'struct');
    const enums = allTypes.filter(t => t.kind === 'enum');
    
    // Check excluded types
    const excludedTypes = classes.filter(t => isTypeExcluded(t.name, exclusions));
    const includedTypes = classes.filter(t => !isTypeExcluded(t.name, exclusions));
    
    // Find abstract types
    const abstractTypes = includedTypes.filter(t => t.isAbstract);
    const concreteTypes = includedTypes.filter(t => !t.isAbstract);
    
    console.log('=== Type Coverage Report ===\n');
    console.log(`Total types found: ${allTypes.length}`);
    console.log(`  Classes/Structs: ${classes.length}`);
    console.log(`  Enums: ${enums.length}`);
    console.log('');
    
    console.log(`Excluded types: ${excludedTypes.length}`);
    excludedTypes.forEach(t => console.log(`  - ${t.name}`));
    console.log('');
    
    console.log(`Included types: ${includedTypes.length}`);
    console.log(`  Abstract: ${abstractTypes.length}`);
    abstractTypes.forEach(t => console.log(`    - ${t.name}`));
    console.log(`  Concrete: ${concreteTypes.length}`);
    console.log('');
    
    // Check for missing important types
    const importantTypes = [
        'Skeleton', 'SkeletonData', 'Animation', 'AnimationState',
        'Bone', 'Slot', 'Attachment', 'Skin', 'Event'
    ];
    
    console.log('Important types check:');
    for (const typeName of importantTypes) {
        const found = concreteTypes.find(t => t.name === typeName);
        const status = found ? '✓' : '✗';
        console.log(`  ${status} ${typeName}`);
    }
    
    console.log('\n=== Method Exclusion Report ===\n');
    
    // Count excluded methods per type
    const methodExclusions = exclusions.filter(e => e.kind === 'method');
    const methodsByType = new Map<string, string[]>();
    
    for (const exc of methodExclusions) {
        if (!methodsByType.has(exc.typeName)) {
            methodsByType.set(exc.typeName, []);
        }
        methodsByType.get(exc.typeName)!.push(exc.methodName!);
    }
    
    console.log(`Total method exclusions: ${methodExclusions.length}`);
    for (const [typeName, methods] of methodsByType) {
        console.log(`  ${typeName}: ${methods.length} methods`);
        methods.forEach(m => console.log(`    - ${m}`));
    }
}

main();