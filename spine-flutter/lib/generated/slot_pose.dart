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
import 'arrays.dart';
import 'attachment.dart';
import 'bounding_box_attachment.dart';
import 'clipping_attachment.dart';
import 'color.dart';
import 'mesh_attachment.dart';
import 'path_attachment.dart';
import 'point_attachment.dart';
import 'region_attachment.dart';

/// SlotPose wrapper
class SlotPose implements Finalizable {
  final Pointer<spine_slot_pose_wrapper> _ptr;

  SlotPose.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory SlotPose() {
    final ptr = SpineBindings.bindings.spine_slot_pose_create();
    return SlotPose.fromPointer(ptr);
  }

  void set(SlotPose pose) {
    SpineBindings.bindings.spine_slot_pose_set(_ptr, pose.nativePtr.cast());
  }

  Color get color {
    final result = SpineBindings.bindings.spine_slot_pose_get_color(_ptr);
    return Color.fromPointer(result);
  }

  Color get darkColor {
    final result = SpineBindings.bindings.spine_slot_pose_get_dark_color(_ptr);
    return Color.fromPointer(result);
  }

  bool get hasDarkColor {
    final result = SpineBindings.bindings.spine_slot_pose_has_dark_color(_ptr);
    return result;
  }

  set hasDarkColor(bool value) {
    SpineBindings.bindings.spine_slot_pose_set_has_dark_color(_ptr, value);
  }

  Attachment get attachment {
    final result = SpineBindings.bindings.spine_slot_pose_get_attachment(_ptr);
    final rtti = SpineBindings.bindings.spine_attachment_get_rtti(result);
    final className = SpineBindings.bindings.spine_rtti_get_class_name(rtti).cast<Utf8>().toDartString();
    switch (className) {
      case 'spine_bounding_box_attachment':
        return BoundingBoxAttachment.fromPointer(result.cast());
      case 'spine_clipping_attachment':
        return ClippingAttachment.fromPointer(result.cast());
      case 'spine_mesh_attachment':
        return MeshAttachment.fromPointer(result.cast());
      case 'spine_path_attachment':
        return PathAttachment.fromPointer(result.cast());
      case 'spine_point_attachment':
        return PointAttachment.fromPointer(result.cast());
      case 'spine_region_attachment':
        return RegionAttachment.fromPointer(result.cast());
      default:
        throw UnsupportedError('Unknown concrete type: $className for abstract class Attachment');
    }
  }

  set attachment(Attachment value) {
    SpineBindings.bindings.spine_slot_pose_set_attachment(_ptr, value.nativePtr.cast());
  }

  int get sequenceIndex {
    final result = SpineBindings.bindings.spine_slot_pose_get_sequence_index(_ptr);
    return result;
  }

  set sequenceIndex(int value) {
    SpineBindings.bindings.spine_slot_pose_set_sequence_index(_ptr, value);
  }

  ArrayFloat get deform {
    final result = SpineBindings.bindings.spine_slot_pose_get_deform(_ptr);
    return ArrayFloat.fromPointer(result);
  }
}
