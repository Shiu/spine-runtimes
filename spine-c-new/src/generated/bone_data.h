#ifndef SPINE_SPINE_BONE_DATA_H
#define SPINE_SPINE_BONE_DATA_H

#include "../base.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_bone_data spine_bone_data_create(int index, const char* name, spine_bone_data parent);

SPINE_C_API void spine_bone_data_dispose(spine_bone_data self);

SPINE_C_API int spine_bone_data_get_index(spine_bone_data self);
SPINE_C_API spine_bone_data spine_bone_data_get_parent(spine_bone_data self);
SPINE_C_API float spine_bone_data_get_length(spine_bone_data self);
SPINE_C_API void spine_bone_data_set_length(spine_bone_data self, float inValue);
SPINE_C_API spine_color spine_bone_data_get_color(spine_bone_data self);
SPINE_C_API const char* spine_bone_data_get_icon(spine_bone_data self);
SPINE_C_API void spine_bone_data_set_icon(spine_bone_data self, const char* icon);
SPINE_C_API bool spine_bone_data_get_visible(spine_bone_data self);
SPINE_C_API void spine_bone_data_set_visible(spine_bone_data self, bool inValue);
SPINE_C_API spine_bone_local spine_bone_data_get_setup_pose(spine_bone_data self);
SPINE_C_API const char* spine_bone_data_get_name(spine_bone_data self);
SPINE_C_API bool spine_bone_data_is_skin_required(spine_bone_data self);
SPINE_C_API void spine_bone_data_set_skin_required(spine_bone_data self, bool skinRequired);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_BONE_DATA_H */