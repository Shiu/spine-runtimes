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

/// Skin wrapper
@objc(SpineSkin)
@objcMembers
public class Skin: NSObject {
    public let _ptr: UnsafeMutableRawPointer

    public init(fromPointer ptr: spine_skin) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        super.init()
    }

    public convenience init(_ name: String) {
        let ptr = spine_skin_create(name)
        self.init(fromPointer: ptr!)
    }

    public var name: String {
        let result = spine_skin_get_name(_ptr.assumingMemoryBound(to: spine_skin_wrapper.self))
        return String(cString: result!)
    }

    public var bones: ArrayBoneData {
        let result = spine_skin_get_bones(_ptr.assumingMemoryBound(to: spine_skin_wrapper.self))
        return ArrayBoneData(fromPointer: result!)
    }

    public var constraints: ArrayConstraintData {
        let result = spine_skin_get_constraints(_ptr.assumingMemoryBound(to: spine_skin_wrapper.self))
        return ArrayConstraintData(fromPointer: result!)
    }

    public var color: Color {
        let result = spine_skin_get_color(_ptr.assumingMemoryBound(to: spine_skin_wrapper.self))
        return Color(fromPointer: result!)
    }

    public func setAttachment(_ slotIndex: Int, _ name: String, _ attachment: Attachment) {
        spine_skin_set_attachment(_ptr.assumingMemoryBound(to: spine_skin_wrapper.self), slotIndex, name, attachment._ptr.assumingMemoryBound(to: spine_attachment_wrapper.self))
    }

    public func getAttachment(_ slotIndex: Int, _ name: String) -> Attachment? {
        let result = spine_skin_get_attachment(_ptr.assumingMemoryBound(to: spine_skin_wrapper.self), slotIndex, name)
        guard let ptr = result else { return nil }
        let rtti = spine_attachment_get_rtti(ptr)
        let rttiClassName = String(cString: spine_rtti_get_class_name(rtti)!)
        switch rttiClassName {
        case "spine_bounding_box_attachment":
            return BoundingBoxAttachment(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_bounding_box_attachment_wrapper.self))
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

    public func removeAttachment(_ slotIndex: Int, _ name: String) {
        spine_skin_remove_attachment(_ptr.assumingMemoryBound(to: spine_skin_wrapper.self), slotIndex, name)
    }

    public func findAttachmentsForSlot(_ slotIndex: Int, _ attachments: ArrayAttachment) {
        spine_skin_find_attachments_for_slot(_ptr.assumingMemoryBound(to: spine_skin_wrapper.self), slotIndex, attachments._ptr.assumingMemoryBound(to: spine_array_attachment_wrapper.self))
    }

    public func addSkin(_ other: Skin) {
        spine_skin_add_skin(_ptr.assumingMemoryBound(to: spine_skin_wrapper.self), other._ptr.assumingMemoryBound(to: spine_skin_wrapper.self))
    }

    public func copySkin(_ other: Skin) {
        spine_skin_copy_skin(_ptr.assumingMemoryBound(to: spine_skin_wrapper.self), other._ptr.assumingMemoryBound(to: spine_skin_wrapper.self))
    }

    public func dispose() {
        spine_skin_dispose(_ptr.assumingMemoryBound(to: spine_skin_wrapper.self))
    }
}