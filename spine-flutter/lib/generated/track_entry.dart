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
import 'spine_dart_bindings_generated.dart';
import '../spine_bindings.dart';
import 'animation.dart';
import 'animation_state.dart';
import 'mix_blend.dart';

/// TrackEntry wrapper
class TrackEntry {
  final Pointer<spine_track_entry_wrapper> _ptr;

  TrackEntry.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory TrackEntry() {
    final ptr = SpineBindings.bindings.spine_track_entry_create();
    return TrackEntry.fromPointer(ptr);
  }

  void dispose() {
    SpineBindings.bindings.spine_track_entry_dispose(_ptr);
  }

  int get trackIndex {
    final result = SpineBindings.bindings.spine_track_entry_get_track_index(_ptr);
    return result;
  }

  Animation get animation {
    final result = SpineBindings.bindings.spine_track_entry_get_animation(_ptr);
    return Animation.fromPointer(result);
  }

  set animation(Animation value) {
    SpineBindings.bindings.spine_track_entry_set_animation(_ptr, value.nativePtr.cast());
  }

  TrackEntry? get previous {
    final result = SpineBindings.bindings.spine_track_entry_get_previous(_ptr);
    return result.address == 0 ? null : TrackEntry.fromPointer(result);
  }

  bool get loop {
    final result = SpineBindings.bindings.spine_track_entry_get_loop(_ptr);
    return result;
  }

  set loop(bool value) {
    SpineBindings.bindings.spine_track_entry_set_loop(_ptr, value);
  }

  bool get holdPrevious {
    final result = SpineBindings.bindings.spine_track_entry_get_hold_previous(_ptr);
    return result;
  }

  set holdPrevious(bool value) {
    SpineBindings.bindings.spine_track_entry_set_hold_previous(_ptr, value);
  }

  bool get reverse {
    final result = SpineBindings.bindings.spine_track_entry_get_reverse(_ptr);
    return result;
  }

  set reverse(bool value) {
    SpineBindings.bindings.spine_track_entry_set_reverse(_ptr, value);
  }

  bool get shortestRotation {
    final result = SpineBindings.bindings.spine_track_entry_get_shortest_rotation(_ptr);
    return result;
  }

  set shortestRotation(bool value) {
    SpineBindings.bindings.spine_track_entry_set_shortest_rotation(_ptr, value);
  }

  double get delay {
    final result = SpineBindings.bindings.spine_track_entry_get_delay(_ptr);
    return result;
  }

  set delay(double value) {
    SpineBindings.bindings.spine_track_entry_set_delay(_ptr, value);
  }

  double get trackTime {
    final result = SpineBindings.bindings.spine_track_entry_get_track_time(_ptr);
    return result;
  }

  set trackTime(double value) {
    SpineBindings.bindings.spine_track_entry_set_track_time(_ptr, value);
  }

  double get trackEnd {
    final result = SpineBindings.bindings.spine_track_entry_get_track_end(_ptr);
    return result;
  }

  set trackEnd(double value) {
    SpineBindings.bindings.spine_track_entry_set_track_end(_ptr, value);
  }

  double get animationStart {
    final result = SpineBindings.bindings.spine_track_entry_get_animation_start(_ptr);
    return result;
  }

  set animationStart(double value) {
    SpineBindings.bindings.spine_track_entry_set_animation_start(_ptr, value);
  }

  double get animationEnd {
    final result = SpineBindings.bindings.spine_track_entry_get_animation_end(_ptr);
    return result;
  }

  set animationEnd(double value) {
    SpineBindings.bindings.spine_track_entry_set_animation_end(_ptr, value);
  }

  double get animationLast {
    final result = SpineBindings.bindings.spine_track_entry_get_animation_last(_ptr);
    return result;
  }

  set animationLast(double value) {
    SpineBindings.bindings.spine_track_entry_set_animation_last(_ptr, value);
  }

  double get animationTime {
    final result = SpineBindings.bindings.spine_track_entry_get_animation_time(_ptr);
    return result;
  }

  double get timeScale {
    final result = SpineBindings.bindings.spine_track_entry_get_time_scale(_ptr);
    return result;
  }

  set timeScale(double value) {
    SpineBindings.bindings.spine_track_entry_set_time_scale(_ptr, value);
  }

  double get alpha {
    final result = SpineBindings.bindings.spine_track_entry_get_alpha(_ptr);
    return result;
  }

  set alpha(double value) {
    SpineBindings.bindings.spine_track_entry_set_alpha(_ptr, value);
  }

  double get eventThreshold {
    final result = SpineBindings.bindings.spine_track_entry_get_event_threshold(_ptr);
    return result;
  }

  set eventThreshold(double value) {
    SpineBindings.bindings.spine_track_entry_set_event_threshold(_ptr, value);
  }

  double get mixAttachmentThreshold {
    final result = SpineBindings.bindings.spine_track_entry_get_mix_attachment_threshold(_ptr);
    return result;
  }

  set mixAttachmentThreshold(double value) {
    SpineBindings.bindings.spine_track_entry_set_mix_attachment_threshold(_ptr, value);
  }

  double get alphaAttachmentThreshold {
    final result = SpineBindings.bindings.spine_track_entry_get_alpha_attachment_threshold(_ptr);
    return result;
  }

  set alphaAttachmentThreshold(double value) {
    SpineBindings.bindings.spine_track_entry_set_alpha_attachment_threshold(_ptr, value);
  }

  double get mixDrawOrderThreshold {
    final result = SpineBindings.bindings.spine_track_entry_get_mix_draw_order_threshold(_ptr);
    return result;
  }

  set mixDrawOrderThreshold(double value) {
    SpineBindings.bindings.spine_track_entry_set_mix_draw_order_threshold(_ptr, value);
  }

  TrackEntry? get next {
    final result = SpineBindings.bindings.spine_track_entry_get_next(_ptr);
    return result.address == 0 ? null : TrackEntry.fromPointer(result);
  }

  bool get isComplete {
    final result = SpineBindings.bindings.spine_track_entry_is_complete(_ptr);
    return result;
  }

  double get mixTime {
    final result = SpineBindings.bindings.spine_track_entry_get_mix_time(_ptr);
    return result;
  }

  set mixTime(double value) {
    SpineBindings.bindings.spine_track_entry_set_mix_time(_ptr, value);
  }

  double get mixDuration {
    final result = SpineBindings.bindings.spine_track_entry_get_mix_duration(_ptr);
    return result;
  }

  MixBlend get mixBlend {
    final result = SpineBindings.bindings.spine_track_entry_get_mix_blend(_ptr);
    return MixBlend.fromValue(result);
  }

  set mixBlend(MixBlend value) {
    SpineBindings.bindings.spine_track_entry_set_mix_blend(_ptr, value.value);
  }

  TrackEntry? get mixingFrom {
    final result = SpineBindings.bindings.spine_track_entry_get_mixing_from(_ptr);
    return result.address == 0 ? null : TrackEntry.fromPointer(result);
  }

  TrackEntry? get mixingTo {
    final result = SpineBindings.bindings.spine_track_entry_get_mixing_to(_ptr);
    return result.address == 0 ? null : TrackEntry.fromPointer(result);
  }

  void resetRotationDirections() {
    SpineBindings.bindings.spine_track_entry_reset_rotation_directions(_ptr);
  }

  double get trackComplete {
    final result = SpineBindings.bindings.spine_track_entry_get_track_complete(_ptr);
    return result;
  }

  bool get isEmptyAnimation {
    final result = SpineBindings.bindings.spine_track_entry_is_empty_animation(_ptr);
    return result;
  }

  bool get wasApplied {
    final result = SpineBindings.bindings.spine_track_entry_was_applied(_ptr);
    return result;
  }

  bool get isNextReady {
    final result = SpineBindings.bindings.spine_track_entry_is_next_ready(_ptr);
    return result;
  }

  AnimationState? get animationState {
    final result = SpineBindings.bindings.spine_track_entry_get_animation_state(_ptr);
    return result.address == 0 ? null : AnimationState.fromPointer(result);
  }

  set animationState(AnimationState? value) {
    SpineBindings.bindings
        .spine_track_entry_set_animation_state(_ptr, value?.nativePtr.cast() ?? Pointer.fromAddress(0));
  }

  Pointer<Void>? get rendererObject {
    final result = SpineBindings.bindings.spine_track_entry_get_renderer_object(_ptr);
    return result;
  }

  set setMixDuration(double value) {
    SpineBindings.bindings.spine_track_entry_set_mix_duration_1(_ptr, value);
  }

  void setMixDuration2(double mixDuration, double delay) {
    SpineBindings.bindings.spine_track_entry_set_mix_duration_2(_ptr, mixDuration, delay);
  }
}
