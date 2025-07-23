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
import 'atlas_page.dart';
import 'arrays.dart';

/// AtlasRegion wrapper
class AtlasRegion implements Finalizable {
  static late SpineFlutterBindings _bindings;
  final Pointer<spine_atlas_region_wrapper> _ptr;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  AtlasRegion.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory AtlasRegion() {
    final ptr = _bindings.spine_atlas_region_create();
    return AtlasRegion.fromPointer(ptr);
  }

  Rtti get rtti {
    final result = _bindings.spine_atlas_region_get_rtti(_ptr);
    return Rtti.fromPointer(result);
  }

  AtlasPage get page {
    final result = _bindings.spine_atlas_region_get_page(_ptr);
    return AtlasPage.fromPointer(result);
  }

  int get index {
    final result = _bindings.spine_atlas_region_get_index(_ptr);
    return result;
  }

  int get x {
    final result = _bindings.spine_atlas_region_get_x(_ptr);
    return result;
  }

  int get y {
    final result = _bindings.spine_atlas_region_get_y(_ptr);
    return result;
  }

  double get offsetX {
    final result = _bindings.spine_atlas_region_get_offset_x(_ptr);
    return result;
  }

  double get offsetY {
    final result = _bindings.spine_atlas_region_get_offset_y(_ptr);
    return result;
  }

  int get packedWidth {
    final result = _bindings.spine_atlas_region_get_packed_width(_ptr);
    return result;
  }

  int get packedHeight {
    final result = _bindings.spine_atlas_region_get_packed_height(_ptr);
    return result;
  }

  int get originalWidth {
    final result = _bindings.spine_atlas_region_get_original_width(_ptr);
    return result;
  }

  int get originalHeight {
    final result = _bindings.spine_atlas_region_get_original_height(_ptr);
    return result;
  }

  bool get rotate {
    final result = _bindings.spine_atlas_region_get_rotate(_ptr);
    return result;
  }

  int get degrees {
    final result = _bindings.spine_atlas_region_get_degrees(_ptr);
    return result;
  }

  ArrayInt get splits {
    final result = _bindings.spine_atlas_region_get_splits(_ptr);
    return ArrayInt.fromPointer(result);
  }

  ArrayInt get pads {
    final result = _bindings.spine_atlas_region_get_pads(_ptr);
    return ArrayInt.fromPointer(result);
  }

  ArrayFloat get values {
    final result = _bindings.spine_atlas_region_get_values(_ptr);
    return ArrayFloat.fromPointer(result);
  }

  set page(AtlasPage value) {
    _bindings.spine_atlas_region_set_page(_ptr, value.nativePtr.cast());
  }

  set name(String value) {
    _bindings.spine_atlas_region_set_name(_ptr, value.toNativeUtf8().cast<Char>());
  }

  set index(int value) {
    _bindings.spine_atlas_region_set_index(_ptr, value);
  }

  set x(int value) {
    _bindings.spine_atlas_region_set_x(_ptr, value);
  }

  set y(int value) {
    _bindings.spine_atlas_region_set_y(_ptr, value);
  }

  set offsetX(double value) {
    _bindings.spine_atlas_region_set_offset_x(_ptr, value);
  }

  set offsetY(double value) {
    _bindings.spine_atlas_region_set_offset_y(_ptr, value);
  }

  set packedWidth(int value) {
    _bindings.spine_atlas_region_set_packed_width(_ptr, value);
  }

  set packedHeight(int value) {
    _bindings.spine_atlas_region_set_packed_height(_ptr, value);
  }

  set originalWidth(int value) {
    _bindings.spine_atlas_region_set_original_width(_ptr, value);
  }

  set originalHeight(int value) {
    _bindings.spine_atlas_region_set_original_height(_ptr, value);
  }

  set rotate(bool value) {
    _bindings.spine_atlas_region_set_rotate(_ptr, value);
  }

  set degrees(int value) {
    _bindings.spine_atlas_region_set_degrees(_ptr, value);
  }

  set splits(ArrayInt value) {
    _bindings.spine_atlas_region_set_splits(_ptr, value.nativePtr.cast());
  }

  set pads(ArrayInt value) {
    _bindings.spine_atlas_region_set_pads(_ptr, value.nativePtr.cast());
  }

  set values(ArrayFloat value) {
    _bindings.spine_atlas_region_set_values(_ptr, value.nativePtr.cast());
  }

  double get u {
    final result = _bindings.spine_atlas_region_get_u(_ptr);
    return result;
  }

  set u(double value) {
    _bindings.spine_atlas_region_set_u(_ptr, value);
  }

  double get v {
    final result = _bindings.spine_atlas_region_get_v(_ptr);
    return result;
  }

  set v(double value) {
    _bindings.spine_atlas_region_set_v(_ptr, value);
  }

  double get u2 {
    final result = _bindings.spine_atlas_region_get_u2(_ptr);
    return result;
  }

  set u2(double value) {
    _bindings.spine_atlas_region_set_u2(_ptr, value);
  }

  double get v2 {
    final result = _bindings.spine_atlas_region_get_v2(_ptr);
    return result;
  }

  set v2(double value) {
    _bindings.spine_atlas_region_set_v2(_ptr, value);
  }

  int get regionWidth {
    final result = _bindings.spine_atlas_region_get_region_width(_ptr);
    return result;
  }

  set regionWidth(int value) {
    _bindings.spine_atlas_region_set_region_width(_ptr, value);
  }

  int get regionHeight {
    final result = _bindings.spine_atlas_region_get_region_height(_ptr);
    return result;
  }

  set regionHeight(int value) {
    _bindings.spine_atlas_region_set_region_height(_ptr, value);
  }

  static Rtti rttiStatic() {
    final result = _bindings.spine_atlas_region_rtti();
    return Rtti.fromPointer(result);
  }

  void dispose() {
    _bindings.spine_atlas_region_dispose(_ptr);
  }
}