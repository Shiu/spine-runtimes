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

@objc(SpineFromShearY)
@objcMembers
public final class FromShearY: FromProperty {
    internal let wrappee: spine_from_shear_y

    internal init(_ wrappee: spine_from_shear_y) {
        self.wrappee = wrappee
        super.init(wrappee)
    }

    public convenience init() {
        let ptr = spine_from_shear_y_create()
        self.init(ptr)
    }

    public func getRtti() -> Rtti {
        let result = spine_from_shear_y_get_rtti(wrappee)
        return Rtti(result)
    }

    public func value(skeleton: Skeleton, source: BonePose, local: Bool, offsets: UnsafeMutablePointer<Float>?) -> Float {
        return spine_from_shear_y_value(wrappee, skeleton.wrappee, source.wrappee, local ? 1 : 0, offsets)
    }

    public func rtti() -> Rtti {
        let result = spine_from_shear_y_rtti(wrappee)
        return Rtti(result)
    }

    deinit {
        spine_from_shear_y_dispose(wrappee)
    }
}