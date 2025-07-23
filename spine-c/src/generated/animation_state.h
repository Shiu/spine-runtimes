#ifndef SPINE_SPINE_ANIMATION_STATE_H
#define SPINE_SPINE_ANIMATION_STATE_H

#include "../base.h"
#include "types.h"
#include "arrays.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_animation_state spine_animation_state_create(spine_animation_state_data data);

SPINE_C_API void spine_animation_state_dispose(spine_animation_state self);

SPINE_C_API void spine_animation_state_update(spine_animation_state self, float delta);
SPINE_C_API bool spine_animation_state_apply(spine_animation_state self, spine_skeleton skeleton);
SPINE_C_API void spine_animation_state_clear_tracks(spine_animation_state self);
SPINE_C_API void spine_animation_state_clear_track(spine_animation_state self, size_t trackIndex);
SPINE_C_API spine_track_entry spine_animation_state_set_animation_1(spine_animation_state self, size_t trackIndex, const char *animationName,
																	bool loop);
SPINE_C_API spine_track_entry spine_animation_state_set_animation_2(spine_animation_state self, size_t trackIndex, spine_animation animation,
																	bool loop);
SPINE_C_API spine_track_entry spine_animation_state_add_animation_1(spine_animation_state self, size_t trackIndex, const char *animationName,
																	bool loop, float delay);
SPINE_C_API spine_track_entry spine_animation_state_add_animation_2(spine_animation_state self, size_t trackIndex, spine_animation animation,
																	bool loop, float delay);
SPINE_C_API spine_track_entry spine_animation_state_set_empty_animation(spine_animation_state self, size_t trackIndex, float mixDuration);
SPINE_C_API spine_track_entry spine_animation_state_add_empty_animation(spine_animation_state self, size_t trackIndex, float mixDuration,
																		float delay);
SPINE_C_API void spine_animation_state_set_empty_animations(spine_animation_state self, float mixDuration);
SPINE_C_API spine_track_entry spine_animation_state_get_current(spine_animation_state self, size_t trackIndex);
SPINE_C_API spine_animation_state_data spine_animation_state_get_data(spine_animation_state self);
SPINE_C_API spine_array_track_entry spine_animation_state_get_tracks(spine_animation_state self);
SPINE_C_API float spine_animation_state_get_time_scale(spine_animation_state self);
SPINE_C_API void spine_animation_state_set_time_scale(spine_animation_state self, float inValue);
SPINE_C_API void spine_animation_state_disable_queue(spine_animation_state self);
SPINE_C_API void spine_animation_state_enable_queue(spine_animation_state self);
SPINE_C_API void spine_animation_state_set_manual_track_entry_disposal(spine_animation_state self, bool inValue);
SPINE_C_API bool spine_animation_state_get_manual_track_entry_disposal(spine_animation_state self);
SPINE_C_API void spine_animation_state_dispose_track_entry(spine_animation_state self, spine_track_entry entry);
SPINE_C_API void *spine_animation_state_get_renderer_object(spine_animation_state self);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_ANIMATION_STATE_H */
