#ifndef SPINE_SPINE_ANIMATION_STATE_DATA_H
#define SPINE_SPINE_ANIMATION_STATE_DATA_H

#include "../base.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_animation_state_data spine_animation_state_data_create(spine_skeleton_data skeletonData);

SPINE_C_API void spine_animation_state_data_dispose(spine_animation_state_data self);

SPINE_C_API spine_skeleton_data spine_animation_state_data_get_skeleton_data(spine_animation_state_data self);
SPINE_C_API float spine_animation_state_data_get_default_mix(spine_animation_state_data self);
SPINE_C_API void spine_animation_state_data_set_default_mix(spine_animation_state_data self, float inValue);
SPINE_C_API void spine_animation_state_data_set_mix_1(spine_animation_state_data self, const char * fromName, const char * toName, float duration);
SPINE_C_API void spine_animation_state_data_set_mix_2(spine_animation_state_data self, spine_animation from, spine_animation to, float duration);
SPINE_C_API float spine_animation_state_data_get_mix(spine_animation_state_data self, spine_animation from, spine_animation to);
SPINE_C_API void spine_animation_state_data_clear(spine_animation_state_data self);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_ANIMATION_STATE_DATA_H */
