#ifndef SPINE_SPINE_SLOT_POSE_H
#define SPINE_SPINE_SLOT_POSE_H

#include "../base.h"
#include "types.h"
#include "arrays.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_slot_pose spine_slot_pose_create(void);

SPINE_C_API void spine_slot_pose_dispose(spine_slot_pose self);

SPINE_C_API void spine_slot_pose_set(spine_slot_pose self, spine_slot_pose pose);
SPINE_C_API spine_color spine_slot_pose_get_color(spine_slot_pose self);
SPINE_C_API spine_color spine_slot_pose_get_dark_color(spine_slot_pose self);
SPINE_C_API bool spine_slot_pose_has_dark_color(spine_slot_pose self);
SPINE_C_API void spine_slot_pose_set_has_dark_color(spine_slot_pose self, bool hasDarkColor);
SPINE_C_API /*@null*/ spine_attachment spine_slot_pose_get_attachment(spine_slot_pose self);
SPINE_C_API void spine_slot_pose_set_attachment(spine_slot_pose self, /*@null*/ spine_attachment attachment);
SPINE_C_API int spine_slot_pose_get_sequence_index(spine_slot_pose self);
SPINE_C_API void spine_slot_pose_set_sequence_index(spine_slot_pose self, int sequenceIndex);
SPINE_C_API spine_array_float spine_slot_pose_get_deform(spine_slot_pose self);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_SLOT_POSE_H */
