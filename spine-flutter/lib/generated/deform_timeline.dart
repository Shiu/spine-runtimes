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
import 'vertex_attachment.dart';
import 'skeleton.dart';
import 'mix_blend.dart';
import 'mix_direction.dart';
import 'arrays.dart';

/// DeformTimeline wrapper
class DeformTimeline implements Finalizable {
  static late SpineFlutterBindings _bindings;
  final Pointer<spine_deform_timeline_wrapper> _ptr;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  DeformTimeline.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory DeformTimeline(int frameCount, int bezierCount, int slotIndex, VertexAttachment attachment) {
    final ptr = _bindings.spine_deform_timeline_create(frameCount, bezierCount, slotIndex, attachment.nativePtr.cast());
    return DeformTimeline.fromPointer(ptr);
  }

  Rtti get rtti {
    final result = _bindings.spine_deform_timeline_get_rtti(_ptr);
    return Rtti.fromPointer(result);
  }

  void setFrame(int frameIndex, double time, ArrayFloat vertices) {
    _bindings.spine_deform_timeline_set_frame(_ptr, frameIndex, time, vertices.nativePtr.cast());
  }

  VertexAttachment get attachment {
    final result = _bindings.spine_deform_timeline_get_attachment(_ptr);
    return VertexAttachment.fromPointer(result);
  }

  set attachment(VertexAttachment value) {
    _bindings.spine_deform_timeline_set_attachment(_ptr, value.nativePtr.cast());
  }

  void setBezier(int bezier, int frame, double value, double time1, double value1, double cx1, double cy1, double cx2, double cy2, double time2, double value2) {
    _bindings.spine_deform_timeline_set_bezier(_ptr, bezier, frame, value, time1, value1, cx1, cy1, cx2, cy2, time2, value2);
  }

  double getCurvePercent(double time, int frame) {
    final result = _bindings.spine_deform_timeline_get_curve_percent(_ptr, time, frame);
    return result;
  }

  int get frameCount {
    final result = _bindings.spine_deform_timeline_get_frame_count(_ptr);
    return result;
  }

  void apply(Skeleton skeleton, double lastTime, double time, ArrayEvent pEvents, double alpha, MixBlend blend, MixDirection direction, bool appliedPose) {
    _bindings.spine_deform_timeline_apply(_ptr, skeleton.nativePtr.cast(), lastTime, time, pEvents.nativePtr.cast(), alpha, blend.value, direction.value, appliedPose);
  }

  set linear(int value) {
    _bindings.spine_deform_timeline_set_linear(_ptr, value);
  }

  set stepped(int value) {
    _bindings.spine_deform_timeline_set_stepped(_ptr, value);
  }

  double getBezierValue(double time, int frame, int valueOffset, int i) {
    final result = _bindings.spine_deform_timeline_get_bezier_value(_ptr, time, frame, valueOffset, i);
    return result;
  }

  ArrayFloat get curves {
    final result = _bindings.spine_deform_timeline_get_curves(_ptr);
    return ArrayFloat.fromPointer(result);
  }

  int get frameEntries {
    final result = _bindings.spine_deform_timeline_get_frame_entries(_ptr);
    return result;
  }

  ArrayFloat get frames {
    final result = _bindings.spine_deform_timeline_get_frames(_ptr);
    return ArrayFloat.fromPointer(result);
  }

  double get duration {
    final result = _bindings.spine_deform_timeline_get_duration(_ptr);
    return result;
  }

  ArrayPropertyId get propertyIds {
    final result = _bindings.spine_deform_timeline_get_property_ids(_ptr);
    return ArrayPropertyId.fromPointer(result);
  }

  int get slotIndex {
    final result = _bindings.spine_deform_timeline_get_slot_index(_ptr);
    return result;
  }

  set slotIndex(int value) {
    _bindings.spine_deform_timeline_set_slot_index(_ptr, value);
  }

  static Rtti rttiStatic() {
    final result = _bindings.spine_deform_timeline_rtti();
    return Rtti.fromPointer(result);
  }

  void dispose() {
    _bindings.spine_deform_timeline_dispose(_ptr);
  }
}