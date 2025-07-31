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

@objc(SpineTrackEntry)
@objcMembers
public final class TrackEntry: NSObject {
    internal let wrappee: spine_track_entry

    internal init(_ wrappee: spine_track_entry) {
        self.wrappee = wrappee
        super.init()
    }

    public override func isEqual(_ object: Any?) -> Bool {
        guard let other = object as? TrackEntry else { return false }
        return self.wrappee == other.wrappee
    }

    public override var hash: Int {
        var hasher = Hasher()
        hasher.combine(self.wrappee)
        return hasher.finalize()
    }

    public convenience init() {
        let ptr = spine_track_entry_create()
        self.init(ptr)
    }

    public func getTrackIndex() -> Int32 {
        return spine_track_entry_get_track_index(wrappee)
    }

    public func getAnimation() -> Animation {
        let result = spine_track_entry_get_animation(wrappee)
        return Animation(result)
    }

    public func setAnimation(animation: Animation) {
        spine_track_entry_set_animation(wrappee, animation.wrappee)
    }

    public func getPrevious() -> TrackEntry {
        let result = spine_track_entry_get_previous(wrappee)
        return TrackEntry(result)
    }

    public func getLoop() -> Bool {
        return spine_track_entry_get_loop(wrappee) != 0
    }

    public func setLoop(inValue: Bool) {
        spine_track_entry_set_loop(wrappee, inValue ? 1 : 0)
    }

    public func getHoldPrevious() -> Bool {
        return spine_track_entry_get_hold_previous(wrappee) != 0
    }

    public func setHoldPrevious(inValue: Bool) {
        spine_track_entry_set_hold_previous(wrappee, inValue ? 1 : 0)
    }

    public func getReverse() -> Bool {
        return spine_track_entry_get_reverse(wrappee) != 0
    }

    public func setReverse(inValue: Bool) {
        spine_track_entry_set_reverse(wrappee, inValue ? 1 : 0)
    }

    public func getShortestRotation() -> Bool {
        return spine_track_entry_get_shortest_rotation(wrappee) != 0
    }

    public func setShortestRotation(inValue: Bool) {
        spine_track_entry_set_shortest_rotation(wrappee, inValue ? 1 : 0)
    }

    public func getDelay() -> Float {
        return spine_track_entry_get_delay(wrappee)
    }

    public func setDelay(inValue: Float) {
        spine_track_entry_set_delay(wrappee, inValue)
    }

    public func getTrackTime() -> Float {
        return spine_track_entry_get_track_time(wrappee)
    }

    public func setTrackTime(inValue: Float) {
        spine_track_entry_set_track_time(wrappee, inValue)
    }

    public func getTrackEnd() -> Float {
        return spine_track_entry_get_track_end(wrappee)
    }

    public func setTrackEnd(inValue: Float) {
        spine_track_entry_set_track_end(wrappee, inValue)
    }

    public func getAnimationStart() -> Float {
        return spine_track_entry_get_animation_start(wrappee)
    }

    public func setAnimationStart(inValue: Float) {
        spine_track_entry_set_animation_start(wrappee, inValue)
    }

    public func getAnimationEnd() -> Float {
        return spine_track_entry_get_animation_end(wrappee)
    }

    public func setAnimationEnd(inValue: Float) {
        spine_track_entry_set_animation_end(wrappee, inValue)
    }

    public func getAnimationLast() -> Float {
        return spine_track_entry_get_animation_last(wrappee)
    }

    public func setAnimationLast(inValue: Float) {
        spine_track_entry_set_animation_last(wrappee, inValue)
    }

    public func getAnimationTime() -> Float {
        return spine_track_entry_get_animation_time(wrappee)
    }

    public func getTimeScale() -> Float {
        return spine_track_entry_get_time_scale(wrappee)
    }

    public func setTimeScale(inValue: Float) {
        spine_track_entry_set_time_scale(wrappee, inValue)
    }

    public func getAlpha() -> Float {
        return spine_track_entry_get_alpha(wrappee)
    }

    public func setAlpha(inValue: Float) {
        spine_track_entry_set_alpha(wrappee, inValue)
    }

    public func getEventThreshold() -> Float {
        return spine_track_entry_get_event_threshold(wrappee)
    }

    public func setEventThreshold(inValue: Float) {
        spine_track_entry_set_event_threshold(wrappee, inValue)
    }

    public func getMixAttachmentThreshold() -> Float {
        return spine_track_entry_get_mix_attachment_threshold(wrappee)
    }

    public func setMixAttachmentThreshold(inValue: Float) {
        spine_track_entry_set_mix_attachment_threshold(wrappee, inValue)
    }

    public func getAlphaAttachmentThreshold() -> Float {
        return spine_track_entry_get_alpha_attachment_threshold(wrappee)
    }

    public func setAlphaAttachmentThreshold(inValue: Float) {
        spine_track_entry_set_alpha_attachment_threshold(wrappee, inValue)
    }

    public func getMixDrawOrderThreshold() -> Float {
        return spine_track_entry_get_mix_draw_order_threshold(wrappee)
    }

    public func setMixDrawOrderThreshold(inValue: Float) {
        spine_track_entry_set_mix_draw_order_threshold(wrappee, inValue)
    }

    public func getNext() -> TrackEntry {
        let result = spine_track_entry_get_next(wrappee)
        return TrackEntry(result)
    }

    public func isComplete() -> Bool {
        return spine_track_entry_is_complete(wrappee) != 0
    }

    public func getMixTime() -> Float {
        return spine_track_entry_get_mix_time(wrappee)
    }

    public func setMixTime(inValue: Float) {
        spine_track_entry_set_mix_time(wrappee, inValue)
    }

    public func getMixDuration() -> Float {
        return spine_track_entry_get_mix_duration(wrappee)
    }

    public func setMixDuration(inValue: Float) {
        spine_track_entry_set_mix_duration_1(wrappee, inValue)
    }

    public func setMixDuration(mixDuration: Float, delay: Float) {
        spine_track_entry_set_mix_duration_2(wrappee, mixDuration, delay)
    }

    public func getMixBlend() -> MixBlend {
        return spine_track_entry_get_mix_blend(wrappee)
    }

    public func setMixBlend(blend: MixBlend) {
        spine_track_entry_set_mix_blend(wrappee, blend)
    }

    public func getMixingFrom() -> TrackEntry {
        let result = spine_track_entry_get_mixing_from(wrappee)
        return TrackEntry(result)
    }

    public func getMixingTo() -> TrackEntry {
        let result = spine_track_entry_get_mixing_to(wrappee)
        return TrackEntry(result)
    }

    public func resetRotationDirections() {
        spine_track_entry_reset_rotation_directions(wrappee)
    }

    public func getTrackComplete() -> Float {
        return spine_track_entry_get_track_complete(wrappee)
    }

    public func isEmptyAnimation() -> Bool {
        return spine_track_entry_is_empty_animation(wrappee) != 0
    }

    public func wasApplied() -> Bool {
        return spine_track_entry_was_applied(wrappee) != 0
    }

    public func isNextReady() -> Bool {
        return spine_track_entry_is_next_ready(wrappee) != 0
    }

    public func getAnimationState() -> AnimationState {
        let result = spine_track_entry_get_animation_state(wrappee)
        return AnimationState(result)
    }

    public func setAnimationState(state: AnimationState) {
        spine_track_entry_set_animation_state(wrappee, state.wrappee)
    }

    public func getRendererObject() -> OpaquePointer? {
        return spine_track_entry_get_renderer_object(wrappee)
    }

    deinit {
        spine_track_entry_dispose(wrappee)
    }
}