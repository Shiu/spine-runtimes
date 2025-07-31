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

@objc(SpineRegionAttachment)
@objcMembers
public final class RegionAttachment: Attachment {
    internal let wrappee: spine_region_attachment

    internal init(_ wrappee: spine_region_attachment) {
        self.wrappee = wrappee
        super.init(wrappee)
    }

    public convenience init(name: String?) {
        let ptr = spine_region_attachment_create(name)
        self.init(ptr)
    }

    public func getRtti() -> Rtti {
        let result = spine_region_attachment_get_rtti(wrappee)
        return Rtti(result)
    }

    public func updateRegion() {
        spine_region_attachment_update_region(wrappee)
    }

    public func computeWorldVertices(slot: Slot, worldVertices: UnsafeMutablePointer<Float>?, offset: size_t, stride: size_t) {
        spine_region_attachment_compute_world_vertices_1(wrappee, slot.wrappee, worldVertices, offset, stride)
    }

    public func computeWorldVertices(slot: Slot, worldVertices: ArrayFloat, offset: size_t, stride: size_t) {
        spine_region_attachment_compute_world_vertices_2(wrappee, slot.wrappee, worldVertices, offset, stride)
    }

    public func getX() -> Float {
        return spine_region_attachment_get_x(wrappee)
    }

    public func setX(inValue: Float) {
        spine_region_attachment_set_x(wrappee, inValue)
    }

    public func getY() -> Float {
        return spine_region_attachment_get_y(wrappee)
    }

    public func setY(inValue: Float) {
        spine_region_attachment_set_y(wrappee, inValue)
    }

    public func getRotation() -> Float {
        return spine_region_attachment_get_rotation(wrappee)
    }

    public func setRotation(inValue: Float) {
        spine_region_attachment_set_rotation(wrappee, inValue)
    }

    public func getScaleX() -> Float {
        return spine_region_attachment_get_scale_x(wrappee)
    }

    public func setScaleX(inValue: Float) {
        spine_region_attachment_set_scale_x(wrappee, inValue)
    }

    public func getScaleY() -> Float {
        return spine_region_attachment_get_scale_y(wrappee)
    }

    public func setScaleY(inValue: Float) {
        spine_region_attachment_set_scale_y(wrappee, inValue)
    }

    public func getWidth() -> Float {
        return spine_region_attachment_get_width(wrappee)
    }

    public func setWidth(inValue: Float) {
        spine_region_attachment_set_width(wrappee, inValue)
    }

    public func getHeight() -> Float {
        return spine_region_attachment_get_height(wrappee)
    }

    public func setHeight(inValue: Float) {
        spine_region_attachment_set_height(wrappee, inValue)
    }

    public func getColor() -> Color {
        let result = spine_region_attachment_get_color(wrappee)
        return Color(result)
    }

    public func getPath() -> String? {
        let result = spine_region_attachment_get_path(wrappee)
        return result != nil ? String(cString: result!) : nil
    }

    public func setPath(inValue: String?) {
        spine_region_attachment_set_path(wrappee, inValue?.cString(using: .utf8))
    }

    public func getRegion() -> TextureRegion {
        let result = spine_region_attachment_get_region(wrappee)
        return TextureRegion(result)
    }

    public func setRegion(region: TextureRegion) {
        spine_region_attachment_set_region(wrappee, region.wrappee)
    }

    public func getSequence() -> Sequence {
        let result = spine_region_attachment_get_sequence(wrappee)
        return Sequence(result)
    }

    public func setSequence(sequence: Sequence) {
        spine_region_attachment_set_sequence(wrappee, sequence.wrappee)
    }

    public func getOffset() -> ArrayFloat {
        return spine_region_attachment_get_offset(wrappee)
    }

    public func getUVs() -> ArrayFloat {
        return spine_region_attachment_get_u_vs(wrappee)
    }

    public func copy() -> Attachment {
        let result = spine_region_attachment_copy(wrappee)
        return Attachment(result)
    }

    public func getName() -> String? {
        let result = spine_region_attachment_get_name(wrappee)
        return result != nil ? String(cString: result!) : nil
    }

    public func getRefCount() -> Int32 {
        return spine_region_attachment_get_ref_count(wrappee)
    }

    public func reference() {
        spine_region_attachment_reference(wrappee)
    }

    public func dereference() {
        spine_region_attachment_dereference(wrappee)
    }

    public func rtti() -> Rtti {
        let result = spine_region_attachment_rtti(wrappee)
        return Rtti(result)
    }

    deinit {
        spine_region_attachment_dispose(wrappee)
    }
}