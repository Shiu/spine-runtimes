#include "skeleton_data.h"
#include <spine/spine.h>

using namespace spine;

spine_skeleton_data spine_skeleton_data_create(void) {
    return (spine_skeleton_data) new (__FILE__, __LINE__) SkeletonData();
}

void spine_skeleton_data_dispose(spine_skeleton_data self) {
    delete (SkeletonData*)self;
}

spine_bone_data spine_skeleton_data_find_bone(spine_skeleton_data self, const char* boneName) {
    return (spine_bone_data)((SkeletonData*)self)->findBone(String(boneName));
}

spine_slot_data spine_skeleton_data_find_slot(spine_skeleton_data self, const char* slotName) {
    return (spine_slot_data)((SkeletonData*)self)->findSlot(String(slotName));
}

spine_skin spine_skeleton_data_find_skin(spine_skeleton_data self, const char* skinName) {
    return (spine_skin)((SkeletonData*)self)->findSkin(String(skinName));
}

spine_event_data spine_skeleton_data_find_event(spine_skeleton_data self, const char* eventDataName) {
    return (spine_event_data)((SkeletonData*)self)->findEvent(String(eventDataName));
}

spine_animation spine_skeleton_data_find_animation(spine_skeleton_data self, const char* animationName) {
    return (spine_animation)((SkeletonData*)self)->findAnimation(String(animationName));
}

const char* spine_skeleton_data_get_name(spine_skeleton_data self) {
    return ((SkeletonData*)self)->getName().buffer();
}

void spine_skeleton_data_set_name(spine_skeleton_data self, const char* inValue) {
    ((SkeletonData*)self)->setName(String(inValue));
}

spine_array_bone_data spine_skeleton_data_get_bones(spine_skeleton_data self) {
    return (spine_array_bone_data)&((SkeletonData*)self)->getBones();
}

spine_array_slot_data spine_skeleton_data_get_slots(spine_skeleton_data self) {
    return (spine_array_slot_data)&((SkeletonData*)self)->getSlots();
}

spine_array_skin spine_skeleton_data_get_skins(spine_skeleton_data self) {
    return (spine_array_skin)&((SkeletonData*)self)->getSkins();
}

spine_skin spine_skeleton_data_get_default_skin(spine_skeleton_data self) {
    return (spine_skin)((SkeletonData*)self)->getDefaultSkin();
}

void spine_skeleton_data_set_default_skin(spine_skeleton_data self, spine_skin inValue) {
    ((SkeletonData*)self)->setDefaultSkin((Skin *)inValue);
}

spine_array_event_data spine_skeleton_data_get_events(spine_skeleton_data self) {
    return (spine_array_event_data)&((SkeletonData*)self)->getEvents();
}

spine_array_animation spine_skeleton_data_get_animations(spine_skeleton_data self) {
    return (spine_array_animation)&((SkeletonData*)self)->getAnimations();
}

spine_array_constraint_data spine_skeleton_data_get_constraints(spine_skeleton_data self) {
    return (spine_array_constraint_data)&((SkeletonData*)self)->getConstraints();
}

float spine_skeleton_data_get_x(spine_skeleton_data self) {
    return ((SkeletonData*)self)->getX();
}

void spine_skeleton_data_set_x(spine_skeleton_data self, float inValue) {
    ((SkeletonData*)self)->setX(inValue);
}

float spine_skeleton_data_get_y(spine_skeleton_data self) {
    return ((SkeletonData*)self)->getY();
}

void spine_skeleton_data_set_y(spine_skeleton_data self, float inValue) {
    ((SkeletonData*)self)->setY(inValue);
}

float spine_skeleton_data_get_width(spine_skeleton_data self) {
    return ((SkeletonData*)self)->getWidth();
}

void spine_skeleton_data_set_width(spine_skeleton_data self, float inValue) {
    ((SkeletonData*)self)->setWidth(inValue);
}

float spine_skeleton_data_get_height(spine_skeleton_data self) {
    return ((SkeletonData*)self)->getHeight();
}

void spine_skeleton_data_set_height(spine_skeleton_data self, float inValue) {
    ((SkeletonData*)self)->setHeight(inValue);
}

float spine_skeleton_data_get_reference_scale(spine_skeleton_data self) {
    return ((SkeletonData*)self)->getReferenceScale();
}

void spine_skeleton_data_set_reference_scale(spine_skeleton_data self, float inValue) {
    ((SkeletonData*)self)->setReferenceScale(inValue);
}

const char* spine_skeleton_data_get_version(spine_skeleton_data self) {
    return ((SkeletonData*)self)->getVersion().buffer();
}

void spine_skeleton_data_set_version(spine_skeleton_data self, const char* inValue) {
    ((SkeletonData*)self)->setVersion(String(inValue));
}

const char* spine_skeleton_data_get_hash(spine_skeleton_data self) {
    return ((SkeletonData*)self)->getHash().buffer();
}

void spine_skeleton_data_set_hash(spine_skeleton_data self, const char* inValue) {
    ((SkeletonData*)self)->setHash(String(inValue));
}

const char* spine_skeleton_data_get_images_path(spine_skeleton_data self) {
    return ((SkeletonData*)self)->getImagesPath().buffer();
}

void spine_skeleton_data_set_images_path(spine_skeleton_data self, const char* inValue) {
    ((SkeletonData*)self)->setImagesPath(String(inValue));
}

const char* spine_skeleton_data_get_audio_path(spine_skeleton_data self) {
    return ((SkeletonData*)self)->getAudioPath().buffer();
}

void spine_skeleton_data_set_audio_path(spine_skeleton_data self, const char* inValue) {
    ((SkeletonData*)self)->setAudioPath(String(inValue));
}

float spine_skeleton_data_get_fps(spine_skeleton_data self) {
    return ((SkeletonData*)self)->getFps();
}

void spine_skeleton_data_set_fps(spine_skeleton_data self, float inValue) {
    ((SkeletonData*)self)->setFps(inValue);
}
