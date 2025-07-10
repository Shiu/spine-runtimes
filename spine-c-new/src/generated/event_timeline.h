#ifndef SPINE_SPINE_EVENT_TIMELINE_H
#define SPINE_SPINE_EVENT_TIMELINE_H

#include "../base.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_event_timeline spine_event_timeline_create(size_t frameCount);

SPINE_C_API void spine_event_timeline_dispose(spine_event_timeline self);

SPINE_C_API spine_rtti spine_event_timeline_get_rtti(spine_event_timeline self);
SPINE_C_API void spine_event_timeline_apply(spine_event_timeline self, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose);
SPINE_C_API size_t spine_event_timeline_get_frame_count(spine_event_timeline self);
SPINE_C_API spine_array_event spine_event_timeline_get_events(spine_event_timeline self);
SPINE_C_API void spine_event_timeline_set_frame(spine_event_timeline self, size_t frame, spine_event event);
SPINE_C_API size_t spine_event_timeline_get_frame_entries(spine_event_timeline self);
SPINE_C_API spine_array_float spine_event_timeline_get_frames(spine_event_timeline self);
SPINE_C_API float spine_event_timeline_get_duration(spine_event_timeline self);
SPINE_C_API spine_array_property_id spine_event_timeline_get_property_ids(spine_event_timeline self);
SPINE_C_API spine_rtti spine_event_timeline_rtti(void);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_EVENT_TIMELINE_H */