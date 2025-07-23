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
import 'rtti.dart';
import 'constraint.dart';
import 'skeleton.dart';
import 'slot_data.dart';
import 'position_mode.dart';
import 'spacing_mode.dart';
import 'rotate_mode.dart';
import 'path_constraint_pose.dart';
import 'arrays.dart';

/// PathConstraintData wrapper
class PathConstraintData implements Finalizable {
  static late SpineFlutterBindings _bindings;
  final Pointer<spine_path_constraint_data_wrapper> _ptr;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  PathConstraintData.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory PathConstraintData(String name) {
    final ptr = _bindings.spine_path_constraint_data_create(name.toNativeUtf8().cast<Char>());
    return PathConstraintData.fromPointer(ptr);
  }

  Rtti get rtti {
    final result = _bindings.spine_path_constraint_data_get_rtti(_ptr);
    return Rtti.fromPointer(result);
  }

  Constraint createMethod(Skeleton skeleton) {
    final result = _bindings.spine_path_constraint_data_create_method(_ptr, skeleton.nativePtr.cast());
    return Constraint.fromPointer(result);
  }

  ArrayBoneData get bones {
    final result = _bindings.spine_path_constraint_data_get_bones(_ptr);
    return ArrayBoneData.fromPointer(result);
  }

  SlotData get slot {
    final result = _bindings.spine_path_constraint_data_get_slot(_ptr);
    return SlotData.fromPointer(result);
  }

  set slot(SlotData value) {
    _bindings.spine_path_constraint_data_set_slot(_ptr, value.nativePtr.cast());
  }

  PositionMode get positionMode {
    final result = _bindings.spine_path_constraint_data_get_position_mode(_ptr);
    return PositionMode.fromValue(result);
  }

  set positionMode(PositionMode value) {
    _bindings.spine_path_constraint_data_set_position_mode(_ptr, value.value);
  }

  SpacingMode get spacingMode {
    final result = _bindings.spine_path_constraint_data_get_spacing_mode(_ptr);
    return SpacingMode.fromValue(result);
  }

  set spacingMode(SpacingMode value) {
    _bindings.spine_path_constraint_data_set_spacing_mode(_ptr, value.value);
  }

  RotateMode get rotateMode {
    final result = _bindings.spine_path_constraint_data_get_rotate_mode(_ptr);
    return RotateMode.fromValue(result);
  }

  set rotateMode(RotateMode value) {
    _bindings.spine_path_constraint_data_set_rotate_mode(_ptr, value.value);
  }

  double get offsetRotation {
    final result = _bindings.spine_path_constraint_data_get_offset_rotation(_ptr);
    return result;
  }

  set offsetRotation(double value) {
    _bindings.spine_path_constraint_data_set_offset_rotation(_ptr, value);
  }

  String get name {
    final result = _bindings.spine_path_constraint_data_get_name(_ptr);
    return result.cast<Utf8>().toDartString();
  }

  bool get skinRequired {
    final result = _bindings.spine_path_constraint_data_get_skin_required(_ptr);
    return result;
  }

  PathConstraintPose get setupPose {
    final result = _bindings.spine_path_constraint_data_get_setup_pose(_ptr);
    return PathConstraintPose.fromPointer(result);
  }

  set skinRequired(bool value) {
    _bindings.spine_path_constraint_data_set_skin_required(_ptr, value);
  }

  static Rtti rttiStatic() {
    final result = _bindings.spine_path_constraint_data_rtti();
    return Rtti.fromPointer(result);
  }

  void dispose() {
    _bindings.spine_path_constraint_data_dispose(_ptr);
  }
}