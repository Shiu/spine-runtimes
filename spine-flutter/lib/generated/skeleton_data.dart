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
import 'bone_data.dart';
import 'slot_data.dart';
import 'skin.dart';
import 'event_data.dart';
import 'animation.dart';
import 'arrays.dart';

/// SkeletonData wrapper
class SkeletonData implements Finalizable {
  static late SpineFlutterBindings _bindings;
  final Pointer<spine_skeleton_data_wrapper> _ptr;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  SkeletonData.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory SkeletonData() {
    final ptr = _bindings.spine_skeleton_data_create();
    return SkeletonData.fromPointer(ptr);
  }

  BoneData findBone(String boneName) {
    final result = _bindings.spine_skeleton_data_find_bone(_ptr, boneName.toNativeUtf8().cast<Char>());
    return BoneData.fromPointer(result);
  }

  SlotData findSlot(String slotName) {
    final result = _bindings.spine_skeleton_data_find_slot(_ptr, slotName.toNativeUtf8().cast<Char>());
    return SlotData.fromPointer(result);
  }

  Skin findSkin(String skinName) {
    final result = _bindings.spine_skeleton_data_find_skin(_ptr, skinName.toNativeUtf8().cast<Char>());
    return Skin.fromPointer(result);
  }

  EventData findEvent(String eventDataName) {
    final result = _bindings.spine_skeleton_data_find_event(_ptr, eventDataName.toNativeUtf8().cast<Char>());
    return EventData.fromPointer(result);
  }

  Animation findAnimation(String animationName) {
    final result = _bindings.spine_skeleton_data_find_animation(_ptr, animationName.toNativeUtf8().cast<Char>());
    return Animation.fromPointer(result);
  }

  String get name {
    final result = _bindings.spine_skeleton_data_get_name(_ptr);
    return result.cast<Utf8>().toDartString();
  }

  set name(String value) {
    _bindings.spine_skeleton_data_set_name(_ptr, value.toNativeUtf8().cast<Char>());
  }

  ArrayBoneData get bones {
    final result = _bindings.spine_skeleton_data_get_bones(_ptr);
    return ArrayBoneData.fromPointer(result);
  }

  ArraySlotData get slots {
    final result = _bindings.spine_skeleton_data_get_slots(_ptr);
    return ArraySlotData.fromPointer(result);
  }

  ArraySkin get skins {
    final result = _bindings.spine_skeleton_data_get_skins(_ptr);
    return ArraySkin.fromPointer(result);
  }

  Skin get defaultSkin {
    final result = _bindings.spine_skeleton_data_get_default_skin(_ptr);
    return Skin.fromPointer(result);
  }

  set defaultSkin(Skin value) {
    _bindings.spine_skeleton_data_set_default_skin(_ptr, value.nativePtr.cast());
  }

  ArrayEventData get events {
    final result = _bindings.spine_skeleton_data_get_events(_ptr);
    return ArrayEventData.fromPointer(result);
  }

  ArrayAnimation get animations {
    final result = _bindings.spine_skeleton_data_get_animations(_ptr);
    return ArrayAnimation.fromPointer(result);
  }

  ArrayConstraintData get constraints {
    final result = _bindings.spine_skeleton_data_get_constraints(_ptr);
    return ArrayConstraintData.fromPointer(result);
  }

  double get x {
    final result = _bindings.spine_skeleton_data_get_x(_ptr);
    return result;
  }

  set x(double value) {
    _bindings.spine_skeleton_data_set_x(_ptr, value);
  }

  double get y {
    final result = _bindings.spine_skeleton_data_get_y(_ptr);
    return result;
  }

  set y(double value) {
    _bindings.spine_skeleton_data_set_y(_ptr, value);
  }

  double get width {
    final result = _bindings.spine_skeleton_data_get_width(_ptr);
    return result;
  }

  set width(double value) {
    _bindings.spine_skeleton_data_set_width(_ptr, value);
  }

  double get height {
    final result = _bindings.spine_skeleton_data_get_height(_ptr);
    return result;
  }

  set height(double value) {
    _bindings.spine_skeleton_data_set_height(_ptr, value);
  }

  double get referenceScale {
    final result = _bindings.spine_skeleton_data_get_reference_scale(_ptr);
    return result;
  }

  set referenceScale(double value) {
    _bindings.spine_skeleton_data_set_reference_scale(_ptr, value);
  }

  String get version {
    final result = _bindings.spine_skeleton_data_get_version(_ptr);
    return result.cast<Utf8>().toDartString();
  }

  set version(String value) {
    _bindings.spine_skeleton_data_set_version(_ptr, value.toNativeUtf8().cast<Char>());
  }

  String get hash {
    final result = _bindings.spine_skeleton_data_get_hash(_ptr);
    return result.cast<Utf8>().toDartString();
  }

  set hash(String value) {
    _bindings.spine_skeleton_data_set_hash(_ptr, value.toNativeUtf8().cast<Char>());
  }

  String get imagesPath {
    final result = _bindings.spine_skeleton_data_get_images_path(_ptr);
    return result.cast<Utf8>().toDartString();
  }

  set imagesPath(String value) {
    _bindings.spine_skeleton_data_set_images_path(_ptr, value.toNativeUtf8().cast<Char>());
  }

  String get audioPath {
    final result = _bindings.spine_skeleton_data_get_audio_path(_ptr);
    return result.cast<Utf8>().toDartString();
  }

  set audioPath(String value) {
    _bindings.spine_skeleton_data_set_audio_path(_ptr, value.toNativeUtf8().cast<Char>());
  }

  double get fps {
    final result = _bindings.spine_skeleton_data_get_fps(_ptr);
    return result;
  }

  set fps(double value) {
    _bindings.spine_skeleton_data_set_fps(_ptr, value);
  }

  void dispose() {
    _bindings.spine_skeleton_data_dispose(_ptr);
  }
}