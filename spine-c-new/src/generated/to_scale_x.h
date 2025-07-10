#ifndef SPINE_SPINE_TO_SCALE_X_H
#define SPINE_SPINE_TO_SCALE_X_H

#include "../base.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_to_scale_x spine_to_scale_x_create(void);

SPINE_C_API void spine_to_scale_x_dispose(spine_to_scale_x self);

SPINE_C_API float spine_to_scale_x_mix(spine_to_scale_x self, spine_transform_constraint_pose pose);
SPINE_C_API void spine_to_scale_x_apply(spine_to_scale_x self, spine_skeleton skeleton, spine_transform_constraint_pose pose, spine_bone_pose bone, float value, bool local, bool additive);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_TO_SCALE_X_H */