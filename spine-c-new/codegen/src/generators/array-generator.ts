import { Type, Member, toSnakeCase, Method } from '../types';
import { ArraySpecialization } from '../array-scanner';

export class ArrayGenerator {
    private arrayType: Type | undefined;

    constructor(private typesJson: any) {
        // Find the Array type definition
        for (const header of Object.keys(typesJson)) {
            const arrayType = typesJson[header].find((t: Type) => t.name === 'Array');
            if (arrayType) {
                this.arrayType = arrayType;
                break;
            }
        }
    }

    /**
     * Generates arrays.h and arrays.cpp content
     */
    generate(specializations: ArraySpecialization[]): { header: string[], source: string[] } {
        const header: string[] = [];
        const source: string[] = [];

        if (!this.arrayType) {
            console.error('ERROR: Array type not found in spine-cpp types');
            return { header, source };
        }

        // Header file
        header.push('#ifndef SPINE_C_ARRAYS_H');
        header.push('#define SPINE_C_ARRAYS_H');
        header.push('');
        header.push('#include "../base.h"');
        header.push('#include "types.h"');
        header.push('');
        header.push('#ifdef __cplusplus');
        header.push('extern "C" {');
        header.push('#endif');
        header.push('');

        // Source file
        source.push('#include "arrays.h"');
        source.push('#include <spine/Array.h>');
        source.push('#include <spine/spine.h>');
        source.push('');
        source.push('using namespace spine;');
        source.push('');

        // Generate for each specialization
        for (const spec of specializations) {
            console.log(`Generating array specialization: ${spec.cTypeName}`);
            this.generateSpecialization(spec, header, source);
        }

        // Close header
        header.push('#ifdef __cplusplus');
        header.push('}');
        header.push('#endif');
        header.push('');
        header.push('#endif // SPINE_C_ARRAYS_H');

        return { header, source };
    }

    private generateSpecialization(spec: ArraySpecialization, header: string[], source: string[]) {
        // Opaque type declaration
        header.push(`// ${spec.cppType}`);
        header.push(`SPINE_OPAQUE_TYPE(${spec.cTypeName})`);
        header.push('');

        // Get Array methods to wrap
        const methods = this.arrayType!.members?.filter(m =>
            m.kind === 'method'
        ).filter(m => !m.isStatic && !m.name.includes('operator')) || [];

        // Generate create method (constructor)
        header.push(`SPINE_C_EXPORT ${spec.cTypeName} ${spec.cTypeName}_create();`);
        source.push(`${spec.cTypeName} ${spec.cTypeName}_create() {`);
        source.push(`    return (${spec.cTypeName}) new (__FILE__, __LINE__) ${spec.cppType}();`);
        source.push('}');
        source.push('');

        // Generate dispose
        header.push(`SPINE_C_EXPORT void ${spec.cTypeName}_dispose(${spec.cTypeName} array);`);
        source.push(`void ${spec.cTypeName}_dispose(${spec.cTypeName} array) {`);
        source.push(`    if (!array) return;`);
        source.push(`    delete (${spec.cppType}*) array;`);
        source.push('}');
        source.push('');

        // Generate hardcoded get/set methods
        header.push(`SPINE_C_EXPORT ${spec.cElementType} ${spec.cTypeName}_get(${spec.cTypeName} array, int index);`);
        source.push(`${spec.cElementType} ${spec.cTypeName}_get(${spec.cTypeName} array, int index) {`);
        source.push(`    if (!array) return ${this.getDefaultValue(spec)};`);
        source.push(`    ${spec.cppType} *_array = (${spec.cppType}*) array;`);
        source.push(`    return ${this.convertFromCpp(spec, '(*_array)[index]')};`);
        source.push('}');
        source.push('');

        header.push(`SPINE_C_EXPORT void ${spec.cTypeName}_set(${spec.cTypeName} array, int index, ${spec.cElementType} value);`);
        source.push(`void ${spec.cTypeName}_set(${spec.cTypeName} array, int index, ${spec.cElementType} value) {`);
        source.push(`    if (!array) return;`);
        source.push(`    ${spec.cppType} *_array = (${spec.cppType}*) array;`);
        source.push(`    (*_array)[index] = ${this.convertToCpp(spec, 'value')};`);
        source.push('}');
        source.push('');

        // Generate wrapper for each Array method
        for (const method of methods) {
            this.generateMethodWrapper(spec, method, header, source);
        }

        header.push('');
    }

    private generateMethodWrapper(spec: ArraySpecialization, method: Method, header: string[], source: string[]) {
        // Skip constructors and destructors
        if (method.name === 'Array' || method.name === '~Array') return;

        // Build C function name
        const cFuncName = `${spec.cTypeName}_${toSnakeCase(method.name)}`;

        // Convert return type
        let returnType = 'void';
        let hasReturn = false;
        if (method.returnType && method.returnType !== 'void') {
            hasReturn = true;
            if (method.returnType === 'T &' || method.returnType === `${spec.elementType} &`) {
                // Return by reference becomes return by value in C
                returnType = spec.cElementType;
            } else if (method.returnType === 'T *' || method.returnType === `${spec.elementType} *`) {
                returnType = spec.cElementType;
            } else if (method.returnType === 'size_t') {
                returnType = 'size_t';
            } else if (method.returnType === 'int') {
                returnType = 'int';
            } else if (method.returnType === 'bool') {
                returnType = 'bool';
            } else if (method.returnType === `${spec.cppType} *`) {
                returnType = spec.cTypeName;
            } else {
                // Unknown return type - skip this method
                console.log(`  Skipping Array method ${method.name} - unknown return type: ${method.returnType}`);
                return;
            }
        }

        // Build parameter list
        const cParams: string[] = [`${spec.cTypeName} array`];
        const cppArgs: string[] = [];

        if (method.parameters) {
            for (const param of method.parameters) {
                if (param.type === 'T' || param.type === spec.elementType ||
                    param.type === 'const T &' || param.type === `const ${spec.elementType} &`) {
                    cParams.push(`${spec.cElementType} ${param.name}`);
                    cppArgs.push(this.convertToCpp(spec, param.name));
                } else if (param.type === 'size_t') {
                    cParams.push(`size_t ${param.name}`);
                    cppArgs.push(param.name);
                } else if (param.type === 'int') {
                    cParams.push(`int ${param.name}`);
                    cppArgs.push(param.name);
                } else {
                    // Unknown parameter type - skip this method
                    console.log(`  Skipping Array method ${method.name} - unknown param type: ${param.type}`);
                    return;
                }
            }
        }

        // Generate declaration
        header.push(`SPINE_C_EXPORT ${returnType} ${cFuncName}(${cParams.join(', ')});`);

        // Generate implementation
        source.push(`${returnType} ${cFuncName}(${cParams.join(', ')}) {`);
        source.push(`    if (!array) return${hasReturn ? ' ' + this.getDefaultReturn(returnType, spec) : ''};`);
        source.push(`    ${spec.cppType} *_array = (${spec.cppType}*) array;`);

        const call = `_array->${method.name}(${cppArgs.join(', ')})`;
        if (hasReturn) {
            if (returnType === spec.cElementType) {
                source.push(`    return ${this.convertFromCpp(spec, call)};`);
            } else {
                source.push(`    return ${call};`);
            }
        } else {
            source.push(`    ${call};`);
        }

        source.push('}');
        source.push('');
    }

    private getDefaultValue(spec: ArraySpecialization): string {
        if (spec.isPointer) return 'nullptr';
        if (spec.isPrimitive) {
            if (spec.cElementType === 'bool') return 'false';
            return '0';
        }
        if (spec.isEnum) return '0';
        return '0';
    }

    private getDefaultReturn(returnType: string, spec: ArraySpecialization): string {
        if (returnType === 'bool') return 'false';
        if (returnType === 'size_t' || returnType === 'int') return '0';
        if (returnType === spec.cElementType) return this.getDefaultValue(spec);
        if (returnType === spec.cTypeName) return 'nullptr';
        return '0';
    }

    private convertFromCpp(spec: ArraySpecialization, expr: string): string {
        if (spec.isPointer) {
            return `(${spec.cElementType}) ${expr}`;
        }
        if (spec.isEnum && spec.elementType !== 'PropertyId') {
            return `(${spec.cElementType}) ${expr}`;
        }
        return expr;
    }

    private convertToCpp(spec: ArraySpecialization, expr: string): string {
        if (spec.isPointer) {
            return `(${spec.elementType}) ${expr}`;
        }
        if (spec.isEnum && spec.elementType !== 'PropertyId') {
            return `(${spec.elementType}) ${expr}`;
        }
        return expr;
    }
}