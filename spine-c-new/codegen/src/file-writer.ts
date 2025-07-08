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
            ...headerContent,
            '',
            '#ifdef __cplusplus',
            '}',
            '#endif',
            '',
            `#endif // ${headerGuard}`
        ];
        
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
            '#include "../../custom.h"',
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
            '// Custom types and functions',
            '#include "../src/custom.h"',
            '',
            '// Generated enum types'
        ];
        
        // Add enum includes
        for (const enumType of enums) {
            lines.push(`#include "../src/generated/${toSnakeCase(enumType.name)}.h"`);
        }
        
        lines.push('');
        lines.push('// Generated class types');
        
        // Add class includes
        for (const classType of classes) {
            lines.push(`#include "../src/generated/${toSnakeCase(classType.name)}.h"`);
        }
        
        lines.push('');
        lines.push('#endif // SPINE_C_H');
        
        fs.writeFileSync(mainHeaderPath, lines.join('\n'));
    }
}