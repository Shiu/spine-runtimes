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
import 'spine_flutter_bindings_generated.dart';
import '../spine_bindings.dart';
import 'mesh_attachment.dart';

/// LinkedMesh wrapper
class LinkedMesh implements Finalizable {
  final Pointer<spine_linked_mesh_wrapper> _ptr;

  LinkedMesh.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory LinkedMesh(MeshAttachment mesh, dynamic skinIndex, int slotIndex, String parent, bool inheritTimelines) {
    final ptr = SpineBindings.bindings.spine_linked_mesh_create(mesh.nativePtr.cast(), skinIndex, slotIndex, parent.toNativeUtf8().cast<Char>(), inheritTimelines);
    return LinkedMesh.fromPointer(ptr);
  }

  factory LinkedMesh.variant2(MeshAttachment mesh, String skin, int slotIndex, String parent, bool inheritTimelines) {
    final ptr = SpineBindings.bindings.spine_linked_mesh_create2(mesh.nativePtr.cast(), skin.toNativeUtf8().cast<Char>(), slotIndex, parent.toNativeUtf8().cast<Char>(), inheritTimelines);
    return LinkedMesh.fromPointer(ptr);
  }

  void dispose() {
    SpineBindings.bindings.spine_linked_mesh_dispose(_ptr);
  }
}