#ifndef SPINE_SPINE_SKELETON_DATA_H
#define SPINE_SPINE_SKELETON_DATA_H

#include "../base.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_skeleton_data spine_skeleton_data_create(void);

SPINE_C_API void spine_skeleton_data_dispose(spine_skeleton_data self);

SPINE_C_API spine_bone_data spine_skeleton_data_find_bone(spine_skeleton_data self, const char* boneName);
SPINE_C_API spine_slot_data spine_skeleton_data_find_slot(spine_skeleton_data self, const char* slotName);
SPINE_C_API spine_skin spine_skeleton_data_find_skin(spine_skeleton_data self, const char* skinName);
SPINE_C_API spine_event_data spine_skeleton_data_find_event(spine_skeleton_data self, const char* eventDataName);
SPINE_C_API spine_animation spine_skeleton_data_find_animation(spine_skeleton_data self, const char* animationName);
SPINE_C_API spine_ik_constraint_data spine_skeleton_data_find_ik_constraint(spine_skeleton_data self, const char* constraintName);
SPINE_C_API spine_transform_constraint_data spine_skeleton_data_find_transform_constraint(spine_skeleton_data self, const char* constraintName);
SPINE_C_API spine_path_constraint_data spine_skeleton_data_find_path_constraint(spine_skeleton_data self, const char* constraintName);
SPINE_C_API spine_physics_constraint_data spine_skeleton_data_find_physics_constraint(spine_skeleton_data self, const char* constraintName);
SPINE_C_API const char* spine_skeleton_data_get_name(spine_skeleton_data self);
SPINE_C_API void spine_skeleton_data_set_name(spine_skeleton_data self, const char* inValue);
SPINE_C_API spine_array_bone_data spine_skeleton_data_get_bones(spine_skeleton_data self);
SPINE_C_API spine_array_slot_data spine_skeleton_data_get_slots(spine_skeleton_data self);
SPINE_C_API spine_array_skin spine_skeleton_data_get_skins(spine_skeleton_data self);
SPINE_C_API spine_skin spine_skeleton_data_get_default_skin(spine_skeleton_data self);
SPINE_C_API void spine_skeleton_data_set_default_skin(spine_skeleton_data self, spine_skin inValue);
SPINE_C_API spine_array_event_data spine_skeleton_data_get_events(spine_skeleton_data self);
SPINE_C_API spine_array_animation spine_skeleton_data_get_animations(spine_skeleton_data self);
SPINE_C_API spine_array_ik_constraint_data spine_skeleton_data_get_ik_constraints(spine_skeleton_data self);
SPINE_C_API spine_array_transform_constraint_data spine_skeleton_data_get_transform_constraints(spine_skeleton_data self);
SPINE_C_API spine_array_path_constraint_data spine_skeleton_data_get_path_constraints(spine_skeleton_data self);
SPINE_C_API spine_array_physics_constraint_data spine_skeleton_data_get_physics_constraints(spine_skeleton_data self);
SPINE_C_API spine_array_constraint_data spine_skeleton_data_get_constraints(spine_skeleton_data self);
SPINE_C_API float spine_skeleton_data_get_x(spine_skeleton_data self);
SPINE_C_API void spine_skeleton_data_set_x(spine_skeleton_data self, float inValue);
SPINE_C_API float spine_skeleton_data_get_y(spine_skeleton_data self);
SPINE_C_API void spine_skeleton_data_set_y(spine_skeleton_data self, float inValue);
SPINE_C_API float spine_skeleton_data_get_width(spine_skeleton_data self);
SPINE_C_API void spine_skeleton_data_set_width(spine_skeleton_data self, float inValue);
SPINE_C_API float spine_skeleton_data_get_height(spine_skeleton_data self);
SPINE_C_API void spine_skeleton_data_set_height(spine_skeleton_data self, float inValue);
SPINE_C_API float spine_skeleton_data_get_reference_scale(spine_skeleton_data self);
SPINE_C_API void spine_skeleton_data_set_reference_scale(spine_skeleton_data self, float inValue);
SPINE_C_API const char* spine_skeleton_data_get_version(spine_skeleton_data self);
SPINE_C_API void spine_skeleton_data_set_version(spine_skeleton_data self, const char* inValue);
SPINE_C_API const char* spine_skeleton_data_get_hash(spine_skeleton_data self);
SPINE_C_API void spine_skeleton_data_set_hash(spine_skeleton_data self, const char* inValue);
SPINE_C_API const char* spine_skeleton_data_get_images_path(spine_skeleton_data self);
SPINE_C_API void spine_skeleton_data_set_images_path(spine_skeleton_data self, const char* inValue);
SPINE_C_API const char* spine_skeleton_data_get_audio_path(spine_skeleton_data self);
SPINE_C_API void spine_skeleton_data_set_audio_path(spine_skeleton_data self, const char* inValue);
SPINE_C_API float spine_skeleton_data_get_fps(spine_skeleton_data self);
SPINE_C_API void spine_skeleton_data_set_fps(spine_skeleton_data self, float inValue);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_SKELETON_DATA_H */
