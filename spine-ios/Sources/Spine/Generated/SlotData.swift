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

@objc(SpineSlotData)
@objcMembers
public final class SlotData: PosedData {
    internal let wrappee: spine_slot_data

    internal init(_ wrappee: spine_slot_data) {
        self.wrappee = wrappee
        super.init(wrappee)
    }

    public convenience init(index: Int32, name: String?, boneData: BoneData) {
        let ptr = spine_slot_data_create(index, name, boneData.wrappee)
        self.init(ptr)
    }

    public func getIndex() -> Int32 {
        return spine_slot_data_get_index(wrappee)
    }

    public func getBoneData() -> BoneData {
        let result = spine_slot_data_get_bone_data(wrappee)
        return BoneData(result)
    }

    public func setAttachmentName(attachmentName: String?) {
        spine_slot_data_set_attachment_name(wrappee, attachmentName?.cString(using: .utf8))
    }

    public func getAttachmentName() -> String? {
        let result = spine_slot_data_get_attachment_name(wrappee)
        return result != nil ? String(cString: result!) : nil
    }

    public func getBlendMode() -> BlendMode {
        return spine_slot_data_get_blend_mode(wrappee)
    }

    public func setBlendMode(blendMode: BlendMode) {
        spine_slot_data_set_blend_mode(wrappee, blendMode)
    }

    public func getVisible() -> Bool {
        return spine_slot_data_get_visible(wrappee) != 0
    }

    public func setVisible(visible: Bool) {
        spine_slot_data_set_visible(wrappee, visible ? 1 : 0)
    }

    public func getSetupPose() -> SlotPose {
        let result = spine_slot_data_get_setup_pose(wrappee)
        return SlotPose(result)
    }

    public func getName() -> String? {
        let result = spine_slot_data_get_name(wrappee)
        return result != nil ? String(cString: result!) : nil
    }

    public func getSkinRequired() -> Bool {
        return spine_slot_data_get_skin_required(wrappee) != 0
    }

    public func setSkinRequired(skinRequired: Bool) {
        spine_slot_data_set_skin_required(wrappee, skinRequired ? 1 : 0)
    }

    deinit {
        spine_slot_data_dispose(wrappee)
    }
}