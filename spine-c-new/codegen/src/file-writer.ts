import * as fs from 'fs';
import * as path from 'path';
import { Type, toSnakeCase } from './types';

const LICENSE_HEADER = `/******************************************************************************
 * Spine Runtimes License Agreement
 * Last updated April 5, 2025. Replaces all prior versions.
 *
 * Copyright (c) 2013-2025, Esoteric Software LLC
 *
 * Integration of the Spine Runtimes into software or otherwise creating
 * derivative works of the Spine Runtimes is permitted under the terms and
 * conditions of Section 2 of the Spine Editor License Agreement:
 * http://esotericsoftware.com/spine-editor-license
 *
 * Otherwise, it is permitted to integrate the Spine Runtimes into software
 * or otherwise create derivative works of the Spine Runtimes (collectively,
 * "Products"), provided that each user of the Products must obtain their own
 * Spine Editor license and redistribution of the Products in any form must
 * include this license and copyright notice.
 *
 * THE SPINE RUNTIMES ARE PROVIDED BY ESOTERIC SOFTWARE LLC "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ESOTERIC SOFTWARE LLC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES,
 * BUSINESS INTERRUPTION, OR LOSS OF USE, DATA, OR PROFITS) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THE SPINE RUNTIMES, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/`;

export class FileWriter {
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
    
    async writeType(typeName: string, headerContent: string[], sourceContent: string[]): Promise<void> {
        const fileName = toSnakeCase(typeName);
        
        // Write header file
        const headerPath = path.join(this.outputDir, `${fileName}.h`);
        const headerGuard = `SPINE_C_${typeName.toUpperCase()}_H`;
        
        // Check if the header content uses any custom types from extensions.h
        const headerString = headerContent.join('\n');
        const needsExtensions = headerString.includes('spine_void') || 
                               headerString.includes('spine_dispose_renderer_object') ||
                               headerString.includes('spine_texture_loader');
        
        const headerLines = [
            LICENSE_HEADER,
            '',
            `#ifndef ${headerGuard}`,
            `#define ${headerGuard}`,
            '',
            '#ifdef __cplusplus',
            'extern "C" {',
            '#endif',
            '',
            '#include "types.h"',
        ];
        
        // Include extensions.h if needed
        if (needsExtensions) {
            headerLines.push('#include "../extensions.h"');
        }
        
        headerLines.push(
            '',
            ...headerContent,
            '',
            '#ifdef __cplusplus',
            '}',
            '#endif',
            '',
            `#endif // ${headerGuard}`
        );
        
        fs.writeFileSync(headerPath, headerLines.join('\n'));
        
        // Write source file (as .cpp since it contains C++ code)
        const sourcePath = path.join(this.outputDir, `${fileName}.cpp`);
        const sourceLines = [
            LICENSE_HEADER,
            '',
            ...sourceContent
        ];
        
        fs.writeFileSync(sourcePath, sourceLines.join('\n'));
    }
    
    async writeEnum(enumName: string, content: string[]): Promise<void> {
        const fileName = toSnakeCase(enumName);
        const headerPath = path.join(this.outputDir, `${fileName}.h`);
        const headerGuard = `SPINE_C_${enumName.toUpperCase()}_H`;
        
        const headerLines = [
            LICENSE_HEADER,
            '',
            `#ifndef ${headerGuard}`,
            `#define ${headerGuard}`,
            '',
            '#include "../base.h"',
            '',
            '#ifdef __cplusplus',
            'extern "C" {',
            '#endif',
            '',
            ...content,
            '',
            '#ifdef __cplusplus',
            '}',
            '#endif',
            '',
            `#endif // ${headerGuard}`
        ];
        
        fs.writeFileSync(headerPath, headerLines.join('\n'));
    }
    
    async writeMainHeader(classes: Type[], enums: Type[]): Promise<void> {
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
            '// Extension functions',
            '#include "../src/extensions.h"',
            '',
            '// Generated class types'
        ];
        
        // Add class includes (they contain the actual function declarations)
        for (const classType of classes) {
            lines.push(`#include "../src/generated/${toSnakeCase(classType.name)}.h"`);
        }
        
        lines.push('');
        lines.push('#endif // SPINE_C_H');
        
        fs.writeFileSync(mainHeaderPath, lines.join('\n'));
    }
    
    async writeArrays(header: string[], source: string[]): Promise<void> {
        const headerPath = path.join(this.outputDir, 'arrays.h');
        const sourcePath = path.join(this.outputDir, 'arrays.cpp');
        
        // Add license header to both files
        const headerLines = [LICENSE_HEADER, '', ...header];
        const sourceLines = [LICENSE_HEADER, '', ...source];
        
        fs.writeFileSync(headerPath, headerLines.join('\n'));
        fs.writeFileSync(sourcePath, sourceLines.join('\n'));
    }
    
    async writeTypesHeader(classes: Type[], enums: Type[]): Promise<void> {
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
        for (const classType of classes) {
            const cTypeName = `spine_${toSnakeCase(classType.name)}`;
            lines.push(`SPINE_OPAQUE_TYPE(${cTypeName})`);
        }
        
        lines.push('');
        lines.push('// Include all enum types (cannot be forward declared)');
        
        // Include all enum headers
        for (const enumType of enums) {
            lines.push(`#include "${toSnakeCase(enumType.name)}.h"`);
        }
        
        lines.push('');
        lines.push('// Array specializations');
        lines.push('#include "arrays.h"');
        
        lines.push('');
        lines.push('#ifdef __cplusplus');
        lines.push('}');
        lines.push('#endif');
        lines.push('');
        lines.push('#endif // SPINE_C_TYPES_H');
        
        fs.writeFileSync(headerPath, lines.join('\n'));
    }
}