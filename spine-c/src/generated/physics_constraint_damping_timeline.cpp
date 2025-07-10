#include "physics_constraint_damping_timeline.h"
#include <spine/spine.h>

using namespace spine;

spine_physics_constraint_damping_timeline spine_physics_constraint_damping_timeline_create(size_t frameCount, size_t bezierCount, int physicsConstraintIndex) {
    return (spine_physics_constraint_damping_timeline) new (__FILE__, __LINE__) PhysicsConstraintDampingTimeline(frameCount, bezierCount, physicsConstraintIndex);
}

void spine_physics_constraint_damping_timeline_dispose(spine_physics_constraint_damping_timeline self) {
    delete (PhysicsConstraintDampingTimeline*)self;
}

spine_rtti spine_physics_constraint_damping_timeline_get_rtti(spine_physics_constraint_damping_timeline self) {
    return (spine_rtti)&((PhysicsConstraintDampingTimeline*)self)->getRTTI();
}

void spine_physics_constraint_damping_timeline_apply(spine_physics_constraint_damping_timeline self, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    ((PhysicsConstraintTimeline*)(PhysicsConstraintDampingTimeline*)self)->apply(*((Skeleton*)skeleton), lastTime, time, (Array<Event *> *)pEvents, alpha, (MixBlend)blend, (MixDirection)direction, appliedPose);
}

void spine_physics_constraint_damping_timeline_set_frame(spine_physics_constraint_damping_timeline self, size_t frame, float time, float value) {
    ((PhysicsConstraintTimeline*)(PhysicsConstraintDampingTimeline*)self)->setFrame(frame, time, value);
}

float spine_physics_constraint_damping_timeline_get_curve_value(spine_physics_constraint_damping_timeline self, float time) {
    return ((PhysicsConstraintTimeline*)(PhysicsConstraintDampingTimeline*)self)->getCurveValue(time);
}

float spine_physics_constraint_damping_timeline_get_relative_value(spine_physics_constraint_damping_timeline self, float time, float alpha, spine_mix_blend blend, float current, float setup) {
    return ((PhysicsConstraintTimeline*)(PhysicsConstraintDampingTimeline*)self)->getRelativeValue(time, alpha, (MixBlend)blend, current, setup);
}

float spine_physics_constraint_damping_timeline_get_absolute_value_1(spine_physics_constraint_damping_timeline self, float time, float alpha, spine_mix_blend blend, float current, float setup) {
    return ((PhysicsConstraintTimeline*)(PhysicsConstraintDampingTimeline*)self)->getAbsoluteValue(time, alpha, (MixBlend)blend, current, setup);
}

float spine_physics_constraint_damping_timeline_get_absolute_value_2(spine_physics_constraint_damping_timeline self, float time, float alpha, spine_mix_blend blend, float current, float setup, float value) {
    return ((PhysicsConstraintTimeline*)(PhysicsConstraintDampingTimeline*)self)->getAbsoluteValue(time, alpha, (MixBlend)blend, current, setup, value);
}

float spine_physics_constraint_damping_timeline_get_scale_value(spine_physics_constraint_damping_timeline self, float time, float alpha, spine_mix_blend blend, spine_mix_direction direction, float current, float setup) {
    return ((PhysicsConstraintTimeline*)(PhysicsConstraintDampingTimeline*)self)->getScaleValue(time, alpha, (MixBlend)blend, (MixDirection)direction, current, setup);
}

void spine_physics_constraint_damping_timeline_set_linear(spine_physics_constraint_damping_timeline self, size_t frame) {
    ((PhysicsConstraintTimeline*)(PhysicsConstraintDampingTimeline*)self)->setLinear(frame);
}

void spine_physics_constraint_damping_timeline_set_stepped(spine_physics_constraint_damping_timeline self, size_t frame) {
    ((PhysicsConstraintTimeline*)(PhysicsConstraintDampingTimeline*)self)->setStepped(frame);
}

void spine_physics_constraint_damping_timeline_set_bezier(spine_physics_constraint_damping_timeline self, size_t bezier, size_t frame, float value, float time1, float value1, float cx1, float cy1, float cx2, float cy2, float time2, float value2) {
    ((PhysicsConstraintTimeline*)(PhysicsConstraintDampingTimeline*)self)->setBezier(bezier, frame, value, time1, value1, cx1, cy1, cx2, cy2, time2, value2);
}

float spine_physics_constraint_damping_timeline_get_bezier_value(spine_physics_constraint_damping_timeline self, float time, size_t frame, size_t valueOffset, size_t i) {
    return ((PhysicsConstraintTimeline*)(PhysicsConstraintDampingTimeline*)self)->getBezierValue(time, frame, valueOffset, i);
}

spine_array_float spine_physics_constraint_damping_timeline_get_curves(spine_physics_constraint_damping_timeline self) {
    return (spine_array_float)&((PhysicsConstraintTimeline*)(PhysicsConstraintDampingTimeline*)self)->getCurves();
}

size_t spine_physics_constraint_damping_timeline_get_frame_entries(spine_physics_constraint_damping_timeline self) {
    return ((PhysicsConstraintTimeline*)(PhysicsConstraintDampingTimeline*)self)->getFrameEntries();
}

size_t spine_physics_constraint_damping_timeline_get_frame_count(spine_physics_constraint_damping_timeline self) {
    return ((PhysicsConstraintTimeline*)(PhysicsConstraintDampingTimeline*)self)->getFrameCount();
}

spine_array_float spine_physics_constraint_damping_timeline_get_frames(spine_physics_constraint_damping_timeline self) {
    return (spine_array_float)&((PhysicsConstraintTimeline*)(PhysicsConstraintDampingTimeline*)self)->getFrames();
}

float spine_physics_constraint_damping_timeline_get_duration(spine_physics_constraint_damping_timeline self) {
    return ((PhysicsConstraintTimeline*)(PhysicsConstraintDampingTimeline*)self)->getDuration();
}

spine_array_property_id spine_physics_constraint_damping_timeline_get_property_ids(spine_physics_constraint_damping_timeline self) {
    return (spine_array_property_id)&((PhysicsConstraintTimeline*)(PhysicsConstraintDampingTimeline*)self)->getPropertyIds();
}

int spine_physics_constraint_damping_timeline_get_constraint_index(spine_physics_constraint_damping_timeline self) {
    return ((PhysicsConstraintTimeline*)(PhysicsConstraintDampingTimeline*)self)->getConstraintIndex();
}

void spine_physics_constraint_damping_timeline_set_constraint_index(spine_physics_constraint_damping_timeline self, int inValue) {
    ((PhysicsConstraintTimeline*)(PhysicsConstraintDampingTimeline*)self)->setConstraintIndex(inValue);
}

spine_rtti spine_physics_constraint_damping_timeline_rtti(void) {
    return (spine_rtti)&PhysicsConstraintDampingTimeline::rtti;
}
