#ifndef SPINE_SPINE_PHYSICS_CONSTRAINT_TIMELINE_H
#define SPINE_SPINE_PHYSICS_CONSTRAINT_TIMELINE_H

#include "../base.h"
#include "types.h"
#include "arrays.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API void spine_physics_constraint_timeline_dispose(spine_physics_constraint_timeline self);

SPINE_C_API spine_rtti spine_physics_constraint_timeline_get_rtti(spine_physics_constraint_timeline self);
SPINE_C_API void spine_physics_constraint_timeline_apply(spine_physics_constraint_timeline self, spine_skeleton skeleton, float lastTime, float time,
														 /*@null*/ spine_array_event events, float alpha, spine_mix_blend blend,
														 spine_mix_direction direction, bool appliedPose);
SPINE_C_API int spine_physics_constraint_timeline_get_constraint_index(spine_physics_constraint_timeline self);
SPINE_C_API void spine_physics_constraint_timeline_set_constraint_index(spine_physics_constraint_timeline self, int inValue);
SPINE_C_API void spine_physics_constraint_timeline_set_frame(spine_physics_constraint_timeline self, size_t frame, float time, float value);
SPINE_C_API float spine_physics_constraint_timeline_get_curve_value(spine_physics_constraint_timeline self, float time);
SPINE_C_API float spine_physics_constraint_timeline_get_relative_value(spine_physics_constraint_timeline self, float time, float alpha,
																	   spine_mix_blend blend, float current, float setup);
SPINE_C_API float spine_physics_constraint_timeline_get_absolute_value_1(spine_physics_constraint_timeline self, float time, float alpha,
																		 spine_mix_blend blend, float current, float setup);
SPINE_C_API float spine_physics_constraint_timeline_get_absolute_value_2(spine_physics_constraint_timeline self, float time, float alpha,
																		 spine_mix_blend blend, float current, float setup, float value);
SPINE_C_API float spine_physics_constraint_timeline_get_scale_value(spine_physics_constraint_timeline self, float time, float alpha,
																	spine_mix_blend blend, spine_mix_direction direction, float current, float setup);
SPINE_C_API void spine_physics_constraint_timeline_set_linear(spine_physics_constraint_timeline self, size_t frame);
SPINE_C_API void spine_physics_constraint_timeline_set_stepped(spine_physics_constraint_timeline self, size_t frame);
SPINE_C_API void spine_physics_constraint_timeline_set_bezier(spine_physics_constraint_timeline self, size_t bezier, size_t frame, float value,
															  float time1, float value1, float cx1, float cy1, float cx2, float cy2, float time2,
															  float value2);
SPINE_C_API float spine_physics_constraint_timeline_get_bezier_value(spine_physics_constraint_timeline self, float time, size_t frame,
																	 size_t valueOffset, size_t i);
SPINE_C_API spine_array_float spine_physics_constraint_timeline_get_curves(spine_physics_constraint_timeline self);
SPINE_C_API size_t spine_physics_constraint_timeline_get_frame_entries(spine_physics_constraint_timeline self);
SPINE_C_API size_t spine_physics_constraint_timeline_get_frame_count(spine_physics_constraint_timeline self);
SPINE_C_API spine_array_float spine_physics_constraint_timeline_get_frames(spine_physics_constraint_timeline self);
SPINE_C_API float spine_physics_constraint_timeline_get_duration(spine_physics_constraint_timeline self);
SPINE_C_API spine_array_property_id spine_physics_constraint_timeline_get_property_ids(spine_physics_constraint_timeline self);
SPINE_C_API spine_rtti spine_physics_constraint_timeline_rtti(void);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_PHYSICS_CONSTRAINT_TIMELINE_H */
