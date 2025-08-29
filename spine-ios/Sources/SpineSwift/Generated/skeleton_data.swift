//
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

// AUTO GENERATED FILE, DO NOT EDIT.

import Foundation
import SpineC

/// SkeletonData wrapper
@objc(SpineSkeletonData)
@objcMembers
public class SkeletonData: NSObject {
    public let _ptr: UnsafeMutableRawPointer

    public init(fromPointer ptr: spine_skeleton_data) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        super.init()
    }

    public override convenience init() {
        let ptr = spine_skeleton_data_create()
        self.init(fromPointer: ptr!)
    }

    public var name: String {
        get {
            let result = spine_skeleton_data_get_name(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self))
        return String(cString: result!)
        }
        set {
            spine_skeleton_data_set_name(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self), newValue)
        }
    }

    public var bones: ArrayBoneData {
        let result = spine_skeleton_data_get_bones(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self))
        return ArrayBoneData(fromPointer: result!)
    }

    public var slots: ArraySlotData {
        let result = spine_skeleton_data_get_slots(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self))
        return ArraySlotData(fromPointer: result!)
    }

    public var skins: ArraySkin {
        let result = spine_skeleton_data_get_skins(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self))
        return ArraySkin(fromPointer: result!)
    }

    public var defaultSkin: Skin? {
        get {
            let result = spine_skeleton_data_get_default_skin(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self))
        return result.map { Skin(fromPointer: $0) }
        }
        set {
            spine_skeleton_data_set_default_skin(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self), newValue?._ptr.assumingMemoryBound(to: spine_skin_wrapper.self))
        }
    }

    public var events: ArrayEventData {
        let result = spine_skeleton_data_get_events(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self))
        return ArrayEventData(fromPointer: result!)
    }

    public var animations: ArrayAnimation {
        let result = spine_skeleton_data_get_animations(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self))
        return ArrayAnimation(fromPointer: result!)
    }

    public var constraints: ArrayConstraintData {
        let result = spine_skeleton_data_get_constraints(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self))
        return ArrayConstraintData(fromPointer: result!)
    }

    public var x: Float {
        get {
            let result = spine_skeleton_data_get_x(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self))
        return result
        }
        set {
            spine_skeleton_data_set_x(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self), newValue)
        }
    }

    public var y: Float {
        get {
            let result = spine_skeleton_data_get_y(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self))
        return result
        }
        set {
            spine_skeleton_data_set_y(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self), newValue)
        }
    }

    public var width: Float {
        get {
            let result = spine_skeleton_data_get_width(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self))
        return result
        }
        set {
            spine_skeleton_data_set_width(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self), newValue)
        }
    }

    public var height: Float {
        get {
            let result = spine_skeleton_data_get_height(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self))
        return result
        }
        set {
            spine_skeleton_data_set_height(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self), newValue)
        }
    }

    public var referenceScale: Float {
        get {
            let result = spine_skeleton_data_get_reference_scale(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self))
        return result
        }
        set {
            spine_skeleton_data_set_reference_scale(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self), newValue)
        }
    }

    public var version: String {
        get {
            let result = spine_skeleton_data_get_version(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self))
        return String(cString: result!)
        }
        set {
            spine_skeleton_data_set_version(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self), newValue)
        }
    }

    public var hashString: String {
        get {
            let result = spine_skeleton_data_get_hash(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self))
        return String(cString: result!)
        }
        set {
            spine_skeleton_data_set_hash(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self), newValue)
        }
    }

    public var imagesPath: String {
        get {
            let result = spine_skeleton_data_get_images_path(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self))
        return String(cString: result!)
        }
        set {
            spine_skeleton_data_set_images_path(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self), newValue)
        }
    }

    public var audioPath: String {
        get {
            let result = spine_skeleton_data_get_audio_path(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self))
        return String(cString: result!)
        }
        set {
            spine_skeleton_data_set_audio_path(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self), newValue)
        }
    }

    public var fps: Float {
        get {
            let result = spine_skeleton_data_get_fps(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self))
        return result
        }
        set {
            spine_skeleton_data_set_fps(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self), newValue)
        }
    }

    public func findBone(_ boneName: String) -> BoneData? {
        let result = spine_skeleton_data_find_bone(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self), boneName)
        return result.map { BoneData(fromPointer: $0) }
    }

    public func findSlot(_ slotName: String) -> SlotData? {
        let result = spine_skeleton_data_find_slot(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self), slotName)
        return result.map { SlotData(fromPointer: $0) }
    }

    public func findSkin(_ skinName: String) -> Skin? {
        let result = spine_skeleton_data_find_skin(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self), skinName)
        return result.map { Skin(fromPointer: $0) }
    }

    public func findEvent(_ eventDataName: String) -> EventData? {
        let result = spine_skeleton_data_find_event(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self), eventDataName)
        return result.map { EventData(fromPointer: $0) }
    }

    public func findAnimation(_ animationName: String) -> Animation? {
        let result = spine_skeleton_data_find_animation(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self), animationName)
        return result.map { Animation(fromPointer: $0) }
    }

    public func dispose() {
        spine_skeleton_data_dispose(_ptr.assumingMemoryBound(to: spine_skeleton_data_wrapper.self))
    }
}