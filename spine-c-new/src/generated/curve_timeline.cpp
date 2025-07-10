#include "curve_timeline.h"
#include <spine/spine.h>

using namespace spine;

void spine_curve_timeline_dispose(spine_curve_timeline self) {
    delete (CurveTimeline*)self;
}

spine_rtti spine_curve_timeline_get_rtti(spine_curve_timeline self) {
    return (spine_rtti)&((CurveTimeline*)self)->getRTTI();
}

void spine_curve_timeline_set_linear(spine_curve_timeline self, size_t frame) {
    ((CurveTimeline*)self)->setLinear(frame);
}

void spine_curve_timeline_set_stepped(spine_curve_timeline self, size_t frame) {
    ((CurveTimeline*)self)->setStepped(frame);
}

void spine_curve_timeline_set_bezier(spine_curve_timeline self, size_t bezier, size_t frame, float value, float time1, float value1, float cx1, float cy1, float cx2, float cy2, float time2, float value2) {
    ((CurveTimeline*)self)->setBezier(bezier, frame, value, time1, value1, cx1, cy1, cx2, cy2, time2, value2);
}

float spine_curve_timeline_get_bezier_value(spine_curve_timeline self, float time, size_t frame, size_t valueOffset, size_t i) {
    return ((CurveTimeline*)self)->getBezierValue(time, frame, valueOffset, i);
}

spine_array_float spine_curve_timeline_get_curves(spine_curve_timeline self) {
    return (spine_array_float)&((CurveTimeline*)self)->getCurves();
}

void spine_curve_timeline_apply(spine_curve_timeline self, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    ((Timeline*)(CurveTimeline*)self)->apply(*((Skeleton*)skeleton), lastTime, time, (Array<Event *> *)pEvents, alpha, (MixBlend)blend, (MixDirection)direction, appliedPose);
}

size_t spine_curve_timeline_get_frame_entries(spine_curve_timeline self) {
    return ((Timeline*)(CurveTimeline*)self)->getFrameEntries();
}

size_t spine_curve_timeline_get_frame_count(spine_curve_timeline self) {
    return ((Timeline*)(CurveTimeline*)self)->getFrameCount();
}

spine_array_float spine_curve_timeline_get_frames(spine_curve_timeline self) {
    return (spine_array_float)&((Timeline*)(CurveTimeline*)self)->getFrames();
}

float spine_curve_timeline_get_duration(spine_curve_timeline self) {
    return ((Timeline*)(CurveTimeline*)self)->getDuration();
}

spine_array_property_id spine_curve_timeline_get_property_ids(spine_curve_timeline self) {
    return (spine_array_property_id)&((Timeline*)(CurveTimeline*)self)->getPropertyIds();
}

spine_rtti spine_curve_timeline_rtti(void) {
    return (spine_rtti)&CurveTimeline::rtti;
}
