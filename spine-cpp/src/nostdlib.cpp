/*
 * Minimal runtime stubs for nostdlib spine-cpp build
 * 
 * Provides minimal implementations of C++ runtime symbols required
 * for spine-cpp to work without the standard library.
 */

#include <cstddef>

// ============================================================================
// C++ Runtime Stubs
// ============================================================================

// Memory operators - basic malloc/free wrappers
// Note: These require a C library that provides malloc/free
extern "C" {
    void* malloc(size_t size);
    void free(void* ptr);
}

// Memory operators - use malloc/free but with careful implementation
// Make them weak so system can override if needed
__attribute__((weak)) void* operator new(size_t size) {
    return malloc(size);
}

__attribute__((weak)) void operator delete(void* ptr) {
    if (ptr) free(ptr);
}

// Static initialization guards (single-threaded stubs)
// Make them weak so system can override if needed
extern "C" __attribute__((weak)) int __cxa_guard_acquire(char* guard) {
    return *guard == 0 ? (*guard = 1, 1) : 0;
}

extern "C" __attribute__((weak)) void __cxa_guard_release(char* guard) {
    // No-op for single-threaded
    (void)guard;
}

// Pure virtual function handler
extern "C" __attribute__((weak)) void __cxa_pure_virtual() {
    // In a real implementation, this would abort or throw
    // For minimal stub, we'll just return (undefined behavior but won't crash)
    // This should never be called in a correctly written program
}

// Stack protection (for GCC -fstack-protector)
// Make it weak so libc can override it in static builds
extern "C" __attribute__((weak)) char __stack_chk_guard = 0;
extern "C" __attribute__((weak)) void __stack_chk_fail() {
    // Could call abort() or be no-op for minimal runtime
}