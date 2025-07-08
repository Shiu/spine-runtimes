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

#ifndef SPINE_C_SLOTDATA_H
#define SPINE_C_SLOTDATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../custom.h"

SPINE_OPAQUE_TYPE(spine_slot_data)

SPINE_C_EXPORT spine_slot_data spine_slot_data_create(int32_t index, const utf8 * name, spine_bone_data boneData);
SPINE_C_EXPORT void spine_slot_data_dispose(spine_slot_data obj);
SPINE_C_EXPORT int32_t spine_slot_data_get_index(spine_slot_data obj);
SPINE_C_EXPORT spine_bone_data spine_slot_data_get_bone_data(spine_slot_data obj);
SPINE_C_EXPORT void spine_slot_data_set_attachment_name(spine_slot_data obj, const utf8 * value);
SPINE_C_EXPORT const utf8 * spine_slot_data_get_attachment_name(spine_slot_data obj);
SPINE_C_EXPORT spine_blend_mode spine_slot_data_get_blend_mode(spine_slot_data obj);
SPINE_C_EXPORT void spine_slot_data_set_blend_mode(spine_slot_data obj, spine_blend_mode value);
SPINE_C_EXPORT spine_bool spine_slot_data_get_visible(spine_slot_data obj);
SPINE_C_EXPORT void spine_slot_data_set_visible(spine_slot_data obj, spine_bool value);
SPINE_C_EXPORT spine_slot_pose spine_slot_data_get_setup_pose(spine_slot_data obj);
SPINE_C_EXPORT spine_slot_pose spine_slot_data_get_setup_pose(spine_slot_data obj);
SPINE_C_EXPORT spine_spine::string spine_slot_data_get_name(spine_slot_data obj);
SPINE_C_EXPORT spine_bool spine_slot_data_is_skin_required(spine_slot_data obj);
SPINE_C_EXPORT void spine_slot_data_set_skin_required(spine_slot_data obj, spine_bool value);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_SLOTDATA_H