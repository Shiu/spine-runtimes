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

@objc(SpinePhysicsConstraint)
@objcMembers
public final class PhysicsConstraint: PosedActive {
    internal let wrappee: spine_physics_constraint

    internal init(_ wrappee: spine_physics_constraint) {
        self.wrappee = wrappee
        super.init(wrappee)
    }

    public convenience init(data: PhysicsConstraintData, skeleton: Skeleton) {
        let ptr = spine_physics_constraint_create(data.wrappee, skeleton.wrappee)
        self.init(ptr)
    }

    public func getRtti() -> Rtti {
        let result = spine_physics_constraint_get_rtti(wrappee)
        return Rtti(result)
    }

    public func update(skeleton: Skeleton, physics: Physics) {
        spine_physics_constraint_update(wrappee, skeleton.wrappee, physics)
    }

    public func sort(skeleton: Skeleton) {
        spine_physics_constraint_sort(wrappee, skeleton.wrappee)
    }

    public func isSourceActive() -> Bool {
        return spine_physics_constraint_is_source_active(wrappee) != 0
    }

    public func copy(skeleton: Skeleton) -> PhysicsConstraint {
        let result = spine_physics_constraint_copy(wrappee, skeleton.wrappee)
        return PhysicsConstraint(result)
    }

    public func reset(skeleton: Skeleton) {
        spine_physics_constraint_reset(wrappee, skeleton.wrappee)
    }

    public func translate(x: Float, y: Float) {
        spine_physics_constraint_translate(wrappee, x, y)
    }

    public func rotate(x: Float, y: Float, degrees: Float) {
        spine_physics_constraint_rotate(wrappee, x, y, degrees)
    }

    public func getBone() -> BonePose {
        let result = spine_physics_constraint_get_bone(wrappee)
        return BonePose(result)
    }

    public func setBone(bone: BonePose) {
        spine_physics_constraint_set_bone(wrappee, bone.wrappee)
    }

    public func getData() -> PhysicsConstraintData {
        let result = spine_physics_constraint_get_data(wrappee)
        return PhysicsConstraintData(result)
    }

    public func getPose() -> PhysicsConstraintPose {
        let result = spine_physics_constraint_get_pose(wrappee)
        return PhysicsConstraintPose(result)
    }

    public func getAppliedPose() -> PhysicsConstraintPose {
        let result = spine_physics_constraint_get_applied_pose(wrappee)
        return PhysicsConstraintPose(result)
    }

    public func resetConstrained() {
        spine_physics_constraint_reset_constrained(wrappee)
    }

    public func constrained() {
        spine_physics_constraint_constrained(wrappee)
    }

    public func isPoseEqualToApplied() -> Bool {
        return spine_physics_constraint_is_pose_equal_to_applied(wrappee) != 0
    }

    public func isActive() -> Bool {
        return spine_physics_constraint_is_active(wrappee) != 0
    }

    public func setActive(active: Bool) {
        spine_physics_constraint_set_active(wrappee, active ? 1 : 0)
    }

    public func rtti() -> Rtti {
        let result = spine_physics_constraint_rtti(wrappee)
        return Rtti(result)
    }

    deinit {
        spine_physics_constraint_dispose(wrappee)
    }
}