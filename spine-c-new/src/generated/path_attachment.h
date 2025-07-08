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

#ifndef SPINE_C_PATHATTACHMENT_H
#define SPINE_C_PATHATTACHMENT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../custom.h"

SPINE_OPAQUE_TYPE(spine_path_attachment)

SPINE_C_EXPORT spine_path_attachment spine_path_attachment_create(const utf8 * name);
SPINE_C_EXPORT void spine_path_attachment_dispose(spine_path_attachment obj);
SPINE_C_EXPORT spine_rtti spine_path_attachment_get_rtti(spine_path_attachment obj);
SPINE_C_EXPORT void * spine_path_attachment_get_lengths(spine_path_attachment obj);
SPINE_C_EXPORT int32_t spine_path_attachment_get_num_lengths(spine_path_attachment obj);
SPINE_C_EXPORT spine_float *spine_path_attachment_get_lengths(spine_path_attachment obj);
SPINE_C_EXPORT void spine_path_attachment_set_lengths(spine_path_attachment obj, void * value);
SPINE_C_EXPORT spine_bool spine_path_attachment_is_closed(spine_path_attachment obj);
SPINE_C_EXPORT void spine_path_attachment_set_closed(spine_path_attachment obj, spine_bool value);
SPINE_C_EXPORT spine_bool spine_path_attachment_is_constant_speed(spine_path_attachment obj);
SPINE_C_EXPORT void spine_path_attachment_set_constant_speed(spine_path_attachment obj, spine_bool value);
SPINE_C_EXPORT spine_color spine_path_attachment_get_color(spine_path_attachment obj);
SPINE_C_EXPORT spine_attachment spine_path_attachment_copy(spine_path_attachment obj);
SPINE_C_EXPORT void spine_path_attachment_compute_world_vertices(spine_path_attachment obj, spine_skeleton skeleton, spine_slot slot, spine_size_t start, spine_size_t count, spine_float worldVertices, spine_size_t offset, spine_size_t stride);
SPINE_C_EXPORT void spine_path_attachment_compute_world_vertices(spine_path_attachment obj, spine_skeleton skeleton, spine_slot slot, spine_size_t start, spine_size_t count, void * worldVertices, spine_size_t offset, spine_size_t stride);
SPINE_C_EXPORT int32_t spine_path_attachment_get_id(spine_path_attachment obj);
SPINE_C_EXPORT int32_t * spine_path_attachment_get_bones(spine_path_attachment obj);
SPINE_C_EXPORT int32_t spine_path_attachment_get_num_bones(spine_path_attachment obj);
SPINE_C_EXPORT int32_t *spine_path_attachment_get_bones(spine_path_attachment obj);
SPINE_C_EXPORT void spine_path_attachment_set_bones(spine_path_attachment obj, int32_t * value);
SPINE_C_EXPORT void * spine_path_attachment_get_vertices(spine_path_attachment obj);
SPINE_C_EXPORT int32_t spine_path_attachment_get_num_vertices(spine_path_attachment obj);
SPINE_C_EXPORT spine_float *spine_path_attachment_get_vertices(spine_path_attachment obj);
SPINE_C_EXPORT void spine_path_attachment_set_vertices(spine_path_attachment obj, void * value);
SPINE_C_EXPORT spine_size_t spine_path_attachment_get_world_vertices_length(spine_path_attachment obj);
SPINE_C_EXPORT void spine_path_attachment_set_world_vertices_length(spine_path_attachment obj, spine_size_t value);
SPINE_C_EXPORT spine_attachment spine_path_attachment_get_timeline_attachment(spine_path_attachment obj);
SPINE_C_EXPORT void spine_path_attachment_set_timeline_attachment(spine_path_attachment obj, spine_attachment value);
SPINE_C_EXPORT void spine_path_attachment_copy_to(spine_path_attachment obj, spine_vertex_attachment other);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_PATHATTACHMENT_H