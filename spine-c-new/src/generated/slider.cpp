#include "slider.h"
#include <spine/spine.h>

using namespace spine;

spine_slider spine_slider_create(spine_slider_data data, spine_skeleton skeleton) {
    return (spine_slider) new (__FILE__, __LINE__) Slider(*((SliderData*)data), *((Skeleton*)skeleton));
}

void spine_slider_dispose(spine_slider self) {
    delete (Slider*)self;
}

spine_rtti spine_slider_get_rtti(spine_slider self) {
    return (spine_rtti)&((Slider*)self)->getRTTI();
}

spine_slider spine_slider_copy(spine_slider self, spine_skeleton skeleton) {
    return (spine_slider)((Slider*)self)->copy(*((Skeleton*)skeleton));
}

void spine_slider_update(spine_slider self, spine_skeleton skeleton, spine_physics physics) {
    ((Slider*)self)->update(*((Skeleton*)skeleton), (Physics)physics);
}

void spine_slider_sort(spine_slider self, spine_skeleton skeleton) {
    ((Slider*)self)->sort(*((Skeleton*)skeleton));
}

bool spine_slider_is_source_active(spine_slider self) {
    return ((Slider*)self)->isSourceActive();
}

spine_bone spine_slider_get_bone(spine_slider self) {
    return (spine_bone)((Slider*)self)->getBone();
}

void spine_slider_set_bone(spine_slider self, spine_bone bone) {
    ((Slider*)self)->setBone((Bone *)bone);
}

spine_constraint_data spine_slider_get_data(spine_slider self) {
    return (spine_constraint_data)&((ConstraintGeneric<Slider, SliderData, SliderPose>*)(Slider*)self)->getData();
}

spine_slider_pose spine_slider_get_pose(spine_slider self) {
    return (spine_slider_pose)&((ConstraintGeneric<Slider, SliderData, SliderPose>*)(Slider*)self)->getPose();
}

spine_slider_pose spine_slider_get_applied_pose(spine_slider self) {
    return (spine_slider_pose)&((ConstraintGeneric<Slider, SliderData, SliderPose>*)(Slider*)self)->getAppliedPose();
}

void spine_slider_reset_constrained(spine_slider self) {
    ((ConstraintGeneric<Slider, SliderData, SliderPose>*)(Slider*)self)->resetConstrained();
}

void spine_slider_constrained(spine_slider self) {
    ((ConstraintGeneric<Slider, SliderData, SliderPose>*)(Slider*)self)->constrained();
}

bool spine_slider_is_pose_equal_to_applied(spine_slider self) {
    return ((ConstraintGeneric<Slider, SliderData, SliderPose>*)(Slider*)self)->isPoseEqualToApplied();
}

bool spine_slider_is_active(spine_slider self) {
    return ((ConstraintGeneric<Slider, SliderData, SliderPose>*)(Slider*)self)->isActive();
}

void spine_slider_set_active(spine_slider self, bool active) {
    ((ConstraintGeneric<Slider, SliderData, SliderPose>*)(Slider*)self)->setActive(active);
}

spine_rtti spine_slider_rtti(void) {
    return (spine_rtti)&Slider::rtti;
}
