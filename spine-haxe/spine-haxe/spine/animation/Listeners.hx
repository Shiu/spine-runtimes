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

/** The interface to implement for receiving TrackEntry events. It is always safe to call AnimationState methods when receiving
 * events.
 * <p>
 * TrackEntry events are collected during {@link AnimationState#update(float)} and {@link AnimationState#apply(Skeleton)} and
 * fired only after those methods are finished.
 * <p>
 * See TrackEntry {@link TrackEntry#setListener(AnimationStateListener)} and AnimationState
 * {@link AnimationState#addListener(AnimationStateListener)}. */
class Listeners {
	private var _listeners:Array<TrackEntry->Void>;

	public var listeners(get, never):Array<TrackEntry->Void>;

	private function get_listeners():Array<TrackEntry->Void> {
		return _listeners;
	}

	public function new() {
		_listeners = new Array<TrackEntry->Void>();
	}

	/** Invoked when this entry has been set as the current entry. {@link #end(TrackEntry)} will occur when this entry will no
	 * longer be applied. */
	public function invoke(entry:TrackEntry) {
		for (listener in _listeners) {
			listener(entry);
		}
	}

	public function add(listener:TrackEntry->Void):Void {
		if (listener == null)
			throw new SpineException("listener cannot be null.");
		var indexOf:Int = _listeners.indexOf(listener);
		if (indexOf == -1)
			_listeners.push(listener);
	}

	public function remove(listener:TrackEntry->Void):Void {
		if (listener == null)
			throw new SpineException("listener cannot be null.");
		var indexOf:Int = _listeners.indexOf(listener);
		if (indexOf != -1)
			_listeners.splice(indexOf, 1);
	}
}

/** The interface to implement for receiving TrackEntry events. It is always safe to call AnimationState methods when receiving
 * events.
 * <p>
 * TrackEntry events are collected during {@link AnimationState#update(float)} and {@link AnimationState#apply(Skeleton)} and
 * fired only after those methods are finished.
 * <p>
 * See TrackEntry {@link TrackEntry#setListener(AnimationStateListener)} and AnimationState
 * {@link AnimationState#addListener(AnimationStateListener)}. */
class EventListeners {
	private var _listeners:Array<TrackEntry->Event->Void>;

	public var listeners(get, never):Array<TrackEntry->Event->Void>;

	private function get_listeners():Array<TrackEntry->Event->Void> {
		return _listeners;
	}

	public function new() {
		_listeners = new Array<TrackEntry->Event->Void>();
	}

	/** Invoked when this entry's animation triggers an event. This may occur during mixing (after
	 * {@link #interrupt(TrackEntry)}), see {@link TrackEntry#eventThreshold}.
	 * <p>
	 * Because this event is triggered at the end of {@link AnimationState#apply(Skeleton)}, any animations set in response to
	 * the event won't be applied until the next time the AnimationState is applied. */
	public function invoke(entry:TrackEntry, event:Event) {
		for (listener in _listeners) {
			listener(entry, event);
		}
	}

	public function add(listener:TrackEntry->Event->Void):Void {
		if (listener == null)
			throw new SpineException("listener cannot be null.");
		var indexOf:Int = _listeners.indexOf(listener);
		if (indexOf == -1)
			_listeners.push(listener);
	}

	public function remove(listener:TrackEntry->Event->Void):Void {
		if (listener == null)
			throw new SpineException("listener cannot be null.");
		var indexOf:Int = _listeners.indexOf(listener);
		if (indexOf != -1)
			_listeners.splice(indexOf, 1);
	}
}
