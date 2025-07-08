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

#ifndef SPINE_C_EVENT_H
#define SPINE_C_EVENT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"

SPINE_C_EXPORT spine_event spine_event_create(float time, spine_event_data data);
SPINE_C_EXPORT void spine_event_dispose(spine_event obj);
SPINE_C_EXPORT spine_event_data spine_event_get_data(spine_event obj);
SPINE_C_EXPORT float spine_event_get_time(spine_event obj);
SPINE_C_EXPORT int spine_event_get_int(spine_event obj);
SPINE_C_EXPORT void spine_event_set_int(spine_event obj, int value);
SPINE_C_EXPORT float spine_event_get_float(spine_event obj);
SPINE_C_EXPORT void spine_event_set_float(spine_event obj, float value);
SPINE_C_EXPORT const char* spine_event_get_string(spine_event obj);
SPINE_C_EXPORT void spine_event_set_string(spine_event obj, const char* value);
SPINE_C_EXPORT float spine_event_get_volume(spine_event obj);
SPINE_C_EXPORT void spine_event_set_volume(spine_event obj, float value);
SPINE_C_EXPORT float spine_event_get_balance(spine_event obj);
SPINE_C_EXPORT void spine_event_set_balance(spine_event obj, float value);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_EVENT_H