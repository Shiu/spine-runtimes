#include "from_rotate.h"
#include <spine/spine.h>

using namespace spine;

spine_from_rotate spine_from_rotate_create(void) {
    return (spine_from_rotate) new (__FILE__, __LINE__) FromRotate();
}

void spine_from_rotate_dispose(spine_from_rotate self) {
    delete (FromRotate*)self;
}

float spine_from_rotate_value(spine_from_rotate self, spine_skeleton skeleton, spine_bone_pose source, bool local, float * offsets) {
    return ((FromRotate*)self)->value(*((Skeleton*)skeleton), *((BonePose*)source), local, offsets);
}
