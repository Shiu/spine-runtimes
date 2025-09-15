#ifndef SPINE_SPINE_IK_CONSTRAINT_H
#define SPINE_SPINE_IK_CONSTRAINT_H

#include "../base.h"
#include "types.h"
#include "arrays.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_ik_constraint spine_ik_constraint_create(spine_ik_constraint_data data, spine_skeleton skeleton);

SPINE_C_API void spine_ik_constraint_dispose(spine_ik_constraint self);

SPINE_C_API spine_rtti spine_ik_constraint_get_rtti(spine_ik_constraint self);
SPINE_C_API spine_ik_constraint spine_ik_constraint_copy(spine_ik_constraint self, spine_skeleton skeleton);
SPINE_C_API void spine_ik_constraint_update(spine_ik_constraint self, spine_skeleton skeleton, spine_physics physics);
SPINE_C_API void spine_ik_constraint_sort(spine_ik_constraint self, spine_skeleton skeleton);
SPINE_C_API bool spine_ik_constraint_is_source_active(spine_ik_constraint self);
SPINE_C_API spine_array_bone_pose spine_ik_constraint_get_bones(spine_ik_constraint self);
SPINE_C_API spine_bone spine_ik_constraint_get_target(spine_ik_constraint self);
SPINE_C_API void spine_ik_constraint_set_target(spine_ik_constraint self, spine_bone inValue);
/**
 * Adjusts the bone rotation so the tip is as close to the target position as
 * possible. The target is specified in the world coordinate system.
 */
SPINE_C_API void spine_ik_constraint_apply_1(spine_skeleton skeleton, spine_bone_pose bone, float targetX, float targetY, bool compress, bool stretch,
											 bool uniform, float mix);
/**
 * Adjusts the parent and child bone rotations so the tip of the child is as
 * close to the target position as possible. The target is specified in the
 * world coordinate system.
 *
 * @param child A direct descendant of the parent bone.
 */
SPINE_C_API void spine_ik_constraint_apply_2(spine_skeleton skeleton, spine_bone_pose parent, spine_bone_pose child, float targetX, float targetY,
											 int bendDirection, bool stretch, bool uniform, float softness, float mix);
SPINE_C_API spine_ik_constraint_data spine_ik_constraint_get_data(spine_ik_constraint self);
SPINE_C_API spine_ik_constraint_pose spine_ik_constraint_get_pose(spine_ik_constraint self);
SPINE_C_API spine_ik_constraint_pose spine_ik_constraint_get_applied_pose(spine_ik_constraint self);
SPINE_C_API void spine_ik_constraint_reset_constrained(spine_ik_constraint self);
SPINE_C_API void spine_ik_constraint_constrained(spine_ik_constraint self);
SPINE_C_API bool spine_ik_constraint_is_pose_equal_to_applied(spine_ik_constraint self);
SPINE_C_API bool spine_ik_constraint_is_active(spine_ik_constraint self);
SPINE_C_API void spine_ik_constraint_set_active(spine_ik_constraint self, bool active);
SPINE_C_API spine_rtti spine_ik_constraint_rtti(void);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_IK_CONSTRAINT_H */
