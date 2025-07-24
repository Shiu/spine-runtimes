#include "rgba_timeline.h"
#include <spine/spine.h>

using namespace spine;

spine_rgba_timeline spine_rgba_timeline_create(size_t frameCount, size_t bezierCount, int slotIndex) {
	return (spine_rgba_timeline) new (__FILE__, __LINE__) RGBATimeline(frameCount, bezierCount, slotIndex);
}

void spine_rgba_timeline_dispose(spine_rgba_timeline self) {
	delete (RGBATimeline *) self;
}

spine_rtti spine_rgba_timeline_get_rtti(spine_rgba_timeline self) {
	RGBATimeline *_self = (RGBATimeline *) self;
	return (spine_rtti) &_self->getRTTI();
}

void spine_rgba_timeline_set_frame(spine_rgba_timeline self, int frame, float time, float r, float g, float b, float a) {
	RGBATimeline *_self = (RGBATimeline *) self;
	_self->setFrame(frame, time, r, g, b, a);
}

void spine_rgba_timeline_apply(spine_rgba_timeline self, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha,
							   spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
	SlotCurveTimeline *_self = (SlotCurveTimeline *) (RGBATimeline *) self;
	_self->apply(*((Skeleton *) skeleton), lastTime, time, (Array<Event *> *) pEvents, alpha, (MixBlend) blend, (MixDirection) direction,
				 appliedPose);
}

int spine_rgba_timeline_get_slot_index(spine_rgba_timeline self) {
	SlotCurveTimeline *_self = (SlotCurveTimeline *) (RGBATimeline *) self;
	return _self->getSlotIndex();
}

void spine_rgba_timeline_set_slot_index(spine_rgba_timeline self, int inValue) {
	SlotCurveTimeline *_self = (SlotCurveTimeline *) (RGBATimeline *) self;
	_self->setSlotIndex(inValue);
}

void spine_rgba_timeline_set_linear(spine_rgba_timeline self, size_t frame) {
	SlotCurveTimeline *_self = (SlotCurveTimeline *) (RGBATimeline *) self;
	_self->setLinear(frame);
}

void spine_rgba_timeline_set_stepped(spine_rgba_timeline self, size_t frame) {
	SlotCurveTimeline *_self = (SlotCurveTimeline *) (RGBATimeline *) self;
	_self->setStepped(frame);
}

void spine_rgba_timeline_set_bezier(spine_rgba_timeline self, size_t bezier, size_t frame, float value, float time1, float value1, float cx1,
									float cy1, float cx2, float cy2, float time2, float value2) {
	SlotCurveTimeline *_self = (SlotCurveTimeline *) (RGBATimeline *) self;
	_self->setBezier(bezier, frame, value, time1, value1, cx1, cy1, cx2, cy2, time2, value2);
}

float spine_rgba_timeline_get_bezier_value(spine_rgba_timeline self, float time, size_t frame, size_t valueOffset, size_t i) {
	SlotCurveTimeline *_self = (SlotCurveTimeline *) (RGBATimeline *) self;
	return _self->getBezierValue(time, frame, valueOffset, i);
}

spine_array_float spine_rgba_timeline_get_curves(spine_rgba_timeline self) {
	SlotCurveTimeline *_self = (SlotCurveTimeline *) (RGBATimeline *) self;
	return (spine_array_float) &_self->getCurves();
}

size_t spine_rgba_timeline_get_frame_entries(spine_rgba_timeline self) {
	SlotCurveTimeline *_self = (SlotCurveTimeline *) (RGBATimeline *) self;
	return _self->getFrameEntries();
}

size_t spine_rgba_timeline_get_frame_count(spine_rgba_timeline self) {
	SlotCurveTimeline *_self = (SlotCurveTimeline *) (RGBATimeline *) self;
	return _self->getFrameCount();
}

spine_array_float spine_rgba_timeline_get_frames(spine_rgba_timeline self) {
	SlotCurveTimeline *_self = (SlotCurveTimeline *) (RGBATimeline *) self;
	return (spine_array_float) &_self->getFrames();
}

float spine_rgba_timeline_get_duration(spine_rgba_timeline self) {
	SlotCurveTimeline *_self = (SlotCurveTimeline *) (RGBATimeline *) self;
	return _self->getDuration();
}

spine_array_property_id spine_rgba_timeline_get_property_ids(spine_rgba_timeline self) {
	SlotCurveTimeline *_self = (SlotCurveTimeline *) (RGBATimeline *) self;
	return (spine_array_property_id) &_self->getPropertyIds();
}

spine_rtti spine_rgba_timeline_rtti(void) {
	return (spine_rtti) &RGBATimeline::rtti;
}
