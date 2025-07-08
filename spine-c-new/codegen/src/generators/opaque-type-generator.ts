import { Type, toSnakeCase } from '../types';

export class OpaqueTypeGenerator {
    generate(type: Type): string {
        const cName = `spine_${toSnakeCase(type.name)}`;
        return `SPINE_OPAQUE_TYPE(${cName})`;
    }
}