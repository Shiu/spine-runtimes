#include "event_timeline.h"
#include <spine/spine.h>

using namespace spine;

spine_event_timeline spine_event_timeline_create(size_t frameCount) {
    return (spine_event_timeline) new (__FILE__, __LINE__) EventTimeline(frameCount);
}

void spine_event_timeline_dispose(spine_event_timeline self) {
    delete (EventTimeline*)self;
}

spine_rtti spine_event_timeline_get_rtti(spine_event_timeline self) {
    return (spine_rtti)&((EventTimeline*)self)->getRTTI();
}

void spine_event_timeline_apply(spine_event_timeline self, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    ((EventTimeline*)self)->apply(*((Skeleton*)skeleton), lastTime, time, (Array<Event *> *)pEvents, alpha, (MixBlend)blend, (MixDirection)direction, appliedPose);
}

size_t spine_event_timeline_get_frame_count(spine_event_timeline self) {
    return ((EventTimeline*)self)->getFrameCount();
}

spine_array_event spine_event_timeline_get_events(spine_event_timeline self) {
    return (spine_array_event)&((EventTimeline*)self)->getEvents();
}

void spine_event_timeline_set_frame(spine_event_timeline self, size_t frame, spine_event event) {
    ((EventTimeline*)self)->setFrame(frame, (Event *)event);
}

size_t spine_event_timeline_get_frame_entries(spine_event_timeline self) {
    return ((Timeline*)(EventTimeline*)self)->getFrameEntries();
}

spine_array_float spine_event_timeline_get_frames(spine_event_timeline self) {
    return (spine_array_float)&((Timeline*)(EventTimeline*)self)->getFrames();
}

float spine_event_timeline_get_duration(spine_event_timeline self) {
    return ((Timeline*)(EventTimeline*)self)->getDuration();
}

spine_array_property_id spine_event_timeline_get_property_ids(spine_event_timeline self) {
    return (spine_array_property_id)&((Timeline*)(EventTimeline*)self)->getPropertyIds();
}

spine_rtti spine_event_timeline_rtti(void) {
    return (spine_rtti)&EventTimeline::rtti;
}
