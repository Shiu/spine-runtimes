#include "ik_constraint_data.h"
#include <spine/spine.h>

using namespace spine;

spine_ik_constraint_data spine_ik_constraint_data_create(const char* name) {
    return (spine_ik_constraint_data) new (__FILE__, __LINE__) IkConstraintData(*((const String*)name));
}

void spine_ik_constraint_data_dispose(spine_ik_constraint_data self) {
    delete (IkConstraintData*)self;
}

spine_rtti spine_ik_constraint_data_get_rtti(spine_ik_constraint_data self) {
    return (spine_rtti)&((IkConstraintData*)self)->getRTTI();
}

spine_constraint spine_ik_constraint_data_create_method(spine_ik_constraint_data self, spine_skeleton skeleton) {
    return (spine_constraint)((IkConstraintData*)self)->create(*((Skeleton*)skeleton));
}

spine_array_bone_data spine_ik_constraint_data_get_bones(spine_ik_constraint_data self) {
    return (spine_array_bone_data)&((IkConstraintData*)self)->getBones();
}

spine_bone_data spine_ik_constraint_data_get_target(spine_ik_constraint_data self) {
    return (spine_bone_data)((IkConstraintData*)self)->getTarget();
}

void spine_ik_constraint_data_set_target(spine_ik_constraint_data self, spine_bone_data inValue) {
    ((IkConstraintData*)self)->setTarget((BoneData *)inValue);
}

bool spine_ik_constraint_data_get_uniform(spine_ik_constraint_data self) {
    return ((IkConstraintData*)self)->getUniform();
}

void spine_ik_constraint_data_set_uniform(spine_ik_constraint_data self, bool uniform) {
    ((IkConstraintData*)self)->setUniform(uniform);
}

const char* spine_ik_constraint_data_get_name(spine_ik_constraint_data self) {
    return (const char*)&((ConstraintDataGeneric<IkConstraint, IkConstraintPose>*)(IkConstraintData*)self)->getName();
}

bool spine_ik_constraint_data_is_skin_required(spine_ik_constraint_data self) {
    return ((ConstraintDataGeneric<IkConstraint, IkConstraintPose>*)(IkConstraintData*)self)->isSkinRequired();
}

spine_ik_constraint_pose spine_ik_constraint_data_get_setup_pose(spine_ik_constraint_data self) {
    return (spine_ik_constraint_pose)&((ConstraintDataGeneric<IkConstraint, IkConstraintPose>*)(IkConstraintData*)self)->getSetupPose();
}

void spine_ik_constraint_data_set_skin_required(spine_ik_constraint_data self, bool skinRequired) {
    ((ConstraintDataGeneric<IkConstraint, IkConstraintPose>*)(IkConstraintData*)self)->setSkinRequired(skinRequired);
}

spine_rtti spine_ik_constraint_data_rtti(void) {
    return (spine_rtti)&IkConstraintData::rtti;
}
