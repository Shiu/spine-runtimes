#!/usr/bin/env node

const { execSync } = require('child_process');
const fs = require('fs');
const path = require('path');

const scriptDir = path.dirname(path.resolve(__filename));
const spineIncludeDir = path.join(scriptDir, 'spine-cpp', 'include');

function showHelp() {
  console.log(`
extract-spine-cpp-types.js - Extract type information from spine-cpp header files

USAGE:
  extract-spine-cpp-types.js [<header-file>]
  extract-spine-cpp-types.js --help

DESCRIPTION:
  Extracts classes, structs, enums, and their public members from C++ headers.
  Without arguments, processes all headers in spine-cpp/include.
  
  In all-files mode, performs two passes:
  1. Extract all type definitions
  2. Add inherited methods from supertypes (including template instantiations)

OUTPUT FORMAT:
  Single file mode: Array of type definitions
  All files mode: Object with relative file paths as keys

TYPE DEFINITION STRUCTURE:
  {
    "name": "ClassName",                    // Type name
    "kind": "class" | "struct" | "enum",    // Type kind
    "loc": {                                // Source location
      "line": 45,
      "col": 15
    },
    "superTypes": ["BaseClass", "Interface"],  // Base classes (optional)
    "members": [...],                          // Public members (classes/structs)
    "values": [...],                           // Enum constants (enums only)
    "isTemplate": true,                        // Present if type is a template
    "templateParams": ["T", "U"],              // Template parameter names (templates only)
    "isAbstract": true                         // Present if class has pure virtual methods
  }

MEMBER STRUCTURE:
  Fields:
    {
      "kind": "field",
      "name": "fieldName",
      "type": "int"
    }

  Methods:
    {
      "kind": "method",
      "name": "methodName",
      "returnType": "void",
      "parameters": [
        {"name": "param1", "type": "int"},
        {"name": "param2", "type": "const String &"}
      ],
      "isStatic": false,
      "isVirtual": true,
      "isPure": false,
      "fromSupertype": "BaseClass"    // Present if inherited (all-files mode only)
    }

  Constructors:
    {
      "kind": "constructor",
      "name": "ClassName",
      "parameters": [...]
    }

ENUM VALUES:
  {
    "name": "ENUM_VALUE",
    "value": "1 << 0"    // Present only if explicitly initialized
  }

INHERITANCE (all-files mode only):
  - Methods inherited from non-template supertypes are included
  - Methods inherited from template supertypes have parameters substituted
  - Full inheritance hierarchy is preserved (grandparent methods appear via parent)
  - SpineObject methods are excluded (considered noise)
  - Methods are marked with "fromSupertype" field indicating immediate source
  - Template supertypes appear as "TemplateName<Type1, Type2>"
  - Example: If C inherits B inherits A, C gets all methods from A and B

NOTES:
  - Only public members are extracted
  - Forward declarations are excluded
  - Template instantiations (e.g., Vector<int>) are excluded
  - Friend declarations are excluded
  - Implicit/compiler-generated methods are excluded
  - Destructors and operator methods are excluded (not needed for C wrapper generation)

EXAMPLES:
  # Extract types from single file
  extract-spine-cpp-types.js spine-cpp/include/spine/Animation.h > animation.json

  # Extract all types with inheritance resolution
  extract-spine-cpp-types.js > all-spine-types.json

  # Query specific type
  extract-spine-cpp-types.js > types.json
  jq '."spine/Bone.h"[] | select(.name == "Bone")' types.json
`);
}

function extractLocalTypes(headerFile, typeMap = null) {
  const absHeaderPath = path.resolve(headerFile);
  const sourceContent = fs.readFileSync(absHeaderPath, 'utf8');
  const sourceLines = sourceContent.split('\n');
  
  // Get AST from clang
  const cmd = `clang++ -Xclang -ast-dump=json -fsyntax-only -std=c++11 -I "${spineIncludeDir}" "${absHeaderPath}" 2>/dev/null`;
  const maxBuffer = headerFile.includes('Debug.h') ? 500 : 200; // MB
  
  let astJson;
  try {
    const output = execSync(cmd, { encoding: 'utf8', maxBuffer: maxBuffer * 1024 * 1024 });
    astJson = JSON.parse(output);
  } catch (error) {
    throw new Error(error.code === 'ENOBUFS' 
      ? `AST output too large (>${maxBuffer}MB)` 
      : error.message);
  }
  
  const types = [];
  
  function extractEnumValueFromSource(enumConstNode) {
    if (!enumConstNode.loc) return undefined;
    
    const line = sourceLines[enumConstNode.loc.line - 1];
    if (!line) return undefined;
    
    // Find enum name and check for '='
    const nameMatch = line.match(new RegExp(`\\b${enumConstNode.name}\\b`));
    if (!nameMatch) return undefined;
    
    const afterName = line.substring(nameMatch.index + enumConstNode.name.length);
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
  
  function extractReturnType(methodNode) {
    const fullType = methodNode.type?.qualType || '';
    const match = fullType.match(/^(.+?)\s*\(/);
    return match ? match[1].trim() : 'void';
  }
  
  function extractParameters(methodNode) {
    return (methodNode.inner || [])
      .filter(n => n.kind === 'ParmVarDecl')
      .map(n => ({
        name: n.name || '',
        type: n.type?.qualType || ''
      }));
  }
  
  function isInTargetFile(node) {
    if (!node.loc) return false;
    
    const targetPath = path.resolve(headerFile);
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
  
  function extractTypeInfo(node) {
    const info = {
      name: node.name || '',
      kind: node.kind === 'EnumDecl' ? 'enum' : (node.tagUsed || ''),
      loc: {
        line: node.loc?.line || 0,
        col: node.loc?.col || 0
      }
    };
    
    // Extract base classes
    if (node.bases?.length > 0) {
      info.superTypes = node.bases.map(b => b.type?.qualType || '').filter(Boolean);
    }
    
    // For enums, extract the values
    if (node.kind === 'EnumDecl') {
      info.values = (node.inner || [])
        .filter(n => n.kind === 'EnumConstantDecl')
        .map(n => {
          const enumValue = { name: n.name || '' };
          const sourceValue = extractEnumValueFromSource(n);
          
          if (sourceValue === null) {
            // Implicit value - no value property
          } else if (sourceValue) {
            enumValue.value = sourceValue;
          } else if (n.inner?.length > 0) {
            enumValue.value = "<<extraction failed>>";
          }
          
          return enumValue;
        });
      return info;
    }
    
    // For classes/structs, extract public members
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
    
    // Mark as abstract if it has pure virtual methods
    if (hasPureVirtual) {
      info.isAbstract = true;
    }
    
    return info;
  }
  
  function extractMember(inner, parent) {
    if (inner.isImplicit) return null;
    
    switch (inner.kind) {
      case 'FieldDecl':
        return {
          kind: 'field',
          name: inner.name || '',
          type: inner.type?.qualType || ''
        };
        
      case 'CXXMethodDecl':
        if (!inner.name) return null;
        // Skip operators - not needed for C wrapper generation
        if (inner.name.startsWith('operator')) return null;
        
        return {
          kind: 'method',
          name: inner.name,
          returnType: extractReturnType(inner),
          parameters: extractParameters(inner),
          isStatic: inner.storageClass === 'static',
          isVirtual: inner.virtual || false,
          isPure: inner.pure || false
        };
        
      case 'CXXConstructorDecl':
        return {
          kind: 'constructor',
          name: inner.name || parent.name || '',
          parameters: extractParameters(inner)
        };
        
      case 'CXXDestructorDecl':
        // Skip destructors - not needed for C wrapper generation
        return null;
        
      default:
        return null;
    }
  }
  
  function processNode(node, inSpineNamespace = false) {
    if (!node || typeof node !== 'object') return;
    
    // Handle spine namespace
    if (node.kind === 'NamespaceDecl' && node.name === 'spine') {
      (node.inner || []).forEach(n => processNode(n, true));
      return;
    }
    
    // Recurse to find spine namespace
    if (!inSpineNamespace) {
      (node.inner || []).forEach(n => processNode(n, false));
      return;
    }
    
    // Process type declarations
    const typeKinds = ['CXXRecordDecl', 'ClassTemplateDecl', 'EnumDecl', 'TypedefDecl', 'TypeAliasDecl'];
    if (!typeKinds.includes(node.kind)) return;
    
    // Skip if not in target file or invalid
    if (!isInTargetFile(node) || 
        node.isImplicit || 
        !node.name || 
        node.name.startsWith('_') || 
        node.name.includes('<')) return;
    
    // Skip forward declarations
    if (node.previousDecl && (!node.inner || node.inner.length === 0)) return;
    
    // Extract type info
    if (node.kind === 'ClassTemplateDecl') {
      const classNode = (node.inner || []).find(n => n.kind === 'CXXRecordDecl');
      if (classNode) {
        const typeInfo = extractTypeInfo(classNode);
        typeInfo.isTemplate = true;
        
        // Extract template parameters
        const templateParams = [];
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
      types.push(extractTypeInfo(node));
    } else if (node.kind === 'EnumDecl') {
      types.push(extractTypeInfo(node));
    } else if (node.kind === 'TypedefDecl' || node.kind === 'TypeAliasDecl') {
      types.push(extractTypeInfo(node));
    }
  }
  
  processNode(astJson);
  
  // Filter out forward declarations and sort by line number
  const filteredTypes = types
    .filter(t => !(t.members && t.members.length === 0))
    .sort((a, b) => a.loc.line - b.loc.line);
  
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

function addInheritedMethods(type, typeMap) {
  const inheritedMethods = [];
  const ownMethodSignatures = new Set();
  
  // Build a set of method signatures from this type
  for (const member of type.members) {
    if (member.kind === 'method') {
      const sig = getMethodSignature(member);
      ownMethodSignatures.add(sig);
    }
  }
  
  // Process each supertype
  for (const superTypeName of type.superTypes) {
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
      if (templateType && templateType.isTemplate && templateType.members) {
        // Process template inheritance
        addTemplateInheritedMethods(
          type, templateType, templateClassName, templateArgs, 
          inheritedMethods, ownMethodSignatures
        );
      } else if (templateType && !templateType.isTemplate) {
        // Template might not be marked as isTemplate, try anyway
        addTemplateInheritedMethods(
          type, templateType, templateClassName, templateArgs, 
          inheritedMethods, ownMethodSignatures
        );
      }
    } else {
      // Non-template supertype
      const superType = typeMap.get(cleanName);
      
      if (!superType || !superType.members) continue;
      
      // Add non-overridden methods from supertype
      for (const member of superType.members) {
        if (member.kind === 'method') {
          const sig = getMethodSignature(member);
          if (!ownMethodSignatures.has(sig)) {
            const inheritedMember = { ...member, fromSupertype: cleanName };
            inheritedMethods.push(inheritedMember);
            ownMethodSignatures.add(sig); // Prevent duplicates from multiple inheritance
          }
        }
      }
    }
  }
  
  // Add inherited methods to the type
  type.members.push(...inheritedMethods);
}

function addTemplateInheritedMethods(
  type, templateType, templateClassName, templateArgs, 
  inheritedMethods, ownMethodSignatures
) {
  // Parse template arguments (handle multiple args)
  const argsList = [];
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
  const paramMap = new Map();
  
  // Use the actual template parameters if we have them
  if (templateType.templateParams && templateType.templateParams.length === argsList.length) {
    templateType.templateParams.forEach((param, i) => {
      paramMap.set(param, argsList[i]);
    });
  } else {
    // Fallback: if we don't have template param info, skip substitution
    console.error(`Warning: Template ${templateClassName} missing parameter info, skipping substitution`);
    return;
  }
  
  // Process each member of the template
  for (const member of templateType.members) {
    if (member.kind === 'method') {
      // Skip template constructors - they have weird names like "Pose<P>"
      if (member.name.includes('<')) continue;
      
      // Clone the member and substitute template parameters
      const inheritedMember = JSON.parse(JSON.stringify(member));
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

function substituteTemplateParams(typeStr, paramMap) {
  let result = typeStr;
  
  // Replace template parameters in order of length (longest first)
  // to avoid replacing substrings (e.g., V before V1)
  const sortedParams = Array.from(paramMap.keys()).sort((a, b) => b.length - a.length);
  
  for (const param of sortedParams) {
    const regex = new RegExp(`\\b${param}\\b`, 'g');
    result = result.replace(regex, paramMap.get(param));
  }
  
  return result;
}

function getMethodSignature(method) {
  // Create a signature that identifies method overrides
  // For virtual methods, just use the name
  // For non-virtual methods, include parameter types
  let sig = method.name;
  if (method.parameters && method.parameters.length > 0) {
    sig += '(' + method.parameters.map(p => p.type).join(',') + ')';
  } else {
    sig += '()';
  }
  
  // Add const qualifier if present
  if (method.returnType && method.returnType.includes('const')) {
    sig += ' const';
  }
  
  return sig;
}

function findAllHeaderFiles() {
  const headers = [];
  
  function walkDir(dir) {
    fs.readdirSync(dir).forEach(file => {
      const fullPath = path.join(dir, file);
      if (fs.statSync(fullPath).isDirectory()) {
        walkDir(fullPath);
      } else if (file.endsWith('.h') && file !== 'spine.h') {
        headers.push(fullPath);
      }
    });
  }
  
  walkDir(spineIncludeDir);
  return headers.sort();
}

// Main execution
const arg = process.argv[2];

if (arg === '--help' || arg === '-h') {
  showHelp();
  process.exit(0);
}

if (arg) {
  // Single file mode - no inheritance support
  if (!fs.existsSync(arg)) {
    console.error(`Error: File not found: ${arg}`);
    process.exit(1);
  }
  
  try {
    const types = extractLocalTypes(arg);
    if (types.length === 0) {
      console.error('No types found in the specified file');
      process.exit(1);
    }
    console.log(JSON.stringify(types, null, 2));
  } catch (error) {
    console.error(`Error: ${error.message}`);
    process.exit(1);
  }
} else {
  // Process all files
  const allHeaders = findAllHeaderFiles();
  const allTypes = {};
  let processed = 0, errors = 0;
  
  console.error(`Processing ${allHeaders.length} header files...`);
  
  // First pass: extract all types without inheritance
  const typeMap = new Map();
  
  for (const headerFile of allHeaders) {
    const relPath = path.relative(spineIncludeDir, headerFile);
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
    } catch (error) {
      errors++;
      console.error(`\n    ERROR processing ${relPath}: ${error.message}`);
    }
  }
  
  // Second pass: add inherited methods
  console.error(`\n  Pass 2 - Adding inherited methods...`);
  processed = 0;
  
  for (const headerFile of allHeaders) {
    const relPath = path.relative(spineIncludeDir, headerFile);
    if (!allTypes[relPath]) continue;
    
    process.stderr.write(`\r\x1b[K  Pass 2 - Processing ${++processed}/${Object.keys(allTypes).length}: ${relPath}...`);
    
    for (const type of allTypes[relPath]) {
      if (type.superTypes && type.members) {
        addInheritedMethods(type, typeMap);
      }
    }
  }
  
  console.error(`\n  Completed: ${Object.keys(allTypes).length} files processed, ${errors} errors`);
  console.log(JSON.stringify(allTypes, null, 2));
}