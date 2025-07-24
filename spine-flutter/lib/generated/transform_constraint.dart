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
import 'bone.dart';
import 'transform_constraint_data.dart';
import 'transform_constraint_pose.dart';
import 'arrays.dart';

/// TransformConstraint wrapper
class TransformConstraint implements Finalizable {
  final Pointer<spine_transform_constraint_wrapper> _ptr;

  TransformConstraint.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory TransformConstraint(TransformConstraintData data, Skeleton skeleton) {
    final ptr = SpineBindings.bindings.spine_transform_constraint_create(data.nativePtr.cast(), skeleton.nativePtr.cast());
    return TransformConstraint.fromPointer(ptr);
  }

  Rtti get rtti {
    final result = SpineBindings.bindings.spine_transform_constraint_get_rtti(_ptr);
    return Rtti.fromPointer(result);
  }

  TransformConstraint copy(Skeleton skeleton) {
    final result = SpineBindings.bindings.spine_transform_constraint_copy(_ptr, skeleton.nativePtr.cast());
    return TransformConstraint.fromPointer(result);
  }

  void update(Skeleton skeleton, Physics physics) {
    SpineBindings.bindings.spine_transform_constraint_update(_ptr, skeleton.nativePtr.cast(), physics.value);
  }

  void sort(Skeleton skeleton) {
    SpineBindings.bindings.spine_transform_constraint_sort(_ptr, skeleton.nativePtr.cast());
  }

  bool get isSourceActive {
    final result = SpineBindings.bindings.spine_transform_constraint_is_source_active(_ptr);
    return result;
  }

  ArrayBonePose get bones {
    final result = SpineBindings.bindings.spine_transform_constraint_get_bones(_ptr);
    return ArrayBonePose.fromPointer(result);
  }

  Bone get source {
    final result = SpineBindings.bindings.spine_transform_constraint_get_source(_ptr);
    return Bone.fromPointer(result);
  }

  set source(Bone value) {
    SpineBindings.bindings.spine_transform_constraint_set_source(_ptr, value.nativePtr.cast());
  }

  TransformConstraintData get data {
    final result = SpineBindings.bindings.spine_transform_constraint_get_data(_ptr);
    return TransformConstraintData.fromPointer(result);
  }

  TransformConstraintPose get pose {
    final result = SpineBindings.bindings.spine_transform_constraint_get_pose(_ptr);
    return TransformConstraintPose.fromPointer(result);
  }

  TransformConstraintPose get appliedPose {
    final result = SpineBindings.bindings.spine_transform_constraint_get_applied_pose(_ptr);
    return TransformConstraintPose.fromPointer(result);
  }

  void resetConstrained() {
    SpineBindings.bindings.spine_transform_constraint_reset_constrained(_ptr);
  }

  void constrained() {
    SpineBindings.bindings.spine_transform_constraint_constrained(_ptr);
  }

  bool get isPoseEqualToApplied {
    final result = SpineBindings.bindings.spine_transform_constraint_is_pose_equal_to_applied(_ptr);
    return result;
  }

  bool get isActive {
    final result = SpineBindings.bindings.spine_transform_constraint_is_active(_ptr);
    return result;
  }

  set active(bool value) {
    SpineBindings.bindings.spine_transform_constraint_set_active(_ptr, value);
  }

  static Rtti rttiStatic() {
    final result = SpineBindings.bindings.spine_transform_constraint_rtti();
    return Rtti.fromPointer(result);
  }

  void dispose() {
    SpineBindings.bindings.spine_transform_constraint_dispose(_ptr);
  }
}