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

@objc(SpineCurveTimeline)
@objcMembers
public final class CurveTimeline: Timeline {
    internal let wrappee: spine_curve_timeline

    internal init(_ wrappee: spine_curve_timeline) {
        self.wrappee = wrappee
        super.init(wrappee)
    }

    public func getRtti() -> Rtti {
        let result = spine_curve_timeline_get_rtti(wrappee)
        return Rtti(result)
    }

    public func setLinear(frame: size_t) {
        spine_curve_timeline_set_linear(wrappee, frame)
    }

    public func setStepped(frame: size_t) {
        spine_curve_timeline_set_stepped(wrappee, frame)
    }

    public func setBezier(bezier: size_t, frame: size_t, value: Float, time1: Float, value1: Float, cx1: Float, cy1: Float, cx2: Float, cy2: Float, time2: Float, value2: Float) {
        spine_curve_timeline_set_bezier(wrappee, bezier, frame, value, time1, value1, cx1, cy1, cx2, cy2, time2, value2)
    }

    public func getBezierValue(time: Float, frame: size_t, valueOffset: size_t, i: size_t) -> Float {
        return spine_curve_timeline_get_bezier_value(wrappee, time, frame, valueOffset, i)
    }

    public func getCurves() -> ArrayFloat {
        return spine_curve_timeline_get_curves(wrappee)
    }

    public func apply(skeleton: Skeleton, lastTime: Float, time: Float, events: ArrayEvent, alpha: Float, blend: MixBlend, direction: MixDirection, appliedPose: Bool) {
        spine_curve_timeline_apply(wrappee, skeleton.wrappee, lastTime, time, events, alpha, blend, direction, appliedPose ? 1 : 0)
    }

    public func getFrameEntries() -> size_t {
        return spine_curve_timeline_get_frame_entries(wrappee)
    }

    public func getFrameCount() -> size_t {
        return spine_curve_timeline_get_frame_count(wrappee)
    }

    public func getFrames() -> ArrayFloat {
        return spine_curve_timeline_get_frames(wrappee)
    }

    public func getDuration() -> Float {
        return spine_curve_timeline_get_duration(wrappee)
    }

    public func getPropertyIds() -> ArrayPropertyId {
        return spine_curve_timeline_get_property_ids(wrappee)
    }

    public func rtti() -> Rtti {
        let result = spine_curve_timeline_rtti(wrappee)
        return Rtti(result)
    }

    deinit {
        spine_curve_timeline_dispose(wrappee)
    }
}