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
import 'skeleton.dart';
import 'slot.dart';
import 'color.dart';
import 'texture_region.dart';
import 'sequence.dart';
import 'attachment.dart';
import 'vertex_attachment.dart';
import 'arrays.dart';

/// MeshAttachment wrapper
class MeshAttachment implements Finalizable {
  static late SpineFlutterBindings _bindings;
  final Pointer<spine_mesh_attachment_wrapper> _ptr;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  MeshAttachment.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory MeshAttachment(String name) {
    final ptr = _bindings.spine_mesh_attachment_create(name.toNativeUtf8().cast<Char>());
    return MeshAttachment.fromPointer(ptr);
  }

  Rtti get rtti {
    final result = _bindings.spine_mesh_attachment_get_rtti(_ptr);
    return Rtti.fromPointer(result);
  }

  void updateRegion() {
    _bindings.spine_mesh_attachment_update_region(_ptr);
  }

  int get hullLength {
    final result = _bindings.spine_mesh_attachment_get_hull_length(_ptr);
    return result;
  }

  set hullLength(int value) {
    _bindings.spine_mesh_attachment_set_hull_length(_ptr, value);
  }

  ArrayFloat get regionUVs {
    final result = _bindings.spine_mesh_attachment_get_region_u_vs(_ptr);
    return ArrayFloat.fromPointer(result);
  }

  set regionUVs(ArrayFloat value) {
    _bindings.spine_mesh_attachment_set_region_u_vs(_ptr, value.nativePtr.cast());
  }

  ArrayFloat get uVs {
    final result = _bindings.spine_mesh_attachment_get_u_vs(_ptr);
    return ArrayFloat.fromPointer(result);
  }

  ArrayUnsignedShort get triangles {
    final result = _bindings.spine_mesh_attachment_get_triangles(_ptr);
    return ArrayUnsignedShort.fromPointer(result);
  }

  set triangles(ArrayUnsignedShort value) {
    _bindings.spine_mesh_attachment_set_triangles(_ptr, value.nativePtr.cast());
  }

  Color get color {
    final result = _bindings.spine_mesh_attachment_get_color(_ptr);
    return Color.fromPointer(result);
  }

  String get path {
    final result = _bindings.spine_mesh_attachment_get_path(_ptr);
    return result.cast<Utf8>().toDartString();
  }

  set path(String value) {
    _bindings.spine_mesh_attachment_set_path(_ptr, value.toNativeUtf8().cast<Char>());
  }

  TextureRegion get region {
    final result = _bindings.spine_mesh_attachment_get_region(_ptr);
    return TextureRegion.fromPointer(result);
  }

  set region(TextureRegion value) {
    _bindings.spine_mesh_attachment_set_region(_ptr, value.nativePtr.cast());
  }

  Sequence get sequence {
    final result = _bindings.spine_mesh_attachment_get_sequence(_ptr);
    return Sequence.fromPointer(result);
  }

  set sequence(Sequence value) {
    _bindings.spine_mesh_attachment_set_sequence(_ptr, value.nativePtr.cast());
  }

  MeshAttachment get parentMesh {
    final result = _bindings.spine_mesh_attachment_get_parent_mesh(_ptr);
    return MeshAttachment.fromPointer(result);
  }

  set parentMesh(MeshAttachment value) {
    _bindings.spine_mesh_attachment_set_parent_mesh(_ptr, value.nativePtr.cast());
  }

  ArrayUnsignedShort get edges {
    final result = _bindings.spine_mesh_attachment_get_edges(_ptr);
    return ArrayUnsignedShort.fromPointer(result);
  }

  set edges(ArrayUnsignedShort value) {
    _bindings.spine_mesh_attachment_set_edges(_ptr, value.nativePtr.cast());
  }

  double get width {
    final result = _bindings.spine_mesh_attachment_get_width(_ptr);
    return result;
  }

  set width(double value) {
    _bindings.spine_mesh_attachment_set_width(_ptr, value);
  }

  double get height {
    final result = _bindings.spine_mesh_attachment_get_height(_ptr);
    return result;
  }

  set height(double value) {
    _bindings.spine_mesh_attachment_set_height(_ptr, value);
  }

  Attachment copy() {
    final result = _bindings.spine_mesh_attachment_copy(_ptr);
    return Attachment.fromPointer(result);
  }

  MeshAttachment newLinkedMesh() {
    final result = _bindings.spine_mesh_attachment_new_linked_mesh(_ptr);
    return MeshAttachment.fromPointer(result);
  }

  int get id {
    final result = _bindings.spine_mesh_attachment_get_id(_ptr);
    return result;
  }

  ArrayInt get bones {
    final result = _bindings.spine_mesh_attachment_get_bones(_ptr);
    return ArrayInt.fromPointer(result);
  }

  set bones(ArrayInt value) {
    _bindings.spine_mesh_attachment_set_bones(_ptr, value.nativePtr.cast());
  }

  ArrayFloat get vertices {
    final result = _bindings.spine_mesh_attachment_get_vertices(_ptr);
    return ArrayFloat.fromPointer(result);
  }

  set vertices(ArrayFloat value) {
    _bindings.spine_mesh_attachment_set_vertices(_ptr, value.nativePtr.cast());
  }

  int get worldVerticesLength {
    final result = _bindings.spine_mesh_attachment_get_world_vertices_length(_ptr);
    return result;
  }

  set worldVerticesLength(int value) {
    _bindings.spine_mesh_attachment_set_world_vertices_length(_ptr, value);
  }

  Attachment get timelineAttachment {
    final result = _bindings.spine_mesh_attachment_get_timeline_attachment(_ptr);
    return Attachment.fromPointer(result);
  }

  set timelineAttachment(Attachment value) {
    _bindings.spine_mesh_attachment_set_timeline_attachment(_ptr, value.nativePtr.cast());
  }

  void copyTo(VertexAttachment other) {
    _bindings.spine_mesh_attachment_copy_to(_ptr, other.nativePtr.cast());
  }

  String get name {
    final result = _bindings.spine_mesh_attachment_get_name(_ptr);
    return result.cast<Utf8>().toDartString();
  }

  int get refCount {
    final result = _bindings.spine_mesh_attachment_get_ref_count(_ptr);
    return result;
  }

  void reference() {
    _bindings.spine_mesh_attachment_reference(_ptr);
  }

  void dereference() {
    _bindings.spine_mesh_attachment_dereference(_ptr);
  }

  static Rtti rttiStatic() {
    final result = _bindings.spine_mesh_attachment_rtti();
    return Rtti.fromPointer(result);
  }

  void computeWorldVertices(Skeleton skeleton, Slot slot, int start, int count, ArrayFloat worldVertices, int offset, int stride) {
    _bindings.spine_mesh_attachment_compute_world_vertices_2(_ptr, skeleton.nativePtr.cast(), slot.nativePtr.cast(), start, count, worldVertices.nativePtr.cast(), offset, stride);
  }

  void dispose() {
    _bindings.spine_mesh_attachment_dispose(_ptr);
  }
}