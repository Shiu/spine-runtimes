#include "curve_timeline2.h"
#include <spine/spine.h>

using namespace spine;

void spine_curve_timeline2_dispose(spine_curve_timeline2 self) {
    delete (CurveTimeline2*)self;
}

spine_rtti spine_curve_timeline2_get_rtti(spine_curve_timeline2 self) {
    return (spine_rtti)&((CurveTimeline2*)self)->getRTTI();
}

void spine_curve_timeline2_set_frame(spine_curve_timeline2 self, size_t frame, float time, float value1, float value2) {
    ((CurveTimeline2*)self)->setFrame(frame, time, value1, value2);
}

float spine_curve_timeline2_get_curve_value(spine_curve_timeline2 self, float time) {
    return ((CurveTimeline2*)self)->getCurveValue(time);
}

void spine_curve_timeline2_set_linear(spine_curve_timeline2 self, size_t frame) {
    ((CurveTimeline*)(CurveTimeline2*)self)->setLinear(frame);
}

void spine_curve_timeline2_set_stepped(spine_curve_timeline2 self, size_t frame) {
    ((CurveTimeline*)(CurveTimeline2*)self)->setStepped(frame);
}

void spine_curve_timeline2_set_bezier(spine_curve_timeline2 self, size_t bezier, size_t frame, float value, float time1, float value1, float cx1, float cy1, float cx2, float cy2, float time2, float value2) {
    ((CurveTimeline*)(CurveTimeline2*)self)->setBezier(bezier, frame, value, time1, value1, cx1, cy1, cx2, cy2, time2, value2);
}

float spine_curve_timeline2_get_bezier_value(spine_curve_timeline2 self, float time, size_t frame, size_t valueOffset, size_t i) {
    return ((CurveTimeline*)(CurveTimeline2*)self)->getBezierValue(time, frame, valueOffset, i);
}

spine_array_float spine_curve_timeline2_get_curves(spine_curve_timeline2 self) {
    return (spine_array_float)&((CurveTimeline*)(CurveTimeline2*)self)->getCurves();
}

void spine_curve_timeline2_apply(spine_curve_timeline2 self, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    ((CurveTimeline*)(CurveTimeline2*)self)->apply(*((Skeleton*)skeleton), lastTime, time, (Array<Event *> *)pEvents, alpha, (MixBlend)blend, (MixDirection)direction, appliedPose);
}

size_t spine_curve_timeline2_get_frame_entries(spine_curve_timeline2 self) {
    return ((CurveTimeline*)(CurveTimeline2*)self)->getFrameEntries();
}

size_t spine_curve_timeline2_get_frame_count(spine_curve_timeline2 self) {
    return ((CurveTimeline*)(CurveTimeline2*)self)->getFrameCount();
}

spine_array_float spine_curve_timeline2_get_frames(spine_curve_timeline2 self) {
    return (spine_array_float)&((CurveTimeline*)(CurveTimeline2*)self)->getFrames();
}

float spine_curve_timeline2_get_duration(spine_curve_timeline2 self) {
    return ((CurveTimeline*)(CurveTimeline2*)self)->getDuration();
}

spine_array_property_id spine_curve_timeline2_get_property_ids(spine_curve_timeline2 self) {
    return (spine_array_property_id)&((CurveTimeline*)(CurveTimeline2*)self)->getPropertyIds();
}

spine_rtti spine_curve_timeline2_rtti(void) {
    return (spine_rtti)&CurveTimeline2::rtti;
}
