#include "from_scale_x.h"
#include <spine/spine.h>

using namespace spine;

spine_from_scale_x spine_from_scale_x_create(void) {
    return (spine_from_scale_x) new (__FILE__, __LINE__) FromScaleX();
}

void spine_from_scale_x_dispose(spine_from_scale_x self) {
    delete (FromScaleX*)self;
}

float spine_from_scale_x_value(spine_from_scale_x self, spine_skeleton skeleton, spine_bone_pose source, bool local, float * offsets) {
    return ((FromScaleX*)self)->value(*((Skeleton*)skeleton), *((BonePose*)source), local, offsets);
}
