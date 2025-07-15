#ifndef SPINE_SPINE_CLIPPING_ATTACHMENT_H
#define SPINE_SPINE_CLIPPING_ATTACHMENT_H

#include "../base.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_clipping_attachment spine_clipping_attachment_create(const char *name);

SPINE_C_API void spine_clipping_attachment_dispose(spine_clipping_attachment self);

SPINE_C_API spine_rtti spine_clipping_attachment_get_rtti(spine_clipping_attachment self);
SPINE_C_API spine_slot_data spine_clipping_attachment_get_end_slot(spine_clipping_attachment self);
SPINE_C_API void spine_clipping_attachment_set_end_slot(spine_clipping_attachment self, spine_slot_data inValue);
SPINE_C_API spine_color spine_clipping_attachment_get_color(spine_clipping_attachment self);
SPINE_C_API spine_attachment spine_clipping_attachment_copy(spine_clipping_attachment self);
SPINE_C_API void spine_clipping_attachment_compute_world_vertices_1(spine_clipping_attachment self, spine_skeleton skeleton, spine_slot slot,
																	size_t start, size_t count, float *worldVertices, size_t offset, size_t stride);
SPINE_C_API void spine_clipping_attachment_compute_world_vertices_2(spine_clipping_attachment self, spine_skeleton skeleton, spine_slot slot,
																	size_t start, size_t count, spine_array_float worldVertices, size_t offset,
																	size_t stride);
SPINE_C_API int spine_clipping_attachment_get_id(spine_clipping_attachment self);
SPINE_C_API spine_array_int spine_clipping_attachment_get_bones(spine_clipping_attachment self);
SPINE_C_API void spine_clipping_attachment_set_bones(spine_clipping_attachment self, spine_array_int bones);
SPINE_C_API spine_array_float spine_clipping_attachment_get_vertices(spine_clipping_attachment self);
SPINE_C_API void spine_clipping_attachment_set_vertices(spine_clipping_attachment self, spine_array_float vertices);
SPINE_C_API size_t spine_clipping_attachment_get_world_vertices_length(spine_clipping_attachment self);
SPINE_C_API void spine_clipping_attachment_set_world_vertices_length(spine_clipping_attachment self, size_t inValue);
SPINE_C_API spine_attachment spine_clipping_attachment_get_timeline_attachment(spine_clipping_attachment self);
SPINE_C_API void spine_clipping_attachment_set_timeline_attachment(spine_clipping_attachment self, spine_attachment attachment);
SPINE_C_API void spine_clipping_attachment_copy_to(spine_clipping_attachment self, spine_vertex_attachment other);
SPINE_C_API const char *spine_clipping_attachment_get_name(spine_clipping_attachment self);
SPINE_C_API int spine_clipping_attachment_get_ref_count(spine_clipping_attachment self);
SPINE_C_API void spine_clipping_attachment_reference(spine_clipping_attachment self);
SPINE_C_API void spine_clipping_attachment_dereference(spine_clipping_attachment self);
SPINE_C_API spine_rtti spine_clipping_attachment_rtti(void);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_CLIPPING_ATTACHMENT_H */
