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

@objc(SpineSequenceTimeline)
@objcMembers
public final class SequenceTimeline: Timeline {
    internal let wrappee: spine_sequence_timeline

    internal init(_ wrappee: spine_sequence_timeline) {
        self.wrappee = wrappee
        super.init(wrappee)
    }

    public convenience init(frameCount: size_t, slotIndex: Int32, attachment: Attachment) {
        let ptr = spine_sequence_timeline_create(frameCount, slotIndex, attachment.wrappee)
        self.init(ptr)
    }

    public func getRtti() -> Rtti {
        let result = spine_sequence_timeline_get_rtti(wrappee)
        return Rtti(result)
    }

    public func apply(skeleton: Skeleton, lastTime: Float, time: Float, events: ArrayEvent, alpha: Float, blend: MixBlend, direction: MixDirection, appliedPose: Bool) {
        spine_sequence_timeline_apply(wrappee, skeleton.wrappee, lastTime, time, events, alpha, blend, direction, appliedPose ? 1 : 0)
    }

    public func setFrame(frame: Int32, time: Float, mode: SequenceMode, index: Int32, delay: Float) {
        spine_sequence_timeline_set_frame(wrappee, frame, time, mode, index, delay)
    }

    public func getAttachment() -> Attachment {
        let result = spine_sequence_timeline_get_attachment(wrappee)
        return Attachment(result)
    }

    public func getSlotIndex() -> Int32 {
        return spine_sequence_timeline_get_slot_index(wrappee)
    }

    public func setSlotIndex(inValue: Int32) {
        spine_sequence_timeline_set_slot_index(wrappee, inValue)
    }

    public func getFrameEntries() -> size_t {
        return spine_sequence_timeline_get_frame_entries(wrappee)
    }

    public func getFrameCount() -> size_t {
        return spine_sequence_timeline_get_frame_count(wrappee)
    }

    public func getFrames() -> ArrayFloat {
        return spine_sequence_timeline_get_frames(wrappee)
    }

    public func getDuration() -> Float {
        return spine_sequence_timeline_get_duration(wrappee)
    }

    public func getPropertyIds() -> ArrayPropertyId {
        return spine_sequence_timeline_get_property_ids(wrappee)
    }

    public func rtti() -> Rtti {
        let result = spine_sequence_timeline_rtti(wrappee)
        return Rtti(result)
    }

    deinit {
        spine_sequence_timeline_dispose(wrappee)
    }
}