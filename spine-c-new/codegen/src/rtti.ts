import * as fs from 'fs';
import { Type } from './types';

export function loadRttiBases(filePath: string): Set<string> {
    const content = fs.readFileSync(filePath, 'utf8');
    const lines = content.split('\n');
    const bases = new Set<string>();
    
    for (const line of lines) {
        const trimmed = line.trim();
        if (trimmed && !trimmed.startsWith('#')) {
            bases.add(trimmed);
        }
    }
    
    return bases;
}

export function getTypeHierarchy(type: Type, allTypes: Type[]): string[] {
    const hierarchy: string[] = [type.name];
    
    if (type.superTypes) {
        for (const superName of type.superTypes) {
            const superType = allTypes.find(t => t.name === superName);
            if (superType) {
                hierarchy.push(...getTypeHierarchy(superType, allTypes));
            }
        }
    }
    
    return hierarchy;
}

export function getAllDerivedTypes(baseName: string, allTypes: Type[]): Type[] {
    const derived: Type[] = [];
    
    for (const type of allTypes) {
        if (type.superTypes && type.superTypes.includes(baseName)) {
            derived.push(type);
            // Recursively find all derived types
            derived.push(...getAllDerivedTypes(type.name, allTypes));
        }
    }
    
    return derived;
}

export function getLeafTypes(baseName: string, allTypes: Type[]): Type[] {
    const allDerived = getAllDerivedTypes(baseName, allTypes);
    const leafTypes: Type[] = [];
    
    for (const type of allDerived) {
        // A type is a leaf if no other type derives from it
        const hasChildren = allTypes.some(t => t.superTypes && t.superTypes.includes(type.name));
        if (!hasChildren && !type.isAbstract) {
            leafTypes.push(type);
        }
    }
    
    return leafTypes;
}