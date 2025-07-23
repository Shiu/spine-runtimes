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
import 'bone_data.dart';
import 'physics_constraint_pose.dart';

/// PhysicsConstraintData wrapper
class PhysicsConstraintData implements Finalizable {
  static late SpineFlutterBindings _bindings;
  final Pointer<spine_physics_constraint_data_wrapper> _ptr;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  PhysicsConstraintData.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory PhysicsConstraintData(String name) {
    final ptr = _bindings.spine_physics_constraint_data_create(name.toNativeUtf8().cast<Char>());
    return PhysicsConstraintData.fromPointer(ptr);
  }

  Rtti get rtti {
    final result = _bindings.spine_physics_constraint_data_get_rtti(_ptr);
    return Rtti.fromPointer(result);
  }

  Constraint createMethod(Skeleton skeleton) {
    final result = _bindings.spine_physics_constraint_data_create_method(_ptr, skeleton.nativePtr.cast());
    return Constraint.fromPointer(result);
  }

  BoneData get bone {
    final result = _bindings.spine_physics_constraint_data_get_bone(_ptr);
    return BoneData.fromPointer(result);
  }

  set bone(BoneData value) {
    _bindings.spine_physics_constraint_data_set_bone(_ptr, value.nativePtr.cast());
  }

  double get step {
    final result = _bindings.spine_physics_constraint_data_get_step(_ptr);
    return result;
  }

  set step(double value) {
    _bindings.spine_physics_constraint_data_set_step(_ptr, value);
  }

  double get x {
    final result = _bindings.spine_physics_constraint_data_get_x(_ptr);
    return result;
  }

  set x(double value) {
    _bindings.spine_physics_constraint_data_set_x(_ptr, value);
  }

  double get y {
    final result = _bindings.spine_physics_constraint_data_get_y(_ptr);
    return result;
  }

  set y(double value) {
    _bindings.spine_physics_constraint_data_set_y(_ptr, value);
  }

  double get rotate {
    final result = _bindings.spine_physics_constraint_data_get_rotate(_ptr);
    return result;
  }

  set rotate(double value) {
    _bindings.spine_physics_constraint_data_set_rotate(_ptr, value);
  }

  double get scaleX {
    final result = _bindings.spine_physics_constraint_data_get_scale_x(_ptr);
    return result;
  }

  set scaleX(double value) {
    _bindings.spine_physics_constraint_data_set_scale_x(_ptr, value);
  }

  double get shearX {
    final result = _bindings.spine_physics_constraint_data_get_shear_x(_ptr);
    return result;
  }

  set shearX(double value) {
    _bindings.spine_physics_constraint_data_set_shear_x(_ptr, value);
  }

  double get limit {
    final result = _bindings.spine_physics_constraint_data_get_limit(_ptr);
    return result;
  }

  set limit(double value) {
    _bindings.spine_physics_constraint_data_set_limit(_ptr, value);
  }

  bool get inertiaGlobal {
    final result = _bindings.spine_physics_constraint_data_get_inertia_global(_ptr);
    return result;
  }

  set inertiaGlobal(bool value) {
    _bindings.spine_physics_constraint_data_set_inertia_global(_ptr, value);
  }

  bool get strengthGlobal {
    final result = _bindings.spine_physics_constraint_data_get_strength_global(_ptr);
    return result;
  }

  set strengthGlobal(bool value) {
    _bindings.spine_physics_constraint_data_set_strength_global(_ptr, value);
  }

  bool get dampingGlobal {
    final result = _bindings.spine_physics_constraint_data_get_damping_global(_ptr);
    return result;
  }

  set dampingGlobal(bool value) {
    _bindings.spine_physics_constraint_data_set_damping_global(_ptr, value);
  }

  bool get massGlobal {
    final result = _bindings.spine_physics_constraint_data_get_mass_global(_ptr);
    return result;
  }

  set massGlobal(bool value) {
    _bindings.spine_physics_constraint_data_set_mass_global(_ptr, value);
  }

  bool get windGlobal {
    final result = _bindings.spine_physics_constraint_data_get_wind_global(_ptr);
    return result;
  }

  set windGlobal(bool value) {
    _bindings.spine_physics_constraint_data_set_wind_global(_ptr, value);
  }

  bool get gravityGlobal {
    final result = _bindings.spine_physics_constraint_data_get_gravity_global(_ptr);
    return result;
  }

  set gravityGlobal(bool value) {
    _bindings.spine_physics_constraint_data_set_gravity_global(_ptr, value);
  }

  bool get mixGlobal {
    final result = _bindings.spine_physics_constraint_data_get_mix_global(_ptr);
    return result;
  }

  set mixGlobal(bool value) {
    _bindings.spine_physics_constraint_data_set_mix_global(_ptr, value);
  }

  String get name {
    final result = _bindings.spine_physics_constraint_data_get_name(_ptr);
    return result.cast<Utf8>().toDartString();
  }

  bool get skinRequired {
    final result = _bindings.spine_physics_constraint_data_get_skin_required(_ptr);
    return result;
  }

  PhysicsConstraintPose get setupPose {
    final result = _bindings.spine_physics_constraint_data_get_setup_pose(_ptr);
    return PhysicsConstraintPose.fromPointer(result);
  }

  set skinRequired(bool value) {
    _bindings.spine_physics_constraint_data_set_skin_required(_ptr, value);
  }

  static Rtti rttiStatic() {
    final result = _bindings.spine_physics_constraint_data_rtti();
    return Rtti.fromPointer(result);
  }

  void dispose() {
    _bindings.spine_physics_constraint_data_dispose(_ptr);
  }
}