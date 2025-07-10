#include "shear_x_timeline.h"
#include <spine/spine.h>

using namespace spine;

spine_shear_x_timeline spine_shear_x_timeline_create(size_t frameCount, size_t bezierCount, int boneIndex) {
    return (spine_shear_x_timeline) new (__FILE__, __LINE__) ShearXTimeline(frameCount, bezierCount, boneIndex);
}

void spine_shear_x_timeline_dispose(spine_shear_x_timeline self) {
    delete (ShearXTimeline*)self;
}

spine_rtti spine_shear_x_timeline_get_rtti(spine_shear_x_timeline self) {
    return (spine_rtti)&((ShearXTimeline*)self)->getRTTI();
}

void spine_shear_x_timeline_apply(spine_shear_x_timeline self, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    ((BoneTimeline1*)(ShearXTimeline*)self)->apply(*((Skeleton*)skeleton), lastTime, time, (Array<Event *> *)pEvents, alpha, (MixBlend)blend, (MixDirection)direction, appliedPose);
}

void spine_shear_x_timeline_set_frame(spine_shear_x_timeline self, size_t frame, float time, float value) {
    ((BoneTimeline1*)(ShearXTimeline*)self)->setFrame(frame, time, value);
}

float spine_shear_x_timeline_get_curve_value(spine_shear_x_timeline self, float time) {
    return ((BoneTimeline1*)(ShearXTimeline*)self)->getCurveValue(time);
}

float spine_shear_x_timeline_get_relative_value(spine_shear_x_timeline self, float time, float alpha, spine_mix_blend blend, float current, float setup) {
    return ((BoneTimeline1*)(ShearXTimeline*)self)->getRelativeValue(time, alpha, (MixBlend)blend, current, setup);
}

float spine_shear_x_timeline_get_absolute_value_1(spine_shear_x_timeline self, float time, float alpha, spine_mix_blend blend, float current, float setup) {
    return ((BoneTimeline1*)(ShearXTimeline*)self)->getAbsoluteValue(time, alpha, (MixBlend)blend, current, setup);
}

float spine_shear_x_timeline_get_absolute_value_2(spine_shear_x_timeline self, float time, float alpha, spine_mix_blend blend, float current, float setup, float value) {
    return ((BoneTimeline1*)(ShearXTimeline*)self)->getAbsoluteValue(time, alpha, (MixBlend)blend, current, setup, value);
}

float spine_shear_x_timeline_get_scale_value(spine_shear_x_timeline self, float time, float alpha, spine_mix_blend blend, spine_mix_direction direction, float current, float setup) {
    return ((BoneTimeline1*)(ShearXTimeline*)self)->getScaleValue(time, alpha, (MixBlend)blend, (MixDirection)direction, current, setup);
}

void spine_shear_x_timeline_set_linear(spine_shear_x_timeline self, size_t frame) {
    ((BoneTimeline1*)(ShearXTimeline*)self)->setLinear(frame);
}

void spine_shear_x_timeline_set_stepped(spine_shear_x_timeline self, size_t frame) {
    ((BoneTimeline1*)(ShearXTimeline*)self)->setStepped(frame);
}

void spine_shear_x_timeline_set_bezier(spine_shear_x_timeline self, size_t bezier, size_t frame, float value, float time1, float value1, float cx1, float cy1, float cx2, float cy2, float time2, float value2) {
    ((BoneTimeline1*)(ShearXTimeline*)self)->setBezier(bezier, frame, value, time1, value1, cx1, cy1, cx2, cy2, time2, value2);
}

float spine_shear_x_timeline_get_bezier_value(spine_shear_x_timeline self, float time, size_t frame, size_t valueOffset, size_t i) {
    return ((BoneTimeline1*)(ShearXTimeline*)self)->getBezierValue(time, frame, valueOffset, i);
}

spine_array_float spine_shear_x_timeline_get_curves(spine_shear_x_timeline self) {
    return (spine_array_float)&((BoneTimeline1*)(ShearXTimeline*)self)->getCurves();
}

size_t spine_shear_x_timeline_get_frame_entries(spine_shear_x_timeline self) {
    return ((BoneTimeline1*)(ShearXTimeline*)self)->getFrameEntries();
}

size_t spine_shear_x_timeline_get_frame_count(spine_shear_x_timeline self) {
    return ((BoneTimeline1*)(ShearXTimeline*)self)->getFrameCount();
}

spine_array_float spine_shear_x_timeline_get_frames(spine_shear_x_timeline self) {
    return (spine_array_float)&((BoneTimeline1*)(ShearXTimeline*)self)->getFrames();
}

float spine_shear_x_timeline_get_duration(spine_shear_x_timeline self) {
    return ((BoneTimeline1*)(ShearXTimeline*)self)->getDuration();
}

spine_array_property_id spine_shear_x_timeline_get_property_ids(spine_shear_x_timeline self) {
    return (spine_array_property_id)&((BoneTimeline1*)(ShearXTimeline*)self)->getPropertyIds();
}

int spine_shear_x_timeline_get_bone_index(spine_shear_x_timeline self) {
    return ((BoneTimeline1*)(ShearXTimeline*)self)->getBoneIndex();
}

void spine_shear_x_timeline_set_bone_index(spine_shear_x_timeline self, int inValue) {
    ((BoneTimeline1*)(ShearXTimeline*)self)->setBoneIndex(inValue);
}

spine_rtti spine_shear_x_timeline_rtti(void) {
    return (spine_rtti)&ShearXTimeline::rtti;
}
