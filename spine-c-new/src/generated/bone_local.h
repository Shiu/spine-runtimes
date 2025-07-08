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

#ifndef SPINE_C_BONELOCAL_H
#define SPINE_C_BONELOCAL_H

#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"

SPINE_C_EXPORT spine_bone_local spine_bone_local_create(void);
SPINE_C_EXPORT void spine_bone_local_dispose(spine_bone_local obj);
SPINE_C_EXPORT void spine_bone_local_set(spine_bone_local obj, spine_bone_local value);
SPINE_C_EXPORT float spine_bone_local_get_x(spine_bone_local obj);
SPINE_C_EXPORT void spine_bone_local_set_x(spine_bone_local obj, float value);
SPINE_C_EXPORT float spine_bone_local_get_y(spine_bone_local obj);
SPINE_C_EXPORT void spine_bone_local_set_y(spine_bone_local obj, float value);
SPINE_C_EXPORT void spine_bone_local_set_position(spine_bone_local obj, float x, float y);
SPINE_C_EXPORT float spine_bone_local_get_rotation(spine_bone_local obj);
SPINE_C_EXPORT void spine_bone_local_set_rotation(spine_bone_local obj, float value);
SPINE_C_EXPORT float spine_bone_local_get_scale_x(spine_bone_local obj);
SPINE_C_EXPORT void spine_bone_local_set_scale_x(spine_bone_local obj, float value);
SPINE_C_EXPORT float spine_bone_local_get_scale_y(spine_bone_local obj);
SPINE_C_EXPORT void spine_bone_local_set_scale_y(spine_bone_local obj, float value);
SPINE_C_EXPORT void spine_bone_local_set_scale(spine_bone_local obj, float scaleX, float scaleY);
SPINE_C_EXPORT void spine_bone_local_set_scale(spine_bone_local obj, float value);
SPINE_C_EXPORT float spine_bone_local_get_shear_x(spine_bone_local obj);
SPINE_C_EXPORT void spine_bone_local_set_shear_x(spine_bone_local obj, float value);
SPINE_C_EXPORT float spine_bone_local_get_shear_y(spine_bone_local obj);
SPINE_C_EXPORT void spine_bone_local_set_shear_y(spine_bone_local obj, float value);
SPINE_C_EXPORT spine_inherit spine_bone_local_get_inherit(spine_bone_local obj);
SPINE_C_EXPORT void spine_bone_local_set_inherit(spine_bone_local obj, spine_inherit value);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_BONELOCAL_H