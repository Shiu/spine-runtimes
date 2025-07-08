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

#ifndef SPINE_C_ANIMATIONSTATEDATA_H
#define SPINE_C_ANIMATIONSTATEDATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"

SPINE_C_EXPORT spine_animation_state_data spine_animation_state_data_create(spine_skeleton_data skeletonData);
SPINE_C_EXPORT void spine_animation_state_data_dispose(spine_animation_state_data obj);
SPINE_C_EXPORT spine_skeleton_data spine_animation_state_data_get_skeleton_data(spine_animation_state_data obj);
SPINE_C_EXPORT float spine_animation_state_data_get_default_mix(spine_animation_state_data obj);
SPINE_C_EXPORT void spine_animation_state_data_set_default_mix(spine_animation_state_data obj, float value);
SPINE_C_EXPORT void spine_animation_state_data_set_mix(spine_animation_state_data obj, const char* fromName, const char* toName, float duration);
SPINE_C_EXPORT void spine_animation_state_data_set_mix_3(spine_animation_state_data obj, spine_animation from, spine_animation to, float duration);
SPINE_C_EXPORT float spine_animation_state_data_get_mix(spine_animation_state_data obj, spine_animation from, spine_animation to);
SPINE_C_EXPORT void spine_animation_state_data_clear(spine_animation_state_data obj);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_ANIMATIONSTATEDATA_H