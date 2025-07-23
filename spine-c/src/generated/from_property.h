#ifndef SPINE_SPINE_FROM_PROPERTY_H
#define SPINE_SPINE_FROM_PROPERTY_H

#include "../base.h"
#include "types.h"
#include "arrays.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API void spine_from_property_dispose(spine_from_property self);

SPINE_C_API spine_rtti spine_from_property_get_rtti(spine_from_property self);
SPINE_C_API float spine_from_property_value(spine_from_property self, spine_skeleton skeleton, spine_bone_pose source, bool local, float *offsets);
SPINE_C_API spine_rtti spine_from_property_rtti(void);
SPINE_C_API float spine_from_property_get__offset(spine_from_property self);
SPINE_C_API void spine_from_property_set__offset(spine_from_property self, float value);
SPINE_C_API spine_array_to_property spine_from_property_get__to(spine_from_property self);
SPINE_C_API void spine_from_property_set__to(spine_from_property self, spine_array_to_property value);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_FROM_PROPERTY_H */
