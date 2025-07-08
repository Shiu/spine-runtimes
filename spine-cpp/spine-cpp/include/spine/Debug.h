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

#ifndef SPINE_LOG_H
#define SPINE_LOG_H

#include <spine/Extension.h>
#include <spine/Vector.h>
#include <spine/HashMap.h>

namespace spine {

	class SP_API DebugExtension : public SpineExtension {
		struct Allocation {
			void *address;
			size_t size;
			const char *fileName;
			int line;

			Allocation() : address(NULL), size(0), fileName(NULL), line(0) {
			}

			Allocation(void *a, size_t s, const char *f, int l) : address(a), size(s), fileName(f), line(l) {
			}
		};

	public:
		DebugExtension(SpineExtension *extension) : _extension(extension), _allocations(0), _reallocations(0),
													_frees(0) {
		}

		void reportLeaks() {
			HashMap<void *, Allocation>::Entries entries = _allocated.getEntries();
			while (entries.hasNext()) {
				HashMap<void *, Allocation>::Pair pair = entries.next();
				printf("\"%s:%i (%zu bytes at %p)\n", pair.value.fileName, pair.value.line, pair.value.size,
					   pair.value.address);
			}
			printf("allocations: %zu, reallocations: %zu, frees: %zu\n", _allocations, _reallocations, _frees);
			if (_allocated.size() == 0) printf("No leaks detected\n");
		}

		void clearAllocations() {
			_allocated.clear();
			_usedMemory = 0;
		}

		virtual void *_alloc(size_t size, const char *file, int line) {
			void *result = _extension->_alloc(size, file, line);
			_allocated.put(result, Allocation(result, size, file, line));
			_allocations++;
			_usedMemory += size;
			return result;
		}

		virtual void *_calloc(size_t size, const char *file, int line) {
			void *result = _extension->_calloc(size, file, line);
			_allocated.put(result, Allocation(result, size, file, line));
			_allocations++;
			_usedMemory += size;
			return result;
		}

		virtual void *_realloc(void *ptr, size_t size, const char *file, int line) {
			if (_allocated.containsKey(ptr)) {
				// Find and store the size before removing
				HashMap<void *, Allocation>::Entries entries = _allocated.getEntries();
				while (entries.hasNext()) {
					HashMap<void *, Allocation>::Pair pair = entries.next();
					if (pair.key == ptr) {
						_usedMemory -= pair.value.size;
						break;
					}
				}
				_allocated.remove(ptr);
			}
			void *result = _extension->_realloc(ptr, size, file, line);
			_reallocations++;
			_allocated.put(result, Allocation(result, size, file, line));
			_usedMemory += size;
			return result;
		}

		virtual void _free(void *mem, const char *file, int line) {
			if (_allocated.containsKey(mem)) {
				_extension->_free(mem, file, line);
				_frees++;
				// Find and store the size before removing
				HashMap<void *, Allocation>::Entries entries = _allocated.getEntries();
				while (entries.hasNext()) {
					HashMap<void *, Allocation>::Pair pair = entries.next();
					if (pair.key == mem) {
						_usedMemory -= pair.value.size;
						break;
					}
				}
				_allocated.remove(mem);
				return;
			}

			printf("%s:%i (address %p): Double free or not allocated through SpineExtension\n", file, line, mem);
			_extension->_free(mem, file, line);
		}

		virtual char *_readFile(const String &path, int *length) {
            auto data = _extension->_readFile(path, length);

            if (!_allocated.containsKey(data)) {
                _allocated.put(data, Allocation(data, sizeof(char) * (*length), nullptr, 0));
                _allocations++;
                _usedMemory += sizeof(char) * (*length);
            }

            return data;
		}

		size_t getUsedMemory() {
			return _usedMemory;
		}

	private:
		SpineExtension *_extension;
		HashMap<void *, Allocation> _allocated;
		size_t _allocations;
		size_t _reallocations;
		size_t _frees;
		size_t _usedMemory;
	};
}


#endif //SPINE_LOG_H
