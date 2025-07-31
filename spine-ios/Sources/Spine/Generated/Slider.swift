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

@objc(SpineSlider)
@objcMembers
public final class Slider: PosedActive, Posed, Constraint {
    internal let wrappee: spine_slider

    internal init(_ wrappee: spine_slider) {
        self.wrappee = wrappee
        super.init(wrappee)
    }

    public convenience init(data: SliderData, skeleton: Skeleton) {
        let ptr = spine_slider_create(data.wrappee, skeleton.wrappee)
        self.init(ptr)
    }

    public func getRtti() -> Rtti {
        let result = spine_slider_get_rtti(wrappee)
        return Rtti(result)
    }

    public func copy(skeleton: Skeleton) -> Slider {
        let result = spine_slider_copy(wrappee, skeleton.wrappee)
        return Slider(result)
    }

    public func update(skeleton: Skeleton, physics: Physics) {
        spine_slider_update(wrappee, skeleton.wrappee, physics)
    }

    public func sort(skeleton: Skeleton) {
        spine_slider_sort(wrappee, skeleton.wrappee)
    }

    public func isSourceActive() -> Bool {
        return spine_slider_is_source_active(wrappee) != 0
    }

    public func getBone() -> Bone {
        let result = spine_slider_get_bone(wrappee)
        return Bone(result)
    }

    public func setBone(bone: Bone) {
        spine_slider_set_bone(wrappee, bone.wrappee)
    }

    public func getData() -> SliderData {
        let result = spine_slider_get_data(wrappee)
        return SliderData(result)
    }

    public func getPose() -> SliderPose {
        let result = spine_slider_get_pose(wrappee)
        return SliderPose(result)
    }

    public func getAppliedPose() -> SliderPose {
        let result = spine_slider_get_applied_pose(wrappee)
        return SliderPose(result)
    }

    public func resetConstrained() {
        spine_slider_reset_constrained(wrappee)
    }

    public func constrained() {
        spine_slider_constrained(wrappee)
    }

    public func isPoseEqualToApplied() -> Bool {
        return spine_slider_is_pose_equal_to_applied(wrappee) != 0
    }

    public func isActive() -> Bool {
        return spine_slider_is_active(wrappee) != 0
    }

    public func setActive(active: Bool) {
        spine_slider_set_active(wrappee, active ? 1 : 0)
    }

    public func rtti() -> Rtti {
        let result = spine_slider_rtti(wrappee)
        return Rtti(result)
    }

    deinit {
        spine_slider_dispose(wrappee)
    }
}