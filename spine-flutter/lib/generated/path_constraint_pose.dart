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

import 'dart:ffi';
import 'spine_dart_bindings_generated.dart';
import '../spine_bindings.dart';

/// PathConstraintPose wrapper
class PathConstraintPose implements Finalizable {
  final Pointer<spine_path_constraint_pose_wrapper> _ptr;

  PathConstraintPose.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory PathConstraintPose() {
    final ptr = SpineBindings.bindings.spine_path_constraint_pose_create();
    return PathConstraintPose.fromPointer(ptr);
  }

  void set(PathConstraintPose pose) {
    SpineBindings.bindings.spine_path_constraint_pose_set(_ptr, pose.nativePtr.cast());
  }

  double get position {
    final result = SpineBindings.bindings.spine_path_constraint_pose_get_position(_ptr);
    return result;
  }

  set position(double value) {
    SpineBindings.bindings.spine_path_constraint_pose_set_position(_ptr, value);
  }

  double get spacing {
    final result = SpineBindings.bindings.spine_path_constraint_pose_get_spacing(_ptr);
    return result;
  }

  set spacing(double value) {
    SpineBindings.bindings.spine_path_constraint_pose_set_spacing(_ptr, value);
  }

  double get mixRotate {
    final result = SpineBindings.bindings.spine_path_constraint_pose_get_mix_rotate(_ptr);
    return result;
  }

  set mixRotate(double value) {
    SpineBindings.bindings.spine_path_constraint_pose_set_mix_rotate(_ptr, value);
  }

  double get mixX {
    final result = SpineBindings.bindings.spine_path_constraint_pose_get_mix_x(_ptr);
    return result;
  }

  set mixX(double value) {
    SpineBindings.bindings.spine_path_constraint_pose_set_mix_x(_ptr, value);
  }

  double get mixY {
    final result = SpineBindings.bindings.spine_path_constraint_pose_get_mix_y(_ptr);
    return result;
  }

  set mixY(double value) {
    SpineBindings.bindings.spine_path_constraint_pose_set_mix_y(_ptr, value);
  }
}
