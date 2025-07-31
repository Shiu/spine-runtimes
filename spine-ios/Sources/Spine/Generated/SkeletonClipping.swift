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

import Foundation

@objc(SpineSkeletonClipping)
@objcMembers
public final class SkeletonClipping: NSObject {
    internal let wrappee: spine_skeleton_clipping

    internal init(_ wrappee: spine_skeleton_clipping) {
        self.wrappee = wrappee
        super.init()
    }

    public override func isEqual(_ object: Any?) -> Bool {
        guard let other = object as? SkeletonClipping else { return false }
        return self.wrappee == other.wrappee
    }

    public override var hash: Int {
        var hasher = Hasher()
        hasher.combine(self.wrappee)
        return hasher.finalize()
    }

    public convenience init() {
        let ptr = spine_skeleton_clipping_create()
        self.init(ptr)
    }

    public func clipStart(skeleton: Skeleton, slot: Slot, clip: ClippingAttachment) -> size_t {
        return spine_skeleton_clipping_clip_start(wrappee, skeleton.wrappee, slot.wrappee, clip.wrappee)
    }

    public func clipEnd(slot: Slot) {
        spine_skeleton_clipping_clip_end_1(wrappee, slot.wrappee)
    }

    public func clipEnd() {
        spine_skeleton_clipping_clip_end_2(wrappee)
    }

    public func clipTriangles(vertices: UnsafeMutablePointer<Float>?, triangles: OpaquePointer?, trianglesLength: size_t) -> Bool {
        return spine_skeleton_clipping_clip_triangles_1(wrappee, vertices, triangles, trianglesLength) != 0
    }

    public func clipTriangles(vertices: UnsafeMutablePointer<Float>?, triangles: OpaquePointer?, trianglesLength: size_t, uvs: UnsafeMutablePointer<Float>?, stride: size_t) -> Bool {
        return spine_skeleton_clipping_clip_triangles_2(wrappee, vertices, triangles, trianglesLength, uvs, stride) != 0
    }

    public func clipTriangles(vertices: ArrayFloat, triangles: ArrayUnsignedShort, uvs: ArrayFloat, stride: size_t) -> Bool {
        return spine_skeleton_clipping_clip_triangles_3(wrappee, vertices, triangles, uvs, stride) != 0
    }

    public func isClipping() -> Bool {
        return spine_skeleton_clipping_is_clipping(wrappee) != 0
    }

    public func getClippedVertices() -> ArrayFloat {
        return spine_skeleton_clipping_get_clipped_vertices(wrappee)
    }

    public func getClippedTriangles() -> ArrayUnsignedShort {
        return spine_skeleton_clipping_get_clipped_triangles(wrappee)
    }

    public func getClippedUVs() -> ArrayFloat {
        return spine_skeleton_clipping_get_clipped_u_vs(wrappee)
    }

    deinit {
        spine_skeleton_clipping_dispose(wrappee)
    }
}