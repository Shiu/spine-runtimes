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

@objc(SpineBoneLocal)
@objcMembers
public final class BoneLocal: NSObject {
    internal let wrappee: spine_bone_local

    internal init(_ wrappee: spine_bone_local) {
        self.wrappee = wrappee
        super.init()
    }

    public override func isEqual(_ object: Any?) -> Bool {
        guard let other = object as? BoneLocal else { return false }
        return self.wrappee == other.wrappee
    }

    public override var hash: Int {
        var hasher = Hasher()
        hasher.combine(self.wrappee)
        return hasher.finalize()
    }

    public convenience init() {
        let ptr = spine_bone_local_create()
        self.init(ptr)
    }

    public func set(pose: BoneLocal) {
        spine_bone_local_set(wrappee, pose.wrappee)
    }

    public func getX() -> Float {
        return spine_bone_local_get_x(wrappee)
    }

    public func setX(x: Float) {
        spine_bone_local_set_x(wrappee, x)
    }

    public func getY() -> Float {
        return spine_bone_local_get_y(wrappee)
    }

    public func setY(y: Float) {
        spine_bone_local_set_y(wrappee, y)
    }

    public func setPosition(x: Float, y: Float) {
        spine_bone_local_set_position(wrappee, x, y)
    }

    public func getRotation() -> Float {
        return spine_bone_local_get_rotation(wrappee)
    }

    public func setRotation(rotation: Float) {
        spine_bone_local_set_rotation(wrappee, rotation)
    }

    public func getScaleX() -> Float {
        return spine_bone_local_get_scale_x(wrappee)
    }

    public func setScaleX(scaleX: Float) {
        spine_bone_local_set_scale_x(wrappee, scaleX)
    }

    public func getScaleY() -> Float {
        return spine_bone_local_get_scale_y(wrappee)
    }

    public func setScaleY(scaleY: Float) {
        spine_bone_local_set_scale_y(wrappee, scaleY)
    }

    public func setScale(scaleX: Float, scaleY: Float) {
        spine_bone_local_set_scale_1(wrappee, scaleX, scaleY)
    }

    public func setScale(scale: Float) {
        spine_bone_local_set_scale_2(wrappee, scale)
    }

    public func getShearX() -> Float {
        return spine_bone_local_get_shear_x(wrappee)
    }

    public func setShearX(shearX: Float) {
        spine_bone_local_set_shear_x(wrappee, shearX)
    }

    public func getShearY() -> Float {
        return spine_bone_local_get_shear_y(wrappee)
    }

    public func setShearY(shearY: Float) {
        spine_bone_local_set_shear_y(wrappee, shearY)
    }

    public func getInherit() -> Inherit {
        return spine_bone_local_get_inherit(wrappee)
    }

    public func setInherit(inherit: Inherit) {
        spine_bone_local_set_inherit(wrappee, inherit)
    }

    deinit {
        spine_bone_local_dispose(wrappee)
    }
}