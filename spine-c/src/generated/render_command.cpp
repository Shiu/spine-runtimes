#include "render_command.h"
#include <spine/spine.h>

using namespace spine;

void spine_render_command_dispose(spine_render_command self) {
	delete (RenderCommand *) self;
}

float *spine_render_command_get_positions(spine_render_command self) {
	RenderCommand *_self = (RenderCommand *) self;
	return _self->positions;
}

float *spine_render_command_get_uvs(spine_render_command self) {
	RenderCommand *_self = (RenderCommand *) self;
	return _self->uvs;
}

uint32_t *spine_render_command_get_colors(spine_render_command self) {
	RenderCommand *_self = (RenderCommand *) self;
	return _self->colors;
}

uint32_t *spine_render_command_get_dark_colors(spine_render_command self) {
	RenderCommand *_self = (RenderCommand *) self;
	return _self->darkColors;
}

int32_t spine_render_command_get_num_vertices(spine_render_command self) {
	RenderCommand *_self = (RenderCommand *) self;
	return _self->numVertices;
}

uint16_t *spine_render_command_get_indices(spine_render_command self) {
	RenderCommand *_self = (RenderCommand *) self;
	return _self->indices;
}

int32_t spine_render_command_get_num_indices(spine_render_command self) {
	RenderCommand *_self = (RenderCommand *) self;
	return _self->numIndices;
}

spine_blend_mode spine_render_command_get_blend_mode(spine_render_command self) {
	RenderCommand *_self = (RenderCommand *) self;
	return (spine_blend_mode) _self->blendMode;
}

void *spine_render_command_get_texture(spine_render_command self) {
	RenderCommand *_self = (RenderCommand *) self;
	return _self->texture;
}

spine_render_command spine_render_command_get_next(spine_render_command self) {
	RenderCommand *_self = (RenderCommand *) self;
	return (spine_render_command) _self->next;
}
