#ifndef SPINE_SPINE_BONE_POSE_H
#define SPINE_SPINE_BONE_POSE_H

#include "../base.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_bone_pose spine_bone_pose_create(void);

SPINE_C_API void spine_bone_pose_dispose(spine_bone_pose self);

SPINE_C_API void spine_bone_pose_update(spine_bone_pose self, spine_skeleton skeleton, spine_physics physics);
SPINE_C_API void spine_bone_pose_update_world_transform(spine_bone_pose self, spine_skeleton skeleton);
SPINE_C_API void spine_bone_pose_update_local_transform(spine_bone_pose self, spine_skeleton skeleton);
SPINE_C_API void spine_bone_pose_validate_local_transform(spine_bone_pose self, spine_skeleton skeleton);
SPINE_C_API void spine_bone_pose_modify_local(spine_bone_pose self, spine_skeleton skeleton);
SPINE_C_API void spine_bone_pose_modify_world(spine_bone_pose self, int update);
SPINE_C_API void spine_bone_pose_reset_world(spine_bone_pose self, int update);
SPINE_C_API float spine_bone_pose_get_a(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_set_a(spine_bone_pose self, float a);
SPINE_C_API float spine_bone_pose_get_b(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_set_b(spine_bone_pose self, float b);
SPINE_C_API float spine_bone_pose_get_c(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_set_c(spine_bone_pose self, float c);
SPINE_C_API float spine_bone_pose_get_d(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_set_d(spine_bone_pose self, float d);
SPINE_C_API float spine_bone_pose_get_world_x(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_set_world_x(spine_bone_pose self, float worldX);
SPINE_C_API float spine_bone_pose_get_world_y(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_set_world_y(spine_bone_pose self, float worldY);
SPINE_C_API float spine_bone_pose_get_world_rotation_x(spine_bone_pose self);
SPINE_C_API float spine_bone_pose_get_world_rotation_y(spine_bone_pose self);
SPINE_C_API float spine_bone_pose_get_world_scale_x(spine_bone_pose self);
SPINE_C_API float spine_bone_pose_get_world_scale_y(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_world_to_local(spine_bone_pose self, float worldX, float worldY, float* outLocalX, float* outLocalY);
SPINE_C_API void spine_bone_pose_local_to_world(spine_bone_pose self, float localX, float localY, float* outWorldX, float* outWorldY);
SPINE_C_API void spine_bone_pose_world_to_parent(spine_bone_pose self, float worldX, float worldY, float* outParentX, float* outParentY);
SPINE_C_API void spine_bone_pose_parent_to_world(spine_bone_pose self, float parentX, float parentY, float* outWorldX, float* outWorldY);
SPINE_C_API float spine_bone_pose_world_to_local_rotation(spine_bone_pose self, float worldRotation);
SPINE_C_API float spine_bone_pose_local_to_world_rotation(spine_bone_pose self, float localRotation);
SPINE_C_API void spine_bone_pose_rotate_world(spine_bone_pose self, float degrees);
SPINE_C_API void spine_bone_pose_set(spine_bone_pose self, spine_bone_local pose);
SPINE_C_API float spine_bone_pose_get_x(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_set_x(spine_bone_pose self, float x);
SPINE_C_API float spine_bone_pose_get_y(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_set_y(spine_bone_pose self, float y);
SPINE_C_API void spine_bone_pose_set_position(spine_bone_pose self, float x, float y);
SPINE_C_API float spine_bone_pose_get_rotation(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_set_rotation(spine_bone_pose self, float rotation);
SPINE_C_API float spine_bone_pose_get_scale_x(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_set_scale_x(spine_bone_pose self, float scaleX);
SPINE_C_API float spine_bone_pose_get_scale_y(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_set_scale_y(spine_bone_pose self, float scaleY);
SPINE_C_API void spine_bone_pose_set_scale_1(spine_bone_pose self, float scaleX, float scaleY);
SPINE_C_API void spine_bone_pose_set_scale_2(spine_bone_pose self, float scale);
SPINE_C_API float spine_bone_pose_get_shear_x(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_set_shear_x(spine_bone_pose self, float shearX);
SPINE_C_API float spine_bone_pose_get_shear_y(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_set_shear_y(spine_bone_pose self, float shearY);
SPINE_C_API spine_inherit spine_bone_pose_get_inherit(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_set_inherit(spine_bone_pose self, spine_inherit inherit);
SPINE_C_API spine_rtti spine_bone_pose_get_rtti(spine_bone_pose self);
SPINE_C_API spine_rtti spine_bone_pose_rtti(void);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_BONE_POSE_H */