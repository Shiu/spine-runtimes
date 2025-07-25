#ifndef SPINE_SPINE_PATH_CONSTRAINT_H
#define SPINE_SPINE_PATH_CONSTRAINT_H

#include "../base.h"
#include "types.h"
#include "arrays.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_path_constraint spine_path_constraint_create(spine_path_constraint_data data, spine_skeleton skeleton);

SPINE_C_API void spine_path_constraint_dispose(spine_path_constraint self);

SPINE_C_API spine_rtti spine_path_constraint_get_rtti(spine_path_constraint self);
SPINE_C_API spine_path_constraint spine_path_constraint_copy(spine_path_constraint self, spine_skeleton skeleton);
SPINE_C_API void spine_path_constraint_update(spine_path_constraint self, spine_skeleton skeleton, spine_physics physics);
SPINE_C_API void spine_path_constraint_sort(spine_path_constraint self, spine_skeleton skeleton);
SPINE_C_API bool spine_path_constraint_is_source_active(spine_path_constraint self);
SPINE_C_API /*@null*/ spine_array_bone_pose spine_path_constraint_get_bones(spine_path_constraint self);
SPINE_C_API spine_slot spine_path_constraint_get_slot(spine_path_constraint self);
SPINE_C_API void spine_path_constraint_set_slot(spine_path_constraint self, spine_slot slot);
SPINE_C_API spine_path_constraint_data spine_path_constraint_get_data(spine_path_constraint self);
SPINE_C_API spine_path_constraint_pose spine_path_constraint_get_pose(spine_path_constraint self);
SPINE_C_API spine_path_constraint_pose spine_path_constraint_get_applied_pose(spine_path_constraint self);
SPINE_C_API void spine_path_constraint_reset_constrained(spine_path_constraint self);
SPINE_C_API void spine_path_constraint_constrained(spine_path_constraint self);
SPINE_C_API bool spine_path_constraint_is_pose_equal_to_applied(spine_path_constraint self);
SPINE_C_API bool spine_path_constraint_is_active(spine_path_constraint self);
SPINE_C_API void spine_path_constraint_set_active(spine_path_constraint self, bool active);
SPINE_C_API spine_rtti spine_path_constraint_rtti(void);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_PATH_CONSTRAINT_H */
