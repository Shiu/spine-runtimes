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

#ifndef SPINE_C_BONETIMELINE1_H
#define SPINE_C_BONETIMELINE1_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../custom.h"

SPINE_OPAQUE_TYPE(spine_bone_timeline1)

SPINE_C_EXPORT spine_bone_timeline1 spine_bone_timeline1_create(spine_size_t frameCount, spine_size_t bezierCount, int32_t boneIndex, spine_property property);
SPINE_C_EXPORT void spine_bone_timeline1_dispose(spine_bone_timeline1 obj);
SPINE_C_EXPORT spine_rtti spine_bone_timeline1_get_rtti(spine_bone_timeline1 obj);
SPINE_C_EXPORT void spine_bone_timeline1_apply(spine_bone_timeline1 obj, spine_skeleton skeleton, float lastTime, float time, void * pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, spine_bool appliedPose);
SPINE_C_EXPORT void spine_bone_timeline1_set_frame(spine_bone_timeline1 obj, spine_size_t frame, float time, float value);
SPINE_C_EXPORT float spine_bone_timeline1_get_curve_value(spine_bone_timeline1 obj, float time);
SPINE_C_EXPORT float spine_bone_timeline1_get_relative_value(spine_bone_timeline1 obj, float time, float alpha, spine_mix_blend blend, float current, float setup);
SPINE_C_EXPORT float spine_bone_timeline1_get_absolute_value(spine_bone_timeline1 obj, float time, float alpha, spine_mix_blend blend, float current, float setup);
SPINE_C_EXPORT float spine_bone_timeline1_get_absolute_value(spine_bone_timeline1 obj, float time, float alpha, spine_mix_blend blend, float current, float setup, float value);
SPINE_C_EXPORT float spine_bone_timeline1_get_scale_value(spine_bone_timeline1 obj, float time, float alpha, spine_mix_blend blend, spine_mix_direction direction, float current, float setup);
SPINE_C_EXPORT int32_t spine_bone_timeline1_get_bone_index(spine_bone_timeline1 obj);
SPINE_C_EXPORT void spine_bone_timeline1_set_bone_index(spine_bone_timeline1 obj, int32_t value);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_BONETIMELINE1_H