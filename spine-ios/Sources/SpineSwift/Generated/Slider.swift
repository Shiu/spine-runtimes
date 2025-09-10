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

/// Slider wrapper
@objc(SpineSlider)
@objcMembers
public class Slider: SliderBase {
    @nonobjc
    public init(fromPointer ptr: spine_slider) {
        super.init(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_slider_base_wrapper.self))
    }

    public convenience init(_ data: SliderData, _ skeleton: Skeleton) {
        let ptr = spine_slider_create(data._ptr.assumingMemoryBound(to: spine_slider_data_wrapper.self), skeleton._ptr.assumingMemoryBound(to: spine_skeleton_wrapper.self))
        self.init(fromPointer: ptr!)
    }

    public var bone: Bone {
        get {
            let result = spine_slider_get_bone(_ptr.assumingMemoryBound(to: spine_slider_wrapper.self))
        return Bone(fromPointer: result!)
        }
        set {
            spine_slider_set_bone(_ptr.assumingMemoryBound(to: spine_slider_wrapper.self), newValue._ptr.assumingMemoryBound(to: spine_bone_wrapper.self))
        }
    }

    public func copyAttachment(_ skeleton: Skeleton) -> Slider {
        let result = spine_slider_copy(_ptr.assumingMemoryBound(to: spine_slider_wrapper.self), skeleton._ptr.assumingMemoryBound(to: spine_skeleton_wrapper.self))
        return Slider(fromPointer: result!)
    }

    public override func dispose() {
        spine_slider_dispose(_ptr.assumingMemoryBound(to: spine_slider_wrapper.self))
    }
}