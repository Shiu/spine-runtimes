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
import SpineC

@objc(SpineColor)
@objcMembers
public final class Color: NSObject {
    internal let wrappee: spine_color

    internal init(_ wrappee: spine_color) {
        self.wrappee = wrappee
        super.init()
    }

    public override func isEqual(_ object: Any?) -> Bool {
        guard let other = object as? Color else { return false }
        return self.wrappee == other.wrappee
    }

    public override var hash: Int {
        var hasher = Hasher()
        hasher.combine(self.wrappee)
        return hasher.finalize()
    }

    public convenience init() {
        let ptr = spine_color_create()
        self.init(ptr)
    }

    public convenience init(r: Float, g: Float, b: Float, a: Float) {
        let ptr = spine_color_create(r, g, b, a)
        self.init(ptr)
    }

    public func set(_r: Float, _g: Float, _b: Float, _a: Float) -> Color {
        let result = spine_color_set_1(wrappee, _r, _g, _b, _a)
        return Color(result)
    }

    public func set(_r: Float, _g: Float, _b: Float) -> Color {
        let result = spine_color_set_2(wrappee, _r, _g, _b)
        return Color(result)
    }

    public func set(other: Color) -> Color {
        let result = spine_color_set_3(wrappee, other.wrappee)
        return Color(result)
    }

    public func add(_r: Float, _g: Float, _b: Float, _a: Float) -> Color {
        let result = spine_color_add_1(wrappee, _r, _g, _b, _a)
        return Color(result)
    }

    public func add(_r: Float, _g: Float, _b: Float) -> Color {
        let result = spine_color_add_2(wrappee, _r, _g, _b)
        return Color(result)
    }

    public func add(other: Color) -> Color {
        let result = spine_color_add_3(wrappee, other.wrappee)
        return Color(result)
    }

    public func clamp() -> Color {
        let result = spine_color_clamp(wrappee)
        return Color(result)
    }

    public func parseHex(value: String?, index: size_t) -> Float {
        return spine_color_parse_hex(wrappee, value?.cString(using: .utf8), index)
    }

    public func rgba8888ToColor(color: Color, value: Int32) {
        spine_color_rgba8888_to_color(wrappee, color.wrappee, value)
    }

    public func rgb888ToColor(color: Color, value: Int32) {
        spine_color_rgb888_to_color(wrappee, color.wrappee, value)
    }

    public func getR() -> Float {
        return spine_color_get_r(wrappee)
    }

    public func setR(value: Float) {
        spine_color_set_r(wrappee, value)
    }

    public func getG() -> Float {
        return spine_color_get_g(wrappee)
    }

    public func setG(value: Float) {
        spine_color_set_g(wrappee, value)
    }

    public func getB() -> Float {
        return spine_color_get_b(wrappee)
    }

    public func setB(value: Float) {
        spine_color_set_b(wrappee, value)
    }

    public func getA() -> Float {
        return spine_color_get_a(wrappee)
    }

    public func setA(value: Float) {
        spine_color_set_a(wrappee, value)
    }

    deinit {
        spine_color_dispose(wrappee)
    }
}