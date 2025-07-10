#include "from_property.h"
#include <spine/spine.h>

using namespace spine;

void spine_from_property_dispose(spine_from_property self) {
    delete (FromProperty*)self;
}

float spine_from_property_value(spine_from_property self, spine_skeleton skeleton, spine_bone_pose source, bool local, float * offsets) {
    return ((FromProperty*)self)->value(*((Skeleton*)skeleton), *((BonePose*)source), local, offsets);
}

float spine_from_property_get__offset(spine_from_property self) {
    return ((FromProperty*)self)->_offset;
}

void spine_from_property_set__offset(spine_from_property self, float value) {
    ((FromProperty*)self)->_offset = value;
}

spine_array_to_property spine_from_property_get__to(spine_from_property self) {
    return (spine_array_to_property)&((FromProperty*)self)->_to;
}

void spine_from_property_set__to(spine_from_property self, spine_array_to_property value) {
    ((FromProperty*)self)->_to = *((Array<ToProperty *>*)value);
}
