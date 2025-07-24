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
import 'spine_dart_bindings_generated.dart';
import '../spine_bindings.dart';
import 'animation.dart';
import 'animation_state_data.dart';
import 'arrays.dart';
import 'skeleton.dart';
import 'track_entry.dart';

/// AnimationState wrapper
class AnimationState implements Finalizable {
  final Pointer<spine_animation_state_wrapper> _ptr;

  AnimationState.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory AnimationState(AnimationStateData data) {
    final ptr = SpineBindings.bindings.spine_animation_state_create(data.nativePtr.cast());
    return AnimationState.fromPointer(ptr);
  }

  void update(double delta) {
    SpineBindings.bindings.spine_animation_state_update(_ptr, delta);
  }

  bool apply(Skeleton skeleton) {
    final result = SpineBindings.bindings.spine_animation_state_apply(_ptr, skeleton.nativePtr.cast());
    return result;
  }

  void clearTracks() {
    SpineBindings.bindings.spine_animation_state_clear_tracks(_ptr);
  }

  void clearTrack(int trackIndex) {
    SpineBindings.bindings.spine_animation_state_clear_track(_ptr, trackIndex);
  }

  TrackEntry setEmptyAnimation(int trackIndex, double mixDuration) {
    final result = SpineBindings.bindings.spine_animation_state_set_empty_animation(_ptr, trackIndex, mixDuration);
    return TrackEntry.fromPointer(result);
  }

  TrackEntry addEmptyAnimation(int trackIndex, double mixDuration, double delay) {
    final result =
        SpineBindings.bindings.spine_animation_state_add_empty_animation(_ptr, trackIndex, mixDuration, delay);
    return TrackEntry.fromPointer(result);
  }

  set emptyAnimations(double value) {
    SpineBindings.bindings.spine_animation_state_set_empty_animations(_ptr, value);
  }

  TrackEntry getCurrent(int trackIndex) {
    final result = SpineBindings.bindings.spine_animation_state_get_current(_ptr, trackIndex);
    return TrackEntry.fromPointer(result);
  }

  AnimationStateData get data {
    final result = SpineBindings.bindings.spine_animation_state_get_data(_ptr);
    return AnimationStateData.fromPointer(result);
  }

  ArrayTrackEntry get tracks {
    final result = SpineBindings.bindings.spine_animation_state_get_tracks(_ptr);
    return ArrayTrackEntry.fromPointer(result);
  }

  double get timeScale {
    final result = SpineBindings.bindings.spine_animation_state_get_time_scale(_ptr);
    return result;
  }

  set timeScale(double value) {
    SpineBindings.bindings.spine_animation_state_set_time_scale(_ptr, value);
  }

  void disableQueue() {
    SpineBindings.bindings.spine_animation_state_disable_queue(_ptr);
  }

  void enableQueue() {
    SpineBindings.bindings.spine_animation_state_enable_queue(_ptr);
  }

  set manualTrackEntryDisposal(bool value) {
    SpineBindings.bindings.spine_animation_state_set_manual_track_entry_disposal(_ptr, value);
  }

  bool get manualTrackEntryDisposal {
    final result = SpineBindings.bindings.spine_animation_state_get_manual_track_entry_disposal(_ptr);
    return result;
  }

  void disposeTrackEntry(TrackEntry entry) {
    SpineBindings.bindings.spine_animation_state_dispose_track_entry(_ptr, entry.nativePtr.cast());
  }

  Pointer<Void> get rendererObject {
    final result = SpineBindings.bindings.spine_animation_state_get_renderer_object(_ptr);
    return result;
  }

  TrackEntry setAnimation(int trackIndex, String animationName, bool loop) {
    final result = SpineBindings.bindings
        .spine_animation_state_set_animation_1(_ptr, trackIndex, animationName.toNativeUtf8().cast<Char>(), loop);
    return TrackEntry.fromPointer(result);
  }

  TrackEntry setAnimation2(int trackIndex, Animation animation, bool loop) {
    final result = SpineBindings.bindings
        .spine_animation_state_set_animation_2(_ptr, trackIndex, animation.nativePtr.cast(), loop);
    return TrackEntry.fromPointer(result);
  }

  TrackEntry addAnimation(int trackIndex, String animationName, bool loop, double delay) {
    final result = SpineBindings.bindings.spine_animation_state_add_animation_1(
        _ptr, trackIndex, animationName.toNativeUtf8().cast<Char>(), loop, delay);
    return TrackEntry.fromPointer(result);
  }

  TrackEntry addAnimation2(int trackIndex, Animation animation, bool loop, double delay) {
    final result = SpineBindings.bindings
        .spine_animation_state_add_animation_2(_ptr, trackIndex, animation.nativePtr.cast(), loop, delay);
    return TrackEntry.fromPointer(result);
  }
}
