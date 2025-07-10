#ifndef SPINE_SPINE_TRACK_ENTRY_H
#define SPINE_SPINE_TRACK_ENTRY_H

#include "../base.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_track_entry spine_track_entry_create(void);

SPINE_C_API void spine_track_entry_dispose(spine_track_entry self);

SPINE_C_API int spine_track_entry_get_track_index(spine_track_entry self);
SPINE_C_API spine_animation spine_track_entry_get_animation(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_animation(spine_track_entry self, spine_animation animation);
SPINE_C_API spine_track_entry spine_track_entry_get_previous(spine_track_entry self);
SPINE_C_API bool spine_track_entry_get_loop(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_loop(spine_track_entry self, bool inValue);
SPINE_C_API bool spine_track_entry_get_hold_previous(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_hold_previous(spine_track_entry self, bool inValue);
SPINE_C_API bool spine_track_entry_get_reverse(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_reverse(spine_track_entry self, bool inValue);
SPINE_C_API bool spine_track_entry_get_shortest_rotation(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_shortest_rotation(spine_track_entry self, bool inValue);
SPINE_C_API float spine_track_entry_get_delay(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_delay(spine_track_entry self, float inValue);
SPINE_C_API float spine_track_entry_get_track_time(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_track_time(spine_track_entry self, float inValue);
SPINE_C_API float spine_track_entry_get_track_end(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_track_end(spine_track_entry self, float inValue);
SPINE_C_API float spine_track_entry_get_animation_start(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_animation_start(spine_track_entry self, float inValue);
SPINE_C_API float spine_track_entry_get_animation_end(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_animation_end(spine_track_entry self, float inValue);
SPINE_C_API float spine_track_entry_get_animation_last(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_animation_last(spine_track_entry self, float inValue);
SPINE_C_API float spine_track_entry_get_animation_time(spine_track_entry self);
SPINE_C_API float spine_track_entry_get_time_scale(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_time_scale(spine_track_entry self, float inValue);
SPINE_C_API float spine_track_entry_get_alpha(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_alpha(spine_track_entry self, float inValue);
SPINE_C_API float spine_track_entry_get_event_threshold(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_event_threshold(spine_track_entry self, float inValue);
SPINE_C_API float spine_track_entry_get_mix_attachment_threshold(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_mix_attachment_threshold(spine_track_entry self, float inValue);
SPINE_C_API float spine_track_entry_get_alpha_attachment_threshold(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_alpha_attachment_threshold(spine_track_entry self, float inValue);
SPINE_C_API float spine_track_entry_get_mix_draw_order_threshold(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_mix_draw_order_threshold(spine_track_entry self, float inValue);
SPINE_C_API spine_track_entry spine_track_entry_get_next(spine_track_entry self);
SPINE_C_API bool spine_track_entry_is_complete(spine_track_entry self);
SPINE_C_API float spine_track_entry_get_mix_time(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_mix_time(spine_track_entry self, float inValue);
SPINE_C_API float spine_track_entry_get_mix_duration(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_mix_duration_1(spine_track_entry self, float inValue);
SPINE_C_API void spine_track_entry_set_mix_duration_2(spine_track_entry self, float mixDuration, float delay);
SPINE_C_API spine_mix_blend spine_track_entry_get_mix_blend(spine_track_entry self);
SPINE_C_API void spine_track_entry_set_mix_blend(spine_track_entry self, spine_mix_blend blend);
SPINE_C_API spine_track_entry spine_track_entry_get_mixing_from(spine_track_entry self);
SPINE_C_API spine_track_entry spine_track_entry_get_mixing_to(spine_track_entry self);
SPINE_C_API void spine_track_entry_reset_rotation_directions(spine_track_entry self);
SPINE_C_API float spine_track_entry_get_track_complete(spine_track_entry self);
SPINE_C_API bool spine_track_entry_is_empty_animation(spine_track_entry self);
SPINE_C_API bool spine_track_entry_was_applied(spine_track_entry self);
SPINE_C_API bool spine_track_entry_is_next_ready(spine_track_entry self);
SPINE_C_API void * spine_track_entry_get_renderer_object(spine_track_entry self);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_TRACK_ENTRY_H */
