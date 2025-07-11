#include "attachment_timeline.h"
#include <spine/spine.h>

using namespace spine;

spine_attachment_timeline spine_attachment_timeline_create(size_t frameCount, int slotIndex) {
    return (spine_attachment_timeline) new (__FILE__, __LINE__) AttachmentTimeline(frameCount, slotIndex);
}

void spine_attachment_timeline_dispose(spine_attachment_timeline self) {
    delete (AttachmentTimeline*)self;
}

spine_rtti spine_attachment_timeline_get_rtti(spine_attachment_timeline self) {
    return (spine_rtti)&((AttachmentTimeline*)self)->getRTTI();
}

void spine_attachment_timeline_apply(spine_attachment_timeline self, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    ((AttachmentTimeline*)self)->apply(*((Skeleton*)skeleton), lastTime, time, (Array<Event *> *)pEvents, alpha, (MixBlend)blend, (MixDirection)direction, appliedPose);
}

void spine_attachment_timeline_set_frame(spine_attachment_timeline self, int frame, float time, const char* attachmentName) {
    ((AttachmentTimeline*)self)->setFrame(frame, time, String(attachmentName));
}

size_t spine_attachment_timeline_get_frame_entries(spine_attachment_timeline self) {
    return ((Timeline*)(AttachmentTimeline*)self)->getFrameEntries();
}

size_t spine_attachment_timeline_get_frame_count(spine_attachment_timeline self) {
    return ((Timeline*)(AttachmentTimeline*)self)->getFrameCount();
}

spine_array_float spine_attachment_timeline_get_frames(spine_attachment_timeline self) {
    return (spine_array_float)&((Timeline*)(AttachmentTimeline*)self)->getFrames();
}

float spine_attachment_timeline_get_duration(spine_attachment_timeline self) {
    return ((Timeline*)(AttachmentTimeline*)self)->getDuration();
}

spine_array_property_id spine_attachment_timeline_get_property_ids(spine_attachment_timeline self) {
    return (spine_array_property_id)&((Timeline*)(AttachmentTimeline*)self)->getPropertyIds();
}

int spine_attachment_timeline_get_slot_index(spine_attachment_timeline self) {
    return ((SlotTimeline*)(AttachmentTimeline*)self)->getSlotIndex();
}

void spine_attachment_timeline_set_slot_index(spine_attachment_timeline self, int inValue) {
    ((SlotTimeline*)(AttachmentTimeline*)self)->setSlotIndex(inValue);
}

spine_rtti spine_attachment_timeline_rtti(void) {
    return (spine_rtti)&AttachmentTimeline::rtti;
}
