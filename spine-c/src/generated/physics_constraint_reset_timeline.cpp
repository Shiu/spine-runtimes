#include "physics_constraint_reset_timeline.h"
#include <spine/spine.h>

using namespace spine;

spine_physics_constraint_reset_timeline spine_physics_constraint_reset_timeline_create(size_t frameCount, int constraintIndex) {
    return (spine_physics_constraint_reset_timeline) new (__FILE__, __LINE__) PhysicsConstraintResetTimeline(frameCount, constraintIndex);
}

void spine_physics_constraint_reset_timeline_dispose(spine_physics_constraint_reset_timeline self) {
    delete (PhysicsConstraintResetTimeline*)self;
}

spine_rtti spine_physics_constraint_reset_timeline_get_rtti(spine_physics_constraint_reset_timeline self) {
    return (spine_rtti)&((PhysicsConstraintResetTimeline*)self)->getRTTI();
}

void spine_physics_constraint_reset_timeline_apply(spine_physics_constraint_reset_timeline self, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    ((PhysicsConstraintResetTimeline*)self)->apply(*((Skeleton*)skeleton), lastTime, time, (Array<Event *> *)pEvents, alpha, (MixBlend)blend, (MixDirection)direction, appliedPose);
}

int spine_physics_constraint_reset_timeline_get_frame_count(spine_physics_constraint_reset_timeline self) {
    return ((PhysicsConstraintResetTimeline*)self)->getFrameCount();
}

int spine_physics_constraint_reset_timeline_get_constraint_index(spine_physics_constraint_reset_timeline self) {
    return ((PhysicsConstraintResetTimeline*)self)->getConstraintIndex();
}

void spine_physics_constraint_reset_timeline_set_frame(spine_physics_constraint_reset_timeline self, int frame, float time) {
    ((PhysicsConstraintResetTimeline*)self)->setFrame(frame, time);
}

size_t spine_physics_constraint_reset_timeline_get_frame_entries(spine_physics_constraint_reset_timeline self) {
    return ((Timeline*)(PhysicsConstraintResetTimeline*)self)->getFrameEntries();
}

spine_array_float spine_physics_constraint_reset_timeline_get_frames(spine_physics_constraint_reset_timeline self) {
    return (spine_array_float)&((Timeline*)(PhysicsConstraintResetTimeline*)self)->getFrames();
}

float spine_physics_constraint_reset_timeline_get_duration(spine_physics_constraint_reset_timeline self) {
    return ((Timeline*)(PhysicsConstraintResetTimeline*)self)->getDuration();
}

spine_array_property_id spine_physics_constraint_reset_timeline_get_property_ids(spine_physics_constraint_reset_timeline self) {
    return (spine_array_property_id)&((Timeline*)(PhysicsConstraintResetTimeline*)self)->getPropertyIds();
}

void spine_physics_constraint_reset_timeline_set_constraint_index(spine_physics_constraint_reset_timeline self, int inValue) {
    ((ConstraintTimeline*)(PhysicsConstraintResetTimeline*)self)->setConstraintIndex(inValue);
}

spine_rtti spine_physics_constraint_reset_timeline_rtti(void) {
    return (spine_rtti)&PhysicsConstraintResetTimeline::rtti;
}
