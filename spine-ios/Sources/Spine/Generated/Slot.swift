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

@objc(SpineSlot)
@objcMembers
public final class Slot: NSObject, Posed {
    internal let wrappee: spine_slot

    internal init(_ wrappee: spine_slot) {
        self.wrappee = wrappee
        super.init()
    }

    public override func isEqual(_ object: Any?) -> Bool {
        guard let other = object as? Slot else { return false }
        return self.wrappee == other.wrappee
    }

    public override var hash: Int {
        var hasher = Hasher()
        hasher.combine(self.wrappee)
        return hasher.finalize()
    }

    public convenience init(data: SlotData, skeleton: Skeleton) {
        let ptr = spine_slot_create(data.wrappee, skeleton.wrappee)
        self.init(ptr)
    }

    public func getBone() -> Bone {
        let result = spine_slot_get_bone(wrappee)
        return Bone(result)
    }

    public func setupPose() {
        spine_slot_setup_pose(wrappee)
    }

    public func getData() -> SlotData {
        let result = spine_slot_get_data(wrappee)
        return SlotData(result)
    }

    public func getPose() -> SlotPose {
        let result = spine_slot_get_pose(wrappee)
        return SlotPose(result)
    }

    public func getAppliedPose() -> SlotPose {
        let result = spine_slot_get_applied_pose(wrappee)
        return SlotPose(result)
    }

    public func resetConstrained() {
        spine_slot_reset_constrained(wrappee)
    }

    public func constrained() {
        spine_slot_constrained(wrappee)
    }

    public func isPoseEqualToApplied() -> Bool {
        return spine_slot_is_pose_equal_to_applied(wrappee) != 0
    }

    deinit {
        spine_slot_dispose(wrappee)
    }
}