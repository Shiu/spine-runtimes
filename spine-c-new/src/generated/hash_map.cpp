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

#include "hash_map.h"
#include <spine/spine.h>

using namespace spine;

spine_hash_map spine_hash_map_create(void) {
    HashMap *obj = new (__FILE__, __LINE__) HashMap();
    return (spine_hash_map) obj;
}

void spine_hash_map_dispose(spine_hash_map obj) {
    if (!obj) return;
    delete (HashMap *) obj;
}

void spine_hash_map_clear(spine_hash_map obj) {
    if (!obj) return ;
    HashMap *_obj = (HashMap *) obj;
    _obj->clear();
}

spine_size_t spine_hash_map_size(spine_hash_map obj) {
    if (!obj) return nullptr;
    HashMap *_obj = (HashMap *) obj;
    return _obj->size();
}

void spine_hash_map_put(spine_hash_map obj, spine_k key, spine_v value) {
    if (!obj) return ;
    HashMap *_obj = (HashMap *) obj;
    _obj->put(key, value);
}

spine_bool spine_hash_map_add_all(spine_hash_map obj, void * keys, spine_v value) {
    if (!obj) return 0;
    HashMap *_obj = (HashMap *) obj;
    return _obj->addAll((Vector<K> &) keys, value);
}

spine_bool spine_hash_map_contains_key(spine_hash_map obj, spine_k key) {
    if (!obj) return 0;
    HashMap *_obj = (HashMap *) obj;
    return _obj->containsKey(key);
}

spine_bool spine_hash_map_remove(spine_hash_map obj, spine_k key) {
    if (!obj) return 0;
    HashMap *_obj = (HashMap *) obj;
    return _obj->remove(key);
}

spine_entries spine_hash_map_get_entries(spine_hash_map obj) {
    if (!obj) return nullptr;
    HashMap *_obj = (HashMap *) obj;
    return _obj->getEntries();
}
