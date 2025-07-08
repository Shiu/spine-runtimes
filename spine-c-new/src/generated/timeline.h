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

#ifndef SPINE_C_TIMELINE_H
#define SPINE_C_TIMELINE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../custom.h"

SPINE_OPAQUE_TYPE(spine_timeline)

SPINE_C_EXPORT spine_timeline spine_timeline_create(spine_size_t frameCount, spine_size_t frameEntries);
SPINE_C_EXPORT void spine_timeline_dispose(spine_timeline obj);
SPINE_C_EXPORT spine_rtti spine_timeline_get_rtti(spine_timeline obj);
SPINE_C_EXPORT void spine_timeline_apply(spine_timeline obj, spine_skeleton skeleton, float lastTime, float time, void * pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, spine_bool appliedPose);
SPINE_C_EXPORT spine_size_t spine_timeline_get_frame_entries(spine_timeline obj);
SPINE_C_EXPORT spine_size_t spine_timeline_get_frame_count(spine_timeline obj);
SPINE_C_EXPORT void * spine_timeline_get_frames(spine_timeline obj);
SPINE_C_EXPORT int32_t spine_timeline_get_num_frames(spine_timeline obj);
SPINE_C_EXPORT spine_float *spine_timeline_get_frames(spine_timeline obj);
SPINE_C_EXPORT float spine_timeline_get_duration(spine_timeline obj);
SPINE_C_EXPORT void * spine_timeline_get_property_ids(spine_timeline obj);
SPINE_C_EXPORT int32_t spine_timeline_get_num_property_ids(spine_timeline obj);
SPINE_C_EXPORT spine_property_id *spine_timeline_get_property_ids(spine_timeline obj);
struct spine_attachment_timeline_wrapper;
typedef struct spine_attachment_timeline_wrapper *spine_attachment_timeline;
struct spine_rotate_timeline_wrapper;
typedef struct spine_rotate_timeline_wrapper *spine_rotate_timeline;
struct spine_scale_x_timeline_wrapper;
typedef struct spine_scale_x_timeline_wrapper *spine_scale_x_timeline;
struct spine_scale_y_timeline_wrapper;
typedef struct spine_scale_y_timeline_wrapper *spine_scale_y_timeline;
struct spine_shear_x_timeline_wrapper;
typedef struct spine_shear_x_timeline_wrapper *spine_shear_x_timeline;
struct spine_shear_y_timeline_wrapper;
typedef struct spine_shear_y_timeline_wrapper *spine_shear_y_timeline;
struct spine_translate_x_timeline_wrapper;
typedef struct spine_translate_x_timeline_wrapper *spine_translate_x_timeline;
struct spine_translate_y_timeline_wrapper;
typedef struct spine_translate_y_timeline_wrapper *spine_translate_y_timeline;
struct spine_alpha_timeline_wrapper;
typedef struct spine_alpha_timeline_wrapper *spine_alpha_timeline;
struct spine_path_constraint_position_timeline_wrapper;
typedef struct spine_path_constraint_position_timeline_wrapper *spine_path_constraint_position_timeline;
struct spine_path_constraint_spacing_timeline_wrapper;
typedef struct spine_path_constraint_spacing_timeline_wrapper *spine_path_constraint_spacing_timeline;
struct spine_slider_mix_timeline_wrapper;
typedef struct spine_slider_mix_timeline_wrapper *spine_slider_mix_timeline;
struct spine_slider_timeline_wrapper;
typedef struct spine_slider_timeline_wrapper *spine_slider_timeline;
struct spine_physics_constraint_inertia_timeline_wrapper;
typedef struct spine_physics_constraint_inertia_timeline_wrapper *spine_physics_constraint_inertia_timeline;
struct spine_physics_constraint_strength_timeline_wrapper;
typedef struct spine_physics_constraint_strength_timeline_wrapper *spine_physics_constraint_strength_timeline;
struct spine_physics_constraint_damping_timeline_wrapper;
typedef struct spine_physics_constraint_damping_timeline_wrapper *spine_physics_constraint_damping_timeline;
struct spine_physics_constraint_mass_timeline_wrapper;
typedef struct spine_physics_constraint_mass_timeline_wrapper *spine_physics_constraint_mass_timeline;
struct spine_physics_constraint_wind_timeline_wrapper;
typedef struct spine_physics_constraint_wind_timeline_wrapper *spine_physics_constraint_wind_timeline;
struct spine_physics_constraint_gravity_timeline_wrapper;
typedef struct spine_physics_constraint_gravity_timeline_wrapper *spine_physics_constraint_gravity_timeline;
struct spine_physics_constraint_mix_timeline_wrapper;
typedef struct spine_physics_constraint_mix_timeline_wrapper *spine_physics_constraint_mix_timeline;
struct spine_scale_timeline_wrapper;
typedef struct spine_scale_timeline_wrapper *spine_scale_timeline;
struct spine_shear_timeline_wrapper;
typedef struct spine_shear_timeline_wrapper *spine_shear_timeline;
struct spine_translate_timeline_wrapper;
typedef struct spine_translate_timeline_wrapper *spine_translate_timeline;
struct spine_ik_constraint_timeline_wrapper;
typedef struct spine_ik_constraint_timeline_wrapper *spine_ik_constraint_timeline;
struct spine_path_constraint_mix_timeline_wrapper;
typedef struct spine_path_constraint_mix_timeline_wrapper *spine_path_constraint_mix_timeline;
struct spine_rgba_timeline_wrapper;
typedef struct spine_rgba_timeline_wrapper *spine_rgba_timeline;
struct spine_rgb_timeline_wrapper;
typedef struct spine_rgb_timeline_wrapper *spine_rgb_timeline;
struct spine_rgba2_timeline_wrapper;
typedef struct spine_rgba2_timeline_wrapper *spine_rgba2_timeline;
struct spine_rgb2_timeline_wrapper;
typedef struct spine_rgb2_timeline_wrapper *spine_rgb2_timeline;
struct spine_deform_timeline_wrapper;
typedef struct spine_deform_timeline_wrapper *spine_deform_timeline;
struct spine_transform_constraint_timeline_wrapper;
typedef struct spine_transform_constraint_timeline_wrapper *spine_transform_constraint_timeline;
struct spine_draw_order_timeline_wrapper;
typedef struct spine_draw_order_timeline_wrapper *spine_draw_order_timeline;
struct spine_event_timeline_wrapper;
typedef struct spine_event_timeline_wrapper *spine_event_timeline;
struct spine_inherit_timeline_wrapper;
typedef struct spine_inherit_timeline_wrapper *spine_inherit_timeline;
struct spine_physics_constraint_reset_timeline_wrapper;
typedef struct spine_physics_constraint_reset_timeline_wrapper *spine_physics_constraint_reset_timeline;
struct spine_sequence_timeline_wrapper;
typedef struct spine_sequence_timeline_wrapper *spine_sequence_timeline;

typedef enum spine_timeline_type {
    SPINE_TYPE_TIMELINE_ATTACHMENT_TIMELINE = 0,
    SPINE_TYPE_TIMELINE_ROTATE_TIMELINE = 1,
    SPINE_TYPE_TIMELINE_SCALE_X_TIMELINE = 2,
    SPINE_TYPE_TIMELINE_SCALE_Y_TIMELINE = 3,
    SPINE_TYPE_TIMELINE_SHEAR_X_TIMELINE = 4,
    SPINE_TYPE_TIMELINE_SHEAR_Y_TIMELINE = 5,
    SPINE_TYPE_TIMELINE_TRANSLATE_X_TIMELINE = 6,
    SPINE_TYPE_TIMELINE_TRANSLATE_Y_TIMELINE = 7,
    SPINE_TYPE_TIMELINE_ALPHA_TIMELINE = 8,
    SPINE_TYPE_TIMELINE_PATH_CONSTRAINT_POSITION_TIMELINE = 9,
    SPINE_TYPE_TIMELINE_PATH_CONSTRAINT_SPACING_TIMELINE = 10,
    SPINE_TYPE_TIMELINE_SLIDER_MIX_TIMELINE = 11,
    SPINE_TYPE_TIMELINE_SLIDER_TIMELINE = 12,
    SPINE_TYPE_TIMELINE_PHYSICS_CONSTRAINT_INERTIA_TIMELINE = 13,
    SPINE_TYPE_TIMELINE_PHYSICS_CONSTRAINT_STRENGTH_TIMELINE = 14,
    SPINE_TYPE_TIMELINE_PHYSICS_CONSTRAINT_DAMPING_TIMELINE = 15,
    SPINE_TYPE_TIMELINE_PHYSICS_CONSTRAINT_MASS_TIMELINE = 16,
    SPINE_TYPE_TIMELINE_PHYSICS_CONSTRAINT_WIND_TIMELINE = 17,
    SPINE_TYPE_TIMELINE_PHYSICS_CONSTRAINT_GRAVITY_TIMELINE = 18,
    SPINE_TYPE_TIMELINE_PHYSICS_CONSTRAINT_MIX_TIMELINE = 19,
    SPINE_TYPE_TIMELINE_SCALE_TIMELINE = 20,
    SPINE_TYPE_TIMELINE_SHEAR_TIMELINE = 21,
    SPINE_TYPE_TIMELINE_TRANSLATE_TIMELINE = 22,
    SPINE_TYPE_TIMELINE_IK_CONSTRAINT_TIMELINE = 23,
    SPINE_TYPE_TIMELINE_PATH_CONSTRAINT_MIX_TIMELINE = 24,
    SPINE_TYPE_TIMELINE_RGBA_TIMELINE = 25,
    SPINE_TYPE_TIMELINE_RGB_TIMELINE = 26,
    SPINE_TYPE_TIMELINE_RGBA2_TIMELINE = 27,
    SPINE_TYPE_TIMELINE_RGB2_TIMELINE = 28,
    SPINE_TYPE_TIMELINE_DEFORM_TIMELINE = 29,
    SPINE_TYPE_TIMELINE_TRANSFORM_CONSTRAINT_TIMELINE = 30,
    SPINE_TYPE_TIMELINE_DRAW_ORDER_TIMELINE = 31,
    SPINE_TYPE_TIMELINE_EVENT_TIMELINE = 32,
    SPINE_TYPE_TIMELINE_INHERIT_TIMELINE = 33,
    SPINE_TYPE_TIMELINE_PHYSICS_CONSTRAINT_RESET_TIMELINE = 34,
    SPINE_TYPE_TIMELINE_SEQUENCE_TIMELINE = 35
} spine_timeline_type;

SPINE_C_EXPORT spine_bool spine_timeline_is_type(spine_timeline obj, spine_timeline_type type);
SPINE_C_EXPORT spine_attachment_timeline spine_timeline_as_attachment_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_rotate_timeline spine_timeline_as_rotate_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_scale_x_timeline spine_timeline_as_scale_x_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_scale_y_timeline spine_timeline_as_scale_y_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_shear_x_timeline spine_timeline_as_shear_x_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_shear_y_timeline spine_timeline_as_shear_y_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_translate_x_timeline spine_timeline_as_translate_x_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_translate_y_timeline spine_timeline_as_translate_y_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_alpha_timeline spine_timeline_as_alpha_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_path_constraint_position_timeline spine_timeline_as_path_constraint_position_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_path_constraint_spacing_timeline spine_timeline_as_path_constraint_spacing_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_slider_mix_timeline spine_timeline_as_slider_mix_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_slider_timeline spine_timeline_as_slider_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_physics_constraint_inertia_timeline spine_timeline_as_physics_constraint_inertia_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_physics_constraint_strength_timeline spine_timeline_as_physics_constraint_strength_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_physics_constraint_damping_timeline spine_timeline_as_physics_constraint_damping_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_physics_constraint_mass_timeline spine_timeline_as_physics_constraint_mass_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_physics_constraint_wind_timeline spine_timeline_as_physics_constraint_wind_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_physics_constraint_gravity_timeline spine_timeline_as_physics_constraint_gravity_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_physics_constraint_mix_timeline spine_timeline_as_physics_constraint_mix_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_scale_timeline spine_timeline_as_scale_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_shear_timeline spine_timeline_as_shear_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_translate_timeline spine_timeline_as_translate_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_ik_constraint_timeline spine_timeline_as_ik_constraint_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_path_constraint_mix_timeline spine_timeline_as_path_constraint_mix_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_rgba_timeline spine_timeline_as_rgba_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_rgb_timeline spine_timeline_as_rgb_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_rgba2_timeline spine_timeline_as_rgba2_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_rgb2_timeline spine_timeline_as_rgb2_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_deform_timeline spine_timeline_as_deform_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_transform_constraint_timeline spine_timeline_as_transform_constraint_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_draw_order_timeline spine_timeline_as_draw_order_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_event_timeline spine_timeline_as_event_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_inherit_timeline spine_timeline_as_inherit_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_physics_constraint_reset_timeline spine_timeline_as_physics_constraint_reset_timeline(spine_timeline obj);
SPINE_C_EXPORT spine_sequence_timeline spine_timeline_as_sequence_timeline(spine_timeline obj);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_TIMELINE_H