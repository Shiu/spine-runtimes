#ifndef SPINE_SPINE_CURVE_TIMELINE_H
#define SPINE_SPINE_CURVE_TIMELINE_H

#include "../base.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API void spine_curve_timeline_dispose(spine_curve_timeline self);

SPINE_C_API spine_rtti spine_curve_timeline_get_rtti(spine_curve_timeline self);
SPINE_C_API void spine_curve_timeline_set_linear(spine_curve_timeline self, size_t frame);
SPINE_C_API void spine_curve_timeline_set_stepped(spine_curve_timeline self, size_t frame);
SPINE_C_API void spine_curve_timeline_set_bezier(spine_curve_timeline self, size_t bezier, size_t frame, float value, float time1, float value1,
												 float cx1, float cy1, float cx2, float cy2, float time2, float value2);
SPINE_C_API float spine_curve_timeline_get_bezier_value(spine_curve_timeline self, float time, size_t frame, size_t valueOffset, size_t i);
SPINE_C_API spine_array_float spine_curve_timeline_get_curves(spine_curve_timeline self);
SPINE_C_API void spine_curve_timeline_apply(spine_curve_timeline self, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents,
											float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose);
SPINE_C_API size_t spine_curve_timeline_get_frame_entries(spine_curve_timeline self);
SPINE_C_API size_t spine_curve_timeline_get_frame_count(spine_curve_timeline self);
SPINE_C_API spine_array_float spine_curve_timeline_get_frames(spine_curve_timeline self);
SPINE_C_API float spine_curve_timeline_get_duration(spine_curve_timeline self);
SPINE_C_API spine_array_property_id spine_curve_timeline_get_property_ids(spine_curve_timeline self);
SPINE_C_API spine_rtti spine_curve_timeline_rtti(void);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_CURVE_TIMELINE_H */
