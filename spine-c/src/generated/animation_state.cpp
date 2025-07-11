#include "animation_state.h"
#include <spine/spine.h>

using namespace spine;

spine_animation_state spine_animation_state_create(spine_animation_state_data data) {
    return (spine_animation_state) new (__FILE__, __LINE__) AnimationState((AnimationStateData *)data);
}

void spine_animation_state_dispose(spine_animation_state self) {
    delete (AnimationState*)self;
}

void spine_animation_state_update(spine_animation_state self, float delta) {
    ((AnimationState*)self)->update(delta);
}

bool spine_animation_state_apply(spine_animation_state self, spine_skeleton skeleton) {
    return ((AnimationState*)self)->apply(*((Skeleton*)skeleton));
}

void spine_animation_state_clear_tracks(spine_animation_state self) {
    ((AnimationState*)self)->clearTracks();
}

void spine_animation_state_clear_track(spine_animation_state self, size_t trackIndex) {
    ((AnimationState*)self)->clearTrack(trackIndex);
}

spine_track_entry spine_animation_state_set_animation_1(spine_animation_state self, size_t trackIndex, const char* animationName, bool loop) {
    return (spine_track_entry)((AnimationState*)self)->setAnimation(trackIndex, String(animationName), loop);
}

spine_track_entry spine_animation_state_set_animation_2(spine_animation_state self, size_t trackIndex, spine_animation animation, bool loop) {
    return (spine_track_entry)((AnimationState*)self)->setAnimation(trackIndex, (Animation *)animation, loop);
}

spine_track_entry spine_animation_state_add_animation_1(spine_animation_state self, size_t trackIndex, const char* animationName, bool loop, float delay) {
    return (spine_track_entry)((AnimationState*)self)->addAnimation(trackIndex, String(animationName), loop, delay);
}

spine_track_entry spine_animation_state_add_animation_2(spine_animation_state self, size_t trackIndex, spine_animation animation, bool loop, float delay) {
    return (spine_track_entry)((AnimationState*)self)->addAnimation(trackIndex, (Animation *)animation, loop, delay);
}

spine_track_entry spine_animation_state_set_empty_animation(spine_animation_state self, size_t trackIndex, float mixDuration) {
    return (spine_track_entry)((AnimationState*)self)->setEmptyAnimation(trackIndex, mixDuration);
}

spine_track_entry spine_animation_state_add_empty_animation(spine_animation_state self, size_t trackIndex, float mixDuration, float delay) {
    return (spine_track_entry)((AnimationState*)self)->addEmptyAnimation(trackIndex, mixDuration, delay);
}

void spine_animation_state_set_empty_animations(spine_animation_state self, float mixDuration) {
    ((AnimationState*)self)->setEmptyAnimations(mixDuration);
}

spine_track_entry spine_animation_state_get_current(spine_animation_state self, size_t trackIndex) {
    return (spine_track_entry)((AnimationState*)self)->getCurrent(trackIndex);
}

spine_animation_state_data spine_animation_state_get_data(spine_animation_state self) {
    return (spine_animation_state_data)((AnimationState*)self)->getData();
}

spine_array_track_entry spine_animation_state_get_tracks(spine_animation_state self) {
    return (spine_array_track_entry)&((AnimationState*)self)->getTracks();
}

float spine_animation_state_get_time_scale(spine_animation_state self) {
    return ((AnimationState*)self)->getTimeScale();
}

void spine_animation_state_set_time_scale(spine_animation_state self, float inValue) {
    ((AnimationState*)self)->setTimeScale(inValue);
}

void spine_animation_state_disable_queue(spine_animation_state self) {
    ((AnimationState*)self)->disableQueue();
}

void spine_animation_state_enable_queue(spine_animation_state self) {
    ((AnimationState*)self)->enableQueue();
}

void spine_animation_state_set_manual_track_entry_disposal(spine_animation_state self, bool inValue) {
    ((AnimationState*)self)->setManualTrackEntryDisposal(inValue);
}

bool spine_animation_state_get_manual_track_entry_disposal(spine_animation_state self) {
    return ((AnimationState*)self)->getManualTrackEntryDisposal();
}

void spine_animation_state_dispose_track_entry(spine_animation_state self, spine_track_entry entry) {
    ((AnimationState*)self)->disposeTrackEntry((TrackEntry *)entry);
}

void * spine_animation_state_get_renderer_object(spine_animation_state self) {
    return ((HasRendererObject*)(AnimationState*)self)->getRendererObject();
}
