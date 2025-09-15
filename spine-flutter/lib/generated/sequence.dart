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

import 'package:universal_ffi/ffi.dart';
import 'package:universal_ffi/ffi_utils.dart';
import 'spine_dart_bindings_generated.dart';
import '../spine_bindings.dart';
import 'arrays.dart';
import 'attachment.dart';
import 'slot_pose.dart';

/// Sequence wrapper
class Sequence {
  final Pointer<spine_sequence_wrapper> _ptr;

  Sequence.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory Sequence(int count) {
    final ptr = SpineBindings.bindings.spine_sequence_create(count);
    return Sequence.fromPointer(ptr);
  }

  void dispose() {
    SpineBindings.bindings.spine_sequence_dispose(_ptr);
  }

  Sequence copy() {
    final result = SpineBindings.bindings.spine_sequence_copy(_ptr);
    return Sequence.fromPointer(result);
  }

  void apply(SlotPose? slot, Attachment? attachment) {
    SpineBindings.bindings.spine_sequence_apply(
        _ptr, slot?.nativePtr.cast() ?? Pointer.fromAddress(0), attachment?.nativePtr.cast() ?? Pointer.fromAddress(0));
  }

  String getPath(String basePath, int index) {
    final result = SpineBindings.bindings.spine_sequence_get_path(_ptr, basePath.toNativeUtf8().cast<Char>(), index);
    return result.cast<Utf8>().toDartString();
  }

  /// Returns a unique ID for this attachment.
  int get id {
    final result = SpineBindings.bindings.spine_sequence_get_id(_ptr);
    return result;
  }

  set id(int value) {
    SpineBindings.bindings.spine_sequence_set_id(_ptr, value);
  }

  int get start {
    final result = SpineBindings.bindings.spine_sequence_get_start(_ptr);
    return result;
  }

  set start(int value) {
    SpineBindings.bindings.spine_sequence_set_start(_ptr, value);
  }

  int get digits {
    final result = SpineBindings.bindings.spine_sequence_get_digits(_ptr);
    return result;
  }

  set digits(int value) {
    SpineBindings.bindings.spine_sequence_set_digits(_ptr, value);
  }

  /// The index of the region to show for the setup pose.
  int get setupIndex {
    final result = SpineBindings.bindings.spine_sequence_get_setup_index(_ptr);
    return result;
  }

  set setupIndex(int value) {
    SpineBindings.bindings.spine_sequence_set_setup_index(_ptr, value);
  }

  ArrayTextureRegion get regions {
    final result = SpineBindings.bindings.spine_sequence_get_regions(_ptr);
    return ArrayTextureRegion.fromPointer(result);
  }
}
