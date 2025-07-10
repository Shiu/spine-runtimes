#include "track_entry.h"
#include <spine/spine.h>

using namespace spine;

spine_track_entry spine_track_entry_create(void) {
    return (spine_track_entry) new (__FILE__, __LINE__) TrackEntry();
}

void spine_track_entry_dispose(spine_track_entry self) {
    delete (TrackEntry*)self;
}

int spine_track_entry_get_track_index(spine_track_entry self) {
    return ((TrackEntry*)self)->getTrackIndex();
}

spine_animation spine_track_entry_get_animation(spine_track_entry self) {
    return (spine_animation)((TrackEntry*)self)->getAnimation();
}

void spine_track_entry_set_animation(spine_track_entry self, spine_animation animation) {
    ((TrackEntry*)self)->setAnimation((Animation *)animation);
}

spine_track_entry spine_track_entry_get_previous(spine_track_entry self) {
    return (spine_track_entry)((TrackEntry*)self)->getPrevious();
}

bool spine_track_entry_get_loop(spine_track_entry self) {
    return ((TrackEntry*)self)->getLoop();
}

void spine_track_entry_set_loop(spine_track_entry self, bool inValue) {
    ((TrackEntry*)self)->setLoop(inValue);
}

bool spine_track_entry_get_hold_previous(spine_track_entry self) {
    return ((TrackEntry*)self)->getHoldPrevious();
}

void spine_track_entry_set_hold_previous(spine_track_entry self, bool inValue) {
    ((TrackEntry*)self)->setHoldPrevious(inValue);
}

bool spine_track_entry_get_reverse(spine_track_entry self) {
    return ((TrackEntry*)self)->getReverse();
}

void spine_track_entry_set_reverse(spine_track_entry self, bool inValue) {
    ((TrackEntry*)self)->setReverse(inValue);
}

bool spine_track_entry_get_shortest_rotation(spine_track_entry self) {
    return ((TrackEntry*)self)->getShortestRotation();
}

void spine_track_entry_set_shortest_rotation(spine_track_entry self, bool inValue) {
    ((TrackEntry*)self)->setShortestRotation(inValue);
}

float spine_track_entry_get_delay(spine_track_entry self) {
    return ((TrackEntry*)self)->getDelay();
}

void spine_track_entry_set_delay(spine_track_entry self, float inValue) {
    ((TrackEntry*)self)->setDelay(inValue);
}

float spine_track_entry_get_track_time(spine_track_entry self) {
    return ((TrackEntry*)self)->getTrackTime();
}

void spine_track_entry_set_track_time(spine_track_entry self, float inValue) {
    ((TrackEntry*)self)->setTrackTime(inValue);
}

float spine_track_entry_get_track_end(spine_track_entry self) {
    return ((TrackEntry*)self)->getTrackEnd();
}

void spine_track_entry_set_track_end(spine_track_entry self, float inValue) {
    ((TrackEntry*)self)->setTrackEnd(inValue);
}

float spine_track_entry_get_animation_start(spine_track_entry self) {
    return ((TrackEntry*)self)->getAnimationStart();
}

void spine_track_entry_set_animation_start(spine_track_entry self, float inValue) {
    ((TrackEntry*)self)->setAnimationStart(inValue);
}

float spine_track_entry_get_animation_end(spine_track_entry self) {
    return ((TrackEntry*)self)->getAnimationEnd();
}

void spine_track_entry_set_animation_end(spine_track_entry self, float inValue) {
    ((TrackEntry*)self)->setAnimationEnd(inValue);
}

float spine_track_entry_get_animation_last(spine_track_entry self) {
    return ((TrackEntry*)self)->getAnimationLast();
}

void spine_track_entry_set_animation_last(spine_track_entry self, float inValue) {
    ((TrackEntry*)self)->setAnimationLast(inValue);
}

float spine_track_entry_get_animation_time(spine_track_entry self) {
    return ((TrackEntry*)self)->getAnimationTime();
}

float spine_track_entry_get_time_scale(spine_track_entry self) {
    return ((TrackEntry*)self)->getTimeScale();
}

void spine_track_entry_set_time_scale(spine_track_entry self, float inValue) {
    ((TrackEntry*)self)->setTimeScale(inValue);
}

float spine_track_entry_get_alpha(spine_track_entry self) {
    return ((TrackEntry*)self)->getAlpha();
}

void spine_track_entry_set_alpha(spine_track_entry self, float inValue) {
    ((TrackEntry*)self)->setAlpha(inValue);
}

float spine_track_entry_get_event_threshold(spine_track_entry self) {
    return ((TrackEntry*)self)->getEventThreshold();
}

void spine_track_entry_set_event_threshold(spine_track_entry self, float inValue) {
    ((TrackEntry*)self)->setEventThreshold(inValue);
}

float spine_track_entry_get_mix_attachment_threshold(spine_track_entry self) {
    return ((TrackEntry*)self)->getMixAttachmentThreshold();
}

void spine_track_entry_set_mix_attachment_threshold(spine_track_entry self, float inValue) {
    ((TrackEntry*)self)->setMixAttachmentThreshold(inValue);
}

float spine_track_entry_get_alpha_attachment_threshold(spine_track_entry self) {
    return ((TrackEntry*)self)->getAlphaAttachmentThreshold();
}

void spine_track_entry_set_alpha_attachment_threshold(spine_track_entry self, float inValue) {
    ((TrackEntry*)self)->setAlphaAttachmentThreshold(inValue);
}

float spine_track_entry_get_mix_draw_order_threshold(spine_track_entry self) {
    return ((TrackEntry*)self)->getMixDrawOrderThreshold();
}

void spine_track_entry_set_mix_draw_order_threshold(spine_track_entry self, float inValue) {
    ((TrackEntry*)self)->setMixDrawOrderThreshold(inValue);
}

spine_track_entry spine_track_entry_get_next(spine_track_entry self) {
    return (spine_track_entry)((TrackEntry*)self)->getNext();
}

bool spine_track_entry_is_complete(spine_track_entry self) {
    return ((TrackEntry*)self)->isComplete();
}

float spine_track_entry_get_mix_time(spine_track_entry self) {
    return ((TrackEntry*)self)->getMixTime();
}

void spine_track_entry_set_mix_time(spine_track_entry self, float inValue) {
    ((TrackEntry*)self)->setMixTime(inValue);
}

float spine_track_entry_get_mix_duration(spine_track_entry self) {
    return ((TrackEntry*)self)->getMixDuration();
}

void spine_track_entry_set_mix_duration_1(spine_track_entry self, float inValue) {
    ((TrackEntry*)self)->setMixDuration(inValue);
}

void spine_track_entry_set_mix_duration_2(spine_track_entry self, float mixDuration, float delay) {
    ((TrackEntry*)self)->setMixDuration(mixDuration, delay);
}

spine_mix_blend spine_track_entry_get_mix_blend(spine_track_entry self) {
    return (spine_mix_blend)((TrackEntry*)self)->getMixBlend();
}

void spine_track_entry_set_mix_blend(spine_track_entry self, spine_mix_blend blend) {
    ((TrackEntry*)self)->setMixBlend((MixBlend)blend);
}

spine_track_entry spine_track_entry_get_mixing_from(spine_track_entry self) {
    return (spine_track_entry)((TrackEntry*)self)->getMixingFrom();
}

spine_track_entry spine_track_entry_get_mixing_to(spine_track_entry self) {
    return (spine_track_entry)((TrackEntry*)self)->getMixingTo();
}

void spine_track_entry_reset_rotation_directions(spine_track_entry self) {
    ((TrackEntry*)self)->resetRotationDirections();
}

float spine_track_entry_get_track_complete(spine_track_entry self) {
    return ((TrackEntry*)self)->getTrackComplete();
}

bool spine_track_entry_is_empty_animation(spine_track_entry self) {
    return ((TrackEntry*)self)->isEmptyAnimation();
}

bool spine_track_entry_was_applied(spine_track_entry self) {
    return ((TrackEntry*)self)->wasApplied();
}

bool spine_track_entry_is_next_ready(spine_track_entry self) {
    return ((TrackEntry*)self)->isNextReady();
}

void * spine_track_entry_get_renderer_object(spine_track_entry self) {
    return ((HasRendererObject*)(TrackEntry*)self)->getRendererObject();
}
