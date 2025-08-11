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

@objc(SpineSlotPose)
@objcMembers
public final class SlotPose: NSObject {
    internal let wrappee: spine_slot_pose

    internal init(_ wrappee: spine_slot_pose) {
        self.wrappee = wrappee
        super.init()
    }

    public override func isEqual(_ object: Any?) -> Bool {
        guard let other = object as? SlotPose else { return false }
        return self.wrappee == other.wrappee
    }

    public override var hash: Int {
        var hasher = Hasher()
        hasher.combine(self.wrappee)
        return hasher.finalize()
    }

    public convenience init() {
        let ptr = spine_slot_pose_create()
        self.init(ptr)
    }

    public func set(pose: SlotPose) {
        spine_slot_pose_set(wrappee, pose.wrappee)
    }

    public func getColor() -> Color {
        let result = spine_slot_pose_get_color(wrappee)
        return Color(result)
    }

    public func getDarkColor() -> Color {
        let result = spine_slot_pose_get_dark_color(wrappee)
        return Color(result)
    }

    public func hasDarkColor() -> Bool {
        return spine_slot_pose_has_dark_color(wrappee) != 0
    }

    public func setHasDarkColor(hasDarkColor: Bool) {
        spine_slot_pose_set_has_dark_color(wrappee, hasDarkColor ? 1 : 0)
    }

    public func getAttachment() -> Attachment {
        let result = spine_slot_pose_get_attachment(wrappee)
        return Attachment(result)
    }

    public func setAttachment(attachment: Attachment) {
        spine_slot_pose_set_attachment(wrappee, attachment.wrappee)
    }

    public func getSequenceIndex() -> Int32 {
        return spine_slot_pose_get_sequence_index(wrappee)
    }

    public func setSequenceIndex(sequenceIndex: Int32) {
        spine_slot_pose_set_sequence_index(wrappee, sequenceIndex)
    }

    public func getDeform() -> ArrayFloat {
        return spine_slot_pose_get_deform(wrappee)
    }

    deinit {
        spine_slot_pose_dispose(wrappee)
    }
}