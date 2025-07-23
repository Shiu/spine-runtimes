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
import 'animation.dart';
import 'bone_data.dart';
import 'from_property.dart';
import 'slider_pose.dart';

/// SliderData wrapper
class SliderData implements Finalizable {
  static late SpineFlutterBindings _bindings;
  final Pointer<spine_slider_data_wrapper> _ptr;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  SliderData.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory SliderData(String name) {
    final ptr = _bindings.spine_slider_data_create(name.toNativeUtf8().cast<Char>());
    return SliderData.fromPointer(ptr);
  }

  Rtti get rtti {
    final result = _bindings.spine_slider_data_get_rtti(_ptr);
    return Rtti.fromPointer(result);
  }

  Constraint createMethod(Skeleton skeleton) {
    final result = _bindings.spine_slider_data_create_method(_ptr, skeleton.nativePtr.cast());
    return Constraint.fromPointer(result);
  }

  Animation get animation {
    final result = _bindings.spine_slider_data_get_animation(_ptr);
    return Animation.fromPointer(result);
  }

  set animation(Animation value) {
    _bindings.spine_slider_data_set_animation(_ptr, value.nativePtr.cast());
  }

  bool get additive {
    final result = _bindings.spine_slider_data_get_additive(_ptr);
    return result;
  }

  set additive(bool value) {
    _bindings.spine_slider_data_set_additive(_ptr, value);
  }

  bool get loop {
    final result = _bindings.spine_slider_data_get_loop(_ptr);
    return result;
  }

  set loop(bool value) {
    _bindings.spine_slider_data_set_loop(_ptr, value);
  }

  BoneData get bone {
    final result = _bindings.spine_slider_data_get_bone(_ptr);
    return BoneData.fromPointer(result);
  }

  set bone(BoneData value) {
    _bindings.spine_slider_data_set_bone(_ptr, value.nativePtr.cast());
  }

  FromProperty get property {
    final result = _bindings.spine_slider_data_get_property(_ptr);
    return FromProperty.fromPointer(result);
  }

  set property(FromProperty value) {
    _bindings.spine_slider_data_set_property(_ptr, value.nativePtr.cast());
  }

  double get scale {
    final result = _bindings.spine_slider_data_get_scale(_ptr);
    return result;
  }

  set scale(double value) {
    _bindings.spine_slider_data_set_scale(_ptr, value);
  }

  double get offset {
    final result = _bindings.spine_slider_data_get_offset(_ptr);
    return result;
  }

  set offset(double value) {
    _bindings.spine_slider_data_set_offset(_ptr, value);
  }

  bool get local {
    final result = _bindings.spine_slider_data_get_local(_ptr);
    return result;
  }

  set local(bool value) {
    _bindings.spine_slider_data_set_local(_ptr, value);
  }

  String get name {
    final result = _bindings.spine_slider_data_get_name(_ptr);
    return result.cast<Utf8>().toDartString();
  }

  bool get skinRequired {
    final result = _bindings.spine_slider_data_get_skin_required(_ptr);
    return result;
  }

  SliderPose get setupPose {
    final result = _bindings.spine_slider_data_get_setup_pose(_ptr);
    return SliderPose.fromPointer(result);
  }

  set skinRequired(bool value) {
    _bindings.spine_slider_data_set_skin_required(_ptr, value);
  }

  static Rtti rttiStatic() {
    final result = _bindings.spine_slider_data_rtti();
    return Rtti.fromPointer(result);
  }

  void dispose() {
    _bindings.spine_slider_data_dispose(_ptr);
  }
}