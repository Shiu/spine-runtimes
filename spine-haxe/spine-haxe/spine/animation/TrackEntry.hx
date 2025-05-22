/******************************************************************************
 * Spine Runtimes License Agreement
 * Last updated July 28, 2023. Replaces all prior versions.
 *
 * Copyright (c) 2013-2023, Esoteric Software LLC
 *
 * Integration of the Spine Runtimes into software or otherwise creating
 * derivative works of the Spine Runtimes is permitted under the terms and
 * conditions of Section 2 of the Spine Editor License Agreement:
 * http://esotericsoftware.com/spine-editor-license
 *
 * Otherwise, it is permitted to integrate the Spine Runtimes into software or
 * otherwise create derivative works of the Spine Runtimes (collectively,
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
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THE
 * SPINE RUNTIMES, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*****************************************************************************/

package spine.animation;

import spine.animation.Listeners.EventListeners;
import spine.Poolable;

/** Stores settings and other state for the playback of an animation on an {@link AnimationState} track.
 * <p>
 * References to a track entry must not be kept after the {@link AnimationStateListener#dispose(TrackEntry)} event occurs. */
class TrackEntry implements Poolable {
	/** The animation to apply for this track entry. */
	public var animation:Animation;
	/** The animation queued to start after this animation, or null if there is none. <code>next</code> makes up a doubly linked
	 * list.
	 * <p>
	 * See {@link AnimationState#clearNext(TrackEntry)} to truncate the list. */
	public var next:TrackEntry;
	/** The animation queued to play before this animation, or null. <code>previous</code> makes up a doubly linked list. */
	public var previous:TrackEntry;
	/** The track entry for the previous animation when mixing from the previous animation to this animation, or null if no
	 * mixing is currently occurring. When mixing from multiple animations, <code>mixingFrom</code> makes up a linked list. */
	public var mixingFrom:TrackEntry;
	/** The track entry for the next animation when mixing from this animation to the next animation, or null if no mixing is
	 * currently occurring. When mixing to multiple animations, <code>mixingTo</code> makes up a linked list. */
	public var mixingTo:TrackEntry;
	public var onStart:Listeners = new Listeners();
	public var onInterrupt:Listeners = new Listeners();
	public var onEnd:Listeners = new Listeners();
	public var onDispose:Listeners = new Listeners();
	public var onComplete:Listeners = new Listeners();
	public var onEvent:EventListeners = new EventListeners();
	/** The index of the track where this track entry is either current or queued.
	 * <p>
	 * See {@link AnimationState#getCurrent(int)}. */
	public var trackIndex:Int = 0;
	/** If true, the animation will repeat. If false it will not, instead its last frame is applied if played beyond its
	 * duration. */
	public var loop:Bool = false;
	/** If true, the animation will be applied in reverse. Events are not fired when an animation is applied in reverse. */
	public var reverse:Bool = false;
	/** If true, when mixing from the previous animation to this animation, the previous animation is applied as normal instead
	 * of being mixed out.
	 * <p>
	 * When mixing between animations that key the same property, if a lower track also keys that property then the value will
	 * briefly dip toward the lower track value during the mix. This happens because the first animation mixes from 100% to 0%
	 * while the second animation mixes from 0% to 100%. Setting <code>holdPrevious</code> to true applies the first animation
	 * at 100% during the mix so the lower track value is overwritten. Such dipping does not occur on the lowest track which
	 * keys the property, only when a higher track also keys the property.
	 * <p>
	 * Snapping will occur if <code>holdPrevious</code> is true and this animation does not key all the same properties as the
	 * previous animation. */
	public var holdPrevious:Bool = false;
	/** When the mix percentage ({@link #getMixTime()} / {@link #getMixDuration()}) is less than the
	 * <code>eventThreshold</code>, event timelines are applied while this animation is being mixed out. Defaults to 0, so event
	 * timelines are not applied while this animation is being mixed out. */
	public var eventThreshold:Float = 0;
	/** When the mix percentage ({@link #getMixTime()} / {@link #getMixDuration()}) is less than the
	 * <code>mixAttachmentThreshold</code>, attachment timelines are applied while this animation is being mixed out. Defaults
	 * to 0, so attachment timelines are not applied while this animation is being mixed out. */
	public var mixAttachmentThreshold:Float = 0;
	/** When {@link #getAlpha()} is greater than <code>alphaAttachmentThreshold</code>, attachment timelines are applied.
	 * Defaults to 0, so attachment timelines are always applied. */
	public var alphaAttachmentThreshold:Float = 0;
	/** When the mix percentage ({@link #getMixTime()} / {@link #getMixDuration()}) is less than the
	 * <code>mixDrawOrderThreshold</code>, draw order timelines are applied while this animation is being mixed out. Defaults to
	 * 0, so draw order timelines are not applied while this animation is being mixed out. */
	public var mixDrawOrderThreshold:Float = 0;
	/** Seconds when this animation starts, both initially and after looping. Defaults to 0.
	 * <p>
	 * When changing the <code>animationStart</code> time, it often makes sense to set {@link #getAnimationLast()} to the same
	 * value to prevent timeline keys before the start time from triggering. */
	public var animationStart:Float = 0;
	/** Seconds for the last frame of this animation. Non-looping animations won't play past this time. Looping animations will
	 * loop back to {@link #getAnimationStart()} at this time. Defaults to the animation {@link Animation#duration}. */
	public var animationEnd:Float = 0;
	/** The time in seconds this animation was last applied. Some timelines use this for one-time triggers. Eg, when this
	 * animation is applied, event timelines will fire all events between the <code>animationLast</code> time (exclusive) and
	 * <code>animationTime</code> (inclusive). Defaults to -1 to ensure triggers on frame 0 happen the first time this animation
	 * is applied. */
	public var animationLast:Float = 0;
	public var nextAnimationLast:Float = 0;

	/** Seconds to postpone playing the animation. Must be >= 0. When this track entry is the current track entry,
	* <code>delay</code> postpones incrementing the {@link #getTrackTime()}. When this track entry is queued,
	* <code>delay</code> is the time from the start of the previous animation to when this track entry will become the current
	* track entry (ie when the previous track entry {@link TrackEntry#getTrackTime()} >= this track entry's
	* <code>delay</code>).
	* <p>
	* {@link #getTimeScale()} affects the delay.
	* <p>
	* When passing <code>delay</code> <= 0 to {@link AnimationState#addAnimation(int, Animation, boolean, float)} this
	* <code>delay</code> is set using a mix duration from {@link AnimationStateData}. To change the {@link #getMixDuration()}
	* afterward, use {@link #setMixDuration(float, float)} so this <code>delay</code> is adjusted. */
	public var delay(default, set):Float = 0;

	/** Current time in seconds this track entry has been the current track entry. The track time determines
	 * {@link #getAnimationTime()}. The track time can be set to start the animation at a time other than 0, without affecting
	 * looping. */
	public var trackTime:Float = 0;
	public var trackLast:Float = 0;
	public var nextTrackLast:Float = 0;
	/** The track time in seconds when this animation will be removed from the track. Defaults to the highest possible float
	 * value, meaning the animation will be applied until a new animation is set or the track is cleared. If the track end time
	 * is reached, no other animations are queued for playback, and mixing from any previous animations is complete, then the
	 * properties keyed by the animation are set to the setup pose and the track is cleared.
	 * <p>
	 * It may be desired to use {@link AnimationState#addEmptyAnimation(int, float, float)} rather than have the animation
	 * abruptly cease being applied. */
	public var trackEnd:Float = 0;
	/** Multiplier for the delta time when this track entry is updated, causing time for this animation to pass slower or
	 * faster. Defaults to 1.
	 * <p>
	 * Values < 0 are not supported. To play an animation in reverse, use {@link #getReverse()}.
	 * <p>
	 * {@link #getMixTime()} is not affected by track entry time scale, so {@link #getMixDuration()} may need to be adjusted to
	 * match the animation speed.
	 * <p>
	 * When using {@link AnimationState#addAnimation(int, Animation, boolean, float)} with a <code>delay</code> <= 0, the
	 * {@link #getDelay()} is set using the mix duration from the {@link AnimationStateData}, assuming time scale to be 1. If
	 * the time scale is not 1, the delay may need to be adjusted.
	 * <p>
	 * See AnimationState {@link AnimationState#getTimeScale()} for affecting all animations. */
	public var timeScale:Float = 0;
	/** Values < 1 mix this animation with the skeleton's current pose (usually the pose resulting from lower tracks). Defaults
	 * to 1, which overwrites the skeleton's current pose with this animation.
	 * <p>
	 * Typically track 0 is used to completely pose the skeleton, then alpha is used on higher tracks. It doesn't make sense to
	 * use alpha on track 0 if the skeleton pose is from the last frame render. */
	public var alpha:Float = 0;
	/** Seconds from 0 to the {@link #getMixDuration()} when mixing from the previous animation to this animation. May be
	 * slightly more than <code>mixDuration</code> when the mix is complete. */
	public var mixTime:Float = 0;
	/** Seconds for mixing from the previous animation to this animation. Defaults to the value provided by AnimationStateData
	 * {@link AnimationStateData#getMix(Animation, Animation)} based on the animation before this animation (if any).
	 * <p>
	 * A mix duration of 0 still mixes out over one frame to provide the track entry being mixed out a chance to revert the
	 * properties it was animating. A mix duration of 0 can be set at any time to end the mix on the next
	 * {@link AnimationState#update(float) update}.
	 * <p>
	 * The <code>mixDuration</code> can be set manually rather than use the value from
	 * {@link AnimationStateData#getMix(Animation, Animation)}. In that case, the <code>mixDuration</code> can be set for a new
	 * track entry only before {@link AnimationState#update(float)} is first called.
	 * <p>
	 * When using {@link AnimationState#addAnimation(int, Animation, boolean, float)} with a <code>delay</code> <= 0, the
	 * {@link #getDelay()} is set using the mix duration from the {@link AnimationStateData}. If <code>mixDuration</code> is set
	 * afterward, the delay may need to be adjusted. For example:<br>
	 * <code>entry.delay = entry.previous.getTrackComplete() - entry.mixDuration;</code><br>
	 * Alternatively, {@link #setMixDuration(float, float)} can be used to recompute the delay:<br>
	 * <code>entry.setMixDuration(0.25f, 0);</code> */
	public var mixDuration:Float = 0;
	public var interruptAlpha:Float = 0;
	public var totalAlpha:Float = 0;
	/** Controls how properties keyed in the animation are mixed with lower tracks. Defaults to {@link MixBlend#replace}.
	 * <p>
	 * Track entries on track 0 ignore this setting and always use {@link MixBlend#first}.
	 * <p>
	 * The <code>mixBlend</code> can be set for a new track entry only before {@link AnimationState#apply(Skeleton)} is first
	 * called. */
	public var mixBlend:MixBlend = MixBlend.replace;
	public var timelineMode:Array<Int> = new Array<Int>();
	public var timelineHoldMix:Array<TrackEntry> = new Array<TrackEntry>();
	public var timelinesRotation:Array<Float> = new Array<Float>();
	/** If true, mixing rotation between tracks always uses the shortest rotation direction. If the rotation is animated, the
	 * shortest rotation direction may change during the mix.
	 * <p>
	 * If false, the shortest rotation direction is remembered when the mix starts and the same direction is used for the rest
	 * of the mix. Defaults to false. */
	public var shortestRotation = false;

	function set_delay(delay:Float):Float {
		if (delay < 0) throw new SpineException("delay must be >= 0.");
		return this.delay = delay;
	}

	public function new() {}

	/** Uses {@link #getTrackTime()} to compute the <code>animationTime</code>. When the <code>trackTime</code> is 0, the
	 * <code>animationTime</code> is equal to the <code>animationStart</code> time.
	 * <p>
	 * The <code>animationTime</code> is between {@link #getAnimationStart()} and {@link #getAnimationEnd()}, except if this
	 * track entry is non-looping and {@link #getAnimationEnd()} is >= to the animation {@link Animation#duration}, then
	 * <code>animationTime</code> continues to increase past {@link #getAnimationEnd()}. */
	public function getAnimationTime():Float {
		if (loop) {
			var duration:Float = animationEnd - animationStart;
			if (duration == 0)
				return animationStart;
			return (trackTime % duration) + animationStart;
		}
		return Math.min(trackTime + animationStart, animationEnd);
	}

	/** If this track entry is non-looping, the track time in seconds when {@link #getAnimationEnd()} is reached, or the current
	 * {@link #getTrackTime()} if it has already been reached. If this track entry is looping, the track time when this
	 * animation will reach its next {@link #getAnimationEnd()} (the next loop completion). */
	public function getTrackComplete():Float {
		var duration:Float = animationEnd - animationStart;
		if (duration != 0) {
			if (loop)
				return duration * (1 + Std.int(trackTime / duration)); // Completion of next loop.
			if (trackTime < duration)
				return duration; // Before duration.
		}
		return trackTime; // Next update.
	}

	/** Returns true if this track entry has been applied at least once.
	 * <p>
	 * See {@link AnimationState#apply(Skeleton)}. */
	public function wasApplied() {
		return nextTrackLast != -1;
	}

	/** Returns true if there is a {@link #getNext()} track entry and it will become the current track entry during the next
	* {@link AnimationState#update(float)}. */
	public function isNextReady():Bool {
		return next != null && nextTrackLast - next.delay >= 0;
	}

	public function reset():Void {
		next = null;
		previous = null;
		mixingFrom = null;
		mixingTo = null;
		animation = null;
		onStart.listeners.resize(0);
		onInterrupt.listeners.resize(0);
		onEnd.listeners.resize(0);
		onDispose.listeners.resize(0);
		onComplete.listeners.resize(0);
		onEvent.listeners.resize(0);
		timelineMode.resize(0);
		timelineHoldMix.resize(0);
		timelinesRotation.resize(0);
	}

	/** Resets the rotation directions for mixing this entry's rotate timelines. This can be useful to avoid bones rotating the
	 * long way around when using {@link #getAlpha()} and starting animations on other tracks.
	 * <p>
	 * Mixing with {@link MixBlend#replace} involves finding a rotation between two others, which has two possible solutions:
	 * the short way or the long way around. The two rotations likely change over time, so which direction is the short or long
	 * way also changes. If the short way was always chosen, bones would flip to the other side when that direction became the
	 * long way. TrackEntry chooses the short way the first time it is applied and remembers that direction. */
	public function resetRotationDirection():Void {
		timelinesRotation.resize(0);
	}

	/** Sets both {@link #getMixDuration()} and {@link #getDelay()}.
	 * @param mixDuration If > 0, sets {@link TrackEntry#getDelay()}. If <= 0, the delay set is the duration of the previous track
	 *           entry minus the specified mix duration plus the specified <code>delay</code> (ie the mix ends at
	 *           (<code>delay</code> = 0) or before (<code>delay</code> < 0) the previous track entry duration). If the previous
	 *           entry is looping, its next loop completion is used instead of its duration. */
	public function setMixDurationWithDelay(mixDuration:Float):Float {
		this.mixDuration = mixDuration;
		if (delay <= 0) {
			if (this.previous != null)
				delay = Math.max(delay + this.previous.getTrackComplete() - mixDuration, 0);
			else
				delay = 0;
		}
		return mixDuration;
	}
}
