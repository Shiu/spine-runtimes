#include "timeline.h"
#include <spine/spine.h>

using namespace spine;

void spine_timeline_dispose(spine_timeline self) {
    delete (Timeline*)self;
}

spine_rtti spine_timeline_get_rtti(spine_timeline self) {
    return (spine_rtti)&((Timeline*)self)->getRTTI();
}

void spine_timeline_apply(spine_timeline self, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    ((Timeline*)self)->apply(*((Skeleton*)skeleton), lastTime, time, (Array<Event *> *)pEvents, alpha, (MixBlend)blend, (MixDirection)direction, appliedPose);
}

size_t spine_timeline_get_frame_entries(spine_timeline self) {
    return ((Timeline*)self)->getFrameEntries();
}

size_t spine_timeline_get_frame_count(spine_timeline self) {
    return ((Timeline*)self)->getFrameCount();
}

spine_array_float spine_timeline_get_frames(spine_timeline self) {
    return (spine_array_float)&((Timeline*)self)->getFrames();
}

float spine_timeline_get_duration(spine_timeline self) {
    return ((Timeline*)self)->getDuration();
}

spine_array_property_id spine_timeline_get_property_ids(spine_timeline self) {
    return (spine_array_property_id)&((Timeline*)self)->getPropertyIds();
}

spine_rtti spine_timeline_rtti(void) {
    return (spine_rtti)&Timeline::rtti;
}
