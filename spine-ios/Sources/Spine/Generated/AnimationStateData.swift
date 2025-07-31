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

@objc(SpineAnimationStateData)
@objcMembers
public final class AnimationStateData: NSObject {
    internal let wrappee: spine_animation_state_data

    internal init(_ wrappee: spine_animation_state_data) {
        self.wrappee = wrappee
        super.init()
    }

    public override func isEqual(_ object: Any?) -> Bool {
        guard let other = object as? AnimationStateData else { return false }
        return self.wrappee == other.wrappee
    }

    public override var hash: Int {
        var hasher = Hasher()
        hasher.combine(self.wrappee)
        return hasher.finalize()
    }

    public convenience init(skeletonData: SkeletonData) {
        let ptr = spine_animation_state_data_create(skeletonData.wrappee)
        self.init(ptr)
    }

    public func getSkeletonData() -> SkeletonData {
        let result = spine_animation_state_data_get_skeleton_data(wrappee)
        return SkeletonData(result)
    }

    public func getDefaultMix() -> Float {
        return spine_animation_state_data_get_default_mix(wrappee)
    }

    public func setDefaultMix(inValue: Float) {
        spine_animation_state_data_set_default_mix(wrappee, inValue)
    }

    public func setMix(fromName: String?, toName: String?, duration: Float) {
        spine_animation_state_data_set_mix_1(wrappee, fromName?.cString(using: .utf8), toName?.cString(using: .utf8), duration)
    }

    public func setMix(from: Animation, to: Animation, duration: Float) {
        spine_animation_state_data_set_mix_2(wrappee, from.wrappee, to.wrappee, duration)
    }

    public func getMix(from: Animation, to: Animation) -> Float {
        return spine_animation_state_data_get_mix(wrappee, from.wrappee, to.wrappee)
    }

    public func clear() {
        spine_animation_state_data_clear(wrappee)
    }

    deinit {
        spine_animation_state_data_dispose(wrappee)
    }
}