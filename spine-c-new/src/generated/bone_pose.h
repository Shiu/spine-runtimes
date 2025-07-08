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

#ifndef SPINE_C_BONEPOSE_H
#define SPINE_C_BONEPOSE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../custom.h"

SPINE_OPAQUE_TYPE(spine_bone_pose)

SPINE_C_EXPORT spine_bone_pose spine_bone_pose_create(void);
SPINE_C_EXPORT void spine_bone_pose_dispose(spine_bone_pose obj);
SPINE_C_EXPORT void spine_bone_pose_update(spine_bone_pose obj, spine_skeleton skeleton, spine_physics physics);
SPINE_C_EXPORT void spine_bone_pose_update_world_transform(spine_bone_pose obj, spine_skeleton skeleton);
SPINE_C_EXPORT void spine_bone_pose_update_local_transform(spine_bone_pose obj, spine_skeleton skeleton);
SPINE_C_EXPORT void spine_bone_pose_validate_local_transform(spine_bone_pose obj, spine_skeleton skeleton);
SPINE_C_EXPORT void spine_bone_pose_modify_local(spine_bone_pose obj, spine_skeleton skeleton);
SPINE_C_EXPORT void spine_bone_pose_modify_world(spine_bone_pose obj, int32_t update);
SPINE_C_EXPORT void spine_bone_pose_reset_world(spine_bone_pose obj, int32_t update);
SPINE_C_EXPORT float spine_bone_pose_get_a(spine_bone_pose obj);
SPINE_C_EXPORT void spine_bone_pose_set_a(spine_bone_pose obj, float value);
SPINE_C_EXPORT float spine_bone_pose_get_b(spine_bone_pose obj);
SPINE_C_EXPORT void spine_bone_pose_set_b(spine_bone_pose obj, float value);
SPINE_C_EXPORT float spine_bone_pose_get_c(spine_bone_pose obj);
SPINE_C_EXPORT void spine_bone_pose_set_c(spine_bone_pose obj, float value);
SPINE_C_EXPORT float spine_bone_pose_get_d(spine_bone_pose obj);
SPINE_C_EXPORT void spine_bone_pose_set_d(spine_bone_pose obj, float value);
SPINE_C_EXPORT float spine_bone_pose_get_world_x(spine_bone_pose obj);
SPINE_C_EXPORT void spine_bone_pose_set_world_x(spine_bone_pose obj, float value);
SPINE_C_EXPORT float spine_bone_pose_get_world_y(spine_bone_pose obj);
SPINE_C_EXPORT void spine_bone_pose_set_world_y(spine_bone_pose obj, float value);
SPINE_C_EXPORT float spine_bone_pose_get_world_rotation_x(spine_bone_pose obj);
SPINE_C_EXPORT float spine_bone_pose_get_world_rotation_y(spine_bone_pose obj);
SPINE_C_EXPORT float spine_bone_pose_get_world_scale_x(spine_bone_pose obj);
SPINE_C_EXPORT float spine_bone_pose_get_world_scale_y(spine_bone_pose obj);
SPINE_C_EXPORT void spine_bone_pose_world_to_local(spine_bone_pose obj, float worldX, float worldY, float outLocalX, float outLocalY);
SPINE_C_EXPORT void spine_bone_pose_local_to_world(spine_bone_pose obj, float localX, float localY, float outWorldX, float outWorldY);
SPINE_C_EXPORT void spine_bone_pose_world_to_parent(spine_bone_pose obj, float worldX, float worldY, float outParentX, float outParentY);
SPINE_C_EXPORT void spine_bone_pose_parent_to_world(spine_bone_pose obj, float parentX, float parentY, float outWorldX, float outWorldY);
SPINE_C_EXPORT float spine_bone_pose_world_to_local_rotation(spine_bone_pose obj, float worldRotation);
SPINE_C_EXPORT float spine_bone_pose_local_to_world_rotation(spine_bone_pose obj, float localRotation);
SPINE_C_EXPORT void spine_bone_pose_rotate_world(spine_bone_pose obj, float degrees);
SPINE_C_EXPORT void spine_bone_pose_set(spine_bone_pose obj, spine_bone_local value);
SPINE_C_EXPORT float spine_bone_pose_get_x(spine_bone_pose obj);
SPINE_C_EXPORT void spine_bone_pose_set_x(spine_bone_pose obj, float value);
SPINE_C_EXPORT float spine_bone_pose_get_y(spine_bone_pose obj);
SPINE_C_EXPORT void spine_bone_pose_set_y(spine_bone_pose obj, float value);
SPINE_C_EXPORT void spine_bone_pose_set_position(spine_bone_pose obj, float x, float y);
SPINE_C_EXPORT float spine_bone_pose_get_rotation(spine_bone_pose obj);
SPINE_C_EXPORT void spine_bone_pose_set_rotation(spine_bone_pose obj, float value);
SPINE_C_EXPORT float spine_bone_pose_get_scale_x(spine_bone_pose obj);
SPINE_C_EXPORT void spine_bone_pose_set_scale_x(spine_bone_pose obj, float value);
SPINE_C_EXPORT float spine_bone_pose_get_scale_y(spine_bone_pose obj);
SPINE_C_EXPORT void spine_bone_pose_set_scale_y(spine_bone_pose obj, float value);
SPINE_C_EXPORT void spine_bone_pose_set_scale(spine_bone_pose obj, float scaleX, float scaleY);
SPINE_C_EXPORT void spine_bone_pose_set_scale(spine_bone_pose obj, float value);
SPINE_C_EXPORT float spine_bone_pose_get_shear_x(spine_bone_pose obj);
SPINE_C_EXPORT void spine_bone_pose_set_shear_x(spine_bone_pose obj, float value);
SPINE_C_EXPORT float spine_bone_pose_get_shear_y(spine_bone_pose obj);
SPINE_C_EXPORT void spine_bone_pose_set_shear_y(spine_bone_pose obj, float value);
SPINE_C_EXPORT spine_inherit spine_bone_pose_get_inherit(spine_bone_pose obj);
SPINE_C_EXPORT void spine_bone_pose_set_inherit(spine_bone_pose obj, spine_inherit value);
SPINE_C_EXPORT spine_rtti spine_bone_pose_get_rtti(spine_bone_pose obj);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_BONEPOSE_H