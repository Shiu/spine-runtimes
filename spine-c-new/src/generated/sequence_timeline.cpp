#include "sequence_timeline.h"
#include <spine/spine.h>

using namespace spine;

spine_sequence_timeline spine_sequence_timeline_create(size_t frameCount, int slotIndex, spine_attachment attachment) {
    return (spine_sequence_timeline) new (__FILE__, __LINE__) SequenceTimeline(frameCount, slotIndex, (Attachment *)attachment);
}

void spine_sequence_timeline_dispose(spine_sequence_timeline self) {
    delete (SequenceTimeline*)self;
}

spine_rtti spine_sequence_timeline_get_rtti(spine_sequence_timeline self) {
    return (spine_rtti)&((SequenceTimeline*)self)->getRTTI();
}

void spine_sequence_timeline_apply(spine_sequence_timeline self, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    ((SequenceTimeline*)self)->apply(*((Skeleton*)skeleton), lastTime, time, (Array<Event *> *)pEvents, alpha, (MixBlend)blend, (MixDirection)direction, appliedPose);
}

void spine_sequence_timeline_set_frame(spine_sequence_timeline self, int frame, float time, spine_sequence_mode mode, int index, float delay) {
    ((SequenceTimeline*)self)->setFrame(frame, time, (SequenceMode)mode, index, delay);
}

spine_attachment spine_sequence_timeline_get_attachment(spine_sequence_timeline self) {
    return (spine_attachment)((SequenceTimeline*)self)->getAttachment();
}

size_t spine_sequence_timeline_get_frame_entries(spine_sequence_timeline self) {
    return ((Timeline*)(SequenceTimeline*)self)->getFrameEntries();
}

size_t spine_sequence_timeline_get_frame_count(spine_sequence_timeline self) {
    return ((Timeline*)(SequenceTimeline*)self)->getFrameCount();
}

spine_array_float spine_sequence_timeline_get_frames(spine_sequence_timeline self) {
    return (spine_array_float)&((Timeline*)(SequenceTimeline*)self)->getFrames();
}

float spine_sequence_timeline_get_duration(spine_sequence_timeline self) {
    return ((Timeline*)(SequenceTimeline*)self)->getDuration();
}

spine_array_property_id spine_sequence_timeline_get_property_ids(spine_sequence_timeline self) {
    return (spine_array_property_id)&((Timeline*)(SequenceTimeline*)self)->getPropertyIds();
}

int spine_sequence_timeline_get_slot_index(spine_sequence_timeline self) {
    return ((SlotTimeline*)(SequenceTimeline*)self)->getSlotIndex();
}

void spine_sequence_timeline_set_slot_index(spine_sequence_timeline self, int inValue) {
    ((SlotTimeline*)(SequenceTimeline*)self)->setSlotIndex(inValue);
}

spine_rtti spine_sequence_timeline_rtti(void) {
    return (spine_rtti)&SequenceTimeline::rtti;
}
