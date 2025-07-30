import 'web_ffi/web_ffi.dart';
import 'web_ffi/web_ffi_modules.dart';

/// Web implementation of malloc that uses the Memory allocator
/// Memory.global will be set when the DynamicLibrary is loaded
Allocator get malloc {
  if (Memory.global == null) {
    throw StateError('Memory.global is not initialized. Make sure spine is initialized before using malloc.');
  }
  return Memory.global!;
}
