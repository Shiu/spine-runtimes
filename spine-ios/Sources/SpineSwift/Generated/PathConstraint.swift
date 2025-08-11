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

@objc(SpinePathConstraint)
@objcMembers
public final class PathConstraint: PosedActive {
    internal let wrappee: spine_path_constraint

    internal init(_ wrappee: spine_path_constraint) {
        self.wrappee = wrappee
        super.init(wrappee)
    }

    public convenience init(data: PathConstraintData, skeleton: Skeleton) {
        let ptr = spine_path_constraint_create(data.wrappee, skeleton.wrappee)
        self.init(ptr)
    }

    public func getRtti() -> Rtti {
        let result = spine_path_constraint_get_rtti(wrappee)
        return Rtti(result)
    }

    public func copy(skeleton: Skeleton) -> PathConstraint {
        let result = spine_path_constraint_copy(wrappee, skeleton.wrappee)
        return PathConstraint(result)
    }

    public func update(skeleton: Skeleton, physics: Physics) {
        spine_path_constraint_update(wrappee, skeleton.wrappee, physics)
    }

    public func sort(skeleton: Skeleton) {
        spine_path_constraint_sort(wrappee, skeleton.wrappee)
    }

    public func isSourceActive() -> Bool {
        return spine_path_constraint_is_source_active(wrappee) != 0
    }

    public func getBones() -> ArrayBonePose {
        return spine_path_constraint_get_bones(wrappee)
    }

    public func getSlot() -> Slot {
        let result = spine_path_constraint_get_slot(wrappee)
        return Slot(result)
    }

    public func setSlot(slot: Slot) {
        spine_path_constraint_set_slot(wrappee, slot.wrappee)
    }

    public func getData() -> PathConstraintData {
        let result = spine_path_constraint_get_data(wrappee)
        return PathConstraintData(result)
    }

    public func getPose() -> PathConstraintPose {
        let result = spine_path_constraint_get_pose(wrappee)
        return PathConstraintPose(result)
    }

    public func getAppliedPose() -> PathConstraintPose {
        let result = spine_path_constraint_get_applied_pose(wrappee)
        return PathConstraintPose(result)
    }

    public func resetConstrained() {
        spine_path_constraint_reset_constrained(wrappee)
    }

    public func constrained() {
        spine_path_constraint_constrained(wrappee)
    }

    public func isPoseEqualToApplied() -> Bool {
        return spine_path_constraint_is_pose_equal_to_applied(wrappee) != 0
    }

    public func isActive() -> Bool {
        return spine_path_constraint_is_active(wrappee) != 0
    }

    public func setActive(active: Bool) {
        spine_path_constraint_set_active(wrappee, active ? 1 : 0)
    }

    public func rtti() -> Rtti {
        let result = spine_path_constraint_rtti(wrappee)
        return Rtti(result)
    }

    deinit {
        spine_path_constraint_dispose(wrappee)
    }
}