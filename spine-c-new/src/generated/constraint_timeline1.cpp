#include "constraint_timeline1.h"
#include <spine/spine.h>

using namespace spine;

void spine_constraint_timeline1_dispose(spine_constraint_timeline1 self) {
    delete (ConstraintTimeline1*)self;
}

spine_rtti spine_constraint_timeline1_get_rtti(spine_constraint_timeline1 self) {
    return (spine_rtti)&((ConstraintTimeline1*)self)->getRTTI();
}

void spine_constraint_timeline1_set_frame(spine_constraint_timeline1 self, size_t frame, float time, float value) {
    ((CurveTimeline1*)(ConstraintTimeline1*)self)->setFrame(frame, time, value);
}

float spine_constraint_timeline1_get_curve_value(spine_constraint_timeline1 self, float time) {
    return ((CurveTimeline1*)(ConstraintTimeline1*)self)->getCurveValue(time);
}

float spine_constraint_timeline1_get_relative_value(spine_constraint_timeline1 self, float time, float alpha, spine_mix_blend blend, float current, float setup) {
    return ((CurveTimeline1*)(ConstraintTimeline1*)self)->getRelativeValue(time, alpha, (MixBlend)blend, current, setup);
}

float spine_constraint_timeline1_get_absolute_value_1(spine_constraint_timeline1 self, float time, float alpha, spine_mix_blend blend, float current, float setup) {
    return ((CurveTimeline1*)(ConstraintTimeline1*)self)->getAbsoluteValue(time, alpha, (MixBlend)blend, current, setup);
}

float spine_constraint_timeline1_get_absolute_value_2(spine_constraint_timeline1 self, float time, float alpha, spine_mix_blend blend, float current, float setup, float value) {
    return ((CurveTimeline1*)(ConstraintTimeline1*)self)->getAbsoluteValue(time, alpha, (MixBlend)blend, current, setup, value);
}

float spine_constraint_timeline1_get_scale_value(spine_constraint_timeline1 self, float time, float alpha, spine_mix_blend blend, spine_mix_direction direction, float current, float setup) {
    return ((CurveTimeline1*)(ConstraintTimeline1*)self)->getScaleValue(time, alpha, (MixBlend)blend, (MixDirection)direction, current, setup);
}

void spine_constraint_timeline1_set_linear(spine_constraint_timeline1 self, size_t frame) {
    ((CurveTimeline1*)(ConstraintTimeline1*)self)->setLinear(frame);
}

void spine_constraint_timeline1_set_stepped(spine_constraint_timeline1 self, size_t frame) {
    ((CurveTimeline1*)(ConstraintTimeline1*)self)->setStepped(frame);
}

void spine_constraint_timeline1_set_bezier(spine_constraint_timeline1 self, size_t bezier, size_t frame, float value, float time1, float value1, float cx1, float cy1, float cx2, float cy2, float time2, float value2) {
    ((CurveTimeline1*)(ConstraintTimeline1*)self)->setBezier(bezier, frame, value, time1, value1, cx1, cy1, cx2, cy2, time2, value2);
}

float spine_constraint_timeline1_get_bezier_value(spine_constraint_timeline1 self, float time, size_t frame, size_t valueOffset, size_t i) {
    return ((CurveTimeline1*)(ConstraintTimeline1*)self)->getBezierValue(time, frame, valueOffset, i);
}

spine_array_float spine_constraint_timeline1_get_curves(spine_constraint_timeline1 self) {
    return (spine_array_float)&((CurveTimeline1*)(ConstraintTimeline1*)self)->getCurves();
}

void spine_constraint_timeline1_apply(spine_constraint_timeline1 self, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    ((CurveTimeline1*)(ConstraintTimeline1*)self)->apply(*((Skeleton*)skeleton), lastTime, time, (Array<Event *> *)pEvents, alpha, (MixBlend)blend, (MixDirection)direction, appliedPose);
}

size_t spine_constraint_timeline1_get_frame_entries(spine_constraint_timeline1 self) {
    return ((CurveTimeline1*)(ConstraintTimeline1*)self)->getFrameEntries();
}

size_t spine_constraint_timeline1_get_frame_count(spine_constraint_timeline1 self) {
    return ((CurveTimeline1*)(ConstraintTimeline1*)self)->getFrameCount();
}

spine_array_float spine_constraint_timeline1_get_frames(spine_constraint_timeline1 self) {
    return (spine_array_float)&((CurveTimeline1*)(ConstraintTimeline1*)self)->getFrames();
}

float spine_constraint_timeline1_get_duration(spine_constraint_timeline1 self) {
    return ((CurveTimeline1*)(ConstraintTimeline1*)self)->getDuration();
}

spine_array_property_id spine_constraint_timeline1_get_property_ids(spine_constraint_timeline1 self) {
    return (spine_array_property_id)&((CurveTimeline1*)(ConstraintTimeline1*)self)->getPropertyIds();
}

int spine_constraint_timeline1_get_constraint_index(spine_constraint_timeline1 self) {
    return ((ConstraintTimeline*)(ConstraintTimeline1*)self)->getConstraintIndex();
}

void spine_constraint_timeline1_set_constraint_index(spine_constraint_timeline1 self, int inValue) {
    ((ConstraintTimeline*)(ConstraintTimeline1*)self)->setConstraintIndex(inValue);
}

spine_rtti spine_constraint_timeline1_rtti(void) {
    return (spine_rtti)&ConstraintTimeline1::rtti;
}
