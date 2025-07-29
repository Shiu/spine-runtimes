/// Spine Runtimes License Agreement
/// Last updated April 5, 2025. Replaces all prior versions.
///
/// Copyright (c) 2013-2025, Esoteric Software LLC
///
/// Integration of the Spine Runtimes into software or otherwise creating
/// derivative works of the Spine Runtimes is permitted under the terms and
/// conditions of Section 2 of the Spine Editor License Agreement:
/// http://esotericsoftware.com/spine-editor-license
///
/// Otherwise, it is permitted to integrate the Spine Runtimes into software
/// or otherwise create derivative works of the Spine Runtimes (collectively,
/// "Products"), provided that each user of the Products must obtain their own
/// Spine Editor license and redistribution of the Products in any form must
/// include this license and copyright notice.
///
/// THE SPINE RUNTIMES ARE PROVIDED BY ESOTERIC SOFTWARE LLC "AS IS" AND ANY
/// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
/// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
/// DISCLAIMED. IN NO EVENT SHALL ESOTERIC SOFTWARE LLC BE LIABLE FOR ANY
/// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
/// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES,
/// BUSINESS INTERRUPTION, OR LOSS OF USE, DATA, OR PROFITS) HOWEVER CAUSED AND
/// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
/// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
/// THE SPINE RUNTIMES, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
library;

import 'generated/spine_dart_bindings_generated.dart';
import 'spine_bindings.dart';
import 'spine_dart_init.dart' if (dart.library.html) 'spine_flutter_init_web.dart';
import 'dart:ffi';
import 'dart:typed_data';
import 'package:ffi/ffi.dart';
import 'generated/atlas.dart';
import 'generated/skeleton_data.dart';
import 'generated/skin.dart';
import 'generated/attachment.dart';
import 'generated/region_attachment.dart';
import 'generated/mesh_attachment.dart';
import 'generated/bounding_box_attachment.dart';
import 'generated/clipping_attachment.dart';
import 'generated/path_attachment.dart';
import 'generated/point_attachment.dart';
import 'generated/rtti.dart';

// Export generated classes
export 'generated/api.dart';
export 'generated/spine_dart_bindings_generated.dart';
export 'spine_bindings.dart';

Future<void> initSpineDart({bool useStaticLinkage = false, bool enableMemoryDebugging = false}) async {
  final ffi = await initSpineDartFFI(useStaticLinkage);
  final bindings = SpineDartBindings(ffi.dylib);
  if (enableMemoryDebugging) bindings.spine_enable_debug_extension(true);

  // Initialize the global bindings for generated code
  SpineBindings.init(bindings);

  return;
}

int majorVersion() => SpineBindings.bindings.spine_major_version();

int minorVersion() => SpineBindings.bindings.spine_minor_version();

void reportLeaks() => SpineBindings.bindings.spine_report_leaks();

/// Load an Atlas from atlas data string
Atlas loadAtlas(String atlasData) {
  final atlasDataNative = atlasData.toNativeUtf8();
  final resultPtr = SpineBindings.bindings.spine_atlas_load(atlasDataNative.cast<Char>());
  malloc.free(atlasDataNative);

  // Check for error
  final errorPtr = SpineBindings.bindings.spine_atlas_result_get_error(resultPtr.cast());
  if (errorPtr != nullptr) {
    final error = errorPtr.cast<Utf8>().toDartString();
    SpineBindings.bindings.spine_atlas_result_dispose(resultPtr.cast());
    throw Exception("Couldn't load atlas: $error");
  }

  // Get atlas
  final atlasPtr = SpineBindings.bindings.spine_atlas_result_get_atlas(resultPtr.cast());
  final atlas = Atlas.fromPointer(atlasPtr);
  SpineBindings.bindings.spine_atlas_result_dispose(resultPtr.cast());
  return atlas;
}

/// Load skeleton data from JSON string
SkeletonData loadSkeletonDataJson(Atlas atlas, String jsonData, {String? path}) {
  final jsonDataNative = jsonData.toNativeUtf8();
  final pathNative = (path ?? '').toNativeUtf8();

  final resultPtr = SpineBindings.bindings
      .spine_skeleton_data_load_json(atlas.nativePtr.cast(), jsonDataNative.cast<Char>(), pathNative.cast<Char>());

  malloc.free(jsonDataNative);
  malloc.free(pathNative);

  // Check for error
  final errorPtr = SpineBindings.bindings.spine_skeleton_data_result_get_error(resultPtr.cast());
  if (errorPtr != nullptr) {
    final error = errorPtr.cast<Utf8>().toDartString();
    SpineBindings.bindings.spine_skeleton_data_result_dispose(resultPtr.cast());
    throw Exception("Couldn't load skeleton data: $error");
  }

  // Get skeleton data
  final skeletonDataPtr = SpineBindings.bindings.spine_skeleton_data_result_get_data(resultPtr.cast());
  final skeletonData = SkeletonData.fromPointer(skeletonDataPtr);
  SpineBindings.bindings.spine_skeleton_data_result_dispose(resultPtr.cast());
  return skeletonData;
}

/// Load skeleton data from binary data
SkeletonData loadSkeletonDataBinary(Atlas atlas, Uint8List binaryData, {String? path}) {
  final Pointer<Uint8> binaryNative = malloc.allocate(binaryData.lengthInBytes);
  binaryNative.asTypedList(binaryData.lengthInBytes).setAll(0, binaryData);
  final pathNative = (path ?? '').toNativeUtf8();

  final resultPtr = SpineBindings.bindings.spine_skeleton_data_load_binary(
      atlas.nativePtr.cast(), binaryNative.cast(), binaryData.lengthInBytes, pathNative.cast<Char>());

  malloc.free(binaryNative);
  malloc.free(pathNative);

  // Check for error
  final errorPtr = SpineBindings.bindings.spine_skeleton_data_result_get_error(resultPtr.cast());
  if (errorPtr != nullptr) {
    final error = errorPtr.cast<Utf8>().toDartString();
    SpineBindings.bindings.spine_skeleton_data_result_dispose(resultPtr.cast());
    throw Exception("Couldn't load skeleton data: $error");
  }

  // Get skeleton data
  final skeletonDataPtr = SpineBindings.bindings.spine_skeleton_data_result_get_data(resultPtr.cast());
  final skeletonData = SkeletonData.fromPointer(skeletonDataPtr);
  SpineBindings.bindings.spine_skeleton_data_result_dispose(resultPtr.cast());
  return skeletonData;
}

/// Represents an entry in a skin
class SkinEntry {
  final int slotIndex;
  final String name;
  final Attachment? attachment;

  SkinEntry._({required this.slotIndex, required this.name, required this.attachment});
}

/// Extension method for Skin to get all entries
extension SkinExtensions on Skin {
  /// Get all entries (slot/attachment pairs) in this skin
  List<SkinEntry> getEntries() {
    final entriesPtr = SpineBindings.bindings.spine_skin_get_entries(nativePtr.cast());
    if (entriesPtr == nullptr) return [];

    try {
      final numEntries = SpineBindings.bindings.spine_skin_entries_get_num_entries(entriesPtr.cast());
      final entries = <SkinEntry>[];

      for (int i = 0; i < numEntries; i++) {
        final entryPtr = SpineBindings.bindings.spine_skin_entries_get_entry(entriesPtr.cast(), i);
        if (entryPtr != nullptr) {
          final slotIndex = SpineBindings.bindings.spine_skin_entry_get_slot_index(entryPtr.cast());
          final namePtr = SpineBindings.bindings.spine_skin_entry_get_name(entryPtr.cast());
          final name = namePtr.cast<Utf8>().toDartString();
          
          final attachmentPtr = SpineBindings.bindings.spine_skin_entry_get_attachment(entryPtr.cast());
          Attachment? attachment;
          if (attachmentPtr.address != 0) {
            // Use RTTI to determine the concrete attachment type
            final rtti = SpineBindings.bindings.spine_attachment_get_rtti(attachmentPtr);
            final className = SpineBindings.bindings.spine_rtti_get_class_name(rtti).cast<Utf8>().toDartString();
            
            switch (className) {
              case 'spine_region_attachment':
                attachment = RegionAttachment.fromPointer(attachmentPtr.cast());
                break;
              case 'spine_mesh_attachment':
                attachment = MeshAttachment.fromPointer(attachmentPtr.cast());
                break;
              case 'spine_bounding_box_attachment':
                attachment = BoundingBoxAttachment.fromPointer(attachmentPtr.cast());
                break;
              case 'spine_clipping_attachment':
                attachment = ClippingAttachment.fromPointer(attachmentPtr.cast());
                break;
              case 'spine_path_attachment':
                attachment = PathAttachment.fromPointer(attachmentPtr.cast());
                break;
              case 'spine_point_attachment':
                attachment = PointAttachment.fromPointer(attachmentPtr.cast());
                break;
              default:
                // Unknown attachment type, treat as generic Attachment
                attachment = null;
            }
          }

          entries.add(SkinEntry._(
            slotIndex: slotIndex,
            name: name,
            attachment: attachment,
          ));
        }
      }

      return entries;
    } finally {
      SpineBindings.bindings.spine_skin_entries_dispose(entriesPtr.cast());
    }
  }
}
