#ifndef SPINE_SPINE_TEXTURE_REGION_H
#define SPINE_SPINE_TEXTURE_REGION_H

#include "../base.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_texture_region spine_texture_region_create(void);

SPINE_C_API void spine_texture_region_dispose(spine_texture_region self);

SPINE_C_API void * spine_texture_region_get_renderer_object(spine_texture_region self);
SPINE_C_API void spine_texture_region_set_renderer_object(spine_texture_region self, void * value);
SPINE_C_API float spine_texture_region_get_u(spine_texture_region self);
SPINE_C_API void spine_texture_region_set_u(spine_texture_region self, float value);
SPINE_C_API float spine_texture_region_get_v(spine_texture_region self);
SPINE_C_API void spine_texture_region_set_v(spine_texture_region self, float value);
SPINE_C_API float spine_texture_region_get_u2(spine_texture_region self);
SPINE_C_API void spine_texture_region_set_u2(spine_texture_region self, float value);
SPINE_C_API float spine_texture_region_get_v2(spine_texture_region self);
SPINE_C_API void spine_texture_region_set_v2(spine_texture_region self, float value);
SPINE_C_API int spine_texture_region_get_degrees(spine_texture_region self);
SPINE_C_API void spine_texture_region_set_degrees(spine_texture_region self, int value);
SPINE_C_API float spine_texture_region_get_offset_x(spine_texture_region self);
SPINE_C_API void spine_texture_region_set_offset_x(spine_texture_region self, float value);
SPINE_C_API float spine_texture_region_get_offset_y(spine_texture_region self);
SPINE_C_API void spine_texture_region_set_offset_y(spine_texture_region self, float value);
SPINE_C_API int spine_texture_region_get_width(spine_texture_region self);
SPINE_C_API void spine_texture_region_set_width(spine_texture_region self, int value);
SPINE_C_API int spine_texture_region_get_height(spine_texture_region self);
SPINE_C_API void spine_texture_region_set_height(spine_texture_region self, int value);
SPINE_C_API int spine_texture_region_get_original_width(spine_texture_region self);
SPINE_C_API void spine_texture_region_set_original_width(spine_texture_region self, int value);
SPINE_C_API int spine_texture_region_get_original_height(spine_texture_region self);
SPINE_C_API void spine_texture_region_set_original_height(spine_texture_region self, int value);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_TEXTURE_REGION_H */