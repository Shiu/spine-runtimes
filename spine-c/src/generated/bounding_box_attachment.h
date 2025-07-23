#ifndef SPINE_SPINE_BOUNDING_BOX_ATTACHMENT_H
#define SPINE_SPINE_BOUNDING_BOX_ATTACHMENT_H

#include "../base.h"
#include "types.h"
#include "arrays.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_bounding_box_attachment spine_bounding_box_attachment_create(const char *name);

SPINE_C_API void spine_bounding_box_attachment_dispose(spine_bounding_box_attachment self);

SPINE_C_API spine_rtti spine_bounding_box_attachment_get_rtti(spine_bounding_box_attachment self);
SPINE_C_API spine_color spine_bounding_box_attachment_get_color(spine_bounding_box_attachment self);
SPINE_C_API spine_attachment spine_bounding_box_attachment_copy(spine_bounding_box_attachment self);
SPINE_C_API void spine_bounding_box_attachment_compute_world_vertices_1(spine_bounding_box_attachment self, spine_skeleton skeleton, spine_slot slot,
																		size_t start, size_t count, float *worldVertices, size_t offset,
																		size_t stride);
SPINE_C_API void spine_bounding_box_attachment_compute_world_vertices_2(spine_bounding_box_attachment self, spine_skeleton skeleton, spine_slot slot,
																		size_t start, size_t count, spine_array_float worldVertices, size_t offset,
																		size_t stride);
SPINE_C_API int spine_bounding_box_attachment_get_id(spine_bounding_box_attachment self);
SPINE_C_API spine_array_int spine_bounding_box_attachment_get_bones(spine_bounding_box_attachment self);
SPINE_C_API void spine_bounding_box_attachment_set_bones(spine_bounding_box_attachment self, spine_array_int bones);
SPINE_C_API spine_array_float spine_bounding_box_attachment_get_vertices(spine_bounding_box_attachment self);
SPINE_C_API void spine_bounding_box_attachment_set_vertices(spine_bounding_box_attachment self, spine_array_float vertices);
SPINE_C_API size_t spine_bounding_box_attachment_get_world_vertices_length(spine_bounding_box_attachment self);
SPINE_C_API void spine_bounding_box_attachment_set_world_vertices_length(spine_bounding_box_attachment self, size_t inValue);
SPINE_C_API spine_attachment spine_bounding_box_attachment_get_timeline_attachment(spine_bounding_box_attachment self);
SPINE_C_API void spine_bounding_box_attachment_set_timeline_attachment(spine_bounding_box_attachment self, spine_attachment attachment);
SPINE_C_API void spine_bounding_box_attachment_copy_to(spine_bounding_box_attachment self, spine_vertex_attachment other);
SPINE_C_API const char *spine_bounding_box_attachment_get_name(spine_bounding_box_attachment self);
SPINE_C_API int spine_bounding_box_attachment_get_ref_count(spine_bounding_box_attachment self);
SPINE_C_API void spine_bounding_box_attachment_reference(spine_bounding_box_attachment self);
SPINE_C_API void spine_bounding_box_attachment_dereference(spine_bounding_box_attachment self);
SPINE_C_API spine_rtti spine_bounding_box_attachment_rtti(void);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_BOUNDING_BOX_ATTACHMENT_H */
