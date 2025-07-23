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
import 'rtti.dart';
import 'color.dart';
import 'bone_pose.dart';
import 'attachment.dart';

/// PointAttachment wrapper
class PointAttachment implements Finalizable {
  static late SpineFlutterBindings _bindings;
  final Pointer<spine_point_attachment_wrapper> _ptr;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  PointAttachment.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory PointAttachment(String name) {
    final ptr = _bindings.spine_point_attachment_create(name.toNativeUtf8().cast<Char>());
    return PointAttachment.fromPointer(ptr);
  }

  Rtti get rtti {
    final result = _bindings.spine_point_attachment_get_rtti(_ptr);
    return Rtti.fromPointer(result);
  }

  double get x {
    final result = _bindings.spine_point_attachment_get_x(_ptr);
    return result;
  }

  set x(double value) {
    _bindings.spine_point_attachment_set_x(_ptr, value);
  }

  double get y {
    final result = _bindings.spine_point_attachment_get_y(_ptr);
    return result;
  }

  set y(double value) {
    _bindings.spine_point_attachment_set_y(_ptr, value);
  }

  double get rotation {
    final result = _bindings.spine_point_attachment_get_rotation(_ptr);
    return result;
  }

  set rotation(double value) {
    _bindings.spine_point_attachment_set_rotation(_ptr, value);
  }

  Color get color {
    final result = _bindings.spine_point_attachment_get_color(_ptr);
    return Color.fromPointer(result);
  }

  double computeWorldRotation(BonePose bone) {
    final result = _bindings.spine_point_attachment_compute_world_rotation(_ptr, bone.nativePtr.cast());
    return result;
  }

  Attachment copy() {
    final result = _bindings.spine_point_attachment_copy(_ptr);
    return Attachment.fromPointer(result);
  }

  String get name {
    final result = _bindings.spine_point_attachment_get_name(_ptr);
    return result.cast<Utf8>().toDartString();
  }

  int get refCount {
    final result = _bindings.spine_point_attachment_get_ref_count(_ptr);
    return result;
  }

  void reference() {
    _bindings.spine_point_attachment_reference(_ptr);
  }

  void dereference() {
    _bindings.spine_point_attachment_dereference(_ptr);
  }

  static Rtti rttiStatic() {
    final result = _bindings.spine_point_attachment_rtti();
    return Rtti.fromPointer(result);
  }

  void dispose() {
    _bindings.spine_point_attachment_dispose(_ptr);
  }
}