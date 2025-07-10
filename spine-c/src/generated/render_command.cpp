#include "render_command.h"
#include <spine/spine.h>

using namespace spine;

void spine_render_command_dispose(spine_render_command self) {
    delete (RenderCommand*)self;
}

float * spine_render_command_get_positions(spine_render_command self) {
    return ((RenderCommand*)self)->positions;
}

float * spine_render_command_get_uvs(spine_render_command self) {
    return ((RenderCommand*)self)->uvs;
}

uint32_t * spine_render_command_get_colors(spine_render_command self) {
    return ((RenderCommand*)self)->colors;
}

uint32_t * spine_render_command_get_dark_colors(spine_render_command self) {
    return ((RenderCommand*)self)->darkColors;
}

int32_t spine_render_command_get_num_vertices(spine_render_command self) {
    return ((RenderCommand*)self)->numVertices;
}

uint16_t * spine_render_command_get_indices(spine_render_command self) {
    return ((RenderCommand*)self)->indices;
}

int32_t spine_render_command_get_num_indices(spine_render_command self) {
    return ((RenderCommand*)self)->numIndices;
}

spine_blend_mode spine_render_command_get_blend_mode(spine_render_command self) {
    return (spine_blend_mode)((RenderCommand*)self)->blendMode;
}

void * spine_render_command_get_texture(spine_render_command self) {
    return ((RenderCommand*)self)->texture;
}

spine_render_command spine_render_command_get_next(spine_render_command self) {
    return (spine_render_command)((RenderCommand*)self)->next;
}
