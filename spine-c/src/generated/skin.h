#ifndef SPINE_SPINE_SKIN_H
#define SPINE_SPINE_SKIN_H

#include "../base.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_skin spine_skin_create(const char* name);

SPINE_C_API void spine_skin_dispose(spine_skin self);

SPINE_C_API void spine_skin_set_attachment(spine_skin self, size_t slotIndex, const char* name, spine_attachment attachment);
SPINE_C_API spine_attachment spine_skin_get_attachment(spine_skin self, size_t slotIndex, const char* name);
SPINE_C_API void spine_skin_remove_attachment(spine_skin self, size_t slotIndex, const char* name);
SPINE_C_API void spine_skin_find_attachments_for_slot(spine_skin self, size_t slotIndex, spine_array_attachment attachments);
SPINE_C_API const char* spine_skin_get_name(spine_skin self);
SPINE_C_API void spine_skin_add_skin(spine_skin self, spine_skin other);
SPINE_C_API void spine_skin_copy_skin(spine_skin self, spine_skin other);
SPINE_C_API spine_array_bone_data spine_skin_get_bones(spine_skin self);
SPINE_C_API spine_array_constraint_data spine_skin_get_constraints(spine_skin self);
SPINE_C_API spine_color spine_skin_get_color(spine_skin self);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_SKIN_H */
