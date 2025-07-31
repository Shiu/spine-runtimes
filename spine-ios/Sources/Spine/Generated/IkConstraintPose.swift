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

@objc(SpineIkConstraintPose)
@objcMembers
public final class IkConstraintPose: NSObject {
    internal let wrappee: spine_ik_constraint_pose

    internal init(_ wrappee: spine_ik_constraint_pose) {
        self.wrappee = wrappee
        super.init()
    }

    public override func isEqual(_ object: Any?) -> Bool {
        guard let other = object as? IkConstraintPose else { return false }
        return self.wrappee == other.wrappee
    }

    public override var hash: Int {
        var hasher = Hasher()
        hasher.combine(self.wrappee)
        return hasher.finalize()
    }

    public convenience init() {
        let ptr = spine_ik_constraint_pose_create()
        self.init(ptr)
    }

    public func set(pose: IkConstraintPose) {
        spine_ik_constraint_pose_set(wrappee, pose.wrappee)
    }

    public func getMix() -> Float {
        return spine_ik_constraint_pose_get_mix(wrappee)
    }

    public func setMix(mix: Float) {
        spine_ik_constraint_pose_set_mix(wrappee, mix)
    }

    public func getSoftness() -> Float {
        return spine_ik_constraint_pose_get_softness(wrappee)
    }

    public func setSoftness(softness: Float) {
        spine_ik_constraint_pose_set_softness(wrappee, softness)
    }

    public func getBendDirection() -> Int32 {
        return spine_ik_constraint_pose_get_bend_direction(wrappee)
    }

    public func setBendDirection(bendDirection: Int32) {
        spine_ik_constraint_pose_set_bend_direction(wrappee, bendDirection)
    }

    public func getCompress() -> Bool {
        return spine_ik_constraint_pose_get_compress(wrappee) != 0
    }

    public func setCompress(compress: Bool) {
        spine_ik_constraint_pose_set_compress(wrappee, compress ? 1 : 0)
    }

    public func getStretch() -> Bool {
        return spine_ik_constraint_pose_get_stretch(wrappee) != 0
    }

    public func setStretch(stretch: Bool) {
        spine_ik_constraint_pose_set_stretch(wrappee, stretch ? 1 : 0)
    }

    deinit {
        spine_ik_constraint_pose_dispose(wrappee)
    }
}