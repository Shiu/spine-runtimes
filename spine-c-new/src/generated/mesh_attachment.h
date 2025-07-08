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

#ifndef SPINE_C_MESHATTACHMENT_H
#define SPINE_C_MESHATTACHMENT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../custom.h"

SPINE_OPAQUE_TYPE(spine_mesh_attachment)

SPINE_C_EXPORT spine_mesh_attachment spine_mesh_attachment_create(const utf8 * name);
SPINE_C_EXPORT void spine_mesh_attachment_dispose(spine_mesh_attachment obj);
SPINE_C_EXPORT spine_rtti spine_mesh_attachment_get_rtti(spine_mesh_attachment obj);
SPINE_C_EXPORT void spine_mesh_attachment_compute_world_vertices(spine_mesh_attachment obj, spine_skeleton skeleton, spine_slot slot, spine_size_t start, spine_size_t count, spine_float worldVertices, spine_size_t offset, spine_size_t stride);
SPINE_C_EXPORT void spine_mesh_attachment_update_region(spine_mesh_attachment obj);
SPINE_C_EXPORT int32_t spine_mesh_attachment_get_hull_length(spine_mesh_attachment obj);
SPINE_C_EXPORT void spine_mesh_attachment_set_hull_length(spine_mesh_attachment obj, int32_t value);
SPINE_C_EXPORT void * spine_mesh_attachment_get_region_u_vs(spine_mesh_attachment obj);
SPINE_C_EXPORT int32_t spine_mesh_attachment_get_num_region_u_vs(spine_mesh_attachment obj);
SPINE_C_EXPORT spine_float *spine_mesh_attachment_get_region_u_vs(spine_mesh_attachment obj);
SPINE_C_EXPORT void spine_mesh_attachment_set_region_u_vs(spine_mesh_attachment obj, void * value);
SPINE_C_EXPORT void * spine_mesh_attachment_get_u_vs(spine_mesh_attachment obj);
SPINE_C_EXPORT int32_t spine_mesh_attachment_get_num_u_vs(spine_mesh_attachment obj);
SPINE_C_EXPORT spine_float *spine_mesh_attachment_get_u_vs(spine_mesh_attachment obj);
SPINE_C_EXPORT void * spine_mesh_attachment_get_triangles(spine_mesh_attachment obj);
SPINE_C_EXPORT int32_t spine_mesh_attachment_get_num_triangles(spine_mesh_attachment obj);
SPINE_C_EXPORT spine_unsigned short *spine_mesh_attachment_get_triangles(spine_mesh_attachment obj);
SPINE_C_EXPORT void spine_mesh_attachment_set_triangles(spine_mesh_attachment obj, void * value);
SPINE_C_EXPORT spine_color spine_mesh_attachment_get_color(spine_mesh_attachment obj);
SPINE_C_EXPORT const utf8 * spine_mesh_attachment_get_path(spine_mesh_attachment obj);
SPINE_C_EXPORT void spine_mesh_attachment_set_path(spine_mesh_attachment obj, const utf8 * value);
SPINE_C_EXPORT spine_texture_region spine_mesh_attachment_get_region(spine_mesh_attachment obj);
SPINE_C_EXPORT void spine_mesh_attachment_set_region(spine_mesh_attachment obj, spine_texture_region value);
SPINE_C_EXPORT spine_sequence spine_mesh_attachment_get_sequence(spine_mesh_attachment obj);
SPINE_C_EXPORT void spine_mesh_attachment_set_sequence(spine_mesh_attachment obj, spine_sequence value);
SPINE_C_EXPORT spine_mesh_attachment spine_mesh_attachment_get_parent_mesh(spine_mesh_attachment obj);
SPINE_C_EXPORT void spine_mesh_attachment_set_parent_mesh(spine_mesh_attachment obj, spine_mesh_attachment value);
SPINE_C_EXPORT void * spine_mesh_attachment_get_edges(spine_mesh_attachment obj);
SPINE_C_EXPORT int32_t spine_mesh_attachment_get_num_edges(spine_mesh_attachment obj);
SPINE_C_EXPORT spine_unsigned short *spine_mesh_attachment_get_edges(spine_mesh_attachment obj);
SPINE_C_EXPORT void spine_mesh_attachment_set_edges(spine_mesh_attachment obj, void * value);
SPINE_C_EXPORT float spine_mesh_attachment_get_width(spine_mesh_attachment obj);
SPINE_C_EXPORT void spine_mesh_attachment_set_width(spine_mesh_attachment obj, float value);
SPINE_C_EXPORT float spine_mesh_attachment_get_height(spine_mesh_attachment obj);
SPINE_C_EXPORT void spine_mesh_attachment_set_height(spine_mesh_attachment obj, float value);
SPINE_C_EXPORT spine_attachment spine_mesh_attachment_copy(spine_mesh_attachment obj);
SPINE_C_EXPORT spine_mesh_attachment spine_mesh_attachment_new_linked_mesh(spine_mesh_attachment obj);
SPINE_C_EXPORT void spine_mesh_attachment_compute_world_vertices(spine_mesh_attachment obj, spine_skeleton skeleton, spine_slot slot, spine_size_t start, spine_size_t count, void * worldVertices, spine_size_t offset, spine_size_t stride);
SPINE_C_EXPORT int32_t spine_mesh_attachment_get_id(spine_mesh_attachment obj);
SPINE_C_EXPORT int32_t * spine_mesh_attachment_get_bones(spine_mesh_attachment obj);
SPINE_C_EXPORT int32_t spine_mesh_attachment_get_num_bones(spine_mesh_attachment obj);
SPINE_C_EXPORT int32_t *spine_mesh_attachment_get_bones(spine_mesh_attachment obj);
SPINE_C_EXPORT void spine_mesh_attachment_set_bones(spine_mesh_attachment obj, int32_t * value);
SPINE_C_EXPORT void * spine_mesh_attachment_get_vertices(spine_mesh_attachment obj);
SPINE_C_EXPORT int32_t spine_mesh_attachment_get_num_vertices(spine_mesh_attachment obj);
SPINE_C_EXPORT spine_float *spine_mesh_attachment_get_vertices(spine_mesh_attachment obj);
SPINE_C_EXPORT void spine_mesh_attachment_set_vertices(spine_mesh_attachment obj, void * value);
SPINE_C_EXPORT spine_size_t spine_mesh_attachment_get_world_vertices_length(spine_mesh_attachment obj);
SPINE_C_EXPORT void spine_mesh_attachment_set_world_vertices_length(spine_mesh_attachment obj, spine_size_t value);
SPINE_C_EXPORT spine_attachment spine_mesh_attachment_get_timeline_attachment(spine_mesh_attachment obj);
SPINE_C_EXPORT void spine_mesh_attachment_set_timeline_attachment(spine_mesh_attachment obj, spine_attachment value);
SPINE_C_EXPORT void spine_mesh_attachment_copy_to(spine_mesh_attachment obj, spine_vertex_attachment other);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_MESHATTACHMENT_H