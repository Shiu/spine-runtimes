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

import Foundation
import SpineC

@objc(SpineAnimationState)
@objcMembers
public final class AnimationState: NSObject {
    internal let wrappee: spine_animation_state

    internal init(_ wrappee: spine_animation_state) {
        self.wrappee = wrappee
        super.init()
    }

    public override func isEqual(_ object: Any?) -> Bool {
        guard let other = object as? AnimationState else { return false }
        return self.wrappee == other.wrappee
    }

    public override var hash: Int {
        var hasher = Hasher()
        hasher.combine(self.wrappee)
        return hasher.finalize()
    }

    public convenience init(data: AnimationStateData) {
        let ptr = spine_animation_state_create(data.wrappee)
        self.init(ptr)
    }

    public func update(delta: Float) {
        spine_animation_state_update(wrappee, delta)
    }

    public func apply(skeleton: Skeleton) -> Bool {
        return spine_animation_state_apply(wrappee, skeleton.wrappee) != 0
    }

    public func clearTracks() {
        spine_animation_state_clear_tracks(wrappee)
    }

    public func clearTrack(trackIndex: size_t) {
        spine_animation_state_clear_track(wrappee, trackIndex)
    }

    public func setAnimation(trackIndex: size_t, animationName: String?, loop: Bool) -> TrackEntry {
        let result = spine_animation_state_set_animation_1(wrappee, trackIndex, animationName?.cString(using: .utf8), loop ? 1 : 0)
        return TrackEntry(result)
    }

    public func setAnimation(trackIndex: size_t, animation: Animation, loop: Bool) -> TrackEntry {
        let result = spine_animation_state_set_animation_2(wrappee, trackIndex, animation.wrappee, loop ? 1 : 0)
        return TrackEntry(result)
    }

    public func addAnimation(trackIndex: size_t, animationName: String?, loop: Bool, delay: Float) -> TrackEntry {
        let result = spine_animation_state_add_animation_1(wrappee, trackIndex, animationName?.cString(using: .utf8), loop ? 1 : 0, delay)
        return TrackEntry(result)
    }

    public func addAnimation(trackIndex: size_t, animation: Animation, loop: Bool, delay: Float) -> TrackEntry {
        let result = spine_animation_state_add_animation_2(wrappee, trackIndex, animation.wrappee, loop ? 1 : 0, delay)
        return TrackEntry(result)
    }

    public func setEmptyAnimation(trackIndex: size_t, mixDuration: Float) -> TrackEntry {
        let result = spine_animation_state_set_empty_animation(wrappee, trackIndex, mixDuration)
        return TrackEntry(result)
    }

    public func addEmptyAnimation(trackIndex: size_t, mixDuration: Float, delay: Float) -> TrackEntry {
        let result = spine_animation_state_add_empty_animation(wrappee, trackIndex, mixDuration, delay)
        return TrackEntry(result)
    }

    public func setEmptyAnimations(mixDuration: Float) {
        spine_animation_state_set_empty_animations(wrappee, mixDuration)
    }

    public func getCurrent(trackIndex: size_t) -> TrackEntry {
        let result = spine_animation_state_get_current(wrappee, trackIndex)
        return TrackEntry(result)
    }

    public func getData() -> AnimationStateData {
        let result = spine_animation_state_get_data(wrappee)
        return AnimationStateData(result)
    }

    public func getTracks() -> ArrayTrackEntry {
        return spine_animation_state_get_tracks(wrappee)
    }

    public func getTimeScale() -> Float {
        return spine_animation_state_get_time_scale(wrappee)
    }

    public func setTimeScale(inValue: Float) {
        spine_animation_state_set_time_scale(wrappee, inValue)
    }

    public func disableQueue() {
        spine_animation_state_disable_queue(wrappee)
    }

    public func enableQueue() {
        spine_animation_state_enable_queue(wrappee)
    }

    public func setManualTrackEntryDisposal(inValue: Bool) {
        spine_animation_state_set_manual_track_entry_disposal(wrappee, inValue ? 1 : 0)
    }

    public func getManualTrackEntryDisposal() -> Bool {
        return spine_animation_state_get_manual_track_entry_disposal(wrappee) != 0
    }

    public func disposeTrackEntry(entry: TrackEntry) {
        spine_animation_state_dispose_track_entry(wrappee, entry.wrappee)
    }

    public func getRendererObject() -> OpaquePointer? {
        return spine_animation_state_get_renderer_object(wrappee)
    }

    deinit {
        spine_animation_state_dispose(wrappee)
    }
}