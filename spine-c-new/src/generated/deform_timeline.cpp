#include "deform_timeline.h"
#include <spine/spine.h>

using namespace spine;

spine_deform_timeline spine_deform_timeline_create(size_t frameCount, size_t bezierCount, int slotIndex, spine_vertex_attachment attachment) {
    return (spine_deform_timeline) new (__FILE__, __LINE__) DeformTimeline(frameCount, bezierCount, slotIndex, (VertexAttachment *)attachment);
}

void spine_deform_timeline_dispose(spine_deform_timeline self) {
    delete (DeformTimeline*)self;
}

spine_rtti spine_deform_timeline_get_rtti(spine_deform_timeline self) {
    return (spine_rtti)&((DeformTimeline*)self)->getRTTI();
}

void spine_deform_timeline_set_frame(spine_deform_timeline self, int frameIndex, float time, spine_array_float vertices) {
    ((DeformTimeline*)self)->setFrame(frameIndex, time, *((Array<float>*)vertices));
}

spine_vertex_attachment spine_deform_timeline_get_attachment(spine_deform_timeline self) {
    return (spine_vertex_attachment)((DeformTimeline*)self)->getAttachment();
}

void spine_deform_timeline_set_attachment(spine_deform_timeline self, spine_vertex_attachment inValue) {
    ((DeformTimeline*)self)->setAttachment((VertexAttachment *)inValue);
}

void spine_deform_timeline_set_bezier(spine_deform_timeline self, size_t bezier, size_t frame, float value, float time1, float value1, float cx1, float cy1, float cx2, float cy2, float time2, float value2) {
    ((DeformTimeline*)self)->setBezier(bezier, frame, value, time1, value1, cx1, cy1, cx2, cy2, time2, value2);
}

float spine_deform_timeline_get_curve_percent(spine_deform_timeline self, float time, int frame) {
    return ((DeformTimeline*)self)->getCurvePercent(time, frame);
}

size_t spine_deform_timeline_get_frame_count(spine_deform_timeline self) {
    return ((DeformTimeline*)self)->getFrameCount();
}

void spine_deform_timeline_apply(spine_deform_timeline self, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    ((SlotCurveTimeline*)(DeformTimeline*)self)->apply(*((Skeleton*)skeleton), lastTime, time, (Array<Event *> *)pEvents, alpha, (MixBlend)blend, (MixDirection)direction, appliedPose);
}

void spine_deform_timeline_set_linear(spine_deform_timeline self, size_t frame) {
    ((SlotCurveTimeline*)(DeformTimeline*)self)->setLinear(frame);
}

void spine_deform_timeline_set_stepped(spine_deform_timeline self, size_t frame) {
    ((SlotCurveTimeline*)(DeformTimeline*)self)->setStepped(frame);
}

float spine_deform_timeline_get_bezier_value(spine_deform_timeline self, float time, size_t frame, size_t valueOffset, size_t i) {
    return ((SlotCurveTimeline*)(DeformTimeline*)self)->getBezierValue(time, frame, valueOffset, i);
}

spine_array_float spine_deform_timeline_get_curves(spine_deform_timeline self) {
    return (spine_array_float)&((SlotCurveTimeline*)(DeformTimeline*)self)->getCurves();
}

size_t spine_deform_timeline_get_frame_entries(spine_deform_timeline self) {
    return ((SlotCurveTimeline*)(DeformTimeline*)self)->getFrameEntries();
}

spine_array_float spine_deform_timeline_get_frames(spine_deform_timeline self) {
    return (spine_array_float)&((SlotCurveTimeline*)(DeformTimeline*)self)->getFrames();
}

float spine_deform_timeline_get_duration(spine_deform_timeline self) {
    return ((SlotCurveTimeline*)(DeformTimeline*)self)->getDuration();
}

spine_array_property_id spine_deform_timeline_get_property_ids(spine_deform_timeline self) {
    return (spine_array_property_id)&((SlotCurveTimeline*)(DeformTimeline*)self)->getPropertyIds();
}

int spine_deform_timeline_get_slot_index(spine_deform_timeline self) {
    return ((SlotCurveTimeline*)(DeformTimeline*)self)->getSlotIndex();
}

void spine_deform_timeline_set_slot_index(spine_deform_timeline self, int inValue) {
    ((SlotCurveTimeline*)(DeformTimeline*)self)->setSlotIndex(inValue);
}

spine_rtti spine_deform_timeline_rtti(void) {
    return (spine_rtti)&DeformTimeline::rtti;
}
