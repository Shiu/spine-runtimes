import 'dart:ffi';
import 'package:ffi/ffi.dart';
import 'generated/atlas.dart';
import 'generated/skeleton_data.dart';
import 'spine_bindings.dart';

// Atlas Extensions
extension AtlasExtensions on Atlas {
  /// Creates an Atlas from atlas data string (without loading images)
  static Atlas fromString(String atlasData) {
    final atlasDataNative = atlasData.toNativeUtf8();
    final atlasPtr = SpineBindings.bindings.spine_atlas_load(atlasDataNative.cast<Char>());
    malloc.free(atlasDataNative);
    return Atlas.fromPointer(atlasPtr);
  }

  /// Dispose the atlas and free its memory
  void dispose() {
    SpineBindings.bindings.spine_atlas_dispose(nativePtr.cast());
  }
}

// Skeleton Data Result wrapper
class SkeletonDataResult {
  final String? error;
  final SkeletonData? skeletonData;
  final Pointer? _resultPtr;

  SkeletonDataResult._(this.error, this.skeletonData, this._resultPtr);

  void dispose() {
    if (_resultPtr != null) {
      SpineBindings.bindings.spine_skeleton_data_result_dispose(_resultPtr!.cast());
    }
  }
}

// Skeleton Data Extensions
extension SkeletonDataExtensions on SkeletonData {
  /// Load skeleton data from JSON string
  static SkeletonDataResult fromJson(Atlas atlas, String jsonData, {String? path}) {
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
      return SkeletonDataResult._(error, null, resultPtr);
    }

    // Get skeleton data
    final skeletonDataPtr = SpineBindings.bindings.spine_skeleton_data_result_get_data(resultPtr.cast());
    final skeletonData = SkeletonData.fromPointer(skeletonDataPtr);

    return SkeletonDataResult._(null, skeletonData, resultPtr);
  }
}
