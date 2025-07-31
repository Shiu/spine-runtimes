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

@objc(SpineTextureRegion)
@objcMembers
public final class TextureRegion: NSObject {
    internal let wrappee: spine_texture_region

    internal init(_ wrappee: spine_texture_region) {
        self.wrappee = wrappee
        super.init()
    }

    public override func isEqual(_ object: Any?) -> Bool {
        guard let other = object as? TextureRegion else { return false }
        return self.wrappee == other.wrappee
    }

    public override var hash: Int {
        var hasher = Hasher()
        hasher.combine(self.wrappee)
        return hasher.finalize()
    }

    public convenience init() {
        let ptr = spine_texture_region_create()
        self.init(ptr)
    }

    public func getRtti() -> Rtti {
        let result = spine_texture_region_get_rtti(wrappee)
        return Rtti(result)
    }

    public func getU() -> Float {
        return spine_texture_region_get_u(wrappee)
    }

    public func setU(value: Float) {
        spine_texture_region_set_u(wrappee, value)
    }

    public func getV() -> Float {
        return spine_texture_region_get_v(wrappee)
    }

    public func setV(value: Float) {
        spine_texture_region_set_v(wrappee, value)
    }

    public func getU2() -> Float {
        return spine_texture_region_get_u2(wrappee)
    }

    public func setU2(value: Float) {
        spine_texture_region_set_u2(wrappee, value)
    }

    public func getV2() -> Float {
        return spine_texture_region_get_v2(wrappee)
    }

    public func setV2(value: Float) {
        spine_texture_region_set_v2(wrappee, value)
    }

    public func getRegionWidth() -> Int32 {
        return spine_texture_region_get_region_width(wrappee)
    }

    public func setRegionWidth(value: Int32) {
        spine_texture_region_set_region_width(wrappee, value)
    }

    public func getRegionHeight() -> Int32 {
        return spine_texture_region_get_region_height(wrappee)
    }

    public func setRegionHeight(value: Int32) {
        spine_texture_region_set_region_height(wrappee, value)
    }

    public func rtti() -> Rtti {
        let result = spine_texture_region_rtti(wrappee)
        return Rtti(result)
    }

    deinit {
        spine_texture_region_dispose(wrappee)
    }
}