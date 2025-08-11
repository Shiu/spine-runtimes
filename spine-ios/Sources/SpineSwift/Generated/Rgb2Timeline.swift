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

@objc(SpineRgb2Timeline)
@objcMembers
public final class Rgb2Timeline: SlotCurveTimeline {
    internal let wrappee: spine_rgb2_timeline

    internal init(_ wrappee: spine_rgb2_timeline) {
        self.wrappee = wrappee
        super.init(wrappee)
    }

    public convenience init(frameCount: size_t, bezierCount: size_t, slotIndex: Int32) {
        let ptr = spine_rgb2_timeline_create(frameCount, bezierCount, slotIndex)
        self.init(ptr)
    }

    public func getRtti() -> Rtti {
        let result = spine_rgb2_timeline_get_rtti(wrappee)
        return Rtti(result)
    }

    public func setFrame(frame: Int32, time: Float, r: Float, g: Float, b: Float, r2: Float, g2: Float, b2: Float) {
        spine_rgb2_timeline_set_frame(wrappee, frame, time, r, g, b, r2, g2, b2)
    }

    public func apply(skeleton: Skeleton, lastTime: Float, time: Float, events: ArrayEvent, alpha: Float, blend: MixBlend, direction: MixDirection, appliedPose: Bool) {
        spine_rgb2_timeline_apply(wrappee, skeleton.wrappee, lastTime, time, events, alpha, blend, direction, appliedPose ? 1 : 0)
    }

    public func getSlotIndex() -> Int32 {
        return spine_rgb2_timeline_get_slot_index(wrappee)
    }

    public func setSlotIndex(inValue: Int32) {
        spine_rgb2_timeline_set_slot_index(wrappee, inValue)
    }

    public func setLinear(frame: size_t) {
        spine_rgb2_timeline_set_linear(wrappee, frame)
    }

    public func setStepped(frame: size_t) {
        spine_rgb2_timeline_set_stepped(wrappee, frame)
    }

    public func setBezier(bezier: size_t, frame: size_t, value: Float, time1: Float, value1: Float, cx1: Float, cy1: Float, cx2: Float, cy2: Float, time2: Float, value2: Float) {
        spine_rgb2_timeline_set_bezier(wrappee, bezier, frame, value, time1, value1, cx1, cy1, cx2, cy2, time2, value2)
    }

    public func getBezierValue(time: Float, frame: size_t, valueOffset: size_t, i: size_t) -> Float {
        return spine_rgb2_timeline_get_bezier_value(wrappee, time, frame, valueOffset, i)
    }

    public func getCurves() -> ArrayFloat {
        return spine_rgb2_timeline_get_curves(wrappee)
    }

    public func getFrameEntries() -> size_t {
        return spine_rgb2_timeline_get_frame_entries(wrappee)
    }

    public func getFrameCount() -> size_t {
        return spine_rgb2_timeline_get_frame_count(wrappee)
    }

    public func getFrames() -> ArrayFloat {
        return spine_rgb2_timeline_get_frames(wrappee)
    }

    public func getDuration() -> Float {
        return spine_rgb2_timeline_get_duration(wrappee)
    }

    public func getPropertyIds() -> ArrayPropertyId {
        return spine_rgb2_timeline_get_property_ids(wrappee)
    }

    public func rtti() -> Rtti {
        let result = spine_rgb2_timeline_rtti(wrappee)
        return Rtti(result)
    }

    deinit {
        spine_rgb2_timeline_dispose(wrappee)
    }
}