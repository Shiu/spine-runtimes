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

@objc(SpinePhysicsConstraintData)
@objcMembers
public final class PhysicsConstraintData: PosedData, ConstraintData {
    internal let wrappee: spine_physics_constraint_data

    internal init(_ wrappee: spine_physics_constraint_data) {
        self.wrappee = wrappee
        super.init(wrappee)
    }

    public convenience init(name: String?) {
        let ptr = spine_physics_constraint_data_create(name)
        self.init(ptr)
    }

    public func getRtti() -> Rtti {
        let result = spine_physics_constraint_data_get_rtti(wrappee)
        return Rtti(result)
    }

    public func createMethod(skeleton: Skeleton) -> Constraint {
        let result = spine_physics_constraint_data_create_method(wrappee, skeleton.wrappee)
        return Constraint(result)
    }

    public func getBone() -> BoneData {
        let result = spine_physics_constraint_data_get_bone(wrappee)
        return BoneData(result)
    }

    public func setBone(bone: BoneData) {
        spine_physics_constraint_data_set_bone(wrappee, bone.wrappee)
    }

    public func getStep() -> Float {
        return spine_physics_constraint_data_get_step(wrappee)
    }

    public func setStep(step: Float) {
        spine_physics_constraint_data_set_step(wrappee, step)
    }

    public func getX() -> Float {
        return spine_physics_constraint_data_get_x(wrappee)
    }

    public func setX(x: Float) {
        spine_physics_constraint_data_set_x(wrappee, x)
    }

    public func getY() -> Float {
        return spine_physics_constraint_data_get_y(wrappee)
    }

    public func setY(y: Float) {
        spine_physics_constraint_data_set_y(wrappee, y)
    }

    public func getRotate() -> Float {
        return spine_physics_constraint_data_get_rotate(wrappee)
    }

    public func setRotate(rotate: Float) {
        spine_physics_constraint_data_set_rotate(wrappee, rotate)
    }

    public func getScaleX() -> Float {
        return spine_physics_constraint_data_get_scale_x(wrappee)
    }

    public func setScaleX(scaleX: Float) {
        spine_physics_constraint_data_set_scale_x(wrappee, scaleX)
    }

    public func getShearX() -> Float {
        return spine_physics_constraint_data_get_shear_x(wrappee)
    }

    public func setShearX(shearX: Float) {
        spine_physics_constraint_data_set_shear_x(wrappee, shearX)
    }

    public func getLimit() -> Float {
        return spine_physics_constraint_data_get_limit(wrappee)
    }

    public func setLimit(limit: Float) {
        spine_physics_constraint_data_set_limit(wrappee, limit)
    }

    public func getInertiaGlobal() -> Bool {
        return spine_physics_constraint_data_get_inertia_global(wrappee) != 0
    }

    public func setInertiaGlobal(inertiaGlobal: Bool) {
        spine_physics_constraint_data_set_inertia_global(wrappee, inertiaGlobal ? 1 : 0)
    }

    public func getStrengthGlobal() -> Bool {
        return spine_physics_constraint_data_get_strength_global(wrappee) != 0
    }

    public func setStrengthGlobal(strengthGlobal: Bool) {
        spine_physics_constraint_data_set_strength_global(wrappee, strengthGlobal ? 1 : 0)
    }

    public func getDampingGlobal() -> Bool {
        return spine_physics_constraint_data_get_damping_global(wrappee) != 0
    }

    public func setDampingGlobal(dampingGlobal: Bool) {
        spine_physics_constraint_data_set_damping_global(wrappee, dampingGlobal ? 1 : 0)
    }

    public func getMassGlobal() -> Bool {
        return spine_physics_constraint_data_get_mass_global(wrappee) != 0
    }

    public func setMassGlobal(massGlobal: Bool) {
        spine_physics_constraint_data_set_mass_global(wrappee, massGlobal ? 1 : 0)
    }

    public func getWindGlobal() -> Bool {
        return spine_physics_constraint_data_get_wind_global(wrappee) != 0
    }

    public func setWindGlobal(windGlobal: Bool) {
        spine_physics_constraint_data_set_wind_global(wrappee, windGlobal ? 1 : 0)
    }

    public func getGravityGlobal() -> Bool {
        return spine_physics_constraint_data_get_gravity_global(wrappee) != 0
    }

    public func setGravityGlobal(gravityGlobal: Bool) {
        spine_physics_constraint_data_set_gravity_global(wrappee, gravityGlobal ? 1 : 0)
    }

    public func getMixGlobal() -> Bool {
        return spine_physics_constraint_data_get_mix_global(wrappee) != 0
    }

    public func setMixGlobal(mixGlobal: Bool) {
        spine_physics_constraint_data_set_mix_global(wrappee, mixGlobal ? 1 : 0)
    }

    public func getName() -> String? {
        let result = spine_physics_constraint_data_get_name(wrappee)
        return result != nil ? String(cString: result!) : nil
    }

    public func getSkinRequired() -> Bool {
        return spine_physics_constraint_data_get_skin_required(wrappee) != 0
    }

    public func getSetupPose() -> PhysicsConstraintPose {
        let result = spine_physics_constraint_data_get_setup_pose(wrappee)
        return PhysicsConstraintPose(result)
    }

    public func setSkinRequired(skinRequired: Bool) {
        spine_physics_constraint_data_set_skin_required(wrappee, skinRequired ? 1 : 0)
    }

    public func rtti() -> Rtti {
        let result = spine_physics_constraint_data_rtti(wrappee)
        return Rtti(result)
    }

    deinit {
        spine_physics_constraint_data_dispose(wrappee)
    }
}