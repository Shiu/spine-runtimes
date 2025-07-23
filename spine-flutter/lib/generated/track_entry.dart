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
import 'animation.dart';
import 'mix_blend.dart';

/// TrackEntry wrapper
class TrackEntry implements Finalizable {
  static late SpineFlutterBindings _bindings;
  final Pointer<spine_track_entry_wrapper> _ptr;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  TrackEntry.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory TrackEntry() {
    final ptr = _bindings.spine_track_entry_create();
    return TrackEntry.fromPointer(ptr);
  }

  int get trackIndex {
    final result = _bindings.spine_track_entry_get_track_index(_ptr);
    return result;
  }

  Animation get animation {
    final result = _bindings.spine_track_entry_get_animation(_ptr);
    return Animation.fromPointer(result);
  }

  set animation(Animation value) {
    _bindings.spine_track_entry_set_animation(_ptr, value.nativePtr.cast());
  }

  TrackEntry get previous {
    final result = _bindings.spine_track_entry_get_previous(_ptr);
    return TrackEntry.fromPointer(result);
  }

  bool get loop {
    final result = _bindings.spine_track_entry_get_loop(_ptr);
    return result;
  }

  set loop(bool value) {
    _bindings.spine_track_entry_set_loop(_ptr, value);
  }

  bool get holdPrevious {
    final result = _bindings.spine_track_entry_get_hold_previous(_ptr);
    return result;
  }

  set holdPrevious(bool value) {
    _bindings.spine_track_entry_set_hold_previous(_ptr, value);
  }

  bool get reverse {
    final result = _bindings.spine_track_entry_get_reverse(_ptr);
    return result;
  }

  set reverse(bool value) {
    _bindings.spine_track_entry_set_reverse(_ptr, value);
  }

  bool get shortestRotation {
    final result = _bindings.spine_track_entry_get_shortest_rotation(_ptr);
    return result;
  }

  set shortestRotation(bool value) {
    _bindings.spine_track_entry_set_shortest_rotation(_ptr, value);
  }

  double get delay {
    final result = _bindings.spine_track_entry_get_delay(_ptr);
    return result;
  }

  set delay(double value) {
    _bindings.spine_track_entry_set_delay(_ptr, value);
  }

  double get trackTime {
    final result = _bindings.spine_track_entry_get_track_time(_ptr);
    return result;
  }

  set trackTime(double value) {
    _bindings.spine_track_entry_set_track_time(_ptr, value);
  }

  double get trackEnd {
    final result = _bindings.spine_track_entry_get_track_end(_ptr);
    return result;
  }

  set trackEnd(double value) {
    _bindings.spine_track_entry_set_track_end(_ptr, value);
  }

  double get animationStart {
    final result = _bindings.spine_track_entry_get_animation_start(_ptr);
    return result;
  }

  set animationStart(double value) {
    _bindings.spine_track_entry_set_animation_start(_ptr, value);
  }

  double get animationEnd {
    final result = _bindings.spine_track_entry_get_animation_end(_ptr);
    return result;
  }

  set animationEnd(double value) {
    _bindings.spine_track_entry_set_animation_end(_ptr, value);
  }

  double get animationLast {
    final result = _bindings.spine_track_entry_get_animation_last(_ptr);
    return result;
  }

  set animationLast(double value) {
    _bindings.spine_track_entry_set_animation_last(_ptr, value);
  }

  double get animationTime {
    final result = _bindings.spine_track_entry_get_animation_time(_ptr);
    return result;
  }

  double get timeScale {
    final result = _bindings.spine_track_entry_get_time_scale(_ptr);
    return result;
  }

  set timeScale(double value) {
    _bindings.spine_track_entry_set_time_scale(_ptr, value);
  }

  double get alpha {
    final result = _bindings.spine_track_entry_get_alpha(_ptr);
    return result;
  }

  set alpha(double value) {
    _bindings.spine_track_entry_set_alpha(_ptr, value);
  }

  double get eventThreshold {
    final result = _bindings.spine_track_entry_get_event_threshold(_ptr);
    return result;
  }

  set eventThreshold(double value) {
    _bindings.spine_track_entry_set_event_threshold(_ptr, value);
  }

  double get mixAttachmentThreshold {
    final result = _bindings.spine_track_entry_get_mix_attachment_threshold(_ptr);
    return result;
  }

  set mixAttachmentThreshold(double value) {
    _bindings.spine_track_entry_set_mix_attachment_threshold(_ptr, value);
  }

  double get alphaAttachmentThreshold {
    final result = _bindings.spine_track_entry_get_alpha_attachment_threshold(_ptr);
    return result;
  }

  set alphaAttachmentThreshold(double value) {
    _bindings.spine_track_entry_set_alpha_attachment_threshold(_ptr, value);
  }

  double get mixDrawOrderThreshold {
    final result = _bindings.spine_track_entry_get_mix_draw_order_threshold(_ptr);
    return result;
  }

  set mixDrawOrderThreshold(double value) {
    _bindings.spine_track_entry_set_mix_draw_order_threshold(_ptr, value);
  }

  TrackEntry get next {
    final result = _bindings.spine_track_entry_get_next(_ptr);
    return TrackEntry.fromPointer(result);
  }

  bool get isComplete {
    final result = _bindings.spine_track_entry_is_complete(_ptr);
    return result;
  }

  double get mixTime {
    final result = _bindings.spine_track_entry_get_mix_time(_ptr);
    return result;
  }

  set mixTime(double value) {
    _bindings.spine_track_entry_set_mix_time(_ptr, value);
  }

  double get mixDuration {
    final result = _bindings.spine_track_entry_get_mix_duration(_ptr);
    return result;
  }

  MixBlend get mixBlend {
    final result = _bindings.spine_track_entry_get_mix_blend(_ptr);
    return MixBlend.fromValue(result);
  }

  set mixBlend(MixBlend value) {
    _bindings.spine_track_entry_set_mix_blend(_ptr, value.value);
  }

  TrackEntry get mixingFrom {
    final result = _bindings.spine_track_entry_get_mixing_from(_ptr);
    return TrackEntry.fromPointer(result);
  }

  TrackEntry get mixingTo {
    final result = _bindings.spine_track_entry_get_mixing_to(_ptr);
    return TrackEntry.fromPointer(result);
  }

  void resetRotationDirections() {
    _bindings.spine_track_entry_reset_rotation_directions(_ptr);
  }

  double get trackComplete {
    final result = _bindings.spine_track_entry_get_track_complete(_ptr);
    return result;
  }

  bool get isEmptyAnimation {
    final result = _bindings.spine_track_entry_is_empty_animation(_ptr);
    return result;
  }

  bool wasApplied() {
    final result = _bindings.spine_track_entry_was_applied(_ptr);
    return result;
  }

  bool get isNextReady {
    final result = _bindings.spine_track_entry_is_next_ready(_ptr);
    return result;
  }

  set mixDuration1(double value) {
    _bindings.spine_track_entry_set_mix_duration_1(_ptr, value);
  }

  void setMixDuration2(double mixDuration, double delay) {
    _bindings.spine_track_entry_set_mix_duration_2(_ptr, mixDuration, delay);
  }

  void dispose() {
    _bindings.spine_track_entry_dispose(_ptr);
  }
}