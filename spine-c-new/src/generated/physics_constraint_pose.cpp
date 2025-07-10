#include "physics_constraint_pose.h"
#include <spine/spine.h>

using namespace spine;

spine_physics_constraint_pose spine_physics_constraint_pose_create(void) {
    return (spine_physics_constraint_pose) new (__FILE__, __LINE__) PhysicsConstraintPose();
}

void spine_physics_constraint_pose_dispose(spine_physics_constraint_pose self) {
    delete (PhysicsConstraintPose*)self;
}

void spine_physics_constraint_pose_set(spine_physics_constraint_pose self, spine_physics_constraint_pose pose) {
    ((PhysicsConstraintPose*)self)->set(*((PhysicsConstraintPose*)pose));
}

float spine_physics_constraint_pose_get_inertia(spine_physics_constraint_pose self) {
    return ((PhysicsConstraintPose*)self)->getInertia();
}

void spine_physics_constraint_pose_set_inertia(spine_physics_constraint_pose self, float inertia) {
    ((PhysicsConstraintPose*)self)->setInertia(inertia);
}

float spine_physics_constraint_pose_get_strength(spine_physics_constraint_pose self) {
    return ((PhysicsConstraintPose*)self)->getStrength();
}

void spine_physics_constraint_pose_set_strength(spine_physics_constraint_pose self, float strength) {
    ((PhysicsConstraintPose*)self)->setStrength(strength);
}

float spine_physics_constraint_pose_get_damping(spine_physics_constraint_pose self) {
    return ((PhysicsConstraintPose*)self)->getDamping();
}

void spine_physics_constraint_pose_set_damping(spine_physics_constraint_pose self, float damping) {
    ((PhysicsConstraintPose*)self)->setDamping(damping);
}

float spine_physics_constraint_pose_get_mass_inverse(spine_physics_constraint_pose self) {
    return ((PhysicsConstraintPose*)self)->getMassInverse();
}

void spine_physics_constraint_pose_set_mass_inverse(spine_physics_constraint_pose self, float massInverse) {
    ((PhysicsConstraintPose*)self)->setMassInverse(massInverse);
}

float spine_physics_constraint_pose_get_wind(spine_physics_constraint_pose self) {
    return ((PhysicsConstraintPose*)self)->getWind();
}

void spine_physics_constraint_pose_set_wind(spine_physics_constraint_pose self, float wind) {
    ((PhysicsConstraintPose*)self)->setWind(wind);
}

float spine_physics_constraint_pose_get_gravity(spine_physics_constraint_pose self) {
    return ((PhysicsConstraintPose*)self)->getGravity();
}

void spine_physics_constraint_pose_set_gravity(spine_physics_constraint_pose self, float gravity) {
    ((PhysicsConstraintPose*)self)->setGravity(gravity);
}

float spine_physics_constraint_pose_get_mix(spine_physics_constraint_pose self) {
    return ((PhysicsConstraintPose*)self)->getMix();
}

void spine_physics_constraint_pose_set_mix(spine_physics_constraint_pose self, float mix) {
    ((PhysicsConstraintPose*)self)->setMix(mix);
}
