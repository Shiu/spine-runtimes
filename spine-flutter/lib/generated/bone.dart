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
import 'bone_data.dart';
import 'bone_local.dart';
import 'bone_pose.dart';
import 'arrays.dart';

/// Bone wrapper
class Bone implements Finalizable {
  static late SpineFlutterBindings _bindings;
  final Pointer<spine_bone_wrapper> _ptr;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  Bone.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory Bone(BoneData data, Bone parent) {
    final ptr = _bindings.spine_bone_create(data.nativePtr.cast(), parent.nativePtr.cast());
    return Bone.fromPointer(ptr);
  }

  factory Bone.from(Bone bone, Bone parent) {
    final ptr = _bindings.spine_bone_create2(bone.nativePtr.cast(), parent.nativePtr.cast());
    return Bone.fromPointer(ptr);
  }

  Rtti get rtti {
    final result = _bindings.spine_bone_get_rtti(_ptr);
    return Rtti.fromPointer(result);
  }

  Bone get parent {
    final result = _bindings.spine_bone_get_parent(_ptr);
    return Bone.fromPointer(result);
  }

  ArrayBone get children {
    final result = _bindings.spine_bone_get_children(_ptr);
    return ArrayBone.fromPointer(result);
  }

  static bool isYDown() {
    final result = _bindings.spine_bone_is_y_down();
    return result;
  }

  static void setYDown(bool value) {
    _bindings.spine_bone_set_y_down(value);
  }

  void update(Skeleton skeleton, Physics physics) {
    _bindings.spine_bone_update(_ptr, skeleton.nativePtr.cast(), physics.value);
  }

  BoneData get data {
    final result = _bindings.spine_bone_get_data(_ptr);
    return BoneData.fromPointer(result);
  }

  BoneLocal get pose {
    final result = _bindings.spine_bone_get_pose(_ptr);
    return BoneLocal.fromPointer(result);
  }

  BonePose get appliedPose {
    final result = _bindings.spine_bone_get_applied_pose(_ptr);
    return BonePose.fromPointer(result);
  }

  void resetConstrained() {
    _bindings.spine_bone_reset_constrained(_ptr);
  }

  void constrained() {
    _bindings.spine_bone_constrained(_ptr);
  }

  bool get isPoseEqualToApplied {
    final result = _bindings.spine_bone_is_pose_equal_to_applied(_ptr);
    return result;
  }

  bool get isActive {
    final result = _bindings.spine_bone_is_active(_ptr);
    return result;
  }

  set active(bool value) {
    _bindings.spine_bone_set_active(_ptr, value);
  }

  static Rtti rttiStatic() {
    final result = _bindings.spine_bone_rtti();
    return Rtti.fromPointer(result);
  }

  void dispose() {
    _bindings.spine_bone_dispose(_ptr);
  }
}