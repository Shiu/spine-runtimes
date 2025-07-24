#include "scale_y_timeline.h"
#include <spine/spine.h>

using namespace spine;

spine_scale_y_timeline spine_scale_y_timeline_create(size_t frameCount, size_t bezierCount, int boneIndex) {
	return (spine_scale_y_timeline) new (__FILE__, __LINE__) ScaleYTimeline(frameCount, bezierCount, boneIndex);
}

void spine_scale_y_timeline_dispose(spine_scale_y_timeline self) {
	delete (ScaleYTimeline *) self;
}

spine_rtti spine_scale_y_timeline_get_rtti(spine_scale_y_timeline self) {
	ScaleYTimeline *_self = (ScaleYTimeline *) self;
	return (spine_rtti) &_self->getRTTI();
}

void spine_scale_y_timeline_apply(spine_scale_y_timeline self, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents,
								  float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
	BoneTimeline1 *_self = (BoneTimeline1 *) (ScaleYTimeline *) self;
	_self->apply(*((Skeleton *) skeleton), lastTime, time, (Array<Event *> *) pEvents, alpha, (MixBlend) blend, (MixDirection) direction,
				 appliedPose);
}

int spine_scale_y_timeline_get_bone_index(spine_scale_y_timeline self) {
	BoneTimeline1 *_self = (BoneTimeline1 *) (ScaleYTimeline *) self;
	return _self->getBoneIndex();
}

void spine_scale_y_timeline_set_bone_index(spine_scale_y_timeline self, int inValue) {
	BoneTimeline1 *_self = (BoneTimeline1 *) (ScaleYTimeline *) self;
	_self->setBoneIndex(inValue);
}

void spine_scale_y_timeline_set_frame(spine_scale_y_timeline self, size_t frame, float time, float value) {
	BoneTimeline1 *_self = (BoneTimeline1 *) (ScaleYTimeline *) self;
	_self->setFrame(frame, time, value);
}

float spine_scale_y_timeline_get_curve_value(spine_scale_y_timeline self, float time) {
	BoneTimeline1 *_self = (BoneTimeline1 *) (ScaleYTimeline *) self;
	return _self->getCurveValue(time);
}

float spine_scale_y_timeline_get_relative_value(spine_scale_y_timeline self, float time, float alpha, spine_mix_blend blend, float current,
												float setup) {
	BoneTimeline1 *_self = (BoneTimeline1 *) (ScaleYTimeline *) self;
	return _self->getRelativeValue(time, alpha, (MixBlend) blend, current, setup);
}

float spine_scale_y_timeline_get_absolute_value_1(spine_scale_y_timeline self, float time, float alpha, spine_mix_blend blend, float current,
												  float setup) {
	BoneTimeline1 *_self = (BoneTimeline1 *) (ScaleYTimeline *) self;
	return _self->getAbsoluteValue(time, alpha, (MixBlend) blend, current, setup);
}

float spine_scale_y_timeline_get_absolute_value_2(spine_scale_y_timeline self, float time, float alpha, spine_mix_blend blend, float current,
												  float setup, float value) {
	BoneTimeline1 *_self = (BoneTimeline1 *) (ScaleYTimeline *) self;
	return _self->getAbsoluteValue(time, alpha, (MixBlend) blend, current, setup, value);
}

float spine_scale_y_timeline_get_scale_value(spine_scale_y_timeline self, float time, float alpha, spine_mix_blend blend,
											 spine_mix_direction direction, float current, float setup) {
	BoneTimeline1 *_self = (BoneTimeline1 *) (ScaleYTimeline *) self;
	return _self->getScaleValue(time, alpha, (MixBlend) blend, (MixDirection) direction, current, setup);
}

void spine_scale_y_timeline_set_linear(spine_scale_y_timeline self, size_t frame) {
	BoneTimeline1 *_self = (BoneTimeline1 *) (ScaleYTimeline *) self;
	_self->setLinear(frame);
}

void spine_scale_y_timeline_set_stepped(spine_scale_y_timeline self, size_t frame) {
	BoneTimeline1 *_self = (BoneTimeline1 *) (ScaleYTimeline *) self;
	_self->setStepped(frame);
}

void spine_scale_y_timeline_set_bezier(spine_scale_y_timeline self, size_t bezier, size_t frame, float value, float time1, float value1, float cx1,
									   float cy1, float cx2, float cy2, float time2, float value2) {
	BoneTimeline1 *_self = (BoneTimeline1 *) (ScaleYTimeline *) self;
	_self->setBezier(bezier, frame, value, time1, value1, cx1, cy1, cx2, cy2, time2, value2);
}

float spine_scale_y_timeline_get_bezier_value(spine_scale_y_timeline self, float time, size_t frame, size_t valueOffset, size_t i) {
	BoneTimeline1 *_self = (BoneTimeline1 *) (ScaleYTimeline *) self;
	return _self->getBezierValue(time, frame, valueOffset, i);
}

spine_array_float spine_scale_y_timeline_get_curves(spine_scale_y_timeline self) {
	BoneTimeline1 *_self = (BoneTimeline1 *) (ScaleYTimeline *) self;
	return (spine_array_float) &_self->getCurves();
}

size_t spine_scale_y_timeline_get_frame_entries(spine_scale_y_timeline self) {
	BoneTimeline1 *_self = (BoneTimeline1 *) (ScaleYTimeline *) self;
	return _self->getFrameEntries();
}

size_t spine_scale_y_timeline_get_frame_count(spine_scale_y_timeline self) {
	BoneTimeline1 *_self = (BoneTimeline1 *) (ScaleYTimeline *) self;
	return _self->getFrameCount();
}

spine_array_float spine_scale_y_timeline_get_frames(spine_scale_y_timeline self) {
	BoneTimeline1 *_self = (BoneTimeline1 *) (ScaleYTimeline *) self;
	return (spine_array_float) &_self->getFrames();
}

float spine_scale_y_timeline_get_duration(spine_scale_y_timeline self) {
	BoneTimeline1 *_self = (BoneTimeline1 *) (ScaleYTimeline *) self;
	return _self->getDuration();
}

spine_array_property_id spine_scale_y_timeline_get_property_ids(spine_scale_y_timeline self) {
	BoneTimeline1 *_self = (BoneTimeline1 *) (ScaleYTimeline *) self;
	return (spine_array_property_id) &_self->getPropertyIds();
}

spine_rtti spine_scale_y_timeline_rtti(void) {
	return (spine_rtti) &ScaleYTimeline::rtti;
}
