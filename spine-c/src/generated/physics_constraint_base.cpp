#include "physics_constraint_base.h"
#include <spine/spine.h>

using namespace spine;

void spine_physics_constraint_base_dispose(spine_physics_constraint_base self) {
	delete (PhysicsConstraintBase *) self;
}

spine_physics_constraint_data spine_physics_constraint_base_get_data(spine_physics_constraint_base self) {
	ConstraintGeneric<PhysicsConstraint, PhysicsConstraintData, PhysicsConstraintPose>
		*_self = (ConstraintGeneric<PhysicsConstraint, PhysicsConstraintData, PhysicsConstraintPose> *) (PhysicsConstraintBase *) self;
	return (spine_physics_constraint_data) &_self->getData();
}

spine_physics_constraint_pose spine_physics_constraint_base_get_pose(spine_physics_constraint_base self) {
	ConstraintGeneric<PhysicsConstraint, PhysicsConstraintData, PhysicsConstraintPose>
		*_self = (ConstraintGeneric<PhysicsConstraint, PhysicsConstraintData, PhysicsConstraintPose> *) (PhysicsConstraintBase *) self;
	return (spine_physics_constraint_pose) &_self->getPose();
}

spine_physics_constraint_pose spine_physics_constraint_base_get_applied_pose(spine_physics_constraint_base self) {
	ConstraintGeneric<PhysicsConstraint, PhysicsConstraintData, PhysicsConstraintPose>
		*_self = (ConstraintGeneric<PhysicsConstraint, PhysicsConstraintData, PhysicsConstraintPose> *) (PhysicsConstraintBase *) self;
	return (spine_physics_constraint_pose) &_self->getAppliedPose();
}

void spine_physics_constraint_base_reset_constrained(spine_physics_constraint_base self) {
	ConstraintGeneric<PhysicsConstraint, PhysicsConstraintData, PhysicsConstraintPose>
		*_self = (ConstraintGeneric<PhysicsConstraint, PhysicsConstraintData, PhysicsConstraintPose> *) (PhysicsConstraintBase *) self;
	_self->resetConstrained();
}

void spine_physics_constraint_base_constrained(spine_physics_constraint_base self) {
	ConstraintGeneric<PhysicsConstraint, PhysicsConstraintData, PhysicsConstraintPose>
		*_self = (ConstraintGeneric<PhysicsConstraint, PhysicsConstraintData, PhysicsConstraintPose> *) (PhysicsConstraintBase *) self;
	_self->constrained();
}

bool spine_physics_constraint_base_is_pose_equal_to_applied(spine_physics_constraint_base self) {
	ConstraintGeneric<PhysicsConstraint, PhysicsConstraintData, PhysicsConstraintPose>
		*_self = (ConstraintGeneric<PhysicsConstraint, PhysicsConstraintData, PhysicsConstraintPose> *) (PhysicsConstraintBase *) self;
	return _self->isPoseEqualToApplied();
}

bool spine_physics_constraint_base_is_active(spine_physics_constraint_base self) {
	ConstraintGeneric<PhysicsConstraint, PhysicsConstraintData, PhysicsConstraintPose>
		*_self = (ConstraintGeneric<PhysicsConstraint, PhysicsConstraintData, PhysicsConstraintPose> *) (PhysicsConstraintBase *) self;
	return _self->isActive();
}

void spine_physics_constraint_base_set_active(spine_physics_constraint_base self, bool active) {
	ConstraintGeneric<PhysicsConstraint, PhysicsConstraintData, PhysicsConstraintPose>
		*_self = (ConstraintGeneric<PhysicsConstraint, PhysicsConstraintData, PhysicsConstraintPose> *) (PhysicsConstraintBase *) self;
	_self->setActive(active);
}

spine_rtti spine_physics_constraint_base_get_rtti(spine_physics_constraint_base self) {
	ConstraintGeneric<PhysicsConstraint, PhysicsConstraintData, PhysicsConstraintPose>
		*_self = (ConstraintGeneric<PhysicsConstraint, PhysicsConstraintData, PhysicsConstraintPose> *) (PhysicsConstraintBase *) self;
	return (spine_rtti) &_self->getRTTI();
}

void spine_physics_constraint_base_sort(spine_physics_constraint_base self, spine_skeleton skeleton) {
	ConstraintGeneric<PhysicsConstraint, PhysicsConstraintData, PhysicsConstraintPose>
		*_self = (ConstraintGeneric<PhysicsConstraint, PhysicsConstraintData, PhysicsConstraintPose> *) (PhysicsConstraintBase *) self;
	_self->sort(*((Skeleton *) skeleton));
}

bool spine_physics_constraint_base_is_source_active(spine_physics_constraint_base self) {
	ConstraintGeneric<PhysicsConstraint, PhysicsConstraintData, PhysicsConstraintPose>
		*_self = (ConstraintGeneric<PhysicsConstraint, PhysicsConstraintData, PhysicsConstraintPose> *) (PhysicsConstraintBase *) self;
	return _self->isSourceActive();
}

void spine_physics_constraint_base_update(spine_physics_constraint_base self, spine_skeleton skeleton, spine_physics physics) {
	ConstraintGeneric<PhysicsConstraint, PhysicsConstraintData, PhysicsConstraintPose>
		*_self = (ConstraintGeneric<PhysicsConstraint, PhysicsConstraintData, PhysicsConstraintPose> *) (PhysicsConstraintBase *) self;
	_self->update(*((Skeleton *) skeleton), (Physics) physics);
}

spine_rtti spine_physics_constraint_base_rtti(void) {
	return (spine_rtti) &PhysicsConstraintBase::rtti;
}
