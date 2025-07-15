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

import haxe.ds.StringMap;
import spine.animation.Listeners.EventListeners;
import spine.Event;
import spine.Pool;
import spine.Skeleton;

/**
 * Applies animations over time, queues animations for later playback, mixes (crossfading) between animations, and applies
 * multiple animations on top of each other (layering).
 *
 * @see https://esotericsoftware.com/spine-applying-animations/ Applying Animations in the Spine Runtimes Guide
 */
class AnimationState {
	/**
	 * 1) A previously applied timeline has set this property.
	 * Result: Mix from the current pose to the timeline pose.
	 */
	public static inline var SUBSEQUENT:Int = 0;

	/**
	 * 1) This is the first timeline to set this property.
	 * 2) The next track entry applied after this one does not have a timeline to set this property.
	 * Result: Mix from the setup pose to the timeline pose.
	 */
	public static inline var FIRST:Int = 1;

	/**
	 * 1) A previously applied timeline has set this property.
	 * 2) The next track entry to be applied does have a timeline to set this property.
	 * 3) The next track entry after that one does not have a timeline to set this property.
	 * Result: Mix from the current pose to the timeline pose, but do not mix out. This avoids "dipping" when crossfading
	 * animations that key the same property. A subsequent timeline will set this property using a mix.
	 */
	public static inline var HOLD_SUBSEQUENT:Int = 2;

	/**
	 * 1) This is the first timeline to set this property.
	 * 2) The next track entry to be applied does have a timeline to set this property.
	 * 3) The next track entry after that one does not have a timeline to set this property.
	 * Result: Mix from the setup pose to the timeline pose, but do not mix out. This avoids "dipping" when crossfading animations
	 * that key the same property. A subsequent timeline will set this property using a mix.
	 */
	public static inline var HOLD_FIRST:Int = 3;

	/**
	 * 1) This is the first timeline to set this property.
	 * 2) The next track entry to be applied does have a timeline to set this property.
	 * 3) The next track entry after that one does have a timeline to set this property.
	 * 4) timelineHoldMix stores the first subsequent track entry that does not have a timeline to set this property.
	 * Result: The same as HOLD except the mix percentage from the timelineHoldMix track entry is used. This handles when more than
	 * 2 track entries in a row have a timeline that sets the same property.
	 * Eg, A -> B -> C -> D where A, B, and C have a timeline setting same property, but D does not. When A is applied, to avoid
	 * "dipping" A is not mixed out, however D (the first entry that doesn't set the property) mixing in is used to mix out A
	 * (which affects B and C). Without using D to mix out, A would be applied fully until mixing completes, then snap to the mixed
	 * out position.
	 */
	public static inline var HOLD_MIX:Int = 4;

	public static inline var SETUP:Int = 1;
	public static inline var CURRENT:Int = 2;

	private static var emptyAnimation:Animation = new Animation("<empty>", new Array<Timeline>(), 0);

	public var data:AnimationStateData;
	public var tracks:Array<TrackEntry> = new Array<TrackEntry>();

	private var events:Array<Event> = new Array<Event>();

	public var onStart:Listeners = new Listeners();
	public var onInterrupt:Listeners = new Listeners();
	public var onEnd:Listeners = new Listeners();
	public var onDispose:Listeners = new Listeners();
	public var onComplete:Listeners = new Listeners();
	public var onEvent:EventListeners = new EventListeners();

	private var queue:EventQueue;
	private var propertyIDs:StringSet = new StringSet();

	public var animationsChanged:Bool = false;
	public var timeScale:Float = 1;
	public var trackEntryPool:Pool<TrackEntry>;

	private var unkeyedState:Int = 0;

	/**
	 * Creates an uninitialized AnimationState. The animation state data must be set before use.
	 */
	public function new(data:AnimationStateData) {
		if (data == null)
			throw new SpineException("data can not be null");
		this.data = data;
		this.queue = new EventQueue(this);
		this.trackEntryPool = new Pool(function():Dynamic {
			return new TrackEntry();
		});
	}

	/**
	 * Increments each track entry spine.animation.TrackEntry.getTrackTime(), setting queued animations as current if needed.
	 */
	public function update(delta:Float):Void {
		delta *= timeScale;
		for (i in 0...tracks.length) {
			var current:TrackEntry = tracks[i];
			if (current == null)
				continue;

			current.animationLast = current.nextAnimationLast;
			current.trackLast = current.nextTrackLast;

			var currentDelta:Float = delta * current.timeScale;

			if (current.delay > 0) {
				current.delay -= currentDelta;
				if (current.delay > 0)
					continue;
				currentDelta = -current.delay;
				current.delay = 0;
			}

			var next:TrackEntry = current.next;
			if (next != null) {
				// When the next entry's delay is passed, change to the next entry, preserving leftover time.
				var nextTime:Float = current.trackLast - next.delay;
				if (nextTime >= 0) {
					next.delay = 0;
					next.trackTime = current.timeScale == 0 ? 0 : (nextTime / current.timeScale + delta) * next.timeScale;
					current.trackTime += currentDelta;
					setCurrent(i, next, true);
					while (next.mixingFrom != null) {
						next.mixTime += currentDelta;
						next = next.mixingFrom;
					}
					continue;
				}
			} else if (current.trackLast >= current.trackEnd && current.mixingFrom == null) {
				// Clear the track when there is no next entry, the track end time is reached, and there is no mixingFrom.
				tracks[i] = null;
				queue.end(current);
				clearNext(current);
				continue;
			}

			if (current.mixingFrom != null && updateMixingFrom(current, delta)) {
				// End mixing from entries once all have completed.
				var from:TrackEntry = current.mixingFrom;
				current.mixingFrom = null;
				if (from != null)
					from.mixingTo = null;
				while (from != null) {
					queue.end(from);
					from = from.mixingFrom;
				}
			}

			current.trackTime += currentDelta;
		}

		queue.drain();
	}

	/**
	 * Returns true when all mixing from entries are complete.
	 */
	private function updateMixingFrom(to:TrackEntry, delta:Float):Bool {
		var from:TrackEntry = to.mixingFrom;
		if (from == null)
			return true;

		var finished:Bool = updateMixingFrom(from, delta);

		from.animationLast = from.nextAnimationLast;
		from.trackLast = from.nextTrackLast;

		// The from entry was applied at least once and the mix is complete.
		if (to.nextTrackLast != -1 && to.mixTime >= to.mixDuration) {
			// Mixing is complete for all entries before the from entry or the mix is instantaneous.
			if (from.totalAlpha == 0 || to.mixDuration == 0) {
				to.mixingFrom = from.mixingFrom;
				if (from.mixingFrom != null)
					from.mixingFrom.mixingTo = to;
				to.interruptAlpha = from.interruptAlpha;
				queue.end(from);
			}
			return finished;
		}

		from.trackTime += delta * from.timeScale;
		to.mixTime += delta;
		return false;
	}

	/**
	 * Poses the skeleton using the track entry animations. The animation state is not changed, so can be applied to multiple
	 * skeletons to pose them identically.
	 * @return True if any animations were applied.
	 */
	public function apply(skeleton:Skeleton):Bool {
		if (skeleton == null)
			throw new SpineException("skeleton cannot be null.");
		if (animationsChanged)
			_animationsChanged();
		var applied:Bool = false;

		for (i in 0...tracks.length) {
			var current:TrackEntry = tracks[i];
			if (current == null || current.delay > 0)
				continue;
			applied = true;
			var blend:MixBlend = i == 0 ? MixBlend.first : current.mixBlend;

			// Apply mixing from entries first.
			var alpha:Float = current.alpha;
			if (current.mixingFrom != null) {
				alpha *= applyMixingFrom(current, skeleton, blend);
			} else if (current.trackTime >= current.trackEnd && current.next == null) {
				alpha = 0;
			}
			var attachments:Bool = alpha >= current.alphaAttachmentThreshold;

			// Apply current entry.
			var animationLast:Float = current.animationLast,
				animationTime:Float = current.getAnimationTime(),
				applyTime:Float = animationTime;
			var applyEvents:Array<Event> = events;
			if (current.reverse) {
				applyTime = current.animation.duration - applyTime;
				applyEvents = null;
			}
			var timelines:Array<Timeline> = current.animation.timelines;
			var timelineCount:Int = timelines.length;
			var timeline:Timeline;
			if ((i == 0 && alpha == 1) || blend == MixBlend.add) {
				if (i == 0)
					attachments = true;
				for (timeline in timelines) {
					if (Std.isOfType(timeline, AttachmentTimeline)) {
						applyAttachmentTimeline(cast(timeline, AttachmentTimeline), skeleton, applyTime, blend, attachments);
					} else {
						timeline.apply(skeleton, animationLast, applyTime, applyEvents, alpha, blend, MixDirection.mixIn, false);
					}
				}
			} else {
				var timelineMode:Array<Int> = current.timelineMode;

				var shortestRotation = current.shortestRotation;
				var firstFrame:Bool = !shortestRotation && current.timelinesRotation.length != timelineCount << 1;
				if (firstFrame)
					current.timelinesRotation.resize(timelineCount << 1);

				for (ii in 0...timelineCount) {
					var timeline:Timeline = timelines[ii];
					var timelineBlend:MixBlend = timelineMode[ii] == SUBSEQUENT ? blend : MixBlend.setup;
					if (!shortestRotation && Std.isOfType(timeline, RotateTimeline)) {
						this.applyRotateTimeline(cast(timeline, RotateTimeline), skeleton, applyTime, alpha, timelineBlend, current.timelinesRotation,
							ii << 1, firstFrame);
					} else if (Std.isOfType(timeline, AttachmentTimeline)) {
						this.applyAttachmentTimeline(cast(timeline, AttachmentTimeline), skeleton, applyTime, blend, attachments);
					} else {
						timeline.apply(skeleton, animationLast, applyTime, applyEvents, alpha, timelineBlend, MixDirection.mixIn, false);
					}
				}
			}
			queueEvents(current, animationTime);
			events.resize(0);
			current.nextAnimationLast = animationTime;
			current.nextTrackLast = current.trackTime;
		}

		// Set slots attachments to the setup pose, if needed. This occurs if an animation that is mixing out sets attachments so
		// subsequent timelines see any deform, but the subsequent timelines don't set an attachment (eg they are also mixing out or
		// the time is before the first key).
		var setupState:Int = unkeyedState + SETUP;
		for (slot in skeleton.slots) {
			if (slot.attachmentState == setupState) {
				var attachmentName:String = slot.data.attachmentName;
				slot.pose.attachment = attachmentName == null ? null : skeleton.getAttachmentForSlotIndex(slot.data.index, attachmentName);
			}
		}
		unkeyedState += 2; // Increasing after each use avoids the need to reset attachmentState for every slot.

		queue.drain();
		return applied;
	}

	private function applyMixingFrom(to:TrackEntry, skeleton:Skeleton, blend:MixBlend):Float {
		var from:TrackEntry = to.mixingFrom;
		if (from.mixingFrom != null)
			applyMixingFrom(from, skeleton, blend);

		var mix:Float = 0;
		if (to.mixDuration == 0) // Single frame mix to undo mixingFrom changes.
		{
			mix = 1;
			if (blend == MixBlend.first)
				blend = MixBlend.setup;
		} else {
			mix = to.mixTime / to.mixDuration;
			if (mix > 1)
				mix = 1;
			if (blend != MixBlend.first)
				blend = from.mixBlend;
		}

		var attachments:Bool = mix < from.mixAttachmentThreshold,
			drawOrder:Bool = mix < from.mixDrawOrderThreshold;
		var timelineCount:Int = from.animation.timelines.length;
		var timelines:Array<Timeline> = from.animation.timelines;
		var alphaHold:Float = from.alpha * to.interruptAlpha,
			alphaMix:Float = alphaHold * (1 - mix);
		var animationLast:Float = from.animationLast,
			animationTime:Float = from.getAnimationTime(),
			applyTime:Float = animationTime;
		var applyEvents:Array<Event> = null;
		if (from.reverse) {
			applyTime = from.animation.duration - applyTime;
		} else if (mix < from.eventThreshold) {
			applyEvents = events;
		}

		if (blend == MixBlend.add) {
			for (timeline in timelines) {
				timeline.apply(skeleton, animationLast, applyTime, applyEvents, alphaMix, blend, MixDirection.mixOut, false);
			}
		} else {
			var timelineMode:Array<Int> = from.timelineMode;
			var timelineHoldMix:Array<TrackEntry> = from.timelineHoldMix;
			var shortestRotation = from.shortestRotation;

			var firstFrame:Bool = !shortestRotation && from.timelinesRotation.length != timelineCount << 1;
			if (firstFrame)
				from.timelinesRotation.resize(timelineCount << 1);
			var timelinesRotation:Array<Float> = from.timelinesRotation;

			from.totalAlpha = 0;
			for (i in 0...timelineCount) {
				var timeline:Timeline = timelines[i];
				var direction:MixDirection = MixDirection.mixOut;
				var timelineBlend:MixBlend;
				var alpha:Float = 0;
				switch (timelineMode[i]) {
					case SUBSEQUENT:
						if (!drawOrder && Std.isOfType(timeline, DrawOrderTimeline))
							continue;
						timelineBlend = blend;
						alpha = alphaMix;
					case FIRST:
						timelineBlend = MixBlend.setup;
						alpha = alphaMix;
					case HOLD_SUBSEQUENT:
						timelineBlend = blend;
						alpha = alphaHold;
					case HOLD_FIRST:
						timelineBlend = MixBlend.setup;
						alpha = alphaHold;
					default:
						timelineBlend = MixBlend.setup;
						var holdMix:TrackEntry = timelineHoldMix[i];
						alpha = alphaHold * Math.max(0, 1 - holdMix.mixTime / holdMix.mixDuration);
				}
				from.totalAlpha += alpha;

				if (!shortestRotation && Std.isOfType(timeline, RotateTimeline)) {
					applyRotateTimeline(cast(timeline, RotateTimeline), skeleton, applyTime, alpha, timelineBlend, from.timelinesRotation, i << 1, firstFrame);
				} else if (Std.isOfType(timeline, AttachmentTimeline)) {
					applyAttachmentTimeline(cast(timeline, AttachmentTimeline), skeleton, applyTime,
						timelineBlend, attachments && alpha >= from.alphaAttachmentThreshold);
				} else {
					if (drawOrder && Std.isOfType(timeline, DrawOrderTimeline) && timelineBlend == MixBlend.setup)
						direction = MixDirection.mixIn;
					timeline.apply(skeleton, animationLast, applyTime, events, alpha, timelineBlend, direction, false);
				}
			}
		}

		if (to.mixDuration > 0)
			queueEvents(from, animationTime);
		events.resize(0);
		from.nextAnimationLast = animationTime;
		from.nextTrackLast = from.trackTime;

		return mix;
	}

	/**
	 * Applies the attachment timeline and sets spine.Slot.attachmentState.
	 * @param attachments False when: 1) the attachment timeline is mixing out, 2) mix < attachmentThreshold, and 3) the timeline
	 *           is not the last timeline to set the slot's attachment. In that case the timeline is applied only so subsequent
	 *           timelines see any deform.
	 */
	public function applyAttachmentTimeline(timeline:AttachmentTimeline, skeleton:Skeleton, time:Float, blend:MixBlend, attachments:Bool) {
		var slot = skeleton.slots[timeline.slotIndex];
		if (!slot.bone.active)
			return;

		if (time < timeline.frames[0]) { // Time is before first frame.
			if (blend == MixBlend.setup || blend == MixBlend.first)
				this.setAttachment(skeleton, slot, slot.data.attachmentName, attachments);
		} else
			this.setAttachment(skeleton, slot, timeline.attachmentNames[Timeline.search1(timeline.frames, time)], attachments);

		// If an attachment wasn't set (ie before the first frame or attachments is false), set the setup attachment later.
		if (slot.attachmentState <= this.unkeyedState)
			slot.attachmentState = this.unkeyedState + SETUP;
	}

	/**
	 * Applies the rotate timeline, mixing with the current pose while keeping the same rotation direction chosen as the shortest
	 * the first time the mixing was applied.
	 */
	public function applyRotateTimeline(timeline:RotateTimeline, skeleton:Skeleton, time:Float, alpha:Float, blend:MixBlend, timelinesRotation:Array<Float>,
			i:Int, firstFrame:Bool) {
		if (firstFrame)
			timelinesRotation[i] = 0;

		if (alpha == 1) {
			timeline.apply(skeleton, 0, time, null, 1, blend, MixDirection.mixIn, false);
			return;
		}

		var bone = skeleton.bones[timeline.boneIndex];
		if (!bone.active)
			return;
		var pose = bone.pose, setup = bone.data.setup;
		var frames = timeline.frames;
		var r1:Float = 0, r2:Float = 0;
		if (time < frames[0]) {
			switch (blend) {
				case MixBlend.setup:
					pose.rotation = setup.rotation;
				default:
					return;
				case MixBlend.first:
					r1 = pose.rotation;
					r2 = setup.rotation;
			}
		} else {
			r1 = blend == MixBlend.setup ? setup.rotation : pose.rotation;
			r2 = setup.rotation + timeline.getCurveValue(time);
		}

		// Mix between rotations using the direction of the shortest route on the first frame while detecting crosses.
		var total:Float = 0, diff:Float = r2 - r1;
		diff -= Math.ceil(diff / 360 - 0.5) * 360;
		if (diff == 0) {
			total = timelinesRotation[i];
		} else {
			var lastTotal:Float = 0, lastDiff:Float = 0;
			if (firstFrame) {
				lastTotal = 0;
				lastDiff = diff;
			} else {
				lastTotal = timelinesRotation[i];
				lastDiff = timelinesRotation[i + 1];
			}
			var loops:Float = lastTotal - lastTotal % 360;
			total = diff + loops;
			var current = diff >= 0, dir = lastTotal >= 0;
			if (Math.abs(lastDiff) <= 90 && MathUtils.signum(lastDiff) != MathUtils.signum(diff)) {
				if (Math.abs(lastTotal - loops) > 180) {
					total += 360 * MathUtils.signum(lastTotal);
					dir = current;
				} else if (loops != 0)
					total -= 360 * MathUtils.signum(lastTotal);
				else
					dir = current;
			}
			if (dir != current)
				total += 360 * MathUtils.signum(lastTotal);
			timelinesRotation[i] = total;
		}
		timelinesRotation[i + 1] = diff;
		pose.rotation = r1 + total * alpha;
	}

	private function setAttachment(skeleton:Skeleton, slot:Slot, attachmentName:String, attachments:Bool):Void {
		slot.pose.attachment = attachmentName == null ? null : skeleton.getAttachmentForSlotIndex(slot.data.index, attachmentName);
		if (attachments)
			slot.attachmentState = unkeyedState + CURRENT;
	}

	private function queueEvents(entry:TrackEntry, animationTime:Float):Void {
		var animationStart:Float = entry.animationStart,
			animationEnd:Float = entry.animationEnd;
		var duration:Float = animationEnd - animationStart;
		var trackLastWrapped:Float = entry.trackLast % duration;

		// Queue events before complete.
		var event:Event;
		var i:Int = 0;
		var n:Int = events.length;
		while (i < n) {
			event = events[i++];
			if (event == null)
				continue;
			if (event.time < trackLastWrapped)
				break;
			if (event.time > animationEnd)
				continue; // Discard events outside animation start/end.
			queue.event(entry, event);
		}

		// Queue complete if completed a loop iteration or the animation.
		var complete = false;
		if (entry.loop) {
			if (duration == 0)
				complete = true;
			else {
				var cycles:Float = Math.floor(entry.trackTime / duration);
				complete = cycles > 0 && cycles > Math.floor(entry.trackLast / duration);
			}
		} else
			complete = animationTime >= animationEnd && entry.animationLast < animationEnd;
		if (complete)
			queue.complete(entry);

		// Queue events after complete.
		while (i < n) {
			event = events[i++];
			if (event == null)
				continue;
			if (event.time < animationStart)
				continue; // Discard events outside animation start/end.
			queue.event(entry, event);
		}
	}

	/**
	 * Removes all animations from all tracks, leaving skeletons in their current pose.
	 *
	 * It may be desired to use spine.animation.AnimationState.setEmptyAnimations() to mix the skeletons back to the setup pose,
	 * rather than leaving them in their current pose.
	 */
	public function clearTracks():Void {
		var oldTrainDisabled:Bool = queue.drainDisabled;
		queue.drainDisabled = true;
		for (i in 0...tracks.length) {
			clearTrack(i);
		}
		tracks.resize(0);
		queue.drainDisabled = oldTrainDisabled;
		queue.drain();
	}

	/**
	 * Removes all animations from the track, leaving skeletons in their current pose.
	 *
	 * It may be desired to use spine.animation.AnimationState.setEmptyAnimation() to mix the skeletons back to the setup pose,
	 * rather than leaving them in their current pose.
	 */
	public function clearTrack(trackIndex:Int):Void {
		if (trackIndex >= tracks.length)
			return;
		var current:TrackEntry = tracks[trackIndex];
		if (current == null)
			return;

		queue.end(current);
		clearNext(current);

		var entry:TrackEntry = current;
		while (true) {
			var from:TrackEntry = entry.mixingFrom;
			if (from == null)
				break;
			queue.end(from);
			entry.mixingFrom = null;
			entry.mixingTo = null;
			entry = from;
		}

		tracks[current.trackIndex] = null;

		queue.drain();
	}

	private function setCurrent(index:Int, current:TrackEntry, interrupt:Bool):Void {
		var from:TrackEntry = expandToIndex(index);
		tracks[index] = current;

		if (from != null) {
			if (interrupt)
				queue.interrupt(from);
			current.mixingFrom = from;
			from.mixingTo = current;
			current.mixTime = 0;

			// Store the interrupted mix percentage.
			if (from.mixingFrom != null && from.mixDuration > 0) {
				current.interruptAlpha *= Math.min(1, from.mixTime / from.mixDuration);
			}

			from.timelinesRotation.resize(0); // Reset rotation for mixing out, in case entry was mixed in.
		}

		queue.start(current);
	}

	/**
	 * Sets an animation by name.
	 *
	 * See spine.animation.AnimationState.setAnimation().
	 */
	public function setAnimationByName(trackIndex:Int, animationName:String, loop:Bool):TrackEntry {
		var animation:Animation = data.skeletonData.findAnimation(animationName);
		if (animation == null)
			throw new SpineException("Animation not found: " + animationName);
		return setAnimation(trackIndex, animation, loop);
	}

	/** Sets the current animation for a track, discarding any queued animations.
	 * If the formerly current track entry is for the same animation and was never applied to a skeleton, it is replaced (not mixed
	 * from).
	 * @param loop If true, the animation will repeat. If false it will not, instead its last frame is applied if played beyond its
	 *           duration. In either case spine.animation.TrackEntry.getTrackEnd() determines when the track is cleared.
	 * @return A track entry to allow further customization of animation playback. References to the track entry must not be kept
	 *         after the spine.animation.AnimationStateListener.dispose() event occurs.
	 */
	public function setAnimation(trackIndex:Int, animation:Animation, loop:Bool):TrackEntry {
		if (animation == null)
			throw new SpineException("animation cannot be null.");
		var interrupt:Bool = true;
		var current:TrackEntry = expandToIndex(trackIndex);
		if (current != null) {
			if (current.nextTrackLast == -1 && current.animation == animation) {
				// Don't mix from an entry that was never applied.
				tracks[trackIndex] = current.mixingFrom;
				queue.interrupt(current);
				queue.end(current);
				clearNext(current);
				current = current.mixingFrom;
				interrupt = false;
			} else {
				clearNext(current);
			}
		}
		var entry:TrackEntry = trackEntry(trackIndex, animation, loop, current);
		setCurrent(trackIndex, entry, interrupt);
		queue.drain();
		return entry;
	}

	/**
	 * Queues an animation by name.
	 *
	 * See spine.animation.AnimationState.addAnimation().
	 */
	public function addAnimationByName(trackIndex:Int, animationName:String, loop:Bool, delay:Float):TrackEntry {
		var animation:Animation = data.skeletonData.findAnimation(animationName);
		if (animation == null)
			throw new SpineException("Animation not found: " + animationName);
		return addAnimation(trackIndex, animation, loop, delay);
	}

	/** Adds an animation to be played after the current or last queued animation for a track. If the track has no entries, this is
	 * equivalent to calling spine.animation.AnimationState.setAnimation().
	 * @param delay If > 0, sets spine.animation.TrackEntry.getDelay(). If <= 0, the delay set is the duration of the previous track entry
	 *           minus any mix duration (from the spine.animation.AnimationStateData) plus the specified delay (ie the mix
	 *           ends at (delay = 0) or before (delay < 0) the previous track entry duration). If the
	 *           previous entry is looping, its next loop completion is used instead of its duration.
	 * @return A track entry to allow further customization of animation playback. References to the track entry must not be kept
	 *         after the spine.animation.AnimationStateListener.dispose() event occurs.
	 */
	public function addAnimation(trackIndex:Int, animation:Animation, loop:Bool, delay:Float):TrackEntry {
		if (animation == null)
			throw new SpineException("animation cannot be null.");

		var last:TrackEntry = expandToIndex(trackIndex);
		if (last != null) {
			while (last.next != null) {
				last = last.next;
			}
		}

		var entry:TrackEntry = trackEntry(trackIndex, animation, loop, last);

		if (last == null) {
			setCurrent(trackIndex, entry, true);
			queue.drain();
			if (delay < 0)
				delay = 0;
		} else {
			last.next = entry;
			entry.previous = last;
			if (delay <= 0)
				delay = Math.max(delay + last.getTrackComplete() - entry.mixDuration, 0);
		}

		entry.delay = delay;
		return entry;
	}

	/**
	 * Sets an empty animation for a track, discarding any queued animations, and sets the track entry's
	 * spine.animation.TrackEntry.getMixDuration(). An empty animation has no timelines and serves as a placeholder for mixing in or out.
	 *
	 * Mixing out is done by setting an empty animation with a mix duration using either spine.animation.AnimationState.setEmptyAnimation(),
	 * spine.animation.AnimationState.setEmptyAnimations(), or spine.animation.AnimationState.addEmptyAnimation(). Mixing to an empty animation causes
	 * the previous animation to be applied less and less over the mix duration. Properties keyed in the previous animation
	 * transition to the value from lower tracks or to the setup pose value if no lower tracks key the property. A mix duration of
	 * 0 still mixes out over one frame.
	 *
	 * Mixing in is done by first setting an empty animation, then adding an animation using
	 * spine.animation.AnimationState.addAnimation() with the desired delay (an empty animation has a duration of 0) and on
	 * the returned track entry, set the spine.animation.TrackEntry.setMixDuration(). Mixing from an empty animation causes the new
	 * animation to be applied more and more over the mix duration. Properties keyed in the new animation transition from the value
	 * from lower tracks or from the setup pose value if no lower tracks key the property to the value keyed in the new
	 * animation.
	 *
	 * See <a href='https://esotericsoftware.com/spine-applying-animations/#Empty-animations'>Empty animations</a> in the Spine
	 * Runtimes Guide. */
	public function setEmptyAnimation(trackIndex:Int, mixDuration:Float):TrackEntry {
		var entry:TrackEntry = setAnimation(trackIndex, emptyAnimation, false);
		entry.mixDuration = mixDuration;
		entry.trackEnd = mixDuration;
		return entry;
	}

	/**
	 * Adds an empty animation to be played after the current or last queued animation for a track, and sets the track entry's
	 * spine.animation.TrackEntry.getMixDuration(). If the track has no entries,, it is equivalent to calling
	 * spine.animation.AnimationState.setEmptyAnimation().
	 *
	 * See spine.animation.AnimationState.setEmptyAnimation() and
	 * <a href='https://esotericsoftware.com/spine-applying-animations/#Empty-animations'>Empty animations</a> in the Spine
	 * Runtimes Guide.
	 * @param delay If > 0, sets spine.animation.TrackEntry.getDelay(). If <= 0, the delay set is the duration of the previous track entry
	 *           minus any mix duration plus the specified delay (ie the mix ends at (delay = 0) or
	 *           before (delay < 0) the previous track entry duration). If the previous entry is looping, its next
	 *           loop completion is used instead of its duration.
	 * @return A track entry to allow further customization of animation playback. References to the track entry must not be kept
	 *         after the spine.animation.AnimationStateListener.dispose() event occurs.
	 */
	public function addEmptyAnimation(trackIndex:Int, mixDuration:Float, delay:Float):TrackEntry {
		var entry:TrackEntry = addAnimation(trackIndex, emptyAnimation, false, delay);
		if (delay <= 0)
			entry.delay = Math.max(entry.delay + entry.mixDuration - mixDuration, 0);
		entry.mixDuration = mixDuration;
		entry.trackEnd = mixDuration;
		return entry;
	}

	/** Sets an empty animation for every track, discarding any queued animations, and mixes to it over the specified mix duration.
	 *
	 * See <a href='https://esotericsoftware.com/spine-applying-animations/#Empty-animations'>Empty animations</a> in the Spine
	 * Runtimes Guide. */
	public function setEmptyAnimations(mixDuration:Float):Void {
		var oldDrainDisabled:Bool = queue.drainDisabled;
		queue.drainDisabled = true;
		for (i in 0...tracks.length) {
			var current:TrackEntry = tracks[i];
			if (current != null)
				setEmptyAnimation(current.trackIndex, mixDuration);
		}
		queue.drainDisabled = oldDrainDisabled;
		queue.drain();
	}

	private function expandToIndex(index:Int):TrackEntry {
		if (index < tracks.length)
			return tracks[index];
		tracks.resize(index + 1);
		return null;
	}

	private function trackEntry(trackIndex:Int, animation:Animation, loop:Bool, last:TrackEntry):TrackEntry {
		var entry:TrackEntry = cast(trackEntryPool.obtain(), TrackEntry);
		entry.trackIndex = trackIndex;
		entry.animation = animation;
		entry.loop = loop;
		entry.holdPrevious = false;

		entry.reverse = false;
		entry.shortestRotation = false;

		entry.eventThreshold = 0;
		entry.alphaAttachmentThreshold = 0;
		entry.mixAttachmentThreshold = 0;
		entry.mixDrawOrderThreshold = 0;

		entry.animationStart = 0;
		entry.animationEnd = animation.duration;
		entry.animationLast = -1;
		entry.nextAnimationLast = -1;

		entry.delay = 0;
		entry.trackTime = 0;
		entry.trackLast = -1;
		entry.nextTrackLast = -1;
		entry.trackEnd = 2147483647;
		entry.timeScale = 1;

		entry.alpha = 1;
		entry.mixTime = 0;
		entry.mixDuration = last == null ? 0 : data.getMix(last.animation, animation);
		entry.interruptAlpha = 1;
		entry.totalAlpha = 0;
		entry.mixBlend = MixBlend.replace;
		return entry;
	}

	/**
	 * Removes the spine.animation.TrackEntry.getNext() next entry and all entries after it for the specified entry.
	 */
	public function clearNext(entry:TrackEntry):Void {
		var next:TrackEntry = entry.next;
		while (next != null) {
			queue.dispose(next);
			next = next.next;
		}
		entry.next = null;
	}

	private function _animationsChanged():Void {
		animationsChanged = false;

		propertyIDs.clear();
		var entry:TrackEntry = null;
		for (i in 0...tracks.length) {
			entry = tracks[i];
			if (entry == null)
				continue;
			while (entry.mixingFrom != null) {
				entry = entry.mixingFrom;
			}
			do {
				if (entry.mixingTo == null || entry.mixBlend != MixBlend.add)
					computeHold(entry);
				entry = entry.mixingTo;
			} while (entry != null);
		}
	}

	private function computeHold(entry:TrackEntry):Void {
		var to:TrackEntry = entry.mixingTo;
		var timelines:Array<Timeline> = entry.animation.timelines;
		var timelinesCount:Int = entry.animation.timelines.length;
		var timelineMode:Array<Int> = entry.timelineMode;
		timelineMode.resize(timelinesCount);
		entry.timelineHoldMix.resize(0);
		var timelineHoldMix:Array<TrackEntry> = entry.timelineHoldMix;
		timelineHoldMix.resize(timelinesCount);

		if (to != null && to.holdPrevious) {
			for (i in 0...timelinesCount) {
				timelineMode[i] = propertyIDs.addAll(timelines[i].propertyIds) ? HOLD_FIRST : HOLD_SUBSEQUENT;
			}
			return;
		}

		var continueOuter:Bool;
		for (i in 0...timelinesCount) {
			continueOuter = false;
			var timeline:Timeline = timelines[i];
			var ids:Array<String> = timeline.propertyIds;
			if (!propertyIDs.addAll(ids)) {
				timelineMode[i] = SUBSEQUENT;
			} else if (to == null
				|| Std.isOfType(timeline, AttachmentTimeline)
				|| Std.isOfType(timeline, DrawOrderTimeline)
				|| Std.isOfType(timeline, EventTimeline)
				|| !to.animation.hasTimeline(ids)) {
				timelineMode[i] = FIRST;
			} else {
				var next:TrackEntry = to.mixingTo;
				while (next != null) {
					if (next.animation.hasTimeline(ids)) {
						next = next.mixingTo;
						continue;
					}
					if (entry.mixDuration > 0) {
						timelineMode[i] = HOLD_MIX;
						timelineHoldMix[i] = next;
						continueOuter = true;
						break;
					}
					break;
				}
				if (continueOuter)
					continue;
				timelineMode[i] = HOLD_FIRST;
			}
		}
	}

	/**
	 * Returns the track entry for the animation currently playing on the track, or null if no animation is currently playing.
	 */
	public function getCurrent(trackIndex:Int):TrackEntry {
		if (trackIndex >= tracks.length)
			return null;
		return tracks[trackIndex];
	}

	public var fHasEndListener(get, never):Bool;

	private function get_fHasEndListener():Bool {
		return onComplete.listeners.length > 0 || onEnd.listeners.length > 0;
	}

	/**
	 * Removes all listeners added with spine.animation.AnimationState.addListener().
	 */
	public function clearListeners():Void {
		onStart.listeners.resize(0);
		onInterrupt.listeners.resize(0);
		onEnd.listeners.resize(0);
		onDispose.listeners.resize(0);
		onComplete.listeners.resize(0);
		onEvent.listeners.resize(0);
	}

	/**
	 * Discards all listener notifications that have not yet been delivered. This can be useful to call from an
	 * spine.animation.AnimationStateListener when it is known that further notifications that may have been already queued for delivery
	 * are not wanted because new animations are being set.
	 */
	public function clearListenerNotifications():Void {
		queue.clear();
	}
}

class StringSet {
	private var entries:StringMap<Bool> = new StringMap<Bool>();
	private var size:Int = 0;

	public function new() {}

	public function add(value:String):Bool {
		var contains:Bool = entries.exists(value);
		entries.set(value, true);
		if (!contains) {
			size++;
			return true;
		}
		return false;
	}

	public function addAll(values:Array<String>):Bool {
		var oldSize:Int = size;
		for (i in 0...values.length) {
			add(values[i]);
		}
		return oldSize != size;
	}

	public function contains(value:String):Bool {
		return entries.exists(value);
	}

	public function clear():Void {
		entries = new StringMap<Bool>();
		size = 0;
	}
}
