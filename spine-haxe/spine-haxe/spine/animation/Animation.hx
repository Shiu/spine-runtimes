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
import spine.Event;
import spine.Skeleton;

/** Stores a list of timelines to animate a skeleton's pose over time. */
class Animation {
	private var _name:String;
	private var _timelines:Array<Timeline>;
	private var _timelineIds:StringMap<Bool> = new StringMap<Bool>();

	/** The duration of the animation in seconds, which is usually the highest time of all frames in the timeline. The duration is
	 * used to know when it has completed and when it should loop back to the start. */
	public var duration:Float = 0;

	public function new(name:String, timelines:Array<Timeline>, duration:Float) {
		if (name == null)
			throw new SpineException("name cannot be null.");
		_name = name;
		setTimelines(timelines);
		this.duration = duration;
	}

	public function setTimelines(timelines:Array<Timeline>) {
		if (timelines == null)
			throw new SpineException("timelines cannot be null.");
		_timelines = timelines;
		_timelineIds = new StringMap<Bool>();
		for (timeline in timelines) {
			var ids:Array<String> = timeline.propertyIds;
			for (id in ids) {
				_timelineIds.set(id, true);
			}
		}
	}

	/** Returns true if this animation contains a timeline with any of the specified property IDs. */
	public function hasTimeline(ids:Array<String>):Bool {
		for (id in ids) {
			if (_timelineIds.exists(id))
				return true;
		}
		return false;
	}

	/** Applies the animation's timelines to the specified skeleton.
	 * 
	 * See Timeline.apply().
	 * @param skeleton The skeleton the animation is being applied to. This provides access to the bones, slots, and other skeleton
	 *           components the timelines may change.
	 * @param lastTime The last time in seconds this animation was applied. Some timelines trigger only at specific times rather
	 *           than every frame. Pass -1 the first time an animation is applied to ensure frame 0 is triggered.
	 * @param time The time in seconds the skeleton is being posed for. Most timelines find the frame before and the frame after
	 *           this time and interpolate between the frame values. If beyond the duration and loop is
	 *           true then the animation will repeat, else the last frame will be applied.
	 * @param loop If true, the animation repeats after the duration.
	 * @param events If any events are fired, they are added to this list. Can be null to ignore fired events or if no timelines
	 *           fire events.
	 * @param alpha 0 applies the current or setup values (depending on blend). 1 applies the timeline values. Between
	 *           0 and 1 applies values between the current or setup values and the timeline values. By adjusting
	 *           alpha over time, an animation can be mixed in or out. alpha can also be useful to apply
	 *           animations on top of each other (layering).
	 * @param blend Controls how mixing is applied when alpha < 1.
	 * @param direction Indicates whether the timelines are mixing in or out. Used by timelines which perform instant transitions,
	 *           such as DrawOrderTimeline or AttachmentTimeline. */
	public function apply(skeleton:Skeleton, lastTime:Float, time:Float, loop:Bool, events:Array<Event>, alpha:Float, blend:MixBlend,
			direction:MixDirection):Void {
		if (skeleton == null)
			throw new SpineException("skeleton cannot be null.");

		if (loop && duration != 0) {
			time %= duration;
			if (lastTime > 0)
				lastTime %= duration;
		}

		for (timeline in timelines) {
			timeline.apply(skeleton, lastTime, time, events, alpha, blend, direction);
		}
	}

	/** The animation's name, which is unique across all animations in the skeleton. */
	public var name(get, never):String;

	private function get_name():String {
		return _name;
	}

	public function toString():String {
		return _name;
	}

	/** If the returned array or the timelines it contains are modified, setTimelines() must be called. */
	public var timelines(get, never):Array<Timeline>;

	private function get_timelines():Array<Timeline> {
		return _timelines;
	}
}
