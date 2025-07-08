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

#ifndef SPINE_C_SKELETONDATA_H
#define SPINE_C_SKELETONDATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../custom.h"

SPINE_OPAQUE_TYPE(spine_skeleton_data)

SPINE_C_EXPORT spine_skeleton_data spine_skeleton_data_create(void);
SPINE_C_EXPORT void spine_skeleton_data_dispose(spine_skeleton_data obj);
SPINE_C_EXPORT spine_bone_data spine_skeleton_data_find_bone(spine_skeleton_data obj, const utf8 * boneName);
SPINE_C_EXPORT spine_slot_data spine_skeleton_data_find_slot(spine_skeleton_data obj, const utf8 * slotName);
SPINE_C_EXPORT spine_skin spine_skeleton_data_find_skin(spine_skeleton_data obj, const utf8 * skinName);
SPINE_C_EXPORT spine_spine::event_data spine_skeleton_data_find_event(spine_skeleton_data obj, const utf8 * eventDataName);
SPINE_C_EXPORT spine_animation spine_skeleton_data_find_animation(spine_skeleton_data obj, const utf8 * animationName);
SPINE_C_EXPORT spine_ik_constraint_data spine_skeleton_data_find_ik_constraint(spine_skeleton_data obj, const utf8 * constraintName);
SPINE_C_EXPORT spine_transform_constraint_data spine_skeleton_data_find_transform_constraint(spine_skeleton_data obj, const utf8 * constraintName);
SPINE_C_EXPORT spine_path_constraint_data spine_skeleton_data_find_path_constraint(spine_skeleton_data obj, const utf8 * constraintName);
SPINE_C_EXPORT spine_physics_constraint_data spine_skeleton_data_find_physics_constraint(spine_skeleton_data obj, const utf8 * constraintName);
SPINE_C_EXPORT const utf8 * spine_skeleton_data_get_name(spine_skeleton_data obj);
SPINE_C_EXPORT void * spine_skeleton_data_get_bones(spine_skeleton_data obj);
SPINE_C_EXPORT int32_t spine_skeleton_data_get_num_bones(spine_skeleton_data obj);
SPINE_C_EXPORT spine_bone_data *spine_skeleton_data_get_bones(spine_skeleton_data obj);
SPINE_C_EXPORT void * spine_skeleton_data_get_slots(spine_skeleton_data obj);
SPINE_C_EXPORT int32_t spine_skeleton_data_get_num_slots(spine_skeleton_data obj);
SPINE_C_EXPORT spine_slot_data *spine_skeleton_data_get_slots(spine_skeleton_data obj);
SPINE_C_EXPORT void * spine_skeleton_data_get_skins(spine_skeleton_data obj);
SPINE_C_EXPORT int32_t spine_skeleton_data_get_num_skins(spine_skeleton_data obj);
SPINE_C_EXPORT spine_skin *spine_skeleton_data_get_skins(spine_skeleton_data obj);
SPINE_C_EXPORT spine_skin spine_skeleton_data_get_default_skin(spine_skeleton_data obj);
SPINE_C_EXPORT void spine_skeleton_data_set_default_skin(spine_skeleton_data obj, spine_skin value);
SPINE_C_EXPORT void * spine_skeleton_data_get_events(spine_skeleton_data obj);
SPINE_C_EXPORT int32_t spine_skeleton_data_get_num_events(spine_skeleton_data obj);
SPINE_C_EXPORT spine_spine::event_data *spine_skeleton_data_get_events(spine_skeleton_data obj);
SPINE_C_EXPORT void * spine_skeleton_data_get_animations(spine_skeleton_data obj);
SPINE_C_EXPORT int32_t spine_skeleton_data_get_num_animations(spine_skeleton_data obj);
SPINE_C_EXPORT spine_animation *spine_skeleton_data_get_animations(spine_skeleton_data obj);
SPINE_C_EXPORT void * spine_skeleton_data_get_ik_constraints(spine_skeleton_data obj);
SPINE_C_EXPORT int32_t spine_skeleton_data_get_num_ik_constraints(spine_skeleton_data obj);
SPINE_C_EXPORT spine_ik_constraint_data *spine_skeleton_data_get_ik_constraints(spine_skeleton_data obj);
SPINE_C_EXPORT void * spine_skeleton_data_get_transform_constraints(spine_skeleton_data obj);
SPINE_C_EXPORT int32_t spine_skeleton_data_get_num_transform_constraints(spine_skeleton_data obj);
SPINE_C_EXPORT spine_transform_constraint_data *spine_skeleton_data_get_transform_constraints(spine_skeleton_data obj);
SPINE_C_EXPORT void * spine_skeleton_data_get_path_constraints(spine_skeleton_data obj);
SPINE_C_EXPORT int32_t spine_skeleton_data_get_num_path_constraints(spine_skeleton_data obj);
SPINE_C_EXPORT spine_path_constraint_data *spine_skeleton_data_get_path_constraints(spine_skeleton_data obj);
SPINE_C_EXPORT void * spine_skeleton_data_get_physics_constraints(spine_skeleton_data obj);
SPINE_C_EXPORT int32_t spine_skeleton_data_get_num_physics_constraints(spine_skeleton_data obj);
SPINE_C_EXPORT spine_physics_constraint_data *spine_skeleton_data_get_physics_constraints(spine_skeleton_data obj);
SPINE_C_EXPORT void * spine_skeleton_data_get_constraints(spine_skeleton_data obj);
SPINE_C_EXPORT int32_t spine_skeleton_data_get_num_constraints(spine_skeleton_data obj);
SPINE_C_EXPORT spine_constraint_data *spine_skeleton_data_get_constraints(spine_skeleton_data obj);
SPINE_C_EXPORT float spine_skeleton_data_get_x(spine_skeleton_data obj);
SPINE_C_EXPORT void spine_skeleton_data_set_x(spine_skeleton_data obj, float value);
SPINE_C_EXPORT float spine_skeleton_data_get_y(spine_skeleton_data obj);
SPINE_C_EXPORT void spine_skeleton_data_set_y(spine_skeleton_data obj, float value);
SPINE_C_EXPORT float spine_skeleton_data_get_width(spine_skeleton_data obj);
SPINE_C_EXPORT void spine_skeleton_data_set_width(spine_skeleton_data obj, float value);
SPINE_C_EXPORT float spine_skeleton_data_get_height(spine_skeleton_data obj);
SPINE_C_EXPORT void spine_skeleton_data_set_height(spine_skeleton_data obj, float value);
SPINE_C_EXPORT float spine_skeleton_data_get_reference_scale(spine_skeleton_data obj);
SPINE_C_EXPORT void spine_skeleton_data_set_reference_scale(spine_skeleton_data obj, float value);
SPINE_C_EXPORT const utf8 * spine_skeleton_data_get_version(spine_skeleton_data obj);
SPINE_C_EXPORT const utf8 * spine_skeleton_data_get_hash(spine_skeleton_data obj);
SPINE_C_EXPORT const utf8 * spine_skeleton_data_get_images_path(spine_skeleton_data obj);
SPINE_C_EXPORT const utf8 * spine_skeleton_data_get_audio_path(spine_skeleton_data obj);
SPINE_C_EXPORT float spine_skeleton_data_get_fps(spine_skeleton_data obj);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_SKELETONDATA_H