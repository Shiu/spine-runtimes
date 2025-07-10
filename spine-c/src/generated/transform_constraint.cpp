#include "transform_constraint.h"
#include <spine/spine.h>

using namespace spine;

spine_transform_constraint spine_transform_constraint_create(spine_transform_constraint_data data, spine_skeleton skeleton) {
    return (spine_transform_constraint) new (__FILE__, __LINE__) TransformConstraint(*((TransformConstraintData*)data), *((Skeleton*)skeleton));
}

void spine_transform_constraint_dispose(spine_transform_constraint self) {
    delete (TransformConstraint*)self;
}

spine_rtti spine_transform_constraint_get_rtti(spine_transform_constraint self) {
    return (spine_rtti)&((TransformConstraint*)self)->getRTTI();
}

spine_transform_constraint spine_transform_constraint_copy(spine_transform_constraint self, spine_skeleton skeleton) {
    return (spine_transform_constraint)((TransformConstraint*)self)->copy(*((Skeleton*)skeleton));
}

void spine_transform_constraint_update(spine_transform_constraint self, spine_skeleton skeleton, spine_physics physics) {
    ((TransformConstraint*)self)->update(*((Skeleton*)skeleton), (Physics)physics);
}

void spine_transform_constraint_sort(spine_transform_constraint self, spine_skeleton skeleton) {
    ((TransformConstraint*)self)->sort(*((Skeleton*)skeleton));
}

bool spine_transform_constraint_is_source_active(spine_transform_constraint self) {
    return ((TransformConstraint*)self)->isSourceActive();
}

spine_array_bone_pose spine_transform_constraint_get_bones(spine_transform_constraint self) {
    return (spine_array_bone_pose)&((TransformConstraint*)self)->getBones();
}

spine_bone spine_transform_constraint_get_source(spine_transform_constraint self) {
    return (spine_bone)((TransformConstraint*)self)->getSource();
}

void spine_transform_constraint_set_source(spine_transform_constraint self, spine_bone source) {
    ((TransformConstraint*)self)->setSource((Bone *)source);
}

spine_constraint_data spine_transform_constraint_get_data(spine_transform_constraint self) {
    return (spine_constraint_data)&((ConstraintGeneric<TransformConstraint, TransformConstraintData, TransformConstraintPose>*)(TransformConstraint*)self)->getData();
}

spine_transform_constraint_pose spine_transform_constraint_get_pose(spine_transform_constraint self) {
    return (spine_transform_constraint_pose)&((ConstraintGeneric<TransformConstraint, TransformConstraintData, TransformConstraintPose>*)(TransformConstraint*)self)->getPose();
}

spine_transform_constraint_pose spine_transform_constraint_get_applied_pose(spine_transform_constraint self) {
    return (spine_transform_constraint_pose)&((ConstraintGeneric<TransformConstraint, TransformConstraintData, TransformConstraintPose>*)(TransformConstraint*)self)->getAppliedPose();
}

void spine_transform_constraint_reset_constrained(spine_transform_constraint self) {
    ((ConstraintGeneric<TransformConstraint, TransformConstraintData, TransformConstraintPose>*)(TransformConstraint*)self)->resetConstrained();
}

void spine_transform_constraint_constrained(spine_transform_constraint self) {
    ((ConstraintGeneric<TransformConstraint, TransformConstraintData, TransformConstraintPose>*)(TransformConstraint*)self)->constrained();
}

bool spine_transform_constraint_is_pose_equal_to_applied(spine_transform_constraint self) {
    return ((ConstraintGeneric<TransformConstraint, TransformConstraintData, TransformConstraintPose>*)(TransformConstraint*)self)->isPoseEqualToApplied();
}

bool spine_transform_constraint_is_active(spine_transform_constraint self) {
    return ((ConstraintGeneric<TransformConstraint, TransformConstraintData, TransformConstraintPose>*)(TransformConstraint*)self)->isActive();
}

void spine_transform_constraint_set_active(spine_transform_constraint self, bool active) {
    ((ConstraintGeneric<TransformConstraint, TransformConstraintData, TransformConstraintPose>*)(TransformConstraint*)self)->setActive(active);
}

spine_rtti spine_transform_constraint_rtti(void) {
    return (spine_rtti)&TransformConstraint::rtti;
}
