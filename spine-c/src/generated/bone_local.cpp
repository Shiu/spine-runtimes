#include "bone_local.h"
#include <spine/spine.h>

using namespace spine;

spine_bone_local spine_bone_local_create(void) {
    return (spine_bone_local) new (__FILE__, __LINE__) BoneLocal();
}

void spine_bone_local_dispose(spine_bone_local self) {
    delete (BoneLocal*)self;
}

void spine_bone_local_set(spine_bone_local self, spine_bone_local pose) {
    ((BoneLocal*)self)->set(*((BoneLocal*)pose));
}

float spine_bone_local_get_x(spine_bone_local self) {
    return ((BoneLocal*)self)->getX();
}

void spine_bone_local_set_x(spine_bone_local self, float x) {
    ((BoneLocal*)self)->setX(x);
}

float spine_bone_local_get_y(spine_bone_local self) {
    return ((BoneLocal*)self)->getY();
}

void spine_bone_local_set_y(spine_bone_local self, float y) {
    ((BoneLocal*)self)->setY(y);
}

void spine_bone_local_set_position(spine_bone_local self, float x, float y) {
    ((BoneLocal*)self)->setPosition(x, y);
}

float spine_bone_local_get_rotation(spine_bone_local self) {
    return ((BoneLocal*)self)->getRotation();
}

void spine_bone_local_set_rotation(spine_bone_local self, float rotation) {
    ((BoneLocal*)self)->setRotation(rotation);
}

float spine_bone_local_get_scale_x(spine_bone_local self) {
    return ((BoneLocal*)self)->getScaleX();
}

void spine_bone_local_set_scale_x(spine_bone_local self, float scaleX) {
    ((BoneLocal*)self)->setScaleX(scaleX);
}

float spine_bone_local_get_scale_y(spine_bone_local self) {
    return ((BoneLocal*)self)->getScaleY();
}

void spine_bone_local_set_scale_y(spine_bone_local self, float scaleY) {
    ((BoneLocal*)self)->setScaleY(scaleY);
}

void spine_bone_local_set_scale_1(spine_bone_local self, float scaleX, float scaleY) {
    ((BoneLocal*)self)->setScale(scaleX, scaleY);
}

void spine_bone_local_set_scale_2(spine_bone_local self, float scale) {
    ((BoneLocal*)self)->setScale(scale);
}

float spine_bone_local_get_shear_x(spine_bone_local self) {
    return ((BoneLocal*)self)->getShearX();
}

void spine_bone_local_set_shear_x(spine_bone_local self, float shearX) {
    ((BoneLocal*)self)->setShearX(shearX);
}

float spine_bone_local_get_shear_y(spine_bone_local self) {
    return ((BoneLocal*)self)->getShearY();
}

void spine_bone_local_set_shear_y(spine_bone_local self, float shearY) {
    ((BoneLocal*)self)->setShearY(shearY);
}

spine_inherit spine_bone_local_get_inherit(spine_bone_local self) {
    return (spine_inherit)((BoneLocal*)self)->getInherit();
}

void spine_bone_local_set_inherit(spine_bone_local self, spine_inherit inherit) {
    ((BoneLocal*)self)->setInherit((Inherit)inherit);
}
