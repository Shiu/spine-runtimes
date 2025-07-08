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

#ifndef SPINE_C_TRANSFORMCONSTRAINTDATA_H
#define SPINE_C_TRANSFORMCONSTRAINTDATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"

SPINE_C_EXPORT spine_transform_constraint_data spine_transform_constraint_data_create(const char* name);
SPINE_C_EXPORT void spine_transform_constraint_data_dispose(spine_transform_constraint_data obj);
SPINE_C_EXPORT spine_rtti spine_transform_constraint_data_get_rtti();
SPINE_C_EXPORT spine_constraint spine_transform_constraint_data_create(spine_transform_constraint_data obj, spine_skeleton skeleton);
SPINE_C_EXPORT int32_t spine_transform_constraint_data_get_num_bones(spine_transform_constraint_data obj);
SPINE_C_EXPORT spine_bone_data *spine_transform_constraint_data_get_bones(spine_transform_constraint_data obj);
SPINE_C_EXPORT spine_bone_data spine_transform_constraint_data_get_source(spine_transform_constraint_data obj);
SPINE_C_EXPORT void spine_transform_constraint_data_set_source(spine_transform_constraint_data obj, spine_bone_data value);
SPINE_C_EXPORT float spine_transform_constraint_data_get_offset_rotation(spine_transform_constraint_data obj);
SPINE_C_EXPORT void spine_transform_constraint_data_set_offset_rotation(spine_transform_constraint_data obj, float value);
SPINE_C_EXPORT float spine_transform_constraint_data_get_offset_x(spine_transform_constraint_data obj);
SPINE_C_EXPORT void spine_transform_constraint_data_set_offset_x(spine_transform_constraint_data obj, float value);
SPINE_C_EXPORT float spine_transform_constraint_data_get_offset_y(spine_transform_constraint_data obj);
SPINE_C_EXPORT void spine_transform_constraint_data_set_offset_y(spine_transform_constraint_data obj, float value);
SPINE_C_EXPORT float spine_transform_constraint_data_get_offset_scale_x(spine_transform_constraint_data obj);
SPINE_C_EXPORT void spine_transform_constraint_data_set_offset_scale_x(spine_transform_constraint_data obj, float value);
SPINE_C_EXPORT float spine_transform_constraint_data_get_offset_scale_y(spine_transform_constraint_data obj);
SPINE_C_EXPORT void spine_transform_constraint_data_set_offset_scale_y(spine_transform_constraint_data obj, float value);
SPINE_C_EXPORT float spine_transform_constraint_data_get_offset_shear_y(spine_transform_constraint_data obj);
SPINE_C_EXPORT void spine_transform_constraint_data_set_offset_shear_y(spine_transform_constraint_data obj, float value);
SPINE_C_EXPORT bool spine_transform_constraint_data_get_local_source(spine_transform_constraint_data obj);
SPINE_C_EXPORT void spine_transform_constraint_data_set_local_source(spine_transform_constraint_data obj, bool value);
SPINE_C_EXPORT bool spine_transform_constraint_data_get_local_target(spine_transform_constraint_data obj);
SPINE_C_EXPORT void spine_transform_constraint_data_set_local_target(spine_transform_constraint_data obj, bool value);
SPINE_C_EXPORT bool spine_transform_constraint_data_get_additive(spine_transform_constraint_data obj);
SPINE_C_EXPORT void spine_transform_constraint_data_set_additive(spine_transform_constraint_data obj, bool value);
SPINE_C_EXPORT bool spine_transform_constraint_data_get_clamp(spine_transform_constraint_data obj);
SPINE_C_EXPORT void spine_transform_constraint_data_set_clamp(spine_transform_constraint_data obj, bool value);
SPINE_C_EXPORT int32_t spine_transform_constraint_data_get_num_properties(spine_transform_constraint_data obj);
SPINE_C_EXPORT spine_class from_property *spine_transform_constraint_data_get_properties(spine_transform_constraint_data obj);
SPINE_C_EXPORT const char* spine_transform_constraint_data_get_name(spine_transform_constraint_data obj);
SPINE_C_EXPORT bool spine_transform_constraint_data_is_skin_required(spine_transform_constraint_data obj);
SPINE_C_EXPORT spine_transform_constraint_pose spine_transform_constraint_data_get_setup_pose(spine_transform_constraint_data obj);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_TRANSFORMCONSTRAINTDATA_H