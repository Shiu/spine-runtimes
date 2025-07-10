#ifndef SPINE_SPINE_PHYSICS_CONSTRAINT_H
#define SPINE_SPINE_PHYSICS_CONSTRAINT_H

#include "../base.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_physics_constraint spine_physics_constraint_create(spine_physics_constraint_data data, spine_skeleton skeleton);

SPINE_C_API void spine_physics_constraint_dispose(spine_physics_constraint self);

SPINE_C_API spine_rtti spine_physics_constraint_get_rtti(spine_physics_constraint self);
SPINE_C_API void spine_physics_constraint_update(spine_physics_constraint self, spine_skeleton skeleton, spine_physics physics);
SPINE_C_API void spine_physics_constraint_sort(spine_physics_constraint self, spine_skeleton skeleton);
SPINE_C_API bool spine_physics_constraint_is_source_active(spine_physics_constraint self);
SPINE_C_API spine_physics_constraint spine_physics_constraint_copy(spine_physics_constraint self, spine_skeleton skeleton);
SPINE_C_API void spine_physics_constraint_reset(spine_physics_constraint self, spine_skeleton skeleton);
SPINE_C_API void spine_physics_constraint_translate(spine_physics_constraint self, float x, float y);
SPINE_C_API void spine_physics_constraint_rotate(spine_physics_constraint self, float x, float y, float degrees);
SPINE_C_API spine_bone_pose spine_physics_constraint_get_bone(spine_physics_constraint self);
SPINE_C_API void spine_physics_constraint_set_bone(spine_physics_constraint self, spine_bone_pose bone);
SPINE_C_API spine_constraint_data spine_physics_constraint_get_data(spine_physics_constraint self);
SPINE_C_API spine_physics_constraint_pose spine_physics_constraint_get_pose(spine_physics_constraint self);
SPINE_C_API spine_physics_constraint_pose spine_physics_constraint_get_applied_pose(spine_physics_constraint self);
SPINE_C_API void spine_physics_constraint_reset_constrained(spine_physics_constraint self);
SPINE_C_API void spine_physics_constraint_constrained(spine_physics_constraint self);
SPINE_C_API bool spine_physics_constraint_is_pose_equal_to_applied(spine_physics_constraint self);
SPINE_C_API bool spine_physics_constraint_is_active(spine_physics_constraint self);
SPINE_C_API void spine_physics_constraint_set_active(spine_physics_constraint self, bool active);
SPINE_C_API spine_rtti spine_physics_constraint_rtti(void);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_PHYSICS_CONSTRAINT_H */