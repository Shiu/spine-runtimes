#include "slider_mix_timeline.h"
#include <spine/spine.h>

using namespace spine;

spine_slider_mix_timeline spine_slider_mix_timeline_create(size_t frameCount, size_t bezierCount, int sliderIndex) {
	return (spine_slider_mix_timeline) new (__FILE__, __LINE__) SliderMixTimeline(frameCount, bezierCount, sliderIndex);
}

void spine_slider_mix_timeline_dispose(spine_slider_mix_timeline self) {
	delete (SliderMixTimeline *) self;
}

spine_rtti spine_slider_mix_timeline_get_rtti(spine_slider_mix_timeline self) {
	SliderMixTimeline *_self = (SliderMixTimeline *) self;
	return (spine_rtti) &_self->getRTTI();
}

void spine_slider_mix_timeline_apply(spine_slider_mix_timeline self, spine_skeleton skeleton, float lastTime, float time,
									 /*@null*/ spine_array_event events, float alpha, spine_mix_blend blend, spine_mix_direction direction,
									 bool appliedPose) {
	SliderMixTimeline *_self = (SliderMixTimeline *) self;
	_self->apply(*((Skeleton *) skeleton), lastTime, time, (Array<Event *> *) events, alpha, (MixBlend) blend, (MixDirection) direction, appliedPose);
}

int spine_slider_mix_timeline_get_constraint_index(spine_slider_mix_timeline self) {
	ConstraintTimeline1 *_self = (ConstraintTimeline1 *) (SliderMixTimeline *) self;
	return _self->getConstraintIndex();
}

void spine_slider_mix_timeline_set_constraint_index(spine_slider_mix_timeline self, int inValue) {
	ConstraintTimeline1 *_self = (ConstraintTimeline1 *) (SliderMixTimeline *) self;
	_self->setConstraintIndex(inValue);
}

void spine_slider_mix_timeline_set_frame(spine_slider_mix_timeline self, size_t frame, float time, float value) {
	ConstraintTimeline1 *_self = (ConstraintTimeline1 *) (SliderMixTimeline *) self;
	_self->setFrame(frame, time, value);
}

float spine_slider_mix_timeline_get_curve_value(spine_slider_mix_timeline self, float time) {
	ConstraintTimeline1 *_self = (ConstraintTimeline1 *) (SliderMixTimeline *) self;
	return _self->getCurveValue(time);
}

float spine_slider_mix_timeline_get_relative_value(spine_slider_mix_timeline self, float time, float alpha, spine_mix_blend blend, float current,
												   float setup) {
	ConstraintTimeline1 *_self = (ConstraintTimeline1 *) (SliderMixTimeline *) self;
	return _self->getRelativeValue(time, alpha, (MixBlend) blend, current, setup);
}

float spine_slider_mix_timeline_get_absolute_value_1(spine_slider_mix_timeline self, float time, float alpha, spine_mix_blend blend, float current,
													 float setup) {
	ConstraintTimeline1 *_self = (ConstraintTimeline1 *) (SliderMixTimeline *) self;
	return _self->getAbsoluteValue(time, alpha, (MixBlend) blend, current, setup);
}

float spine_slider_mix_timeline_get_absolute_value_2(spine_slider_mix_timeline self, float time, float alpha, spine_mix_blend blend, float current,
													 float setup, float value) {
	ConstraintTimeline1 *_self = (ConstraintTimeline1 *) (SliderMixTimeline *) self;
	return _self->getAbsoluteValue(time, alpha, (MixBlend) blend, current, setup, value);
}

float spine_slider_mix_timeline_get_scale_value(spine_slider_mix_timeline self, float time, float alpha, spine_mix_blend blend,
												spine_mix_direction direction, float current, float setup) {
	ConstraintTimeline1 *_self = (ConstraintTimeline1 *) (SliderMixTimeline *) self;
	return _self->getScaleValue(time, alpha, (MixBlend) blend, (MixDirection) direction, current, setup);
}

void spine_slider_mix_timeline_set_linear(spine_slider_mix_timeline self, size_t frame) {
	ConstraintTimeline1 *_self = (ConstraintTimeline1 *) (SliderMixTimeline *) self;
	_self->setLinear(frame);
}

void spine_slider_mix_timeline_set_stepped(spine_slider_mix_timeline self, size_t frame) {
	ConstraintTimeline1 *_self = (ConstraintTimeline1 *) (SliderMixTimeline *) self;
	_self->setStepped(frame);
}

void spine_slider_mix_timeline_set_bezier(spine_slider_mix_timeline self, size_t bezier, size_t frame, float value, float time1, float value1,
										  float cx1, float cy1, float cx2, float cy2, float time2, float value2) {
	ConstraintTimeline1 *_self = (ConstraintTimeline1 *) (SliderMixTimeline *) self;
	_self->setBezier(bezier, frame, value, time1, value1, cx1, cy1, cx2, cy2, time2, value2);
}

float spine_slider_mix_timeline_get_bezier_value(spine_slider_mix_timeline self, float time, size_t frame, size_t valueOffset, size_t i) {
	ConstraintTimeline1 *_self = (ConstraintTimeline1 *) (SliderMixTimeline *) self;
	return _self->getBezierValue(time, frame, valueOffset, i);
}

spine_array_float spine_slider_mix_timeline_get_curves(spine_slider_mix_timeline self) {
	ConstraintTimeline1 *_self = (ConstraintTimeline1 *) (SliderMixTimeline *) self;
	return (spine_array_float) &_self->getCurves();
}

size_t spine_slider_mix_timeline_get_frame_entries(spine_slider_mix_timeline self) {
	ConstraintTimeline1 *_self = (ConstraintTimeline1 *) (SliderMixTimeline *) self;
	return _self->getFrameEntries();
}

size_t spine_slider_mix_timeline_get_frame_count(spine_slider_mix_timeline self) {
	ConstraintTimeline1 *_self = (ConstraintTimeline1 *) (SliderMixTimeline *) self;
	return _self->getFrameCount();
}

spine_array_float spine_slider_mix_timeline_get_frames(spine_slider_mix_timeline self) {
	ConstraintTimeline1 *_self = (ConstraintTimeline1 *) (SliderMixTimeline *) self;
	return (spine_array_float) &_self->getFrames();
}

float spine_slider_mix_timeline_get_duration(spine_slider_mix_timeline self) {
	ConstraintTimeline1 *_self = (ConstraintTimeline1 *) (SliderMixTimeline *) self;
	return _self->getDuration();
}

spine_array_property_id spine_slider_mix_timeline_get_property_ids(spine_slider_mix_timeline self) {
	ConstraintTimeline1 *_self = (ConstraintTimeline1 *) (SliderMixTimeline *) self;
	return (spine_array_property_id) &_self->getPropertyIds();
}

spine_rtti spine_slider_mix_timeline_rtti(void) {
	return (spine_rtti) &SliderMixTimeline::rtti;
}
