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
import 'bone_local.dart';
import 'inherit.dart';

/// BonePose wrapper
class BonePose implements Finalizable {
  static late SpineFlutterBindings _bindings;
  final Pointer<spine_bone_pose_wrapper> _ptr;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  BonePose.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory BonePose() {
    final ptr = _bindings.spine_bone_pose_create();
    return BonePose.fromPointer(ptr);
  }

  Rtti get rtti {
    final result = _bindings.spine_bone_pose_get_rtti(_ptr);
    return Rtti.fromPointer(result);
  }

  void update(Skeleton skeleton, Physics physics) {
    _bindings.spine_bone_pose_update(_ptr, skeleton.nativePtr.cast(), physics.value);
  }

  void updateWorldTransform(Skeleton skeleton) {
    _bindings.spine_bone_pose_update_world_transform(_ptr, skeleton.nativePtr.cast());
  }

  void updateLocalTransform(Skeleton skeleton) {
    _bindings.spine_bone_pose_update_local_transform(_ptr, skeleton.nativePtr.cast());
  }

  void validateLocalTransform(Skeleton skeleton) {
    _bindings.spine_bone_pose_validate_local_transform(_ptr, skeleton.nativePtr.cast());
  }

  void modifyLocal(Skeleton skeleton) {
    _bindings.spine_bone_pose_modify_local(_ptr, skeleton.nativePtr.cast());
  }

  void modifyWorld(int update) {
    _bindings.spine_bone_pose_modify_world(_ptr, update);
  }

  void resetWorld(int update) {
    _bindings.spine_bone_pose_reset_world(_ptr, update);
  }

  double get a {
    final result = _bindings.spine_bone_pose_get_a(_ptr);
    return result;
  }

  set a(double value) {
    _bindings.spine_bone_pose_set_a(_ptr, value);
  }

  double get b {
    final result = _bindings.spine_bone_pose_get_b(_ptr);
    return result;
  }

  set b(double value) {
    _bindings.spine_bone_pose_set_b(_ptr, value);
  }

  double get c {
    final result = _bindings.spine_bone_pose_get_c(_ptr);
    return result;
  }

  set c(double value) {
    _bindings.spine_bone_pose_set_c(_ptr, value);
  }

  double get d {
    final result = _bindings.spine_bone_pose_get_d(_ptr);
    return result;
  }

  set d(double value) {
    _bindings.spine_bone_pose_set_d(_ptr, value);
  }

  double get worldX {
    final result = _bindings.spine_bone_pose_get_world_x(_ptr);
    return result;
  }

  set worldX(double value) {
    _bindings.spine_bone_pose_set_world_x(_ptr, value);
  }

  double get worldY {
    final result = _bindings.spine_bone_pose_get_world_y(_ptr);
    return result;
  }

  set worldY(double value) {
    _bindings.spine_bone_pose_set_world_y(_ptr, value);
  }

  double get worldRotationX {
    final result = _bindings.spine_bone_pose_get_world_rotation_x(_ptr);
    return result;
  }

  double get worldRotationY {
    final result = _bindings.spine_bone_pose_get_world_rotation_y(_ptr);
    return result;
  }

  double get worldScaleX {
    final result = _bindings.spine_bone_pose_get_world_scale_x(_ptr);
    return result;
  }

  double get worldScaleY {
    final result = _bindings.spine_bone_pose_get_world_scale_y(_ptr);
    return result;
  }

  double worldToLocalRotation(double worldRotation) {
    final result = _bindings.spine_bone_pose_world_to_local_rotation(_ptr, worldRotation);
    return result;
  }

  double localToWorldRotation(double localRotation) {
    final result = _bindings.spine_bone_pose_local_to_world_rotation(_ptr, localRotation);
    return result;
  }

  void rotateWorld(double degrees) {
    _bindings.spine_bone_pose_rotate_world(_ptr, degrees);
  }

  void set(BoneLocal pose) {
    _bindings.spine_bone_pose_set(_ptr, pose.nativePtr.cast());
  }

  double get x {
    final result = _bindings.spine_bone_pose_get_x(_ptr);
    return result;
  }

  set x(double value) {
    _bindings.spine_bone_pose_set_x(_ptr, value);
  }

  double get y {
    final result = _bindings.spine_bone_pose_get_y(_ptr);
    return result;
  }

  set y(double value) {
    _bindings.spine_bone_pose_set_y(_ptr, value);
  }

  void setPosition(double x, double y) {
    _bindings.spine_bone_pose_set_position(_ptr, x, y);
  }

  double get rotation {
    final result = _bindings.spine_bone_pose_get_rotation(_ptr);
    return result;
  }

  set rotation(double value) {
    _bindings.spine_bone_pose_set_rotation(_ptr, value);
  }

  double get scaleX {
    final result = _bindings.spine_bone_pose_get_scale_x(_ptr);
    return result;
  }

  set scaleX(double value) {
    _bindings.spine_bone_pose_set_scale_x(_ptr, value);
  }

  double get scaleY {
    final result = _bindings.spine_bone_pose_get_scale_y(_ptr);
    return result;
  }

  set scaleY(double value) {
    _bindings.spine_bone_pose_set_scale_y(_ptr, value);
  }

  double get shearX {
    final result = _bindings.spine_bone_pose_get_shear_x(_ptr);
    return result;
  }

  set shearX(double value) {
    _bindings.spine_bone_pose_set_shear_x(_ptr, value);
  }

  double get shearY {
    final result = _bindings.spine_bone_pose_get_shear_y(_ptr);
    return result;
  }

  set shearY(double value) {
    _bindings.spine_bone_pose_set_shear_y(_ptr, value);
  }

  Inherit get inherit {
    final result = _bindings.spine_bone_pose_get_inherit(_ptr);
    return Inherit.fromValue(result);
  }

  set inherit(Inherit value) {
    _bindings.spine_bone_pose_set_inherit(_ptr, value.value);
  }

  static Rtti rttiStatic() {
    final result = _bindings.spine_bone_pose_rtti();
    return Rtti.fromPointer(result);
  }

  void setScale1(double scaleX, double scaleY) {
    _bindings.spine_bone_pose_set_scale_1(_ptr, scaleX, scaleY);
  }

  set scale2(double value) {
    _bindings.spine_bone_pose_set_scale_2(_ptr, value);
  }

  void dispose() {
    _bindings.spine_bone_pose_dispose(_ptr);
  }
}