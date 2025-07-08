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

#ifndef SPINE_C_ANIMATION_H
#define SPINE_C_ANIMATION_H

#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"

SPINE_C_EXPORT spine_animation spine_animation_create(const char* name, spine_array_timeline timelines, float duration);
SPINE_C_EXPORT void spine_animation_dispose(spine_animation obj);
SPINE_C_EXPORT int32_t spine_animation_get_num_timelines(spine_animation obj);
SPINE_C_EXPORT spine_timeline *spine_animation_get_timelines(spine_animation obj);
SPINE_C_EXPORT void spine_animation_set_timelines(spine_animation obj, spine_array_timeline value);
SPINE_C_EXPORT bool spine_animation_has_timeline(spine_animation obj, spine_array_property_id ids);
SPINE_C_EXPORT float spine_animation_get_duration(spine_animation obj);
SPINE_C_EXPORT void spine_animation_set_duration(spine_animation obj, float value);
SPINE_C_EXPORT void spine_animation_apply(spine_animation obj, spine_skeleton skeleton, float lastTime, float time, bool loop, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose);
SPINE_C_EXPORT const char* spine_animation_get_name(spine_animation obj);
SPINE_C_EXPORT int32_t spine_animation_get_num_bones(spine_animation obj);
SPINE_C_EXPORT int *spine_animation_get_bones(spine_animation obj);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_ANIMATION_H