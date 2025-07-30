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
import 'rtti.dart';
import 'arrays.dart';
import 'bone.dart';
import 'bone_pose.dart';
import 'constraint.dart';
import 'ik_constraint_data.dart';
import 'ik_constraint_pose.dart';
import 'physics.dart';
import 'posed.dart';
import 'posed_active.dart';
import 'skeleton.dart';

/// IkConstraint wrapper
class IkConstraint extends PosedActive implements Posed, Constraint {
  final Pointer<spine_ik_constraint_wrapper> _ptr;

  IkConstraint.fromPointer(this._ptr) : super.fromPointer(_ptr.cast());

  /// Get the native pointer for FFI calls
  @override
  Pointer get nativePtr => _ptr;

  factory IkConstraint(IkConstraintData data, Skeleton skeleton) {
    final ptr = SpineBindings.bindings.spine_ik_constraint_create(data.nativePtr.cast(), skeleton.nativePtr.cast());
    return IkConstraint.fromPointer(ptr);
  }

  @override
  void dispose() {
    SpineBindings.bindings.spine_ik_constraint_dispose(_ptr);
  }

  @override
  Rtti get rtti {
    final result = SpineBindings.bindings.spine_ik_constraint_get_rtti(_ptr);
    return Rtti.fromPointer(result);
  }

  IkConstraint copy(Skeleton skeleton) {
    final result = SpineBindings.bindings.spine_ik_constraint_copy(_ptr, skeleton.nativePtr.cast());
    return IkConstraint.fromPointer(result);
  }

  @override
  void update(Skeleton skeleton, Physics physics) {
    SpineBindings.bindings.spine_ik_constraint_update(_ptr, skeleton.nativePtr.cast(), physics.value);
  }

  @override
  void sort(Skeleton skeleton) {
    SpineBindings.bindings.spine_ik_constraint_sort(_ptr, skeleton.nativePtr.cast());
  }

  @override
  bool get isSourceActive {
    final result = SpineBindings.bindings.spine_ik_constraint_is_source_active(_ptr);
    return result;
  }

  @override
  IkConstraintData get data {
    final result = SpineBindings.bindings.spine_ik_constraint_get_data(_ptr);
    return IkConstraintData.fromPointer(result);
  }

  ArrayBonePose get bones {
    final result = SpineBindings.bindings.spine_ik_constraint_get_bones(_ptr);
    return ArrayBonePose.fromPointer(result);
  }

  Bone get target {
    final result = SpineBindings.bindings.spine_ik_constraint_get_target(_ptr);
    return Bone.fromPointer(result);
  }

  set target(Bone value) {
    SpineBindings.bindings.spine_ik_constraint_set_target(_ptr, value.nativePtr.cast());
  }

  IkConstraintPose get pose {
    final result = SpineBindings.bindings.spine_ik_constraint_get_pose(_ptr);
    return IkConstraintPose.fromPointer(result);
  }

  IkConstraintPose get appliedPose {
    final result = SpineBindings.bindings.spine_ik_constraint_get_applied_pose(_ptr);
    return IkConstraintPose.fromPointer(result);
  }

  @override
  void resetConstrained() {
    SpineBindings.bindings.spine_ik_constraint_reset_constrained(_ptr);
  }

  @override
  void constrained() {
    SpineBindings.bindings.spine_ik_constraint_constrained(_ptr);
  }

  @override
  bool get isPoseEqualToApplied {
    final result = SpineBindings.bindings.spine_ik_constraint_is_pose_equal_to_applied(_ptr);
    return result;
  }

  static Rtti rttiStatic() {
    final result = SpineBindings.bindings.spine_ik_constraint_rtti();
    return Rtti.fromPointer(result);
  }

  static void apply(Skeleton skeleton, BonePose bone, double targetX, double targetY, bool compress, bool stretch,
      bool uniform, double mix) {
    SpineBindings.bindings.spine_ik_constraint_apply_1(
        skeleton.nativePtr.cast(), bone.nativePtr.cast(), targetX, targetY, compress, stretch, uniform, mix);
  }

  static void apply2(Skeleton skeleton, BonePose parent, BonePose child, double targetX, double targetY,
      int bendDirection, bool stretch, bool uniform, double softness, double mix) {
    SpineBindings.bindings.spine_ik_constraint_apply_2(skeleton.nativePtr.cast(), parent.nativePtr.cast(),
        child.nativePtr.cast(), targetX, targetY, bendDirection, stretch, uniform, softness, mix);
  }
}
