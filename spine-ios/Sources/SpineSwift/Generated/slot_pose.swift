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

/// SlotPose wrapper
@objc(SpineSlotPose)
@objcMembers
public class SlotPose: NSObject {
    public let _ptr: UnsafeMutableRawPointer

    public init(fromPointer ptr: spine_slot_pose) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        super.init()
    }

    public override convenience init() {
        let ptr = spine_slot_pose_create()
        self.init(fromPointer: ptr!)
    }

    public var color: Color {
        let result = spine_slot_pose_get_color(_ptr.assumingMemoryBound(to: spine_slot_pose_wrapper.self))
        return Color(fromPointer: result!)
    }

    public var darkColor: Color {
        let result = spine_slot_pose_get_dark_color(_ptr.assumingMemoryBound(to: spine_slot_pose_wrapper.self))
        return Color(fromPointer: result!)
    }

    public var hasDarkColor: Bool {
        get {
            let result = spine_slot_pose_has_dark_color(_ptr.assumingMemoryBound(to: spine_slot_pose_wrapper.self))
            return result
        }
        set {
            spine_slot_pose_set_has_dark_color(_ptr.assumingMemoryBound(to: spine_slot_pose_wrapper.self), newValue)
        }
    }

    public var attachment: Attachment? {
        get {
            let result = spine_slot_pose_get_attachment(_ptr.assumingMemoryBound(to: spine_slot_pose_wrapper.self))
            guard let ptr = result else { return nil }
            let rtti = spine_attachment_get_rtti(ptr)
            let rttiClassName = String(cString: spine_rtti_get_class_name(rtti)!)
            switch rttiClassName {
            case "spine_bounding_box_attachment":
                return BoundingBoxAttachment(
                    fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_bounding_box_attachment_wrapper.self))
            case "spine_clipping_attachment":
                return ClippingAttachment(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_clipping_attachment_wrapper.self))
            case "spine_mesh_attachment":
                return MeshAttachment(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_mesh_attachment_wrapper.self))
            case "spine_path_attachment":
                return PathAttachment(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_path_attachment_wrapper.self))
            case "spine_point_attachment":
                return PointAttachment(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_point_attachment_wrapper.self))
            case "spine_region_attachment":
                return RegionAttachment(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_region_attachment_wrapper.self))
            default:
                fatalError("Unknown concrete type: \(rttiClassName) for abstract class Attachment")
            }
        }
        set {
            spine_slot_pose_set_attachment(
                _ptr.assumingMemoryBound(to: spine_slot_pose_wrapper.self), newValue?._ptr.assumingMemoryBound(to: spine_attachment_wrapper.self))
        }
    }

    public var sequenceIndex: Int32 {
        get {
            let result = spine_slot_pose_get_sequence_index(_ptr.assumingMemoryBound(to: spine_slot_pose_wrapper.self))
            return result
        }
        set {
            spine_slot_pose_set_sequence_index(_ptr.assumingMemoryBound(to: spine_slot_pose_wrapper.self), newValue)
        }
    }

    public var deform: ArrayFloat {
        let result = spine_slot_pose_get_deform(_ptr.assumingMemoryBound(to: spine_slot_pose_wrapper.self))
        return ArrayFloat(fromPointer: result!)
    }

    public func set(_ pose: SlotPose) {
        spine_slot_pose_set(
            _ptr.assumingMemoryBound(to: spine_slot_pose_wrapper.self), pose._ptr.assumingMemoryBound(to: spine_slot_pose_wrapper.self))
    }

    public func dispose() {
        spine_slot_pose_dispose(_ptr.assumingMemoryBound(to: spine_slot_pose_wrapper.self))
    }
}
