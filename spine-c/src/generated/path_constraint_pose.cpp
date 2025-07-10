#include "path_constraint_pose.h"
#include <spine/spine.h>

using namespace spine;

spine_path_constraint_pose spine_path_constraint_pose_create(void) {
    return (spine_path_constraint_pose) new (__FILE__, __LINE__) PathConstraintPose();
}

void spine_path_constraint_pose_dispose(spine_path_constraint_pose self) {
    delete (PathConstraintPose*)self;
}

void spine_path_constraint_pose_set(spine_path_constraint_pose self, spine_path_constraint_pose pose) {
    ((PathConstraintPose*)self)->set(*((PathConstraintPose*)pose));
}

float spine_path_constraint_pose_get_position(spine_path_constraint_pose self) {
    return ((PathConstraintPose*)self)->getPosition();
}

void spine_path_constraint_pose_set_position(spine_path_constraint_pose self, float position) {
    ((PathConstraintPose*)self)->setPosition(position);
}

float spine_path_constraint_pose_get_spacing(spine_path_constraint_pose self) {
    return ((PathConstraintPose*)self)->getSpacing();
}

void spine_path_constraint_pose_set_spacing(spine_path_constraint_pose self, float spacing) {
    ((PathConstraintPose*)self)->setSpacing(spacing);
}

float spine_path_constraint_pose_get_mix_rotate(spine_path_constraint_pose self) {
    return ((PathConstraintPose*)self)->getMixRotate();
}

void spine_path_constraint_pose_set_mix_rotate(spine_path_constraint_pose self, float mixRotate) {
    ((PathConstraintPose*)self)->setMixRotate(mixRotate);
}

float spine_path_constraint_pose_get_mix_x(spine_path_constraint_pose self) {
    return ((PathConstraintPose*)self)->getMixX();
}

void spine_path_constraint_pose_set_mix_x(spine_path_constraint_pose self, float mixX) {
    ((PathConstraintPose*)self)->setMixX(mixX);
}

float spine_path_constraint_pose_get_mix_y(spine_path_constraint_pose self) {
    return ((PathConstraintPose*)self)->getMixY();
}

void spine_path_constraint_pose_set_mix_y(spine_path_constraint_pose self, float mixY) {
    ((PathConstraintPose*)self)->setMixY(mixY);
}
