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

#include "rtti.h"
#include <spine/spine.h>

using namespace spine;

spine_rtti spine_rtti_create(const utf8 * className) {
    RTTI *obj = new (__FILE__, __LINE__) RTTI((const char *) className);
    return (spine_rtti) obj;
}

spine_rtti spine_rtti_create_with_string_rtti(const utf8 * className, spine_rtti baseRTTI) {
    RTTI *obj = new (__FILE__, __LINE__) RTTI((const char *) className, baseRTTI);
    return (spine_rtti) obj;
}

spine_rtti spine_rtti_create_with_string_rtti_rtti_rtti_rtti(const utf8 * className, spine_rtti baseRTTI, spine_const rtti interface1, spine_const rtti interface2, spine_const rtti interface3) {
    RTTI *obj = new (__FILE__, __LINE__) RTTI((const char *) className, baseRTTI, (const RTTI *) interface1, (const RTTI *) interface2, (const RTTI *) interface3);
    return (spine_rtti) obj;
}

void spine_rtti_dispose(spine_rtti obj) {
    if (!obj) return;
    delete (RTTI *) obj;
}

const utf8 * spine_rtti_get_class_name(spine_rtti obj) {
    if (!obj) return nullptr;
    RTTI *_obj = (RTTI *) obj;
    return (const utf8 *) _obj->getClassName();
}

spine_bool spine_rtti_is_exactly(spine_rtti obj, spine_rtti rtti) {
    if (!obj) return 0;
    RTTI *_obj = (RTTI *) obj;
    return _obj->isExactly(rtti);
}

spine_bool spine_rtti_instance_of(spine_rtti obj, spine_rtti rtti) {
    if (!obj) return 0;
    RTTI *_obj = (RTTI *) obj;
    return _obj->instanceOf(rtti);
}
