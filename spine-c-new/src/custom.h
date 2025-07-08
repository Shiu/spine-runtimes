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

#ifndef SPINE_C_NEW_CUSTOM_H
#define SPINE_C_NEW_CUSTOM_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
#if _WIN32
#define SPINE_C_EXPORT extern "C" __declspec(dllexport)
#else
#ifdef __EMSCRIPTEN__
#define SPINE_C_EXPORT extern "C" __attribute__((used))
#else
#define SPINE_C_EXPORT extern "C"
#endif
#endif
#else
#if _WIN32
#define SPINE_C_EXPORT __declspec(dllexport)
#else
#ifdef __EMSCRIPTEN__
#define SPINE_C_EXPORT __attribute__((used))
#else
#define SPINE_C_EXPORT
#endif
#endif
#endif

#define SPINE_OPAQUE_TYPE(name)     \
    typedef struct name##_wrapper { \
    } name##_wrapper;               \
    typedef name##_wrapper *name;

typedef char utf8;
typedef int32_t spine_bool;
typedef size_t spine_size_t;

// Custom types for spine-c-new
SPINE_OPAQUE_TYPE(spine_atlas)
SPINE_OPAQUE_TYPE(spine_skeleton_data_result)
SPINE_OPAQUE_TYPE(spine_bounds)
SPINE_OPAQUE_TYPE(spine_vector)
SPINE_OPAQUE_TYPE(spine_color)
SPINE_OPAQUE_TYPE(spine_skeleton_drawable)
SPINE_OPAQUE_TYPE(spine_render_command)
SPINE_OPAQUE_TYPE(spine_skin_entry)
SPINE_OPAQUE_TYPE(spine_skin_entries)
SPINE_OPAQUE_TYPE(spine_rtti)

// Texture loader callbacks
typedef void* (*spine_texture_loader_load_func)(const char *path);
typedef void (*spine_texture_loader_unload_func)(void *texture);

// Version functions
SPINE_C_EXPORT int32_t spine_major_version();
SPINE_C_EXPORT int32_t spine_minor_version();
SPINE_C_EXPORT void spine_enable_debug_extension(spine_bool enable);
SPINE_C_EXPORT void spine_report_leaks();

// Color functions
SPINE_C_EXPORT float spine_color_get_r(spine_color color);
SPINE_C_EXPORT float spine_color_get_g(spine_color color);
SPINE_C_EXPORT float spine_color_get_b(spine_color color);
SPINE_C_EXPORT float spine_color_get_a(spine_color color);

// Bounds functions
SPINE_C_EXPORT float spine_bounds_get_x(spine_bounds bounds);
SPINE_C_EXPORT float spine_bounds_get_y(spine_bounds bounds);
SPINE_C_EXPORT float spine_bounds_get_width(spine_bounds bounds);
SPINE_C_EXPORT float spine_bounds_get_height(spine_bounds bounds);

// Vector functions
SPINE_C_EXPORT float spine_vector_get_x(spine_vector vector);
SPINE_C_EXPORT float spine_vector_get_y(spine_vector vector);

// Atlas functions
SPINE_C_EXPORT spine_atlas spine_atlas_load(const utf8 *atlasData);
SPINE_C_EXPORT spine_atlas spine_atlas_load_callback(const utf8 *atlasData, const utf8 *atlasDir, 
                                                     spine_texture_loader_load_func load, 
                                                     spine_texture_loader_unload_func unload);
SPINE_C_EXPORT int32_t spine_atlas_get_num_image_paths(spine_atlas atlas);
SPINE_C_EXPORT utf8 *spine_atlas_get_image_path(spine_atlas atlas, int32_t index);
SPINE_C_EXPORT spine_bool spine_atlas_is_pma(spine_atlas atlas);
SPINE_C_EXPORT utf8 *spine_atlas_get_error(spine_atlas atlas);
SPINE_C_EXPORT void spine_atlas_dispose(spine_atlas atlas);

// Forward declarations for types used in generated headers
struct spine_skeleton_data_wrapper;
typedef struct spine_skeleton_data_wrapper *spine_skeleton_data;
struct spine_timeline_wrapper;
typedef struct spine_timeline_wrapper *spine_timeline;
struct spine_skeleton_wrapper;
typedef struct spine_skeleton_wrapper *spine_skeleton;
struct spine_event_wrapper;
typedef struct spine_event_wrapper *spine_event;
struct spine_skin_wrapper;
typedef struct spine_skin_wrapper *spine_skin;
struct spine_sequence_wrapper;
typedef struct spine_sequence_wrapper *spine_sequence;
struct spine_attachment_wrapper;
typedef struct spine_attachment_wrapper *spine_attachment;

SPINE_C_EXPORT spine_skeleton_data_result spine_skeleton_data_load_json(spine_atlas atlas, const utf8 *skeletonData);
SPINE_C_EXPORT spine_skeleton_data_result spine_skeleton_data_load_binary(spine_atlas atlas, const uint8_t *skeletonData, int32_t length);
SPINE_C_EXPORT utf8 *spine_skeleton_data_result_get_error(spine_skeleton_data_result result);
SPINE_C_EXPORT spine_skeleton_data spine_skeleton_data_result_get_data(spine_skeleton_data_result result);
SPINE_C_EXPORT void spine_skeleton_data_result_dispose(spine_skeleton_data_result result);

// Skeleton drawable - these need forward declarations
struct spine_skeleton_wrapper;
typedef struct spine_skeleton_wrapper *spine_skeleton;
struct spine_animation_state_wrapper;
typedef struct spine_animation_state_wrapper *spine_animation_state;
struct spine_animation_state_data_wrapper;
typedef struct spine_animation_state_data_wrapper *spine_animation_state_data;
struct spine_animation_state_events_wrapper;
typedef struct spine_animation_state_events_wrapper *spine_animation_state_events;

SPINE_C_EXPORT spine_skeleton_drawable spine_skeleton_drawable_create(spine_skeleton_data skeletonData);
SPINE_C_EXPORT spine_render_command spine_skeleton_drawable_render(spine_skeleton_drawable drawable);
SPINE_C_EXPORT void spine_skeleton_drawable_dispose(spine_skeleton_drawable drawable);
SPINE_C_EXPORT spine_skeleton spine_skeleton_drawable_get_skeleton(spine_skeleton_drawable drawable);
SPINE_C_EXPORT spine_animation_state spine_skeleton_drawable_get_animation_state(spine_skeleton_drawable drawable);
SPINE_C_EXPORT spine_animation_state_data spine_skeleton_drawable_get_animation_state_data(spine_skeleton_drawable drawable);
SPINE_C_EXPORT spine_animation_state_events spine_skeleton_drawable_get_animation_state_events(spine_skeleton_drawable drawable);

// Render command functions
SPINE_C_EXPORT float *spine_render_command_get_positions(spine_render_command command);
SPINE_C_EXPORT float *spine_render_command_get_uvs(spine_render_command command);
SPINE_C_EXPORT int32_t *spine_render_command_get_colors(spine_render_command command);
SPINE_C_EXPORT int32_t *spine_render_command_get_dark_colors(spine_render_command command);
SPINE_C_EXPORT int32_t spine_render_command_get_num_vertices(spine_render_command command);
SPINE_C_EXPORT uint16_t *spine_render_command_get_indices(spine_render_command command);
SPINE_C_EXPORT int32_t spine_render_command_get_num_indices(spine_render_command command);
SPINE_C_EXPORT int32_t spine_render_command_get_atlas_page(spine_render_command command);

// Forward declaration for spine_blend_mode enum
typedef enum spine_blend_mode {
    SPINE_BLEND_MODE_NORMAL = 0,
    SPINE_BLEND_MODE_ADDITIVE,
    SPINE_BLEND_MODE_MULTIPLY,
    SPINE_BLEND_MODE_SCREEN
} spine_blend_mode;

// Forward declarations for other enum types used in generated headers
typedef enum spine_mix_blend spine_mix_blend;
typedef enum spine_mix_direction spine_mix_direction;

SPINE_C_EXPORT spine_blend_mode spine_render_command_get_blend_mode(spine_render_command command);
SPINE_C_EXPORT spine_render_command spine_render_command_get_next(spine_render_command command);

// Skin entries - these need forward declarations
struct spine_attachment_wrapper;
typedef struct spine_attachment_wrapper *spine_attachment;

SPINE_C_EXPORT spine_skin_entries spine_skin_entries_create();
SPINE_C_EXPORT void spine_skin_entries_dispose(spine_skin_entries entries);
SPINE_C_EXPORT int32_t spine_skin_entries_get_num_entries(spine_skin_entries entries);
SPINE_C_EXPORT spine_skin_entry spine_skin_entries_get_entry(spine_skin_entries entries, int32_t index);

SPINE_C_EXPORT int32_t spine_skin_entry_get_slot_index(spine_skin_entry entry);
SPINE_C_EXPORT const utf8 *spine_skin_entry_get_name(spine_skin_entry entry);
SPINE_C_EXPORT spine_attachment spine_skin_entry_get_attachment(spine_skin_entry entry);

#endif // SPINE_C_NEW_CUSTOM_H