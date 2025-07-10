#include "physics_constraint_timeline.h"
#include <spine/spine.h>

using namespace spine;

void spine_physics_constraint_timeline_dispose(spine_physics_constraint_timeline self) {
    delete (PhysicsConstraintTimeline*)self;
}

spine_rtti spine_physics_constraint_timeline_get_rtti(spine_physics_constraint_timeline self) {
    return (spine_rtti)&((PhysicsConstraintTimeline*)self)->getRTTI();
}

void spine_physics_constraint_timeline_apply(spine_physics_constraint_timeline self, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    ((PhysicsConstraintTimeline*)self)->apply(*((Skeleton*)skeleton), lastTime, time, (Array<Event *> *)pEvents, alpha, (MixBlend)blend, (MixDirection)direction, appliedPose);
}

void spine_physics_constraint_timeline_set_frame(spine_physics_constraint_timeline self, size_t frame, float time, float value) {
    ((CurveTimeline1*)(PhysicsConstraintTimeline*)self)->setFrame(frame, time, value);
}

float spine_physics_constraint_timeline_get_curve_value(spine_physics_constraint_timeline self, float time) {
    return ((CurveTimeline1*)(PhysicsConstraintTimeline*)self)->getCurveValue(time);
}

float spine_physics_constraint_timeline_get_relative_value(spine_physics_constraint_timeline self, float time, float alpha, spine_mix_blend blend, float current, float setup) {
    return ((CurveTimeline1*)(PhysicsConstraintTimeline*)self)->getRelativeValue(time, alpha, (MixBlend)blend, current, setup);
}

float spine_physics_constraint_timeline_get_absolute_value_1(spine_physics_constraint_timeline self, float time, float alpha, spine_mix_blend blend, float current, float setup) {
    return ((CurveTimeline1*)(PhysicsConstraintTimeline*)self)->getAbsoluteValue(time, alpha, (MixBlend)blend, current, setup);
}

float spine_physics_constraint_timeline_get_absolute_value_2(spine_physics_constraint_timeline self, float time, float alpha, spine_mix_blend blend, float current, float setup, float value) {
    return ((CurveTimeline1*)(PhysicsConstraintTimeline*)self)->getAbsoluteValue(time, alpha, (MixBlend)blend, current, setup, value);
}

float spine_physics_constraint_timeline_get_scale_value(spine_physics_constraint_timeline self, float time, float alpha, spine_mix_blend blend, spine_mix_direction direction, float current, float setup) {
    return ((CurveTimeline1*)(PhysicsConstraintTimeline*)self)->getScaleValue(time, alpha, (MixBlend)blend, (MixDirection)direction, current, setup);
}

void spine_physics_constraint_timeline_set_linear(spine_physics_constraint_timeline self, size_t frame) {
    ((CurveTimeline1*)(PhysicsConstraintTimeline*)self)->setLinear(frame);
}

void spine_physics_constraint_timeline_set_stepped(spine_physics_constraint_timeline self, size_t frame) {
    ((CurveTimeline1*)(PhysicsConstraintTimeline*)self)->setStepped(frame);
}

void spine_physics_constraint_timeline_set_bezier(spine_physics_constraint_timeline self, size_t bezier, size_t frame, float value, float time1, float value1, float cx1, float cy1, float cx2, float cy2, float time2, float value2) {
    ((CurveTimeline1*)(PhysicsConstraintTimeline*)self)->setBezier(bezier, frame, value, time1, value1, cx1, cy1, cx2, cy2, time2, value2);
}

float spine_physics_constraint_timeline_get_bezier_value(spine_physics_constraint_timeline self, float time, size_t frame, size_t valueOffset, size_t i) {
    return ((CurveTimeline1*)(PhysicsConstraintTimeline*)self)->getBezierValue(time, frame, valueOffset, i);
}

spine_array_float spine_physics_constraint_timeline_get_curves(spine_physics_constraint_timeline self) {
    return (spine_array_float)&((CurveTimeline1*)(PhysicsConstraintTimeline*)self)->getCurves();
}

size_t spine_physics_constraint_timeline_get_frame_entries(spine_physics_constraint_timeline self) {
    return ((CurveTimeline1*)(PhysicsConstraintTimeline*)self)->getFrameEntries();
}

size_t spine_physics_constraint_timeline_get_frame_count(spine_physics_constraint_timeline self) {
    return ((CurveTimeline1*)(PhysicsConstraintTimeline*)self)->getFrameCount();
}

spine_array_float spine_physics_constraint_timeline_get_frames(spine_physics_constraint_timeline self) {
    return (spine_array_float)&((CurveTimeline1*)(PhysicsConstraintTimeline*)self)->getFrames();
}

float spine_physics_constraint_timeline_get_duration(spine_physics_constraint_timeline self) {
    return ((CurveTimeline1*)(PhysicsConstraintTimeline*)self)->getDuration();
}

spine_array_property_id spine_physics_constraint_timeline_get_property_ids(spine_physics_constraint_timeline self) {
    return (spine_array_property_id)&((CurveTimeline1*)(PhysicsConstraintTimeline*)self)->getPropertyIds();
}

int spine_physics_constraint_timeline_get_constraint_index(spine_physics_constraint_timeline self) {
    return ((ConstraintTimeline*)(PhysicsConstraintTimeline*)self)->getConstraintIndex();
}

void spine_physics_constraint_timeline_set_constraint_index(spine_physics_constraint_timeline self, int inValue) {
    ((ConstraintTimeline*)(PhysicsConstraintTimeline*)self)->setConstraintIndex(inValue);
}

spine_rtti spine_physics_constraint_timeline_rtti(void) {
    return (spine_rtti)&PhysicsConstraintTimeline::rtti;
}
