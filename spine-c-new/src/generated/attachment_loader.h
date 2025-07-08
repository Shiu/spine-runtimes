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

#ifndef SPINE_C_ATTACHMENTLOADER_H
#define SPINE_C_ATTACHMENTLOADER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../custom.h"

SPINE_OPAQUE_TYPE(spine_attachment_loader)

SPINE_C_EXPORT spine_attachment_loader spine_attachment_loader_create(void);
SPINE_C_EXPORT void spine_attachment_loader_dispose(spine_attachment_loader obj);
SPINE_C_EXPORT spine_region_attachment spine_attachment_loader_new_region_attachment(spine_attachment_loader obj, spine_skin skin, const utf8 * name, const utf8 * path, spine_sequence sequence);
SPINE_C_EXPORT spine_mesh_attachment spine_attachment_loader_new_mesh_attachment(spine_attachment_loader obj, spine_skin skin, const utf8 * name, const utf8 * path, spine_sequence sequence);
SPINE_C_EXPORT spine_bounding_box_attachment spine_attachment_loader_new_bounding_box_attachment(spine_attachment_loader obj, spine_skin skin, const utf8 * name);
SPINE_C_EXPORT spine_path_attachment spine_attachment_loader_new_path_attachment(spine_attachment_loader obj, spine_skin skin, const utf8 * name);
SPINE_C_EXPORT spine_point_attachment spine_attachment_loader_new_point_attachment(spine_attachment_loader obj, spine_skin skin, const utf8 * name);
SPINE_C_EXPORT spine_clipping_attachment spine_attachment_loader_new_clipping_attachment(spine_attachment_loader obj, spine_skin skin, const utf8 * name);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_ATTACHMENTLOADER_H