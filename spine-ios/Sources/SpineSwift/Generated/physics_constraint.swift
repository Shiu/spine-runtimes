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

/// PhysicsConstraint wrapper
@objc(SpinePhysicsConstraint)
@objcMembers
public class PhysicsConstraint: PosedActive, Posed, Constraint {
    @nonobjc
    public init(fromPointer ptr: spine_physics_constraint) {
        super.init(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_posed_active_wrapper.self))
    }

    public convenience init(_ data: PhysicsConstraintData, _ skeleton: Skeleton) {
        let ptr = spine_physics_constraint_create(
            data._ptr.assumingMemoryBound(to: spine_physics_constraint_data_wrapper.self),
            skeleton._ptr.assumingMemoryBound(to: spine_skeleton_wrapper.self))
        self.init(fromPointer: ptr!)
    }

    public var rtti: Rtti {
        let result = spine_physics_constraint_get_rtti(_ptr.assumingMemoryBound(to: spine_physics_constraint_wrapper.self))
        return Rtti(fromPointer: result!)
    }

    public var isSourceActive: Bool {
        let result = spine_physics_constraint_is_source_active(_ptr.assumingMemoryBound(to: spine_physics_constraint_wrapper.self))
        return result
    }

    public var bone: BonePose {
        get {
            let result = spine_physics_constraint_get_bone(_ptr.assumingMemoryBound(to: spine_physics_constraint_wrapper.self))
            return BonePose(fromPointer: result!)
        }
        set {
            spine_physics_constraint_set_bone(
                _ptr.assumingMemoryBound(to: spine_physics_constraint_wrapper.self),
                newValue._ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self))
        }
    }

    public var data: ConstraintData {
        let result = spine_physics_constraint_get_data(_ptr.assumingMemoryBound(to: spine_physics_constraint_wrapper.self))
        return PhysicsConstraintData(fromPointer: result!)
    }

    public var pose: PhysicsConstraintPose {
        let result = spine_physics_constraint_get_pose(_ptr.assumingMemoryBound(to: spine_physics_constraint_wrapper.self))
        return PhysicsConstraintPose(fromPointer: result!)
    }

    public var appliedPose: PhysicsConstraintPose {
        let result = spine_physics_constraint_get_applied_pose(_ptr.assumingMemoryBound(to: spine_physics_constraint_wrapper.self))
        return PhysicsConstraintPose(fromPointer: result!)
    }

    public var isPoseEqualToApplied: Bool {
        let result = spine_physics_constraint_is_pose_equal_to_applied(_ptr.assumingMemoryBound(to: spine_physics_constraint_wrapper.self))
        return result
    }

    public func update(_ skeleton: Skeleton, _ physics: Physics) {
        spine_physics_constraint_update(
            _ptr.assumingMemoryBound(to: spine_physics_constraint_wrapper.self), skeleton._ptr.assumingMemoryBound(to: spine_skeleton_wrapper.self),
            spine_physics(rawValue: UInt32(physics.rawValue)))
    }

    public func sort(_ skeleton: Skeleton) {
        spine_physics_constraint_sort(
            _ptr.assumingMemoryBound(to: spine_physics_constraint_wrapper.self), skeleton._ptr.assumingMemoryBound(to: spine_skeleton_wrapper.self))
    }

    public func copyAttachment(_ skeleton: Skeleton) -> PhysicsConstraint {
        let result = spine_physics_constraint_copy(
            _ptr.assumingMemoryBound(to: spine_physics_constraint_wrapper.self), skeleton._ptr.assumingMemoryBound(to: spine_skeleton_wrapper.self))
        return PhysicsConstraint(fromPointer: result!)
    }

    public func reset(_ skeleton: Skeleton) {
        spine_physics_constraint_reset(
            _ptr.assumingMemoryBound(to: spine_physics_constraint_wrapper.self), skeleton._ptr.assumingMemoryBound(to: spine_skeleton_wrapper.self))
    }

    public func translate(_ x: Float, _ y: Float) {
        spine_physics_constraint_translate(_ptr.assumingMemoryBound(to: spine_physics_constraint_wrapper.self), x, y)
    }

    public func rotate(_ x: Float, _ y: Float, _ degrees: Float) {
        spine_physics_constraint_rotate(_ptr.assumingMemoryBound(to: spine_physics_constraint_wrapper.self), x, y, degrees)
    }

    public func resetConstrained() {
        spine_physics_constraint_reset_constrained(_ptr.assumingMemoryBound(to: spine_physics_constraint_wrapper.self))
    }

    public func constrained() {
        spine_physics_constraint_constrained(_ptr.assumingMemoryBound(to: spine_physics_constraint_wrapper.self))
    }

    public static func rttiStatic() -> Rtti {
        let result = spine_physics_constraint_rtti()
        return Rtti(fromPointer: result!)
    }

    public override func dispose() {
        spine_physics_constraint_dispose(_ptr.assumingMemoryBound(to: spine_physics_constraint_wrapper.self))
    }
}
