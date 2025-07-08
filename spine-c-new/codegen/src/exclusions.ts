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
        
        // Parse method exclusion with optional const specification
        // Format: method: Type::method or method: Type::method const
        const methodMatch = trimmed.match(/^method:\s*(.+?)::(.+?)(\s+const)?$/);
        if (methodMatch) {
            const methodName = methodMatch[2].trim();
            const isConst = !!methodMatch[3];
            
            exclusions.push({
                kind: 'method',
                typeName: methodMatch[1].trim(),
                methodName: methodName,
                isConst: isConst
            });
            
            if (isConst) {
                console.log(`Parsed const exclusion: ${methodMatch[1].trim()}::${methodName} const`);
            }
        }
    }
    
    return exclusions;
}

export function isTypeExcluded(typeName: string, exclusions: Exclusion[]): boolean {
    return exclusions.some(ex => ex.kind === 'type' && ex.typeName === typeName);
}

export function isMethodExcluded(typeName: string, methodName: string, exclusions: Exclusion[], returnType?: string): boolean {
    // Determine if method is const by looking at return type
    const isConstMethod = returnType ? returnType.includes('const ') && returnType.includes('&') : false;
    
    const result = exclusions.some(ex => {
        if (ex.kind === 'method' && 
            ex.typeName === typeName && 
            ex.methodName === methodName) {
            // If exclusion doesn't specify const, it matches all
            if (ex.isConst === undefined) return true;
            // Otherwise, it must match the const flag
            return ex.isConst === isConstMethod;
        }
        return false;
    });
    
    return result;
}