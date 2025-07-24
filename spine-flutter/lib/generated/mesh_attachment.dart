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
import 'color.dart';
import 'sequence.dart';
import 'texture_region.dart';
import 'vertex_attachment.dart';

/// MeshAttachment wrapper
class MeshAttachment extends VertexAttachment {
  final Pointer<spine_mesh_attachment_wrapper> _ptr;

  MeshAttachment.fromPointer(this._ptr) : super.fromPointer(_ptr.cast());

  /// Get the native pointer for FFI calls
  @override
  Pointer get nativePtr => _ptr;

  factory MeshAttachment(String name) {
    final ptr = SpineBindings.bindings
        .spine_mesh_attachment_create(name.toNativeUtf8().cast<Char>());
    return MeshAttachment.fromPointer(ptr);
  }

  void updateRegion() {
    SpineBindings.bindings.spine_mesh_attachment_update_region(_ptr);
  }

  int get hullLength {
    final result =
        SpineBindings.bindings.spine_mesh_attachment_get_hull_length(_ptr);
    return result;
  }

  set hullLength(int value) {
    SpineBindings.bindings.spine_mesh_attachment_set_hull_length(_ptr, value);
  }

  ArrayFloat get regionUVs {
    final result =
        SpineBindings.bindings.spine_mesh_attachment_get_region_u_vs(_ptr);
    return ArrayFloat.fromPointer(result);
  }

  set regionUVs(ArrayFloat value) {
    SpineBindings.bindings
        .spine_mesh_attachment_set_region_u_vs(_ptr, value.nativePtr.cast());
  }

  ArrayFloat get uVs {
    final result = SpineBindings.bindings.spine_mesh_attachment_get_u_vs(_ptr);
    return ArrayFloat.fromPointer(result);
  }

  ArrayUnsignedShort get triangles {
    final result =
        SpineBindings.bindings.spine_mesh_attachment_get_triangles(_ptr);
    return ArrayUnsignedShort.fromPointer(result);
  }

  set triangles(ArrayUnsignedShort value) {
    SpineBindings.bindings
        .spine_mesh_attachment_set_triangles(_ptr, value.nativePtr.cast());
  }

  Color get color {
    final result = SpineBindings.bindings.spine_mesh_attachment_get_color(_ptr);
    return Color.fromPointer(result);
  }

  String get path {
    final result = SpineBindings.bindings.spine_mesh_attachment_get_path(_ptr);
    return result.cast<Utf8>().toDartString();
  }

  set path(String value) {
    SpineBindings.bindings.spine_mesh_attachment_set_path(
        _ptr, value.toNativeUtf8().cast<Char>());
  }

  TextureRegion get region {
    final result =
        SpineBindings.bindings.spine_mesh_attachment_get_region(_ptr);
    return TextureRegion.fromPointer(result);
  }

  set region(TextureRegion value) {
    SpineBindings.bindings
        .spine_mesh_attachment_set_region(_ptr, value.nativePtr.cast());
  }

  Sequence get sequence {
    final result =
        SpineBindings.bindings.spine_mesh_attachment_get_sequence(_ptr);
    return Sequence.fromPointer(result);
  }

  set sequence(Sequence value) {
    SpineBindings.bindings
        .spine_mesh_attachment_set_sequence(_ptr, value.nativePtr.cast());
  }

  MeshAttachment get parentMesh {
    final result =
        SpineBindings.bindings.spine_mesh_attachment_get_parent_mesh(_ptr);
    return MeshAttachment.fromPointer(result);
  }

  set parentMesh(MeshAttachment value) {
    SpineBindings.bindings
        .spine_mesh_attachment_set_parent_mesh(_ptr, value.nativePtr.cast());
  }

  ArrayUnsignedShort get edges {
    final result = SpineBindings.bindings.spine_mesh_attachment_get_edges(_ptr);
    return ArrayUnsignedShort.fromPointer(result);
  }

  set edges(ArrayUnsignedShort value) {
    SpineBindings.bindings
        .spine_mesh_attachment_set_edges(_ptr, value.nativePtr.cast());
  }

  double get width {
    final result = SpineBindings.bindings.spine_mesh_attachment_get_width(_ptr);
    return result;
  }

  set width(double value) {
    SpineBindings.bindings.spine_mesh_attachment_set_width(_ptr, value);
  }

  double get height {
    final result =
        SpineBindings.bindings.spine_mesh_attachment_get_height(_ptr);
    return result;
  }

  set height(double value) {
    SpineBindings.bindings.spine_mesh_attachment_set_height(_ptr, value);
  }

  MeshAttachment newLinkedMesh() {
    final result =
        SpineBindings.bindings.spine_mesh_attachment_new_linked_mesh(_ptr);
    return MeshAttachment.fromPointer(result);
  }
}
