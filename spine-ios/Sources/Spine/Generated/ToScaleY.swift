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

@objc(SpineToScaleY)
@objcMembers
public final class ToScaleY: ToProperty {
    internal let wrappee: spine_to_scale_y

    internal init(_ wrappee: spine_to_scale_y) {
        self.wrappee = wrappee
        super.init(wrappee)
    }

    public convenience init() {
        let ptr = spine_to_scale_y_create()
        self.init(ptr)
    }

    public func getRtti() -> Rtti {
        let result = spine_to_scale_y_get_rtti(wrappee)
        return Rtti(result)
    }

    public func mix(pose: TransformConstraintPose) -> Float {
        return spine_to_scale_y_mix(wrappee, pose.wrappee)
    }

    public func apply(skeleton: Skeleton, pose: TransformConstraintPose, bone: BonePose, value: Float, local: Bool, additive: Bool) {
        spine_to_scale_y_apply(wrappee, skeleton.wrappee, pose.wrappee, bone.wrappee, value, local ? 1 : 0, additive ? 1 : 0)
    }

    public func rtti() -> Rtti {
        let result = spine_to_scale_y_rtti(wrappee)
        return Rtti(result)
    }

    deinit {
        spine_to_scale_y_dispose(wrappee)
    }
}