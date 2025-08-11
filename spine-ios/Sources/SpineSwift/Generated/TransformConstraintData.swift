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

@objc(SpineTransformConstraintData)
@objcMembers
public final class TransformConstraintData: PosedData {
    internal let wrappee: spine_transform_constraint_data

    internal init(_ wrappee: spine_transform_constraint_data) {
        self.wrappee = wrappee
        super.init(wrappee)
    }

    public convenience init(name: String?) {
        let ptr = spine_transform_constraint_data_create(name)
        self.init(ptr)
    }

    public func getRtti() -> Rtti {
        let result = spine_transform_constraint_data_get_rtti(wrappee)
        return Rtti(result)
    }

    public func createMethod(skeleton: Skeleton) -> Constraint {
        let result = spine_transform_constraint_data_create_method(wrappee, skeleton.wrappee)
        return Constraint(result)
    }

    public func getBones() -> ArrayBoneData {
        return spine_transform_constraint_data_get_bones(wrappee)
    }

    public func getSource() -> BoneData {
        let result = spine_transform_constraint_data_get_source(wrappee)
        return BoneData(result)
    }

    public func setSource(source: BoneData) {
        spine_transform_constraint_data_set_source(wrappee, source.wrappee)
    }

    public func getOffsetRotation() -> Float {
        return spine_transform_constraint_data_get_offset_rotation(wrappee)
    }

    public func setOffsetRotation(offsetRotation: Float) {
        spine_transform_constraint_data_set_offset_rotation(wrappee, offsetRotation)
    }

    public func getOffsetX() -> Float {
        return spine_transform_constraint_data_get_offset_x(wrappee)
    }

    public func setOffsetX(offsetX: Float) {
        spine_transform_constraint_data_set_offset_x(wrappee, offsetX)
    }

    public func getOffsetY() -> Float {
        return spine_transform_constraint_data_get_offset_y(wrappee)
    }

    public func setOffsetY(offsetY: Float) {
        spine_transform_constraint_data_set_offset_y(wrappee, offsetY)
    }

    public func getOffsetScaleX() -> Float {
        return spine_transform_constraint_data_get_offset_scale_x(wrappee)
    }

    public func setOffsetScaleX(offsetScaleX: Float) {
        spine_transform_constraint_data_set_offset_scale_x(wrappee, offsetScaleX)
    }

    public func getOffsetScaleY() -> Float {
        return spine_transform_constraint_data_get_offset_scale_y(wrappee)
    }

    public func setOffsetScaleY(offsetScaleY: Float) {
        spine_transform_constraint_data_set_offset_scale_y(wrappee, offsetScaleY)
    }

    public func getOffsetShearY() -> Float {
        return spine_transform_constraint_data_get_offset_shear_y(wrappee)
    }

    public func setOffsetShearY(offsetShearY: Float) {
        spine_transform_constraint_data_set_offset_shear_y(wrappee, offsetShearY)
    }

    public func getLocalSource() -> Bool {
        return spine_transform_constraint_data_get_local_source(wrappee) != 0
    }

    public func setLocalSource(localSource: Bool) {
        spine_transform_constraint_data_set_local_source(wrappee, localSource ? 1 : 0)
    }

    public func getLocalTarget() -> Bool {
        return spine_transform_constraint_data_get_local_target(wrappee) != 0
    }

    public func setLocalTarget(localTarget: Bool) {
        spine_transform_constraint_data_set_local_target(wrappee, localTarget ? 1 : 0)
    }

    public func getAdditive() -> Bool {
        return spine_transform_constraint_data_get_additive(wrappee) != 0
    }

    public func setAdditive(additive: Bool) {
        spine_transform_constraint_data_set_additive(wrappee, additive ? 1 : 0)
    }

    public func getClamp() -> Bool {
        return spine_transform_constraint_data_get_clamp(wrappee) != 0
    }

    public func setClamp(clamp: Bool) {
        spine_transform_constraint_data_set_clamp(wrappee, clamp ? 1 : 0)
    }

    public func getProperties() -> ArrayFromProperty {
        return spine_transform_constraint_data_get_properties(wrappee)
    }

    public func getName() -> String? {
        let result = spine_transform_constraint_data_get_name(wrappee)
        return result != nil ? String(cString: result!) : nil
    }

    public func getSkinRequired() -> Bool {
        return spine_transform_constraint_data_get_skin_required(wrappee) != 0
    }

    public func getSetupPose() -> TransformConstraintPose {
        let result = spine_transform_constraint_data_get_setup_pose(wrappee)
        return TransformConstraintPose(result)
    }

    public func setSkinRequired(skinRequired: Bool) {
        spine_transform_constraint_data_set_skin_required(wrappee, skinRequired ? 1 : 0)
    }

    public func rtti() -> Rtti {
        let result = spine_transform_constraint_data_rtti(wrappee)
        return Rtti(result)
    }

    deinit {
        spine_transform_constraint_data_dispose(wrappee)
    }
}