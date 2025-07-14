#include "transform_constraint_data.h"
#include <spine/spine.h>

using namespace spine;

spine_transform_constraint_data spine_transform_constraint_data_create(const char* name) {
    return (spine_transform_constraint_data) new (__FILE__, __LINE__) TransformConstraintData(String(name));
}

void spine_transform_constraint_data_dispose(spine_transform_constraint_data self) {
    delete (TransformConstraintData*)self;
}

spine_rtti spine_transform_constraint_data_get_rtti(spine_transform_constraint_data self) {
    return (spine_rtti)&((TransformConstraintData*)self)->getRTTI();
}

spine_constraint spine_transform_constraint_data_create_method(spine_transform_constraint_data self, spine_skeleton skeleton) {
    return (spine_constraint)((TransformConstraintData*)self)->create(*((Skeleton*)skeleton));
}

spine_array_bone_data spine_transform_constraint_data_get_bones(spine_transform_constraint_data self) {
    return (spine_array_bone_data)&((TransformConstraintData*)self)->getBones();
}

spine_bone_data spine_transform_constraint_data_get_source(spine_transform_constraint_data self) {
    return (spine_bone_data)((TransformConstraintData*)self)->getSource();
}

void spine_transform_constraint_data_set_source(spine_transform_constraint_data self, spine_bone_data source) {
    ((TransformConstraintData*)self)->setSource((BoneData *)source);
}

float spine_transform_constraint_data_get_offset_rotation(spine_transform_constraint_data self) {
    return ((TransformConstraintData*)self)->getOffsetRotation();
}

void spine_transform_constraint_data_set_offset_rotation(spine_transform_constraint_data self, float offsetRotation) {
    ((TransformConstraintData*)self)->setOffsetRotation(offsetRotation);
}

float spine_transform_constraint_data_get_offset_x(spine_transform_constraint_data self) {
    return ((TransformConstraintData*)self)->getOffsetX();
}

void spine_transform_constraint_data_set_offset_x(spine_transform_constraint_data self, float offsetX) {
    ((TransformConstraintData*)self)->setOffsetX(offsetX);
}

float spine_transform_constraint_data_get_offset_y(spine_transform_constraint_data self) {
    return ((TransformConstraintData*)self)->getOffsetY();
}

void spine_transform_constraint_data_set_offset_y(spine_transform_constraint_data self, float offsetY) {
    ((TransformConstraintData*)self)->setOffsetY(offsetY);
}

float spine_transform_constraint_data_get_offset_scale_x(spine_transform_constraint_data self) {
    return ((TransformConstraintData*)self)->getOffsetScaleX();
}

void spine_transform_constraint_data_set_offset_scale_x(spine_transform_constraint_data self, float offsetScaleX) {
    ((TransformConstraintData*)self)->setOffsetScaleX(offsetScaleX);
}

float spine_transform_constraint_data_get_offset_scale_y(spine_transform_constraint_data self) {
    return ((TransformConstraintData*)self)->getOffsetScaleY();
}

void spine_transform_constraint_data_set_offset_scale_y(spine_transform_constraint_data self, float offsetScaleY) {
    ((TransformConstraintData*)self)->setOffsetScaleY(offsetScaleY);
}

float spine_transform_constraint_data_get_offset_shear_y(spine_transform_constraint_data self) {
    return ((TransformConstraintData*)self)->getOffsetShearY();
}

void spine_transform_constraint_data_set_offset_shear_y(spine_transform_constraint_data self, float offsetShearY) {
    ((TransformConstraintData*)self)->setOffsetShearY(offsetShearY);
}

bool spine_transform_constraint_data_get_local_source(spine_transform_constraint_data self) {
    return ((TransformConstraintData*)self)->getLocalSource();
}

void spine_transform_constraint_data_set_local_source(spine_transform_constraint_data self, bool localSource) {
    ((TransformConstraintData*)self)->setLocalSource(localSource);
}

bool spine_transform_constraint_data_get_local_target(spine_transform_constraint_data self) {
    return ((TransformConstraintData*)self)->getLocalTarget();
}

void spine_transform_constraint_data_set_local_target(spine_transform_constraint_data self, bool localTarget) {
    ((TransformConstraintData*)self)->setLocalTarget(localTarget);
}

bool spine_transform_constraint_data_get_additive(spine_transform_constraint_data self) {
    return ((TransformConstraintData*)self)->getAdditive();
}

void spine_transform_constraint_data_set_additive(spine_transform_constraint_data self, bool additive) {
    ((TransformConstraintData*)self)->setAdditive(additive);
}

bool spine_transform_constraint_data_get_clamp(spine_transform_constraint_data self) {
    return ((TransformConstraintData*)self)->getClamp();
}

void spine_transform_constraint_data_set_clamp(spine_transform_constraint_data self, bool clamp) {
    ((TransformConstraintData*)self)->setClamp(clamp);
}

spine_array_from_property spine_transform_constraint_data_get_properties(spine_transform_constraint_data self) {
    return (spine_array_from_property)&((TransformConstraintData*)self)->getProperties();
}

const char* spine_transform_constraint_data_get_name(spine_transform_constraint_data self) {
    return ((ConstraintDataGeneric<TransformConstraint, TransformConstraintPose>*)(TransformConstraintData*)self)->getName().buffer();
}

bool spine_transform_constraint_data_get_skin_required(spine_transform_constraint_data self) {
    return ((ConstraintDataGeneric<TransformConstraint, TransformConstraintPose>*)(TransformConstraintData*)self)->getSkinRequired();
}

spine_transform_constraint_pose spine_transform_constraint_data_get_setup_pose(spine_transform_constraint_data self) {
    return (spine_transform_constraint_pose)&((ConstraintDataGeneric<TransformConstraint, TransformConstraintPose>*)(TransformConstraintData*)self)->getSetupPose();
}

void spine_transform_constraint_data_set_skin_required(spine_transform_constraint_data self, bool skinRequired) {
    ((ConstraintDataGeneric<TransformConstraint, TransformConstraintPose>*)(TransformConstraintData*)self)->setSkinRequired(skinRequired);
}

spine_rtti spine_transform_constraint_data_rtti(void) {
    return (spine_rtti)&TransformConstraintData::rtti;
}
