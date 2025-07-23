// ******************************************************************************
// Spine Runtimes License Agreement
// Last updated July 28, 2023. Replaces all prior versions.
//
// Copyright (c) 2013-2023, Esoteric Software LLC
//
// Integration of the Spine Runtimes into software or otherwise creating
// derivative works of the Spine Runtimes is permitted under the terms and
// conditions of Section 2 of the Spine Editor License Agreement:
// http://esotericsoftware.com/spine-editor-license
//
// Otherwise, it is permitted to integrate the Spine Runtimes into software or
// otherwise create derivative works of the Spine Runtimes (collectively,
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
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THE
// SPINE RUNTIMES, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// *****************************************************************************/

// AUTO GENERATED FILE, DO NOT EDIT.

import 'dart:ffi';
import 'spine_flutter_bindings_generated.dart';
import 'rtti.dart';
import 'skeleton.dart';
import 'physics.dart';
import 'ik_constraint_data.dart';
import 'bone.dart';
import 'bone_pose.dart';
import 'ik_constraint_pose.dart';
import 'arrays.dart';

/// IkConstraint wrapper
class IkConstraint implements Finalizable {
  static late SpineFlutterBindings _bindings;
  final Pointer<spine_ik_constraint_wrapper> _ptr;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  IkConstraint.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory IkConstraint(IkConstraintData data, Skeleton skeleton) {
    final ptr = _bindings.spine_ik_constraint_create(data.nativePtr.cast(), skeleton.nativePtr.cast());
    return IkConstraint.fromPointer(ptr);
  }

  Rtti get rtti {
    final result = _bindings.spine_ik_constraint_get_rtti(_ptr);
    return Rtti.fromPointer(result);
  }

  IkConstraint copy(Skeleton skeleton) {
    final result = _bindings.spine_ik_constraint_copy(_ptr, skeleton.nativePtr.cast());
    return IkConstraint.fromPointer(result);
  }

  void update(Skeleton skeleton, Physics physics) {
    _bindings.spine_ik_constraint_update(_ptr, skeleton.nativePtr.cast(), physics.value);
  }

  void sort(Skeleton skeleton) {
    _bindings.spine_ik_constraint_sort(_ptr, skeleton.nativePtr.cast());
  }

  bool get isSourceActive {
    final result = _bindings.spine_ik_constraint_is_source_active(_ptr);
    return result;
  }

  IkConstraintData get data {
    final result = _bindings.spine_ik_constraint_get_data(_ptr);
    return IkConstraintData.fromPointer(result);
  }

  ArrayBonePose get bones {
    final result = _bindings.spine_ik_constraint_get_bones(_ptr);
    return ArrayBonePose.fromPointer(result);
  }

  Bone get target {
    final result = _bindings.spine_ik_constraint_get_target(_ptr);
    return Bone.fromPointer(result);
  }

  set target(Bone value) {
    _bindings.spine_ik_constraint_set_target(_ptr, value.nativePtr.cast());
  }

  IkConstraintPose get pose {
    final result = _bindings.spine_ik_constraint_get_pose(_ptr);
    return IkConstraintPose.fromPointer(result);
  }

  IkConstraintPose get appliedPose {
    final result = _bindings.spine_ik_constraint_get_applied_pose(_ptr);
    return IkConstraintPose.fromPointer(result);
  }

  void resetConstrained() {
    _bindings.spine_ik_constraint_reset_constrained(_ptr);
  }

  void constrained() {
    _bindings.spine_ik_constraint_constrained(_ptr);
  }

  bool get isPoseEqualToApplied {
    final result = _bindings.spine_ik_constraint_is_pose_equal_to_applied(_ptr);
    return result;
  }

  bool get isActive {
    final result = _bindings.spine_ik_constraint_is_active(_ptr);
    return result;
  }

  set active(bool value) {
    _bindings.spine_ik_constraint_set_active(_ptr, value);
  }

  static Rtti rttiStatic() {
    final result = _bindings.spine_ik_constraint_rtti();
    return Rtti.fromPointer(result);
  }

  static void apply1(Skeleton skeleton, BonePose bone, double targetX, double targetY, bool compress, bool stretch, bool uniform, double mix) {
    _bindings.spine_ik_constraint_apply_1(skeleton.nativePtr.cast(), bone.nativePtr.cast(), targetX, targetY, compress, stretch, uniform, mix);
  }

  static void apply2(Skeleton skeleton, BonePose parent, BonePose child, double targetX, double targetY, int bendDirection, bool stretch, bool uniform, double softness, double mix) {
    _bindings.spine_ik_constraint_apply_2(skeleton.nativePtr.cast(), parent.nativePtr.cast(), child.nativePtr.cast(), targetX, targetY, bendDirection, stretch, uniform, softness, mix);
  }

  void dispose() {
    _bindings.spine_ik_constraint_dispose(_ptr);
  }
}