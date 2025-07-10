#include "slider_timeline.h"
#include <spine/spine.h>

using namespace spine;

spine_slider_timeline spine_slider_timeline_create(size_t frameCount, size_t bezierCount, int sliderIndex) {
    return (spine_slider_timeline) new (__FILE__, __LINE__) SliderTimeline(frameCount, bezierCount, sliderIndex);
}

void spine_slider_timeline_dispose(spine_slider_timeline self) {
    delete (SliderTimeline*)self;
}

spine_rtti spine_slider_timeline_get_rtti(spine_slider_timeline self) {
    return (spine_rtti)&((SliderTimeline*)self)->getRTTI();
}

void spine_slider_timeline_apply(spine_slider_timeline self, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    ((SliderTimeline*)self)->apply(*((Skeleton*)skeleton), lastTime, time, (Array<Event *> *)pEvents, alpha, (MixBlend)blend, (MixDirection)direction, appliedPose);
}

void spine_slider_timeline_set_frame(spine_slider_timeline self, size_t frame, float time, float value) {
    ((ConstraintTimeline1*)(SliderTimeline*)self)->setFrame(frame, time, value);
}

float spine_slider_timeline_get_curve_value(spine_slider_timeline self, float time) {
    return ((ConstraintTimeline1*)(SliderTimeline*)self)->getCurveValue(time);
}

float spine_slider_timeline_get_relative_value(spine_slider_timeline self, float time, float alpha, spine_mix_blend blend, float current, float setup) {
    return ((ConstraintTimeline1*)(SliderTimeline*)self)->getRelativeValue(time, alpha, (MixBlend)blend, current, setup);
}

float spine_slider_timeline_get_absolute_value_1(spine_slider_timeline self, float time, float alpha, spine_mix_blend blend, float current, float setup) {
    return ((ConstraintTimeline1*)(SliderTimeline*)self)->getAbsoluteValue(time, alpha, (MixBlend)blend, current, setup);
}

float spine_slider_timeline_get_absolute_value_2(spine_slider_timeline self, float time, float alpha, spine_mix_blend blend, float current, float setup, float value) {
    return ((ConstraintTimeline1*)(SliderTimeline*)self)->getAbsoluteValue(time, alpha, (MixBlend)blend, current, setup, value);
}

float spine_slider_timeline_get_scale_value(spine_slider_timeline self, float time, float alpha, spine_mix_blend blend, spine_mix_direction direction, float current, float setup) {
    return ((ConstraintTimeline1*)(SliderTimeline*)self)->getScaleValue(time, alpha, (MixBlend)blend, (MixDirection)direction, current, setup);
}

void spine_slider_timeline_set_linear(spine_slider_timeline self, size_t frame) {
    ((ConstraintTimeline1*)(SliderTimeline*)self)->setLinear(frame);
}

void spine_slider_timeline_set_stepped(spine_slider_timeline self, size_t frame) {
    ((ConstraintTimeline1*)(SliderTimeline*)self)->setStepped(frame);
}

void spine_slider_timeline_set_bezier(spine_slider_timeline self, size_t bezier, size_t frame, float value, float time1, float value1, float cx1, float cy1, float cx2, float cy2, float time2, float value2) {
    ((ConstraintTimeline1*)(SliderTimeline*)self)->setBezier(bezier, frame, value, time1, value1, cx1, cy1, cx2, cy2, time2, value2);
}

float spine_slider_timeline_get_bezier_value(spine_slider_timeline self, float time, size_t frame, size_t valueOffset, size_t i) {
    return ((ConstraintTimeline1*)(SliderTimeline*)self)->getBezierValue(time, frame, valueOffset, i);
}

spine_array_float spine_slider_timeline_get_curves(spine_slider_timeline self) {
    return (spine_array_float)&((ConstraintTimeline1*)(SliderTimeline*)self)->getCurves();
}

size_t spine_slider_timeline_get_frame_entries(spine_slider_timeline self) {
    return ((ConstraintTimeline1*)(SliderTimeline*)self)->getFrameEntries();
}

size_t spine_slider_timeline_get_frame_count(spine_slider_timeline self) {
    return ((ConstraintTimeline1*)(SliderTimeline*)self)->getFrameCount();
}

spine_array_float spine_slider_timeline_get_frames(spine_slider_timeline self) {
    return (spine_array_float)&((ConstraintTimeline1*)(SliderTimeline*)self)->getFrames();
}

float spine_slider_timeline_get_duration(spine_slider_timeline self) {
    return ((ConstraintTimeline1*)(SliderTimeline*)self)->getDuration();
}

spine_array_property_id spine_slider_timeline_get_property_ids(spine_slider_timeline self) {
    return (spine_array_property_id)&((ConstraintTimeline1*)(SliderTimeline*)self)->getPropertyIds();
}

int spine_slider_timeline_get_constraint_index(spine_slider_timeline self) {
    return ((ConstraintTimeline1*)(SliderTimeline*)self)->getConstraintIndex();
}

void spine_slider_timeline_set_constraint_index(spine_slider_timeline self, int inValue) {
    ((ConstraintTimeline1*)(SliderTimeline*)self)->setConstraintIndex(inValue);
}

spine_rtti spine_slider_timeline_rtti(void) {
    return (spine_rtti)&SliderTimeline::rtti;
}
