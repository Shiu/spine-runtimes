#ifndef SPINE_SPINE_VERTEX_ATTACHMENT_H
#define SPINE_SPINE_VERTEX_ATTACHMENT_H

#include "../base.h"
#include "types.h"
#include "arrays.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API void spine_vertex_attachment_dispose(spine_vertex_attachment self);

SPINE_C_API spine_rtti spine_vertex_attachment_get_rtti(spine_vertex_attachment self);
SPINE_C_API void spine_vertex_attachment_compute_world_vertices_1(spine_vertex_attachment self, spine_skeleton skeleton, spine_slot slot,
																  size_t start, size_t count, float *worldVertices, size_t offset, size_t stride);
SPINE_C_API void spine_vertex_attachment_compute_world_vertices_2(spine_vertex_attachment self, spine_skeleton skeleton, spine_slot slot,
																  size_t start, size_t count, spine_array_float worldVertices, size_t offset,
																  size_t stride);
SPINE_C_API int spine_vertex_attachment_get_id(spine_vertex_attachment self);
SPINE_C_API spine_array_int spine_vertex_attachment_get_bones(spine_vertex_attachment self);
SPINE_C_API void spine_vertex_attachment_set_bones(spine_vertex_attachment self, spine_array_int bones);
SPINE_C_API spine_array_float spine_vertex_attachment_get_vertices(spine_vertex_attachment self);
SPINE_C_API void spine_vertex_attachment_set_vertices(spine_vertex_attachment self, spine_array_float vertices);
SPINE_C_API size_t spine_vertex_attachment_get_world_vertices_length(spine_vertex_attachment self);
SPINE_C_API void spine_vertex_attachment_set_world_vertices_length(spine_vertex_attachment self, size_t inValue);
SPINE_C_API spine_attachment spine_vertex_attachment_get_timeline_attachment(spine_vertex_attachment self);
SPINE_C_API void spine_vertex_attachment_set_timeline_attachment(spine_vertex_attachment self, spine_attachment attachment);
SPINE_C_API void spine_vertex_attachment_copy_to(spine_vertex_attachment self, spine_vertex_attachment other);
SPINE_C_API const char *spine_vertex_attachment_get_name(spine_vertex_attachment self);
SPINE_C_API spine_attachment spine_vertex_attachment_copy(spine_vertex_attachment self);
SPINE_C_API int spine_vertex_attachment_get_ref_count(spine_vertex_attachment self);
SPINE_C_API void spine_vertex_attachment_reference(spine_vertex_attachment self);
SPINE_C_API void spine_vertex_attachment_dereference(spine_vertex_attachment self);
SPINE_C_API spine_rtti spine_vertex_attachment_rtti(void);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_VERTEX_ATTACHMENT_H */
