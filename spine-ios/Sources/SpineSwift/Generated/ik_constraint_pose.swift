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

/// IkConstraintPose wrapper
@objc(SpineIkConstraintPose)
@objcMembers
public class IkConstraintPose: NSObject {
    public let _ptr: UnsafeMutableRawPointer

    public init(fromPointer ptr: spine_ik_constraint_pose) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        super.init()
    }

    public override convenience init() {
        let ptr = spine_ik_constraint_pose_create()
        self.init(fromPointer: ptr!)
    }

    public var mix: Float {
        get {
            let result = spine_ik_constraint_pose_get_mix(_ptr.assumingMemoryBound(to: spine_ik_constraint_pose_wrapper.self))
            return result
        }
        set {
            spine_ik_constraint_pose_set_mix(_ptr.assumingMemoryBound(to: spine_ik_constraint_pose_wrapper.self), newValue)
        }
    }

    public var softness: Float {
        get {
            let result = spine_ik_constraint_pose_get_softness(_ptr.assumingMemoryBound(to: spine_ik_constraint_pose_wrapper.self))
            return result
        }
        set {
            spine_ik_constraint_pose_set_softness(_ptr.assumingMemoryBound(to: spine_ik_constraint_pose_wrapper.self), newValue)
        }
    }

    public var bendDirection: Int32 {
        get {
            let result = spine_ik_constraint_pose_get_bend_direction(_ptr.assumingMemoryBound(to: spine_ik_constraint_pose_wrapper.self))
            return result
        }
        set {
            spine_ik_constraint_pose_set_bend_direction(_ptr.assumingMemoryBound(to: spine_ik_constraint_pose_wrapper.self), newValue)
        }
    }

    public var compress: Bool {
        get {
            let result = spine_ik_constraint_pose_get_compress(_ptr.assumingMemoryBound(to: spine_ik_constraint_pose_wrapper.self))
            return result
        }
        set {
            spine_ik_constraint_pose_set_compress(_ptr.assumingMemoryBound(to: spine_ik_constraint_pose_wrapper.self), newValue)
        }
    }

    public var stretch: Bool {
        get {
            let result = spine_ik_constraint_pose_get_stretch(_ptr.assumingMemoryBound(to: spine_ik_constraint_pose_wrapper.self))
            return result
        }
        set {
            spine_ik_constraint_pose_set_stretch(_ptr.assumingMemoryBound(to: spine_ik_constraint_pose_wrapper.self), newValue)
        }
    }

    public func set(_ pose: IkConstraintPose) {
        spine_ik_constraint_pose_set(
            _ptr.assumingMemoryBound(to: spine_ik_constraint_pose_wrapper.self),
            pose._ptr.assumingMemoryBound(to: spine_ik_constraint_pose_wrapper.self))
    }

    public func dispose() {
        spine_ik_constraint_pose_dispose(_ptr.assumingMemoryBound(to: spine_ik_constraint_pose_wrapper.self))
    }
}
