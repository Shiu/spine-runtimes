/******************************************************************************
 * Spine Runtimes License Agreement
 * Last updated April 5, 2025. Replaces all prior versions.
 *
 * Copyright (c) 2013-2025, Esoteric Software LLC
 *
 * Integration of the Spine Runtimes into software or otherwise creating
 * derivative works of the Spine Runtimes is permitted under the terms and
 * conditions of Section 2 of the Spine Editor License Agreement:
 * http://esotericsoftware.com/spine-editor-license
 *
 * Otherwise, it is permitted to integrate the Spine Runtimes into software
 * or otherwise create derivative works of the Spine Runtimes (collectively,
 * "Products"), provided that each user of the Products must obtain their own
 * Spine Editor license and redistribution of the Products in any form must
 * include this license and copyright notice.
 *
 * THE SPINE RUNTIMES ARE PROVIDED BY ESOTERIC SOFTWARE LLC "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ESOTERIC SOFTWARE LLC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES,
 * BUSINESS INTERRUPTION, OR LOSS OF USE, DATA, OR PROFITS) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THE SPINE RUNTIMES, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#ifndef Spine_AnimationState_h
#define Spine_AnimationState_h

#include <spine/Array.h>
#include <spine/Pool.h>
#include <spine/Property.h>
#include <spine/MixBlend.h>
#include <spine/SpineObject.h>
#include <spine/SpineString.h>
#include <spine/HasRendererObject.h>
#include "Slot.h"

#ifdef SPINE_USE_STD_FUNCTION
#include <functional>
#endif

namespace spine {
	enum EventType {
		EventType_Start = 0,
		EventType_Interrupt,
		EventType_End,
		EventType_Dispose,
		EventType_Complete,
		EventType_Event
	};

	class AnimationState;

	class TrackEntry;

	class Animation;

	class Event;

	class AnimationStateData;

	class Skeleton;

	class RotateTimeline;

	class AttachmentTimeline;

#ifdef SPINE_USE_STD_FUNCTION
	typedef std::function<void(AnimationState *state, EventType type, TrackEntry *entry, Event *event)> AnimationStateListener;
#else

	typedef void (*AnimationStateListener)(AnimationState *state, EventType type, TrackEntry *entry, Event *event, void *userData);

#endif

	/// Abstract class to inherit from to create a callback object
	class SP_API AnimationStateListenerObject {
	public:
		AnimationStateListenerObject() {};

		virtual ~AnimationStateListenerObject() {};

	public:
		/// The callback function to be called
		virtual void callback(AnimationState *state, EventType type, TrackEntry *entry, Event *event) = 0;
	};

	/// State for the playback of an animation
	class SP_API TrackEntry : public SpineObject, public HasRendererObject {
		friend class EventQueue;

		friend class AnimationState;

	public:
		TrackEntry();

		virtual ~TrackEntry();

		/// The index of the track where this entry is either current or queued.
		int getTrackIndex();

		/// The animation to apply for this track entry.
		Animation &getAnimation();

		/// Sets the animation for this track entry.
		void setAnimation(Animation &animation);

		TrackEntry *getPrevious();

		/// If true, the animation will repeat. If false, it will not, instead its last frame is applied if played beyond its duration.
		bool getLoop();

		void setLoop(bool inValue);

		/// If true, when mixing from the previous animation to this animation, the previous animation is applied as normal instead
		/// of being mixed out.
		///
		/// When mixing between animations that key the same property, if a lower track also keys that property then the value will
		/// briefly dip toward the lower track value during the mix. This happens because the first animation mixes from 100% to 0%
		/// while the second animation mixes from 0% to 100%. Setting holdPrevious to true applies the first animation
		/// at 100% during the mix so the lower track value is overwritten. Such dipping does not occur on the lowest track which
		/// keys the property, only when a higher track also keys the property.
		///
		/// Snapping will occur if holdPrevious is true and this animation does not key all the same properties as the
		/// previous animation.
		bool getHoldPrevious();

		void setHoldPrevious(bool inValue);

		bool getReverse();

		void setReverse(bool inValue);

		bool getShortestRotation();

		void setShortestRotation(bool inValue);

		/// Seconds to postpone playing the animation. Must be >= 0. When this track entry is the current track entry,
		/// delay postpones incrementing the getTrackTime(). When this track entry is queued,
		/// delay is the time from the start of the previous animation to when this track entry will become the current
		/// track entry (ie when the previous track entry getTrackTime() >= this track entry's
		/// delay).
		///
		/// getTimeScale() affects the delay.
		///
		/// When passing delay <= 0 to AnimationState::addAnimation(int, Animation, bool, float) this
		/// delay is set using a mix duration from AnimationStateData. To change the getMixDuration()
		/// afterward, use setMixDuration(float, float) so this delay is adjusted.
		float getDelay();

		void setDelay(float inValue);

		/// Current time in seconds this track entry has been the current track entry. The track time determines
		/// getAnimationTime(). The track time can be set to start the animation at a time other than 0, without affecting
		/// looping.
		float getTrackTime();

		void setTrackTime(float inValue);

		/// The track time in seconds when this animation will be removed from the track. Defaults to the highest possible float
		/// value, meaning the animation will be applied until a new animation is set or the track is cleared. If the track end time
		/// is reached, no other animations are queued for playback, and mixing from any previous animations is complete, then the
		/// properties keyed by the animation are set to the setup pose and the track is cleared.
		///
		/// It may be desired to use AnimationState::addEmptyAnimation(int, float, float) rather than have the animation
		/// abruptly cease being applied.
		float getTrackEnd();

		void setTrackEnd(float inValue);

		/// Seconds when this animation starts, both initially and after looping. Defaults to 0.
		///
		/// When changing the animation start time, it often makes sense to set TrackEntry.AnimationLast to the same value to
		/// prevent timeline keys before the start time from triggering.
		float getAnimationStart();

		void setAnimationStart(float inValue);

		/// Seconds for the last frame of this animation. Non-looping animations won't play past this time. Looping animations will
		/// loop back to TrackEntry.AnimationStart at this time. Defaults to the animation duration.
		float getAnimationEnd();

		void setAnimationEnd(float inValue);

		/// The time in seconds this animation was last applied. Some timelines use this for one-time triggers. Eg, when this
		/// animation is applied, event timelines will fire all events between the animation last time (exclusive) and animation time
		/// (inclusive). Defaults to -1 to ensure triggers on frame 0 happen the first time this animation is applied.
		float getAnimationLast();

		void setAnimationLast(float inValue);

		/// Uses getTrackTime() to compute the animationTime. When the trackTime is 0, the
		/// animationTime is equal to the animationStart time.
		///
		/// The animationTime is between getAnimationStart() and getAnimationEnd(), except if this
		/// track entry is non-looping and getAnimationEnd() is >= to the animation duration, then
		/// animationTime continues to increase past getAnimationEnd().
		float getAnimationTime();

		/// Multiplier for the delta time when this track entry is updated, causing time for this animation to pass slower or
		/// faster. Defaults to 1.
		///
		/// Values < 0 are not supported. To play an animation in reverse, use getReverse().
		///
		/// getMixTime() is not affected by track entry time scale, so getMixDuration() may need to be adjusted to
		/// match the animation speed.
		///
		/// When using AnimationState::addAnimation(int, Animation, bool, float) with a delay <= 0, the
		/// getDelay() is set using the mix duration from the AnimationStateData, assuming time scale to be 1. If
		/// the time scale is not 1, the delay may need to be adjusted.
		///
		/// See AnimationState getTimeScale() for affecting all animations.
		float getTimeScale();

		void setTimeScale(float inValue);

		/// Values less than 1 mix this animation with the last skeleton pose. Defaults to 1, which overwrites the last skeleton pose with
		/// this animation.
		///
		/// Typically track 0 is used to completely pose the skeleton, then alpha can be used on higher tracks. It doesn't make sense
		/// to use alpha on track 0 if the skeleton pose is from the last frame render.
		float getAlpha();

		void setAlpha(float inValue);

		///
		/// When the mix percentage (mix time / mix duration) is less than the event threshold, event timelines for the animation
		/// being mixed out will be applied. Defaults to 0, so event timelines are not applied for an animation being mixed out.
		float getEventThreshold();

		void setEventThreshold(float inValue);

		/// When the mix percentage (mix time / mix duration) is less than the attachment threshold, attachment timelines for the
		/// animation being mixed out will be applied. Defaults to 0, so attachment timelines are not applied for an animation being
		/// mixed out.
		float getMixAttachmentThreshold();

		void setMixAttachmentThreshold(float inValue);

		/// When getAlpha() is greater than alphaAttachmentThreshold, attachment timelines are applied.
		/// Defaults to 0, so attachment timelines are always applied. */
		float getAlphaAttachmentThreshold();

		void setAlphaAttachmentThreshold(float inValue);

		/// When the mix percentage (mix time / mix duration) is less than the draw order threshold, draw order timelines for the
		/// animation being mixed out will be applied. Defaults to 0, so draw order timelines are not applied for an animation being
		/// mixed out.
		float getMixDrawOrderThreshold();

		void setMixDrawOrderThreshold(float inValue);

		/// The animation queued to start after this animation, or NULL.
		TrackEntry *getNext();

		/// Returns true if at least one loop has been completed.
		bool isComplete();

		/// Seconds from 0 to the mix duration when mixing from the previous animation to this animation. May be slightly more than
		/// TrackEntry.MixDuration when the mix is complete.
		float getMixTime();

		void setMixTime(float inValue);

		/// Seconds for mixing from the previous animation to this animation. Defaults to the value provided by
		/// AnimationStateData based on the animation before this animation (if any).
		///
		/// The mix duration can be set manually rather than use the value from AnimationStateData.GetMix.
		/// In that case, the mixDuration must be set before AnimationState.update(float) is next called.
		///
		/// When using AnimationState::addAnimation(int, Animation, bool, float) with a delay
		/// less than or equal to 0, note the Delay is set using the mix duration from the AnimationStateData
		float getMixDuration();

		void setMixDuration(float inValue);

		/// Sets both getMixDuration() and getDelay().
		/// @param delay If > 0, sets TrackEntry::getDelay(). If <= 0, the delay set is the duration of the previous track
		///           entry minus the specified mix duration plus the specified delay (ie the mix ends at
		///           (delay = 0) or before (delay < 0) the previous track entry duration). If the previous
		///           entry is looping, its next loop completion is used instead of its duration.
		void setMixDuration(float mixDuration, float delay);

		MixBlend getMixBlend();

		void setMixBlend(MixBlend blend);

		/// The track entry for the previous animation when mixing from the previous animation to this animation, or NULL if no
		/// mixing is currently occuring. When mixing from multiple animations, MixingFrom makes up a double linked list with MixingTo.
		TrackEntry *getMixingFrom();

		/// The track entry for the next animation when mixing from this animation, or NULL if no mixing is currently occuring.
		/// When mixing from multiple animations, MixingTo makes up a double linked list with MixingFrom.
		TrackEntry *getMixingTo();

		/// Resets the rotation directions for mixing this entry's rotate timelines. This can be useful to avoid bones rotating the
		/// long way around when using alpha and starting animations on other tracks.
		///
		/// Mixing involves finding a rotation between two others, which has two possible solutions: the short way or the long way around.
		/// The two rotations likely change over time, so which direction is the short or long way also changes.
		/// If the short way was always chosen, bones would flip to the other side when that direction became the long way.
		/// TrackEntry chooses the short way the first time it is applied and remembers that direction.
		void resetRotationDirections();

		float getTrackComplete();

		void setListener(AnimationStateListener listener, void *userData = NULL);

		void setListener(AnimationStateListenerObject *listener);

		/// Returns true if this entry is for the empty animation.
		bool isEmptyAnimation();

		/// Returns true if this track entry has been applied at least once.
		///
		/// See AnimationState::apply(Skeleton).
		bool wasApplied();

		/// Returns true if there is a getNext() track entry that is ready to become the current track entry during the
		/// next AnimationState::update(float)}
		bool isNextReady() {
			return _next != NULL && _nextTrackLast - _next->_delay >= 0;
		}

		// The AnimationState this track entry belongs to. May be NULL if TrackEntry is directly instantiated.
		AnimationState *getAnimationState() {
			return _state;
		}

		void setAnimationState(AnimationState *state) {
			_state = state;
		}

	private:
		Animation *_animation;
		TrackEntry *_previous;
		TrackEntry *_next;
		TrackEntry *_mixingFrom;
		TrackEntry *_mixingTo;
		int _trackIndex;

		bool _loop, _holdPrevious, _reverse, _shortestRotation;
		float _eventThreshold, _mixAttachmentThreshold, _alphaAttachmentThreshold, _mixDrawOrderThreshold;
		float _animationStart, _animationEnd, _animationLast, _nextAnimationLast;
		float _delay, _trackTime, _trackLast, _nextTrackLast, _trackEnd, _timeScale;
		float _alpha, _mixTime, _mixDuration, _interruptAlpha, _totalAlpha;
		MixBlend _mixBlend;
		Array<int> _timelineMode;
		Array<TrackEntry *> _timelineHoldMix;
		Array<float> _timelinesRotation;
		AnimationStateListener _listener;
		void *_listenerUserData;
		AnimationStateListenerObject *_listenerObject;
		AnimationState *_state;

		void reset();
	};

	class SP_API EventQueueEntry : public SpineObject {
		friend class EventQueue;

	public:
		EventType _type;
		TrackEntry *_entry;
		Event *_event;

		EventQueueEntry(EventType eventType, TrackEntry *trackEntry, Event *event = NULL);
	};

	class SP_API EventQueue : public SpineObject {
		friend class AnimationState;

	private:
		Array<EventQueueEntry> _eventQueueEntries;
		AnimationState &_state;
		bool _drainDisabled;

		static EventQueue *newEventQueue(AnimationState &state);

		static EventQueueEntry newEventQueueEntry(EventType eventType, TrackEntry *entry, Event *event = NULL);

		EventQueue(AnimationState &state);

		~EventQueue();

		void start(TrackEntry *entry);

		void interrupt(TrackEntry *entry);

		void end(TrackEntry *entry);

		void dispose(TrackEntry *entry);

		void complete(TrackEntry *entry);

		void event(TrackEntry *entry, Event *event);

		/// Raises all events in the queue and drains the queue.
		void drain();
	};

	class SP_API AnimationState : public SpineObject, public HasRendererObject {
		friend class TrackEntry;

		friend class EventQueue;

	public:
		explicit AnimationState(AnimationStateData &data);

		~AnimationState();

		/// Increments each track entry TrackEntry::getTrackTime(), setting queued animations as current if needed.
		void update(float delta);

		/// Poses the skeleton using the track entry animations. The animation state is not changed, so can be applied to multiple
		/// skeletons to pose them identically.
		/// @return True if any animations were applied.
		bool apply(Skeleton &skeleton);

		/// Removes all animations from all tracks, leaving skeletons in their current pose.
		///
		/// It may be desired to use AnimationState::setEmptyAnimations(float) to mix the skeletons back to the setup pose,
		/// rather than leaving them in their current pose.
		void clearTracks();

		/// Removes all animations from the track, leaving skeletons in their current pose.
		///
		/// It may be desired to use AnimationState::setEmptyAnimation(int, float) to mix the skeletons back to the setup pose,
		/// rather than leaving them in their current pose.
		void clearTrack(size_t trackIndex);

		/// Sets an animation by name.
		///
		/// See setAnimation(int, Animation, bool).
		TrackEntry &setAnimation(size_t trackIndex, const String &animationName, bool loop);

		/// Sets the current animation for a track, discarding any queued animations.
		///
		/// If the formerly current track entry is for the same animation and was never applied to a skeleton, it is replaced (not mixed
		/// from).
		/// @param loop If true, the animation will repeat.
		/// If false, it will not, instead its last frame is applied if played beyond its duration.
		/// In either case TrackEntry.TrackEnd determines when the track is cleared.
		/// @return
		/// A track entry to allow further customization of animation playback. References to the track entry must not be kept
		/// after AnimationState.Dispose.
		TrackEntry &setAnimation(size_t trackIndex, Animation &animation, bool loop);

		/// Queues an animation by name.
		///
		/// See addAnimation(int, Animation, bool, float).
		TrackEntry &addAnimation(size_t trackIndex, const String &animationName, bool loop, float delay);

		/// Adds an animation to be played delay seconds after the current or last queued animation
		/// for a track. If the track has no entries, this is equivalent to calling setAnimation.
		/// @param delay
		/// Seconds to begin this animation after the start of the previous animation. May be &lt;= 0 to use the animation
		/// duration of the previous track minus any mix duration plus the negative delay.
		///
		/// @return A track entry to allow further customization of animation playback. References to the track entry must not be kept
		/// after AnimationState.Dispose
		TrackEntry &addAnimation(size_t trackIndex, Animation &animation, bool loop, float delay);

		/// Sets an empty animation for a track, discarding any queued animations, and sets the track entry's
		/// TrackEntry::getMixDuration(). An empty animation has no timelines and serves as a placeholder for mixing in or out.
		///
		/// Mixing out is done by setting an empty animation with a mix duration using either setEmptyAnimation(int, float),
		/// setEmptyAnimations(float), or addEmptyAnimation(int, float, float). Mixing to an empty animation causes
		/// the previous animation to be applied less and less over the mix duration. Properties keyed in the previous animation
		/// transition to the value from lower tracks or to the setup pose value if no lower tracks key the property. A mix duration of
		/// 0 still mixes out over one frame.
		///
		/// Mixing in is done by first setting an empty animation, then adding an animation using
		/// addAnimation(int, Animation, bool, float) with the desired delay (an empty animation has a duration of 0) and on
		/// the returned track entry, set the TrackEntry::setMixDuration(float). Mixing from an empty animation causes the new
		/// animation to be applied more and more over the mix duration. Properties keyed in the new animation transition from the value
		/// from lower tracks or from the setup pose value if no lower tracks key the property to the value keyed in the new animation.
		///
		/// See <a href='https://esotericsoftware.com/spine-applying-animations/#Empty-animations'>Empty animations</a> in the Spine
		/// Runtimes Guide.
		TrackEntry &setEmptyAnimation(size_t trackIndex, float mixDuration);

		/// Adds an empty animation to be played after the current or last queued animation for a track, and sets the track entry's
		/// TrackEntry::getMixDuration(). If the track has no entries, it is equivalent to calling
		/// setEmptyAnimation(int, float).
		///
		/// See setEmptyAnimation(int, float) and
		/// <a href='https://esotericsoftware.com/spine-applying-animations/#Empty-animations'>Empty animations</a> in the Spine
		/// Runtimes Guide.
		/// @param delay If > 0, sets TrackEntry::getDelay(). If <= 0, the delay set is the duration of the previous track entry
		/// minus any mix duration plus the specified <code>delay</code> (ie the mix ends at (<code>delay</code> = 0) or
		/// before (<code>delay</code> < 0) the previous track entry duration). If the previous entry is looping, its next
		/// loop completion is used instead of its duration.
		/// @return A track entry to allow further customization of animation playback. References to the track entry must not be kept
		/// after the AnimationStateListener::dispose(TrackEntry) event occurs.
		TrackEntry &addEmptyAnimation(size_t trackIndex, float mixDuration, float delay);

		/// Sets an empty animation for every track, discarding any queued animations, and mixes to it over the specified mix duration.
		///
		/// See <a href='https://esotericsoftware.com/spine-applying-animations/#Empty-animations'>Empty animations</a> in the Spine
		/// Runtimes Guide.
		void setEmptyAnimations(float mixDuration);

		/// @return The track entry for the animation currently playing on the track, or NULL if no animation is currently playing.
		TrackEntry *getCurrent(size_t trackIndex);

		/// The AnimationStateData to look up mix durations.
		AnimationStateData &getData();

		/// The list of tracks that have had animations, which may contain null entries for tracks that currently have no animation.
		Array<TrackEntry *> &getTracks();

		/// Multiplier for the delta time when the animation state is updated, causing time for all animations and mixes to play slower
		/// or faster. Defaults to 1.
		///
		/// See TrackEntry TrackEntry::getTimeScale() for affecting a single animation.
		float getTimeScale();

		void setTimeScale(float inValue);

		/// Adds a listener to receive events for all track entries.
		void setListener(AnimationStateListener listener, void *userData = NULL);

		/// Adds a listener to receive events for all track entries.
		void setListener(AnimationStateListenerObject *listener);

		void disableQueue();

		void enableQueue();

		void setManualTrackEntryDisposal(bool inValue);

		bool getManualTrackEntryDisposal();

		void disposeTrackEntry(TrackEntry *entry);

	private:
		static const int Subsequent = 0;
		static const int First = 1;
		static const int HoldSubsequent = 2;
		static const int HoldFirst = 3;
		static const int HoldMix = 4;

		static const int Setup = 1;
		static const int Current = 2;

		AnimationStateData *_data;

		Pool<TrackEntry> _trackEntryPool;
		Array<TrackEntry *> _tracks;
		Array<Event *> _events;
		EventQueue *_queue;

		HashMap<PropertyId, bool> _propertyIDs;
		bool _animationsChanged;

		AnimationStateListener _listener;
		void *_listenerUserData;
		AnimationStateListenerObject *_listenerObject;

		int _unkeyedState;

		float _timeScale;

		bool _manualTrackEntryDisposal;

		static Animation *getEmptyAnimation();

		/// Applies the rotate timeline, mixing with the current pose while keeping the same rotation direction chosen as the shortest
		/// the first time the mixing was applied.
		static void applyRotateTimeline(RotateTimeline *rotateTimeline, Skeleton &skeleton, float time, float alpha, MixBlend pose,
										Array<float> &timelinesRotation, size_t i, bool firstFrame);

		/// Applies the attachment timeline and sets Slot::attachmentState.
		/// @param attachments False when: 1) the attachment timeline is mixing out, 2) mix < attachmentThreshold, and 3) the timeline
		/// is not the last timeline to set the slot's attachment. In that case the timeline is applied only so subsequent
		/// timelines see any deform.
		void applyAttachmentTimeline(AttachmentTimeline *attachmentTimeline, Skeleton &skeleton, float animationTime, MixBlend pose,
									 bool attachments);

		/// Returns true when all mixing from entries are complete.
		bool updateMixingFrom(TrackEntry *to, float delta);

		float applyMixingFrom(TrackEntry *to, Skeleton &skeleton, MixBlend currentPose);

		void queueEvents(TrackEntry *entry, float animationTime);

		/// Sets the active TrackEntry for a given track number.
		void setCurrent(size_t index, TrackEntry *current, bool interrupt);

		/// Removes the TrackEntry::getNext() next entry and all entries after it for the specified entry.
		void clearNext(TrackEntry *entry);

		TrackEntry *expandToIndex(size_t index);

		/// Object-pooling version of new TrackEntry. Obtain an unused TrackEntry from the pool and clear/initialize its values.
		/// @param last May be NULL.
		TrackEntry *newTrackEntry(size_t trackIndex, Animation *animation, bool loop, TrackEntry *last);

		void animationsChanged();

		void computeHold(TrackEntry *entry);

		void setAttachment(Skeleton &skeleton, Slot &slot, const String &attachmentName, bool attachments);
	};
}

#endif /* Spine_AnimationState_h */
