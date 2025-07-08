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

spine_event_data spine_event_data_create(const char* name) {
    EventData *obj = new (__FILE__, __LINE__) EventData(String(name));
    return (spine_event_data) obj;
}

void spine_event_data_dispose(spine_event_data obj) {
    if (!obj) return;
    delete (EventData *) obj;
}

const char* spine_event_data_get_name(spine_event_data obj) {
    if (!obj) return nullptr;
    EventData *_obj = (EventData *) obj;
    return (const char *) _obj->getName().buffer();
}

int spine_event_data_get_int_value(spine_event_data obj) {
    if (!obj) return 0;
    EventData *_obj = (EventData *) obj;
    return _obj->getIntValue();
}

void spine_event_data_set_int_value(spine_event_data obj, int value) {
    if (!obj) return;
    EventData *_obj = (EventData *) obj;
    _obj->setIntValue(value);
}

float spine_event_data_get_float_value(spine_event_data obj) {
    if (!obj) return 0;
    EventData *_obj = (EventData *) obj;
    return _obj->getFloatValue();
}

void spine_event_data_set_float_value(spine_event_data obj, float value) {
    if (!obj) return;
    EventData *_obj = (EventData *) obj;
    _obj->setFloatValue(value);
}

const char* spine_event_data_get_string_value(spine_event_data obj) {
    if (!obj) return nullptr;
    EventData *_obj = (EventData *) obj;
    return (const char *) _obj->getStringValue().buffer();
}

void spine_event_data_set_string_value(spine_event_data obj, const char* value) {
    if (!obj) return;
    EventData *_obj = (EventData *) obj;
    _obj->setStringValue(String(value));
}

const char* spine_event_data_get_audio_path(spine_event_data obj) {
    if (!obj) return nullptr;
    EventData *_obj = (EventData *) obj;
    return (const char *) _obj->getAudioPath().buffer();
}

void spine_event_data_set_audio_path(spine_event_data obj, const char* value) {
    if (!obj) return;
    EventData *_obj = (EventData *) obj;
    _obj->setAudioPath(String(value));
}

float spine_event_data_get_volume(spine_event_data obj) {
    if (!obj) return 0;
    EventData *_obj = (EventData *) obj;
    return _obj->getVolume();
}

void spine_event_data_set_volume(spine_event_data obj, float value) {
    if (!obj) return;
    EventData *_obj = (EventData *) obj;
    _obj->setVolume(value);
}

float spine_event_data_get_balance(spine_event_data obj) {
    if (!obj) return 0;
    EventData *_obj = (EventData *) obj;
    return _obj->getBalance();
}

void spine_event_data_set_balance(spine_event_data obj, float value) {
    if (!obj) return;
    EventData *_obj = (EventData *) obj;
    _obj->setBalance(value);
}
