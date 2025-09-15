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
import 'arrays.dart';
import 'mix_blend.dart';
import 'mix_direction.dart';
import 'skeleton.dart';

/// Stores a list of timelines to animate a skeleton's pose over time.
class Animation {
  final Pointer<spine_animation_wrapper> _ptr;

  Animation.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory Animation(String name, ArrayTimeline timelines, double duration) {
    final ptr = SpineBindings.bindings
        .spine_animation_create(name.toNativeUtf8().cast<Char>(), timelines.nativePtr.cast(), duration);
    return Animation.fromPointer(ptr);
  }

  void dispose() {
    SpineBindings.bindings.spine_animation_dispose(_ptr);
  }

  /// If the returned array or the timelines it contains are modified,
  /// setTimelines() must be called.
  ArrayTimeline get timelines {
    final result = SpineBindings.bindings.spine_animation_get_timelines(_ptr);
    return ArrayTimeline.fromPointer(result);
  }

  set timelines(ArrayTimeline value) {
    SpineBindings.bindings.spine_animation_set_timelines(_ptr, value.nativePtr.cast());
  }

  /// Returns true if this animation contains a timeline with any of the
  /// specified property IDs.
  bool hasTimeline(ArrayPropertyId ids) {
    final result = SpineBindings.bindings.spine_animation_has_timeline(_ptr, ids.nativePtr.cast());
    return result;
  }

  /// The duration of the animation in seconds, which is usually the highest
  /// time of all frames in the timeline. The duration is used to know when it
  /// has completed and when it should loop back to the start.
  double get duration {
    final result = SpineBindings.bindings.spine_animation_get_duration(_ptr);
    return result;
  }

  set duration(double value) {
    SpineBindings.bindings.spine_animation_set_duration(_ptr, value);
  }

  /// Applies the animation's timelines to the specified skeleton.
  ///
  /// See Timeline::apply().
  ///
  /// [skeleton] The skeleton the animation is being applied to. This provides access to the bones, slots, and other skeleton components the timelines may change.
  /// [lastTime] The last time in seconds this animation was applied. Some timelines trigger only at specific times rather than every frame. Pass -1 the first time an animation is applied to ensure frame 0 is triggered.
  /// [time] The time in seconds the skeleton is being posed for. Most timelines find the frame before and the frame after this time and interpolate between the frame values. If beyond the getDuration() and loop is true then the animation will repeat, else the last frame will be applied.
  /// [loop] If true, the animation repeats after the getDuration().
  /// [events] If any events are fired, they are added to this list. Can be null to ignore fired events or if no timelines fire events.
  /// [alpha] 0 applies the current or setup values (depending on blend). 1 applies the timeline values. Between 0 and 1 applies values between the current or setup values and the timeline values. By adjusting alpha over time, an animation can be mixed in or out. alpha can also be useful to apply animations on top of each other (layering).
  /// [blend] Controls how mixing is applied when alpha < 1.
  /// [direction] Indicates whether the timelines are mixing in or out. Used by timelines which perform instant transitions, such as DrawOrderTimeline or AttachmentTimeline.
  void apply(Skeleton skeleton, double lastTime, double time, bool loop, ArrayEvent? events, double alpha,
      MixBlend blend, MixDirection direction, bool appliedPose) {
    SpineBindings.bindings.spine_animation_apply(_ptr, skeleton.nativePtr.cast(), lastTime, time, loop,
        events?.nativePtr.cast() ?? Pointer.fromAddress(0), alpha, blend.value, direction.value, appliedPose);
  }

  /// The animation's name, which is unique across all animations in the
  /// skeleton.
  String get name {
    final result = SpineBindings.bindings.spine_animation_get_name(_ptr);
    return result.cast<Utf8>().toDartString();
  }

  /// The bone indices affected by this animation.
  ArrayInt get bones {
    final result = SpineBindings.bindings.spine_animation_get_bones(_ptr);
    return ArrayInt.fromPointer(result);
  }

  /// [target] After the first and before the last entry.
  static int search(ArrayFloat values, double target) {
    final result = SpineBindings.bindings.spine_animation_search_1(values.nativePtr.cast(), target);
    return result;
  }

  static int search2(ArrayFloat values, double target, int step) {
    final result = SpineBindings.bindings.spine_animation_search_2(values.nativePtr.cast(), target, step);
    return result;
  }
}
