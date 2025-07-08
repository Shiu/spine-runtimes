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

#include "event_data.h"
#include <spine/spine.h>

using namespace spine;

spine_event_data spine_event_data_create(const utf8 * name) {
    EventData *obj = new (__FILE__, __LINE__) EventData(String(name));
    return (spine_event_data) obj;
}

void spine_event_data_dispose(spine_event_data obj) {
    if (!obj) return;
    delete (EventData *) obj;
}

const utf8 * spine_event_data_get_name(spine_event_data obj) {
    if (!obj) return nullptr;
    EventData *_obj = (EventData *) obj;
    return (const utf8 *) _obj->getName().buffer();
}

int32_t spine_event_data_get_int_value(spine_event_data obj) {
    if (!obj) return 0;
    EventData *_obj = (EventData *) obj;
    return _obj->getIntValue();
}

float spine_event_data_get_float_value(spine_event_data obj) {
    if (!obj) return 0;
    EventData *_obj = (EventData *) obj;
    return _obj->getFloatValue();
}

const utf8 * spine_event_data_get_string_value(spine_event_data obj) {
    if (!obj) return nullptr;
    EventData *_obj = (EventData *) obj;
    return (const utf8 *) _obj->getStringValue().buffer();
}

const utf8 * spine_event_data_get_audio_path(spine_event_data obj) {
    if (!obj) return nullptr;
    EventData *_obj = (EventData *) obj;
    return (const utf8 *) _obj->getAudioPath().buffer();
}

float spine_event_data_get_volume(spine_event_data obj) {
    if (!obj) return 0;
    EventData *_obj = (EventData *) obj;
    return _obj->getVolume();
}

float spine_event_data_get_balance(spine_event_data obj) {
    if (!obj) return 0;
    EventData *_obj = (EventData *) obj;
    return _obj->getBalance();
}
