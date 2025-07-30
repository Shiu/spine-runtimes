import 'package:wasm_ffi/ffi.dart';
import 'spine_dart_init_web.dart';

/// Web implementation of malloc that uses the DynamicLibrary's allocator
/// The allocator will be available after spine is initialized
Allocator get malloc {
  // Get the allocator from the current dylib
  final dylib = dylibInstance;
  if (dylib == null) {
    throw StateError('DynamicLibrary is not initialized. Make sure spine is initialized before using malloc.');
  }
  return dylib.allocator;
}
