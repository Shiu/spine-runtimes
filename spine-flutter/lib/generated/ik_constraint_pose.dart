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

import '../ffi_proxy.dart';
import 'spine_dart_bindings_generated.dart';
import '../spine_bindings.dart';

/// IkConstraintPose wrapper
class IkConstraintPose {
  final Pointer<spine_ik_constraint_pose_wrapper> _ptr;

  IkConstraintPose.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory IkConstraintPose() {
    final ptr = SpineBindings.bindings.spine_ik_constraint_pose_create();
    return IkConstraintPose.fromPointer(ptr);
  }

  void dispose() {
    SpineBindings.bindings.spine_ik_constraint_pose_dispose(_ptr);
  }

  void set(IkConstraintPose pose) {
    SpineBindings.bindings.spine_ik_constraint_pose_set(_ptr, pose.nativePtr.cast());
  }

  double get mix {
    final result = SpineBindings.bindings.spine_ik_constraint_pose_get_mix(_ptr);
    return result;
  }

  set mix(double value) {
    SpineBindings.bindings.spine_ik_constraint_pose_set_mix(_ptr, value);
  }

  double get softness {
    final result = SpineBindings.bindings.spine_ik_constraint_pose_get_softness(_ptr);
    return result;
  }

  set softness(double value) {
    SpineBindings.bindings.spine_ik_constraint_pose_set_softness(_ptr, value);
  }

  int get bendDirection {
    final result = SpineBindings.bindings.spine_ik_constraint_pose_get_bend_direction(_ptr);
    return result;
  }

  set bendDirection(int value) {
    SpineBindings.bindings.spine_ik_constraint_pose_set_bend_direction(_ptr, value);
  }

  bool get compress {
    final result = SpineBindings.bindings.spine_ik_constraint_pose_get_compress(_ptr);
    return result;
  }

  set compress(bool value) {
    SpineBindings.bindings.spine_ik_constraint_pose_set_compress(_ptr, value);
  }

  bool get stretch {
    final result = SpineBindings.bindings.spine_ik_constraint_pose_get_stretch(_ptr);
    return result;
  }

  set stretch(bool value) {
    SpineBindings.bindings.spine_ik_constraint_pose_set_stretch(_ptr, value);
  }
}
