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

#ifndef SPINE_C_SKIN_H
#define SPINE_C_SKIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../custom.h"

SPINE_OPAQUE_TYPE(spine_skin)

SPINE_C_EXPORT spine_skin spine_skin_create(const utf8 * name);
SPINE_C_EXPORT void spine_skin_dispose(spine_skin obj);
SPINE_C_EXPORT void spine_skin_set_attachment(spine_skin obj, spine_size_t slotIndex, const utf8 * name, spine_attachment attachment);
SPINE_C_EXPORT spine_attachment spine_skin_get_attachment(spine_skin obj, spine_size_t slotIndex, const utf8 * name);
SPINE_C_EXPORT void spine_skin_remove_attachment(spine_skin obj, spine_size_t slotIndex, const utf8 * name);
SPINE_C_EXPORT void spine_skin_find_names_for_slot(spine_skin obj, spine_size_t slotIndex, void * names);
SPINE_C_EXPORT void spine_skin_find_attachments_for_slot(spine_skin obj, spine_size_t slotIndex, void * attachments);
SPINE_C_EXPORT const utf8 * spine_skin_get_name(spine_skin obj);
SPINE_C_EXPORT void spine_skin_add_skin(spine_skin obj, spine_skin other);
SPINE_C_EXPORT void spine_skin_copy_skin(spine_skin obj, spine_skin other);
SPINE_C_EXPORT spine_attachment_map::entries spine_skin_get_attachments(spine_skin obj);
SPINE_C_EXPORT void * spine_skin_get_bones(spine_skin obj);
SPINE_C_EXPORT int32_t spine_skin_get_num_bones(spine_skin obj);
SPINE_C_EXPORT spine_bone_data *spine_skin_get_bones(spine_skin obj);
SPINE_C_EXPORT void * spine_skin_get_constraints(spine_skin obj);
SPINE_C_EXPORT int32_t spine_skin_get_num_constraints(spine_skin obj);
SPINE_C_EXPORT spine_constraint_data *spine_skin_get_constraints(spine_skin obj);
SPINE_C_EXPORT spine_color spine_skin_get_color(spine_skin obj);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_SKIN_H