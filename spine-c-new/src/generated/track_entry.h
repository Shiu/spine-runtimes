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

#ifndef SPINE_C_TRACKENTRY_H
#define SPINE_C_TRACKENTRY_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../custom.h"

SPINE_OPAQUE_TYPE(spine_track_entry)

SPINE_C_EXPORT spine_track_entry spine_track_entry_create(void);
SPINE_C_EXPORT void spine_track_entry_dispose(spine_track_entry obj);
SPINE_C_EXPORT int32_t spine_track_entry_get_track_index(spine_track_entry obj);
SPINE_C_EXPORT spine_animation spine_track_entry_get_animation(spine_track_entry obj);
SPINE_C_EXPORT void spine_track_entry_set_animation(spine_track_entry obj, spine_animation value);
SPINE_C_EXPORT spine_track_entry spine_track_entry_get_previous(spine_track_entry obj);
SPINE_C_EXPORT spine_bool spine_track_entry_get_loop(spine_track_entry obj);
SPINE_C_EXPORT void spine_track_entry_set_loop(spine_track_entry obj, spine_bool value);
SPINE_C_EXPORT spine_bool spine_track_entry_get_hold_previous(spine_track_entry obj);
SPINE_C_EXPORT void spine_track_entry_set_hold_previous(spine_track_entry obj, spine_bool value);
SPINE_C_EXPORT spine_bool spine_track_entry_get_reverse(spine_track_entry obj);
SPINE_C_EXPORT void spine_track_entry_set_reverse(spine_track_entry obj, spine_bool value);
SPINE_C_EXPORT spine_bool spine_track_entry_get_shortest_rotation(spine_track_entry obj);
SPINE_C_EXPORT void spine_track_entry_set_shortest_rotation(spine_track_entry obj, spine_bool value);
SPINE_C_EXPORT float spine_track_entry_get_delay(spine_track_entry obj);
SPINE_C_EXPORT void spine_track_entry_set_delay(spine_track_entry obj, float value);
SPINE_C_EXPORT float spine_track_entry_get_track_time(spine_track_entry obj);
SPINE_C_EXPORT void spine_track_entry_set_track_time(spine_track_entry obj, float value);
SPINE_C_EXPORT float spine_track_entry_get_track_end(spine_track_entry obj);
SPINE_C_EXPORT void spine_track_entry_set_track_end(spine_track_entry obj, float value);
SPINE_C_EXPORT float spine_track_entry_get_animation_start(spine_track_entry obj);
SPINE_C_EXPORT void spine_track_entry_set_animation_start(spine_track_entry obj, float value);
SPINE_C_EXPORT float spine_track_entry_get_animation_end(spine_track_entry obj);
SPINE_C_EXPORT void spine_track_entry_set_animation_end(spine_track_entry obj, float value);
SPINE_C_EXPORT float spine_track_entry_get_animation_last(spine_track_entry obj);
SPINE_C_EXPORT void spine_track_entry_set_animation_last(spine_track_entry obj, float value);
SPINE_C_EXPORT float spine_track_entry_get_animation_time(spine_track_entry obj);
SPINE_C_EXPORT float spine_track_entry_get_time_scale(spine_track_entry obj);
SPINE_C_EXPORT void spine_track_entry_set_time_scale(spine_track_entry obj, float value);
SPINE_C_EXPORT float spine_track_entry_get_alpha(spine_track_entry obj);
SPINE_C_EXPORT void spine_track_entry_set_alpha(spine_track_entry obj, float value);
SPINE_C_EXPORT float spine_track_entry_get_event_threshold(spine_track_entry obj);
SPINE_C_EXPORT void spine_track_entry_set_event_threshold(spine_track_entry obj, float value);
SPINE_C_EXPORT float spine_track_entry_get_mix_attachment_threshold(spine_track_entry obj);
SPINE_C_EXPORT void spine_track_entry_set_mix_attachment_threshold(spine_track_entry obj, float value);
SPINE_C_EXPORT float spine_track_entry_get_alpha_attachment_threshold(spine_track_entry obj);
SPINE_C_EXPORT void spine_track_entry_set_alpha_attachment_threshold(spine_track_entry obj, float value);
SPINE_C_EXPORT float spine_track_entry_get_mix_draw_order_threshold(spine_track_entry obj);
SPINE_C_EXPORT void spine_track_entry_set_mix_draw_order_threshold(spine_track_entry obj, float value);
SPINE_C_EXPORT spine_track_entry spine_track_entry_get_next(spine_track_entry obj);
SPINE_C_EXPORT spine_bool spine_track_entry_is_complete(spine_track_entry obj);
SPINE_C_EXPORT float spine_track_entry_get_mix_time(spine_track_entry obj);
SPINE_C_EXPORT void spine_track_entry_set_mix_time(spine_track_entry obj, float value);
SPINE_C_EXPORT float spine_track_entry_get_mix_duration(spine_track_entry obj);
SPINE_C_EXPORT void spine_track_entry_set_mix_duration(spine_track_entry obj, float value);
SPINE_C_EXPORT void spine_track_entry_set_mix_duration(spine_track_entry obj, float mixDuration, float delay);
SPINE_C_EXPORT spine_mix_blend spine_track_entry_get_mix_blend(spine_track_entry obj);
SPINE_C_EXPORT void spine_track_entry_set_mix_blend(spine_track_entry obj, spine_mix_blend value);
SPINE_C_EXPORT spine_track_entry spine_track_entry_get_mixing_from(spine_track_entry obj);
SPINE_C_EXPORT spine_track_entry spine_track_entry_get_mixing_to(spine_track_entry obj);
SPINE_C_EXPORT void spine_track_entry_reset_rotation_directions(spine_track_entry obj);
SPINE_C_EXPORT float spine_track_entry_get_track_complete(spine_track_entry obj);
SPINE_C_EXPORT void spine_track_entry_set_listener(spine_track_entry obj, spine_animation_state_listener value);
SPINE_C_EXPORT void spine_track_entry_set_listener(spine_track_entry obj, spine_animation_state_listener_object value);
SPINE_C_EXPORT spine_bool spine_track_entry_is_empty_animation(spine_track_entry obj);
SPINE_C_EXPORT spine_bool spine_track_entry_was_applied(spine_track_entry obj);
SPINE_C_EXPORT spine_bool spine_track_entry_is_next_ready(spine_track_entry obj);
SPINE_C_EXPORT spine_void spine_track_entry_get_renderer_object(spine_track_entry obj);
SPINE_C_EXPORT void spine_track_entry_set_renderer_object(spine_track_entry obj, spine_void rendererObject, spine_dispose_renderer_object dispose);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_TRACKENTRY_H