#ifndef SPINE_SPINE_IK_CONSTRAINT_DATA_H
#define SPINE_SPINE_IK_CONSTRAINT_DATA_H

#include "../base.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_ik_constraint_data spine_ik_constraint_data_create(const char * name);

SPINE_C_API void spine_ik_constraint_data_dispose(spine_ik_constraint_data self);

SPINE_C_API spine_rtti spine_ik_constraint_data_get_rtti(spine_ik_constraint_data self);
SPINE_C_API spine_constraint spine_ik_constraint_data_create_method(spine_ik_constraint_data self, spine_skeleton skeleton);
SPINE_C_API spine_array_bone_data spine_ik_constraint_data_get_bones(spine_ik_constraint_data self);
SPINE_C_API spine_bone_data spine_ik_constraint_data_get_target(spine_ik_constraint_data self);
SPINE_C_API void spine_ik_constraint_data_set_target(spine_ik_constraint_data self, spine_bone_data inValue);
SPINE_C_API bool spine_ik_constraint_data_get_uniform(spine_ik_constraint_data self);
SPINE_C_API void spine_ik_constraint_data_set_uniform(spine_ik_constraint_data self, bool uniform);
SPINE_C_API const char * spine_ik_constraint_data_get_name(spine_ik_constraint_data self);
SPINE_C_API bool spine_ik_constraint_data_get_skin_required(spine_ik_constraint_data self);
SPINE_C_API spine_ik_constraint_pose spine_ik_constraint_data_get_setup_pose(spine_ik_constraint_data self);
SPINE_C_API void spine_ik_constraint_data_set_skin_required(spine_ik_constraint_data self, bool skinRequired);
SPINE_C_API spine_rtti spine_ik_constraint_data_rtti(void);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_IK_CONSTRAINT_DATA_H */
