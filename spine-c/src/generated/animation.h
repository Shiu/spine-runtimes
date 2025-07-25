#ifndef SPINE_SPINE_ANIMATION_H
#define SPINE_SPINE_ANIMATION_H

#include "../base.h"
#include "types.h"
#include "arrays.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_animation spine_animation_create(const char *name, /*@null*/ spine_array_timeline timelines, float duration);

SPINE_C_API void spine_animation_dispose(spine_animation self);

SPINE_C_API /*@null*/ spine_array_timeline spine_animation_get_timelines(spine_animation self);
SPINE_C_API void spine_animation_set_timelines(spine_animation self, /*@null*/ spine_array_timeline timelines);
SPINE_C_API bool spine_animation_has_timeline(spine_animation self, spine_array_property_id ids);
SPINE_C_API float spine_animation_get_duration(spine_animation self);
SPINE_C_API void spine_animation_set_duration(spine_animation self, float inValue);
SPINE_C_API void spine_animation_apply(spine_animation self, spine_skeleton skeleton, float lastTime, float time, bool loop,
									   /*@null*/ spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction,
									   bool appliedPose);
SPINE_C_API const char *spine_animation_get_name(spine_animation self);
SPINE_C_API spine_array_int spine_animation_get_bones(spine_animation self);
SPINE_C_API int spine_animation_search_1(spine_array_float values, float target);
SPINE_C_API int spine_animation_search_2(spine_array_float values, float target, int step);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_ANIMATION_H */
