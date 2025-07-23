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
import 'bone.dart';
import 'slider_data.dart';
import 'slider_pose.dart';

/// Slider wrapper
class Slider implements Finalizable {
  static late SpineFlutterBindings _bindings;
  final Pointer<spine_slider_wrapper> _ptr;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  Slider.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory Slider(SliderData data, Skeleton skeleton) {
    final ptr = _bindings.spine_slider_create(data.nativePtr.cast(), skeleton.nativePtr.cast());
    return Slider.fromPointer(ptr);
  }

  Rtti get rtti {
    final result = _bindings.spine_slider_get_rtti(_ptr);
    return Rtti.fromPointer(result);
  }

  Slider copy(Skeleton skeleton) {
    final result = _bindings.spine_slider_copy(_ptr, skeleton.nativePtr.cast());
    return Slider.fromPointer(result);
  }

  void update(Skeleton skeleton, Physics physics) {
    _bindings.spine_slider_update(_ptr, skeleton.nativePtr.cast(), physics.value);
  }

  void sort(Skeleton skeleton) {
    _bindings.spine_slider_sort(_ptr, skeleton.nativePtr.cast());
  }

  bool get isSourceActive {
    final result = _bindings.spine_slider_is_source_active(_ptr);
    return result;
  }

  Bone get bone {
    final result = _bindings.spine_slider_get_bone(_ptr);
    return Bone.fromPointer(result);
  }

  set bone(Bone value) {
    _bindings.spine_slider_set_bone(_ptr, value.nativePtr.cast());
  }

  SliderData get data {
    final result = _bindings.spine_slider_get_data(_ptr);
    return SliderData.fromPointer(result);
  }

  SliderPose get pose {
    final result = _bindings.spine_slider_get_pose(_ptr);
    return SliderPose.fromPointer(result);
  }

  SliderPose get appliedPose {
    final result = _bindings.spine_slider_get_applied_pose(_ptr);
    return SliderPose.fromPointer(result);
  }

  void resetConstrained() {
    _bindings.spine_slider_reset_constrained(_ptr);
  }

  void constrained() {
    _bindings.spine_slider_constrained(_ptr);
  }

  bool get isPoseEqualToApplied {
    final result = _bindings.spine_slider_is_pose_equal_to_applied(_ptr);
    return result;
  }

  bool get isActive {
    final result = _bindings.spine_slider_is_active(_ptr);
    return result;
  }

  set active(bool value) {
    _bindings.spine_slider_set_active(_ptr, value);
  }

  static Rtti rttiStatic() {
    final result = _bindings.spine_slider_rtti();
    return Rtti.fromPointer(result);
  }

  void dispose() {
    _bindings.spine_slider_dispose(_ptr);
  }
}