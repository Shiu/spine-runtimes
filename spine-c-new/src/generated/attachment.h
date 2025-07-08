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

#ifndef SPINE_C_ATTACHMENT_H
#define SPINE_C_ATTACHMENT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../custom.h"

SPINE_OPAQUE_TYPE(spine_attachment)

SPINE_C_EXPORT spine_attachment spine_attachment_create(const utf8 * name);
SPINE_C_EXPORT void spine_attachment_dispose(spine_attachment obj);
SPINE_C_EXPORT spine_rtti spine_attachment_get_rtti(spine_attachment obj);
SPINE_C_EXPORT const utf8 * spine_attachment_get_name(spine_attachment obj);
SPINE_C_EXPORT spine_attachment spine_attachment_copy(spine_attachment obj);
SPINE_C_EXPORT int32_t spine_attachment_get_ref_count(spine_attachment obj);
SPINE_C_EXPORT void spine_attachment_reference(spine_attachment obj);
SPINE_C_EXPORT void spine_attachment_dereference(spine_attachment obj);
struct spine_point_attachment_wrapper;
typedef struct spine_point_attachment_wrapper *spine_point_attachment;
struct spine_region_attachment_wrapper;
typedef struct spine_region_attachment_wrapper *spine_region_attachment;
struct spine_bounding_box_attachment_wrapper;
typedef struct spine_bounding_box_attachment_wrapper *spine_bounding_box_attachment;
struct spine_clipping_attachment_wrapper;
typedef struct spine_clipping_attachment_wrapper *spine_clipping_attachment;
struct spine_mesh_attachment_wrapper;
typedef struct spine_mesh_attachment_wrapper *spine_mesh_attachment;
struct spine_path_attachment_wrapper;
typedef struct spine_path_attachment_wrapper *spine_path_attachment;

typedef enum spine_attachment_type {
    SPINE_TYPE_ATTACHMENT_POINT_ATTACHMENT = 0,
    SPINE_TYPE_ATTACHMENT_REGION_ATTACHMENT = 1,
    SPINE_TYPE_ATTACHMENT_BOUNDING_BOX_ATTACHMENT = 2,
    SPINE_TYPE_ATTACHMENT_CLIPPING_ATTACHMENT = 3,
    SPINE_TYPE_ATTACHMENT_MESH_ATTACHMENT = 4,
    SPINE_TYPE_ATTACHMENT_PATH_ATTACHMENT = 5
} spine_attachment_type;

SPINE_C_EXPORT spine_bool spine_attachment_is_type(spine_attachment obj, spine_attachment_type type);
SPINE_C_EXPORT spine_point_attachment spine_attachment_as_point_attachment(spine_attachment obj);
SPINE_C_EXPORT spine_region_attachment spine_attachment_as_region_attachment(spine_attachment obj);
SPINE_C_EXPORT spine_bounding_box_attachment spine_attachment_as_bounding_box_attachment(spine_attachment obj);
SPINE_C_EXPORT spine_clipping_attachment spine_attachment_as_clipping_attachment(spine_attachment obj);
SPINE_C_EXPORT spine_mesh_attachment spine_attachment_as_mesh_attachment(spine_attachment obj);
SPINE_C_EXPORT spine_path_attachment spine_attachment_as_path_attachment(spine_attachment obj);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_ATTACHMENT_H