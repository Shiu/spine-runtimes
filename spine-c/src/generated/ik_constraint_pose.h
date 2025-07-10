#ifndef SPINE_SPINE_IK_CONSTRAINT_POSE_H
#define SPINE_SPINE_IK_CONSTRAINT_POSE_H

#include "../base.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_ik_constraint_pose spine_ik_constraint_pose_create(void);

SPINE_C_API void spine_ik_constraint_pose_dispose(spine_ik_constraint_pose self);

SPINE_C_API void spine_ik_constraint_pose_set(spine_ik_constraint_pose self, spine_ik_constraint_pose pose);
SPINE_C_API float spine_ik_constraint_pose_get_mix(spine_ik_constraint_pose self);
SPINE_C_API void spine_ik_constraint_pose_set_mix(spine_ik_constraint_pose self, float mix);
SPINE_C_API float spine_ik_constraint_pose_get_softness(spine_ik_constraint_pose self);
SPINE_C_API void spine_ik_constraint_pose_set_softness(spine_ik_constraint_pose self, float softness);
SPINE_C_API int spine_ik_constraint_pose_get_bend_direction(spine_ik_constraint_pose self);
SPINE_C_API void spine_ik_constraint_pose_set_bend_direction(spine_ik_constraint_pose self, int bendDirection);
SPINE_C_API bool spine_ik_constraint_pose_get_compress(spine_ik_constraint_pose self);
SPINE_C_API void spine_ik_constraint_pose_set_compress(spine_ik_constraint_pose self, bool compress);
SPINE_C_API bool spine_ik_constraint_pose_get_stretch(spine_ik_constraint_pose self);
SPINE_C_API void spine_ik_constraint_pose_set_stretch(spine_ik_constraint_pose self, bool stretch);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_IK_CONSTRAINT_POSE_H */
