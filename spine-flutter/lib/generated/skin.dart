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

import '../ffi_proxy.dart';
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

/// Skin wrapper
class Skin {
  final Pointer<spine_skin_wrapper> _ptr;

  Skin.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory Skin(String name) {
    final ptr = SpineBindings.bindings.spine_skin_create(name.toNativeUtf8().cast<Char>());
    return Skin.fromPointer(ptr);
  }

  void dispose() {
    SpineBindings.bindings.spine_skin_dispose(_ptr);
  }

  void setAttachment(int slotIndex, String name, Attachment attachment) {
    SpineBindings.bindings
        .spine_skin_set_attachment(_ptr, slotIndex, name.toNativeUtf8().cast<Char>(), attachment.nativePtr.cast());
  }

  Attachment? getAttachment(int slotIndex, String name) {
    final result = SpineBindings.bindings.spine_skin_get_attachment(_ptr, slotIndex, name.toNativeUtf8().cast<Char>());
    if (result.address == 0) return null;
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

  void removeAttachment(int slotIndex, String name) {
    SpineBindings.bindings.spine_skin_remove_attachment(_ptr, slotIndex, name.toNativeUtf8().cast<Char>());
  }

  void findAttachmentsForSlot(int slotIndex, ArrayAttachment attachments) {
    SpineBindings.bindings.spine_skin_find_attachments_for_slot(_ptr, slotIndex, attachments.nativePtr.cast());
  }

  String get name {
    final result = SpineBindings.bindings.spine_skin_get_name(_ptr);
    return result.cast<Utf8>().toDartString();
  }

  void addSkin(Skin other) {
    SpineBindings.bindings.spine_skin_add_skin(_ptr, other.nativePtr.cast());
  }

  void copySkin(Skin other) {
    SpineBindings.bindings.spine_skin_copy_skin(_ptr, other.nativePtr.cast());
  }

  ArrayBoneData get bones {
    final result = SpineBindings.bindings.spine_skin_get_bones(_ptr);
    return ArrayBoneData.fromPointer(result);
  }

  ArrayConstraintData get constraints {
    final result = SpineBindings.bindings.spine_skin_get_constraints(_ptr);
    return ArrayConstraintData.fromPointer(result);
  }

  Color get color {
    final result = SpineBindings.bindings.spine_skin_get_color(_ptr);
    return Color.fromPointer(result);
  }
}
