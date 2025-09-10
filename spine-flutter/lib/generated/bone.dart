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

import 'package:universal_ffi/ffi.dart';
import 'spine_dart_bindings_generated.dart';
import '../spine_bindings.dart';
import 'rtti.dart';
import 'arrays.dart';
import 'bone_data.dart';
import 'bone_local.dart';
import 'bone_pose.dart';
import 'physics.dart';
import 'posed.dart';
import 'posed_active.dart';
import 'skeleton.dart';
import 'update.dart';

/// Bone wrapper
class Bone extends PosedActive implements Posed, Update {
  final Pointer<spine_bone_wrapper> _ptr;

  Bone.fromPointer(this._ptr) : super.fromPointer(SpineBindings.bindings.spine_bone_cast_to_posed_active(_ptr));

  /// Get the native pointer for FFI calls
  @override
  Pointer get nativePtr => _ptr;

  factory Bone(BoneData data, Bone? parent) {
    final ptr = SpineBindings.bindings
        .spine_bone_create(data.nativePtr.cast(), parent?.nativePtr.cast() ?? Pointer.fromAddress(0));
    return Bone.fromPointer(ptr);
  }

  factory Bone.from(Bone bone, Bone? parent) {
    final ptr = SpineBindings.bindings
        .spine_bone_create2(bone.nativePtr.cast(), parent?.nativePtr.cast() ?? Pointer.fromAddress(0));
    return Bone.fromPointer(ptr);
  }

  @override
  void dispose() {
    SpineBindings.bindings.spine_bone_dispose(_ptr);
  }

  @override
  Rtti get rtti {
    final result = SpineBindings.bindings.spine_bone_get_rtti(_ptr);
    return Rtti.fromPointer(result);
  }

  Bone? get parent {
    final result = SpineBindings.bindings.spine_bone_get_parent(_ptr);
    return result.address == 0 ? null : Bone.fromPointer(result);
  }

  ArrayBone get children {
    final result = SpineBindings.bindings.spine_bone_get_children(_ptr);
    return ArrayBone.fromPointer(result);
  }

  static bool isYDown() {
    final result = SpineBindings.bindings.spine_bone_is_y_down();
    return result;
  }

  static void setYDown(bool value) {
    SpineBindings.bindings.spine_bone_set_y_down(value);
  }

  @override
  void update(Skeleton skeleton, Physics physics) {
    SpineBindings.bindings.spine_bone_update(_ptr, skeleton.nativePtr.cast(), physics.value);
  }

  BoneData get data {
    final result = SpineBindings.bindings.spine_bone_get_data(_ptr);
    return BoneData.fromPointer(result);
  }

  BoneLocal get pose {
    final result = SpineBindings.bindings.spine_bone_get_pose(_ptr);
    return BoneLocal.fromPointer(result);
  }

  BonePose get appliedPose {
    final result = SpineBindings.bindings.spine_bone_get_applied_pose(_ptr);
    return BonePose.fromPointer(result);
  }

  @override
  void resetConstrained() {
    SpineBindings.bindings.spine_bone_reset_constrained(_ptr);
  }

  @override
  void constrained() {
    SpineBindings.bindings.spine_bone_constrained(_ptr);
  }

  @override
  bool get isPoseEqualToApplied {
    final result = SpineBindings.bindings.spine_bone_is_pose_equal_to_applied(_ptr);
    return result;
  }

  static Rtti rttiStatic() {
    final result = SpineBindings.bindings.spine_bone_rtti();
    return Rtti.fromPointer(result);
  }
}
