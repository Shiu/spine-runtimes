#include "inherit_timeline.h"
#include <spine/spine.h>

using namespace spine;

spine_inherit_timeline spine_inherit_timeline_create(size_t frameCount, int boneIndex) {
    return (spine_inherit_timeline) new (__FILE__, __LINE__) InheritTimeline(frameCount, boneIndex);
}

void spine_inherit_timeline_dispose(spine_inherit_timeline self) {
    delete (InheritTimeline*)self;
}

spine_rtti spine_inherit_timeline_get_rtti(spine_inherit_timeline self) {
    return (spine_rtti)&((InheritTimeline*)self)->getRTTI();
}

void spine_inherit_timeline_set_frame(spine_inherit_timeline self, int frame, float time, spine_inherit inherit) {
    ((InheritTimeline*)self)->setFrame(frame, time, (Inherit)inherit);
}

void spine_inherit_timeline_apply(spine_inherit_timeline self, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    ((InheritTimeline*)self)->apply(*((Skeleton*)skeleton), lastTime, time, (Array<Event *> *)pEvents, alpha, (MixBlend)blend, (MixDirection)direction, appliedPose);
}

size_t spine_inherit_timeline_get_frame_entries(spine_inherit_timeline self) {
    return ((Timeline*)(InheritTimeline*)self)->getFrameEntries();
}

size_t spine_inherit_timeline_get_frame_count(spine_inherit_timeline self) {
    return ((Timeline*)(InheritTimeline*)self)->getFrameCount();
}

spine_array_float spine_inherit_timeline_get_frames(spine_inherit_timeline self) {
    return (spine_array_float)&((Timeline*)(InheritTimeline*)self)->getFrames();
}

float spine_inherit_timeline_get_duration(spine_inherit_timeline self) {
    return ((Timeline*)(InheritTimeline*)self)->getDuration();
}

spine_array_property_id spine_inherit_timeline_get_property_ids(spine_inherit_timeline self) {
    return (spine_array_property_id)&((Timeline*)(InheritTimeline*)self)->getPropertyIds();
}

int spine_inherit_timeline_get_bone_index(spine_inherit_timeline self) {
    return ((BoneTimeline*)(InheritTimeline*)self)->getBoneIndex();
}

void spine_inherit_timeline_set_bone_index(spine_inherit_timeline self, int inValue) {
    ((BoneTimeline*)(InheritTimeline*)self)->setBoneIndex(inValue);
}

spine_rtti spine_inherit_timeline_rtti(void) {
    return (spine_rtti)&InheritTimeline::rtti;
}
