#include "path_constraint_spacing_timeline.h"
#include <spine/spine.h>

using namespace spine;

spine_path_constraint_spacing_timeline spine_path_constraint_spacing_timeline_create(size_t frameCount, size_t bezierCount, int constraintIndex) {
    return (spine_path_constraint_spacing_timeline) new (__FILE__, __LINE__) PathConstraintSpacingTimeline(frameCount, bezierCount, constraintIndex);
}

void spine_path_constraint_spacing_timeline_dispose(spine_path_constraint_spacing_timeline self) {
    delete (PathConstraintSpacingTimeline*)self;
}

spine_rtti spine_path_constraint_spacing_timeline_get_rtti(spine_path_constraint_spacing_timeline self) {
    return (spine_rtti)&((PathConstraintSpacingTimeline*)self)->getRTTI();
}

void spine_path_constraint_spacing_timeline_apply(spine_path_constraint_spacing_timeline self, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    ((PathConstraintSpacingTimeline*)self)->apply(*((Skeleton*)skeleton), lastTime, time, (Array<Event *> *)pEvents, alpha, (MixBlend)blend, (MixDirection)direction, appliedPose);
}

void spine_path_constraint_spacing_timeline_set_frame(spine_path_constraint_spacing_timeline self, size_t frame, float time, float value) {
    ((ConstraintTimeline1*)(PathConstraintSpacingTimeline*)self)->setFrame(frame, time, value);
}

float spine_path_constraint_spacing_timeline_get_curve_value(spine_path_constraint_spacing_timeline self, float time) {
    return ((ConstraintTimeline1*)(PathConstraintSpacingTimeline*)self)->getCurveValue(time);
}

float spine_path_constraint_spacing_timeline_get_relative_value(spine_path_constraint_spacing_timeline self, float time, float alpha, spine_mix_blend blend, float current, float setup) {
    return ((ConstraintTimeline1*)(PathConstraintSpacingTimeline*)self)->getRelativeValue(time, alpha, (MixBlend)blend, current, setup);
}

float spine_path_constraint_spacing_timeline_get_absolute_value_1(spine_path_constraint_spacing_timeline self, float time, float alpha, spine_mix_blend blend, float current, float setup) {
    return ((ConstraintTimeline1*)(PathConstraintSpacingTimeline*)self)->getAbsoluteValue(time, alpha, (MixBlend)blend, current, setup);
}

float spine_path_constraint_spacing_timeline_get_absolute_value_2(spine_path_constraint_spacing_timeline self, float time, float alpha, spine_mix_blend blend, float current, float setup, float value) {
    return ((ConstraintTimeline1*)(PathConstraintSpacingTimeline*)self)->getAbsoluteValue(time, alpha, (MixBlend)blend, current, setup, value);
}

float spine_path_constraint_spacing_timeline_get_scale_value(spine_path_constraint_spacing_timeline self, float time, float alpha, spine_mix_blend blend, spine_mix_direction direction, float current, float setup) {
    return ((ConstraintTimeline1*)(PathConstraintSpacingTimeline*)self)->getScaleValue(time, alpha, (MixBlend)blend, (MixDirection)direction, current, setup);
}

void spine_path_constraint_spacing_timeline_set_linear(spine_path_constraint_spacing_timeline self, size_t frame) {
    ((ConstraintTimeline1*)(PathConstraintSpacingTimeline*)self)->setLinear(frame);
}

void spine_path_constraint_spacing_timeline_set_stepped(spine_path_constraint_spacing_timeline self, size_t frame) {
    ((ConstraintTimeline1*)(PathConstraintSpacingTimeline*)self)->setStepped(frame);
}

void spine_path_constraint_spacing_timeline_set_bezier(spine_path_constraint_spacing_timeline self, size_t bezier, size_t frame, float value, float time1, float value1, float cx1, float cy1, float cx2, float cy2, float time2, float value2) {
    ((ConstraintTimeline1*)(PathConstraintSpacingTimeline*)self)->setBezier(bezier, frame, value, time1, value1, cx1, cy1, cx2, cy2, time2, value2);
}

float spine_path_constraint_spacing_timeline_get_bezier_value(spine_path_constraint_spacing_timeline self, float time, size_t frame, size_t valueOffset, size_t i) {
    return ((ConstraintTimeline1*)(PathConstraintSpacingTimeline*)self)->getBezierValue(time, frame, valueOffset, i);
}

spine_array_float spine_path_constraint_spacing_timeline_get_curves(spine_path_constraint_spacing_timeline self) {
    return (spine_array_float)&((ConstraintTimeline1*)(PathConstraintSpacingTimeline*)self)->getCurves();
}

size_t spine_path_constraint_spacing_timeline_get_frame_entries(spine_path_constraint_spacing_timeline self) {
    return ((ConstraintTimeline1*)(PathConstraintSpacingTimeline*)self)->getFrameEntries();
}

size_t spine_path_constraint_spacing_timeline_get_frame_count(spine_path_constraint_spacing_timeline self) {
    return ((ConstraintTimeline1*)(PathConstraintSpacingTimeline*)self)->getFrameCount();
}

spine_array_float spine_path_constraint_spacing_timeline_get_frames(spine_path_constraint_spacing_timeline self) {
    return (spine_array_float)&((ConstraintTimeline1*)(PathConstraintSpacingTimeline*)self)->getFrames();
}

float spine_path_constraint_spacing_timeline_get_duration(spine_path_constraint_spacing_timeline self) {
    return ((ConstraintTimeline1*)(PathConstraintSpacingTimeline*)self)->getDuration();
}

spine_array_property_id spine_path_constraint_spacing_timeline_get_property_ids(spine_path_constraint_spacing_timeline self) {
    return (spine_array_property_id)&((ConstraintTimeline1*)(PathConstraintSpacingTimeline*)self)->getPropertyIds();
}

int spine_path_constraint_spacing_timeline_get_constraint_index(spine_path_constraint_spacing_timeline self) {
    return ((ConstraintTimeline1*)(PathConstraintSpacingTimeline*)self)->getConstraintIndex();
}

void spine_path_constraint_spacing_timeline_set_constraint_index(spine_path_constraint_spacing_timeline self, int inValue) {
    ((ConstraintTimeline1*)(PathConstraintSpacingTimeline*)self)->setConstraintIndex(inValue);
}

spine_rtti spine_path_constraint_spacing_timeline_rtti(void) {
    return (spine_rtti)&PathConstraintSpacingTimeline::rtti;
}
