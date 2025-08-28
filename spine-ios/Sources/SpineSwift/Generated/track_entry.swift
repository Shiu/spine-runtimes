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

/// TrackEntry wrapper
@objc(SpineTrackEntry)
@objcMembers
public class TrackEntry: NSObject {
    public let _ptr: UnsafeMutableRawPointer

    public init(fromPointer ptr: spine_track_entry) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        super.init()
    }

    public override convenience init() {
        let ptr = spine_track_entry_create()
        self.init(fromPointer: ptr!)
    }

    public var trackIndex: Int32 {
        let result = spine_track_entry_get_track_index(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
        return result
    }

    public var animation: Animation {
        get {
            let result = spine_track_entry_get_animation(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
            return Animation(fromPointer: result!)
        }
        set {
            spine_track_entry_set_animation(
                _ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self), newValue._ptr.assumingMemoryBound(to: spine_animation_wrapper.self))
        }
    }

    public var previous: TrackEntry? {
        let result = spine_track_entry_get_previous(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
        return result.map { TrackEntry(fromPointer: $0) }
    }

    public var loop: Bool {
        get {
            let result = spine_track_entry_get_loop(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
            return result
        }
        set {
            spine_track_entry_set_loop(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self), newValue)
        }
    }

    public var holdPrevious: Bool {
        get {
            let result = spine_track_entry_get_hold_previous(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
            return result
        }
        set {
            spine_track_entry_set_hold_previous(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self), newValue)
        }
    }

    public var reverse: Bool {
        get {
            let result = spine_track_entry_get_reverse(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
            return result
        }
        set {
            spine_track_entry_set_reverse(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self), newValue)
        }
    }

    public var shortestRotation: Bool {
        get {
            let result = spine_track_entry_get_shortest_rotation(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
            return result
        }
        set {
            spine_track_entry_set_shortest_rotation(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self), newValue)
        }
    }

    public var delay: Float {
        get {
            let result = spine_track_entry_get_delay(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
            return result
        }
        set {
            spine_track_entry_set_delay(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self), newValue)
        }
    }

    public var trackTime: Float {
        get {
            let result = spine_track_entry_get_track_time(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
            return result
        }
        set {
            spine_track_entry_set_track_time(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self), newValue)
        }
    }

    public var trackEnd: Float {
        get {
            let result = spine_track_entry_get_track_end(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
            return result
        }
        set {
            spine_track_entry_set_track_end(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self), newValue)
        }
    }

    public var animationStart: Float {
        get {
            let result = spine_track_entry_get_animation_start(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
            return result
        }
        set {
            spine_track_entry_set_animation_start(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self), newValue)
        }
    }

    public var animationEnd: Float {
        get {
            let result = spine_track_entry_get_animation_end(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
            return result
        }
        set {
            spine_track_entry_set_animation_end(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self), newValue)
        }
    }

    public var animationLast: Float {
        get {
            let result = spine_track_entry_get_animation_last(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
            return result
        }
        set {
            spine_track_entry_set_animation_last(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self), newValue)
        }
    }

    public var animationTime: Float {
        let result = spine_track_entry_get_animation_time(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
        return result
    }

    public var timeScale: Float {
        get {
            let result = spine_track_entry_get_time_scale(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
            return result
        }
        set {
            spine_track_entry_set_time_scale(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self), newValue)
        }
    }

    public var alpha: Float {
        get {
            let result = spine_track_entry_get_alpha(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
            return result
        }
        set {
            spine_track_entry_set_alpha(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self), newValue)
        }
    }

    public var eventThreshold: Float {
        get {
            let result = spine_track_entry_get_event_threshold(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
            return result
        }
        set {
            spine_track_entry_set_event_threshold(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self), newValue)
        }
    }

    public var mixAttachmentThreshold: Float {
        get {
            let result = spine_track_entry_get_mix_attachment_threshold(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
            return result
        }
        set {
            spine_track_entry_set_mix_attachment_threshold(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self), newValue)
        }
    }

    public var alphaAttachmentThreshold: Float {
        get {
            let result = spine_track_entry_get_alpha_attachment_threshold(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
            return result
        }
        set {
            spine_track_entry_set_alpha_attachment_threshold(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self), newValue)
        }
    }

    public var mixDrawOrderThreshold: Float {
        get {
            let result = spine_track_entry_get_mix_draw_order_threshold(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
            return result
        }
        set {
            spine_track_entry_set_mix_draw_order_threshold(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self), newValue)
        }
    }

    public var next: TrackEntry? {
        let result = spine_track_entry_get_next(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
        return result.map { TrackEntry(fromPointer: $0) }
    }

    public var isComplete: Bool {
        let result = spine_track_entry_is_complete(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
        return result
    }

    public var mixTime: Float {
        get {
            let result = spine_track_entry_get_mix_time(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
            return result
        }
        set {
            spine_track_entry_set_mix_time(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self), newValue)
        }
    }

    public var mixDuration: Float {
        let result = spine_track_entry_get_mix_duration(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
        return result
    }

    public var mixBlend: MixBlend {
        get {
            let result = spine_track_entry_get_mix_blend(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
            return MixBlend(rawValue: Int32(result.rawValue))!
        }
        set {
            spine_track_entry_set_mix_blend(
                _ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self), spine_mix_blend(rawValue: UInt32(newValue.rawValue)))
        }
    }

    public var mixingFrom: TrackEntry? {
        let result = spine_track_entry_get_mixing_from(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
        return result.map { TrackEntry(fromPointer: $0) }
    }

    public var mixingTo: TrackEntry? {
        let result = spine_track_entry_get_mixing_to(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
        return result.map { TrackEntry(fromPointer: $0) }
    }

    public var trackComplete: Float {
        let result = spine_track_entry_get_track_complete(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
        return result
    }

    public var isEmptyAnimation: Bool {
        let result = spine_track_entry_is_empty_animation(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
        return result
    }

    public var wasApplied: Bool {
        let result = spine_track_entry_was_applied(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
        return result
    }

    public var isNextReady: Bool {
        let result = spine_track_entry_is_next_ready(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
        return result
    }

    public var animationState: AnimationState? {
        get {
            let result = spine_track_entry_get_animation_state(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
            return result.map { AnimationState(fromPointer: $0) }
        }
        set {
            spine_track_entry_set_animation_state(
                _ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self),
                newValue?._ptr.assumingMemoryBound(to: spine_animation_state_wrapper.self))
        }
    }

    public var rendererObject: UnsafeMutableRawPointer? {
        let result = spine_track_entry_get_renderer_object(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
        return result
    }

    public var setMixDuration: Float {
        get { fatalError("Setter-only property") }
        set(newValue) {
            spine_track_entry_set_mix_duration_1(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self), newValue)
        }
    }

    public func resetRotationDirections() {
        spine_track_entry_reset_rotation_directions(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
    }

    public func setMixDuration2(_ mixDuration: Float, _ delay: Float) {
        spine_track_entry_set_mix_duration_2(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self), mixDuration, delay)
    }

    public func dispose() {
        spine_track_entry_dispose(_ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
    }
}
