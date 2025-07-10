#include "path_constraint.h"
#include <spine/spine.h>

using namespace spine;

spine_path_constraint spine_path_constraint_create(spine_path_constraint_data data, spine_skeleton skeleton) {
    return (spine_path_constraint) new (__FILE__, __LINE__) PathConstraint(*((PathConstraintData*)data), *((Skeleton*)skeleton));
}

void spine_path_constraint_dispose(spine_path_constraint self) {
    delete (PathConstraint*)self;
}

spine_rtti spine_path_constraint_get_rtti(spine_path_constraint self) {
    return (spine_rtti)&((PathConstraint*)self)->getRTTI();
}

spine_path_constraint spine_path_constraint_copy(spine_path_constraint self, spine_skeleton skeleton) {
    return (spine_path_constraint)((PathConstraint*)self)->copy(*((Skeleton*)skeleton));
}

void spine_path_constraint_update(spine_path_constraint self, spine_skeleton skeleton, spine_physics physics) {
    ((PathConstraint*)self)->update(*((Skeleton*)skeleton), (Physics)physics);
}

void spine_path_constraint_sort(spine_path_constraint self, spine_skeleton skeleton) {
    ((PathConstraint*)self)->sort(*((Skeleton*)skeleton));
}

bool spine_path_constraint_is_source_active(spine_path_constraint self) {
    return ((PathConstraint*)self)->isSourceActive();
}

spine_array_bone_pose spine_path_constraint_get_bones(spine_path_constraint self) {
    return (spine_array_bone_pose)&((PathConstraint*)self)->getBones();
}

spine_slot spine_path_constraint_get_slot(spine_path_constraint self) {
    return (spine_slot)((PathConstraint*)self)->getSlot();
}

void spine_path_constraint_set_slot(spine_path_constraint self, spine_slot slot) {
    ((PathConstraint*)self)->setSlot((Slot *)slot);
}

spine_path_constraint_data spine_path_constraint_get_data(spine_path_constraint self) {
    return (spine_path_constraint_data)&((PathConstraint*)self)->getData();
}

spine_path_constraint_pose spine_path_constraint_get_pose(spine_path_constraint self) {
    return (spine_path_constraint_pose)&((ConstraintGeneric<PathConstraint, PathConstraintData, PathConstraintPose>*)(PathConstraint*)self)->getPose();
}

spine_path_constraint_pose spine_path_constraint_get_applied_pose(spine_path_constraint self) {
    return (spine_path_constraint_pose)&((ConstraintGeneric<PathConstraint, PathConstraintData, PathConstraintPose>*)(PathConstraint*)self)->getAppliedPose();
}

void spine_path_constraint_reset_constrained(spine_path_constraint self) {
    ((ConstraintGeneric<PathConstraint, PathConstraintData, PathConstraintPose>*)(PathConstraint*)self)->resetConstrained();
}

void spine_path_constraint_constrained(spine_path_constraint self) {
    ((ConstraintGeneric<PathConstraint, PathConstraintData, PathConstraintPose>*)(PathConstraint*)self)->constrained();
}

bool spine_path_constraint_is_pose_equal_to_applied(spine_path_constraint self) {
    return ((ConstraintGeneric<PathConstraint, PathConstraintData, PathConstraintPose>*)(PathConstraint*)self)->isPoseEqualToApplied();
}

bool spine_path_constraint_is_active(spine_path_constraint self) {
    return ((ConstraintGeneric<PathConstraint, PathConstraintData, PathConstraintPose>*)(PathConstraint*)self)->isActive();
}

void spine_path_constraint_set_active(spine_path_constraint self, bool active) {
    ((ConstraintGeneric<PathConstraint, PathConstraintData, PathConstraintPose>*)(PathConstraint*)self)->setActive(active);
}

spine_rtti spine_path_constraint_rtti(void) {
    return (spine_rtti)&PathConstraint::rtti;
}
