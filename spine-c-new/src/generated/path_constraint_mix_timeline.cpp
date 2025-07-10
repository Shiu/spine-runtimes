#include "path_constraint_mix_timeline.h"
#include <spine/spine.h>

using namespace spine;

spine_path_constraint_mix_timeline spine_path_constraint_mix_timeline_create(size_t frameCount, size_t bezierCount, int constraintIndex) {
    return (spine_path_constraint_mix_timeline) new (__FILE__, __LINE__) PathConstraintMixTimeline(frameCount, bezierCount, constraintIndex);
}

void spine_path_constraint_mix_timeline_dispose(spine_path_constraint_mix_timeline self) {
    delete (PathConstraintMixTimeline*)self;
}

spine_rtti spine_path_constraint_mix_timeline_get_rtti(spine_path_constraint_mix_timeline self) {
    return (spine_rtti)&((PathConstraintMixTimeline*)self)->getRTTI();
}

void spine_path_constraint_mix_timeline_apply(spine_path_constraint_mix_timeline self, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    ((PathConstraintMixTimeline*)self)->apply(*((Skeleton*)skeleton), lastTime, time, (Array<Event *> *)pEvents, alpha, (MixBlend)blend, (MixDirection)direction, appliedPose);
}

void spine_path_constraint_mix_timeline_set_frame(spine_path_constraint_mix_timeline self, int frame, float time, float mixRotate, float mixX, float mixY) {
    ((PathConstraintMixTimeline*)self)->setFrame(frame, time, mixRotate, mixX, mixY);
}

void spine_path_constraint_mix_timeline_set_linear(spine_path_constraint_mix_timeline self, size_t frame) {
    ((CurveTimeline*)(PathConstraintMixTimeline*)self)->setLinear(frame);
}

void spine_path_constraint_mix_timeline_set_stepped(spine_path_constraint_mix_timeline self, size_t frame) {
    ((CurveTimeline*)(PathConstraintMixTimeline*)self)->setStepped(frame);
}

void spine_path_constraint_mix_timeline_set_bezier(spine_path_constraint_mix_timeline self, size_t bezier, size_t frame, float value, float time1, float value1, float cx1, float cy1, float cx2, float cy2, float time2, float value2) {
    ((CurveTimeline*)(PathConstraintMixTimeline*)self)->setBezier(bezier, frame, value, time1, value1, cx1, cy1, cx2, cy2, time2, value2);
}

float spine_path_constraint_mix_timeline_get_bezier_value(spine_path_constraint_mix_timeline self, float time, size_t frame, size_t valueOffset, size_t i) {
    return ((CurveTimeline*)(PathConstraintMixTimeline*)self)->getBezierValue(time, frame, valueOffset, i);
}

spine_array_float spine_path_constraint_mix_timeline_get_curves(spine_path_constraint_mix_timeline self) {
    return (spine_array_float)&((CurveTimeline*)(PathConstraintMixTimeline*)self)->getCurves();
}

size_t spine_path_constraint_mix_timeline_get_frame_entries(spine_path_constraint_mix_timeline self) {
    return ((CurveTimeline*)(PathConstraintMixTimeline*)self)->getFrameEntries();
}

size_t spine_path_constraint_mix_timeline_get_frame_count(spine_path_constraint_mix_timeline self) {
    return ((CurveTimeline*)(PathConstraintMixTimeline*)self)->getFrameCount();
}

spine_array_float spine_path_constraint_mix_timeline_get_frames(spine_path_constraint_mix_timeline self) {
    return (spine_array_float)&((CurveTimeline*)(PathConstraintMixTimeline*)self)->getFrames();
}

float spine_path_constraint_mix_timeline_get_duration(spine_path_constraint_mix_timeline self) {
    return ((CurveTimeline*)(PathConstraintMixTimeline*)self)->getDuration();
}

spine_array_property_id spine_path_constraint_mix_timeline_get_property_ids(spine_path_constraint_mix_timeline self) {
    return (spine_array_property_id)&((CurveTimeline*)(PathConstraintMixTimeline*)self)->getPropertyIds();
}

int spine_path_constraint_mix_timeline_get_constraint_index(spine_path_constraint_mix_timeline self) {
    return ((ConstraintTimeline*)(PathConstraintMixTimeline*)self)->getConstraintIndex();
}

void spine_path_constraint_mix_timeline_set_constraint_index(spine_path_constraint_mix_timeline self, int inValue) {
    ((ConstraintTimeline*)(PathConstraintMixTimeline*)self)->setConstraintIndex(inValue);
}

spine_rtti spine_path_constraint_mix_timeline_rtti(void) {
    return (spine_rtti)&PathConstraintMixTimeline::rtti;
}
