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

@objc(SpineBone)
@objcMembers
public final class Bone: PosedActive {
    internal let wrappee: spine_bone

    internal init(_ wrappee: spine_bone) {
        self.wrappee = wrappee
        super.init(wrappee)
    }

    public convenience init(data: BoneData, parent: Bone) {
        let ptr = spine_bone_create(data.wrappee, parent.wrappee)
        self.init(ptr)
    }

    public convenience init(bone: Bone, parent: Bone) {
        let ptr = spine_bone_create(bone.wrappee, parent.wrappee)
        self.init(ptr)
    }

    public func getRtti() -> Rtti {
        let result = spine_bone_get_rtti(wrappee)
        return Rtti(result)
    }

    public func getParent() -> Bone {
        let result = spine_bone_get_parent(wrappee)
        return Bone(result)
    }

    public func getChildren() -> ArrayBone {
        return spine_bone_get_children(wrappee)
    }

    public func isYDown() -> Bool {
        return spine_bone_is_y_down(wrappee) != 0
    }

    public func setYDown(value: Bool) {
        spine_bone_set_y_down(wrappee, value ? 1 : 0)
    }

    public func update(skeleton: Skeleton, physics: Physics) {
        spine_bone_update(wrappee, skeleton.wrappee, physics)
    }

    public func getData() -> BoneData {
        let result = spine_bone_get_data(wrappee)
        return BoneData(result)
    }

    public func getPose() -> BoneLocal {
        let result = spine_bone_get_pose(wrappee)
        return BoneLocal(result)
    }

    public func getAppliedPose() -> BonePose {
        let result = spine_bone_get_applied_pose(wrappee)
        return BonePose(result)
    }

    public func resetConstrained() {
        spine_bone_reset_constrained(wrappee)
    }

    public func constrained() {
        spine_bone_constrained(wrappee)
    }

    public func isPoseEqualToApplied() -> Bool {
        return spine_bone_is_pose_equal_to_applied(wrappee) != 0
    }

    public func isActive() -> Bool {
        return spine_bone_is_active(wrappee) != 0
    }

    public func setActive(active: Bool) {
        spine_bone_set_active(wrappee, active ? 1 : 0)
    }

    public func rtti() -> Rtti {
        let result = spine_bone_rtti(wrappee)
        return Rtti(result)
    }

    deinit {
        spine_bone_dispose(wrappee)
    }
}