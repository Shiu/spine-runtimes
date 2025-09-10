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
public class PhysicsConstraint: PhysicsConstraintBase {
    @nonobjc
    public init(fromPointer ptr: spine_physics_constraint) {
        super.init(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_physics_constraint_base_wrapper.self))
    }

    public convenience init(_ data: PhysicsConstraintData, _ skeleton: Skeleton) {
        let ptr = spine_physics_constraint_create(data._ptr.assumingMemoryBound(to: spine_physics_constraint_data_wrapper.self), skeleton._ptr.assumingMemoryBound(to: spine_skeleton_wrapper.self))
        self.init(fromPointer: ptr!)
    }

    public var bone: BonePose {
        get {
            let result = spine_physics_constraint_get_bone(_ptr.assumingMemoryBound(to: spine_physics_constraint_wrapper.self))
        return BonePose(fromPointer: result!)
        }
        set {
            spine_physics_constraint_set_bone(_ptr.assumingMemoryBound(to: spine_physics_constraint_wrapper.self), newValue._ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self))
        }
    }

    public func copyAttachment(_ skeleton: Skeleton) -> PhysicsConstraint {
        let result = spine_physics_constraint_copy(_ptr.assumingMemoryBound(to: spine_physics_constraint_wrapper.self), skeleton._ptr.assumingMemoryBound(to: spine_skeleton_wrapper.self))
        return PhysicsConstraint(fromPointer: result!)
    }

    public func reset(_ skeleton: Skeleton) {
        spine_physics_constraint_reset(_ptr.assumingMemoryBound(to: spine_physics_constraint_wrapper.self), skeleton._ptr.assumingMemoryBound(to: spine_skeleton_wrapper.self))
    }

    public func translate(_ x: Float, _ y: Float) {
        spine_physics_constraint_translate(_ptr.assumingMemoryBound(to: spine_physics_constraint_wrapper.self), x, y)
    }

    public func rotate(_ x: Float, _ y: Float, _ degrees: Float) {
        spine_physics_constraint_rotate(_ptr.assumingMemoryBound(to: spine_physics_constraint_wrapper.self), x, y, degrees)
    }

    public override func dispose() {
        spine_physics_constraint_dispose(_ptr.assumingMemoryBound(to: spine_physics_constraint_wrapper.self))
    }
}