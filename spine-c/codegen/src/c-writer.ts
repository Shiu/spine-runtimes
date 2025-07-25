import * as fs from 'node:fs';
import * as path from 'node:path';
import { fileURLToPath } from 'node:url';
import type { CClassOrStruct, CEnum, CMethod, CParameter } from './c-types';
import { toSnakeCase } from './types';

const __dirname = path.dirname(fileURLToPath(import.meta.url));
const LICENSE_HEADER = fs.readFileSync(path.join(__dirname, '../../../spine-cpp/src/spine/Skeleton.cpp'), 'utf8').split('\n').slice(0, 28).join('\n');

/** Generates strings for CClassOrStruct and CEnum, and writes them to files. */
export class CWriter {
    constructor(private outputDir: string) {
        // Clean and recreate output directory
        this.cleanOutputDirectory();
    }

    private cleanOutputDirectory(): void {
        // Remove existing generated directory if it exists
        if (fs.existsSync(this.outputDir)) {
            console.log(`Cleaning ${this.outputDir}...`);
            fs.rmSync(this.outputDir, { recursive: true, force: true });
        }

        // Recreate the directory
        fs.mkdirSync(this.outputDir, { recursive: true });
    }

    writeClassHeader(type: CClassOrStruct): string {
        const lines: string[] = [];

        // Add header guard
        const guardName = `SPINE_${type.name.toUpperCase()}_H`;
        lines.push(`#ifndef ${guardName}`);
        lines.push(`#define ${guardName}`);
        lines.push('');

        // Add includes
        lines.push('#include "../base.h"');
        lines.push('#include "types.h"');
        lines.push('#include "arrays.h"');
        lines.push('');

        // Add extern C
        lines.push('#ifdef __cplusplus');
        lines.push('extern "C" {');
        lines.push('#endif');
        lines.push('');

        // Add all method declarations
        for (const constr of type.constructors) {
            lines.push(this.writeMethodDeclaration(constr));
        }

        if (type.constructors.length > 0) {
            lines.push('');
        }

        if (type.destructor) {
            lines.push(this.writeMethodDeclaration(type.destructor));
            lines.push('');
        }

        for (const method of type.methods) {
            lines.push(this.writeMethodDeclaration(method));
        }

        // Close extern C
        lines.push('');
        lines.push('#ifdef __cplusplus');
        lines.push('}');
        lines.push('#endif');
        lines.push('');
        lines.push(`#endif /* ${guardName} */`);
        lines.push('');

        return lines.join('\n');
    }

    writeClassSource(type: CClassOrStruct): string {
        const lines: string[] = [];

        // Add includes
        lines.push(`#include "${type.name.replace("spine_", "")}.h"`);
        lines.push('#include <spine/spine.h>');
        lines.push('');
        lines.push('using namespace spine;');
        lines.push('');

        // Add all method implementations
        for (const constr of type.constructors) {
            lines.push(this.writeMethodImplementation(constr));
            lines.push('');
        }

        if (type.destructor) {
            lines.push(this.writeMethodImplementation(type.destructor));
            lines.push('');
        }

        for (const method of type.methods) {
            lines.push(this.writeMethodImplementation(method));
            lines.push('');
        }

        return `${lines.join('\n').trim()}\n`;
    }

    writeEnumHeader(enumType: CEnum): string {
        const lines: string[] = [];

        // Add header guard
        const guardName = `SPINE_${enumType.name.toUpperCase()}_H`;
        lines.push(`#ifndef ${guardName}`);
        lines.push(`#define ${guardName}`);
        lines.push('');

        // Add extern C
        lines.push('#ifdef __cplusplus');
        lines.push('extern "C" {');
        lines.push('#endif');
        lines.push('');

        // Add enum declaration
        lines.push(`typedef enum ${enumType.name} {`);

        for (let i = 0; i < enumType.values.length; i++) {
            const value = enumType.values[i];
            const comma = i < enumType.values.length - 1 ? ',' : '';

            if (value.value) {
                lines.push(`    ${value.name} = ${value.value}${comma}`);
            } else {
                lines.push(`    ${value.name}${comma}`);
            }
        }

        lines.push(`} ${enumType.name};`);

        // Close extern C
        lines.push('');
        lines.push('#ifdef __cplusplus');
        lines.push('}');
        lines.push('#endif');
        lines.push('');
        lines.push(`#endif /* ${guardName} */`);
        lines.push('');

        return lines.join('\n');
    }

    private writeMethodDeclaration(method: CMethod): string {
        const params = this.formatParameters(method.parameters);
        const returnTypeWithAnnotation = method.returnTypeNullable ? `/*@null*/ ${method.returnType}` : method.returnType;
        return `SPINE_C_API ${returnTypeWithAnnotation} ${method.name}(${params});`;
    }

    private writeMethodImplementation(method: CMethod): string {
        const params = this.formatParameters(method.parameters);
        const returnTypeWithAnnotation = method.returnTypeNullable ? `/*@null*/ ${method.returnType}` : method.returnType;
        const signature = `${returnTypeWithAnnotation} ${method.name}(${params})`;

        return `${signature} {
    ${method.body}
}`;
    }

    private formatParameters(parameters: CParameter[]): string {
        if (parameters.length === 0) {
            return 'void';
        }

        return parameters
            .map(p => {
                const typeWithAnnotation = p.isNullable ? `/*@null*/ ${p.cType}` : p.cType;
                return `${typeWithAnnotation} ${p.name}`;
            })
            .join(', ');
    }

    async writeType(typeName: string, headerContent: string, sourceContent?: string): Promise<void> {
        const fileName = toSnakeCase(typeName);

        // Write header file
        const headerPath = path.join(this.outputDir, `${fileName}.h`);
        fs.writeFileSync(headerPath, headerContent);

        // Write source file (as .cpp since it contains C++ code)
        if (sourceContent) {
            const sourcePath = path.join(this.outputDir, `${fileName}.cpp`);
            fs.writeFileSync(sourcePath, sourceContent);
        }
    }

    async writeMainHeader(cClasses: CClassOrStruct[]): Promise<void> {
        const mainHeaderPath = path.join(this.outputDir, '..', '..', 'include', 'spine-c.h');

        // Ensure include directory exists
        const includeDir = path.dirname(mainHeaderPath);
        if (!fs.existsSync(includeDir)) {
            fs.mkdirSync(includeDir, { recursive: true });
        }

        const lines = [
            LICENSE_HEADER,
            '',
            '#ifndef SPINE_C_H',
            '#define SPINE_C_H',
            '',
            '// Base definitions',
            '#include "../src/base.h"',
            '',
            '// All type declarations and enum includes',
            '#include "../src/generated/types.h"',
            '',
            '// Extension types & functions',
            '#include "../src/extensions.h"',
            '',
            '// Generated class types'
        ];

        // Add class includes (they contain the actual function declarations)
        for (const classType of cClasses) {
            lines.push(`#include "../src/generated/${classType.name.replace("spine_", "")}.h"`);
        }

        lines.push('');
        lines.push('#endif // SPINE_C_H');
        lines.push('');

        fs.writeFileSync(mainHeaderPath, lines.join('\n'));
    }

    async writeArrays(cArrayTypes: CClassOrStruct[]): Promise<void> {
        console.log('\nGenerating arrays.h/arrays.cpp...');

        // Generate header
        const arrayHeaderLines: string[] = [];

        arrayHeaderLines.push(LICENSE_HEADER);
        arrayHeaderLines.push('');
        arrayHeaderLines.push('#ifndef SPINE_C_ARRAYS_H');
        arrayHeaderLines.push('#define SPINE_C_ARRAYS_H');
        arrayHeaderLines.push('');
        arrayHeaderLines.push('#include "../base.h"');
        arrayHeaderLines.push('#include "types.h"');
        arrayHeaderLines.push('');
        arrayHeaderLines.push('#ifdef __cplusplus');
        arrayHeaderLines.push('extern "C" {');
        arrayHeaderLines.push('#endif');
        arrayHeaderLines.push('');

        // Add opaque type declarations
        for (const arrayType of cArrayTypes) {
            arrayHeaderLines.push(`SPINE_OPAQUE_TYPE(${arrayType.name})`);
        }

        arrayHeaderLines.push('');

        // Add all method declarations
        for (const arrayType of cArrayTypes) {
            arrayHeaderLines.push(arrayType.constructors.map(c => this.writeMethodDeclaration(c)).join('\n\n'));
            if (arrayType.destructor) {
                arrayHeaderLines.push(this.writeMethodDeclaration(arrayType.destructor));
            }
            arrayHeaderLines.push(arrayType.methods.map(c => this.writeMethodDeclaration(c)).join('\n\n'));
            arrayHeaderLines.push('');
        }

        // Close extern C
        arrayHeaderLines.push('#ifdef __cplusplus');
        arrayHeaderLines.push('}');
        arrayHeaderLines.push('#endif');
        arrayHeaderLines.push('');
        arrayHeaderLines.push('#endif /* SPINE_C_ARRAYS_H */');
        arrayHeaderLines.push('');


        // Generate source
        const arraySourceLines: string[] = [];

        arraySourceLines.push(LICENSE_HEADER);
        arraySourceLines.push('');
        arraySourceLines.push('#include "arrays.h"');
        arraySourceLines.push('#include <spine/spine.h>');
        arraySourceLines.push('');
        arraySourceLines.push('using namespace spine;');
        arraySourceLines.push('');

        // Add all method implementations
        for (const arrayType of cArrayTypes) {
            arraySourceLines.push(arrayType.constructors.map(c => this.writeMethodImplementation(c)).join('\n\n'));
            if (arrayType.destructor) {
                arraySourceLines.push(this.writeMethodImplementation(arrayType.destructor));
            }
            arraySourceLines.push(arrayType.methods.map(c => this.writeMethodImplementation(c)).join('\n\n'));
            arraySourceLines.push('');
        }


        const headerPath = path.join(this.outputDir, 'arrays.h');
        const sourcePath = path.join(this.outputDir, 'arrays.cpp');

        fs.writeFileSync(headerPath, arrayHeaderLines.join('\n'));
        fs.writeFileSync(sourcePath, arraySourceLines.join('\n'));
    }

    /** Writes the types.h file, which includes all class forward declarations and enum types. */
    async writeTypesHeader(cClasses: CClassOrStruct[], cEnums: CEnum[]): Promise<void> {
        const headerPath = path.join(this.outputDir, 'types.h');
        const lines: string[] = [
            LICENSE_HEADER,
            '',
            '#ifndef SPINE_C_TYPES_H',
            '#define SPINE_C_TYPES_H',
            '',
            '#ifdef __cplusplus',
            'extern "C" {',
            '#endif',
            '',
            '#include "../base.h"',
            '',
            '// Forward declarations for all non-enum types'
        ];

        // Forward declare all class types
        for (const classType of cClasses) {
            lines.push(`SPINE_OPAQUE_TYPE(${classType.name})`);
        }

        lines.push('');
        lines.push('// Include all enum types (cannot be forward declared)');

        // Include all enum headers
        for (const enumType of cEnums) {
            lines.push(`#include "${enumType.name.replace("spine_", "")}.h"`);
        }

        lines.push('');
        lines.push('#ifdef __cplusplus');
        lines.push('}');
        lines.push('#endif');
        lines.push('');
        lines.push('#endif // SPINE_C_TYPES_H');
        lines.push('');

        fs.writeFileSync(headerPath, lines.join('\n'));
    }

    async writeAll(cClasses: CClassOrStruct[], cEnums: CEnum[], cArrayTypes: CClassOrStruct[]): Promise<void> {
        await this.writeTypesHeader(cClasses, cEnums);
        await this.writeMainHeader(cClasses);
        await this.writeArrays(cArrayTypes);

        // Write all class files
        for (const classType of cClasses) {
            const headerContent = this.writeClassHeader(classType);
            const sourceContent = this.writeClassSource(classType);
            await this.writeType(classType.name.replace("spine_", ""), headerContent, sourceContent);
        }

        // Write all enum headers
        for (const enumType of cEnums) {
            const headerContent = this.writeEnumHeader(enumType);
            await this.writeType(enumType.name.replace("spine_", ""), headerContent);
        }
    }
}