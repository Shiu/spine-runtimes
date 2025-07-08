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

#ifndef SPINE_C_BONE_H
#define SPINE_C_BONE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../custom.h"

SPINE_OPAQUE_TYPE(spine_bone)

SPINE_C_EXPORT spine_bone spine_bone_create(spine_bone_data data, spine_bone parent);
SPINE_C_EXPORT spine_bone spine_bone_create_with_bone_bone(spine_bone bone, spine_bone parent);
SPINE_C_EXPORT void spine_bone_dispose(spine_bone obj);
SPINE_C_EXPORT spine_rtti spine_bone_get_rtti(spine_bone obj);
SPINE_C_EXPORT spine_bone spine_bone_get_parent(spine_bone obj);
SPINE_C_EXPORT void * spine_bone_get_children(spine_bone obj);
SPINE_C_EXPORT int32_t spine_bone_get_num_children(spine_bone obj);
SPINE_C_EXPORT spine_bone *spine_bone_get_children(spine_bone obj);
SPINE_C_EXPORT void spine_bone_setup_pose(spine_bone obj);
SPINE_C_EXPORT spine_bone_data spine_bone_get_data(spine_bone obj);
SPINE_C_EXPORT spine_bone_local spine_bone_get_pose(spine_bone obj);
SPINE_C_EXPORT spine_bone_pose spine_bone_get_applied_pose(spine_bone obj);
SPINE_C_EXPORT void spine_bone_reset_constrained(spine_bone obj);
SPINE_C_EXPORT void spine_bone_pose(spine_bone obj);
SPINE_C_EXPORT void spine_bone_constrained(spine_bone obj);
SPINE_C_EXPORT spine_bool spine_bone_is_pose_equal_to_applied(spine_bone obj);
SPINE_C_EXPORT spine_bool spine_bone_is_active(spine_bone obj);
SPINE_C_EXPORT void spine_bone_set_active(spine_bone obj, spine_bool value);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_BONE_H