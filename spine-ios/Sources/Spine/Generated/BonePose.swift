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

@objc(SpineBonePose)
@objcMembers
public final class BonePose: BoneLocal, Update {
    internal let wrappee: spine_bone_pose

    internal init(_ wrappee: spine_bone_pose) {
        self.wrappee = wrappee
        super.init(wrappee)
    }

    public convenience init() {
        let ptr = spine_bone_pose_create()
        self.init(ptr)
    }

    public func getRtti() -> Rtti {
        let result = spine_bone_pose_get_rtti(wrappee)
        return Rtti(result)
    }

    public func update(skeleton: Skeleton, physics: Physics) {
        spine_bone_pose_update(wrappee, skeleton.wrappee, physics)
    }

    public func updateWorldTransform(skeleton: Skeleton) {
        spine_bone_pose_update_world_transform(wrappee, skeleton.wrappee)
    }

    public func updateLocalTransform(skeleton: Skeleton) {
        spine_bone_pose_update_local_transform(wrappee, skeleton.wrappee)
    }

    public func validateLocalTransform(skeleton: Skeleton) {
        spine_bone_pose_validate_local_transform(wrappee, skeleton.wrappee)
    }

    public func modifyLocal(skeleton: Skeleton) {
        spine_bone_pose_modify_local(wrappee, skeleton.wrappee)
    }

    public func modifyWorld(update: Int32) {
        spine_bone_pose_modify_world(wrappee, update)
    }

    public func resetWorld(update: Int32) {
        spine_bone_pose_reset_world(wrappee, update)
    }

    public func getA() -> Float {
        return spine_bone_pose_get_a(wrappee)
    }

    public func setA(a: Float) {
        spine_bone_pose_set_a(wrappee, a)
    }

    public func getB() -> Float {
        return spine_bone_pose_get_b(wrappee)
    }

    public func setB(b: Float) {
        spine_bone_pose_set_b(wrappee, b)
    }

    public func getC() -> Float {
        return spine_bone_pose_get_c(wrappee)
    }

    public func setC(c: Float) {
        spine_bone_pose_set_c(wrappee, c)
    }

    public func getD() -> Float {
        return spine_bone_pose_get_d(wrappee)
    }

    public func setD(d: Float) {
        spine_bone_pose_set_d(wrappee, d)
    }

    public func getWorldX() -> Float {
        return spine_bone_pose_get_world_x(wrappee)
    }

    public func setWorldX(worldX: Float) {
        spine_bone_pose_set_world_x(wrappee, worldX)
    }

    public func getWorldY() -> Float {
        return spine_bone_pose_get_world_y(wrappee)
    }

    public func setWorldY(worldY: Float) {
        spine_bone_pose_set_world_y(wrappee, worldY)
    }

    public func getWorldRotationX() -> Float {
        return spine_bone_pose_get_world_rotation_x(wrappee)
    }

    public func getWorldRotationY() -> Float {
        return spine_bone_pose_get_world_rotation_y(wrappee)
    }

    public func getWorldScaleX() -> Float {
        return spine_bone_pose_get_world_scale_x(wrappee)
    }

    public func getWorldScaleY() -> Float {
        return spine_bone_pose_get_world_scale_y(wrappee)
    }

    public func worldToLocal(worldX: Float, worldY: Float, outLocalX: UnsafeMutablePointer<Float>?, outLocalY: UnsafeMutablePointer<Float>?) {
        spine_bone_pose_world_to_local(wrappee, worldX, worldY, outLocalX, outLocalY)
    }

    public func localToWorld(localX: Float, localY: Float, outWorldX: UnsafeMutablePointer<Float>?, outWorldY: UnsafeMutablePointer<Float>?) {
        spine_bone_pose_local_to_world(wrappee, localX, localY, outWorldX, outWorldY)
    }

    public func worldToParent(worldX: Float, worldY: Float, outParentX: UnsafeMutablePointer<Float>?, outParentY: UnsafeMutablePointer<Float>?) {
        spine_bone_pose_world_to_parent(wrappee, worldX, worldY, outParentX, outParentY)
    }

    public func parentToWorld(parentX: Float, parentY: Float, outWorldX: UnsafeMutablePointer<Float>?, outWorldY: UnsafeMutablePointer<Float>?) {
        spine_bone_pose_parent_to_world(wrappee, parentX, parentY, outWorldX, outWorldY)
    }

    public func worldToLocalRotation(worldRotation: Float) -> Float {
        return spine_bone_pose_world_to_local_rotation(wrappee, worldRotation)
    }

    public func localToWorldRotation(localRotation: Float) -> Float {
        return spine_bone_pose_local_to_world_rotation(wrappee, localRotation)
    }

    public func rotateWorld(degrees: Float) {
        spine_bone_pose_rotate_world(wrappee, degrees)
    }

    public func set(pose: BoneLocal) {
        spine_bone_pose_set(wrappee, pose.wrappee)
    }

    public func getX() -> Float {
        return spine_bone_pose_get_x(wrappee)
    }

    public func setX(x: Float) {
        spine_bone_pose_set_x(wrappee, x)
    }

    public func getY() -> Float {
        return spine_bone_pose_get_y(wrappee)
    }

    public func setY(y: Float) {
        spine_bone_pose_set_y(wrappee, y)
    }

    public func setPosition(x: Float, y: Float) {
        spine_bone_pose_set_position(wrappee, x, y)
    }

    public func getRotation() -> Float {
        return spine_bone_pose_get_rotation(wrappee)
    }

    public func setRotation(rotation: Float) {
        spine_bone_pose_set_rotation(wrappee, rotation)
    }

    public func getScaleX() -> Float {
        return spine_bone_pose_get_scale_x(wrappee)
    }

    public func setScaleX(scaleX: Float) {
        spine_bone_pose_set_scale_x(wrappee, scaleX)
    }

    public func getScaleY() -> Float {
        return spine_bone_pose_get_scale_y(wrappee)
    }

    public func setScaleY(scaleY: Float) {
        spine_bone_pose_set_scale_y(wrappee, scaleY)
    }

    public func setScale(scaleX: Float, scaleY: Float) {
        spine_bone_pose_set_scale_1(wrappee, scaleX, scaleY)
    }

    public func setScale(scale: Float) {
        spine_bone_pose_set_scale_2(wrappee, scale)
    }

    public func getShearX() -> Float {
        return spine_bone_pose_get_shear_x(wrappee)
    }

    public func setShearX(shearX: Float) {
        spine_bone_pose_set_shear_x(wrappee, shearX)
    }

    public func getShearY() -> Float {
        return spine_bone_pose_get_shear_y(wrappee)
    }

    public func setShearY(shearY: Float) {
        spine_bone_pose_set_shear_y(wrappee, shearY)
    }

    public func getInherit() -> Inherit {
        return spine_bone_pose_get_inherit(wrappee)
    }

    public func setInherit(inherit: Inherit) {
        spine_bone_pose_set_inherit(wrappee, inherit)
    }

    public func rtti() -> Rtti {
        let result = spine_bone_pose_rtti(wrappee)
        return Rtti(result)
    }

    deinit {
        spine_bone_pose_dispose(wrappee)
    }
}