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

/// BonePose wrapper
public class BonePose: BoneLocal, Update {
    public init(fromPointer ptr: spine_bone_pose) {
        super.init(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_bone_local_wrapper.self))
    }

    public convenience init() {
        let ptr = spine_bone_pose_create()
        self.init(fromPointer: ptr!)
    }

    public var rtti: Rtti {
        let result = spine_bone_pose_get_rtti(_ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self))
        return Rtti(fromPointer: result!)
    }

    public var a: Float {
        get {
            let result = spine_bone_pose_get_a(_ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self))
        return result
        }
        set {
            spine_bone_pose_set_a(_ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self), newValue)
        }
    }

    public var b: Float {
        get {
            let result = spine_bone_pose_get_b(_ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self))
        return result
        }
        set {
            spine_bone_pose_set_b(_ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self), newValue)
        }
    }

    public var c: Float {
        get {
            let result = spine_bone_pose_get_c(_ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self))
        return result
        }
        set {
            spine_bone_pose_set_c(_ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self), newValue)
        }
    }

    public var d: Float {
        get {
            let result = spine_bone_pose_get_d(_ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self))
        return result
        }
        set {
            spine_bone_pose_set_d(_ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self), newValue)
        }
    }

    public var worldX: Float {
        get {
            let result = spine_bone_pose_get_world_x(_ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self))
        return result
        }
        set {
            spine_bone_pose_set_world_x(_ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self), newValue)
        }
    }

    public var worldY: Float {
        get {
            let result = spine_bone_pose_get_world_y(_ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self))
        return result
        }
        set {
            spine_bone_pose_set_world_y(_ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self), newValue)
        }
    }

    public var worldRotationX: Float {
        let result = spine_bone_pose_get_world_rotation_x(_ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self))
        return result
    }

    public var worldRotationY: Float {
        let result = spine_bone_pose_get_world_rotation_y(_ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self))
        return result
    }

    public var worldScaleX: Float {
        let result = spine_bone_pose_get_world_scale_x(_ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self))
        return result
    }

    public var worldScaleY: Float {
        let result = spine_bone_pose_get_world_scale_y(_ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self))
        return result
    }

    public func update(_ skeleton: Skeleton, _ physics: Physics) {
        spine_bone_pose_update(_ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self), skeleton._ptr.assumingMemoryBound(to: spine_skeleton_wrapper.self), spine_physics(rawValue: UInt32(physics.rawValue)))
    }

    public func updateWorldTransform(_ skeleton: Skeleton) {
        spine_bone_pose_update_world_transform(_ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self), skeleton._ptr.assumingMemoryBound(to: spine_skeleton_wrapper.self))
    }

    public func updateLocalTransform(_ skeleton: Skeleton) {
        spine_bone_pose_update_local_transform(_ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self), skeleton._ptr.assumingMemoryBound(to: spine_skeleton_wrapper.self))
    }

    public func validateLocalTransform(_ skeleton: Skeleton) {
        spine_bone_pose_validate_local_transform(_ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self), skeleton._ptr.assumingMemoryBound(to: spine_skeleton_wrapper.self))
    }

    public func modifyLocal(_ skeleton: Skeleton) {
        spine_bone_pose_modify_local(_ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self), skeleton._ptr.assumingMemoryBound(to: spine_skeleton_wrapper.self))
    }

    public func modifyWorld(_ update: Int32) {
        spine_bone_pose_modify_world(_ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self), update)
    }

    public func resetWorld(_ update: Int32) {
        spine_bone_pose_reset_world(_ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self), update)
    }

    public func worldToLocalRotation(_ worldRotation: Float) -> Float {
        let result = spine_bone_pose_world_to_local_rotation(_ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self), worldRotation)
        return result
    }

    public func localToWorldRotation(_ localRotation: Float) -> Float {
        let result = spine_bone_pose_local_to_world_rotation(_ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self), localRotation)
        return result
    }

    public func rotateWorld(_ degrees: Float) {
        spine_bone_pose_rotate_world(_ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self), degrees)
    }

    public static func rttiStatic() -> Rtti {
        let result = spine_bone_pose_rtti()
        return Rtti(fromPointer: result!)
    }

    public override func dispose() {
        spine_bone_pose_dispose(_ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self))
    }
}