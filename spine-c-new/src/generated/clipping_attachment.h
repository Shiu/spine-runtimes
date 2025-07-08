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

#ifndef SPINE_C_CLIPPINGATTACHMENT_H
#define SPINE_C_CLIPPINGATTACHMENT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"

SPINE_C_EXPORT spine_clipping_attachment spine_clipping_attachment_create(const char* name);
SPINE_C_EXPORT void spine_clipping_attachment_dispose(spine_clipping_attachment obj);
SPINE_C_EXPORT spine_rtti spine_clipping_attachment_get_rtti();
SPINE_C_EXPORT spine_slot_data spine_clipping_attachment_get_end_slot(spine_clipping_attachment obj);
SPINE_C_EXPORT void spine_clipping_attachment_set_end_slot(spine_clipping_attachment obj, spine_slot_data value);
SPINE_C_EXPORT spine_color spine_clipping_attachment_get_color(spine_clipping_attachment obj);
SPINE_C_EXPORT spine_attachment spine_clipping_attachment_copy(spine_clipping_attachment obj);
SPINE_C_EXPORT void spine_clipping_attachment_compute_world_vertices(spine_clipping_attachment obj, spine_skeleton skeleton, spine_slot slot, size_t start, size_t count, float * worldVertices, size_t offset, size_t stride);
SPINE_C_EXPORT void spine_clipping_attachment_compute_world_vertices_7(spine_clipping_attachment obj, spine_skeleton skeleton, spine_slot slot, size_t start, size_t count, spine_array_float worldVertices, size_t offset, size_t stride);
SPINE_C_EXPORT int spine_clipping_attachment_get_id(spine_clipping_attachment obj);
SPINE_C_EXPORT int32_t spine_clipping_attachment_get_num_bones(spine_clipping_attachment obj);
SPINE_C_EXPORT int *spine_clipping_attachment_get_bones(spine_clipping_attachment obj);
SPINE_C_EXPORT void spine_clipping_attachment_set_bones(spine_clipping_attachment obj, spine_array_int value);
SPINE_C_EXPORT int32_t spine_clipping_attachment_get_num_vertices(spine_clipping_attachment obj);
SPINE_C_EXPORT float *spine_clipping_attachment_get_vertices(spine_clipping_attachment obj);
SPINE_C_EXPORT void spine_clipping_attachment_set_vertices(spine_clipping_attachment obj, spine_array_float value);
SPINE_C_EXPORT size_t spine_clipping_attachment_get_world_vertices_length(spine_clipping_attachment obj);
SPINE_C_EXPORT void spine_clipping_attachment_set_world_vertices_length(spine_clipping_attachment obj, size_t value);
SPINE_C_EXPORT spine_attachment spine_clipping_attachment_get_timeline_attachment(spine_clipping_attachment obj);
SPINE_C_EXPORT void spine_clipping_attachment_set_timeline_attachment(spine_clipping_attachment obj, spine_attachment value);
SPINE_C_EXPORT void spine_clipping_attachment_copy_to(spine_clipping_attachment obj, spine_vertex_attachment other);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_CLIPPINGATTACHMENT_H