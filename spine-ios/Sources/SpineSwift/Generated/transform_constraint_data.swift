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

/// TransformConstraintData wrapper
public class TransformConstraintData: PosedData, ConstraintData {
    public init(fromPointer ptr: spine_transform_constraint_data) {
        super.init(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_posed_data_wrapper.self))
    }

    public convenience init(_ name: String) {
        let ptr = spine_transform_constraint_data_create(name)
        self.init(fromPointer: ptr!)
    }

    public var rtti: Rtti {
        let result = spine_transform_constraint_data_get_rtti(_ptr.assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self))
        return Rtti(fromPointer: result!)
    }

    public var bones: ArrayBoneData {
        let result = spine_transform_constraint_data_get_bones(_ptr.assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self))
        return ArrayBoneData(fromPointer: result!)
    }

    public var source: BoneData {
        get {
            let result = spine_transform_constraint_data_get_source(_ptr.assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self))
        return BoneData(fromPointer: result!)
        }
        set {
            spine_transform_constraint_data_set_source(_ptr.assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self), newValue._ptr.assumingMemoryBound(to: spine_bone_data_wrapper.self))
        }
    }

    public var offsetRotation: Float {
        get {
            let result = spine_transform_constraint_data_get_offset_rotation(_ptr.assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self))
        return result
        }
        set {
            spine_transform_constraint_data_set_offset_rotation(_ptr.assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self), newValue)
        }
    }

    public var offsetX: Float {
        get {
            let result = spine_transform_constraint_data_get_offset_x(_ptr.assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self))
        return result
        }
        set {
            spine_transform_constraint_data_set_offset_x(_ptr.assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self), newValue)
        }
    }

    public var offsetY: Float {
        get {
            let result = spine_transform_constraint_data_get_offset_y(_ptr.assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self))
        return result
        }
        set {
            spine_transform_constraint_data_set_offset_y(_ptr.assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self), newValue)
        }
    }

    public var offsetScaleX: Float {
        get {
            let result = spine_transform_constraint_data_get_offset_scale_x(_ptr.assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self))
        return result
        }
        set {
            spine_transform_constraint_data_set_offset_scale_x(_ptr.assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self), newValue)
        }
    }

    public var offsetScaleY: Float {
        get {
            let result = spine_transform_constraint_data_get_offset_scale_y(_ptr.assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self))
        return result
        }
        set {
            spine_transform_constraint_data_set_offset_scale_y(_ptr.assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self), newValue)
        }
    }

    public var offsetShearY: Float {
        get {
            let result = spine_transform_constraint_data_get_offset_shear_y(_ptr.assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self))
        return result
        }
        set {
            spine_transform_constraint_data_set_offset_shear_y(_ptr.assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self), newValue)
        }
    }

    public var localSource: Bool {
        get {
            let result = spine_transform_constraint_data_get_local_source(_ptr.assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self))
        return result
        }
        set {
            spine_transform_constraint_data_set_local_source(_ptr.assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self), newValue)
        }
    }

    public var localTarget: Bool {
        get {
            let result = spine_transform_constraint_data_get_local_target(_ptr.assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self))
        return result
        }
        set {
            spine_transform_constraint_data_set_local_target(_ptr.assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self), newValue)
        }
    }

    public var additive: Bool {
        get {
            let result = spine_transform_constraint_data_get_additive(_ptr.assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self))
        return result
        }
        set {
            spine_transform_constraint_data_set_additive(_ptr.assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self), newValue)
        }
    }

    public var clamp: Bool {
        get {
            let result = spine_transform_constraint_data_get_clamp(_ptr.assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self))
        return result
        }
        set {
            spine_transform_constraint_data_set_clamp(_ptr.assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self), newValue)
        }
    }

    public var properties: ArrayFromProperty {
        let result = spine_transform_constraint_data_get_properties(_ptr.assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self))
        return ArrayFromProperty(fromPointer: result!)
    }

    public var setupPose: TransformConstraintPose {
        let result = spine_transform_constraint_data_get_setup_pose(_ptr.assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self))
        return TransformConstraintPose(fromPointer: result!)
    }

    public func createMethod(_ skeleton: Skeleton) -> Constraint {
        let result = spine_transform_constraint_data_create_method(_ptr.assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self), skeleton._ptr.assumingMemoryBound(to: spine_skeleton_wrapper.self))
        let rtti = spine_constraint_get_rtti(result!)
        let className = String(cString: spine_rtti_get_class_name(rtti)!)
        switch className {
        case "spine_ik_constraint":
            return IkConstraint(fromPointer: UnsafeMutableRawPointer(result!).assumingMemoryBound(to: spine_ik_constraint_wrapper.self))
        case "spine_path_constraint":
            return PathConstraint(fromPointer: UnsafeMutableRawPointer(result!).assumingMemoryBound(to: spine_path_constraint_wrapper.self))
        case "spine_physics_constraint":
            return PhysicsConstraint(fromPointer: UnsafeMutableRawPointer(result!).assumingMemoryBound(to: spine_physics_constraint_wrapper.self))
        case "spine_slider":
            return Slider(fromPointer: UnsafeMutableRawPointer(result!).assumingMemoryBound(to: spine_slider_wrapper.self))
        case "spine_transform_constraint":
            return TransformConstraint(fromPointer: UnsafeMutableRawPointer(result!).assumingMemoryBound(to: spine_transform_constraint_wrapper.self))
        default:
            fatalError("Unknown concrete type: \(className) for abstract class Constraint")
        }
    }

    public static func rttiStatic() -> Rtti {
        let result = spine_transform_constraint_data_rtti()
        return Rtti(fromPointer: result!)
    }

    public override func dispose() {
        spine_transform_constraint_data_dispose(_ptr.assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self))
    }
}