#ifndef SPINE_SPINE_SLOT_DATA_H
#define SPINE_SPINE_SLOT_DATA_H

#include "../base.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_slot_data spine_slot_data_create(int index, const char* name, spine_bone_data boneData);

SPINE_C_API void spine_slot_data_dispose(spine_slot_data self);

SPINE_C_API int spine_slot_data_get_index(spine_slot_data self);
SPINE_C_API spine_bone_data spine_slot_data_get_bone_data(spine_slot_data self);
SPINE_C_API void spine_slot_data_set_attachment_name(spine_slot_data self, const char* attachmentName);
SPINE_C_API const char* spine_slot_data_get_attachment_name(spine_slot_data self);
SPINE_C_API spine_blend_mode spine_slot_data_get_blend_mode(spine_slot_data self);
SPINE_C_API void spine_slot_data_set_blend_mode(spine_slot_data self, spine_blend_mode blendMode);
SPINE_C_API bool spine_slot_data_get_visible(spine_slot_data self);
SPINE_C_API void spine_slot_data_set_visible(spine_slot_data self, bool visible);
SPINE_C_API spine_slot_pose spine_slot_data_get_setup_pose(spine_slot_data self);
SPINE_C_API const char* spine_slot_data_get_name(spine_slot_data self);
SPINE_C_API bool spine_slot_data_is_skin_required(spine_slot_data self);
SPINE_C_API void spine_slot_data_set_skin_required(spine_slot_data self, bool skinRequired);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_SLOT_DATA_H */