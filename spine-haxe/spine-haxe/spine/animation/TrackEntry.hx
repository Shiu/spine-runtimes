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

package spine.animation;

import spine.animation.Listeners.EventListeners;
import spine.Poolable;

class TrackEntry implements Poolable {
	public var animation:Animation;
	public var next:TrackEntry;
	public var previous:TrackEntry;
	public var mixingFrom:TrackEntry;
	public var mixingTo:TrackEntry;
	public var onStart:Listeners = new Listeners();
	public var onInterrupt:Listeners = new Listeners();
	public var onEnd:Listeners = new Listeners();
	public var onDispose:Listeners = new Listeners();
	public var onComplete:Listeners = new Listeners();
	public var onEvent:EventListeners = new EventListeners();
	public var trackIndex:Int = 0;
	public var loop:Bool = false;
	public var reverse:Bool = false;
	public var holdPrevious:Bool = false;
	public var eventThreshold:Float = 0;
	public var mixAttachmentThreshold:Float = 0;
	public var alphaAttachmentThreshold:Float = 0;
	public var mixDrawOrderThreshold:Float = 0;
	public var animationStart:Float = 0;
	public var animationEnd:Float = 0;
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

	public var trackTime:Float = 0;
	public var trackLast:Float = 0;
	public var nextTrackLast:Float = 0;
	public var trackEnd:Float = 0;
	public var timeScale:Float = 0;
	public var alpha:Float = 0;
	public var mixTime:Float = 0;
	public var mixDuration:Float = 0;
	public var interruptAlpha:Float = 0;
	public var totalAlpha:Float = 0;
	public var mixBlend:MixBlend = MixBlend.replace;
	public var timelineMode:Array<Int> = new Array<Int>();
	public var timelineHoldMix:Array<TrackEntry> = new Array<TrackEntry>();
	public var timelinesRotation:Array<Float> = new Array<Float>();
	public var shortestRotation = false;

	function set_delay(delay:Float):Float {
		if (delay < 0) throw new SpineException("delay must be >= 0.");
		return this.delay = delay;
	}

	public function new() {}

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

	public function resetRotationDirection():Void {
		timelinesRotation.resize(0);
	}

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
