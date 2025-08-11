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

@objc(SpineBoneData)
@objcMembers
public final class BoneData: PosedData {
    internal let wrappee: spine_bone_data

    internal init(_ wrappee: spine_bone_data) {
        self.wrappee = wrappee
        super.init(wrappee)
    }

    public convenience init(index: Int32, name: String?, parent: BoneData) {
        let ptr = spine_bone_data_create(index, name, parent.wrappee)
        self.init(ptr)
    }

    public func getIndex() -> Int32 {
        return spine_bone_data_get_index(wrappee)
    }

    public func getParent() -> BoneData {
        let result = spine_bone_data_get_parent(wrappee)
        return BoneData(result)
    }

    public func getLength() -> Float {
        return spine_bone_data_get_length(wrappee)
    }

    public func setLength(inValue: Float) {
        spine_bone_data_set_length(wrappee, inValue)
    }

    public func getColor() -> Color {
        let result = spine_bone_data_get_color(wrappee)
        return Color(result)
    }

    public func getIcon() -> String? {
        let result = spine_bone_data_get_icon(wrappee)
        return result != nil ? String(cString: result!) : nil
    }

    public func setIcon(icon: String?) {
        spine_bone_data_set_icon(wrappee, icon?.cString(using: .utf8))
    }

    public func getVisible() -> Bool {
        return spine_bone_data_get_visible(wrappee) != 0
    }

    public func setVisible(inValue: Bool) {
        spine_bone_data_set_visible(wrappee, inValue ? 1 : 0)
    }

    public func getSetupPose() -> BoneLocal {
        let result = spine_bone_data_get_setup_pose(wrappee)
        return BoneLocal(result)
    }

    public func getName() -> String? {
        let result = spine_bone_data_get_name(wrappee)
        return result != nil ? String(cString: result!) : nil
    }

    public func getSkinRequired() -> Bool {
        return spine_bone_data_get_skin_required(wrappee) != 0
    }

    public func setSkinRequired(skinRequired: Bool) {
        spine_bone_data_set_skin_required(wrappee, skinRequired ? 1 : 0)
    }

    deinit {
        spine_bone_data_dispose(wrappee)
    }
}