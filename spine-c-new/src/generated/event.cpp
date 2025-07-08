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

#include "event.h"
#include <spine/spine.h>

using namespace spine;

spine_event spine_event_create(float time, spine_event_data data) {
    Event *obj = new (__FILE__, __LINE__) Event(time, data);
    return (spine_event) obj;
}

void spine_event_dispose(spine_event obj) {
    if (!obj) return;
    delete (Event *) obj;
}

spine_event_data spine_event_get_data(spine_event obj) {
    if (!obj) return nullptr;
    Event *_obj = (Event *) obj;
    return _obj->getData();
}

float spine_event_get_time(spine_event obj) {
    if (!obj) return 0;
    Event *_obj = (Event *) obj;
    return _obj->getTime();
}

int32_t spine_event_get_int(spine_event obj) {
    if (!obj) return 0;
    Event *_obj = (Event *) obj;
    return _obj->getInt();
}

void spine_event_set_int(spine_event obj, int32_t value) {
    if (!obj) return;
    Event *_obj = (Event *) obj;
    _obj->setInt(value);
}

float spine_event_get_float(spine_event obj) {
    if (!obj) return 0;
    Event *_obj = (Event *) obj;
    return _obj->getFloat();
}

void spine_event_set_float(spine_event obj, float value) {
    if (!obj) return;
    Event *_obj = (Event *) obj;
    _obj->setFloat(value);
}

const utf8 * spine_event_get_string(spine_event obj) {
    if (!obj) return nullptr;
    Event *_obj = (Event *) obj;
    return (const utf8 *) _obj->getString().buffer();
}

void spine_event_set_string(spine_event obj, const utf8 * value) {
    if (!obj) return;
    Event *_obj = (Event *) obj;
    _obj->setString(String(value));
}

float spine_event_get_volume(spine_event obj) {
    if (!obj) return 0;
    Event *_obj = (Event *) obj;
    return _obj->getVolume();
}

void spine_event_set_volume(spine_event obj, float value) {
    if (!obj) return;
    Event *_obj = (Event *) obj;
    _obj->setVolume(value);
}

float spine_event_get_balance(spine_event obj) {
    if (!obj) return 0;
    Event *_obj = (Event *) obj;
    return _obj->getBalance();
}

void spine_event_set_balance(spine_event obj, float value) {
    if (!obj) return;
    Event *_obj = (Event *) obj;
    _obj->setBalance(value);
}
