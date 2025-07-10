#include "ik_constraint_timeline.h"
#include <spine/spine.h>

using namespace spine;

spine_ik_constraint_timeline spine_ik_constraint_timeline_create(size_t frameCount, size_t bezierCount, int constraintIndex) {
    return (spine_ik_constraint_timeline) new (__FILE__, __LINE__) IkConstraintTimeline(frameCount, bezierCount, constraintIndex);
}

void spine_ik_constraint_timeline_dispose(spine_ik_constraint_timeline self) {
    delete (IkConstraintTimeline*)self;
}

spine_rtti spine_ik_constraint_timeline_get_rtti(spine_ik_constraint_timeline self) {
    return (spine_rtti)&((IkConstraintTimeline*)self)->getRTTI();
}

void spine_ik_constraint_timeline_apply(spine_ik_constraint_timeline self, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    ((IkConstraintTimeline*)self)->apply(*((Skeleton*)skeleton), lastTime, time, (Array<Event *> *)pEvents, alpha, (MixBlend)blend, (MixDirection)direction, appliedPose);
}

void spine_ik_constraint_timeline_set_frame(spine_ik_constraint_timeline self, int frame, float time, float mix, float softness, int bendDirection, bool compress, bool stretch) {
    ((IkConstraintTimeline*)self)->setFrame(frame, time, mix, softness, bendDirection, compress, stretch);
}

void spine_ik_constraint_timeline_set_linear(spine_ik_constraint_timeline self, size_t frame) {
    ((CurveTimeline*)(IkConstraintTimeline*)self)->setLinear(frame);
}

void spine_ik_constraint_timeline_set_stepped(spine_ik_constraint_timeline self, size_t frame) {
    ((CurveTimeline*)(IkConstraintTimeline*)self)->setStepped(frame);
}

void spine_ik_constraint_timeline_set_bezier(spine_ik_constraint_timeline self, size_t bezier, size_t frame, float value, float time1, float value1, float cx1, float cy1, float cx2, float cy2, float time2, float value2) {
    ((CurveTimeline*)(IkConstraintTimeline*)self)->setBezier(bezier, frame, value, time1, value1, cx1, cy1, cx2, cy2, time2, value2);
}

float spine_ik_constraint_timeline_get_bezier_value(spine_ik_constraint_timeline self, float time, size_t frame, size_t valueOffset, size_t i) {
    return ((CurveTimeline*)(IkConstraintTimeline*)self)->getBezierValue(time, frame, valueOffset, i);
}

spine_array_float spine_ik_constraint_timeline_get_curves(spine_ik_constraint_timeline self) {
    return (spine_array_float)&((CurveTimeline*)(IkConstraintTimeline*)self)->getCurves();
}

size_t spine_ik_constraint_timeline_get_frame_entries(spine_ik_constraint_timeline self) {
    return ((CurveTimeline*)(IkConstraintTimeline*)self)->getFrameEntries();
}

size_t spine_ik_constraint_timeline_get_frame_count(spine_ik_constraint_timeline self) {
    return ((CurveTimeline*)(IkConstraintTimeline*)self)->getFrameCount();
}

spine_array_float spine_ik_constraint_timeline_get_frames(spine_ik_constraint_timeline self) {
    return (spine_array_float)&((CurveTimeline*)(IkConstraintTimeline*)self)->getFrames();
}

float spine_ik_constraint_timeline_get_duration(spine_ik_constraint_timeline self) {
    return ((CurveTimeline*)(IkConstraintTimeline*)self)->getDuration();
}

spine_array_property_id spine_ik_constraint_timeline_get_property_ids(spine_ik_constraint_timeline self) {
    return (spine_array_property_id)&((CurveTimeline*)(IkConstraintTimeline*)self)->getPropertyIds();
}

int spine_ik_constraint_timeline_get_constraint_index(spine_ik_constraint_timeline self) {
    return ((ConstraintTimeline*)(IkConstraintTimeline*)self)->getConstraintIndex();
}

void spine_ik_constraint_timeline_set_constraint_index(spine_ik_constraint_timeline self, int inValue) {
    ((ConstraintTimeline*)(IkConstraintTimeline*)self)->setConstraintIndex(inValue);
}

spine_rtti spine_ik_constraint_timeline_rtti(void) {
    return (spine_rtti)&IkConstraintTimeline::rtti;
}
