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

@objc(SpinePathConstraintData)
@objcMembers
public final class PathConstraintData: PosedData, ConstraintData {
    internal let wrappee: spine_path_constraint_data

    internal init(_ wrappee: spine_path_constraint_data) {
        self.wrappee = wrappee
        super.init(wrappee)
    }

    public convenience init(name: String?) {
        let ptr = spine_path_constraint_data_create(name)
        self.init(ptr)
    }

    public func getRtti() -> Rtti {
        let result = spine_path_constraint_data_get_rtti(wrappee)
        return Rtti(result)
    }

    public func createMethod(skeleton: Skeleton) -> Constraint {
        let result = spine_path_constraint_data_create_method(wrappee, skeleton.wrappee)
        return Constraint(result)
    }

    public func getBones() -> ArrayBoneData {
        return spine_path_constraint_data_get_bones(wrappee)
    }

    public func getSlot() -> SlotData {
        let result = spine_path_constraint_data_get_slot(wrappee)
        return SlotData(result)
    }

    public func setSlot(slot: SlotData) {
        spine_path_constraint_data_set_slot(wrappee, slot.wrappee)
    }

    public func getPositionMode() -> PositionMode {
        return spine_path_constraint_data_get_position_mode(wrappee)
    }

    public func setPositionMode(positionMode: PositionMode) {
        spine_path_constraint_data_set_position_mode(wrappee, positionMode)
    }

    public func getSpacingMode() -> SpacingMode {
        return spine_path_constraint_data_get_spacing_mode(wrappee)
    }

    public func setSpacingMode(spacingMode: SpacingMode) {
        spine_path_constraint_data_set_spacing_mode(wrappee, spacingMode)
    }

    public func getRotateMode() -> RotateMode {
        return spine_path_constraint_data_get_rotate_mode(wrappee)
    }

    public func setRotateMode(rotateMode: RotateMode) {
        spine_path_constraint_data_set_rotate_mode(wrappee, rotateMode)
    }

    public func getOffsetRotation() -> Float {
        return spine_path_constraint_data_get_offset_rotation(wrappee)
    }

    public func setOffsetRotation(offsetRotation: Float) {
        spine_path_constraint_data_set_offset_rotation(wrappee, offsetRotation)
    }

    public func getName() -> String? {
        let result = spine_path_constraint_data_get_name(wrappee)
        return result != nil ? String(cString: result!) : nil
    }

    public func getSkinRequired() -> Bool {
        return spine_path_constraint_data_get_skin_required(wrappee) != 0
    }

    public func getSetupPose() -> PathConstraintPose {
        let result = spine_path_constraint_data_get_setup_pose(wrappee)
        return PathConstraintPose(result)
    }

    public func setSkinRequired(skinRequired: Bool) {
        spine_path_constraint_data_set_skin_required(wrappee, skinRequired ? 1 : 0)
    }

    public func rtti() -> Rtti {
        let result = spine_path_constraint_data_rtti(wrappee)
        return Rtti(result)
    }

    deinit {
        spine_path_constraint_data_dispose(wrappee)
    }
}