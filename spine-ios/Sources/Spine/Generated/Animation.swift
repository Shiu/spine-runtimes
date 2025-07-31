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

@objc(SpineAnimation)
@objcMembers
public final class Animation: NSObject {
    internal let wrappee: spine_animation

    internal init(_ wrappee: spine_animation) {
        self.wrappee = wrappee
        super.init()
    }

    public override func isEqual(_ object: Any?) -> Bool {
        guard let other = object as? Animation else { return false }
        return self.wrappee == other.wrappee
    }

    public override var hash: Int {
        var hasher = Hasher()
        hasher.combine(self.wrappee)
        return hasher.finalize()
    }

    public convenience init(name: String?, timelines: ArrayTimeline, duration: Float) {
        let ptr = spine_animation_create(name, timelines, duration)
        self.init(ptr)
    }

    public func getTimelines() -> ArrayTimeline {
        return spine_animation_get_timelines(wrappee)
    }

    public func setTimelines(timelines: ArrayTimeline) {
        spine_animation_set_timelines(wrappee, timelines)
    }

    public func hasTimeline(ids: ArrayPropertyId) -> Bool {
        return spine_animation_has_timeline(wrappee, ids) != 0
    }

    public func getDuration() -> Float {
        return spine_animation_get_duration(wrappee)
    }

    public func setDuration(inValue: Float) {
        spine_animation_set_duration(wrappee, inValue)
    }

    public func apply(skeleton: Skeleton, lastTime: Float, time: Float, loop: Bool, events: ArrayEvent, alpha: Float, blend: MixBlend, direction: MixDirection, appliedPose: Bool) {
        spine_animation_apply(wrappee, skeleton.wrappee, lastTime, time, loop ? 1 : 0, events, alpha, blend, direction, appliedPose ? 1 : 0)
    }

    public func getName() -> String? {
        let result = spine_animation_get_name(wrappee)
        return result != nil ? String(cString: result!) : nil
    }

    public func getBones() -> ArrayInt {
        return spine_animation_get_bones(wrappee)
    }

    public func search(values: ArrayFloat, target: Float) -> Int32 {
        return spine_animation_search_1(wrappee, values, target)
    }

    public func search(values: ArrayFloat, target: Float, step: Int32) -> Int32 {
        return spine_animation_search_2(wrappee, values, target, step)
    }

    deinit {
        spine_animation_dispose(wrappee)
    }
}