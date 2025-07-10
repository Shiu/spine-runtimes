#include "path_constraint_position_timeline.h"
#include <spine/spine.h>

using namespace spine;

spine_path_constraint_position_timeline spine_path_constraint_position_timeline_create(size_t frameCount, size_t bezierCount, int constraintIndex) {
    return (spine_path_constraint_position_timeline) new (__FILE__, __LINE__) PathConstraintPositionTimeline(frameCount, bezierCount, constraintIndex);
}

void spine_path_constraint_position_timeline_dispose(spine_path_constraint_position_timeline self) {
    delete (PathConstraintPositionTimeline*)self;
}

spine_rtti spine_path_constraint_position_timeline_get_rtti(spine_path_constraint_position_timeline self) {
    return (spine_rtti)&((PathConstraintPositionTimeline*)self)->getRTTI();
}

void spine_path_constraint_position_timeline_apply(spine_path_constraint_position_timeline self, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    ((PathConstraintPositionTimeline*)self)->apply(*((Skeleton*)skeleton), lastTime, time, (Array<Event *> *)pEvents, alpha, (MixBlend)blend, (MixDirection)direction, appliedPose);
}

void spine_path_constraint_position_timeline_set_frame(spine_path_constraint_position_timeline self, size_t frame, float time, float value) {
    ((ConstraintTimeline1*)(PathConstraintPositionTimeline*)self)->setFrame(frame, time, value);
}

float spine_path_constraint_position_timeline_get_curve_value(spine_path_constraint_position_timeline self, float time) {
    return ((ConstraintTimeline1*)(PathConstraintPositionTimeline*)self)->getCurveValue(time);
}

float spine_path_constraint_position_timeline_get_relative_value(spine_path_constraint_position_timeline self, float time, float alpha, spine_mix_blend blend, float current, float setup) {
    return ((ConstraintTimeline1*)(PathConstraintPositionTimeline*)self)->getRelativeValue(time, alpha, (MixBlend)blend, current, setup);
}

float spine_path_constraint_position_timeline_get_absolute_value_1(spine_path_constraint_position_timeline self, float time, float alpha, spine_mix_blend blend, float current, float setup) {
    return ((ConstraintTimeline1*)(PathConstraintPositionTimeline*)self)->getAbsoluteValue(time, alpha, (MixBlend)blend, current, setup);
}

float spine_path_constraint_position_timeline_get_absolute_value_2(spine_path_constraint_position_timeline self, float time, float alpha, spine_mix_blend blend, float current, float setup, float value) {
    return ((ConstraintTimeline1*)(PathConstraintPositionTimeline*)self)->getAbsoluteValue(time, alpha, (MixBlend)blend, current, setup, value);
}

float spine_path_constraint_position_timeline_get_scale_value(spine_path_constraint_position_timeline self, float time, float alpha, spine_mix_blend blend, spine_mix_direction direction, float current, float setup) {
    return ((ConstraintTimeline1*)(PathConstraintPositionTimeline*)self)->getScaleValue(time, alpha, (MixBlend)blend, (MixDirection)direction, current, setup);
}

void spine_path_constraint_position_timeline_set_linear(spine_path_constraint_position_timeline self, size_t frame) {
    ((ConstraintTimeline1*)(PathConstraintPositionTimeline*)self)->setLinear(frame);
}

void spine_path_constraint_position_timeline_set_stepped(spine_path_constraint_position_timeline self, size_t frame) {
    ((ConstraintTimeline1*)(PathConstraintPositionTimeline*)self)->setStepped(frame);
}

void spine_path_constraint_position_timeline_set_bezier(spine_path_constraint_position_timeline self, size_t bezier, size_t frame, float value, float time1, float value1, float cx1, float cy1, float cx2, float cy2, float time2, float value2) {
    ((ConstraintTimeline1*)(PathConstraintPositionTimeline*)self)->setBezier(bezier, frame, value, time1, value1, cx1, cy1, cx2, cy2, time2, value2);
}

float spine_path_constraint_position_timeline_get_bezier_value(spine_path_constraint_position_timeline self, float time, size_t frame, size_t valueOffset, size_t i) {
    return ((ConstraintTimeline1*)(PathConstraintPositionTimeline*)self)->getBezierValue(time, frame, valueOffset, i);
}

spine_array_float spine_path_constraint_position_timeline_get_curves(spine_path_constraint_position_timeline self) {
    return (spine_array_float)&((ConstraintTimeline1*)(PathConstraintPositionTimeline*)self)->getCurves();
}

size_t spine_path_constraint_position_timeline_get_frame_entries(spine_path_constraint_position_timeline self) {
    return ((ConstraintTimeline1*)(PathConstraintPositionTimeline*)self)->getFrameEntries();
}

size_t spine_path_constraint_position_timeline_get_frame_count(spine_path_constraint_position_timeline self) {
    return ((ConstraintTimeline1*)(PathConstraintPositionTimeline*)self)->getFrameCount();
}

spine_array_float spine_path_constraint_position_timeline_get_frames(spine_path_constraint_position_timeline self) {
    return (spine_array_float)&((ConstraintTimeline1*)(PathConstraintPositionTimeline*)self)->getFrames();
}

float spine_path_constraint_position_timeline_get_duration(spine_path_constraint_position_timeline self) {
    return ((ConstraintTimeline1*)(PathConstraintPositionTimeline*)self)->getDuration();
}

spine_array_property_id spine_path_constraint_position_timeline_get_property_ids(spine_path_constraint_position_timeline self) {
    return (spine_array_property_id)&((ConstraintTimeline1*)(PathConstraintPositionTimeline*)self)->getPropertyIds();
}

int spine_path_constraint_position_timeline_get_constraint_index(spine_path_constraint_position_timeline self) {
    return ((ConstraintTimeline1*)(PathConstraintPositionTimeline*)self)->getConstraintIndex();
}

void spine_path_constraint_position_timeline_set_constraint_index(spine_path_constraint_position_timeline self, int inValue) {
    ((ConstraintTimeline1*)(PathConstraintPositionTimeline*)self)->setConstraintIndex(inValue);
}

spine_rtti spine_path_constraint_position_timeline_rtti(void) {
    return (spine_rtti)&PathConstraintPositionTimeline::rtti;
}
