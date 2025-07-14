#include "slider_data.h"
#include <spine/spine.h>

using namespace spine;

spine_slider_data spine_slider_data_create(const char* name) {
    return (spine_slider_data) new (__FILE__, __LINE__) SliderData(String(name));
}

void spine_slider_data_dispose(spine_slider_data self) {
    delete (SliderData*)self;
}

spine_rtti spine_slider_data_get_rtti(spine_slider_data self) {
    return (spine_rtti)&((SliderData*)self)->getRTTI();
}

spine_constraint spine_slider_data_create_method(spine_slider_data self, spine_skeleton skeleton) {
    return (spine_constraint)((SliderData*)self)->create(*((Skeleton*)skeleton));
}

spine_animation spine_slider_data_get_animation(spine_slider_data self) {
    return (spine_animation)((SliderData*)self)->getAnimation();
}

void spine_slider_data_set_animation(spine_slider_data self, spine_animation animation) {
    ((SliderData*)self)->setAnimation((Animation *)animation);
}

bool spine_slider_data_get_additive(spine_slider_data self) {
    return ((SliderData*)self)->getAdditive();
}

void spine_slider_data_set_additive(spine_slider_data self, bool additive) {
    ((SliderData*)self)->setAdditive(additive);
}

bool spine_slider_data_get_loop(spine_slider_data self) {
    return ((SliderData*)self)->getLoop();
}

void spine_slider_data_set_loop(spine_slider_data self, bool loop) {
    ((SliderData*)self)->setLoop(loop);
}

spine_bone_data spine_slider_data_get_bone(spine_slider_data self) {
    return (spine_bone_data)((SliderData*)self)->getBone();
}

void spine_slider_data_set_bone(spine_slider_data self, spine_bone_data bone) {
    ((SliderData*)self)->setBone((BoneData *)bone);
}

spine_from_property spine_slider_data_get_property(spine_slider_data self) {
    return (spine_from_property)((SliderData*)self)->getProperty();
}

void spine_slider_data_set_property(spine_slider_data self, spine_from_property property) {
    ((SliderData*)self)->setProperty((FromProperty *)property);
}

float spine_slider_data_get_scale(spine_slider_data self) {
    return ((SliderData*)self)->getScale();
}

void spine_slider_data_set_scale(spine_slider_data self, float scale) {
    ((SliderData*)self)->setScale(scale);
}

float spine_slider_data_get_offset(spine_slider_data self) {
    return ((SliderData*)self)->getOffset();
}

void spine_slider_data_set_offset(spine_slider_data self, float offset) {
    ((SliderData*)self)->setOffset(offset);
}

bool spine_slider_data_get_local(spine_slider_data self) {
    return ((SliderData*)self)->getLocal();
}

void spine_slider_data_set_local(spine_slider_data self, bool local) {
    ((SliderData*)self)->setLocal(local);
}

const char* spine_slider_data_get_name(spine_slider_data self) {
    return ((ConstraintDataGeneric<Slider, SliderPose>*)(SliderData*)self)->getName().buffer();
}

bool spine_slider_data_get_skin_required(spine_slider_data self) {
    return ((ConstraintDataGeneric<Slider, SliderPose>*)(SliderData*)self)->getSkinRequired();
}

spine_slider_pose spine_slider_data_get_setup_pose(spine_slider_data self) {
    return (spine_slider_pose)&((ConstraintDataGeneric<Slider, SliderPose>*)(SliderData*)self)->getSetupPose();
}

void spine_slider_data_set_skin_required(spine_slider_data self, bool skinRequired) {
    ((ConstraintDataGeneric<Slider, SliderPose>*)(SliderData*)self)->setSkinRequired(skinRequired);
}

spine_rtti spine_slider_data_rtti(void) {
    return (spine_rtti)&SliderData::rtti;
}
