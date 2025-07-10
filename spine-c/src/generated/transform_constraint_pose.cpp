#include "transform_constraint_pose.h"
#include <spine/spine.h>

using namespace spine;

spine_transform_constraint_pose spine_transform_constraint_pose_create(void) {
    return (spine_transform_constraint_pose) new (__FILE__, __LINE__) TransformConstraintPose();
}

void spine_transform_constraint_pose_dispose(spine_transform_constraint_pose self) {
    delete (TransformConstraintPose*)self;
}

void spine_transform_constraint_pose_set(spine_transform_constraint_pose self, spine_transform_constraint_pose pose) {
    ((TransformConstraintPose*)self)->set(*((TransformConstraintPose*)pose));
}

float spine_transform_constraint_pose_get_mix_rotate(spine_transform_constraint_pose self) {
    return ((TransformConstraintPose*)self)->getMixRotate();
}

void spine_transform_constraint_pose_set_mix_rotate(spine_transform_constraint_pose self, float mixRotate) {
    ((TransformConstraintPose*)self)->setMixRotate(mixRotate);
}

float spine_transform_constraint_pose_get_mix_x(spine_transform_constraint_pose self) {
    return ((TransformConstraintPose*)self)->getMixX();
}

void spine_transform_constraint_pose_set_mix_x(spine_transform_constraint_pose self, float mixX) {
    ((TransformConstraintPose*)self)->setMixX(mixX);
}

float spine_transform_constraint_pose_get_mix_y(spine_transform_constraint_pose self) {
    return ((TransformConstraintPose*)self)->getMixY();
}

void spine_transform_constraint_pose_set_mix_y(spine_transform_constraint_pose self, float mixY) {
    ((TransformConstraintPose*)self)->setMixY(mixY);
}

float spine_transform_constraint_pose_get_mix_scale_x(spine_transform_constraint_pose self) {
    return ((TransformConstraintPose*)self)->getMixScaleX();
}

void spine_transform_constraint_pose_set_mix_scale_x(spine_transform_constraint_pose self, float mixScaleX) {
    ((TransformConstraintPose*)self)->setMixScaleX(mixScaleX);
}

float spine_transform_constraint_pose_get_mix_scale_y(spine_transform_constraint_pose self) {
    return ((TransformConstraintPose*)self)->getMixScaleY();
}

void spine_transform_constraint_pose_set_mix_scale_y(spine_transform_constraint_pose self, float mixScaleY) {
    ((TransformConstraintPose*)self)->setMixScaleY(mixScaleY);
}

float spine_transform_constraint_pose_get_mix_shear_y(spine_transform_constraint_pose self) {
    return ((TransformConstraintPose*)self)->getMixShearY();
}

void spine_transform_constraint_pose_set_mix_shear_y(spine_transform_constraint_pose self, float mixShearY) {
    ((TransformConstraintPose*)self)->setMixShearY(mixShearY);
}
