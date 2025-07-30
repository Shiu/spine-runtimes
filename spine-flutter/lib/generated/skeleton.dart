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
import 'package:universal_ffi/ffi_utils.dart';
import 'spine_dart_bindings_generated.dart';
import '../spine_bindings.dart';
import 'arrays.dart';
import 'attachment.dart';
import 'bone.dart';
import 'bounding_box_attachment.dart';
import 'clipping_attachment.dart';
import 'color.dart';
import 'mesh_attachment.dart';
import 'path_attachment.dart';
import 'physics.dart';
import 'point_attachment.dart';
import 'posed.dart';
import 'region_attachment.dart';
import 'skeleton_data.dart';
import 'skin.dart';
import 'slot.dart';

/// Skeleton wrapper
class Skeleton {
  final Pointer<spine_skeleton_wrapper> _ptr;

  Skeleton.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory Skeleton(SkeletonData skeletonData) {
    final ptr = SpineBindings.bindings.spine_skeleton_create(skeletonData.nativePtr.cast());
    return Skeleton.fromPointer(ptr);
  }

  void dispose() {
    SpineBindings.bindings.spine_skeleton_dispose(_ptr);
  }

  void updateCache() {
    SpineBindings.bindings.spine_skeleton_update_cache(_ptr);
  }

  void printUpdateCache() {
    SpineBindings.bindings.spine_skeleton_print_update_cache(_ptr);
  }

  void constrained(Posed object) {
    SpineBindings.bindings.spine_skeleton_constrained(_ptr, object.nativePtr.cast());
  }

  void sortBone(Bone? bone) {
    SpineBindings.bindings.spine_skeleton_sort_bone(_ptr, bone?.nativePtr.cast() ?? Pointer.fromAddress(0));
  }

  static void sortReset(ArrayBone bones) {
    SpineBindings.bindings.spine_skeleton_sort_reset(bones.nativePtr.cast());
  }

  void updateWorldTransform(Physics physics) {
    SpineBindings.bindings.spine_skeleton_update_world_transform(_ptr, physics.value);
  }

  void setupPose() {
    SpineBindings.bindings.spine_skeleton_setup_pose(_ptr);
  }

  void setupPoseBones() {
    SpineBindings.bindings.spine_skeleton_setup_pose_bones(_ptr);
  }

  void setupPoseSlots() {
    SpineBindings.bindings.spine_skeleton_setup_pose_slots(_ptr);
  }

  SkeletonData get data {
    final result = SpineBindings.bindings.spine_skeleton_get_data(_ptr);
    return SkeletonData.fromPointer(result);
  }

  ArrayBone get bones {
    final result = SpineBindings.bindings.spine_skeleton_get_bones(_ptr);
    return ArrayBone.fromPointer(result);
  }

  ArrayUpdate get updateCacheList {
    final result = SpineBindings.bindings.spine_skeleton_get_update_cache(_ptr);
    return ArrayUpdate.fromPointer(result);
  }

  Bone? get rootBone {
    final result = SpineBindings.bindings.spine_skeleton_get_root_bone(_ptr);
    return result.address == 0 ? null : Bone.fromPointer(result);
  }

  Bone? findBone(String boneName) {
    final result = SpineBindings.bindings.spine_skeleton_find_bone(_ptr, boneName.toNativeUtf8().cast<Char>());
    return result.address == 0 ? null : Bone.fromPointer(result);
  }

  ArraySlot get slots {
    final result = SpineBindings.bindings.spine_skeleton_get_slots(_ptr);
    return ArraySlot.fromPointer(result);
  }

  Slot? findSlot(String slotName) {
    final result = SpineBindings.bindings.spine_skeleton_find_slot(_ptr, slotName.toNativeUtf8().cast<Char>());
    return result.address == 0 ? null : Slot.fromPointer(result);
  }

  ArraySlot get drawOrder {
    final result = SpineBindings.bindings.spine_skeleton_get_draw_order(_ptr);
    return ArraySlot.fromPointer(result);
  }

  Skin? get skin {
    final result = SpineBindings.bindings.spine_skeleton_get_skin(_ptr);
    return result.address == 0 ? null : Skin.fromPointer(result);
  }

  void setAttachment(String slotName, String attachmentName) {
    SpineBindings.bindings.spine_skeleton_set_attachment(
        _ptr, slotName.toNativeUtf8().cast<Char>(), attachmentName.toNativeUtf8().cast<Char>());
  }

  ArrayConstraint get constraints {
    final result = SpineBindings.bindings.spine_skeleton_get_constraints(_ptr);
    return ArrayConstraint.fromPointer(result);
  }

  ArrayPhysicsConstraint get physicsConstraints {
    final result = SpineBindings.bindings.spine_skeleton_get_physics_constraints(_ptr);
    return ArrayPhysicsConstraint.fromPointer(result);
  }

  Color get color {
    final result = SpineBindings.bindings.spine_skeleton_get_color(_ptr);
    return Color.fromPointer(result);
  }

  double get scaleX {
    final result = SpineBindings.bindings.spine_skeleton_get_scale_x(_ptr);
    return result;
  }

  set scaleX(double value) {
    SpineBindings.bindings.spine_skeleton_set_scale_x(_ptr, value);
  }

  double get scaleY {
    final result = SpineBindings.bindings.spine_skeleton_get_scale_y(_ptr);
    return result;
  }

  set scaleY(double value) {
    SpineBindings.bindings.spine_skeleton_set_scale_y(_ptr, value);
  }

  void setScale(double scaleX, double scaleY) {
    SpineBindings.bindings.spine_skeleton_set_scale(_ptr, scaleX, scaleY);
  }

  double get x {
    final result = SpineBindings.bindings.spine_skeleton_get_x(_ptr);
    return result;
  }

  set x(double value) {
    SpineBindings.bindings.spine_skeleton_set_x(_ptr, value);
  }

  double get y {
    final result = SpineBindings.bindings.spine_skeleton_get_y(_ptr);
    return result;
  }

  set y(double value) {
    SpineBindings.bindings.spine_skeleton_set_y(_ptr, value);
  }

  void setPosition(double x, double y) {
    SpineBindings.bindings.spine_skeleton_set_position(_ptr, x, y);
  }

  double get windX {
    final result = SpineBindings.bindings.spine_skeleton_get_wind_x(_ptr);
    return result;
  }

  set windX(double value) {
    SpineBindings.bindings.spine_skeleton_set_wind_x(_ptr, value);
  }

  double get windY {
    final result = SpineBindings.bindings.spine_skeleton_get_wind_y(_ptr);
    return result;
  }

  set windY(double value) {
    SpineBindings.bindings.spine_skeleton_set_wind_y(_ptr, value);
  }

  double get gravityX {
    final result = SpineBindings.bindings.spine_skeleton_get_gravity_x(_ptr);
    return result;
  }

  set gravityX(double value) {
    SpineBindings.bindings.spine_skeleton_set_gravity_x(_ptr, value);
  }

  double get gravityY {
    final result = SpineBindings.bindings.spine_skeleton_get_gravity_y(_ptr);
    return result;
  }

  set gravityY(double value) {
    SpineBindings.bindings.spine_skeleton_set_gravity_y(_ptr, value);
  }

  void physicsTranslate(double x, double y) {
    SpineBindings.bindings.spine_skeleton_physics_translate(_ptr, x, y);
  }

  void physicsRotate(double x, double y, double degrees) {
    SpineBindings.bindings.spine_skeleton_physics_rotate(_ptr, x, y, degrees);
  }

  double get time {
    final result = SpineBindings.bindings.spine_skeleton_get_time(_ptr);
    return result;
  }

  set time(double value) {
    SpineBindings.bindings.spine_skeleton_set_time(_ptr, value);
  }

  void update(double delta) {
    SpineBindings.bindings.spine_skeleton_update(_ptr, delta);
  }

  void setSkin(String skinName) {
    SpineBindings.bindings.spine_skeleton_set_skin_1(_ptr, skinName.toNativeUtf8().cast<Char>());
  }

  void setSkin2(Skin? newSkin) {
    SpineBindings.bindings.spine_skeleton_set_skin_2(_ptr, newSkin?.nativePtr.cast() ?? Pointer.fromAddress(0));
  }

  Attachment? getAttachment(String slotName, String attachmentName) {
    final result = SpineBindings.bindings.spine_skeleton_get_attachment_1(
        _ptr, slotName.toNativeUtf8().cast<Char>(), attachmentName.toNativeUtf8().cast<Char>());
    if (result.address == 0) return null;
    final rtti = SpineBindings.bindings.spine_attachment_get_rtti(result);
    final className = SpineBindings.bindings.spine_rtti_get_class_name(rtti).cast<Utf8>().toDartString();
    switch (className) {
      case 'spine_bounding_box_attachment':
        return BoundingBoxAttachment.fromPointer(result.cast());
      case 'spine_clipping_attachment':
        return ClippingAttachment.fromPointer(result.cast());
      case 'spine_mesh_attachment':
        return MeshAttachment.fromPointer(result.cast());
      case 'spine_path_attachment':
        return PathAttachment.fromPointer(result.cast());
      case 'spine_point_attachment':
        return PointAttachment.fromPointer(result.cast());
      case 'spine_region_attachment':
        return RegionAttachment.fromPointer(result.cast());
      default:
        throw UnsupportedError('Unknown concrete type: $className for abstract class Attachment');
    }
  }

  Attachment? getAttachment2(int slotIndex, String attachmentName) {
    final result = SpineBindings.bindings
        .spine_skeleton_get_attachment_2(_ptr, slotIndex, attachmentName.toNativeUtf8().cast<Char>());
    if (result.address == 0) return null;
    final rtti = SpineBindings.bindings.spine_attachment_get_rtti(result);
    final className = SpineBindings.bindings.spine_rtti_get_class_name(rtti).cast<Utf8>().toDartString();
    switch (className) {
      case 'spine_bounding_box_attachment':
        return BoundingBoxAttachment.fromPointer(result.cast());
      case 'spine_clipping_attachment':
        return ClippingAttachment.fromPointer(result.cast());
      case 'spine_mesh_attachment':
        return MeshAttachment.fromPointer(result.cast());
      case 'spine_path_attachment':
        return PathAttachment.fromPointer(result.cast());
      case 'spine_point_attachment':
        return PointAttachment.fromPointer(result.cast());
      case 'spine_region_attachment':
        return RegionAttachment.fromPointer(result.cast());
      default:
        throw UnsupportedError('Unknown concrete type: $className for abstract class Attachment');
    }
  }

  set setColor(Color value) {
    SpineBindings.bindings.spine_skeleton_set_color_1(_ptr, value.nativePtr.cast());
  }

  void setColor2(double r, double g, double b, double a) {
    SpineBindings.bindings.spine_skeleton_set_color_2(_ptr, r, g, b, a);
  }
}
