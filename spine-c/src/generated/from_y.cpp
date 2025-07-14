#include "from_y.h"
#include <spine/spine.h>

using namespace spine;

spine_from_y spine_from_y_create(void) {
    return (spine_from_y) new (__FILE__, __LINE__) FromY();
}

void spine_from_y_dispose(spine_from_y self) {
    delete (FromY*)self;
}

spine_rtti spine_from_y_get_rtti(spine_from_y self) {
    return (spine_rtti)&((FromY*)self)->getRTTI();
}

float spine_from_y_value(spine_from_y self, spine_skeleton skeleton, spine_bone_pose source, bool local, float * offsets) {
    return ((FromY*)self)->value(*((Skeleton*)skeleton), *((BonePose*)source), local, offsets);
}

spine_rtti spine_from_y_rtti(void) {
    return (spine_rtti)&FromY::rtti;
}
