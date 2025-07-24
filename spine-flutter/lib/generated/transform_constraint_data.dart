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
import 'package:ffi/ffi.dart';
import 'spine_flutter_bindings_generated.dart';
import '../spine_bindings.dart';
import 'rtti.dart';
import 'constraint.dart';
import 'skeleton.dart';
import 'bone_data.dart';
import 'transform_constraint_pose.dart';
import 'arrays.dart';

/// TransformConstraintData wrapper
class TransformConstraintData implements Finalizable {
  final Pointer<spine_transform_constraint_data_wrapper> _ptr;

  TransformConstraintData.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory TransformConstraintData(String name) {
    final ptr = SpineBindings.bindings.spine_transform_constraint_data_create(name.toNativeUtf8().cast<Char>());
    return TransformConstraintData.fromPointer(ptr);
  }

  Rtti get rtti {
    final result = SpineBindings.bindings.spine_transform_constraint_data_get_rtti(_ptr);
    return Rtti.fromPointer(result);
  }

  Constraint createMethod(Skeleton skeleton) {
    final result = SpineBindings.bindings.spine_transform_constraint_data_create_method(_ptr, skeleton.nativePtr.cast());
    throw UnsupportedError('Cannot instantiate abstract class Constraint from pointer - no concrete subclasses found');
  }

  ArrayBoneData get bones {
    final result = SpineBindings.bindings.spine_transform_constraint_data_get_bones(_ptr);
    return ArrayBoneData.fromPointer(result);
  }

  BoneData get source {
    final result = SpineBindings.bindings.spine_transform_constraint_data_get_source(_ptr);
    return BoneData.fromPointer(result);
  }

  set source(BoneData value) {
    SpineBindings.bindings.spine_transform_constraint_data_set_source(_ptr, value.nativePtr.cast());
  }

  double get offsetRotation {
    final result = SpineBindings.bindings.spine_transform_constraint_data_get_offset_rotation(_ptr);
    return result;
  }

  set offsetRotation(double value) {
    SpineBindings.bindings.spine_transform_constraint_data_set_offset_rotation(_ptr, value);
  }

  double get offsetX {
    final result = SpineBindings.bindings.spine_transform_constraint_data_get_offset_x(_ptr);
    return result;
  }

  set offsetX(double value) {
    SpineBindings.bindings.spine_transform_constraint_data_set_offset_x(_ptr, value);
  }

  double get offsetY {
    final result = SpineBindings.bindings.spine_transform_constraint_data_get_offset_y(_ptr);
    return result;
  }

  set offsetY(double value) {
    SpineBindings.bindings.spine_transform_constraint_data_set_offset_y(_ptr, value);
  }

  double get offsetScaleX {
    final result = SpineBindings.bindings.spine_transform_constraint_data_get_offset_scale_x(_ptr);
    return result;
  }

  set offsetScaleX(double value) {
    SpineBindings.bindings.spine_transform_constraint_data_set_offset_scale_x(_ptr, value);
  }

  double get offsetScaleY {
    final result = SpineBindings.bindings.spine_transform_constraint_data_get_offset_scale_y(_ptr);
    return result;
  }

  set offsetScaleY(double value) {
    SpineBindings.bindings.spine_transform_constraint_data_set_offset_scale_y(_ptr, value);
  }

  double get offsetShearY {
    final result = SpineBindings.bindings.spine_transform_constraint_data_get_offset_shear_y(_ptr);
    return result;
  }

  set offsetShearY(double value) {
    SpineBindings.bindings.spine_transform_constraint_data_set_offset_shear_y(_ptr, value);
  }

  bool get localSource {
    final result = SpineBindings.bindings.spine_transform_constraint_data_get_local_source(_ptr);
    return result;
  }

  set localSource(bool value) {
    SpineBindings.bindings.spine_transform_constraint_data_set_local_source(_ptr, value);
  }

  bool get localTarget {
    final result = SpineBindings.bindings.spine_transform_constraint_data_get_local_target(_ptr);
    return result;
  }

  set localTarget(bool value) {
    SpineBindings.bindings.spine_transform_constraint_data_set_local_target(_ptr, value);
  }

  bool get additive {
    final result = SpineBindings.bindings.spine_transform_constraint_data_get_additive(_ptr);
    return result;
  }

  set additive(bool value) {
    SpineBindings.bindings.spine_transform_constraint_data_set_additive(_ptr, value);
  }

  bool get clamp {
    final result = SpineBindings.bindings.spine_transform_constraint_data_get_clamp(_ptr);
    return result;
  }

  set clamp(bool value) {
    SpineBindings.bindings.spine_transform_constraint_data_set_clamp(_ptr, value);
  }

  ArrayFromProperty get properties {
    final result = SpineBindings.bindings.spine_transform_constraint_data_get_properties(_ptr);
    return ArrayFromProperty.fromPointer(result);
  }

  String get name {
    final result = SpineBindings.bindings.spine_transform_constraint_data_get_name(_ptr);
    return result.cast<Utf8>().toDartString();
  }

  bool get skinRequired {
    final result = SpineBindings.bindings.spine_transform_constraint_data_get_skin_required(_ptr);
    return result;
  }

  TransformConstraintPose get setupPose {
    final result = SpineBindings.bindings.spine_transform_constraint_data_get_setup_pose(_ptr);
    return TransformConstraintPose.fromPointer(result);
  }

  set skinRequired(bool value) {
    SpineBindings.bindings.spine_transform_constraint_data_set_skin_required(_ptr, value);
  }

  static Rtti rttiStatic() {
    final result = SpineBindings.bindings.spine_transform_constraint_data_rtti();
    return Rtti.fromPointer(result);
  }

  void dispose() {
    SpineBindings.bindings.spine_transform_constraint_data_dispose(_ptr);
  }
}