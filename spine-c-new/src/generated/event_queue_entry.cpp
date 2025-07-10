#include "event_queue_entry.h"
#include <spine/spine.h>

using namespace spine;

spine_event_queue_entry spine_event_queue_entry_create(spine_event_type eventType, spine_track_entry trackEntry, spine_event event) {
    return (spine_event_queue_entry) new (__FILE__, __LINE__) EventQueueEntry((EventType)eventType, (TrackEntry *)trackEntry, (Event *)event);
}

void spine_event_queue_entry_dispose(spine_event_queue_entry self) {
    delete (EventQueueEntry*)self;
}

spine_event_type spine_event_queue_entry_get__type(spine_event_queue_entry self) {
    return (spine_event_type)((EventQueueEntry*)self)->_type;
}

void spine_event_queue_entry_set__type(spine_event_queue_entry self, spine_event_type value) {
    ((EventQueueEntry*)self)->_type = (EventType)value;
}

spine_track_entry spine_event_queue_entry_get__entry(spine_event_queue_entry self) {
    return (spine_track_entry)((EventQueueEntry*)self)->_entry;
}

void spine_event_queue_entry_set__entry(spine_event_queue_entry self, spine_track_entry value) {
    ((EventQueueEntry*)self)->_entry = (TrackEntry*)value;
}

spine_event spine_event_queue_entry_get__event(spine_event_queue_entry self) {
    return (spine_event)((EventQueueEntry*)self)->_event;
}

void spine_event_queue_entry_set__event(spine_event_queue_entry self, spine_event value) {
    ((EventQueueEntry*)self)->_event = (Event*)value;
}
