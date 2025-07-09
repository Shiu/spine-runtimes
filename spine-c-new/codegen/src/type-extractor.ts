import * as fs from 'fs';
import * as path from 'path';
import { execSync } from 'child_process';
import { Type, Member, Method, Field, Constructor, Destructor, Parameter, EnumValue, SpineTypes, ClassOrStruct, Enum } from './types';

const SPINE_CPP_PATH = path.join(__dirname, '../../../spine-cpp');
const SPINE_INCLUDE_DIR = path.join(SPINE_CPP_PATH, 'spine-cpp/include');
const OUTPUT_FILE = path.join(__dirname, '../spine-cpp-types.json');

/**
 * Extracts the value of an enum constant from source code
 */
function extractEnumValueFromSource(
    enumConstNode: any,
    sourceLines: string[]
): string | null | undefined {
    if (!enumConstNode.loc) return undefined;

    const line = sourceLines[enumConstNode.loc.line - 1];
    if (!line) return undefined;

    // Find enum name and check for '='
    const nameMatch = line.match(new RegExp(`\\b${enumConstNode.name}\\b`));
    if (!nameMatch) return undefined;

    const afterName = line.substring(nameMatch.index! + enumConstNode.name.length);
    const equalIndex = afterName.indexOf('=');
    if (equalIndex === -1) return null; // No explicit value

    // Extract value expression
    let valueText = afterName.substring(equalIndex + 1);

    // Handle multi-line values
    let currentLine = enumConstNode.loc.line;
    while (currentLine < sourceLines.length && !valueText.match(/[,}]/)) {
        valueText += '\n' + sourceLines[currentLine++];
    }

    // Extract up to comma or brace
    const endMatch = valueText.match(/^(.*?)([,}])/s);
    if (endMatch) valueText = endMatch[1];

    // Clean up
    return valueText
        .replace(/\/\/.*$/gm, '') // Remove single-line comments
        .replace(/\/\*[\s\S]*?\*\//g, '') // Remove multi-line comments
        .replace(/\s+/g, ' ') // Normalize whitespace
        .trim();
}

/**
 * Extracts return type from a method node
 */
function extractReturnType(methodNode: any): string {
    const fullType = methodNode.type?.qualType || '';
    const match = fullType.match(/^(.+?)\s*\(/);
    return match ? match[1].trim() : 'void';
}

/**
 * Extracts parameters from a method node
 */
function extractParameters(methodNode: any): Parameter[] {
    return (methodNode.inner || [])
        .filter((n: any) => n.kind === 'ParmVarDecl')
        .map((n: any) => ({
            name: n.name || '',
            type: n.type?.qualType || ''
        }));
}

/**
 * Checks if a node is in the target file
 */
function isInTargetFile(node: any, targetPath: string): boolean {
    if (!node.loc) return false;

    const loc = node.loc;

    // Check direct file location
    if (loc.file) return path.resolve(loc.file) === targetPath;

    // Check macro locations
    for (const locType of ['spellingLoc', 'expansionLoc']) {
        if (loc[locType]) {
            if (loc[locType].includedFrom) return false;
            if (loc[locType].file) return path.resolve(loc[locType].file) === targetPath;
        }
    }

    // If included from another file, reject
    if (loc.includedFrom) return false;

    // No location info - assume it's in the main file
    return true;
}

/**
 * Extracts member information from an AST node
 */
function extractMember(inner: any, parent: any): Member | null {
    if (inner.isImplicit) return null;

    switch (inner.kind) {
        case 'FieldDecl':
            const field: Field = {
                kind: 'field',
                name: inner.name || '',
                type: inner.type?.qualType || '',
                isStatic: inner.storageClass === 'static'
            };
            return field;

        case 'CXXMethodDecl':
            if (!inner.name) return null;
            // Skip operators - not needed for C wrapper generation
            if (inner.name.startsWith('operator')) return null;

            const method: Method = {
                kind: 'method',
                name: inner.name,
                returnType: extractReturnType(inner),
                parameters: extractParameters(inner),
                isStatic: inner.storageClass === 'static',
                isVirtual: inner.virtual || false,
                isPure: inner.pure || false,
                isConst: inner.constQualifier || false
            };
            return method;

        case 'CXXConstructorDecl':
            const constructor: Constructor = {
                kind: 'constructor',
                name: inner.name || parent.name || '',
                parameters: extractParameters(inner)
            };
            return constructor;

        case 'CXXDestructorDecl':
            // Include destructors for completeness
            const destructor: Destructor = {
                kind: 'destructor',
                name: inner.name || `~${parent.name}`,
                isVirtual: inner.virtual || false,
                isPure: inner.pure || false
            };
            return destructor;

        default:
            return null;
    }
}

/**
 * Extracts type information from an AST node
 */
function extractTypeInfo(node: any, sourceLines: string[]): Type {
    // Handle enums separately
    if (node.kind === 'EnumDecl') {
        const enumInfo: Enum = {
            kind: 'enum',
            name: node.name || '',
            values: (node.inner || [])
                .filter((n: any) => n.kind === 'EnumConstantDecl')
                .map((n: any) => {
                    const enumValue: EnumValue = { name: n.name || '' };
                    const sourceValue = extractEnumValueFromSource(n, sourceLines);

                    if (sourceValue === null) {
                        // Implicit value - no value property
                    } else if (sourceValue) {
                        enumValue.value = sourceValue;
                    } else if (n.inner?.length > 0) {
                        enumValue.value = "<<extraction failed>>";
                    }

                    return enumValue;
                })
        };
        return enumInfo;
    }

    // Handle classes and structs
    const info: ClassOrStruct = {
        name: node.name || '',
        kind: (node.tagUsed || 'class') as 'class' | 'struct',
        loc: {
            line: node.loc?.line || 0,
            col: node.loc?.col || 0
        }
    };

    // Extract base classes
    if (node.bases?.length > 0) {
        info.superTypes = node.bases.map((b: any) => b.type?.qualType || '').filter(Boolean);
    }

    // Extract public members
    info.members = [];
    let currentAccess = node.tagUsed === 'struct' ? 'public' : 'private';
    let hasPureVirtual = false;

    for (const inner of node.inner || []) {
        if (inner.kind === 'AccessSpecDecl') {
            currentAccess = inner.access || 'private';
            continue;
        }

        if (inner.kind === 'FriendDecl' || currentAccess !== 'public') continue;

        const member = extractMember(inner, node);
        if (member) {
            info.members.push(member);
            // Check if this is a pure virtual method
            if (member.kind === 'method' && member.isPure) {
                hasPureVirtual = true;
            }
        }
    }

    // Always set isAbstract to a boolean value
    info.isAbstract = hasPureVirtual;

    return info;
}

/**
 * Processes an AST node to extract types
 */
function processNode(
    node: any,
    types: Type[],
    targetPath: string,
    sourceLines: string[],
    inSpineNamespace: boolean = false
): void {
    if (!node || typeof node !== 'object') return;

    // Handle spine namespace
    if (node.kind === 'NamespaceDecl' && node.name === 'spine') {
        (node.inner || []).forEach((n: any) => processNode(n, types, targetPath, sourceLines, true));
        return;
    }

    // Recurse to find spine namespace
    if (!inSpineNamespace) {
        (node.inner || []).forEach((n: any) => processNode(n, types, targetPath, sourceLines, false));
        return;
    }

    // Process type declarations
    const typeKinds = ['CXXRecordDecl', 'ClassTemplateDecl', 'EnumDecl', 'TypedefDecl', 'TypeAliasDecl'];
    if (!typeKinds.includes(node.kind)) return;

    // Skip if not in target file or invalid
    if (!isInTargetFile(node, targetPath) ||
        node.isImplicit ||
        !node.name ||
        node.name.startsWith('_') ||
        node.name.includes('<')) return;

    // Skip forward declarations
    if (node.previousDecl && (!node.inner || node.inner.length === 0)) return;

    // Extract type info
    if (node.kind === 'ClassTemplateDecl') {
        const classNode = (node.inner || []).find((n: any) => n.kind === 'CXXRecordDecl');
        if (classNode) {
            const typeInfo = extractTypeInfo(classNode, sourceLines);
            if (typeInfo.kind === 'enum') {
                throw new Error(`Template class ${node.name} is an enum, internal error, this should not happen`);
            }
            typeInfo.isTemplate = true;

            // Extract template parameters
            const templateParams: string[] = [];
            for (const inner of node.inner || []) {
                if (inner.kind === 'TemplateTypeParmDecl' && inner.name) {
                    templateParams.push(inner.name);
                }
            }
            if (templateParams.length > 0) {
                typeInfo.templateParams = templateParams;
            }

            types.push(typeInfo);
        }
    } else if (node.kind === 'CXXRecordDecl' && node.inner?.length > 0) {
        const typeInfo = extractTypeInfo(node, sourceLines);
        if (typeInfo.kind === 'enum') {
            throw new Error(`Class ${node.name} is an enum, which is not supported, internal error, this should not happen`);
        }
        // Ensure isTemplate is always set for non-template classes
        if (typeInfo.isTemplate === undefined) {
            typeInfo.isTemplate = false;
        }
        types.push(typeInfo);
    } else if (node.kind === 'EnumDecl') {
        types.push(extractTypeInfo(node, sourceLines));
    } else if (node.kind === 'TypedefDecl' || node.kind === 'TypeAliasDecl') {
        types.push(extractTypeInfo(node, sourceLines));
    }
}

/**
 * Extracts types from a single header file
 */
function extractLocalTypes(headerFile: string, typeMap: Map<string, Type> | null = null): Type[] {
    const absHeaderPath = path.resolve(headerFile);
    const sourceContent = fs.readFileSync(absHeaderPath, 'utf8');
    const sourceLines = sourceContent.split('\n');

    // Get AST from clang
    const cmd = `clang++ -Xclang -ast-dump=json -fsyntax-only -std=c++11 -I "${SPINE_INCLUDE_DIR}" "${absHeaderPath}" 2>/dev/null`;
    const maxBuffer = headerFile.includes('Debug.h') ? 500 : 200; // MB

    let astJson: any;
    try {
        const output = execSync(cmd, { encoding: 'utf8', maxBuffer: maxBuffer * 1024 * 1024 });
        astJson = JSON.parse(output);
    } catch (error: any) {
        throw new Error(error.code === 'ENOBUFS'
            ? `AST output too large (>${maxBuffer}MB)`
            : error.message);
    }

    const types: Type[] = [];
    processNode(astJson, types, absHeaderPath, sourceLines);

    // Filter out forward declarations and SpineObject
    const filteredTypes = types
        .filter(t => t.kind !== 'enum')
        .filter(t => {
            // Skip types with no members (forward declarations)
            if (t.members && t.members.length === 0) return false;

            // Skip SpineObject - it's not needed for C wrapper generation
            if (t.name === 'SpineObject') return false;

            return true;
        })
        .sort((a, b) => (a.loc?.line || 0) - (b.loc?.line || 0));

    // Add inherited methods if we have a type map
    if (typeMap) {
        for (const type of filteredTypes) {
            if (type.superTypes && type.members) {
                addInheritedMethods(type, typeMap);
            }
        }
    }

    return filteredTypes;
}

/**
 * Creates a method signature for comparison
 */
function getMethodSignature(method: Method): string {
    let sig = method.name;
    if (method.parameters && method.parameters.length > 0) {
        sig += '(' + method.parameters.map(p => p.type).join(',') + ')';
    } else {
        sig += '()';
    }

    // Add const qualifier if present
    if (method.isConst) {
        sig += ' const';
    }

    return sig;
}

/**
 * Substitutes template parameters in a type string
 */
function substituteTemplateParams(typeStr: string, paramMap: Map<string, string>): string {
    let result = typeStr;

    // Replace template parameters in order of length (longest first)
    // to avoid replacing substrings (e.g., V before V1)
    const sortedParams = Array.from(paramMap.keys()).sort((a, b) => b.length - a.length);

    for (const param of sortedParams) {
        const regex = new RegExp(`\\b${param}\\b`, 'g');
        result = result.replace(regex, paramMap.get(param)!);
    }

    return result;
}

/**
 * Adds methods inherited from template supertypes
 */
function addTemplateInheritedMethods(
    _type: ClassOrStruct,
    templateType: ClassOrStruct,
    templateClassName: string,
    templateArgs: string,
    inheritedMethods: Member[],
    ownMethodSignatures: Set<string>
): void {
    // Parse template arguments (handle multiple args)
    const argsList: string[] = [];
    let depth = 0;
    let currentArg = '';

    for (const char of templateArgs) {
        if (char === '<') depth++;
        else if (char === '>') depth--;

        if (char === ',' && depth === 0) {
            argsList.push(currentArg.trim());
            currentArg = '';
        } else {
            currentArg += char;
        }
    }
    if (currentArg.trim()) {
        argsList.push(currentArg.trim());
    }

    // Build a mapping of template params to actual types
    const paramMap = new Map<string, string>();

    // Use the actual template parameters if we have them
    if (templateType.templateParams && templateType.templateParams.length === argsList.length) {
        templateType.templateParams.forEach((param: string, i: number) => {
            paramMap.set(param, argsList[i]);
        });
    } else {
        // Fallback: if we don't have template param info, skip substitution
        console.error(`Warning: Template ${templateClassName} missing parameter info, skipping substitution`);
        return;
    }

    // Process each member of the template
    for (const member of templateType.members || []) {
        if (member.kind === 'method') {
            const method = member as Method;
            // Skip template constructors - they have weird names like "Pose<P>"
            if (method.name.includes('<')) continue;

            // Clone the member and substitute template parameters
            const inheritedMember: Method = JSON.parse(JSON.stringify(method));
            inheritedMember.fromSupertype = `${templateClassName}<${templateArgs}>`;

            // Replace template parameters in return type
            if (inheritedMember.returnType) {
                inheritedMember.returnType = substituteTemplateParams(
                    inheritedMember.returnType, paramMap
                );
            }

            // Replace template parameters in parameters
            if (inheritedMember.parameters) {
                for (const param of inheritedMember.parameters) {
                    param.type = substituteTemplateParams(param.type, paramMap);
                }
            }

            // Check if this method is overridden
            const sig = getMethodSignature(inheritedMember);
            if (!ownMethodSignatures.has(sig)) {
                inheritedMethods.push(inheritedMember);
                ownMethodSignatures.add(sig);
            }
        }
    }
}

/**
 * Adds inherited methods to a type
 */
function addInheritedMethods(type: ClassOrStruct, typeMap: Map<string, Type>): void {
    const inheritedMethods: Member[] = [];
    const ownMethodSignatures = new Set<string>();

    // Build a set of method signatures from this type
    for (const member of type.members || []) {
        if (member.kind === 'method') {
            const sig = getMethodSignature(member as Method);
            ownMethodSignatures.add(sig);
        }
    }

    // Process each supertype
    for (const superTypeName of type.superTypes || []) {
        // Clean up the supertype name (remove namespaces, etc)
        const cleanName = superTypeName.replace(/^.*::/, '');

        // Skip SpineObject inheritance - it's just noise
        if (cleanName === 'SpineObject') continue;

        // Check if this is a template supertype
        const templateMatch = cleanName.match(/^([^<]+)<(.+)>$/);
        if (templateMatch) {
            const templateClassName = templateMatch[1];
            const templateArgs = templateMatch[2];

            const templateType = typeMap.get(templateClassName);
            if (templateType && templateType.kind !== 'enum' && templateType.members) {
                // Process template inheritance
                addTemplateInheritedMethods(
                    type, templateType, templateClassName, templateArgs,
                    inheritedMethods, ownMethodSignatures
                );
            }
        } else {
            // Non-template supertype
            const superType = typeMap.get(cleanName);

            if (!superType || superType.kind === 'enum' || !superType.members) continue;

            // Add non-overridden methods from supertype
            for (const member of superType.members) {
                if (member.kind === 'method') {
                    const method = member as Method;
                    const sig = getMethodSignature(method);
                    if (!ownMethodSignatures.has(sig)) {
                        const inheritedMember = { ...method, fromSupertype: cleanName };
                        inheritedMethods.push(inheritedMember);
                        ownMethodSignatures.add(sig); // Prevent duplicates from multiple inheritance
                    }
                }
            }
        }
    }

    // Add inherited methods to the type
    if (type.members) {
        type.members.push(...inheritedMethods);
    }
}

/**
 * Finds all header files in the spine include directory
 */
function findAllHeaderFiles(): string[] {
    const headers: string[] = [];

    function walkDir(dir: string): void {
        fs.readdirSync(dir).forEach(file => {
            const fullPath = path.join(dir, file);
            if (fs.statSync(fullPath).isDirectory()) {
                walkDir(fullPath);
            } else if (file.endsWith('.h') && file !== 'spine.h') {
                headers.push(fullPath);
            }
        });
    }

    walkDir(SPINE_INCLUDE_DIR);
    return headers.sort();
}

/**
 * Checks if type extraction is needed based on file timestamps
 */
function isExtractionNeeded(): boolean {
    // If output doesn't exist, we need to extract
    if (!fs.existsSync(OUTPUT_FILE)) {
        console.log('spine-cpp-types.json not found, extraction needed');
        return true;
    }

    // Get output file timestamp
    const outputStats = fs.statSync(OUTPUT_FILE);
    const outputTime = outputStats.mtime.getTime();

    // Check all header files in the spine subdirectory
    const spineDir = path.join(SPINE_INCLUDE_DIR, 'spine');
    const headerFiles = fs.readdirSync(spineDir, { recursive: true })
        .filter((f: string | Buffer<ArrayBufferLike>) => f.toString().endsWith('.h'))
        .map((f: string | Buffer<ArrayBufferLike>) => path.join(spineDir, f.toString()));

    // Find newest header modification time
    let newestHeaderTime = 0;
    let newestHeader = '';

    for (const headerFile of headerFiles) {
        const stats = fs.statSync(headerFile);
        if (stats.mtime.getTime() > newestHeaderTime) {
            newestHeaderTime = stats.mtime.getTime();
            newestHeader = path.basename(headerFile);
        }
    }

    // If any header is newer than output, we need to extract
    if (newestHeaderTime > outputTime) {
        console.log(`Header ${newestHeader} is newer than spine-cpp-types.json, extraction needed`);
        return true;
    }

    console.log('spine-cpp-types.json is up to date');
    return false;
}

/**
 * Runs the type extraction process and generates the output file
 */
export function extractTypes(): void {
    if (!isExtractionNeeded()) {
        return;
    }

    console.log('Running type extraction...');

    try {
        const allHeaders = findAllHeaderFiles();
        const allTypes: SpineTypes = {};
        let processed = 0, errors = 0;

        console.error(`Processing ${allHeaders.length} header files...`);

        // First pass: extract all types without inheritance
        const typeMap = new Map<string, Type>();

        for (const headerFile of allHeaders) {
            const relPath = path.relative(SPINE_INCLUDE_DIR, headerFile);
            process.stderr.write(`\r\x1b[K  Pass 1 - Processing ${++processed}/${allHeaders.length}: ${relPath}...`);

            try {
                const types = extractLocalTypes(headerFile);
                if (types.length > 0) {
                    allTypes[relPath] = types;
                    // Build type map
                    for (const type of types) {
                        typeMap.set(type.name, type);
                    }
                }
            } catch (error: any) {
                errors++;
                console.error(`\n    ERROR processing ${relPath}: ${error.message}`);
            }
        }

        // Second pass: add inherited methods
        console.error(`\n  Pass 2 - Adding inherited methods...`);
        processed = 0;

        for (const headerFile of allHeaders) {
            const relPath = path.relative(SPINE_INCLUDE_DIR, headerFile);
            if (!allTypes[relPath]) continue;

            process.stderr.write(`\r\x1b[K  Pass 2 - Processing ${++processed}/${Object.keys(allTypes).length}: ${relPath}...`);

            for (const type of allTypes[relPath]) {
                if (type.kind !== 'enum' && type.superTypes && type.members) {
                    addInheritedMethods(type, typeMap);

                    // Check if any inherited methods are pure virtual
                    // If so, and the class doesn't override them, it's abstract
                    if (!type.isAbstract) {
                        const hasPureVirtual = type.members.some((m: Member) =>
                            m.kind === 'method' && m.isPure === true
                        );
                        if (hasPureVirtual) {
                            type.isAbstract = true;
                        }
                    }
                }
            }
        }

        console.error(`\n  Completed: ${Object.keys(allTypes).length} files processed, ${errors} errors`);

        // Write to output file
        fs.writeFileSync(OUTPUT_FILE, JSON.stringify(allTypes, null, 2));
        console.log(`Type extraction complete, wrote ${OUTPUT_FILE}`);
    } catch (error: any) {
        console.error('Failed to extract types:', error.message);
        throw error;
    }
}

/**
 * Loads the extracted type information
 */
export function loadTypes(): SpineTypes {
    if (!fs.existsSync(OUTPUT_FILE)) {
        throw new Error(`Type information not found at ${OUTPUT_FILE}. Run extraction first.`);
    }

    return JSON.parse(fs.readFileSync(OUTPUT_FILE, 'utf8'));
}