#ifndef SPINE_SPINE_BONE_POSE_H
#define SPINE_SPINE_BONE_POSE_H

#include "../base.h"
#include "types.h"
#include "arrays.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_bone_pose spine_bone_pose_create(void);

SPINE_C_API void spine_bone_pose_dispose(spine_bone_pose self);

SPINE_C_API spine_rtti spine_bone_pose_get_rtti(spine_bone_pose self);
/**
 * Called by Skeleton::updateCache() to compute the world transform, if needed.
 */
SPINE_C_API void spine_bone_pose_update(spine_bone_pose self, spine_skeleton skeleton, spine_physics physics);
/**
 * Computes the world transform using the parent bone's applied pose and this
 * pose. Child bones are not updated.
 *
 * See World transforms in the Spine Runtimes Guide.
 */
SPINE_C_API void spine_bone_pose_update_world_transform(spine_bone_pose self, spine_skeleton skeleton);
/**
 * Computes the local transform values from the world transform.
 *
 * If the world transform is modified (by a constraint, rotateWorld(), etc) then
 * this method should be called so the local transform matches the world
 * transform. The local transform may be needed by other code (eg to apply
 * another constraint).
 *
 * Some information is ambiguous in the world transform, such as -1,-1 scale
 * versus 180 rotation. The local transform after calling this method is
 * equivalent to the local transform used to compute the world transform, but
 * may not be identical.
 */
SPINE_C_API void spine_bone_pose_update_local_transform(spine_bone_pose self, spine_skeleton skeleton);
/**
 * If the world transform has been modified and the local transform no longer
 * matches, updateLocalTransform() is called.
 */
SPINE_C_API void spine_bone_pose_validate_local_transform(spine_bone_pose self, spine_skeleton skeleton);
SPINE_C_API void spine_bone_pose_modify_local(spine_bone_pose self, spine_skeleton skeleton);
SPINE_C_API void spine_bone_pose_modify_world(spine_bone_pose self, int update);
SPINE_C_API void spine_bone_pose_reset_world(spine_bone_pose self, int update);
/**
 * Part of the world transform matrix for the X axis. If changed,
 * updateLocalTransform() should be called.
 */
SPINE_C_API float spine_bone_pose_get_a(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_set_a(spine_bone_pose self, float a);
/**
 * Part of the world transform matrix for the Y axis. If changed,
 * updateLocalTransform() should be called.
 */
SPINE_C_API float spine_bone_pose_get_b(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_set_b(spine_bone_pose self, float b);
/**
 * Part of the world transform matrix for the X axis. If changed,
 * updateLocalTransform() should be called.
 */
SPINE_C_API float spine_bone_pose_get_c(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_set_c(spine_bone_pose self, float c);
/**
 * Part of the world transform matrix for the Y axis. If changed,
 * updateLocalTransform() should be called.
 */
SPINE_C_API float spine_bone_pose_get_d(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_set_d(spine_bone_pose self, float d);
/**
 * The world X position. If changed, updateLocalTransform() should be called.
 */
SPINE_C_API float spine_bone_pose_get_world_x(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_set_world_x(spine_bone_pose self, float worldX);
/**
 * The world Y position. If changed, updateLocalTransform() should be called.
 */
SPINE_C_API float spine_bone_pose_get_world_y(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_set_world_y(spine_bone_pose self, float worldY);
/**
 * The world rotation for the X axis, calculated using a and c.
 */
SPINE_C_API float spine_bone_pose_get_world_rotation_x(spine_bone_pose self);
/**
 * The world rotation for the Y axis, calculated using b and d.
 */
SPINE_C_API float spine_bone_pose_get_world_rotation_y(spine_bone_pose self);
/**
 * The magnitude (always positive) of the world scale X, calculated using a and
 * c.
 */
SPINE_C_API float spine_bone_pose_get_world_scale_x(spine_bone_pose self);
/**
 * The magnitude (always positive) of the world scale Y, calculated using b and
 * d.
 */
SPINE_C_API float spine_bone_pose_get_world_scale_y(spine_bone_pose self);
/**
 * Transforms a point from world coordinates to the bone's local coordinates.
 */
SPINE_C_API void spine_bone_pose_world_to_local(spine_bone_pose self, float worldX, float worldY, float *outLocalX, float *outLocalY);
/**
 * Transforms a point from the bone's local coordinates to world coordinates.
 */
SPINE_C_API void spine_bone_pose_local_to_world(spine_bone_pose self, float localX, float localY, float *outWorldX, float *outWorldY);
/**
 * Transforms a point from world coordinates to the parent bone's local
 * coordinates.
 */
SPINE_C_API void spine_bone_pose_world_to_parent(spine_bone_pose self, float worldX, float worldY, float *outParentX, float *outParentY);
/**
 * Transforms a point from the parent bone's coordinates to world coordinates.
 */
SPINE_C_API void spine_bone_pose_parent_to_world(spine_bone_pose self, float parentX, float parentY, float *outWorldX, float *outWorldY);
/**
 * Transforms a world rotation to a local rotation.
 */
SPINE_C_API float spine_bone_pose_world_to_local_rotation(spine_bone_pose self, float worldRotation);
/**
 * Transforms a local rotation to a world rotation.
 */
SPINE_C_API float spine_bone_pose_local_to_world_rotation(spine_bone_pose self, float localRotation);
/**
 * Rotates the world transform the specified amount.
 *
 * After changes are made to the world transform, updateLocalTransform() should
 * be called on this bone and any child bones, recursively.
 */
SPINE_C_API void spine_bone_pose_rotate_world(spine_bone_pose self, float degrees);
SPINE_C_API void spine_bone_pose_set(spine_bone_pose self, spine_bone_local pose);
/**
 * The local x translation.
 */
SPINE_C_API float spine_bone_pose_get_x(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_set_x(spine_bone_pose self, float x);
/**
 * The local y translation.
 */
SPINE_C_API float spine_bone_pose_get_y(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_set_y(spine_bone_pose self, float y);
SPINE_C_API void spine_bone_pose_set_position(spine_bone_pose self, float x, float y);
/**
 * The local rotation in degrees, counter clockwise.
 */
SPINE_C_API float spine_bone_pose_get_rotation(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_set_rotation(spine_bone_pose self, float rotation);
/**
 * The local scaleX.
 */
SPINE_C_API float spine_bone_pose_get_scale_x(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_set_scale_x(spine_bone_pose self, float scaleX);
/**
 * The local scaleY.
 */
SPINE_C_API float spine_bone_pose_get_scale_y(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_set_scale_y(spine_bone_pose self, float scaleY);
SPINE_C_API void spine_bone_pose_set_scale_1(spine_bone_pose self, float scaleX, float scaleY);
SPINE_C_API void spine_bone_pose_set_scale_2(spine_bone_pose self, float scale);
/**
 * The local shearX.
 */
SPINE_C_API float spine_bone_pose_get_shear_x(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_set_shear_x(spine_bone_pose self, float shearX);
/**
 * The local shearY.
 */
SPINE_C_API float spine_bone_pose_get_shear_y(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_set_shear_y(spine_bone_pose self, float shearY);
/**
 * Determines how parent world transforms affect this bone.
 */
SPINE_C_API spine_inherit spine_bone_pose_get_inherit(spine_bone_pose self);
SPINE_C_API void spine_bone_pose_set_inherit(spine_bone_pose self, spine_inherit inherit);
SPINE_C_API spine_rtti spine_bone_pose_rtti(void);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_BONE_POSE_H */
