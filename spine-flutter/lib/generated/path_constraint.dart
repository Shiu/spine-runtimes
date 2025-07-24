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
import 'spine_flutter_bindings_generated.dart';
import '../spine_bindings.dart';
import 'rtti.dart';
import 'skeleton.dart';
import 'physics.dart';
import 'slot.dart';
import 'path_constraint_data.dart';
import 'path_constraint_pose.dart';
import 'arrays.dart';

/// PathConstraint wrapper
class PathConstraint implements Finalizable {
  final Pointer<spine_path_constraint_wrapper> _ptr;

  PathConstraint.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory PathConstraint(PathConstraintData data, Skeleton skeleton) {
    final ptr = SpineBindings.bindings.spine_path_constraint_create(data.nativePtr.cast(), skeleton.nativePtr.cast());
    return PathConstraint.fromPointer(ptr);
  }

  Rtti get rtti {
    final result = SpineBindings.bindings.spine_path_constraint_get_rtti(_ptr);
    return Rtti.fromPointer(result);
  }

  PathConstraint copy(Skeleton skeleton) {
    final result = SpineBindings.bindings.spine_path_constraint_copy(_ptr, skeleton.nativePtr.cast());
    return PathConstraint.fromPointer(result);
  }

  void update(Skeleton skeleton, Physics physics) {
    SpineBindings.bindings.spine_path_constraint_update(_ptr, skeleton.nativePtr.cast(), physics.value);
  }

  void sort(Skeleton skeleton) {
    SpineBindings.bindings.spine_path_constraint_sort(_ptr, skeleton.nativePtr.cast());
  }

  bool get isSourceActive {
    final result = SpineBindings.bindings.spine_path_constraint_is_source_active(_ptr);
    return result;
  }

  ArrayBonePose get bones {
    final result = SpineBindings.bindings.spine_path_constraint_get_bones(_ptr);
    return ArrayBonePose.fromPointer(result);
  }

  Slot get slot {
    final result = SpineBindings.bindings.spine_path_constraint_get_slot(_ptr);
    return Slot.fromPointer(result);
  }

  set slot(Slot value) {
    SpineBindings.bindings.spine_path_constraint_set_slot(_ptr, value.nativePtr.cast());
  }

  PathConstraintData get data {
    final result = SpineBindings.bindings.spine_path_constraint_get_data(_ptr);
    return PathConstraintData.fromPointer(result);
  }

  PathConstraintPose get pose {
    final result = SpineBindings.bindings.spine_path_constraint_get_pose(_ptr);
    return PathConstraintPose.fromPointer(result);
  }

  PathConstraintPose get appliedPose {
    final result = SpineBindings.bindings.spine_path_constraint_get_applied_pose(_ptr);
    return PathConstraintPose.fromPointer(result);
  }

  void resetConstrained() {
    SpineBindings.bindings.spine_path_constraint_reset_constrained(_ptr);
  }

  void constrained() {
    SpineBindings.bindings.spine_path_constraint_constrained(_ptr);
  }

  bool get isPoseEqualToApplied {
    final result = SpineBindings.bindings.spine_path_constraint_is_pose_equal_to_applied(_ptr);
    return result;
  }

  bool get isActive {
    final result = SpineBindings.bindings.spine_path_constraint_is_active(_ptr);
    return result;
  }

  set active(bool value) {
    SpineBindings.bindings.spine_path_constraint_set_active(_ptr, value);
  }

  static Rtti rttiStatic() {
    final result = SpineBindings.bindings.spine_path_constraint_rtti();
    return Rtti.fromPointer(result);
  }

  void dispose() {
    SpineBindings.bindings.spine_path_constraint_dispose(_ptr);
  }
}