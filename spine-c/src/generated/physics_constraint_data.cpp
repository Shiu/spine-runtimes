#include "physics_constraint_data.h"
#include <spine/spine.h>

using namespace spine;

spine_physics_constraint_data spine_physics_constraint_data_create(const char* name) {
    return (spine_physics_constraint_data) new (__FILE__, __LINE__) PhysicsConstraintData(String(name));
}

void spine_physics_constraint_data_dispose(spine_physics_constraint_data self) {
    delete (PhysicsConstraintData*)self;
}

spine_rtti spine_physics_constraint_data_get_rtti(spine_physics_constraint_data self) {
    return (spine_rtti)&((PhysicsConstraintData*)self)->getRTTI();
}

spine_constraint spine_physics_constraint_data_create_method(spine_physics_constraint_data self, spine_skeleton skeleton) {
    return (spine_constraint)((PhysicsConstraintData*)self)->create(*((Skeleton*)skeleton));
}

spine_bone_data spine_physics_constraint_data_get_bone(spine_physics_constraint_data self) {
    return (spine_bone_data)((PhysicsConstraintData*)self)->getBone();
}

void spine_physics_constraint_data_set_bone(spine_physics_constraint_data self, spine_bone_data bone) {
    ((PhysicsConstraintData*)self)->setBone((BoneData *)bone);
}

float spine_physics_constraint_data_get_step(spine_physics_constraint_data self) {
    return ((PhysicsConstraintData*)self)->getStep();
}

void spine_physics_constraint_data_set_step(spine_physics_constraint_data self, float step) {
    ((PhysicsConstraintData*)self)->setStep(step);
}

float spine_physics_constraint_data_get_x(spine_physics_constraint_data self) {
    return ((PhysicsConstraintData*)self)->getX();
}

void spine_physics_constraint_data_set_x(spine_physics_constraint_data self, float x) {
    ((PhysicsConstraintData*)self)->setX(x);
}

float spine_physics_constraint_data_get_y(spine_physics_constraint_data self) {
    return ((PhysicsConstraintData*)self)->getY();
}

void spine_physics_constraint_data_set_y(spine_physics_constraint_data self, float y) {
    ((PhysicsConstraintData*)self)->setY(y);
}

float spine_physics_constraint_data_get_rotate(spine_physics_constraint_data self) {
    return ((PhysicsConstraintData*)self)->getRotate();
}

void spine_physics_constraint_data_set_rotate(spine_physics_constraint_data self, float rotate) {
    ((PhysicsConstraintData*)self)->setRotate(rotate);
}

float spine_physics_constraint_data_get_scale_x(spine_physics_constraint_data self) {
    return ((PhysicsConstraintData*)self)->getScaleX();
}

void spine_physics_constraint_data_set_scale_x(spine_physics_constraint_data self, float scaleX) {
    ((PhysicsConstraintData*)self)->setScaleX(scaleX);
}

float spine_physics_constraint_data_get_shear_x(spine_physics_constraint_data self) {
    return ((PhysicsConstraintData*)self)->getShearX();
}

void spine_physics_constraint_data_set_shear_x(spine_physics_constraint_data self, float shearX) {
    ((PhysicsConstraintData*)self)->setShearX(shearX);
}

float spine_physics_constraint_data_get_limit(spine_physics_constraint_data self) {
    return ((PhysicsConstraintData*)self)->getLimit();
}

void spine_physics_constraint_data_set_limit(spine_physics_constraint_data self, float limit) {
    ((PhysicsConstraintData*)self)->setLimit(limit);
}

bool spine_physics_constraint_data_get_inertia_global(spine_physics_constraint_data self) {
    return ((PhysicsConstraintData*)self)->getInertiaGlobal();
}

void spine_physics_constraint_data_set_inertia_global(spine_physics_constraint_data self, bool inertiaGlobal) {
    ((PhysicsConstraintData*)self)->setInertiaGlobal(inertiaGlobal);
}

bool spine_physics_constraint_data_get_strength_global(spine_physics_constraint_data self) {
    return ((PhysicsConstraintData*)self)->getStrengthGlobal();
}

void spine_physics_constraint_data_set_strength_global(spine_physics_constraint_data self, bool strengthGlobal) {
    ((PhysicsConstraintData*)self)->setStrengthGlobal(strengthGlobal);
}

bool spine_physics_constraint_data_get_damping_global(spine_physics_constraint_data self) {
    return ((PhysicsConstraintData*)self)->getDampingGlobal();
}

void spine_physics_constraint_data_set_damping_global(spine_physics_constraint_data self, bool dampingGlobal) {
    ((PhysicsConstraintData*)self)->setDampingGlobal(dampingGlobal);
}

bool spine_physics_constraint_data_get_mass_global(spine_physics_constraint_data self) {
    return ((PhysicsConstraintData*)self)->getMassGlobal();
}

void spine_physics_constraint_data_set_mass_global(spine_physics_constraint_data self, bool massGlobal) {
    ((PhysicsConstraintData*)self)->setMassGlobal(massGlobal);
}

bool spine_physics_constraint_data_get_wind_global(spine_physics_constraint_data self) {
    return ((PhysicsConstraintData*)self)->getWindGlobal();
}

void spine_physics_constraint_data_set_wind_global(spine_physics_constraint_data self, bool windGlobal) {
    ((PhysicsConstraintData*)self)->setWindGlobal(windGlobal);
}

bool spine_physics_constraint_data_get_gravity_global(spine_physics_constraint_data self) {
    return ((PhysicsConstraintData*)self)->getGravityGlobal();
}

void spine_physics_constraint_data_set_gravity_global(spine_physics_constraint_data self, bool gravityGlobal) {
    ((PhysicsConstraintData*)self)->setGravityGlobal(gravityGlobal);
}

bool spine_physics_constraint_data_get_mix_global(spine_physics_constraint_data self) {
    return ((PhysicsConstraintData*)self)->getMixGlobal();
}

void spine_physics_constraint_data_set_mix_global(spine_physics_constraint_data self, bool mixGlobal) {
    ((PhysicsConstraintData*)self)->setMixGlobal(mixGlobal);
}

const char* spine_physics_constraint_data_get_name(spine_physics_constraint_data self) {
    return ((ConstraintDataGeneric<PhysicsConstraint, PhysicsConstraintPose>*)(PhysicsConstraintData*)self)->getName().buffer();
}

bool spine_physics_constraint_data_is_skin_required(spine_physics_constraint_data self) {
    return ((ConstraintDataGeneric<PhysicsConstraint, PhysicsConstraintPose>*)(PhysicsConstraintData*)self)->isSkinRequired();
}

spine_physics_constraint_pose spine_physics_constraint_data_get_setup_pose(spine_physics_constraint_data self) {
    return (spine_physics_constraint_pose)&((ConstraintDataGeneric<PhysicsConstraint, PhysicsConstraintPose>*)(PhysicsConstraintData*)self)->getSetupPose();
}

void spine_physics_constraint_data_set_skin_required(spine_physics_constraint_data self, bool skinRequired) {
    ((ConstraintDataGeneric<PhysicsConstraint, PhysicsConstraintPose>*)(PhysicsConstraintData*)self)->setSkinRequired(skinRequired);
}

spine_rtti spine_physics_constraint_data_rtti(void) {
    return (spine_rtti)&PhysicsConstraintData::rtti;
}
