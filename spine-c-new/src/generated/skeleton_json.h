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

#ifndef SPINE_C_SKELETONJSON_H
#define SPINE_C_SKELETONJSON_H

#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"

SPINE_C_EXPORT spine_skeleton_json spine_skeleton_json_create(spine_atlas atlas);
SPINE_C_EXPORT spine_skeleton_json spine_skeleton_json_create_with_attachment_loader_bool(spine_attachment_loader attachmentLoader, bool ownsLoader);
SPINE_C_EXPORT void spine_skeleton_json_dispose(spine_skeleton_json obj);
SPINE_C_EXPORT spine_skeleton_data spine_skeleton_json_read_skeleton_data_file(spine_skeleton_json obj, const char* path);
SPINE_C_EXPORT spine_skeleton_data spine_skeleton_json_read_skeleton_data(spine_skeleton_json obj, const char * json);
SPINE_C_EXPORT void spine_skeleton_json_set_scale(spine_skeleton_json obj, float value);
SPINE_C_EXPORT const char* spine_skeleton_json_get_error(spine_skeleton_json obj);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_SKELETONJSON_H