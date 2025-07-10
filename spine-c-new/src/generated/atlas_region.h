#ifndef SPINE_SPINE_ATLAS_REGION_H
#define SPINE_SPINE_ATLAS_REGION_H

#include "../base.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_atlas_region spine_atlas_region_create(void);

SPINE_C_API void spine_atlas_region_dispose(spine_atlas_region self);

SPINE_C_API spine_atlas_page spine_atlas_region_get_page(spine_atlas_region self);
SPINE_C_API void spine_atlas_region_set_page(spine_atlas_region self, spine_atlas_page value);
SPINE_C_API const char* spine_atlas_region_get_name(spine_atlas_region self);
SPINE_C_API void spine_atlas_region_set_name(spine_atlas_region self, const char* value);
SPINE_C_API int spine_atlas_region_get_index(spine_atlas_region self);
SPINE_C_API void spine_atlas_region_set_index(spine_atlas_region self, int value);
SPINE_C_API int spine_atlas_region_get_x(spine_atlas_region self);
SPINE_C_API void spine_atlas_region_set_x(spine_atlas_region self, int value);
SPINE_C_API int spine_atlas_region_get_y(spine_atlas_region self);
SPINE_C_API void spine_atlas_region_set_y(spine_atlas_region self, int value);
SPINE_C_API spine_array_int spine_atlas_region_get_splits(spine_atlas_region self);
SPINE_C_API void spine_atlas_region_set_splits(spine_atlas_region self, spine_array_int value);
SPINE_C_API spine_array_int spine_atlas_region_get_pads(spine_atlas_region self);
SPINE_C_API void spine_atlas_region_set_pads(spine_atlas_region self, spine_array_int value);
SPINE_C_API spine_array_float spine_atlas_region_get_values(spine_atlas_region self);
SPINE_C_API void spine_atlas_region_set_values(spine_atlas_region self, spine_array_float value);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_ATLAS_REGION_H */