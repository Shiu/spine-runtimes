#ifndef SPINE_SPINE_SLIDER_POSE_H
#define SPINE_SPINE_SLIDER_POSE_H

#include "../base.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_slider_pose spine_slider_pose_create(void);

SPINE_C_API void spine_slider_pose_dispose(spine_slider_pose self);

SPINE_C_API void spine_slider_pose_set(spine_slider_pose self, spine_slider_pose pose);
SPINE_C_API float spine_slider_pose_get_time(spine_slider_pose self);
SPINE_C_API void spine_slider_pose_set_time(spine_slider_pose self, float time);
SPINE_C_API float spine_slider_pose_get_mix(spine_slider_pose self);
SPINE_C_API void spine_slider_pose_set_mix(spine_slider_pose self, float mix);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_SLIDER_POSE_H */
