import * as fs from 'fs';
import { Exclusion } from './types';

export function loadExclusions(filePath: string): Exclusion[] {
    const content = fs.readFileSync(filePath, 'utf8');
    const lines = content.split('\n');
    const exclusions: Exclusion[] = [];
    
    for (const line of lines) {
        const trimmed = line.trim();
        
        // Skip empty lines and comments
        if (!trimmed || trimmed.startsWith('#')) continue;
        
        // Parse type exclusion
        const typeMatch = trimmed.match(/^type:\s*(.+)$/);
        if (typeMatch) {
            exclusions.push({
                kind: 'type',
                typeName: typeMatch[1].trim()
            });
            continue;
        }
        
        // Parse method exclusion
        const methodMatch = trimmed.match(/^method:\s*(.+?)::(.+)$/);
        if (methodMatch) {
            exclusions.push({
                kind: 'method',
                typeName: methodMatch[1].trim(),
                methodName: methodMatch[2].trim()
            });
        }
    }
    
    return exclusions;
}

export function isTypeExcluded(typeName: string, exclusions: Exclusion[]): boolean {
    return exclusions.some(ex => ex.kind === 'type' && ex.typeName === typeName);
}

export function isMethodExcluded(typeName: string, methodName: string, exclusions: Exclusion[]): boolean {
    return exclusions.some(ex => 
        ex.kind === 'method' && 
        ex.typeName === typeName && 
        ex.methodName === methodName
    );
}