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

#ifndef SPINE_C_SKELETON_H
#define SPINE_C_SKELETON_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../custom.h"

SPINE_OPAQUE_TYPE(spine_skeleton)

SPINE_C_EXPORT spine_skeleton spine_skeleton_create(spine_skeleton_data skeletonData);
SPINE_C_EXPORT void spine_skeleton_dispose(spine_skeleton obj);
SPINE_C_EXPORT void spine_skeleton_constrained(spine_skeleton obj, spine_posed object);
SPINE_C_EXPORT void spine_skeleton_sort_bone(spine_skeleton obj, spine_bone bone);
SPINE_C_EXPORT void spine_skeleton_update_world_transform(spine_skeleton obj, spine_physics physics);
SPINE_C_EXPORT void spine_skeleton_update_world_transform(spine_skeleton obj, spine_physics physics, spine_bone_pose parent);
SPINE_C_EXPORT void spine_skeleton_setup_pose(spine_skeleton obj);
SPINE_C_EXPORT void spine_skeleton_setup_pose_bones(spine_skeleton obj);
SPINE_C_EXPORT void spine_skeleton_setup_pose_slots(spine_skeleton obj);
SPINE_C_EXPORT spine_skeleton_data spine_skeleton_get_data(spine_skeleton obj);
SPINE_C_EXPORT void * spine_skeleton_get_bones(spine_skeleton obj);
SPINE_C_EXPORT int32_t spine_skeleton_get_num_bones(spine_skeleton obj);
SPINE_C_EXPORT spine_bone *spine_skeleton_get_bones(spine_skeleton obj);
SPINE_C_EXPORT void * spine_skeleton_get_update_cache(spine_skeleton obj);
SPINE_C_EXPORT int32_t spine_skeleton_get_num_update_cache(spine_skeleton obj);
SPINE_C_EXPORT spine_update *spine_skeleton_get_update_cache(spine_skeleton obj);
SPINE_C_EXPORT spine_bone spine_skeleton_get_root_bone(spine_skeleton obj);
SPINE_C_EXPORT spine_bone spine_skeleton_find_bone(spine_skeleton obj, const utf8 * boneName);
SPINE_C_EXPORT void * spine_skeleton_get_slots(spine_skeleton obj);
SPINE_C_EXPORT int32_t spine_skeleton_get_num_slots(spine_skeleton obj);
SPINE_C_EXPORT spine_slot *spine_skeleton_get_slots(spine_skeleton obj);
SPINE_C_EXPORT spine_slot spine_skeleton_find_slot(spine_skeleton obj, const utf8 * slotName);
SPINE_C_EXPORT void * spine_skeleton_get_draw_order(spine_skeleton obj);
SPINE_C_EXPORT int32_t spine_skeleton_get_num_draw_order(spine_skeleton obj);
SPINE_C_EXPORT spine_slot *spine_skeleton_get_draw_order(spine_skeleton obj);
SPINE_C_EXPORT spine_skin spine_skeleton_get_skin(spine_skeleton obj);
SPINE_C_EXPORT void spine_skeleton_set_skin(spine_skeleton obj, const utf8 * value);
SPINE_C_EXPORT void spine_skeleton_set_skin(spine_skeleton obj, spine_skin value);
SPINE_C_EXPORT spine_attachment spine_skeleton_get_attachment(spine_skeleton obj, const utf8 * slotName, const utf8 * attachmentName);
SPINE_C_EXPORT spine_attachment spine_skeleton_get_attachment(spine_skeleton obj, int32_t slotIndex, const utf8 * attachmentName);
SPINE_C_EXPORT void spine_skeleton_set_attachment(spine_skeleton obj, const utf8 * slotName, const utf8 * attachmentName);
SPINE_C_EXPORT void * spine_skeleton_get_constraints(spine_skeleton obj);
SPINE_C_EXPORT int32_t spine_skeleton_get_num_constraints(spine_skeleton obj);
SPINE_C_EXPORT spine_constraint *spine_skeleton_get_constraints(spine_skeleton obj);
SPINE_C_EXPORT void * spine_skeleton_get_physics_constraints(spine_skeleton obj);
SPINE_C_EXPORT int32_t spine_skeleton_get_num_physics_constraints(spine_skeleton obj);
SPINE_C_EXPORT spine_physics_constraint *spine_skeleton_get_physics_constraints(spine_skeleton obj);
SPINE_C_EXPORT void spine_skeleton_get_bounds(spine_skeleton obj, float outX, float outY, float outWidth, float outHeight, void * outVertexBuffer);
SPINE_C_EXPORT void spine_skeleton_get_bounds(spine_skeleton obj, float outX, float outY, float outWidth, float outHeight, void * outVertexBuffer, spine_skeleton_clipping clipper);
SPINE_C_EXPORT spine_color spine_skeleton_get_color(spine_skeleton obj);
SPINE_C_EXPORT void spine_skeleton_set_color(spine_skeleton obj, spine_color value);
SPINE_C_EXPORT void spine_skeleton_set_color(spine_skeleton obj, float r, float g, float b, float a);
SPINE_C_EXPORT float spine_skeleton_get_scale_x(spine_skeleton obj);
SPINE_C_EXPORT void spine_skeleton_set_scale_x(spine_skeleton obj, float value);
SPINE_C_EXPORT float spine_skeleton_get_scale_y(spine_skeleton obj);
SPINE_C_EXPORT void spine_skeleton_set_scale_y(spine_skeleton obj, float value);
SPINE_C_EXPORT void spine_skeleton_set_scale(spine_skeleton obj, float scaleX, float scaleY);
SPINE_C_EXPORT float spine_skeleton_get_x(spine_skeleton obj);
SPINE_C_EXPORT void spine_skeleton_set_x(spine_skeleton obj, float value);
SPINE_C_EXPORT float spine_skeleton_get_y(spine_skeleton obj);
SPINE_C_EXPORT void spine_skeleton_set_y(spine_skeleton obj, float value);
SPINE_C_EXPORT void spine_skeleton_set_position(spine_skeleton obj, float x, float y);
SPINE_C_EXPORT float spine_skeleton_get_wind_x(spine_skeleton obj);
SPINE_C_EXPORT void spine_skeleton_set_wind_x(spine_skeleton obj, float value);
SPINE_C_EXPORT float spine_skeleton_get_wind_y(spine_skeleton obj);
SPINE_C_EXPORT void spine_skeleton_set_wind_y(spine_skeleton obj, float value);
SPINE_C_EXPORT float spine_skeleton_get_gravity_x(spine_skeleton obj);
SPINE_C_EXPORT void spine_skeleton_set_gravity_x(spine_skeleton obj, float value);
SPINE_C_EXPORT float spine_skeleton_get_gravity_y(spine_skeleton obj);
SPINE_C_EXPORT void spine_skeleton_set_gravity_y(spine_skeleton obj, float value);
SPINE_C_EXPORT void spine_skeleton_physics_translate(spine_skeleton obj, float x, float y);
SPINE_C_EXPORT void spine_skeleton_physics_rotate(spine_skeleton obj, float x, float y, float degrees);
SPINE_C_EXPORT float spine_skeleton_get_time(spine_skeleton obj);
SPINE_C_EXPORT void spine_skeleton_set_time(spine_skeleton obj, float value);
SPINE_C_EXPORT void spine_skeleton_update(spine_skeleton obj, float delta);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_SKELETON_H