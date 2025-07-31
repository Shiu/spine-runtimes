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

@objc(SpinePhysicsConstraintPose)
@objcMembers
public final class PhysicsConstraintPose: NSObject {
    internal let wrappee: spine_physics_constraint_pose

    internal init(_ wrappee: spine_physics_constraint_pose) {
        self.wrappee = wrappee
        super.init()
    }

    public override func isEqual(_ object: Any?) -> Bool {
        guard let other = object as? PhysicsConstraintPose else { return false }
        return self.wrappee == other.wrappee
    }

    public override var hash: Int {
        var hasher = Hasher()
        hasher.combine(self.wrappee)
        return hasher.finalize()
    }

    public convenience init() {
        let ptr = spine_physics_constraint_pose_create()
        self.init(ptr)
    }

    public func set(pose: PhysicsConstraintPose) {
        spine_physics_constraint_pose_set(wrappee, pose.wrappee)
    }

    public func getInertia() -> Float {
        return spine_physics_constraint_pose_get_inertia(wrappee)
    }

    public func setInertia(inertia: Float) {
        spine_physics_constraint_pose_set_inertia(wrappee, inertia)
    }

    public func getStrength() -> Float {
        return spine_physics_constraint_pose_get_strength(wrappee)
    }

    public func setStrength(strength: Float) {
        spine_physics_constraint_pose_set_strength(wrappee, strength)
    }

    public func getDamping() -> Float {
        return spine_physics_constraint_pose_get_damping(wrappee)
    }

    public func setDamping(damping: Float) {
        spine_physics_constraint_pose_set_damping(wrappee, damping)
    }

    public func getMassInverse() -> Float {
        return spine_physics_constraint_pose_get_mass_inverse(wrappee)
    }

    public func setMassInverse(massInverse: Float) {
        spine_physics_constraint_pose_set_mass_inverse(wrappee, massInverse)
    }

    public func getWind() -> Float {
        return spine_physics_constraint_pose_get_wind(wrappee)
    }

    public func setWind(wind: Float) {
        spine_physics_constraint_pose_set_wind(wrappee, wind)
    }

    public func getGravity() -> Float {
        return spine_physics_constraint_pose_get_gravity(wrappee)
    }

    public func setGravity(gravity: Float) {
        spine_physics_constraint_pose_set_gravity(wrappee, gravity)
    }

    public func getMix() -> Float {
        return spine_physics_constraint_pose_get_mix(wrappee)
    }

    public func setMix(mix: Float) {
        spine_physics_constraint_pose_set_mix(wrappee, mix)
    }

    deinit {
        spine_physics_constraint_pose_dispose(wrappee)
    }
}