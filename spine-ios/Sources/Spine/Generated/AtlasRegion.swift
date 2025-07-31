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

@objc(SpineAtlasRegion)
@objcMembers
public final class AtlasRegion: TextureRegion {
    internal let wrappee: spine_atlas_region

    internal init(_ wrappee: spine_atlas_region) {
        self.wrappee = wrappee
        super.init(wrappee)
    }

    public convenience init() {
        let ptr = spine_atlas_region_create()
        self.init(ptr)
    }

    public func getRtti() -> Rtti {
        let result = spine_atlas_region_get_rtti(wrappee)
        return Rtti(result)
    }

    public func getPage() -> AtlasPage {
        let result = spine_atlas_region_get_page(wrappee)
        return AtlasPage(result)
    }

    public func getName() -> String? {
        let result = spine_atlas_region_get_name(wrappee)
        return result != nil ? String(cString: result!) : nil
    }

    public func getIndex() -> Int32 {
        return spine_atlas_region_get_index(wrappee)
    }

    public func getX() -> Int32 {
        return spine_atlas_region_get_x(wrappee)
    }

    public func getY() -> Int32 {
        return spine_atlas_region_get_y(wrappee)
    }

    public func getOffsetX() -> Float {
        return spine_atlas_region_get_offset_x(wrappee)
    }

    public func getOffsetY() -> Float {
        return spine_atlas_region_get_offset_y(wrappee)
    }

    public func getPackedWidth() -> Int32 {
        return spine_atlas_region_get_packed_width(wrappee)
    }

    public func getPackedHeight() -> Int32 {
        return spine_atlas_region_get_packed_height(wrappee)
    }

    public func getOriginalWidth() -> Int32 {
        return spine_atlas_region_get_original_width(wrappee)
    }

    public func getOriginalHeight() -> Int32 {
        return spine_atlas_region_get_original_height(wrappee)
    }

    public func getRotate() -> Bool {
        return spine_atlas_region_get_rotate(wrappee) != 0
    }

    public func getDegrees() -> Int32 {
        return spine_atlas_region_get_degrees(wrappee)
    }

    public func getSplits() -> ArrayInt {
        return spine_atlas_region_get_splits(wrappee)
    }

    public func getPads() -> ArrayInt {
        return spine_atlas_region_get_pads(wrappee)
    }

    public func getValues() -> ArrayFloat {
        return spine_atlas_region_get_values(wrappee)
    }

    public func setPage(value: AtlasPage) {
        spine_atlas_region_set_page(wrappee, value.wrappee)
    }

    public func setName(value: String?) {
        spine_atlas_region_set_name(wrappee, value?.cString(using: .utf8))
    }

    public func setIndex(value: Int32) {
        spine_atlas_region_set_index(wrappee, value)
    }

    public func setX(value: Int32) {
        spine_atlas_region_set_x(wrappee, value)
    }

    public func setY(value: Int32) {
        spine_atlas_region_set_y(wrappee, value)
    }

    public func setOffsetX(value: Float) {
        spine_atlas_region_set_offset_x(wrappee, value)
    }

    public func setOffsetY(value: Float) {
        spine_atlas_region_set_offset_y(wrappee, value)
    }

    public func setPackedWidth(value: Int32) {
        spine_atlas_region_set_packed_width(wrappee, value)
    }

    public func setPackedHeight(value: Int32) {
        spine_atlas_region_set_packed_height(wrappee, value)
    }

    public func setOriginalWidth(value: Int32) {
        spine_atlas_region_set_original_width(wrappee, value)
    }

    public func setOriginalHeight(value: Int32) {
        spine_atlas_region_set_original_height(wrappee, value)
    }

    public func setRotate(value: Bool) {
        spine_atlas_region_set_rotate(wrappee, value ? 1 : 0)
    }

    public func setDegrees(value: Int32) {
        spine_atlas_region_set_degrees(wrappee, value)
    }

    public func setSplits(value: ArrayInt) {
        spine_atlas_region_set_splits(wrappee, value)
    }

    public func setPads(value: ArrayInt) {
        spine_atlas_region_set_pads(wrappee, value)
    }

    public func setValues(value: ArrayFloat) {
        spine_atlas_region_set_values(wrappee, value)
    }

    public func getU() -> Float {
        return spine_atlas_region_get_u(wrappee)
    }

    public func setU(value: Float) {
        spine_atlas_region_set_u(wrappee, value)
    }

    public func getV() -> Float {
        return spine_atlas_region_get_v(wrappee)
    }

    public func setV(value: Float) {
        spine_atlas_region_set_v(wrappee, value)
    }

    public func getU2() -> Float {
        return spine_atlas_region_get_u2(wrappee)
    }

    public func setU2(value: Float) {
        spine_atlas_region_set_u2(wrappee, value)
    }

    public func getV2() -> Float {
        return spine_atlas_region_get_v2(wrappee)
    }

    public func setV2(value: Float) {
        spine_atlas_region_set_v2(wrappee, value)
    }

    public func getRegionWidth() -> Int32 {
        return spine_atlas_region_get_region_width(wrappee)
    }

    public func setRegionWidth(value: Int32) {
        spine_atlas_region_set_region_width(wrappee, value)
    }

    public func getRegionHeight() -> Int32 {
        return spine_atlas_region_get_region_height(wrappee)
    }

    public func setRegionHeight(value: Int32) {
        spine_atlas_region_set_region_height(wrappee, value)
    }

    public func rtti() -> Rtti {
        let result = spine_atlas_region_rtti(wrappee)
        return Rtti(result)
    }

    deinit {
        spine_atlas_region_dispose(wrappee)
    }
}