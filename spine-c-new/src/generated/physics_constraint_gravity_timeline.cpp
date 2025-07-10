#include "physics_constraint_gravity_timeline.h"
#include <spine/spine.h>

using namespace spine;

spine_physics_constraint_gravity_timeline spine_physics_constraint_gravity_timeline_create(size_t frameCount, size_t bezierCount, int physicsConstraintIndex) {
    return (spine_physics_constraint_gravity_timeline) new (__FILE__, __LINE__) PhysicsConstraintGravityTimeline(frameCount, bezierCount, physicsConstraintIndex);
}

void spine_physics_constraint_gravity_timeline_dispose(spine_physics_constraint_gravity_timeline self) {
    delete (PhysicsConstraintGravityTimeline*)self;
}

spine_rtti spine_physics_constraint_gravity_timeline_get_rtti(spine_physics_constraint_gravity_timeline self) {
    return (spine_rtti)&((PhysicsConstraintGravityTimeline*)self)->getRTTI();
}

void spine_physics_constraint_gravity_timeline_apply(spine_physics_constraint_gravity_timeline self, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    ((PhysicsConstraintTimeline*)(PhysicsConstraintGravityTimeline*)self)->apply(*((Skeleton*)skeleton), lastTime, time, (Array<Event *> *)pEvents, alpha, (MixBlend)blend, (MixDirection)direction, appliedPose);
}

void spine_physics_constraint_gravity_timeline_set_frame(spine_physics_constraint_gravity_timeline self, size_t frame, float time, float value) {
    ((PhysicsConstraintTimeline*)(PhysicsConstraintGravityTimeline*)self)->setFrame(frame, time, value);
}

float spine_physics_constraint_gravity_timeline_get_curve_value(spine_physics_constraint_gravity_timeline self, float time) {
    return ((PhysicsConstraintTimeline*)(PhysicsConstraintGravityTimeline*)self)->getCurveValue(time);
}

float spine_physics_constraint_gravity_timeline_get_relative_value(spine_physics_constraint_gravity_timeline self, float time, float alpha, spine_mix_blend blend, float current, float setup) {
    return ((PhysicsConstraintTimeline*)(PhysicsConstraintGravityTimeline*)self)->getRelativeValue(time, alpha, (MixBlend)blend, current, setup);
}

float spine_physics_constraint_gravity_timeline_get_absolute_value_1(spine_physics_constraint_gravity_timeline self, float time, float alpha, spine_mix_blend blend, float current, float setup) {
    return ((PhysicsConstraintTimeline*)(PhysicsConstraintGravityTimeline*)self)->getAbsoluteValue(time, alpha, (MixBlend)blend, current, setup);
}

float spine_physics_constraint_gravity_timeline_get_absolute_value_2(spine_physics_constraint_gravity_timeline self, float time, float alpha, spine_mix_blend blend, float current, float setup, float value) {
    return ((PhysicsConstraintTimeline*)(PhysicsConstraintGravityTimeline*)self)->getAbsoluteValue(time, alpha, (MixBlend)blend, current, setup, value);
}

float spine_physics_constraint_gravity_timeline_get_scale_value(spine_physics_constraint_gravity_timeline self, float time, float alpha, spine_mix_blend blend, spine_mix_direction direction, float current, float setup) {
    return ((PhysicsConstraintTimeline*)(PhysicsConstraintGravityTimeline*)self)->getScaleValue(time, alpha, (MixBlend)blend, (MixDirection)direction, current, setup);
}

void spine_physics_constraint_gravity_timeline_set_linear(spine_physics_constraint_gravity_timeline self, size_t frame) {
    ((PhysicsConstraintTimeline*)(PhysicsConstraintGravityTimeline*)self)->setLinear(frame);
}

void spine_physics_constraint_gravity_timeline_set_stepped(spine_physics_constraint_gravity_timeline self, size_t frame) {
    ((PhysicsConstraintTimeline*)(PhysicsConstraintGravityTimeline*)self)->setStepped(frame);
}

void spine_physics_constraint_gravity_timeline_set_bezier(spine_physics_constraint_gravity_timeline self, size_t bezier, size_t frame, float value, float time1, float value1, float cx1, float cy1, float cx2, float cy2, float time2, float value2) {
    ((PhysicsConstraintTimeline*)(PhysicsConstraintGravityTimeline*)self)->setBezier(bezier, frame, value, time1, value1, cx1, cy1, cx2, cy2, time2, value2);
}

float spine_physics_constraint_gravity_timeline_get_bezier_value(spine_physics_constraint_gravity_timeline self, float time, size_t frame, size_t valueOffset, size_t i) {
    return ((PhysicsConstraintTimeline*)(PhysicsConstraintGravityTimeline*)self)->getBezierValue(time, frame, valueOffset, i);
}

spine_array_float spine_physics_constraint_gravity_timeline_get_curves(spine_physics_constraint_gravity_timeline self) {
    return (spine_array_float)&((PhysicsConstraintTimeline*)(PhysicsConstraintGravityTimeline*)self)->getCurves();
}

size_t spine_physics_constraint_gravity_timeline_get_frame_entries(spine_physics_constraint_gravity_timeline self) {
    return ((PhysicsConstraintTimeline*)(PhysicsConstraintGravityTimeline*)self)->getFrameEntries();
}

size_t spine_physics_constraint_gravity_timeline_get_frame_count(spine_physics_constraint_gravity_timeline self) {
    return ((PhysicsConstraintTimeline*)(PhysicsConstraintGravityTimeline*)self)->getFrameCount();
}

spine_array_float spine_physics_constraint_gravity_timeline_get_frames(spine_physics_constraint_gravity_timeline self) {
    return (spine_array_float)&((PhysicsConstraintTimeline*)(PhysicsConstraintGravityTimeline*)self)->getFrames();
}

float spine_physics_constraint_gravity_timeline_get_duration(spine_physics_constraint_gravity_timeline self) {
    return ((PhysicsConstraintTimeline*)(PhysicsConstraintGravityTimeline*)self)->getDuration();
}

spine_array_property_id spine_physics_constraint_gravity_timeline_get_property_ids(spine_physics_constraint_gravity_timeline self) {
    return (spine_array_property_id)&((PhysicsConstraintTimeline*)(PhysicsConstraintGravityTimeline*)self)->getPropertyIds();
}

int spine_physics_constraint_gravity_timeline_get_constraint_index(spine_physics_constraint_gravity_timeline self) {
    return ((PhysicsConstraintTimeline*)(PhysicsConstraintGravityTimeline*)self)->getConstraintIndex();
}

void spine_physics_constraint_gravity_timeline_set_constraint_index(spine_physics_constraint_gravity_timeline self, int inValue) {
    ((PhysicsConstraintTimeline*)(PhysicsConstraintGravityTimeline*)self)->setConstraintIndex(inValue);
}

spine_rtti spine_physics_constraint_gravity_timeline_rtti(void) {
    return (spine_rtti)&PhysicsConstraintGravityTimeline::rtti;
}
