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

@objc(SpineIkConstraint)
@objcMembers
public final class IkConstraint: PosedActive {
    internal let wrappee: spine_ik_constraint

    internal init(_ wrappee: spine_ik_constraint) {
        self.wrappee = wrappee
        super.init(wrappee)
    }

    public convenience init(data: IkConstraintData, skeleton: Skeleton) {
        let ptr = spine_ik_constraint_create(data.wrappee, skeleton.wrappee)
        self.init(ptr)
    }

    public func getRtti() -> Rtti {
        let result = spine_ik_constraint_get_rtti(wrappee)
        return Rtti(result)
    }

    public func copy(skeleton: Skeleton) -> IkConstraint {
        let result = spine_ik_constraint_copy(wrappee, skeleton.wrappee)
        return IkConstraint(result)
    }

    public func update(skeleton: Skeleton, physics: Physics) {
        spine_ik_constraint_update(wrappee, skeleton.wrappee, physics)
    }

    public func sort(skeleton: Skeleton) {
        spine_ik_constraint_sort(wrappee, skeleton.wrappee)
    }

    public func isSourceActive() -> Bool {
        return spine_ik_constraint_is_source_active(wrappee) != 0
    }

    public func getData() -> IkConstraintData {
        let result = spine_ik_constraint_get_data(wrappee)
        return IkConstraintData(result)
    }

    public func getBones() -> ArrayBonePose {
        return spine_ik_constraint_get_bones(wrappee)
    }

    public func getTarget() -> Bone {
        let result = spine_ik_constraint_get_target(wrappee)
        return Bone(result)
    }

    public func setTarget(inValue: Bone) {
        spine_ik_constraint_set_target(wrappee, inValue.wrappee)
    }

    public func apply(skeleton: Skeleton, bone: BonePose, targetX: Float, targetY: Float, compress: Bool, stretch: Bool, uniform: Bool, mix: Float) {
        spine_ik_constraint_apply_1(wrappee, skeleton.wrappee, bone.wrappee, targetX, targetY, compress ? 1 : 0, stretch ? 1 : 0, uniform ? 1 : 0, mix)
    }

    public func apply(skeleton: Skeleton, parent: BonePose, child: BonePose, targetX: Float, targetY: Float, bendDirection: Int32, stretch: Bool, uniform: Bool, softness: Float, mix: Float) {
        spine_ik_constraint_apply_2(wrappee, skeleton.wrappee, parent.wrappee, child.wrappee, targetX, targetY, bendDirection, stretch ? 1 : 0, uniform ? 1 : 0, softness, mix)
    }

    public func getPose() -> IkConstraintPose {
        let result = spine_ik_constraint_get_pose(wrappee)
        return IkConstraintPose(result)
    }

    public func getAppliedPose() -> IkConstraintPose {
        let result = spine_ik_constraint_get_applied_pose(wrappee)
        return IkConstraintPose(result)
    }

    public func resetConstrained() {
        spine_ik_constraint_reset_constrained(wrappee)
    }

    public func constrained() {
        spine_ik_constraint_constrained(wrappee)
    }

    public func isPoseEqualToApplied() -> Bool {
        return spine_ik_constraint_is_pose_equal_to_applied(wrappee) != 0
    }

    public func isActive() -> Bool {
        return spine_ik_constraint_is_active(wrappee) != 0
    }

    public func setActive(active: Bool) {
        spine_ik_constraint_set_active(wrappee, active ? 1 : 0)
    }

    public func rtti() -> Rtti {
        let result = spine_ik_constraint_rtti(wrappee)
        return Rtti(result)
    }

    deinit {
        spine_ik_constraint_dispose(wrappee)
    }
}