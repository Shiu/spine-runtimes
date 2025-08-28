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

/// SliderData wrapper
@objc(SpineSliderData)
@objcMembers
public class SliderData: PosedData, ConstraintData {
    @nonobjc
    public init(fromPointer ptr: spine_slider_data) {
        super.init(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_posed_data_wrapper.self))
    }

    public convenience init(_ name: String) {
        let ptr = spine_slider_data_create(name)
        self.init(fromPointer: ptr!)
    }

    public var rtti: Rtti {
        let result = spine_slider_data_get_rtti(_ptr.assumingMemoryBound(to: spine_slider_data_wrapper.self))
        return Rtti(fromPointer: result!)
    }

    public var animation: Animation {
        get {
            let result = spine_slider_data_get_animation(_ptr.assumingMemoryBound(to: spine_slider_data_wrapper.self))
            return Animation(fromPointer: result!)
        }
        set {
            spine_slider_data_set_animation(
                _ptr.assumingMemoryBound(to: spine_slider_data_wrapper.self), newValue._ptr.assumingMemoryBound(to: spine_animation_wrapper.self))
        }
    }

    public var additive: Bool {
        get {
            let result = spine_slider_data_get_additive(_ptr.assumingMemoryBound(to: spine_slider_data_wrapper.self))
            return result
        }
        set {
            spine_slider_data_set_additive(_ptr.assumingMemoryBound(to: spine_slider_data_wrapper.self), newValue)
        }
    }

    public var loop: Bool {
        get {
            let result = spine_slider_data_get_loop(_ptr.assumingMemoryBound(to: spine_slider_data_wrapper.self))
            return result
        }
        set {
            spine_slider_data_set_loop(_ptr.assumingMemoryBound(to: spine_slider_data_wrapper.self), newValue)
        }
    }

    public var bone: BoneData? {
        get {
            let result = spine_slider_data_get_bone(_ptr.assumingMemoryBound(to: spine_slider_data_wrapper.self))
            return result.map { BoneData(fromPointer: $0) }
        }
        set {
            spine_slider_data_set_bone(
                _ptr.assumingMemoryBound(to: spine_slider_data_wrapper.self), newValue?._ptr.assumingMemoryBound(to: spine_bone_data_wrapper.self))
        }
    }

    public var property: FromProperty? {
        get {
            let result = spine_slider_data_get_property(_ptr.assumingMemoryBound(to: spine_slider_data_wrapper.self))
            guard let ptr = result else { return nil }
            let rtti = spine_from_property_get_rtti(ptr)
            let rttiClassName = String(cString: spine_rtti_get_class_name(rtti)!)
            switch rttiClassName {
            case "spine_from_rotate":
                return FromRotate(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_from_rotate_wrapper.self))
            case "spine_from_scale_x":
                return FromScaleX(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_from_scale_x_wrapper.self))
            case "spine_from_scale_y":
                return FromScaleY(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_from_scale_y_wrapper.self))
            case "spine_from_shear_y":
                return FromShearY(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_from_shear_y_wrapper.self))
            case "spine_from_x":
                return FromX(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_from_x_wrapper.self))
            case "spine_from_y":
                return FromY(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_from_y_wrapper.self))
            default:
                fatalError("Unknown concrete type: \(rttiClassName) for abstract class FromProperty")
            }
        }
        set {
            spine_slider_data_set_property(
                _ptr.assumingMemoryBound(to: spine_slider_data_wrapper.self), newValue?._ptr.assumingMemoryBound(to: spine_from_property_wrapper.self)
            )
        }
    }

    public var scale: Float {
        get {
            let result = spine_slider_data_get_scale(_ptr.assumingMemoryBound(to: spine_slider_data_wrapper.self))
            return result
        }
        set {
            spine_slider_data_set_scale(_ptr.assumingMemoryBound(to: spine_slider_data_wrapper.self), newValue)
        }
    }

    public var offset: Float {
        get {
            let result = spine_slider_data_get_offset(_ptr.assumingMemoryBound(to: spine_slider_data_wrapper.self))
            return result
        }
        set {
            spine_slider_data_set_offset(_ptr.assumingMemoryBound(to: spine_slider_data_wrapper.self), newValue)
        }
    }

    public var local: Bool {
        get {
            let result = spine_slider_data_get_local(_ptr.assumingMemoryBound(to: spine_slider_data_wrapper.self))
            return result
        }
        set {
            spine_slider_data_set_local(_ptr.assumingMemoryBound(to: spine_slider_data_wrapper.self), newValue)
        }
    }

    public var setupPose: SliderPose {
        let result = spine_slider_data_get_setup_pose(_ptr.assumingMemoryBound(to: spine_slider_data_wrapper.self))
        return SliderPose(fromPointer: result!)
    }

    public func createMethod(_ skeleton: Skeleton) -> Constraint {
        let result = spine_slider_data_create_method(
            _ptr.assumingMemoryBound(to: spine_slider_data_wrapper.self), skeleton._ptr.assumingMemoryBound(to: spine_skeleton_wrapper.self))
        let rtti = spine_constraint_get_rtti(result!)
        let rttiClassName = String(cString: spine_rtti_get_class_name(rtti)!)
        switch rttiClassName {
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
            fatalError("Unknown concrete type: \(rttiClassName) for abstract class Constraint")
        }
    }

    public static func rttiStatic() -> Rtti {
        let result = spine_slider_data_rtti()
        return Rtti(fromPointer: result!)
    }

    public override func dispose() {
        spine_slider_data_dispose(_ptr.assumingMemoryBound(to: spine_slider_data_wrapper.self))
    }
}
