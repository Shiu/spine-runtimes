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

#ifndef SPINE_C_REGIONATTACHMENT_H
#define SPINE_C_REGIONATTACHMENT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"

SPINE_C_EXPORT spine_region_attachment spine_region_attachment_create(const char* name);
SPINE_C_EXPORT void spine_region_attachment_dispose(spine_region_attachment obj);
SPINE_C_EXPORT spine_rtti spine_region_attachment_get_rtti();
SPINE_C_EXPORT void spine_region_attachment_update_region(spine_region_attachment obj);
SPINE_C_EXPORT void spine_region_attachment_compute_world_vertices(spine_region_attachment obj, spine_slot slot, float * worldVertices, size_t offset, size_t stride);
SPINE_C_EXPORT void spine_region_attachment_compute_world_vertices_4(spine_region_attachment obj, spine_slot slot, spine_array_float worldVertices, size_t offset, size_t stride);
SPINE_C_EXPORT float spine_region_attachment_get_x(spine_region_attachment obj);
SPINE_C_EXPORT void spine_region_attachment_set_x(spine_region_attachment obj, float value);
SPINE_C_EXPORT float spine_region_attachment_get_y(spine_region_attachment obj);
SPINE_C_EXPORT void spine_region_attachment_set_y(spine_region_attachment obj, float value);
SPINE_C_EXPORT float spine_region_attachment_get_rotation(spine_region_attachment obj);
SPINE_C_EXPORT void spine_region_attachment_set_rotation(spine_region_attachment obj, float value);
SPINE_C_EXPORT float spine_region_attachment_get_scale_x(spine_region_attachment obj);
SPINE_C_EXPORT void spine_region_attachment_set_scale_x(spine_region_attachment obj, float value);
SPINE_C_EXPORT float spine_region_attachment_get_scale_y(spine_region_attachment obj);
SPINE_C_EXPORT void spine_region_attachment_set_scale_y(spine_region_attachment obj, float value);
SPINE_C_EXPORT float spine_region_attachment_get_width(spine_region_attachment obj);
SPINE_C_EXPORT void spine_region_attachment_set_width(spine_region_attachment obj, float value);
SPINE_C_EXPORT float spine_region_attachment_get_height(spine_region_attachment obj);
SPINE_C_EXPORT void spine_region_attachment_set_height(spine_region_attachment obj, float value);
SPINE_C_EXPORT spine_color spine_region_attachment_get_color(spine_region_attachment obj);
SPINE_C_EXPORT const char* spine_region_attachment_get_path(spine_region_attachment obj);
SPINE_C_EXPORT void spine_region_attachment_set_path(spine_region_attachment obj, const char* value);
SPINE_C_EXPORT spine_texture_region spine_region_attachment_get_region(spine_region_attachment obj);
SPINE_C_EXPORT void spine_region_attachment_set_region(spine_region_attachment obj, spine_texture_region value);
SPINE_C_EXPORT spine_sequence spine_region_attachment_get_sequence(spine_region_attachment obj);
SPINE_C_EXPORT void spine_region_attachment_set_sequence(spine_region_attachment obj, spine_sequence value);
SPINE_C_EXPORT int32_t spine_region_attachment_get_num_offset(spine_region_attachment obj);
SPINE_C_EXPORT float *spine_region_attachment_get_offset(spine_region_attachment obj);
SPINE_C_EXPORT int32_t spine_region_attachment_get_num_u_vs(spine_region_attachment obj);
SPINE_C_EXPORT float *spine_region_attachment_get_u_vs(spine_region_attachment obj);
SPINE_C_EXPORT spine_attachment spine_region_attachment_copy(spine_region_attachment obj);
SPINE_C_EXPORT const char* spine_region_attachment_get_name(spine_region_attachment obj);
SPINE_C_EXPORT int spine_region_attachment_get_ref_count(spine_region_attachment obj);
SPINE_C_EXPORT void spine_region_attachment_reference(spine_region_attachment obj);
SPINE_C_EXPORT void spine_region_attachment_dereference(spine_region_attachment obj);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_REGIONATTACHMENT_H