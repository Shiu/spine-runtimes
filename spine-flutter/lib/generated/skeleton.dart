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
import 'package:ffi/ffi.dart';
import 'spine_flutter_bindings_generated.dart';
import 'posed.dart';
import 'bone.dart';
import 'physics.dart';
import 'bone_pose.dart';
import 'skeleton_data.dart';
import 'slot.dart';
import 'skin.dart';
import 'attachment.dart';
import 'color.dart';
import 'arrays.dart';

/// Skeleton wrapper
class Skeleton implements Finalizable {
  static late SpineFlutterBindings _bindings;
  final Pointer<spine_skeleton_wrapper> _ptr;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  Skeleton.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory Skeleton(SkeletonData skeletonData) {
    final ptr = _bindings.spine_skeleton_create(skeletonData.nativePtr.cast());
    return Skeleton.fromPointer(ptr);
  }

  void updateCache() {
    _bindings.spine_skeleton_update_cache(_ptr);
  }

  void printUpdateCache() {
    _bindings.spine_skeleton_print_update_cache(_ptr);
  }

  void constrained(Posed object) {
    _bindings.spine_skeleton_constrained(_ptr, object.nativePtr.cast());
  }

  void sortBone(Bone bone) {
    _bindings.spine_skeleton_sort_bone(_ptr, bone.nativePtr.cast());
  }

  static void sortReset(ArrayBone bones) {
    _bindings.spine_skeleton_sort_reset(bones.nativePtr.cast());
  }

  void setupPose() {
    _bindings.spine_skeleton_setup_pose(_ptr);
  }

  void setupPoseBones() {
    _bindings.spine_skeleton_setup_pose_bones(_ptr);
  }

  void setupPoseSlots() {
    _bindings.spine_skeleton_setup_pose_slots(_ptr);
  }

  SkeletonData get data {
    final result = _bindings.spine_skeleton_get_data(_ptr);
    return SkeletonData.fromPointer(result);
  }

  ArrayBone get bones {
    final result = _bindings.spine_skeleton_get_bones(_ptr);
    return ArrayBone.fromPointer(result);
  }

  ArrayUpdate get updateCacheList {
    final result = _bindings.spine_skeleton_get_update_cache(_ptr);
    return ArrayUpdate.fromPointer(result);
  }

  Bone get rootBone {
    final result = _bindings.spine_skeleton_get_root_bone(_ptr);
    return Bone.fromPointer(result);
  }

  Bone findBone(String boneName) {
    final result = _bindings.spine_skeleton_find_bone(_ptr, boneName.toNativeUtf8().cast<Char>());
    return Bone.fromPointer(result);
  }

  ArraySlot get slots {
    final result = _bindings.spine_skeleton_get_slots(_ptr);
    return ArraySlot.fromPointer(result);
  }

  Slot findSlot(String slotName) {
    final result = _bindings.spine_skeleton_find_slot(_ptr, slotName.toNativeUtf8().cast<Char>());
    return Slot.fromPointer(result);
  }

  ArraySlot get drawOrder {
    final result = _bindings.spine_skeleton_get_draw_order(_ptr);
    return ArraySlot.fromPointer(result);
  }

  Skin get skin {
    final result = _bindings.spine_skeleton_get_skin(_ptr);
    return Skin.fromPointer(result);
  }

  void setAttachment(String slotName, String attachmentName) {
    _bindings.spine_skeleton_set_attachment(_ptr, slotName.toNativeUtf8().cast<Char>(), attachmentName.toNativeUtf8().cast<Char>());
  }

  ArrayConstraint get constraints {
    final result = _bindings.spine_skeleton_get_constraints(_ptr);
    return ArrayConstraint.fromPointer(result);
  }

  ArrayPhysicsConstraint get physicsConstraints {
    final result = _bindings.spine_skeleton_get_physics_constraints(_ptr);
    return ArrayPhysicsConstraint.fromPointer(result);
  }

  Color get color {
    final result = _bindings.spine_skeleton_get_color(_ptr);
    return Color.fromPointer(result);
  }

  double get scaleX {
    final result = _bindings.spine_skeleton_get_scale_x(_ptr);
    return result;
  }

  set scaleX(double value) {
    _bindings.spine_skeleton_set_scale_x(_ptr, value);
  }

  double get scaleY {
    final result = _bindings.spine_skeleton_get_scale_y(_ptr);
    return result;
  }

  set scaleY(double value) {
    _bindings.spine_skeleton_set_scale_y(_ptr, value);
  }

  void setScale(double scaleX, double scaleY) {
    _bindings.spine_skeleton_set_scale(_ptr, scaleX, scaleY);
  }

  double get x {
    final result = _bindings.spine_skeleton_get_x(_ptr);
    return result;
  }

  set x(double value) {
    _bindings.spine_skeleton_set_x(_ptr, value);
  }

  double get y {
    final result = _bindings.spine_skeleton_get_y(_ptr);
    return result;
  }

  set y(double value) {
    _bindings.spine_skeleton_set_y(_ptr, value);
  }

  void setPosition(double x, double y) {
    _bindings.spine_skeleton_set_position(_ptr, x, y);
  }

  double get windX {
    final result = _bindings.spine_skeleton_get_wind_x(_ptr);
    return result;
  }

  set windX(double value) {
    _bindings.spine_skeleton_set_wind_x(_ptr, value);
  }

  double get windY {
    final result = _bindings.spine_skeleton_get_wind_y(_ptr);
    return result;
  }

  set windY(double value) {
    _bindings.spine_skeleton_set_wind_y(_ptr, value);
  }

  double get gravityX {
    final result = _bindings.spine_skeleton_get_gravity_x(_ptr);
    return result;
  }

  set gravityX(double value) {
    _bindings.spine_skeleton_set_gravity_x(_ptr, value);
  }

  double get gravityY {
    final result = _bindings.spine_skeleton_get_gravity_y(_ptr);
    return result;
  }

  set gravityY(double value) {
    _bindings.spine_skeleton_set_gravity_y(_ptr, value);
  }

  void physicsTranslate(double x, double y) {
    _bindings.spine_skeleton_physics_translate(_ptr, x, y);
  }

  void physicsRotate(double x, double y, double degrees) {
    _bindings.spine_skeleton_physics_rotate(_ptr, x, y, degrees);
  }

  double get time {
    final result = _bindings.spine_skeleton_get_time(_ptr);
    return result;
  }

  set time(double value) {
    _bindings.spine_skeleton_set_time(_ptr, value);
  }

  void update(double delta) {
    _bindings.spine_skeleton_update(_ptr, delta);
  }

  void updateWorldTransform1(Physics physics) {
    _bindings.spine_skeleton_update_world_transform_1(_ptr, physics.value);
  }

  void updateWorldTransform2(Physics physics, BonePose parent) {
    _bindings.spine_skeleton_update_world_transform_2(_ptr, physics.value, parent.nativePtr.cast());
  }

  set skin1(String value) {
    _bindings.spine_skeleton_set_skin_1(_ptr, value.toNativeUtf8().cast<Char>());
  }

  set skin2(Skin value) {
    _bindings.spine_skeleton_set_skin_2(_ptr, value.nativePtr.cast());
  }

  Attachment getAttachment1(String slotName, String attachmentName) {
    final result = _bindings.spine_skeleton_get_attachment_1(_ptr, slotName.toNativeUtf8().cast<Char>(), attachmentName.toNativeUtf8().cast<Char>());
    return Attachment.fromPointer(result);
  }

  Attachment getAttachment2(int slotIndex, String attachmentName) {
    final result = _bindings.spine_skeleton_get_attachment_2(_ptr, slotIndex, attachmentName.toNativeUtf8().cast<Char>());
    return Attachment.fromPointer(result);
  }

  set color1(Color value) {
    _bindings.spine_skeleton_set_color_1(_ptr, value.nativePtr.cast());
  }

  void setColor2(double r, double g, double b, double a) {
    _bindings.spine_skeleton_set_color_2(_ptr, r, g, b, a);
  }

  void dispose() {
    _bindings.spine_skeleton_dispose(_ptr);
  }
}