#ifndef SPINE_SPINE_REGION_ATTACHMENT_H
#define SPINE_SPINE_REGION_ATTACHMENT_H

#include "../base.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_region_attachment spine_region_attachment_create(const char* name);

SPINE_C_API void spine_region_attachment_dispose(spine_region_attachment self);

SPINE_C_API spine_rtti spine_region_attachment_get_rtti(spine_region_attachment self);
SPINE_C_API void spine_region_attachment_update_region(spine_region_attachment self);
SPINE_C_API void spine_region_attachment_compute_world_vertices_1(spine_region_attachment self, spine_slot slot, float * worldVertices, size_t offset, size_t stride);
SPINE_C_API void spine_region_attachment_compute_world_vertices_2(spine_region_attachment self, spine_slot slot, spine_array_float worldVertices, size_t offset, size_t stride);
SPINE_C_API float spine_region_attachment_get_x(spine_region_attachment self);
SPINE_C_API void spine_region_attachment_set_x(spine_region_attachment self, float inValue);
SPINE_C_API float spine_region_attachment_get_y(spine_region_attachment self);
SPINE_C_API void spine_region_attachment_set_y(spine_region_attachment self, float inValue);
SPINE_C_API float spine_region_attachment_get_rotation(spine_region_attachment self);
SPINE_C_API void spine_region_attachment_set_rotation(spine_region_attachment self, float inValue);
SPINE_C_API float spine_region_attachment_get_scale_x(spine_region_attachment self);
SPINE_C_API void spine_region_attachment_set_scale_x(spine_region_attachment self, float inValue);
SPINE_C_API float spine_region_attachment_get_scale_y(spine_region_attachment self);
SPINE_C_API void spine_region_attachment_set_scale_y(spine_region_attachment self, float inValue);
SPINE_C_API float spine_region_attachment_get_width(spine_region_attachment self);
SPINE_C_API void spine_region_attachment_set_width(spine_region_attachment self, float inValue);
SPINE_C_API float spine_region_attachment_get_height(spine_region_attachment self);
SPINE_C_API void spine_region_attachment_set_height(spine_region_attachment self, float inValue);
SPINE_C_API spine_color spine_region_attachment_get_color(spine_region_attachment self);
SPINE_C_API const char* spine_region_attachment_get_path(spine_region_attachment self);
SPINE_C_API void spine_region_attachment_set_path(spine_region_attachment self, const char* inValue);
SPINE_C_API spine_texture_region spine_region_attachment_get_region(spine_region_attachment self);
SPINE_C_API void spine_region_attachment_set_region(spine_region_attachment self, spine_texture_region region);
SPINE_C_API spine_sequence spine_region_attachment_get_sequence(spine_region_attachment self);
SPINE_C_API void spine_region_attachment_set_sequence(spine_region_attachment self, spine_sequence sequence);
SPINE_C_API spine_array_float spine_region_attachment_get_offset(spine_region_attachment self);
SPINE_C_API spine_array_float spine_region_attachment_get_u_vs(spine_region_attachment self);
SPINE_C_API spine_attachment spine_region_attachment_copy(spine_region_attachment self);
SPINE_C_API const char* spine_region_attachment_get_name(spine_region_attachment self);
SPINE_C_API int spine_region_attachment_get_ref_count(spine_region_attachment self);
SPINE_C_API void spine_region_attachment_reference(spine_region_attachment self);
SPINE_C_API void spine_region_attachment_dereference(spine_region_attachment self);
SPINE_C_API spine_rtti spine_region_attachment_rtti(void);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_REGION_ATTACHMENT_H */