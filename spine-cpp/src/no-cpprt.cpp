/******************************************************************************
 * Spine Runtimes License Agreement
 * Last updated April 5, 2025. Replaces all prior versions.
 *
 * Copyright (c) 2013-2025, Esoteric Software LLC
 *
 * Integration of the Spine Runtimes into software or otherwise creating
 * derivative works of the Spine Runtimes is permitted under the terms and
 * conditions of Section 2 of the Spine Editor License Agreement:
 * http://esotericsoftware.com/spine-editor-license
 *
 * Otherwise, it is permitted to integrate the Spine Runtimes into software
 * or otherwise create derivative works of the Spine Runtimes (collectively,
 * "Products"), provided that each user of the Products must obtain their own
 * Spine Editor license and redistribution of the Products in any form must
 * include this license and copyright notice.
 *
 * THE SPINE RUNTIMES ARE PROVIDED BY ESOTERIC SOFTWARE LLC "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ESOTERIC SOFTWARE LLC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES,
 * BUSINESS INTERRUPTION, OR LOSS OF USE, DATA, OR PROFITS) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THE SPINE RUNTIMES, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

// Avoid including any standard headers for maximum portability
#ifdef __cplusplus
extern "C" {
#endif
typedef __SIZE_TYPE__ size_t;
#ifdef __cplusplus
}
#endif

// Stubs for C++ stdlib functions spine-cpp depends on. Used for nostdcpp builds.
// These are weak symbols to allow overriding in custom builds, e.g. headless-test-nostdcpp
// where the main app still requires C++.

extern "C" {
    void* malloc(size_t size);
    void free(void* ptr);
}

__attribute__((weak)) void* operator new(size_t size) {
    return malloc(size);
}

__attribute__((weak)) void operator delete(void* ptr) {
    if (ptr) free(ptr);
}

extern "C" __attribute__((weak)) int __cxa_guard_acquire(char* guard) {
    return *guard == 0 ? (*guard = 1, 1) : 0;
}

extern "C" __attribute__((weak)) void __cxa_guard_release(char* guard) {
    // No-op for single-threaded
    (void)guard;
}

extern "C" __attribute__((weak)) void __cxa_pure_virtual() {
}

extern "C" __attribute__((weak)) char __stack_chk_guard = 0;
extern "C" __attribute__((weak)) void __stack_chk_fail() {
}