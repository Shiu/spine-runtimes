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
import 'rtti.dart';
import 'arrays.dart';
import 'bone_data.dart';
import 'constraint.dart';
import 'constraint_data.dart';
import 'ik_constraint.dart';
import 'ik_constraint_pose.dart';
import 'path_constraint.dart';
import 'physics_constraint.dart';
import 'posed_data.dart';
import 'skeleton.dart';
import 'slider.dart';
import 'transform_constraint.dart';

/// IkConstraintData wrapper
class IkConstraintData extends PosedData implements ConstraintData {
  final Pointer<spine_ik_constraint_data_wrapper> _ptr;

  IkConstraintData.fromPointer(this._ptr) : super.fromPointer(_ptr.cast());

  /// Get the native pointer for FFI calls
  @override
  Pointer get nativePtr => _ptr;

  factory IkConstraintData(String name) {
    final ptr = SpineBindings.bindings.spine_ik_constraint_data_create(name.toNativeUtf8().cast<Char>());
    return IkConstraintData.fromPointer(ptr);
  }

  @override
  void dispose() {
    SpineBindings.bindings.spine_ik_constraint_data_dispose(_ptr);
  }

  @override
  Rtti get rtti {
    final result = SpineBindings.bindings.spine_ik_constraint_data_get_rtti(_ptr);
    return Rtti.fromPointer(result);
  }

  @override
  Constraint createMethod(Skeleton skeleton) {
    final result = SpineBindings.bindings.spine_ik_constraint_data_create_method(_ptr, skeleton.nativePtr.cast());
    final rtti = SpineBindings.bindings.spine_constraint_get_rtti(result);
    final className = SpineBindings.bindings.spine_rtti_get_class_name(rtti).cast<Utf8>().toDartString();
    switch (className) {
      case 'spine_ik_constraint':
        return IkConstraint.fromPointer(result.cast());
      case 'spine_path_constraint':
        return PathConstraint.fromPointer(result.cast());
      case 'spine_physics_constraint':
        return PhysicsConstraint.fromPointer(result.cast());
      case 'spine_slider':
        return Slider.fromPointer(result.cast());
      case 'spine_transform_constraint':
        return TransformConstraint.fromPointer(result.cast());
      default:
        throw UnsupportedError('Unknown concrete type: $className for abstract class Constraint');
    }
  }

  ArrayBoneData get bones {
    final result = SpineBindings.bindings.spine_ik_constraint_data_get_bones(_ptr);
    return ArrayBoneData.fromPointer(result);
  }

  BoneData get target {
    final result = SpineBindings.bindings.spine_ik_constraint_data_get_target(_ptr);
    return BoneData.fromPointer(result);
  }

  set target(BoneData value) {
    SpineBindings.bindings.spine_ik_constraint_data_set_target(_ptr, value.nativePtr.cast());
  }

  bool get uniform {
    final result = SpineBindings.bindings.spine_ik_constraint_data_get_uniform(_ptr);
    return result;
  }

  set uniform(bool value) {
    SpineBindings.bindings.spine_ik_constraint_data_set_uniform(_ptr, value);
  }

  IkConstraintPose get setupPose {
    final result = SpineBindings.bindings.spine_ik_constraint_data_get_setup_pose(_ptr);
    return IkConstraintPose.fromPointer(result);
  }

  static Rtti rttiStatic() {
    final result = SpineBindings.bindings.spine_ik_constraint_data_rtti();
    return Rtti.fromPointer(result);
  }
}
