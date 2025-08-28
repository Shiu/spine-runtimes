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

/// VertexAttachment wrapper
@objc(SpineVertexAttachment)
@objcMembers
open class VertexAttachment: Attachment {
    @nonobjc
    public init(fromPointer ptr: spine_vertex_attachment) {
        super.init(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_attachment_wrapper.self))
    }

    public var id: Int32 {
        let result = spine_vertex_attachment_get_id(_ptr.assumingMemoryBound(to: spine_vertex_attachment_wrapper.self))
        return result
    }

    public var bones: ArrayInt {
        get {
            let result = spine_vertex_attachment_get_bones(_ptr.assumingMemoryBound(to: spine_vertex_attachment_wrapper.self))
            return ArrayInt(fromPointer: result!)
        }
        set {
            spine_vertex_attachment_set_bones(
                _ptr.assumingMemoryBound(to: spine_vertex_attachment_wrapper.self),
                newValue._ptr.assumingMemoryBound(to: spine_array_int_wrapper.self))
        }
    }

    public var vertices: ArrayFloat {
        get {
            let result = spine_vertex_attachment_get_vertices(_ptr.assumingMemoryBound(to: spine_vertex_attachment_wrapper.self))
            return ArrayFloat(fromPointer: result!)
        }
        set {
            spine_vertex_attachment_set_vertices(
                _ptr.assumingMemoryBound(to: spine_vertex_attachment_wrapper.self),
                newValue._ptr.assumingMemoryBound(to: spine_array_float_wrapper.self))
        }
    }

    public var worldVerticesLength: Int {
        get {
            let result = spine_vertex_attachment_get_world_vertices_length(_ptr.assumingMemoryBound(to: spine_vertex_attachment_wrapper.self))
            return result
        }
        set {
            spine_vertex_attachment_set_world_vertices_length(_ptr.assumingMemoryBound(to: spine_vertex_attachment_wrapper.self), newValue)
        }
    }

    public var timelineAttachment: Attachment? {
        get {
            let result = spine_vertex_attachment_get_timeline_attachment(_ptr.assumingMemoryBound(to: spine_vertex_attachment_wrapper.self))
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
            spine_vertex_attachment_set_timeline_attachment(
                _ptr.assumingMemoryBound(to: spine_vertex_attachment_wrapper.self),
                newValue?._ptr.assumingMemoryBound(to: spine_attachment_wrapper.self))
        }
    }

    public func copyTo(_ other: VertexAttachment) {
        spine_vertex_attachment_copy_to(
            _ptr.assumingMemoryBound(to: spine_vertex_attachment_wrapper.self),
            other._ptr.assumingMemoryBound(to: spine_vertex_attachment_wrapper.self))
    }

    public func computeWorldVertices(
        _ skeleton: Skeleton, _ slot: Slot, _ start: Int, _ count: Int, _ worldVertices: ArrayFloat, _ offset: Int, _ stride: Int
    ) {
        spine_vertex_attachment_compute_world_vertices_2(
            _ptr.assumingMemoryBound(to: spine_vertex_attachment_wrapper.self), skeleton._ptr.assumingMemoryBound(to: spine_skeleton_wrapper.self),
            slot._ptr.assumingMemoryBound(to: spine_slot_wrapper.self), start, count,
            worldVertices._ptr.assumingMemoryBound(to: spine_array_float_wrapper.self), offset, stride)
    }

}
