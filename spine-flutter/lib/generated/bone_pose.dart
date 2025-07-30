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
import 'bone_local.dart';
import 'physics.dart';
import 'skeleton.dart';
import 'update.dart';

/// BonePose wrapper
class BonePose extends BoneLocal implements Update {
  final Pointer<spine_bone_pose_wrapper> _ptr;

  BonePose.fromPointer(this._ptr) : super.fromPointer(_ptr.cast());

  /// Get the native pointer for FFI calls
  @override
  Pointer get nativePtr => _ptr;

  factory BonePose() {
    final ptr = SpineBindings.bindings.spine_bone_pose_create();
    return BonePose.fromPointer(ptr);
  }

  @override
  void dispose() {
    SpineBindings.bindings.spine_bone_pose_dispose(_ptr);
  }

  @override
  Rtti get rtti {
    final result = SpineBindings.bindings.spine_bone_pose_get_rtti(_ptr);
    return Rtti.fromPointer(result);
  }

  @override
  void update(Skeleton skeleton, Physics physics) {
    SpineBindings.bindings.spine_bone_pose_update(_ptr, skeleton.nativePtr.cast(), physics.value);
  }

  void updateWorldTransform(Skeleton skeleton) {
    SpineBindings.bindings.spine_bone_pose_update_world_transform(_ptr, skeleton.nativePtr.cast());
  }

  void updateLocalTransform(Skeleton skeleton) {
    SpineBindings.bindings.spine_bone_pose_update_local_transform(_ptr, skeleton.nativePtr.cast());
  }

  void validateLocalTransform(Skeleton skeleton) {
    SpineBindings.bindings.spine_bone_pose_validate_local_transform(_ptr, skeleton.nativePtr.cast());
  }

  void modifyLocal(Skeleton skeleton) {
    SpineBindings.bindings.spine_bone_pose_modify_local(_ptr, skeleton.nativePtr.cast());
  }

  void modifyWorld(int update) {
    SpineBindings.bindings.spine_bone_pose_modify_world(_ptr, update);
  }

  void resetWorld(int update) {
    SpineBindings.bindings.spine_bone_pose_reset_world(_ptr, update);
  }

  double get a {
    final result = SpineBindings.bindings.spine_bone_pose_get_a(_ptr);
    return result;
  }

  set a(double value) {
    SpineBindings.bindings.spine_bone_pose_set_a(_ptr, value);
  }

  double get b {
    final result = SpineBindings.bindings.spine_bone_pose_get_b(_ptr);
    return result;
  }

  set b(double value) {
    SpineBindings.bindings.spine_bone_pose_set_b(_ptr, value);
  }

  double get c {
    final result = SpineBindings.bindings.spine_bone_pose_get_c(_ptr);
    return result;
  }

  set c(double value) {
    SpineBindings.bindings.spine_bone_pose_set_c(_ptr, value);
  }

  double get d {
    final result = SpineBindings.bindings.spine_bone_pose_get_d(_ptr);
    return result;
  }

  set d(double value) {
    SpineBindings.bindings.spine_bone_pose_set_d(_ptr, value);
  }

  double get worldX {
    final result = SpineBindings.bindings.spine_bone_pose_get_world_x(_ptr);
    return result;
  }

  set worldX(double value) {
    SpineBindings.bindings.spine_bone_pose_set_world_x(_ptr, value);
  }

  double get worldY {
    final result = SpineBindings.bindings.spine_bone_pose_get_world_y(_ptr);
    return result;
  }

  set worldY(double value) {
    SpineBindings.bindings.spine_bone_pose_set_world_y(_ptr, value);
  }

  double get worldRotationX {
    final result = SpineBindings.bindings.spine_bone_pose_get_world_rotation_x(_ptr);
    return result;
  }

  double get worldRotationY {
    final result = SpineBindings.bindings.spine_bone_pose_get_world_rotation_y(_ptr);
    return result;
  }

  double get worldScaleX {
    final result = SpineBindings.bindings.spine_bone_pose_get_world_scale_x(_ptr);
    return result;
  }

  double get worldScaleY {
    final result = SpineBindings.bindings.spine_bone_pose_get_world_scale_y(_ptr);
    return result;
  }

  double worldToLocalRotation(double worldRotation) {
    final result = SpineBindings.bindings.spine_bone_pose_world_to_local_rotation(_ptr, worldRotation);
    return result;
  }

  double localToWorldRotation(double localRotation) {
    final result = SpineBindings.bindings.spine_bone_pose_local_to_world_rotation(_ptr, localRotation);
    return result;
  }

  void rotateWorld(double degrees) {
    SpineBindings.bindings.spine_bone_pose_rotate_world(_ptr, degrees);
  }

  static Rtti rttiStatic() {
    final result = SpineBindings.bindings.spine_bone_pose_rtti();
    return Rtti.fromPointer(result);
  }
}
