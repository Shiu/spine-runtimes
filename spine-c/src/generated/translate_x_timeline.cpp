#include "translate_x_timeline.h"
#include <spine/spine.h>

using namespace spine;

spine_translate_x_timeline spine_translate_x_timeline_create(size_t frameCount, size_t bezierCount, int boneIndex) {
    return (spine_translate_x_timeline) new (__FILE__, __LINE__) TranslateXTimeline(frameCount, bezierCount, boneIndex);
}

void spine_translate_x_timeline_dispose(spine_translate_x_timeline self) {
    delete (TranslateXTimeline*)self;
}

spine_rtti spine_translate_x_timeline_get_rtti(spine_translate_x_timeline self) {
    return (spine_rtti)&((TranslateXTimeline*)self)->getRTTI();
}

void spine_translate_x_timeline_apply(spine_translate_x_timeline self, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    ((BoneTimeline1*)(TranslateXTimeline*)self)->apply(*((Skeleton*)skeleton), lastTime, time, (Array<Event *> *)pEvents, alpha, (MixBlend)blend, (MixDirection)direction, appliedPose);
}

void spine_translate_x_timeline_set_frame(spine_translate_x_timeline self, size_t frame, float time, float value) {
    ((BoneTimeline1*)(TranslateXTimeline*)self)->setFrame(frame, time, value);
}

float spine_translate_x_timeline_get_curve_value(spine_translate_x_timeline self, float time) {
    return ((BoneTimeline1*)(TranslateXTimeline*)self)->getCurveValue(time);
}

float spine_translate_x_timeline_get_relative_value(spine_translate_x_timeline self, float time, float alpha, spine_mix_blend blend, float current, float setup) {
    return ((BoneTimeline1*)(TranslateXTimeline*)self)->getRelativeValue(time, alpha, (MixBlend)blend, current, setup);
}

float spine_translate_x_timeline_get_absolute_value_1(spine_translate_x_timeline self, float time, float alpha, spine_mix_blend blend, float current, float setup) {
    return ((BoneTimeline1*)(TranslateXTimeline*)self)->getAbsoluteValue(time, alpha, (MixBlend)blend, current, setup);
}

float spine_translate_x_timeline_get_absolute_value_2(spine_translate_x_timeline self, float time, float alpha, spine_mix_blend blend, float current, float setup, float value) {
    return ((BoneTimeline1*)(TranslateXTimeline*)self)->getAbsoluteValue(time, alpha, (MixBlend)blend, current, setup, value);
}

float spine_translate_x_timeline_get_scale_value(spine_translate_x_timeline self, float time, float alpha, spine_mix_blend blend, spine_mix_direction direction, float current, float setup) {
    return ((BoneTimeline1*)(TranslateXTimeline*)self)->getScaleValue(time, alpha, (MixBlend)blend, (MixDirection)direction, current, setup);
}

void spine_translate_x_timeline_set_linear(spine_translate_x_timeline self, size_t frame) {
    ((BoneTimeline1*)(TranslateXTimeline*)self)->setLinear(frame);
}

void spine_translate_x_timeline_set_stepped(spine_translate_x_timeline self, size_t frame) {
    ((BoneTimeline1*)(TranslateXTimeline*)self)->setStepped(frame);
}

void spine_translate_x_timeline_set_bezier(spine_translate_x_timeline self, size_t bezier, size_t frame, float value, float time1, float value1, float cx1, float cy1, float cx2, float cy2, float time2, float value2) {
    ((BoneTimeline1*)(TranslateXTimeline*)self)->setBezier(bezier, frame, value, time1, value1, cx1, cy1, cx2, cy2, time2, value2);
}

float spine_translate_x_timeline_get_bezier_value(spine_translate_x_timeline self, float time, size_t frame, size_t valueOffset, size_t i) {
    return ((BoneTimeline1*)(TranslateXTimeline*)self)->getBezierValue(time, frame, valueOffset, i);
}

spine_array_float spine_translate_x_timeline_get_curves(spine_translate_x_timeline self) {
    return (spine_array_float)&((BoneTimeline1*)(TranslateXTimeline*)self)->getCurves();
}

size_t spine_translate_x_timeline_get_frame_entries(spine_translate_x_timeline self) {
    return ((BoneTimeline1*)(TranslateXTimeline*)self)->getFrameEntries();
}

size_t spine_translate_x_timeline_get_frame_count(spine_translate_x_timeline self) {
    return ((BoneTimeline1*)(TranslateXTimeline*)self)->getFrameCount();
}

spine_array_float spine_translate_x_timeline_get_frames(spine_translate_x_timeline self) {
    return (spine_array_float)&((BoneTimeline1*)(TranslateXTimeline*)self)->getFrames();
}

float spine_translate_x_timeline_get_duration(spine_translate_x_timeline self) {
    return ((BoneTimeline1*)(TranslateXTimeline*)self)->getDuration();
}

spine_array_property_id spine_translate_x_timeline_get_property_ids(spine_translate_x_timeline self) {
    return (spine_array_property_id)&((BoneTimeline1*)(TranslateXTimeline*)self)->getPropertyIds();
}

int spine_translate_x_timeline_get_bone_index(spine_translate_x_timeline self) {
    return ((BoneTimeline1*)(TranslateXTimeline*)self)->getBoneIndex();
}

void spine_translate_x_timeline_set_bone_index(spine_translate_x_timeline self, int inValue) {
    ((BoneTimeline1*)(TranslateXTimeline*)self)->setBoneIndex(inValue);
}

spine_rtti spine_translate_x_timeline_rtti(void) {
    return (spine_rtti)&TranslateXTimeline::rtti;
}
