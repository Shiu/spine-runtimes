#include "from_scale_y.h"
#include <spine/spine.h>

using namespace spine;

spine_from_scale_y spine_from_scale_y_create(void) {
    return (spine_from_scale_y) new (__FILE__, __LINE__) FromScaleY();
}

void spine_from_scale_y_dispose(spine_from_scale_y self) {
    delete (FromScaleY*)self;
}

spine_rtti spine_from_scale_y_get_rtti(spine_from_scale_y self) {
    return (spine_rtti)&((FromScaleY*)self)->getRTTI();
}

float spine_from_scale_y_value(spine_from_scale_y self, spine_skeleton skeleton, spine_bone_pose source, bool local, float * offsets) {
    return ((FromScaleY*)self)->value(*((Skeleton*)skeleton), *((BonePose*)source), local, offsets);
}

spine_rtti spine_from_scale_y_rtti(void) {
    return (spine_rtti)&FromScaleY::rtti;
}
