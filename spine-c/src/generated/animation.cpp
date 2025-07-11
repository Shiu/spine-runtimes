#include "animation.h"
#include <spine/spine.h>

using namespace spine;

spine_animation spine_animation_create(const char* name, spine_array_timeline timelines, float duration) {
    return (spine_animation) new (__FILE__, __LINE__) Animation(String(name), *((Array<Timeline *>*)timelines), duration);
}

void spine_animation_dispose(spine_animation self) {
    delete (Animation*)self;
}

spine_array_timeline spine_animation_get_timelines(spine_animation self) {
    return (spine_array_timeline)&((Animation*)self)->getTimelines();
}

void spine_animation_set_timelines(spine_animation self, spine_array_timeline timelines) {
    ((Animation*)self)->setTimelines(*((Array<Timeline *>*)timelines));
}

bool spine_animation_has_timeline(spine_animation self, spine_array_property_id ids) {
    return ((Animation*)self)->hasTimeline(*((Array<PropertyId>*)ids));
}

float spine_animation_get_duration(spine_animation self) {
    return ((Animation*)self)->getDuration();
}

void spine_animation_set_duration(spine_animation self, float inValue) {
    ((Animation*)self)->setDuration(inValue);
}

void spine_animation_apply(spine_animation self, spine_skeleton skeleton, float lastTime, float time, bool loop, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    ((Animation*)self)->apply(*((Skeleton*)skeleton), lastTime, time, loop, (Array<Event *> *)pEvents, alpha, (MixBlend)blend, (MixDirection)direction, appliedPose);
}

const char* spine_animation_get_name(spine_animation self) {
    return ((Animation*)self)->getName().buffer();
}

spine_array_int spine_animation_get_bones(spine_animation self) {
    return (spine_array_int)&((Animation*)self)->getBones();
}

int spine_animation_search_1(spine_array_float values, float target) {
    return Animation::search(*((Array<float>*)values), target);
}

int spine_animation_search_2(spine_array_float values, float target, int step) {
    return Animation::search(*((Array<float>*)values), target, step);
}
