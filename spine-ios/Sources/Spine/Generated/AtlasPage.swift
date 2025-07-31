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

@objc(SpineAtlasPage)
@objcMembers
public final class AtlasPage: NSObject {
    internal let wrappee: spine_atlas_page

    internal init(_ wrappee: spine_atlas_page) {
        self.wrappee = wrappee
        super.init()
    }

    public override func isEqual(_ object: Any?) -> Bool {
        guard let other = object as? AtlasPage else { return false }
        return self.wrappee == other.wrappee
    }

    public override var hash: Int {
        var hasher = Hasher()
        hasher.combine(self.wrappee)
        return hasher.finalize()
    }

    public convenience init(inName: String?) {
        let ptr = spine_atlas_page_create(inName)
        self.init(ptr)
    }

    public func getName() -> String? {
        let result = spine_atlas_page_get_name(wrappee)
        return result != nil ? String(cString: result!) : nil
    }

    public func setName(value: String?) {
        spine_atlas_page_set_name(wrappee, value?.cString(using: .utf8))
    }

    public func getTexturePath() -> String? {
        let result = spine_atlas_page_get_texture_path(wrappee)
        return result != nil ? String(cString: result!) : nil
    }

    public func setTexturePath(value: String?) {
        spine_atlas_page_set_texture_path(wrappee, value?.cString(using: .utf8))
    }

    public func getFormat() -> Format {
        return spine_atlas_page_get_format(wrappee)
    }

    public func setFormat(value: Format) {
        spine_atlas_page_set_format(wrappee, value)
    }

    public func getMinFilter() -> TextureFilter {
        return spine_atlas_page_get_min_filter(wrappee)
    }

    public func setMinFilter(value: TextureFilter) {
        spine_atlas_page_set_min_filter(wrappee, value)
    }

    public func getMagFilter() -> TextureFilter {
        return spine_atlas_page_get_mag_filter(wrappee)
    }

    public func setMagFilter(value: TextureFilter) {
        spine_atlas_page_set_mag_filter(wrappee, value)
    }

    public func getUWrap() -> TextureWrap {
        return spine_atlas_page_get_u_wrap(wrappee)
    }

    public func setUWrap(value: TextureWrap) {
        spine_atlas_page_set_u_wrap(wrappee, value)
    }

    public func getVWrap() -> TextureWrap {
        return spine_atlas_page_get_v_wrap(wrappee)
    }

    public func setVWrap(value: TextureWrap) {
        spine_atlas_page_set_v_wrap(wrappee, value)
    }

    public func getWidth() -> Int32 {
        return spine_atlas_page_get_width(wrappee)
    }

    public func setWidth(value: Int32) {
        spine_atlas_page_set_width(wrappee, value)
    }

    public func getHeight() -> Int32 {
        return spine_atlas_page_get_height(wrappee)
    }

    public func setHeight(value: Int32) {
        spine_atlas_page_set_height(wrappee, value)
    }

    public func getPma() -> Bool {
        return spine_atlas_page_get_pma(wrappee) != 0
    }

    public func setPma(value: Bool) {
        spine_atlas_page_set_pma(wrappee, value ? 1 : 0)
    }

    public func getIndex() -> Int32 {
        return spine_atlas_page_get_index(wrappee)
    }

    public func setIndex(value: Int32) {
        spine_atlas_page_set_index(wrappee, value)
    }

    public func getTexture() -> OpaquePointer? {
        return spine_atlas_page_get_texture(wrappee)
    }

    public func setTexture(value: OpaquePointer?) {
        spine_atlas_page_set_texture(wrappee, value)
    }

    deinit {
        spine_atlas_page_dispose(wrappee)
    }
}