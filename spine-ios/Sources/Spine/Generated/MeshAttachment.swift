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

@objc(SpineMeshAttachment)
@objcMembers
public final class MeshAttachment: VertexAttachment {
    internal let wrappee: spine_mesh_attachment

    internal init(_ wrappee: spine_mesh_attachment) {
        self.wrappee = wrappee
        super.init(wrappee)
    }

    public convenience init(name: String?) {
        let ptr = spine_mesh_attachment_create(name)
        self.init(ptr)
    }

    public func getRtti() -> Rtti {
        let result = spine_mesh_attachment_get_rtti(wrappee)
        return Rtti(result)
    }

    public func computeWorldVertices(skeleton: Skeleton, slot: Slot, start: size_t, count: size_t, worldVertices: UnsafeMutablePointer<Float>?, offset: size_t, stride: size_t) {
        spine_mesh_attachment_compute_world_vertices_1(wrappee, skeleton.wrappee, slot.wrappee, start, count, worldVertices, offset, stride)
    }

    public func computeWorldVertices(skeleton: Skeleton, slot: Slot, start: size_t, count: size_t, worldVertices: ArrayFloat, offset: size_t, stride: size_t) {
        spine_mesh_attachment_compute_world_vertices_2(wrappee, skeleton.wrappee, slot.wrappee, start, count, worldVertices, offset, stride)
    }

    public func updateRegion() {
        spine_mesh_attachment_update_region(wrappee)
    }

    public func getHullLength() -> Int32 {
        return spine_mesh_attachment_get_hull_length(wrappee)
    }

    public func setHullLength(inValue: Int32) {
        spine_mesh_attachment_set_hull_length(wrappee, inValue)
    }

    public func getRegionUVs() -> ArrayFloat {
        return spine_mesh_attachment_get_region_u_vs(wrappee)
    }

    public func setRegionUVs(inValue: ArrayFloat) {
        spine_mesh_attachment_set_region_u_vs(wrappee, inValue)
    }

    public func getUVs() -> ArrayFloat {
        return spine_mesh_attachment_get_u_vs(wrappee)
    }

    public func getTriangles() -> ArrayUnsignedShort {
        return spine_mesh_attachment_get_triangles(wrappee)
    }

    public func setTriangles(inValue: ArrayUnsignedShort) {
        spine_mesh_attachment_set_triangles(wrappee, inValue)
    }

    public func getColor() -> Color {
        let result = spine_mesh_attachment_get_color(wrappee)
        return Color(result)
    }

    public func getPath() -> String? {
        let result = spine_mesh_attachment_get_path(wrappee)
        return result != nil ? String(cString: result!) : nil
    }

    public func setPath(inValue: String?) {
        spine_mesh_attachment_set_path(wrappee, inValue?.cString(using: .utf8))
    }

    public func getRegion() -> TextureRegion {
        let result = spine_mesh_attachment_get_region(wrappee)
        return TextureRegion(result)
    }

    public func setRegion(region: TextureRegion) {
        spine_mesh_attachment_set_region(wrappee, region.wrappee)
    }

    public func getSequence() -> Sequence {
        let result = spine_mesh_attachment_get_sequence(wrappee)
        return Sequence(result)
    }

    public func setSequence(sequence: Sequence) {
        spine_mesh_attachment_set_sequence(wrappee, sequence.wrappee)
    }

    public func getParentMesh() -> MeshAttachment {
        let result = spine_mesh_attachment_get_parent_mesh(wrappee)
        return MeshAttachment(result)
    }

    public func setParentMesh(inValue: MeshAttachment) {
        spine_mesh_attachment_set_parent_mesh(wrappee, inValue.wrappee)
    }

    public func getEdges() -> ArrayUnsignedShort {
        return spine_mesh_attachment_get_edges(wrappee)
    }

    public func setEdges(inValue: ArrayUnsignedShort) {
        spine_mesh_attachment_set_edges(wrappee, inValue)
    }

    public func getWidth() -> Float {
        return spine_mesh_attachment_get_width(wrappee)
    }

    public func setWidth(inValue: Float) {
        spine_mesh_attachment_set_width(wrappee, inValue)
    }

    public func getHeight() -> Float {
        return spine_mesh_attachment_get_height(wrappee)
    }

    public func setHeight(inValue: Float) {
        spine_mesh_attachment_set_height(wrappee, inValue)
    }

    public func copy() -> Attachment {
        let result = spine_mesh_attachment_copy(wrappee)
        return Attachment(result)
    }

    public func newLinkedMesh() -> MeshAttachment {
        let result = spine_mesh_attachment_new_linked_mesh(wrappee)
        return MeshAttachment(result)
    }

    public func getId() -> Int32 {
        return spine_mesh_attachment_get_id(wrappee)
    }

    public func getBones() -> ArrayInt {
        return spine_mesh_attachment_get_bones(wrappee)
    }

    public func setBones(bones: ArrayInt) {
        spine_mesh_attachment_set_bones(wrappee, bones)
    }

    public func getVertices() -> ArrayFloat {
        return spine_mesh_attachment_get_vertices(wrappee)
    }

    public func setVertices(vertices: ArrayFloat) {
        spine_mesh_attachment_set_vertices(wrappee, vertices)
    }

    public func getWorldVerticesLength() -> size_t {
        return spine_mesh_attachment_get_world_vertices_length(wrappee)
    }

    public func setWorldVerticesLength(inValue: size_t) {
        spine_mesh_attachment_set_world_vertices_length(wrappee, inValue)
    }

    public func getTimelineAttachment() -> Attachment {
        let result = spine_mesh_attachment_get_timeline_attachment(wrappee)
        return Attachment(result)
    }

    public func setTimelineAttachment(attachment: Attachment) {
        spine_mesh_attachment_set_timeline_attachment(wrappee, attachment.wrappee)
    }

    public func copyTo(other: VertexAttachment) {
        spine_mesh_attachment_copy_to(wrappee, other.wrappee)
    }

    public func getName() -> String? {
        let result = spine_mesh_attachment_get_name(wrappee)
        return result != nil ? String(cString: result!) : nil
    }

    public func getRefCount() -> Int32 {
        return spine_mesh_attachment_get_ref_count(wrappee)
    }

    public func reference() {
        spine_mesh_attachment_reference(wrappee)
    }

    public func dereference() {
        spine_mesh_attachment_dereference(wrappee)
    }

    public func rtti() -> Rtti {
        let result = spine_mesh_attachment_rtti(wrappee)
        return Rtti(result)
    }

    deinit {
        spine_mesh_attachment_dispose(wrappee)
    }
}