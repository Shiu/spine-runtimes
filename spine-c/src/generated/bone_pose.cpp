#include "bone_pose.h"
#include <spine/spine.h>

using namespace spine;

spine_bone_pose spine_bone_pose_create(void) {
    return (spine_bone_pose) new (__FILE__, __LINE__) BonePose();
}

void spine_bone_pose_dispose(spine_bone_pose self) {
    delete (BonePose*)self;
}

void spine_bone_pose_update(spine_bone_pose self, spine_skeleton skeleton, spine_physics physics) {
    ((BonePose*)self)->update(*((Skeleton*)skeleton), (Physics)physics);
}

void spine_bone_pose_update_world_transform(spine_bone_pose self, spine_skeleton skeleton) {
    ((BonePose*)self)->updateWorldTransform(*((Skeleton*)skeleton));
}

void spine_bone_pose_update_local_transform(spine_bone_pose self, spine_skeleton skeleton) {
    ((BonePose*)self)->updateLocalTransform(*((Skeleton*)skeleton));
}

void spine_bone_pose_validate_local_transform(spine_bone_pose self, spine_skeleton skeleton) {
    ((BonePose*)self)->validateLocalTransform(*((Skeleton*)skeleton));
}

void spine_bone_pose_modify_local(spine_bone_pose self, spine_skeleton skeleton) {
    ((BonePose*)self)->modifyLocal(*((Skeleton*)skeleton));
}

void spine_bone_pose_modify_world(spine_bone_pose self, int update) {
    ((BonePose*)self)->modifyWorld(update);
}

void spine_bone_pose_reset_world(spine_bone_pose self, int update) {
    ((BonePose*)self)->resetWorld(update);
}

float spine_bone_pose_get_a(spine_bone_pose self) {
    return ((BonePose*)self)->getA();
}

void spine_bone_pose_set_a(spine_bone_pose self, float a) {
    ((BonePose*)self)->setA(a);
}

float spine_bone_pose_get_b(spine_bone_pose self) {
    return ((BonePose*)self)->getB();
}

void spine_bone_pose_set_b(spine_bone_pose self, float b) {
    ((BonePose*)self)->setB(b);
}

float spine_bone_pose_get_c(spine_bone_pose self) {
    return ((BonePose*)self)->getC();
}

void spine_bone_pose_set_c(spine_bone_pose self, float c) {
    ((BonePose*)self)->setC(c);
}

float spine_bone_pose_get_d(spine_bone_pose self) {
    return ((BonePose*)self)->getD();
}

void spine_bone_pose_set_d(spine_bone_pose self, float d) {
    ((BonePose*)self)->setD(d);
}

float spine_bone_pose_get_world_x(spine_bone_pose self) {
    return ((BonePose*)self)->getWorldX();
}

void spine_bone_pose_set_world_x(spine_bone_pose self, float worldX) {
    ((BonePose*)self)->setWorldX(worldX);
}

float spine_bone_pose_get_world_y(spine_bone_pose self) {
    return ((BonePose*)self)->getWorldY();
}

void spine_bone_pose_set_world_y(spine_bone_pose self, float worldY) {
    ((BonePose*)self)->setWorldY(worldY);
}

float spine_bone_pose_get_world_rotation_x(spine_bone_pose self) {
    return ((BonePose*)self)->getWorldRotationX();
}

float spine_bone_pose_get_world_rotation_y(spine_bone_pose self) {
    return ((BonePose*)self)->getWorldRotationY();
}

float spine_bone_pose_get_world_scale_x(spine_bone_pose self) {
    return ((BonePose*)self)->getWorldScaleX();
}

float spine_bone_pose_get_world_scale_y(spine_bone_pose self) {
    return ((BonePose*)self)->getWorldScaleY();
}

void spine_bone_pose_world_to_local(spine_bone_pose self, float worldX, float worldY, float * outLocalX, float * outLocalY) {
    ((BonePose*)self)->worldToLocal(worldX, worldY, *outLocalX, *outLocalY);
}

void spine_bone_pose_local_to_world(spine_bone_pose self, float localX, float localY, float * outWorldX, float * outWorldY) {
    ((BonePose*)self)->localToWorld(localX, localY, *outWorldX, *outWorldY);
}

void spine_bone_pose_world_to_parent(spine_bone_pose self, float worldX, float worldY, float * outParentX, float * outParentY) {
    ((BonePose*)self)->worldToParent(worldX, worldY, *outParentX, *outParentY);
}

void spine_bone_pose_parent_to_world(spine_bone_pose self, float parentX, float parentY, float * outWorldX, float * outWorldY) {
    ((BonePose*)self)->parentToWorld(parentX, parentY, *outWorldX, *outWorldY);
}

float spine_bone_pose_world_to_local_rotation(spine_bone_pose self, float worldRotation) {
    return ((BonePose*)self)->worldToLocalRotation(worldRotation);
}

float spine_bone_pose_local_to_world_rotation(spine_bone_pose self, float localRotation) {
    return ((BonePose*)self)->localToWorldRotation(localRotation);
}

void spine_bone_pose_rotate_world(spine_bone_pose self, float degrees) {
    ((BonePose*)self)->rotateWorld(degrees);
}

void spine_bone_pose_set(spine_bone_pose self, spine_bone_local pose) {
    ((BoneLocal*)(BonePose*)self)->set(*((BoneLocal*)pose));
}

float spine_bone_pose_get_x(spine_bone_pose self) {
    return ((BoneLocal*)(BonePose*)self)->getX();
}

void spine_bone_pose_set_x(spine_bone_pose self, float x) {
    ((BoneLocal*)(BonePose*)self)->setX(x);
}

float spine_bone_pose_get_y(spine_bone_pose self) {
    return ((BoneLocal*)(BonePose*)self)->getY();
}

void spine_bone_pose_set_y(spine_bone_pose self, float y) {
    ((BoneLocal*)(BonePose*)self)->setY(y);
}

void spine_bone_pose_set_position(spine_bone_pose self, float x, float y) {
    ((BoneLocal*)(BonePose*)self)->setPosition(x, y);
}

float spine_bone_pose_get_rotation(spine_bone_pose self) {
    return ((BoneLocal*)(BonePose*)self)->getRotation();
}

void spine_bone_pose_set_rotation(spine_bone_pose self, float rotation) {
    ((BoneLocal*)(BonePose*)self)->setRotation(rotation);
}

float spine_bone_pose_get_scale_x(spine_bone_pose self) {
    return ((BoneLocal*)(BonePose*)self)->getScaleX();
}

void spine_bone_pose_set_scale_x(spine_bone_pose self, float scaleX) {
    ((BoneLocal*)(BonePose*)self)->setScaleX(scaleX);
}

float spine_bone_pose_get_scale_y(spine_bone_pose self) {
    return ((BoneLocal*)(BonePose*)self)->getScaleY();
}

void spine_bone_pose_set_scale_y(spine_bone_pose self, float scaleY) {
    ((BoneLocal*)(BonePose*)self)->setScaleY(scaleY);
}

void spine_bone_pose_set_scale_1(spine_bone_pose self, float scaleX, float scaleY) {
    ((BoneLocal*)(BonePose*)self)->setScale(scaleX, scaleY);
}

void spine_bone_pose_set_scale_2(spine_bone_pose self, float scale) {
    ((BoneLocal*)(BonePose*)self)->setScale(scale);
}

float spine_bone_pose_get_shear_x(spine_bone_pose self) {
    return ((BoneLocal*)(BonePose*)self)->getShearX();
}

void spine_bone_pose_set_shear_x(spine_bone_pose self, float shearX) {
    ((BoneLocal*)(BonePose*)self)->setShearX(shearX);
}

float spine_bone_pose_get_shear_y(spine_bone_pose self) {
    return ((BoneLocal*)(BonePose*)self)->getShearY();
}

void spine_bone_pose_set_shear_y(spine_bone_pose self, float shearY) {
    ((BoneLocal*)(BonePose*)self)->setShearY(shearY);
}

spine_inherit spine_bone_pose_get_inherit(spine_bone_pose self) {
    return (spine_inherit)((BoneLocal*)(BonePose*)self)->getInherit();
}

void spine_bone_pose_set_inherit(spine_bone_pose self, spine_inherit inherit) {
    ((BoneLocal*)(BonePose*)self)->setInherit((Inherit)inherit);
}

spine_rtti spine_bone_pose_get_rtti(spine_bone_pose self) {
    return (spine_rtti)&((Update*)(BonePose*)self)->getRTTI();
}

spine_rtti spine_bone_pose_rtti(void) {
    return (spine_rtti)&BonePose::rtti;
}
