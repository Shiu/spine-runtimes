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

@objc(SpinePointAttachment)
@objcMembers
public final class PointAttachment: Attachment {
    internal let wrappee: spine_point_attachment

    internal init(_ wrappee: spine_point_attachment) {
        self.wrappee = wrappee
        super.init(wrappee)
    }

    public convenience init(name: String?) {
        let ptr = spine_point_attachment_create(name)
        self.init(ptr)
    }

    public func getRtti() -> Rtti {
        let result = spine_point_attachment_get_rtti(wrappee)
        return Rtti(result)
    }

    public func getX() -> Float {
        return spine_point_attachment_get_x(wrappee)
    }

    public func setX(inValue: Float) {
        spine_point_attachment_set_x(wrappee, inValue)
    }

    public func getY() -> Float {
        return spine_point_attachment_get_y(wrappee)
    }

    public func setY(inValue: Float) {
        spine_point_attachment_set_y(wrappee, inValue)
    }

    public func getRotation() -> Float {
        return spine_point_attachment_get_rotation(wrappee)
    }

    public func setRotation(inValue: Float) {
        spine_point_attachment_set_rotation(wrappee, inValue)
    }

    public func getColor() -> Color {
        let result = spine_point_attachment_get_color(wrappee)
        return Color(result)
    }

    public func computeWorldPosition(bone: BonePose, ox: UnsafeMutablePointer<Float>?, oy: UnsafeMutablePointer<Float>?) {
        spine_point_attachment_compute_world_position(wrappee, bone.wrappee, ox, oy)
    }

    public func computeWorldRotation(bone: BonePose) -> Float {
        return spine_point_attachment_compute_world_rotation(wrappee, bone.wrappee)
    }

    public func copy() -> Attachment {
        let result = spine_point_attachment_copy(wrappee)
        return Attachment(result)
    }

    public func getName() -> String? {
        let result = spine_point_attachment_get_name(wrappee)
        return result != nil ? String(cString: result!) : nil
    }

    public func getRefCount() -> Int32 {
        return spine_point_attachment_get_ref_count(wrappee)
    }

    public func reference() {
        spine_point_attachment_reference(wrappee)
    }

    public func dereference() {
        spine_point_attachment_dereference(wrappee)
    }

    public func rtti() -> Rtti {
        let result = spine_point_attachment_rtti(wrappee)
        return Rtti(result)
    }

    deinit {
        spine_point_attachment_dispose(wrappee)
    }
}