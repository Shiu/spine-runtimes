#ifndef SPINE_SPINE_CURVE_TIMELINE1_H
#define SPINE_SPINE_CURVE_TIMELINE1_H

#include "../base.h"
#include "types.h"
#include "arrays.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API void spine_curve_timeline1_dispose(spine_curve_timeline1 self);

SPINE_C_API spine_rtti spine_curve_timeline1_get_rtti(spine_curve_timeline1 self);
SPINE_C_API void spine_curve_timeline1_set_frame(spine_curve_timeline1 self, size_t frame, float time, float value);
SPINE_C_API float spine_curve_timeline1_get_curve_value(spine_curve_timeline1 self, float time);
SPINE_C_API float spine_curve_timeline1_get_relative_value(spine_curve_timeline1 self, float time, float alpha, spine_mix_blend blend, float current,
														   float setup);
SPINE_C_API float spine_curve_timeline1_get_absolute_value_1(spine_curve_timeline1 self, float time, float alpha, spine_mix_blend blend,
															 float current, float setup);
SPINE_C_API float spine_curve_timeline1_get_absolute_value_2(spine_curve_timeline1 self, float time, float alpha, spine_mix_blend blend,
															 float current, float setup, float value);
SPINE_C_API float spine_curve_timeline1_get_scale_value(spine_curve_timeline1 self, float time, float alpha, spine_mix_blend blend,
														spine_mix_direction direction, float current, float setup);
SPINE_C_API void spine_curve_timeline1_set_linear(spine_curve_timeline1 self, size_t frame);
SPINE_C_API void spine_curve_timeline1_set_stepped(spine_curve_timeline1 self, size_t frame);
SPINE_C_API void spine_curve_timeline1_set_bezier(spine_curve_timeline1 self, size_t bezier, size_t frame, float value, float time1, float value1,
												  float cx1, float cy1, float cx2, float cy2, float time2, float value2);
SPINE_C_API float spine_curve_timeline1_get_bezier_value(spine_curve_timeline1 self, float time, size_t frame, size_t valueOffset, size_t i);
SPINE_C_API spine_array_float spine_curve_timeline1_get_curves(spine_curve_timeline1 self);
SPINE_C_API void spine_curve_timeline1_apply(spine_curve_timeline1 self, spine_skeleton skeleton, float lastTime, float time,
											 spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction,
											 bool appliedPose);
SPINE_C_API size_t spine_curve_timeline1_get_frame_entries(spine_curve_timeline1 self);
SPINE_C_API size_t spine_curve_timeline1_get_frame_count(spine_curve_timeline1 self);
SPINE_C_API spine_array_float spine_curve_timeline1_get_frames(spine_curve_timeline1 self);
SPINE_C_API float spine_curve_timeline1_get_duration(spine_curve_timeline1 self);
SPINE_C_API spine_array_property_id spine_curve_timeline1_get_property_ids(spine_curve_timeline1 self);
SPINE_C_API spine_rtti spine_curve_timeline1_rtti(void);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_CURVE_TIMELINE1_H */
