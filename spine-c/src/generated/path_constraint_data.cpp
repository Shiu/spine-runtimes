#include "path_constraint_data.h"
#include <spine/spine.h>

using namespace spine;

spine_path_constraint_data spine_path_constraint_data_create(const char* name) {
    return (spine_path_constraint_data) new (__FILE__, __LINE__) PathConstraintData(String(name));
}

void spine_path_constraint_data_dispose(spine_path_constraint_data self) {
    delete (PathConstraintData*)self;
}

spine_rtti spine_path_constraint_data_get_rtti(spine_path_constraint_data self) {
    return (spine_rtti)&((PathConstraintData*)self)->getRTTI();
}

spine_constraint spine_path_constraint_data_create_method(spine_path_constraint_data self, spine_skeleton skeleton) {
    return (spine_constraint)((PathConstraintData*)self)->create(*((Skeleton*)skeleton));
}

spine_array_bone_data spine_path_constraint_data_get_bones(spine_path_constraint_data self) {
    return (spine_array_bone_data)&((PathConstraintData*)self)->getBones();
}

spine_slot_data spine_path_constraint_data_get_slot(spine_path_constraint_data self) {
    return (spine_slot_data)((PathConstraintData*)self)->getSlot();
}

void spine_path_constraint_data_set_slot(spine_path_constraint_data self, spine_slot_data slot) {
    ((PathConstraintData*)self)->setSlot((SlotData *)slot);
}

spine_position_mode spine_path_constraint_data_get_position_mode(spine_path_constraint_data self) {
    return (spine_position_mode)((PathConstraintData*)self)->getPositionMode();
}

void spine_path_constraint_data_set_position_mode(spine_path_constraint_data self, spine_position_mode positionMode) {
    ((PathConstraintData*)self)->setPositionMode((PositionMode)positionMode);
}

spine_spacing_mode spine_path_constraint_data_get_spacing_mode(spine_path_constraint_data self) {
    return (spine_spacing_mode)((PathConstraintData*)self)->getSpacingMode();
}

void spine_path_constraint_data_set_spacing_mode(spine_path_constraint_data self, spine_spacing_mode spacingMode) {
    ((PathConstraintData*)self)->setSpacingMode((SpacingMode)spacingMode);
}

spine_rotate_mode spine_path_constraint_data_get_rotate_mode(spine_path_constraint_data self) {
    return (spine_rotate_mode)((PathConstraintData*)self)->getRotateMode();
}

void spine_path_constraint_data_set_rotate_mode(spine_path_constraint_data self, spine_rotate_mode rotateMode) {
    ((PathConstraintData*)self)->setRotateMode((RotateMode)rotateMode);
}

float spine_path_constraint_data_get_offset_rotation(spine_path_constraint_data self) {
    return ((PathConstraintData*)self)->getOffsetRotation();
}

void spine_path_constraint_data_set_offset_rotation(spine_path_constraint_data self, float offsetRotation) {
    ((PathConstraintData*)self)->setOffsetRotation(offsetRotation);
}

const char* spine_path_constraint_data_get_name(spine_path_constraint_data self) {
    return ((ConstraintDataGeneric<PathConstraint, PathConstraintPose>*)(PathConstraintData*)self)->getName().buffer();
}

bool spine_path_constraint_data_is_skin_required(spine_path_constraint_data self) {
    return ((ConstraintDataGeneric<PathConstraint, PathConstraintPose>*)(PathConstraintData*)self)->isSkinRequired();
}

spine_path_constraint_pose spine_path_constraint_data_get_setup_pose(spine_path_constraint_data self) {
    return (spine_path_constraint_pose)&((ConstraintDataGeneric<PathConstraint, PathConstraintPose>*)(PathConstraintData*)self)->getSetupPose();
}

void spine_path_constraint_data_set_skin_required(spine_path_constraint_data self, bool skinRequired) {
    ((ConstraintDataGeneric<PathConstraint, PathConstraintPose>*)(PathConstraintData*)self)->setSkinRequired(skinRequired);
}

spine_rtti spine_path_constraint_data_rtti(void) {
    return (spine_rtti)&PathConstraintData::rtti;
}
