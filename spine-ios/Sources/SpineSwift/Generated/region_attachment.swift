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

/// RegionAttachment wrapper
public class RegionAttachment: Attachment {
    public init(fromPointer ptr: spine_region_attachment) {
        super.init(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_attachment_wrapper.self))
    }

    public convenience init(_ name: String) {
        let ptr = spine_region_attachment_create(name)
        self.init(fromPointer: ptr!)
    }

    public var x: Float {
        get {
            let result = spine_region_attachment_get_x(_ptr.assumingMemoryBound(to: spine_region_attachment_wrapper.self))
        return result
        }
        set {
            spine_region_attachment_set_x(_ptr.assumingMemoryBound(to: spine_region_attachment_wrapper.self), newValue)
        }
    }

    public var y: Float {
        get {
            let result = spine_region_attachment_get_y(_ptr.assumingMemoryBound(to: spine_region_attachment_wrapper.self))
        return result
        }
        set {
            spine_region_attachment_set_y(_ptr.assumingMemoryBound(to: spine_region_attachment_wrapper.self), newValue)
        }
    }

    public var rotation: Float {
        get {
            let result = spine_region_attachment_get_rotation(_ptr.assumingMemoryBound(to: spine_region_attachment_wrapper.self))
        return result
        }
        set {
            spine_region_attachment_set_rotation(_ptr.assumingMemoryBound(to: spine_region_attachment_wrapper.self), newValue)
        }
    }

    public var scaleX: Float {
        get {
            let result = spine_region_attachment_get_scale_x(_ptr.assumingMemoryBound(to: spine_region_attachment_wrapper.self))
        return result
        }
        set {
            spine_region_attachment_set_scale_x(_ptr.assumingMemoryBound(to: spine_region_attachment_wrapper.self), newValue)
        }
    }

    public var scaleY: Float {
        get {
            let result = spine_region_attachment_get_scale_y(_ptr.assumingMemoryBound(to: spine_region_attachment_wrapper.self))
        return result
        }
        set {
            spine_region_attachment_set_scale_y(_ptr.assumingMemoryBound(to: spine_region_attachment_wrapper.self), newValue)
        }
    }

    public var width: Float {
        get {
            let result = spine_region_attachment_get_width(_ptr.assumingMemoryBound(to: spine_region_attachment_wrapper.self))
        return result
        }
        set {
            spine_region_attachment_set_width(_ptr.assumingMemoryBound(to: spine_region_attachment_wrapper.self), newValue)
        }
    }

    public var height: Float {
        get {
            let result = spine_region_attachment_get_height(_ptr.assumingMemoryBound(to: spine_region_attachment_wrapper.self))
        return result
        }
        set {
            spine_region_attachment_set_height(_ptr.assumingMemoryBound(to: spine_region_attachment_wrapper.self), newValue)
        }
    }

    public var color: Color {
        let result = spine_region_attachment_get_color(_ptr.assumingMemoryBound(to: spine_region_attachment_wrapper.self))
        return Color(fromPointer: result!)
    }

    public var path: String {
        get {
            let result = spine_region_attachment_get_path(_ptr.assumingMemoryBound(to: spine_region_attachment_wrapper.self))
        return String(cString: result!)
        }
        set {
            spine_region_attachment_set_path(_ptr.assumingMemoryBound(to: spine_region_attachment_wrapper.self), newValue)
        }
    }

    public var region: TextureRegion? {
        get {
            let result = spine_region_attachment_get_region(_ptr.assumingMemoryBound(to: spine_region_attachment_wrapper.self))
        return result.map { TextureRegion(fromPointer: $0) }
        }
        set {
            spine_region_attachment_set_region(_ptr.assumingMemoryBound(to: spine_region_attachment_wrapper.self), newValue?._ptr.assumingMemoryBound(to: spine_texture_region_wrapper.self))
        }
    }

    public var sequence: Sequence? {
        get {
            let result = spine_region_attachment_get_sequence(_ptr.assumingMemoryBound(to: spine_region_attachment_wrapper.self))
        return result.map { Sequence(fromPointer: $0) }
        }
        set {
            spine_region_attachment_set_sequence(_ptr.assumingMemoryBound(to: spine_region_attachment_wrapper.self), newValue?._ptr.assumingMemoryBound(to: spine_sequence_wrapper.self))
        }
    }

    public var offset: ArrayFloat {
        let result = spine_region_attachment_get_offset(_ptr.assumingMemoryBound(to: spine_region_attachment_wrapper.self))
        return ArrayFloat(fromPointer: result!)
    }

    public var uVs: ArrayFloat {
        let result = spine_region_attachment_get_u_vs(_ptr.assumingMemoryBound(to: spine_region_attachment_wrapper.self))
        return ArrayFloat(fromPointer: result!)
    }

    public func updateRegion() {
        spine_region_attachment_update_region(_ptr.assumingMemoryBound(to: spine_region_attachment_wrapper.self))
    }

    public func computeWorldVertices(_ slot: Slot, _ worldVertices: ArrayFloat, _ offset: Int, _ stride: Int) {
        spine_region_attachment_compute_world_vertices_2(_ptr.assumingMemoryBound(to: spine_region_attachment_wrapper.self), slot._ptr.assumingMemoryBound(to: spine_slot_wrapper.self), worldVertices._ptr.assumingMemoryBound(to: spine_array_float_wrapper.self), offset, stride)
    }

    deinit {
        spine_region_attachment_dispose(_ptr.assumingMemoryBound(to: spine_region_attachment_wrapper.self))
    }
}