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
import 'attachment.dart';
import 'bone_pose.dart';
import 'color.dart';

/// PointAttachment wrapper
class PointAttachment extends Attachment {
  final Pointer<spine_point_attachment_wrapper> _ptr;

  PointAttachment.fromPointer(this._ptr) : super.fromPointer(_ptr.cast());

  /// Get the native pointer for FFI calls
  @override
  Pointer get nativePtr => _ptr;

  factory PointAttachment(String name) {
    final ptr = SpineBindings.bindings.spine_point_attachment_create(name.toNativeUtf8().cast<Char>());
    return PointAttachment.fromPointer(ptr);
  }

  double get x {
    final result = SpineBindings.bindings.spine_point_attachment_get_x(_ptr);
    return result;
  }

  set x(double value) {
    SpineBindings.bindings.spine_point_attachment_set_x(_ptr, value);
  }

  double get y {
    final result = SpineBindings.bindings.spine_point_attachment_get_y(_ptr);
    return result;
  }

  set y(double value) {
    SpineBindings.bindings.spine_point_attachment_set_y(_ptr, value);
  }

  double get rotation {
    final result = SpineBindings.bindings.spine_point_attachment_get_rotation(_ptr);
    return result;
  }

  set rotation(double value) {
    SpineBindings.bindings.spine_point_attachment_set_rotation(_ptr, value);
  }

  Color get color {
    final result = SpineBindings.bindings.spine_point_attachment_get_color(_ptr);
    return Color.fromPointer(result);
  }

  double computeWorldRotation(BonePose bone) {
    final result = SpineBindings.bindings.spine_point_attachment_compute_world_rotation(_ptr, bone.nativePtr.cast());
    return result;
  }
}
