#include "to_scale_x.h"
#include <spine/spine.h>

using namespace spine;

spine_to_scale_x spine_to_scale_x_create(void) {
    return (spine_to_scale_x) new (__FILE__, __LINE__) ToScaleX();
}

void spine_to_scale_x_dispose(spine_to_scale_x self) {
    delete (ToScaleX*)self;
}

float spine_to_scale_x_mix(spine_to_scale_x self, spine_transform_constraint_pose pose) {
    return ((ToScaleX*)self)->mix(*((TransformConstraintPose*)pose));
}

void spine_to_scale_x_apply(spine_to_scale_x self, spine_skeleton skeleton, spine_transform_constraint_pose pose, spine_bone_pose bone, float value, bool local, bool additive) {
    ((ToScaleX*)self)->apply(*((Skeleton*)skeleton), *((TransformConstraintPose*)pose), *((BonePose*)bone), value, local, additive);
}
