#include "slot_curve_timeline.h"
#include <spine/spine.h>

using namespace spine;

void spine_slot_curve_timeline_dispose(spine_slot_curve_timeline self) {
    delete (SlotCurveTimeline*)self;
}

spine_rtti spine_slot_curve_timeline_get_rtti(spine_slot_curve_timeline self) {
    return (spine_rtti)&((SlotCurveTimeline*)self)->getRTTI();
}

void spine_slot_curve_timeline_apply(spine_slot_curve_timeline self, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    ((SlotCurveTimeline*)self)->apply(*((Skeleton*)skeleton), lastTime, time, (Array<Event *> *)pEvents, alpha, (MixBlend)blend, (MixDirection)direction, appliedPose);
}

void spine_slot_curve_timeline_set_linear(spine_slot_curve_timeline self, size_t frame) {
    ((CurveTimeline*)(SlotCurveTimeline*)self)->setLinear(frame);
}

void spine_slot_curve_timeline_set_stepped(spine_slot_curve_timeline self, size_t frame) {
    ((CurveTimeline*)(SlotCurveTimeline*)self)->setStepped(frame);
}

void spine_slot_curve_timeline_set_bezier(spine_slot_curve_timeline self, size_t bezier, size_t frame, float value, float time1, float value1, float cx1, float cy1, float cx2, float cy2, float time2, float value2) {
    ((CurveTimeline*)(SlotCurveTimeline*)self)->setBezier(bezier, frame, value, time1, value1, cx1, cy1, cx2, cy2, time2, value2);
}

float spine_slot_curve_timeline_get_bezier_value(spine_slot_curve_timeline self, float time, size_t frame, size_t valueOffset, size_t i) {
    return ((CurveTimeline*)(SlotCurveTimeline*)self)->getBezierValue(time, frame, valueOffset, i);
}

spine_array_float spine_slot_curve_timeline_get_curves(spine_slot_curve_timeline self) {
    return (spine_array_float)&((CurveTimeline*)(SlotCurveTimeline*)self)->getCurves();
}

size_t spine_slot_curve_timeline_get_frame_entries(spine_slot_curve_timeline self) {
    return ((CurveTimeline*)(SlotCurveTimeline*)self)->getFrameEntries();
}

size_t spine_slot_curve_timeline_get_frame_count(spine_slot_curve_timeline self) {
    return ((CurveTimeline*)(SlotCurveTimeline*)self)->getFrameCount();
}

spine_array_float spine_slot_curve_timeline_get_frames(spine_slot_curve_timeline self) {
    return (spine_array_float)&((CurveTimeline*)(SlotCurveTimeline*)self)->getFrames();
}

float spine_slot_curve_timeline_get_duration(spine_slot_curve_timeline self) {
    return ((CurveTimeline*)(SlotCurveTimeline*)self)->getDuration();
}

spine_array_property_id spine_slot_curve_timeline_get_property_ids(spine_slot_curve_timeline self) {
    return (spine_array_property_id)&((CurveTimeline*)(SlotCurveTimeline*)self)->getPropertyIds();
}

int spine_slot_curve_timeline_get_slot_index(spine_slot_curve_timeline self) {
    return ((SlotTimeline*)(SlotCurveTimeline*)self)->getSlotIndex();
}

void spine_slot_curve_timeline_set_slot_index(spine_slot_curve_timeline self, int inValue) {
    ((SlotTimeline*)(SlotCurveTimeline*)self)->setSlotIndex(inValue);
}

spine_rtti spine_slot_curve_timeline_rtti(void) {
    return (spine_rtti)&SlotCurveTimeline::rtti;
}
