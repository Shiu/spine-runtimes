#ifndef SPINE_SPINE_FROM_SHEAR_Y_H
#define SPINE_SPINE_FROM_SHEAR_Y_H

#include "../base.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_from_shear_y spine_from_shear_y_create(void);

SPINE_C_API void spine_from_shear_y_dispose(spine_from_shear_y self);

SPINE_C_API float spine_from_shear_y_value(spine_from_shear_y self, spine_skeleton skeleton, spine_bone_pose source, bool local, float * offsets);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_FROM_SHEAR_Y_H */
