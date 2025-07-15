#ifndef SPINE_SPINE_PATH_ATTACHMENT_H
#define SPINE_SPINE_PATH_ATTACHMENT_H

#include "../base.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_path_attachment spine_path_attachment_create(const char * name);

SPINE_C_API void spine_path_attachment_dispose(spine_path_attachment self);

SPINE_C_API spine_rtti spine_path_attachment_get_rtti(spine_path_attachment self);
SPINE_C_API spine_array_float spine_path_attachment_get_lengths(spine_path_attachment self);
SPINE_C_API void spine_path_attachment_set_lengths(spine_path_attachment self, spine_array_float inValue);
SPINE_C_API bool spine_path_attachment_get_closed(spine_path_attachment self);
SPINE_C_API void spine_path_attachment_set_closed(spine_path_attachment self, bool inValue);
SPINE_C_API bool spine_path_attachment_get_constant_speed(spine_path_attachment self);
SPINE_C_API void spine_path_attachment_set_constant_speed(spine_path_attachment self, bool inValue);
SPINE_C_API spine_color spine_path_attachment_get_color(spine_path_attachment self);
SPINE_C_API spine_attachment spine_path_attachment_copy(spine_path_attachment self);
SPINE_C_API void spine_path_attachment_compute_world_vertices_1(spine_path_attachment self, spine_skeleton skeleton, spine_slot slot, size_t start, size_t count, float * worldVertices, size_t offset, size_t stride);
SPINE_C_API void spine_path_attachment_compute_world_vertices_2(spine_path_attachment self, spine_skeleton skeleton, spine_slot slot, size_t start, size_t count, spine_array_float worldVertices, size_t offset, size_t stride);
SPINE_C_API int spine_path_attachment_get_id(spine_path_attachment self);
SPINE_C_API spine_array_int spine_path_attachment_get_bones(spine_path_attachment self);
SPINE_C_API void spine_path_attachment_set_bones(spine_path_attachment self, spine_array_int bones);
SPINE_C_API spine_array_float spine_path_attachment_get_vertices(spine_path_attachment self);
SPINE_C_API void spine_path_attachment_set_vertices(spine_path_attachment self, spine_array_float vertices);
SPINE_C_API size_t spine_path_attachment_get_world_vertices_length(spine_path_attachment self);
SPINE_C_API void spine_path_attachment_set_world_vertices_length(spine_path_attachment self, size_t inValue);
SPINE_C_API spine_attachment spine_path_attachment_get_timeline_attachment(spine_path_attachment self);
SPINE_C_API void spine_path_attachment_set_timeline_attachment(spine_path_attachment self, spine_attachment attachment);
SPINE_C_API void spine_path_attachment_copy_to(spine_path_attachment self, spine_vertex_attachment other);
SPINE_C_API const char * spine_path_attachment_get_name(spine_path_attachment self);
SPINE_C_API int spine_path_attachment_get_ref_count(spine_path_attachment self);
SPINE_C_API void spine_path_attachment_reference(spine_path_attachment self);
SPINE_C_API void spine_path_attachment_dereference(spine_path_attachment self);
SPINE_C_API spine_rtti spine_path_attachment_rtti(void);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_PATH_ATTACHMENT_H */
