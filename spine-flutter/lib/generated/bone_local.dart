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
import 'inherit.dart';

/// BoneLocal wrapper
class BoneLocal implements Finalizable {
  static late SpineFlutterBindings _bindings;
  final Pointer<spine_bone_local_wrapper> _ptr;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  BoneLocal.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory BoneLocal() {
    final ptr = _bindings.spine_bone_local_create();
    return BoneLocal.fromPointer(ptr);
  }

  void set(BoneLocal pose) {
    _bindings.spine_bone_local_set(_ptr, pose.nativePtr.cast());
  }

  double get x {
    final result = _bindings.spine_bone_local_get_x(_ptr);
    return result;
  }

  set x(double value) {
    _bindings.spine_bone_local_set_x(_ptr, value);
  }

  double get y {
    final result = _bindings.spine_bone_local_get_y(_ptr);
    return result;
  }

  set y(double value) {
    _bindings.spine_bone_local_set_y(_ptr, value);
  }

  void setPosition(double x, double y) {
    _bindings.spine_bone_local_set_position(_ptr, x, y);
  }

  double get rotation {
    final result = _bindings.spine_bone_local_get_rotation(_ptr);
    return result;
  }

  set rotation(double value) {
    _bindings.spine_bone_local_set_rotation(_ptr, value);
  }

  double get scaleX {
    final result = _bindings.spine_bone_local_get_scale_x(_ptr);
    return result;
  }

  set scaleX(double value) {
    _bindings.spine_bone_local_set_scale_x(_ptr, value);
  }

  double get scaleY {
    final result = _bindings.spine_bone_local_get_scale_y(_ptr);
    return result;
  }

  set scaleY(double value) {
    _bindings.spine_bone_local_set_scale_y(_ptr, value);
  }

  double get shearX {
    final result = _bindings.spine_bone_local_get_shear_x(_ptr);
    return result;
  }

  set shearX(double value) {
    _bindings.spine_bone_local_set_shear_x(_ptr, value);
  }

  double get shearY {
    final result = _bindings.spine_bone_local_get_shear_y(_ptr);
    return result;
  }

  set shearY(double value) {
    _bindings.spine_bone_local_set_shear_y(_ptr, value);
  }

  Inherit get inherit {
    final result = _bindings.spine_bone_local_get_inherit(_ptr);
    return Inherit.fromValue(result);
  }

  set inherit(Inherit value) {
    _bindings.spine_bone_local_set_inherit(_ptr, value.value);
  }

  void setScale1(double scaleX, double scaleY) {
    _bindings.spine_bone_local_set_scale_1(_ptr, scaleX, scaleY);
  }

  set scale2(double value) {
    _bindings.spine_bone_local_set_scale_2(_ptr, value);
  }

  void dispose() {
    _bindings.spine_bone_local_dispose(_ptr);
  }
}