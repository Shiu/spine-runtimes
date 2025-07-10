#include "from_x.h"
#include <spine/spine.h>

using namespace spine;

spine_from_x spine_from_x_create(void) {
    return (spine_from_x) new (__FILE__, __LINE__) FromX();
}

void spine_from_x_dispose(spine_from_x self) {
    delete (FromX*)self;
}

float spine_from_x_value(spine_from_x self, spine_skeleton skeleton, spine_bone_pose source, bool local, float * offsets) {
    return ((FromX*)self)->value(*((Skeleton*)skeleton), *((BonePose*)source), local, offsets);
}
