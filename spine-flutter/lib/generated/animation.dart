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
import 'skeleton.dart';
import 'mix_blend.dart';
import 'mix_direction.dart';
import 'arrays.dart';

/// Animation wrapper
class Animation implements Finalizable {
  static late SpineFlutterBindings _bindings;
  final Pointer<spine_animation_wrapper> _ptr;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  Animation.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory Animation(String name, ArrayTimeline timelines, double duration) {
    final ptr = _bindings.spine_animation_create(name.toNativeUtf8().cast<Char>(), timelines.nativePtr.cast(), duration);
    return Animation.fromPointer(ptr);
  }

  ArrayTimeline get timelines {
    final result = _bindings.spine_animation_get_timelines(_ptr);
    return ArrayTimeline.fromPointer(result);
  }

  set timelines(ArrayTimeline value) {
    _bindings.spine_animation_set_timelines(_ptr, value.nativePtr.cast());
  }

  bool hasTimeline(ArrayPropertyId ids) {
    final result = _bindings.spine_animation_has_timeline(_ptr, ids.nativePtr.cast());
    return result;
  }

  double get duration {
    final result = _bindings.spine_animation_get_duration(_ptr);
    return result;
  }

  set duration(double value) {
    _bindings.spine_animation_set_duration(_ptr, value);
  }

  void apply(Skeleton skeleton, double lastTime, double time, bool loop, ArrayEvent pEvents, double alpha, MixBlend blend, MixDirection direction, bool appliedPose) {
    _bindings.spine_animation_apply(_ptr, skeleton.nativePtr.cast(), lastTime, time, loop, pEvents.nativePtr.cast(), alpha, blend.value, direction.value, appliedPose);
  }

  String get name {
    final result = _bindings.spine_animation_get_name(_ptr);
    return result.cast<Utf8>().toDartString();
  }

  ArrayInt get bones {
    final result = _bindings.spine_animation_get_bones(_ptr);
    return ArrayInt.fromPointer(result);
  }

  static int search1(ArrayFloat values, double target) {
    final result = _bindings.spine_animation_search_1(values.nativePtr.cast(), target);
    return result;
  }

  static int search2(ArrayFloat values, double target, int step) {
    final result = _bindings.spine_animation_search_2(values.nativePtr.cast(), target, step);
    return result;
  }

  void dispose() {
    _bindings.spine_animation_dispose(_ptr);
  }
}