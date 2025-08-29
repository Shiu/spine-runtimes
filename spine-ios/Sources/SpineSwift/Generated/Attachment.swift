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

/// Attachment wrapper
@objc(SpineAttachment)
@objcMembers
open class Attachment: NSObject {
    public let _ptr: UnsafeMutableRawPointer

    public init(fromPointer ptr: spine_attachment) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        super.init()
    }

    public var rtti: Rtti {
        let result = spine_attachment_get_rtti(_ptr.assumingMemoryBound(to: spine_attachment_wrapper.self))
        return Rtti(fromPointer: result!)
    }

    public var name: String {
        let result = spine_attachment_get_name(_ptr.assumingMemoryBound(to: spine_attachment_wrapper.self))
        return String(cString: result!)
    }

    public var refCount: Int32 {
        let result = spine_attachment_get_ref_count(_ptr.assumingMemoryBound(to: spine_attachment_wrapper.self))
        return result
    }

    public func copyAttachment() -> Attachment {
        let result = spine_attachment_copy(_ptr.assumingMemoryBound(to: spine_attachment_wrapper.self))
        let rtti = spine_attachment_get_rtti(result!)
        let rttiClassName = String(cString: spine_rtti_get_class_name(rtti)!)
        switch rttiClassName {
        case "spine_bounding_box_attachment":
            return BoundingBoxAttachment(fromPointer: UnsafeMutableRawPointer(result!).assumingMemoryBound(to: spine_bounding_box_attachment_wrapper.self))
        case "spine_clipping_attachment":
            return ClippingAttachment(fromPointer: UnsafeMutableRawPointer(result!).assumingMemoryBound(to: spine_clipping_attachment_wrapper.self))
        case "spine_mesh_attachment":
            return MeshAttachment(fromPointer: UnsafeMutableRawPointer(result!).assumingMemoryBound(to: spine_mesh_attachment_wrapper.self))
        case "spine_path_attachment":
            return PathAttachment(fromPointer: UnsafeMutableRawPointer(result!).assumingMemoryBound(to: spine_path_attachment_wrapper.self))
        case "spine_point_attachment":
            return PointAttachment(fromPointer: UnsafeMutableRawPointer(result!).assumingMemoryBound(to: spine_point_attachment_wrapper.self))
        case "spine_region_attachment":
            return RegionAttachment(fromPointer: UnsafeMutableRawPointer(result!).assumingMemoryBound(to: spine_region_attachment_wrapper.self))
        default:
            fatalError("Unknown concrete type: \(rttiClassName) for abstract class Attachment")
        }
    }

    public func reference() {
        spine_attachment_reference(_ptr.assumingMemoryBound(to: spine_attachment_wrapper.self))
    }

    public func dereference() {
        spine_attachment_dereference(_ptr.assumingMemoryBound(to: spine_attachment_wrapper.self))
    }

    public static func rttiStatic() -> Rtti {
        let result = spine_attachment_rtti()
        return Rtti(fromPointer: result!)
    }

}