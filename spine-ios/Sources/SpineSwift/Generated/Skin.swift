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

@objc(SpineSkin)
@objcMembers
public final class Skin: NSObject {
    internal let wrappee: spine_skin

    internal init(_ wrappee: spine_skin) {
        self.wrappee = wrappee
        super.init()
    }

    public override func isEqual(_ object: Any?) -> Bool {
        guard let other = object as? Skin else { return false }
        return self.wrappee == other.wrappee
    }

    public override var hash: Int {
        var hasher = Hasher()
        hasher.combine(self.wrappee)
        return hasher.finalize()
    }

    public convenience init(name: String?) {
        let ptr = spine_skin_create(name)
        self.init(ptr)
    }

    public func setAttachment(slotIndex: size_t, name: String?, attachment: Attachment) {
        spine_skin_set_attachment(wrappee, slotIndex, name?.cString(using: .utf8), attachment.wrappee)
    }

    public func getAttachment(slotIndex: size_t, name: String?) -> Attachment {
        let result = spine_skin_get_attachment(wrappee, slotIndex, name?.cString(using: .utf8))
        return Attachment(result)
    }

    public func removeAttachment(slotIndex: size_t, name: String?) {
        spine_skin_remove_attachment(wrappee, slotIndex, name?.cString(using: .utf8))
    }

    public func findAttachmentsForSlot(slotIndex: size_t, attachments: ArrayAttachment) {
        spine_skin_find_attachments_for_slot(wrappee, slotIndex, attachments)
    }

    public func getName() -> String? {
        let result = spine_skin_get_name(wrappee)
        return result != nil ? String(cString: result!) : nil
    }

    public func addSkin(other: Skin) {
        spine_skin_add_skin(wrappee, other.wrappee)
    }

    public func copySkin(other: Skin) {
        spine_skin_copy_skin(wrappee, other.wrappee)
    }

    public func getBones() -> ArrayBoneData {
        return spine_skin_get_bones(wrappee)
    }

    public func getConstraints() -> ArrayConstraintData {
        return spine_skin_get_constraints(wrappee)
    }

    public func getColor() -> Color {
        let result = spine_skin_get_color(wrappee)
        return Color(result)
    }

    deinit {
        spine_skin_dispose(wrappee)
    }
}