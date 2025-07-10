#include "skeleton.h"
#include <spine/spine.h>

using namespace spine;

spine_skeleton spine_skeleton_create(spine_skeleton_data skeletonData) {
    return (spine_skeleton) new (__FILE__, __LINE__) Skeleton(*((SkeletonData*)skeletonData));
}

void spine_skeleton_dispose(spine_skeleton self) {
    delete (Skeleton*)self;
}

void spine_skeleton_update_cache(spine_skeleton self) {
    ((Skeleton*)self)->updateCache();
}

void spine_skeleton_print_update_cache(spine_skeleton self) {
    ((Skeleton*)self)->printUpdateCache();
}

void spine_skeleton_constrained(spine_skeleton self, spine_posed object) {
    ((Skeleton*)self)->constrained(*((Posed*)object));
}

void spine_skeleton_sort_bone(spine_skeleton self, spine_bone bone) {
    ((Skeleton*)self)->sortBone((Bone *)bone);
}

void spine_skeleton_sort_reset(spine_array_bone bones) {
    Skeleton::sortReset(*((Array<Bone *>*)bones));
}

void spine_skeleton_update_world_transform_1(spine_skeleton self, spine_physics physics) {
    ((Skeleton*)self)->updateWorldTransform((Physics)physics);
}

void spine_skeleton_update_world_transform_2(spine_skeleton self, spine_physics physics, spine_bone_pose parent) {
    ((Skeleton*)self)->updateWorldTransform((Physics)physics, (BonePose *)parent);
}

void spine_skeleton_setup_pose(spine_skeleton self) {
    ((Skeleton*)self)->setupPose();
}

void spine_skeleton_setup_pose_bones(spine_skeleton self) {
    ((Skeleton*)self)->setupPoseBones();
}

void spine_skeleton_setup_pose_slots(spine_skeleton self) {
    ((Skeleton*)self)->setupPoseSlots();
}

spine_skeleton_data spine_skeleton_get_data(spine_skeleton self) {
    return (spine_skeleton_data)((Skeleton*)self)->getData();
}

spine_array_bone spine_skeleton_get_bones(spine_skeleton self) {
    return (spine_array_bone)&((Skeleton*)self)->getBones();
}

spine_array_update spine_skeleton_get_update_cache(spine_skeleton self) {
    return (spine_array_update)&((Skeleton*)self)->getUpdateCache();
}

spine_bone spine_skeleton_get_root_bone(spine_skeleton self) {
    return (spine_bone)((Skeleton*)self)->getRootBone();
}

spine_bone spine_skeleton_find_bone(spine_skeleton self, const char* boneName) {
    return (spine_bone)((Skeleton*)self)->findBone(*((const String*)boneName));
}

spine_array_slot spine_skeleton_get_slots(spine_skeleton self) {
    return (spine_array_slot)&((Skeleton*)self)->getSlots();
}

spine_slot spine_skeleton_find_slot(spine_skeleton self, const char* slotName) {
    return (spine_slot)((Skeleton*)self)->findSlot(*((const String*)slotName));
}

spine_array_slot spine_skeleton_get_draw_order(spine_skeleton self) {
    return (spine_array_slot)&((Skeleton*)self)->getDrawOrder();
}

spine_skin spine_skeleton_get_skin(spine_skeleton self) {
    return (spine_skin)((Skeleton*)self)->getSkin();
}

void spine_skeleton_set_skin_1(spine_skeleton self, const char* skinName) {
    ((Skeleton*)self)->setSkin(*((const String*)skinName));
}

void spine_skeleton_set_skin_2(spine_skeleton self, spine_skin newSkin) {
    ((Skeleton*)self)->setSkin((Skin *)newSkin);
}

spine_attachment spine_skeleton_get_attachment_1(spine_skeleton self, const char* slotName, const char* attachmentName) {
    return (spine_attachment)((Skeleton*)self)->getAttachment(*((const String*)slotName), *((const String*)attachmentName));
}

spine_attachment spine_skeleton_get_attachment_2(spine_skeleton self, int slotIndex, const char* attachmentName) {
    return (spine_attachment)((Skeleton*)self)->getAttachment(slotIndex, *((const String*)attachmentName));
}

void spine_skeleton_set_attachment(spine_skeleton self, const char* slotName, const char* attachmentName) {
    ((Skeleton*)self)->setAttachment(*((const String*)slotName), *((const String*)attachmentName));
}

spine_array_constraint spine_skeleton_get_constraints(spine_skeleton self) {
    return (spine_array_constraint)&((Skeleton*)self)->getConstraints();
}

spine_array_physics_constraint spine_skeleton_get_physics_constraints(spine_skeleton self) {
    return (spine_array_physics_constraint)&((Skeleton*)self)->getPhysicsConstraints();
}

void spine_skeleton_get_bounds_1(spine_skeleton self, float* outX, float* outY, float* outWidth, float* outHeight, spine_array_float outVertexBuffer) {
    ((Skeleton*)self)->getBounds(*outX, *outY, *outWidth, *outHeight, *((Array<float>*)outVertexBuffer));
}

void spine_skeleton_get_bounds_2(spine_skeleton self, float* outX, float* outY, float* outWidth, float* outHeight, spine_array_float outVertexBuffer, spine_skeleton_clipping clipper) {
    ((Skeleton*)self)->getBounds(*outX, *outY, *outWidth, *outHeight, *((Array<float>*)outVertexBuffer), (SkeletonClipping *)clipper);
}

spine_color spine_skeleton_get_color(spine_skeleton self) {
    return (spine_color)&((Skeleton*)self)->getColor();
}

void spine_skeleton_set_color_1(spine_skeleton self, spine_color color) {
    ((Skeleton*)self)->setColor(*((Color*)color));
}

void spine_skeleton_set_color_2(spine_skeleton self, float r, float g, float b, float a) {
    ((Skeleton*)self)->setColor(r, g, b, a);
}

float spine_skeleton_get_scale_x(spine_skeleton self) {
    return ((Skeleton*)self)->getScaleX();
}

void spine_skeleton_set_scale_x(spine_skeleton self, float inValue) {
    ((Skeleton*)self)->setScaleX(inValue);
}

float spine_skeleton_get_scale_y(spine_skeleton self) {
    return ((Skeleton*)self)->getScaleY();
}

void spine_skeleton_set_scale_y(spine_skeleton self, float inValue) {
    ((Skeleton*)self)->setScaleY(inValue);
}

void spine_skeleton_set_scale(spine_skeleton self, float scaleX, float scaleY) {
    ((Skeleton*)self)->setScale(scaleX, scaleY);
}

float spine_skeleton_get_x(spine_skeleton self) {
    return ((Skeleton*)self)->getX();
}

void spine_skeleton_set_x(spine_skeleton self, float inValue) {
    ((Skeleton*)self)->setX(inValue);
}

float spine_skeleton_get_y(spine_skeleton self) {
    return ((Skeleton*)self)->getY();
}

void spine_skeleton_set_y(spine_skeleton self, float inValue) {
    ((Skeleton*)self)->setY(inValue);
}

void spine_skeleton_set_position(spine_skeleton self, float x, float y) {
    ((Skeleton*)self)->setPosition(x, y);
}

float spine_skeleton_get_wind_x(spine_skeleton self) {
    return ((Skeleton*)self)->getWindX();
}

void spine_skeleton_set_wind_x(spine_skeleton self, float windX) {
    ((Skeleton*)self)->setWindX(windX);
}

float spine_skeleton_get_wind_y(spine_skeleton self) {
    return ((Skeleton*)self)->getWindY();
}

void spine_skeleton_set_wind_y(spine_skeleton self, float windY) {
    ((Skeleton*)self)->setWindY(windY);
}

float spine_skeleton_get_gravity_x(spine_skeleton self) {
    return ((Skeleton*)self)->getGravityX();
}

void spine_skeleton_set_gravity_x(spine_skeleton self, float gravityX) {
    ((Skeleton*)self)->setGravityX(gravityX);
}

float spine_skeleton_get_gravity_y(spine_skeleton self) {
    return ((Skeleton*)self)->getGravityY();
}

void spine_skeleton_set_gravity_y(spine_skeleton self, float gravityY) {
    ((Skeleton*)self)->setGravityY(gravityY);
}

void spine_skeleton_physics_translate(spine_skeleton self, float x, float y) {
    ((Skeleton*)self)->physicsTranslate(x, y);
}

void spine_skeleton_physics_rotate(spine_skeleton self, float x, float y, float degrees) {
    ((Skeleton*)self)->physicsRotate(x, y, degrees);
}

float spine_skeleton_get_time(spine_skeleton self) {
    return ((Skeleton*)self)->getTime();
}

void spine_skeleton_set_time(spine_skeleton self, float time) {
    ((Skeleton*)self)->setTime(time);
}

void spine_skeleton_update(spine_skeleton self, float delta) {
    ((Skeleton*)self)->update(delta);
}
