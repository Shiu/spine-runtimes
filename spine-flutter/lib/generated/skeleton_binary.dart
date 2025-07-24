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
import 'atlas.dart';
import 'attachment_loader.dart';
import 'skeleton_data.dart';

/// SkeletonBinary wrapper
class SkeletonBinary {
  final Pointer<spine_skeleton_binary_wrapper> _ptr;

  SkeletonBinary.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory SkeletonBinary(Atlas atlas) {
    final ptr = SpineBindings.bindings.spine_skeleton_binary_create(atlas.nativePtr.cast());
    return SkeletonBinary.fromPointer(ptr);
  }

  factory SkeletonBinary.variant2(AttachmentLoader attachmentLoader, bool ownsLoader) {
    final ptr = SpineBindings.bindings.spine_skeleton_binary_create2(attachmentLoader.nativePtr.cast(), ownsLoader);
    return SkeletonBinary.fromPointer(ptr);
  }

  void dispose() {
    SpineBindings.bindings.spine_skeleton_binary_dispose(_ptr);
  }

  SkeletonData readSkeletonDataFile(String path) {
    final result =
        SpineBindings.bindings.spine_skeleton_binary_read_skeleton_data_file(_ptr, path.toNativeUtf8().cast<Char>());
    return SkeletonData.fromPointer(result);
  }

  set scale(double value) {
    SpineBindings.bindings.spine_skeleton_binary_set_scale(_ptr, value);
  }

  String get error {
    final result = SpineBindings.bindings.spine_skeleton_binary_get_error(_ptr);
    return result.cast<Utf8>().toDartString();
  }
}
