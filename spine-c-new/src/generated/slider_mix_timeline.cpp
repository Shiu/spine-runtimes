#include "slider_mix_timeline.h"
#include <spine/spine.h>

using namespace spine;

spine_slider_mix_timeline spine_slider_mix_timeline_create(size_t frameCount, size_t bezierCount, int sliderIndex) {
    return (spine_slider_mix_timeline) new (__FILE__, __LINE__) SliderMixTimeline(frameCount, bezierCount, sliderIndex);
}

void spine_slider_mix_timeline_dispose(spine_slider_mix_timeline self) {
    delete (SliderMixTimeline*)self;
}

spine_rtti spine_slider_mix_timeline_get_rtti(spine_slider_mix_timeline self) {
    return (spine_rtti)&((SliderMixTimeline*)self)->getRTTI();
}

void spine_slider_mix_timeline_apply(spine_slider_mix_timeline self, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    ((SliderMixTimeline*)self)->apply(*((Skeleton*)skeleton), lastTime, time, (Array<Event *> *)pEvents, alpha, (MixBlend)blend, (MixDirection)direction, appliedPose);
}

void spine_slider_mix_timeline_set_frame(spine_slider_mix_timeline self, size_t frame, float time, float value) {
    ((ConstraintTimeline1*)(SliderMixTimeline*)self)->setFrame(frame, time, value);
}

float spine_slider_mix_timeline_get_curve_value(spine_slider_mix_timeline self, float time) {
    return ((ConstraintTimeline1*)(SliderMixTimeline*)self)->getCurveValue(time);
}

float spine_slider_mix_timeline_get_relative_value(spine_slider_mix_timeline self, float time, float alpha, spine_mix_blend blend, float current, float setup) {
    return ((ConstraintTimeline1*)(SliderMixTimeline*)self)->getRelativeValue(time, alpha, (MixBlend)blend, current, setup);
}

float spine_slider_mix_timeline_get_absolute_value_1(spine_slider_mix_timeline self, float time, float alpha, spine_mix_blend blend, float current, float setup) {
    return ((ConstraintTimeline1*)(SliderMixTimeline*)self)->getAbsoluteValue(time, alpha, (MixBlend)blend, current, setup);
}

float spine_slider_mix_timeline_get_absolute_value_2(spine_slider_mix_timeline self, float time, float alpha, spine_mix_blend blend, float current, float setup, float value) {
    return ((ConstraintTimeline1*)(SliderMixTimeline*)self)->getAbsoluteValue(time, alpha, (MixBlend)blend, current, setup, value);
}

float spine_slider_mix_timeline_get_scale_value(spine_slider_mix_timeline self, float time, float alpha, spine_mix_blend blend, spine_mix_direction direction, float current, float setup) {
    return ((ConstraintTimeline1*)(SliderMixTimeline*)self)->getScaleValue(time, alpha, (MixBlend)blend, (MixDirection)direction, current, setup);
}

void spine_slider_mix_timeline_set_linear(spine_slider_mix_timeline self, size_t frame) {
    ((ConstraintTimeline1*)(SliderMixTimeline*)self)->setLinear(frame);
}

void spine_slider_mix_timeline_set_stepped(spine_slider_mix_timeline self, size_t frame) {
    ((ConstraintTimeline1*)(SliderMixTimeline*)self)->setStepped(frame);
}

void spine_slider_mix_timeline_set_bezier(spine_slider_mix_timeline self, size_t bezier, size_t frame, float value, float time1, float value1, float cx1, float cy1, float cx2, float cy2, float time2, float value2) {
    ((ConstraintTimeline1*)(SliderMixTimeline*)self)->setBezier(bezier, frame, value, time1, value1, cx1, cy1, cx2, cy2, time2, value2);
}

float spine_slider_mix_timeline_get_bezier_value(spine_slider_mix_timeline self, float time, size_t frame, size_t valueOffset, size_t i) {
    return ((ConstraintTimeline1*)(SliderMixTimeline*)self)->getBezierValue(time, frame, valueOffset, i);
}

spine_array_float spine_slider_mix_timeline_get_curves(spine_slider_mix_timeline self) {
    return (spine_array_float)&((ConstraintTimeline1*)(SliderMixTimeline*)self)->getCurves();
}

size_t spine_slider_mix_timeline_get_frame_entries(spine_slider_mix_timeline self) {
    return ((ConstraintTimeline1*)(SliderMixTimeline*)self)->getFrameEntries();
}

size_t spine_slider_mix_timeline_get_frame_count(spine_slider_mix_timeline self) {
    return ((ConstraintTimeline1*)(SliderMixTimeline*)self)->getFrameCount();
}

spine_array_float spine_slider_mix_timeline_get_frames(spine_slider_mix_timeline self) {
    return (spine_array_float)&((ConstraintTimeline1*)(SliderMixTimeline*)self)->getFrames();
}

float spine_slider_mix_timeline_get_duration(spine_slider_mix_timeline self) {
    return ((ConstraintTimeline1*)(SliderMixTimeline*)self)->getDuration();
}

spine_array_property_id spine_slider_mix_timeline_get_property_ids(spine_slider_mix_timeline self) {
    return (spine_array_property_id)&((ConstraintTimeline1*)(SliderMixTimeline*)self)->getPropertyIds();
}

int spine_slider_mix_timeline_get_constraint_index(spine_slider_mix_timeline self) {
    return ((ConstraintTimeline1*)(SliderMixTimeline*)self)->getConstraintIndex();
}

void spine_slider_mix_timeline_set_constraint_index(spine_slider_mix_timeline self, int inValue) {
    ((ConstraintTimeline1*)(SliderMixTimeline*)self)->setConstraintIndex(inValue);
}

spine_rtti spine_slider_mix_timeline_rtti(void) {
    return (spine_rtti)&SliderMixTimeline::rtti;
}
