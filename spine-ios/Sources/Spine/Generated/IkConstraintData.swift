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

@objc(SpineIkConstraintData)
@objcMembers
public final class IkConstraintData: PosedData, ConstraintData {
    internal let wrappee: spine_ik_constraint_data

    internal init(_ wrappee: spine_ik_constraint_data) {
        self.wrappee = wrappee
        super.init(wrappee)
    }

    public convenience init(name: String?) {
        let ptr = spine_ik_constraint_data_create(name)
        self.init(ptr)
    }

    public func getRtti() -> Rtti {
        let result = spine_ik_constraint_data_get_rtti(wrappee)
        return Rtti(result)
    }

    public func createMethod(skeleton: Skeleton) -> Constraint {
        let result = spine_ik_constraint_data_create_method(wrappee, skeleton.wrappee)
        return Constraint(result)
    }

    public func getBones() -> ArrayBoneData {
        return spine_ik_constraint_data_get_bones(wrappee)
    }

    public func getTarget() -> BoneData {
        let result = spine_ik_constraint_data_get_target(wrappee)
        return BoneData(result)
    }

    public func setTarget(inValue: BoneData) {
        spine_ik_constraint_data_set_target(wrappee, inValue.wrappee)
    }

    public func getUniform() -> Bool {
        return spine_ik_constraint_data_get_uniform(wrappee) != 0
    }

    public func setUniform(uniform: Bool) {
        spine_ik_constraint_data_set_uniform(wrappee, uniform ? 1 : 0)
    }

    public func getName() -> String? {
        let result = spine_ik_constraint_data_get_name(wrappee)
        return result != nil ? String(cString: result!) : nil
    }

    public func getSkinRequired() -> Bool {
        return spine_ik_constraint_data_get_skin_required(wrappee) != 0
    }

    public func getSetupPose() -> IkConstraintPose {
        let result = spine_ik_constraint_data_get_setup_pose(wrappee)
        return IkConstraintPose(result)
    }

    public func setSkinRequired(skinRequired: Bool) {
        spine_ik_constraint_data_set_skin_required(wrappee, skinRequired ? 1 : 0)
    }

    public func rtti() -> Rtti {
        let result = spine_ik_constraint_data_rtti(wrappee)
        return Rtti(result)
    }

    deinit {
        spine_ik_constraint_data_dispose(wrappee)
    }
}