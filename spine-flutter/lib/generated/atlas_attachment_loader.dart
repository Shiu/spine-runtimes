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
import 'region_attachment.dart';
import 'skin.dart';
import 'sequence.dart';
import 'mesh_attachment.dart';
import 'bounding_box_attachment.dart';
import 'path_attachment.dart';
import 'point_attachment.dart';
import 'clipping_attachment.dart';
import 'atlas_region.dart';
import 'atlas.dart';

/// AtlasAttachmentLoader wrapper
class AtlasAttachmentLoader implements Finalizable {
  static late SpineFlutterBindings _bindings;
  final Pointer<spine_atlas_attachment_loader_wrapper> _ptr;

  /// Initialize the bindings for all spine-flutter classes
  static void init(SpineFlutterBindings bindings) {
    _bindings = bindings;
  }

  AtlasAttachmentLoader.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory AtlasAttachmentLoader(Atlas atlas) {
    final ptr = _bindings.spine_atlas_attachment_loader_create(atlas.nativePtr.cast());
    return AtlasAttachmentLoader.fromPointer(ptr);
  }

  RegionAttachment newRegionAttachment(Skin skin, String name, String path, Sequence sequence) {
    final result = _bindings.spine_atlas_attachment_loader_new_region_attachment(_ptr, skin.nativePtr.cast(), name.toNativeUtf8().cast<Char>(), path.toNativeUtf8().cast<Char>(), sequence.nativePtr.cast());
    return RegionAttachment.fromPointer(result);
  }

  MeshAttachment newMeshAttachment(Skin skin, String name, String path, Sequence sequence) {
    final result = _bindings.spine_atlas_attachment_loader_new_mesh_attachment(_ptr, skin.nativePtr.cast(), name.toNativeUtf8().cast<Char>(), path.toNativeUtf8().cast<Char>(), sequence.nativePtr.cast());
    return MeshAttachment.fromPointer(result);
  }

  BoundingBoxAttachment newBoundingBoxAttachment(Skin skin, String name) {
    final result = _bindings.spine_atlas_attachment_loader_new_bounding_box_attachment(_ptr, skin.nativePtr.cast(), name.toNativeUtf8().cast<Char>());
    return BoundingBoxAttachment.fromPointer(result);
  }

  PathAttachment newPathAttachment(Skin skin, String name) {
    final result = _bindings.spine_atlas_attachment_loader_new_path_attachment(_ptr, skin.nativePtr.cast(), name.toNativeUtf8().cast<Char>());
    return PathAttachment.fromPointer(result);
  }

  PointAttachment newPointAttachment(Skin skin, String name) {
    final result = _bindings.spine_atlas_attachment_loader_new_point_attachment(_ptr, skin.nativePtr.cast(), name.toNativeUtf8().cast<Char>());
    return PointAttachment.fromPointer(result);
  }

  ClippingAttachment newClippingAttachment(Skin skin, String name) {
    final result = _bindings.spine_atlas_attachment_loader_new_clipping_attachment(_ptr, skin.nativePtr.cast(), name.toNativeUtf8().cast<Char>());
    return ClippingAttachment.fromPointer(result);
  }

  AtlasRegion findRegion(String name) {
    final result = _bindings.spine_atlas_attachment_loader_find_region(_ptr, name.toNativeUtf8().cast<Char>());
    return AtlasRegion.fromPointer(result);
  }

  void dispose() {
    _bindings.spine_atlas_attachment_loader_dispose(_ptr);
  }
}