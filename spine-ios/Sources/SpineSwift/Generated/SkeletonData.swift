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

@objc(SpineSkeletonData)
@objcMembers
public final class SkeletonData: NSObject {
    internal let wrappee: spine_skeleton_data

    internal init(_ wrappee: spine_skeleton_data) {
        self.wrappee = wrappee
        super.init()
    }

    public override func isEqual(_ object: Any?) -> Bool {
        guard let other = object as? SkeletonData else { return false }
        return self.wrappee == other.wrappee
    }

    public override var hash: Int {
        var hasher = Hasher()
        hasher.combine(self.wrappee)
        return hasher.finalize()
    }

    public convenience init() {
        let ptr = spine_skeleton_data_create()
        self.init(ptr)
    }

    public func findBone(boneName: String?) -> BoneData {
        let result = spine_skeleton_data_find_bone(wrappee, boneName?.cString(using: .utf8))
        return BoneData(result)
    }

    public func findSlot(slotName: String?) -> SlotData {
        let result = spine_skeleton_data_find_slot(wrappee, slotName?.cString(using: .utf8))
        return SlotData(result)
    }

    public func findSkin(skinName: String?) -> Skin {
        let result = spine_skeleton_data_find_skin(wrappee, skinName?.cString(using: .utf8))
        return Skin(result)
    }

    public func findEvent(eventDataName: String?) -> EventData {
        let result = spine_skeleton_data_find_event(wrappee, eventDataName?.cString(using: .utf8))
        return EventData(result)
    }

    public func findAnimation(animationName: String?) -> Animation {
        let result = spine_skeleton_data_find_animation(wrappee, animationName?.cString(using: .utf8))
        return Animation(result)
    }

    public func getName() -> String? {
        let result = spine_skeleton_data_get_name(wrappee)
        return result != nil ? String(cString: result!) : nil
    }

    public func setName(inValue: String?) {
        spine_skeleton_data_set_name(wrappee, inValue?.cString(using: .utf8))
    }

    public func getBones() -> ArrayBoneData {
        return spine_skeleton_data_get_bones(wrappee)
    }

    public func getSlots() -> ArraySlotData {
        return spine_skeleton_data_get_slots(wrappee)
    }

    public func getSkins() -> ArraySkin {
        return spine_skeleton_data_get_skins(wrappee)
    }

    public func getDefaultSkin() -> Skin {
        let result = spine_skeleton_data_get_default_skin(wrappee)
        return Skin(result)
    }

    public func setDefaultSkin(inValue: Skin) {
        spine_skeleton_data_set_default_skin(wrappee, inValue.wrappee)
    }

    public func getEvents() -> ArrayEventData {
        return spine_skeleton_data_get_events(wrappee)
    }

    public func getAnimations() -> ArrayAnimation {
        return spine_skeleton_data_get_animations(wrappee)
    }

    public func getConstraints() -> ArrayConstraintData {
        return spine_skeleton_data_get_constraints(wrappee)
    }

    public func getX() -> Float {
        return spine_skeleton_data_get_x(wrappee)
    }

    public func setX(inValue: Float) {
        spine_skeleton_data_set_x(wrappee, inValue)
    }

    public func getY() -> Float {
        return spine_skeleton_data_get_y(wrappee)
    }

    public func setY(inValue: Float) {
        spine_skeleton_data_set_y(wrappee, inValue)
    }

    public func getWidth() -> Float {
        return spine_skeleton_data_get_width(wrappee)
    }

    public func setWidth(inValue: Float) {
        spine_skeleton_data_set_width(wrappee, inValue)
    }

    public func getHeight() -> Float {
        return spine_skeleton_data_get_height(wrappee)
    }

    public func setHeight(inValue: Float) {
        spine_skeleton_data_set_height(wrappee, inValue)
    }

    public func getReferenceScale() -> Float {
        return spine_skeleton_data_get_reference_scale(wrappee)
    }

    public func setReferenceScale(inValue: Float) {
        spine_skeleton_data_set_reference_scale(wrappee, inValue)
    }

    public func getVersion() -> String? {
        let result = spine_skeleton_data_get_version(wrappee)
        return result != nil ? String(cString: result!) : nil
    }

    public func setVersion(inValue: String?) {
        spine_skeleton_data_set_version(wrappee, inValue?.cString(using: .utf8))
    }

    public func getHash() -> String? {
        let result = spine_skeleton_data_get_hash(wrappee)
        return result != nil ? String(cString: result!) : nil
    }

    public func setHash(inValue: String?) {
        spine_skeleton_data_set_hash(wrappee, inValue?.cString(using: .utf8))
    }

    public func getImagesPath() -> String? {
        let result = spine_skeleton_data_get_images_path(wrappee)
        return result != nil ? String(cString: result!) : nil
    }

    public func setImagesPath(inValue: String?) {
        spine_skeleton_data_set_images_path(wrappee, inValue?.cString(using: .utf8))
    }

    public func getAudioPath() -> String? {
        let result = spine_skeleton_data_get_audio_path(wrappee)
        return result != nil ? String(cString: result!) : nil
    }

    public func setAudioPath(inValue: String?) {
        spine_skeleton_data_set_audio_path(wrappee, inValue?.cString(using: .utf8))
    }

    public func getFps() -> Float {
        return spine_skeleton_data_get_fps(wrappee)
    }

    public func setFps(inValue: Float) {
        spine_skeleton_data_set_fps(wrappee, inValue)
    }

    deinit {
        spine_skeleton_data_dispose(wrappee)
    }
}