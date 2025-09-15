#ifndef SPINE_SPINE_TRACK_ENTRY_H
#define SPINE_SPINE_TRACK_ENTRY_H

#include "../base.h"
#include "types.h"
#include "arrays.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_track_entry spine_track_entry_create(void);

SPINE_C_API void spine_track_entry_dispose(spine_track_entry self);

/**
 * The index of the track where this entry is either current or queued.
 */
SPINE_C_API int spine_track_entry_get_track_index(spine_track_entry self);
/**
 * The animation to apply for this track entry.
 */
SPINE_C_API spine_animation spine_track_entry_get_animation(spine_track_entry self);
/**
 * Sets the animation for this track entry.
 */
SPINE_C_API void spine_track_entry_set_animation(spine_track_entry self, spine_animation animation);
SPINE_C_API /*@null*/ spine_track_entry spine_track_entry_get_previous(spine_track_entry self);
/**
 * If true, the animation will repeat. If false, it will not, instead its last
 * frame is applied if played beyond its duration.
 */
SPINE_C_API bool spine_track_entry_get_loop(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_loop(spine_track_entry self, bool inValue);
/**
 * If true, when mixing from the previous animation to this animation, the
 * previous animation is applied as normal instead of being mixed out.
 *
 * When mixing between animations that key the same property, if a lower track
 * also keys that property then the value will briefly dip toward the lower
 * track value during the mix. This happens because the first animation mixes
 * from 100% to 0% while the second animation mixes from 0% to 100%. Setting
 * holdPrevious to true applies the first animation at 100% during the mix so
 * the lower track value is overwritten. Such dipping does not occur on the
 * lowest track which keys the property, only when a higher track also keys the
 * property.
 *
 * Snapping will occur if holdPrevious is true and this animation does not key
 * all the same properties as the previous animation.
 */
SPINE_C_API bool spine_track_entry_get_hold_previous(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_hold_previous(spine_track_entry self, bool inValue);
SPINE_C_API bool spine_track_entry_get_reverse(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_reverse(spine_track_entry self, bool inValue);
SPINE_C_API bool spine_track_entry_get_shortest_rotation(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_shortest_rotation(spine_track_entry self, bool inValue);
/**
 * Seconds to postpone playing the animation. Must be >= 0. When this track
 * entry is the current track entry, delay postpones incrementing the
 * getTrackTime(). When this track entry is queued, delay is the time from the
 * start of the previous animation to when this track entry will become the
 * current track entry (ie when the previous track entry getTrackTime() >= this
 * track entry's delay).
 *
 * getTimeScale() affects the delay.
 *
 * When passing delay < = 0 to AnimationState::addAnimation(int, Animation,
 * bool, float) this delay is set using a mix duration from AnimationStateData.
 * To change the getMixDuration() afterward, use setMixDuration(float, float) so
 * this delay is adjusted.
 */
SPINE_C_API float spine_track_entry_get_delay(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_delay(spine_track_entry self, float inValue);
/**
 * Current time in seconds this track entry has been the current track entry.
 * The track time determines getAnimationTime(). The track time can be set to
 * start the animation at a time other than 0, without affecting looping.
 */
SPINE_C_API float spine_track_entry_get_track_time(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_track_time(spine_track_entry self, float inValue);
/**
 * The track time in seconds when this animation will be removed from the track.
 * Defaults to the highest possible float value, meaning the animation will be
 * applied until a new animation is set or the track is cleared. If the track
 * end time is reached, no other animations are queued for playback, and mixing
 * from any previous animations is complete, then the properties keyed by the
 * animation are set to the setup pose and the track is cleared.
 *
 * It may be desired to use AnimationState::addEmptyAnimation(int, float, float)
 * rather than have the animation abruptly cease being applied.
 */
SPINE_C_API float spine_track_entry_get_track_end(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_track_end(spine_track_entry self, float inValue);
/**
 * Seconds when this animation starts, both initially and after looping.
 * Defaults to 0.
 *
 * When changing the animation start time, it often makes sense to set
 * TrackEntry.AnimationLast to the same value to prevent timeline keys before
 * the start time from triggering.
 */
SPINE_C_API float spine_track_entry_get_animation_start(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_animation_start(spine_track_entry self, float inValue);
/**
 * Seconds for the last frame of this animation. Non-looping animations won't
 * play past this time. Looping animations will loop back to
 * TrackEntry.AnimationStart at this time. Defaults to the animation duration.
 */
SPINE_C_API float spine_track_entry_get_animation_end(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_animation_end(spine_track_entry self, float inValue);
/**
 * The time in seconds this animation was last applied. Some timelines use this
 * for one-time triggers. Eg, when this animation is applied, event timelines
 * will fire all events between the animation last time (exclusive) and
 * animation time (inclusive). Defaults to -1 to ensure triggers on frame 0
 * happen the first time this animation is applied.
 */
SPINE_C_API float spine_track_entry_get_animation_last(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_animation_last(spine_track_entry self, float inValue);
/**
 * Uses getTrackTime() to compute the animationTime. When the trackTime is 0,
 * the animationTime is equal to the animationStart time.
 *
 * The animationTime is between getAnimationStart() and getAnimationEnd(),
 * except if this track entry is non-looping and getAnimationEnd() is >= to the
 * animation duration, then animationTime continues to increase past
 * getAnimationEnd().
 */
SPINE_C_API float spine_track_entry_get_animation_time(spine_track_entry self);
/**
 * Multiplier for the delta time when this track entry is updated, causing time
 * for this animation to pass slower or faster. Defaults to 1.
 *
 * Values < 0 are not supported. To play an animation in reverse, use
 * getReverse().
 *
 * getMixTime() is not affected by track entry time scale, so getMixDuration()
 * may need to be adjusted to match the animation speed.
 *
 * When using AnimationState::addAnimation(int, Animation, bool, float) with a
 * delay < = 0, the getDelay() is set using the mix duration from the
 * AnimationStateData, assuming time scale to be 1. If the time scale is not 1,
 * the delay may need to be adjusted.
 *
 * See AnimationState getTimeScale() for affecting all animations.
 */
SPINE_C_API float spine_track_entry_get_time_scale(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_time_scale(spine_track_entry self, float inValue);
/**
 * Values less than 1 mix this animation with the last skeleton pose. Defaults
 * to 1, which overwrites the last skeleton pose with this animation.
 *
 * Typically track 0 is used to completely pose the skeleton, then alpha can be
 * used on higher tracks. It doesn't make sense to use alpha on track 0 if the
 * skeleton pose is from the last frame render.
 */
SPINE_C_API float spine_track_entry_get_alpha(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_alpha(spine_track_entry self, float inValue);
/**
 * When the mix percentage (mix time / mix duration) is less than the event
 * threshold, event timelines for the animation being mixed out will be applied.
 * Defaults to 0, so event timelines are not applied for an animation being
 * mixed out.
 */
SPINE_C_API float spine_track_entry_get_event_threshold(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_event_threshold(spine_track_entry self, float inValue);
/**
 * When the mix percentage (mix time / mix duration) is less than the attachment
 * threshold, attachment timelines for the animation being mixed out will be
 * applied. Defaults to 0, so attachment timelines are not applied for an
 * animation being mixed out.
 */
SPINE_C_API float spine_track_entry_get_mix_attachment_threshold(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_mix_attachment_threshold(spine_track_entry self, float inValue);
/**
 * When getAlpha() is greater than alphaAttachmentThreshold, attachment
 * timelines are applied. Defaults to 0, so attachment timelines are always
 * applied.
 */
SPINE_C_API float spine_track_entry_get_alpha_attachment_threshold(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_alpha_attachment_threshold(spine_track_entry self, float inValue);
/**
 * When the mix percentage (mix time / mix duration) is less than the draw order
 * threshold, draw order timelines for the animation being mixed out will be
 * applied. Defaults to 0, so draw order timelines are not applied for an
 * animation being mixed out.
 */
SPINE_C_API float spine_track_entry_get_mix_draw_order_threshold(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_mix_draw_order_threshold(spine_track_entry self, float inValue);
/**
 * The animation queued to start after this animation, or NULL.
 */
SPINE_C_API /*@null*/ spine_track_entry spine_track_entry_get_next(spine_track_entry self);
/**
 * Returns true if at least one loop has been completed.
 */
SPINE_C_API bool spine_track_entry_is_complete(spine_track_entry self);
/**
 * Seconds from 0 to the mix duration when mixing from the previous animation to
 * this animation. May be slightly more than TrackEntry.MixDuration when the mix
 * is complete.
 */
SPINE_C_API float spine_track_entry_get_mix_time(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_mix_time(spine_track_entry self, float inValue);
/**
 * Seconds for mixing from the previous animation to this animation. Defaults to
 * the value provided by AnimationStateData based on the animation before this
 * animation (if any).
 *
 * The mix duration can be set manually rather than use the value from
 * AnimationStateData.GetMix. In that case, the mixDuration must be set before
 * AnimationState.update(float) is next called.
 *
 * When using AnimationState::addAnimation(int, Animation, bool, float) with a
 * delay less than or equal to 0, note the Delay is set using the mix duration
 * from the AnimationStateData
 */
SPINE_C_API float spine_track_entry_get_mix_duration(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_mix_duration_1(spine_track_entry self, float inValue);
/**
 * Sets both getMixDuration() and getDelay().
 *
 * @param delay If > 0, sets TrackEntry::getDelay(). If < = 0, the delay set is the duration of the previous track entry minus the specified mix duration plus the specified delay (ie the mix ends at (delay = 0) or before (delay < 0) the previous track entry duration). If the previous entry is looping, its next loop completion is used instead of its duration.
 */
SPINE_C_API void spine_track_entry_set_mix_duration_2(spine_track_entry self, float mixDuration, float delay);
SPINE_C_API spine_mix_blend spine_track_entry_get_mix_blend(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_mix_blend(spine_track_entry self, spine_mix_blend blend);
/**
 * The track entry for the previous animation when mixing from the previous
 * animation to this animation, or NULL if no mixing is currently occuring. When
 * mixing from multiple animations, MixingFrom makes up a double linked list
 * with MixingTo.
 */
SPINE_C_API /*@null*/ spine_track_entry spine_track_entry_get_mixing_from(spine_track_entry self);
/**
 * The track entry for the next animation when mixing from this animation, or
 * NULL if no mixing is currently occuring. When mixing from multiple
 * animations, MixingTo makes up a double linked list with MixingFrom.
 */
SPINE_C_API /*@null*/ spine_track_entry spine_track_entry_get_mixing_to(spine_track_entry self);
/**
 * Resets the rotation directions for mixing this entry's rotate timelines. This
 * can be useful to avoid bones rotating the long way around when using alpha
 * and starting animations on other tracks.
 *
 * Mixing involves finding a rotation between two others, which has two possible
 * solutions: the short way or the long way around. The two rotations likely
 * change over time, so which direction is the short or long way also changes.
 * If the short way was always chosen, bones would flip to the other side when
 * that direction became the long way. TrackEntry chooses the short way the
 * first time it is applied and remembers that direction.
 */
SPINE_C_API void spine_track_entry_reset_rotation_directions(spine_track_entry self);
SPINE_C_API float spine_track_entry_get_track_complete(spine_track_entry self);
/**
 * Returns true if this entry is for the empty animation.
 */
SPINE_C_API bool spine_track_entry_is_empty_animation(spine_track_entry self);
/**
 * Returns true if this track entry has been applied at least once.
 *
 * See AnimationState::apply(Skeleton).
 */
SPINE_C_API bool spine_track_entry_was_applied(spine_track_entry self);
/**
 * Returns true if there is a getNext() track entry that is ready to become the
 * current track entry during the next AnimationState::update(float)}
 */
SPINE_C_API bool spine_track_entry_is_next_ready(spine_track_entry self);
/**
 * The AnimationState this track entry belongs to. May be NULL if TrackEntry is
 * directly instantiated.
 */
SPINE_C_API /*@null*/ spine_animation_state spine_track_entry_get_animation_state(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_animation_state(spine_track_entry self, /*@null*/ spine_animation_state state);
SPINE_C_API /*@null*/ void *spine_track_entry_get_renderer_object(spine_track_entry self);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_TRACK_ENTRY_H */
