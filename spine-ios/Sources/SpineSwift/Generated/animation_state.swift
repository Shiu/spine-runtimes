//
// Spine Runtimes License Agreement
// Last updated April 5, 2025. Replaces all prior versions.
//
// Copyright (c) 2013-2025, Esoteric Software LLC
//
// Integration of the Spine Runtimes into software or otherwise creating
// derivative works of the Spine Runtimes is permitted under the terms and
// conditions of Section 2 of the Spine Editor License Agreement:
// http://esotericsoftware.com/spine-editor-license
//
// Otherwise, it is permitted to integrate the Spine Runtimes into software
// or otherwise create derivative works of the Spine Runtimes (collectively,
// "Products"), provided that each user of the Products must obtain their own
// Spine Editor license and redistribution of the Products in any form must
// include this license and copyright notice.
//
// THE SPINE RUNTIMES ARE PROVIDED BY ESOTERIC SOFTWARE LLC "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL ESOTERIC SOFTWARE LLC BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES,
// BUSINESS INTERRUPTION, OR LOSS OF USE, DATA, OR PROFITS) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THE SPINE RUNTIMES, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

// AUTO GENERATED FILE, DO NOT EDIT.

import Foundation
import SpineC

/// AnimationState wrapper
public class AnimationState {
    public let _ptr: UnsafeMutableRawPointer

    public init(fromPointer ptr: spine_animation_state) {
        self._ptr = UnsafeMutableRawPointer(ptr)
    }

    public convenience init(_ data: AnimationStateData) {
        let ptr = spine_animation_state_create(data._ptr.assumingMemoryBound(to: spine_animation_state_data_wrapper.self))
        self.init(fromPointer: ptr!)
    }

    public var emptyAnimations: Float {
        get { fatalError("Setter-only property") }
        set(newValue) {
            spine_animation_state_set_empty_animations(_ptr.assumingMemoryBound(to: spine_animation_state_wrapper.self), newValue)
        }
    }

    public var data: AnimationStateData {
        let result = spine_animation_state_get_data(_ptr.assumingMemoryBound(to: spine_animation_state_wrapper.self))
        return AnimationStateData(fromPointer: result!)
    }

    public var tracks: ArrayTrackEntry {
        let result = spine_animation_state_get_tracks(_ptr.assumingMemoryBound(to: spine_animation_state_wrapper.self))
        return ArrayTrackEntry(fromPointer: result!)
    }

    public var timeScale: Float {
        get {
            let result = spine_animation_state_get_time_scale(_ptr.assumingMemoryBound(to: spine_animation_state_wrapper.self))
        return result
        }
        set {
            spine_animation_state_set_time_scale(_ptr.assumingMemoryBound(to: spine_animation_state_wrapper.self), newValue)
        }
    }

    public var manualTrackEntryDisposal: Bool {
        get {
            let result = spine_animation_state_get_manual_track_entry_disposal(_ptr.assumingMemoryBound(to: spine_animation_state_wrapper.self))
        return result
        }
        set {
            spine_animation_state_set_manual_track_entry_disposal(_ptr.assumingMemoryBound(to: spine_animation_state_wrapper.self), newValue)
        }
    }

    public var rendererObject: UnsafeMutableRawPointer? {
        let result = spine_animation_state_get_renderer_object(_ptr.assumingMemoryBound(to: spine_animation_state_wrapper.self))
        return result
    }

    public func update(_ delta: Float) {
        spine_animation_state_update(_ptr.assumingMemoryBound(to: spine_animation_state_wrapper.self), delta)
    }

    public func apply(_ skeleton: Skeleton) -> Bool {
        let result = spine_animation_state_apply(_ptr.assumingMemoryBound(to: spine_animation_state_wrapper.self), skeleton._ptr.assumingMemoryBound(to: spine_skeleton_wrapper.self))
        return result
    }

    public func clearTracks() {
        spine_animation_state_clear_tracks(_ptr.assumingMemoryBound(to: spine_animation_state_wrapper.self))
    }

    public func clearTrack(_ trackIndex: Int) {
        spine_animation_state_clear_track(_ptr.assumingMemoryBound(to: spine_animation_state_wrapper.self), trackIndex)
    }

    public func setEmptyAnimation(_ trackIndex: Int, _ mixDuration: Float) -> TrackEntry {
        let result = spine_animation_state_set_empty_animation(_ptr.assumingMemoryBound(to: spine_animation_state_wrapper.self), trackIndex, mixDuration)
        return TrackEntry(fromPointer: result!)
    }

    public func addEmptyAnimation(_ trackIndex: Int, _ mixDuration: Float, _ delay: Float) -> TrackEntry {
        let result = spine_animation_state_add_empty_animation(_ptr.assumingMemoryBound(to: spine_animation_state_wrapper.self), trackIndex, mixDuration, delay)
        return TrackEntry(fromPointer: result!)
    }

    public func getCurrent(_ trackIndex: Int) -> TrackEntry? {
        let result = spine_animation_state_get_current(_ptr.assumingMemoryBound(to: spine_animation_state_wrapper.self), trackIndex)
        return result.map { TrackEntry(fromPointer: $0) }
    }

    public func disableQueue() {
        spine_animation_state_disable_queue(_ptr.assumingMemoryBound(to: spine_animation_state_wrapper.self))
    }

    public func enableQueue() {
        spine_animation_state_enable_queue(_ptr.assumingMemoryBound(to: spine_animation_state_wrapper.self))
    }

    public func disposeTrackEntry(_ entry: TrackEntry?) {
        spine_animation_state_dispose_track_entry(_ptr.assumingMemoryBound(to: spine_animation_state_wrapper.self), entry?._ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
    }

    public func setAnimation(_ trackIndex: Int, _ animationName: String, _ loop: Bool) -> TrackEntry {
        let result = spine_animation_state_set_animation_1(_ptr.assumingMemoryBound(to: spine_animation_state_wrapper.self), trackIndex, animationName, loop)
        return TrackEntry(fromPointer: result!)
    }

    public func setAnimation2(_ trackIndex: Int, _ animation: Animation, _ loop: Bool) -> TrackEntry {
        let result = spine_animation_state_set_animation_2(_ptr.assumingMemoryBound(to: spine_animation_state_wrapper.self), trackIndex, animation._ptr.assumingMemoryBound(to: spine_animation_wrapper.self), loop)
        return TrackEntry(fromPointer: result!)
    }

    public func addAnimation(_ trackIndex: Int, _ animationName: String, _ loop: Bool, _ delay: Float) -> TrackEntry {
        let result = spine_animation_state_add_animation_1(_ptr.assumingMemoryBound(to: spine_animation_state_wrapper.self), trackIndex, animationName, loop, delay)
        return TrackEntry(fromPointer: result!)
    }

    public func addAnimation2(_ trackIndex: Int, _ animation: Animation, _ loop: Bool, _ delay: Float) -> TrackEntry {
        let result = spine_animation_state_add_animation_2(_ptr.assumingMemoryBound(to: spine_animation_state_wrapper.self), trackIndex, animation._ptr.assumingMemoryBound(to: spine_animation_wrapper.self), loop, delay)
        return TrackEntry(fromPointer: result!)
    }

    public func dispose() {
        spine_animation_state_dispose(_ptr.assumingMemoryBound(to: spine_animation_state_wrapper.self))
    }
}