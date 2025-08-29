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

/// CurveTimeline1 wrapper
@objc(SpineCurveTimeline1)
@objcMembers
open class CurveTimeline1: CurveTimeline {
    @nonobjc
    public init(fromPointer ptr: spine_curve_timeline1) {
        super.init(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_curve_timeline_wrapper.self))
    }

    public func setFrame(_ frame: Int, _ time: Float, _ value: Float) {
        spine_curve_timeline1_set_frame(_ptr.assumingMemoryBound(to: spine_curve_timeline1_wrapper.self), frame, time, value)
    }

    public func getCurveValue(_ time: Float) -> Float {
        let result = spine_curve_timeline1_get_curve_value(_ptr.assumingMemoryBound(to: spine_curve_timeline1_wrapper.self), time)
        return result
    }

    public func getRelativeValue(_ time: Float, _ alpha: Float, _ blend: MixBlend, _ current: Float, _ setup: Float) -> Float {
        let result = spine_curve_timeline1_get_relative_value(_ptr.assumingMemoryBound(to: spine_curve_timeline1_wrapper.self), time, alpha, spine_mix_blend(rawValue: UInt32(blend.rawValue)), current, setup)
        return result
    }

    public func getScaleValue(_ time: Float, _ alpha: Float, _ blend: MixBlend, _ direction: MixDirection, _ current: Float, _ setup: Float) -> Float {
        let result = spine_curve_timeline1_get_scale_value(_ptr.assumingMemoryBound(to: spine_curve_timeline1_wrapper.self), time, alpha, spine_mix_blend(rawValue: UInt32(blend.rawValue)), spine_mix_direction(rawValue: UInt32(direction.rawValue)), current, setup)
        return result
    }

    public func getAbsoluteValue(_ time: Float, _ alpha: Float, _ blend: MixBlend, _ current: Float, _ setup: Float) -> Float {
        let result = spine_curve_timeline1_get_absolute_value_1(_ptr.assumingMemoryBound(to: spine_curve_timeline1_wrapper.self), time, alpha, spine_mix_blend(rawValue: UInt32(blend.rawValue)), current, setup)
        return result
    }

    public func getAbsoluteValue2(_ time: Float, _ alpha: Float, _ blend: MixBlend, _ current: Float, _ setup: Float, _ value: Float) -> Float {
        let result = spine_curve_timeline1_get_absolute_value_2(_ptr.assumingMemoryBound(to: spine_curve_timeline1_wrapper.self), time, alpha, spine_mix_blend(rawValue: UInt32(blend.rawValue)), current, setup, value)
        return result
    }

}