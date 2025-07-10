#include "scale_timeline.h"
#include <spine/spine.h>

using namespace spine;

spine_scale_timeline spine_scale_timeline_create(size_t frameCount, size_t bezierCount, int boneIndex) {
    return (spine_scale_timeline) new (__FILE__, __LINE__) ScaleTimeline(frameCount, bezierCount, boneIndex);
}

void spine_scale_timeline_dispose(spine_scale_timeline self) {
    delete (ScaleTimeline*)self;
}

spine_rtti spine_scale_timeline_get_rtti(spine_scale_timeline self) {
    return (spine_rtti)&((ScaleTimeline*)self)->getRTTI();
}

void spine_scale_timeline_apply(spine_scale_timeline self, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    ((BoneTimeline2*)(ScaleTimeline*)self)->apply(*((Skeleton*)skeleton), lastTime, time, (Array<Event *> *)pEvents, alpha, (MixBlend)blend, (MixDirection)direction, appliedPose);
}

void spine_scale_timeline_set_frame(spine_scale_timeline self, size_t frame, float time, float value1, float value2) {
    ((BoneTimeline2*)(ScaleTimeline*)self)->setFrame(frame, time, value1, value2);
}

float spine_scale_timeline_get_curve_value(spine_scale_timeline self, float time) {
    return ((BoneTimeline2*)(ScaleTimeline*)self)->getCurveValue(time);
}

void spine_scale_timeline_set_linear(spine_scale_timeline self, size_t frame) {
    ((BoneTimeline2*)(ScaleTimeline*)self)->setLinear(frame);
}

void spine_scale_timeline_set_stepped(spine_scale_timeline self, size_t frame) {
    ((BoneTimeline2*)(ScaleTimeline*)self)->setStepped(frame);
}

void spine_scale_timeline_set_bezier(spine_scale_timeline self, size_t bezier, size_t frame, float value, float time1, float value1, float cx1, float cy1, float cx2, float cy2, float time2, float value2) {
    ((BoneTimeline2*)(ScaleTimeline*)self)->setBezier(bezier, frame, value, time1, value1, cx1, cy1, cx2, cy2, time2, value2);
}

float spine_scale_timeline_get_bezier_value(spine_scale_timeline self, float time, size_t frame, size_t valueOffset, size_t i) {
    return ((BoneTimeline2*)(ScaleTimeline*)self)->getBezierValue(time, frame, valueOffset, i);
}

spine_array_float spine_scale_timeline_get_curves(spine_scale_timeline self) {
    return (spine_array_float)&((BoneTimeline2*)(ScaleTimeline*)self)->getCurves();
}

size_t spine_scale_timeline_get_frame_entries(spine_scale_timeline self) {
    return ((BoneTimeline2*)(ScaleTimeline*)self)->getFrameEntries();
}

size_t spine_scale_timeline_get_frame_count(spine_scale_timeline self) {
    return ((BoneTimeline2*)(ScaleTimeline*)self)->getFrameCount();
}

spine_array_float spine_scale_timeline_get_frames(spine_scale_timeline self) {
    return (spine_array_float)&((BoneTimeline2*)(ScaleTimeline*)self)->getFrames();
}

float spine_scale_timeline_get_duration(spine_scale_timeline self) {
    return ((BoneTimeline2*)(ScaleTimeline*)self)->getDuration();
}

spine_array_property_id spine_scale_timeline_get_property_ids(spine_scale_timeline self) {
    return (spine_array_property_id)&((BoneTimeline2*)(ScaleTimeline*)self)->getPropertyIds();
}

int spine_scale_timeline_get_bone_index(spine_scale_timeline self) {
    return ((BoneTimeline2*)(ScaleTimeline*)self)->getBoneIndex();
}

void spine_scale_timeline_set_bone_index(spine_scale_timeline self, int inValue) {
    ((BoneTimeline2*)(ScaleTimeline*)self)->setBoneIndex(inValue);
}

spine_rtti spine_scale_timeline_rtti(void) {
    return (spine_rtti)&ScaleTimeline::rtti;
}
