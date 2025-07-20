#ifndef SPINE_SPINE_ATLAS_H
#define SPINE_SPINE_ATLAS_H

#include "../base.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API void spine_atlas_flip_v(spine_atlas self);
SPINE_C_API spine_atlas_region spine_atlas_find_region(spine_atlas self, const char *name);
SPINE_C_API spine_array_atlas_page spine_atlas_get_pages(spine_atlas self);
SPINE_C_API spine_array_atlas_region spine_atlas_get_regions(spine_atlas self);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_ATLAS_H */
