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
import 'skeleton_data.dart';
import 'animation.dart';

/// AnimationStateData wrapper
class AnimationStateData implements Finalizable {
  static late SpineFlutterBindings _bindings;
  final Pointer<spine_animation_state_data_wrapper> _ptr;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  AnimationStateData.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory AnimationStateData(SkeletonData skeletonData) {
    final ptr = _bindings.spine_animation_state_data_create(skeletonData.nativePtr.cast());
    return AnimationStateData.fromPointer(ptr);
  }

  SkeletonData get skeletonData {
    final result = _bindings.spine_animation_state_data_get_skeleton_data(_ptr);
    return SkeletonData.fromPointer(result);
  }

  double get defaultMix {
    final result = _bindings.spine_animation_state_data_get_default_mix(_ptr);
    return result;
  }

  set defaultMix(double value) {
    _bindings.spine_animation_state_data_set_default_mix(_ptr, value);
  }

  double getMix(Animation from, Animation to) {
    final result = _bindings.spine_animation_state_data_get_mix(_ptr, from.nativePtr.cast(), to.nativePtr.cast());
    return result;
  }

  void clear() {
    _bindings.spine_animation_state_data_clear(_ptr);
  }

  void setMix1(String fromName, String toName, double duration) {
    _bindings.spine_animation_state_data_set_mix_1(_ptr, fromName.toNativeUtf8().cast<Char>(), toName.toNativeUtf8().cast<Char>(), duration);
  }

  void setMix2(Animation from, Animation to, double duration) {
    _bindings.spine_animation_state_data_set_mix_2(_ptr, from.nativePtr.cast(), to.nativePtr.cast(), duration);
  }

  void dispose() {
    _bindings.spine_animation_state_data_dispose(_ptr);
  }
}