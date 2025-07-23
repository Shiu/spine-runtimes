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
import 'mix_blend.dart';
import 'mix_direction.dart';
import 'arrays.dart';

/// PhysicsConstraintTimeline wrapper
class PhysicsConstraintTimeline implements Finalizable {
  static late SpineFlutterBindings _bindings;
  final Pointer<spine_physics_constraint_timeline_wrapper> _ptr;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  PhysicsConstraintTimeline.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  Rtti get rtti {
    final result = _bindings.spine_physics_constraint_timeline_get_rtti(_ptr);
    return Rtti.fromPointer(result);
  }

  void apply(Skeleton skeleton, double lastTime, double time, ArrayEvent pEvents, double alpha, MixBlend blend, MixDirection direction, bool appliedPose) {
    _bindings.spine_physics_constraint_timeline_apply(_ptr, skeleton.nativePtr.cast(), lastTime, time, pEvents.nativePtr.cast(), alpha, blend.value, direction.value, appliedPose);
  }

  void setFrame(int frame, double time, double value) {
    _bindings.spine_physics_constraint_timeline_set_frame(_ptr, frame, time, value);
  }

  double getCurveValue(double time) {
    final result = _bindings.spine_physics_constraint_timeline_get_curve_value(_ptr, time);
    return result;
  }

  double getRelativeValue(double time, double alpha, MixBlend blend, double current, double setup) {
    final result = _bindings.spine_physics_constraint_timeline_get_relative_value(_ptr, time, alpha, blend.value, current, setup);
    return result;
  }

  double getScaleValue(double time, double alpha, MixBlend blend, MixDirection direction, double current, double setup) {
    final result = _bindings.spine_physics_constraint_timeline_get_scale_value(_ptr, time, alpha, blend.value, direction.value, current, setup);
    return result;
  }

  set linear(int value) {
    _bindings.spine_physics_constraint_timeline_set_linear(_ptr, value);
  }

  set stepped(int value) {
    _bindings.spine_physics_constraint_timeline_set_stepped(_ptr, value);
  }

  void setBezier(int bezier, int frame, double value, double time1, double value1, double cx1, double cy1, double cx2, double cy2, double time2, double value2) {
    _bindings.spine_physics_constraint_timeline_set_bezier(_ptr, bezier, frame, value, time1, value1, cx1, cy1, cx2, cy2, time2, value2);
  }

  double getBezierValue(double time, int frame, int valueOffset, int i) {
    final result = _bindings.spine_physics_constraint_timeline_get_bezier_value(_ptr, time, frame, valueOffset, i);
    return result;
  }

  ArrayFloat get curves {
    final result = _bindings.spine_physics_constraint_timeline_get_curves(_ptr);
    return ArrayFloat.fromPointer(result);
  }

  int get frameEntries {
    final result = _bindings.spine_physics_constraint_timeline_get_frame_entries(_ptr);
    return result;
  }

  int get frameCount {
    final result = _bindings.spine_physics_constraint_timeline_get_frame_count(_ptr);
    return result;
  }

  ArrayFloat get frames {
    final result = _bindings.spine_physics_constraint_timeline_get_frames(_ptr);
    return ArrayFloat.fromPointer(result);
  }

  double get duration {
    final result = _bindings.spine_physics_constraint_timeline_get_duration(_ptr);
    return result;
  }

  ArrayPropertyId get propertyIds {
    final result = _bindings.spine_physics_constraint_timeline_get_property_ids(_ptr);
    return ArrayPropertyId.fromPointer(result);
  }

  int get constraintIndex {
    final result = _bindings.spine_physics_constraint_timeline_get_constraint_index(_ptr);
    return result;
  }

  set constraintIndex(int value) {
    _bindings.spine_physics_constraint_timeline_set_constraint_index(_ptr, value);
  }

  static Rtti rttiStatic() {
    final result = _bindings.spine_physics_constraint_timeline_rtti();
    return Rtti.fromPointer(result);
  }

  double getAbsoluteValue1(double time, double alpha, MixBlend blend, double current, double setup) {
    final result = _bindings.spine_physics_constraint_timeline_get_absolute_value_1(_ptr, time, alpha, blend.value, current, setup);
    return result;
  }

  double getAbsoluteValue2(double time, double alpha, MixBlend blend, double current, double setup, double value) {
    final result = _bindings.spine_physics_constraint_timeline_get_absolute_value_2(_ptr, time, alpha, blend.value, current, setup, value);
    return result;
  }

  void dispose() {
    _bindings.spine_physics_constraint_timeline_dispose(_ptr);
  }
}