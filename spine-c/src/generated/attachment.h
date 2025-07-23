#ifndef SPINE_SPINE_ATTACHMENT_H
#define SPINE_SPINE_ATTACHMENT_H

#include "../base.h"
#include "types.h"
#include "arrays.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API void spine_attachment_dispose(spine_attachment self);

SPINE_C_API spine_rtti spine_attachment_get_rtti(spine_attachment self);
SPINE_C_API const char *spine_attachment_get_name(spine_attachment self);
SPINE_C_API spine_attachment spine_attachment_copy(spine_attachment self);
SPINE_C_API int spine_attachment_get_ref_count(spine_attachment self);
SPINE_C_API void spine_attachment_reference(spine_attachment self);
SPINE_C_API void spine_attachment_dereference(spine_attachment self);
SPINE_C_API spine_rtti spine_attachment_rtti(void);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_ATTACHMENT_H */
