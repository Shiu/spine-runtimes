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

@objc(SpineSkeleton)
@objcMembers
public final class Skeleton: NSObject {
    internal let wrappee: spine_skeleton

    internal init(_ wrappee: spine_skeleton) {
        self.wrappee = wrappee
        super.init()
    }

    public override func isEqual(_ object: Any?) -> Bool {
        guard let other = object as? Skeleton else { return false }
        return self.wrappee == other.wrappee
    }

    public override var hash: Int {
        var hasher = Hasher()
        hasher.combine(self.wrappee)
        return hasher.finalize()
    }

    public convenience init(skeletonData: SkeletonData) {
        let ptr = spine_skeleton_create(skeletonData.wrappee)
        self.init(ptr)
    }

    public func updateCache() {
        spine_skeleton_update_cache(wrappee)
    }

    public func printUpdateCache() {
        spine_skeleton_print_update_cache(wrappee)
    }

    public func constrained(object: Posed) {
        spine_skeleton_constrained(wrappee, object.wrappee)
    }

    public func sortBone(bone: Bone) {
        spine_skeleton_sort_bone(wrappee, bone.wrappee)
    }

    public func sortReset(bones: ArrayBone) {
        spine_skeleton_sort_reset(wrappee, bones)
    }

    public func updateWorldTransform(physics: Physics) {
        spine_skeleton_update_world_transform(wrappee, physics)
    }

    public func setupPose() {
        spine_skeleton_setup_pose(wrappee)
    }

    public func setupPoseBones() {
        spine_skeleton_setup_pose_bones(wrappee)
    }

    public func setupPoseSlots() {
        spine_skeleton_setup_pose_slots(wrappee)
    }

    public func getData() -> SkeletonData {
        let result = spine_skeleton_get_data(wrappee)
        return SkeletonData(result)
    }

    public func getBones() -> ArrayBone {
        return spine_skeleton_get_bones(wrappee)
    }

    public func getUpdateCache() -> ArrayUpdate {
        return spine_skeleton_get_update_cache(wrappee)
    }

    public func getRootBone() -> Bone {
        let result = spine_skeleton_get_root_bone(wrappee)
        return Bone(result)
    }

    public func findBone(boneName: String?) -> Bone {
        let result = spine_skeleton_find_bone(wrappee, boneName?.cString(using: .utf8))
        return Bone(result)
    }

    public func getSlots() -> ArraySlot {
        return spine_skeleton_get_slots(wrappee)
    }

    public func findSlot(slotName: String?) -> Slot {
        let result = spine_skeleton_find_slot(wrappee, slotName?.cString(using: .utf8))
        return Slot(result)
    }

    public func getDrawOrder() -> ArraySlot {
        return spine_skeleton_get_draw_order(wrappee)
    }

    public func getSkin() -> Skin {
        let result = spine_skeleton_get_skin(wrappee)
        return Skin(result)
    }

    public func setSkin(skinName: String?) {
        spine_skeleton_set_skin_1(wrappee, skinName?.cString(using: .utf8))
    }

    public func setSkin(newSkin: Skin) {
        spine_skeleton_set_skin_2(wrappee, newSkin.wrappee)
    }

    public func getAttachment(slotName: String?, attachmentName: String?) -> Attachment {
        let result = spine_skeleton_get_attachment_1(wrappee, slotName?.cString(using: .utf8), attachmentName?.cString(using: .utf8))
        return Attachment(result)
    }

    public func getAttachment(slotIndex: Int32, attachmentName: String?) -> Attachment {
        let result = spine_skeleton_get_attachment_2(wrappee, slotIndex, attachmentName?.cString(using: .utf8))
        return Attachment(result)
    }

    public func setAttachment(slotName: String?, attachmentName: String?) {
        spine_skeleton_set_attachment(wrappee, slotName?.cString(using: .utf8), attachmentName?.cString(using: .utf8))
    }

    public func getConstraints() -> ArrayConstraint {
        return spine_skeleton_get_constraints(wrappee)
    }

    public func getPhysicsConstraints() -> ArrayPhysicsConstraint {
        return spine_skeleton_get_physics_constraints(wrappee)
    }

    public func getBounds(outX: UnsafeMutablePointer<Float>?, outY: UnsafeMutablePointer<Float>?, outWidth: UnsafeMutablePointer<Float>?, outHeight: UnsafeMutablePointer<Float>?) {
        spine_skeleton_get_bounds_1(wrappee, outX, outY, outWidth, outHeight)
    }

    public func getBounds(outX: UnsafeMutablePointer<Float>?, outY: UnsafeMutablePointer<Float>?, outWidth: UnsafeMutablePointer<Float>?, outHeight: UnsafeMutablePointer<Float>?, outVertexBuffer: ArrayFloat, clipping: SkeletonClipping) {
        spine_skeleton_get_bounds_2(wrappee, outX, outY, outWidth, outHeight, outVertexBuffer, clipping.wrappee)
    }

    public func getColor() -> Color {
        let result = spine_skeleton_get_color(wrappee)
        return Color(result)
    }

    public func setColor(color: Color) {
        spine_skeleton_set_color_1(wrappee, color.wrappee)
    }

    public func setColor(r: Float, g: Float, b: Float, a: Float) {
        spine_skeleton_set_color_2(wrappee, r, g, b, a)
    }

    public func getScaleX() -> Float {
        return spine_skeleton_get_scale_x(wrappee)
    }

    public func setScaleX(inValue: Float) {
        spine_skeleton_set_scale_x(wrappee, inValue)
    }

    public func getScaleY() -> Float {
        return spine_skeleton_get_scale_y(wrappee)
    }

    public func setScaleY(inValue: Float) {
        spine_skeleton_set_scale_y(wrappee, inValue)
    }

    public func setScale(scaleX: Float, scaleY: Float) {
        spine_skeleton_set_scale(wrappee, scaleX, scaleY)
    }

    public func getX() -> Float {
        return spine_skeleton_get_x(wrappee)
    }

    public func setX(inValue: Float) {
        spine_skeleton_set_x(wrappee, inValue)
    }

    public func getY() -> Float {
        return spine_skeleton_get_y(wrappee)
    }

    public func setY(inValue: Float) {
        spine_skeleton_set_y(wrappee, inValue)
    }

    public func setPosition(x: Float, y: Float) {
        spine_skeleton_set_position(wrappee, x, y)
    }

    public func getPosition(x: UnsafeMutablePointer<Float>?, y: UnsafeMutablePointer<Float>?) {
        spine_skeleton_get_position(wrappee, x, y)
    }

    public func getWindX() -> Float {
        return spine_skeleton_get_wind_x(wrappee)
    }

    public func setWindX(windX: Float) {
        spine_skeleton_set_wind_x(wrappee, windX)
    }

    public func getWindY() -> Float {
        return spine_skeleton_get_wind_y(wrappee)
    }

    public func setWindY(windY: Float) {
        spine_skeleton_set_wind_y(wrappee, windY)
    }

    public func getGravityX() -> Float {
        return spine_skeleton_get_gravity_x(wrappee)
    }

    public func setGravityX(gravityX: Float) {
        spine_skeleton_set_gravity_x(wrappee, gravityX)
    }

    public func getGravityY() -> Float {
        return spine_skeleton_get_gravity_y(wrappee)
    }

    public func setGravityY(gravityY: Float) {
        spine_skeleton_set_gravity_y(wrappee, gravityY)
    }

    public func physicsTranslate(x: Float, y: Float) {
        spine_skeleton_physics_translate(wrappee, x, y)
    }

    public func physicsRotate(x: Float, y: Float, degrees: Float) {
        spine_skeleton_physics_rotate(wrappee, x, y, degrees)
    }

    public func getTime() -> Float {
        return spine_skeleton_get_time(wrappee)
    }

    public func setTime(time: Float) {
        spine_skeleton_set_time(wrappee, time)
    }

    public func update(delta: Float) {
        spine_skeleton_update(wrappee, delta)
    }

    deinit {
        spine_skeleton_dispose(wrappee)
    }
}