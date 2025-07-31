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

@objc(SpineTransformConstraintPose)
@objcMembers
public final class TransformConstraintPose: NSObject {
    internal let wrappee: spine_transform_constraint_pose

    internal init(_ wrappee: spine_transform_constraint_pose) {
        self.wrappee = wrappee
        super.init()
    }

    public override func isEqual(_ object: Any?) -> Bool {
        guard let other = object as? TransformConstraintPose else { return false }
        return self.wrappee == other.wrappee
    }

    public override var hash: Int {
        var hasher = Hasher()
        hasher.combine(self.wrappee)
        return hasher.finalize()
    }

    public convenience init() {
        let ptr = spine_transform_constraint_pose_create()
        self.init(ptr)
    }

    public func set(pose: TransformConstraintPose) {
        spine_transform_constraint_pose_set(wrappee, pose.wrappee)
    }

    public func getMixRotate() -> Float {
        return spine_transform_constraint_pose_get_mix_rotate(wrappee)
    }

    public func setMixRotate(mixRotate: Float) {
        spine_transform_constraint_pose_set_mix_rotate(wrappee, mixRotate)
    }

    public func getMixX() -> Float {
        return spine_transform_constraint_pose_get_mix_x(wrappee)
    }

    public func setMixX(mixX: Float) {
        spine_transform_constraint_pose_set_mix_x(wrappee, mixX)
    }

    public func getMixY() -> Float {
        return spine_transform_constraint_pose_get_mix_y(wrappee)
    }

    public func setMixY(mixY: Float) {
        spine_transform_constraint_pose_set_mix_y(wrappee, mixY)
    }

    public func getMixScaleX() -> Float {
        return spine_transform_constraint_pose_get_mix_scale_x(wrappee)
    }

    public func setMixScaleX(mixScaleX: Float) {
        spine_transform_constraint_pose_set_mix_scale_x(wrappee, mixScaleX)
    }

    public func getMixScaleY() -> Float {
        return spine_transform_constraint_pose_get_mix_scale_y(wrappee)
    }

    public func setMixScaleY(mixScaleY: Float) {
        spine_transform_constraint_pose_set_mix_scale_y(wrappee, mixScaleY)
    }

    public func getMixShearY() -> Float {
        return spine_transform_constraint_pose_get_mix_shear_y(wrappee)
    }

    public func setMixShearY(mixShearY: Float) {
        spine_transform_constraint_pose_set_mix_shear_y(wrappee, mixShearY)
    }

    deinit {
        spine_transform_constraint_pose_dispose(wrappee)
    }
}