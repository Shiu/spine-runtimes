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

#ifndef SPINE_C_TRANSFORMCONSTRAINT_H
#define SPINE_C_TRANSFORMCONSTRAINT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../custom.h"

SPINE_OPAQUE_TYPE(spine_transform_constraint)

SPINE_C_EXPORT spine_transform_constraint spine_transform_constraint_create(spine_transform_constraint_data data, spine_skeleton skeleton);
SPINE_C_EXPORT void spine_transform_constraint_dispose(spine_transform_constraint obj);
SPINE_C_EXPORT spine_rtti spine_transform_constraint_get_rtti(spine_transform_constraint obj);
SPINE_C_EXPORT spine_transform_constraint spine_transform_constraint_copy(spine_transform_constraint obj, spine_skeleton skeleton);
SPINE_C_EXPORT void spine_transform_constraint_update(spine_transform_constraint obj, spine_skeleton skeleton, spine_physics physics);
SPINE_C_EXPORT void spine_transform_constraint_sort(spine_transform_constraint obj, spine_skeleton skeleton);
SPINE_C_EXPORT spine_bool spine_transform_constraint_is_source_active(spine_transform_constraint obj);
SPINE_C_EXPORT void * spine_transform_constraint_get_bones(spine_transform_constraint obj);
SPINE_C_EXPORT int32_t spine_transform_constraint_get_num_bones(spine_transform_constraint obj);
SPINE_C_EXPORT spine_bone_pose *spine_transform_constraint_get_bones(spine_transform_constraint obj);
SPINE_C_EXPORT spine_bone spine_transform_constraint_get_source(spine_transform_constraint obj);
SPINE_C_EXPORT void spine_transform_constraint_set_source(spine_transform_constraint obj, spine_bone value);
SPINE_C_EXPORT spine_constraint_data spine_transform_constraint_get_data(spine_transform_constraint obj);
SPINE_C_EXPORT void spine_transform_constraint_pose(spine_transform_constraint obj);
SPINE_C_EXPORT void spine_transform_constraint_setup_pose(spine_transform_constraint obj);
SPINE_C_EXPORT spine_transform_constraint_pose spine_transform_constraint_get_pose(spine_transform_constraint obj);
SPINE_C_EXPORT spine_transform_constraint_pose spine_transform_constraint_get_applied_pose(spine_transform_constraint obj);
SPINE_C_EXPORT void spine_transform_constraint_reset_constrained(spine_transform_constraint obj);
SPINE_C_EXPORT void spine_transform_constraint_constrained(spine_transform_constraint obj);
SPINE_C_EXPORT spine_bool spine_transform_constraint_is_pose_equal_to_applied(spine_transform_constraint obj);
SPINE_C_EXPORT spine_bool spine_transform_constraint_is_active(spine_transform_constraint obj);
SPINE_C_EXPORT void spine_transform_constraint_set_active(spine_transform_constraint obj, spine_bool value);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_TRANSFORMCONSTRAINT_H