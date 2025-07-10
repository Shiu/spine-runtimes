#include "slot_pose.h"
#include <spine/spine.h>

using namespace spine;

spine_slot_pose spine_slot_pose_create(void) {
    return (spine_slot_pose) new (__FILE__, __LINE__) SlotPose();
}

void spine_slot_pose_dispose(spine_slot_pose self) {
    delete (SlotPose*)self;
}

void spine_slot_pose_set(spine_slot_pose self, spine_slot_pose pose) {
    ((SlotPose*)self)->set(*((SlotPose*)pose));
}

spine_color spine_slot_pose_get_color(spine_slot_pose self) {
    return (spine_color)&((SlotPose*)self)->getColor();
}

spine_color spine_slot_pose_get_dark_color(spine_slot_pose self) {
    return (spine_color)&((SlotPose*)self)->getDarkColor();
}

bool spine_slot_pose_has_dark_color(spine_slot_pose self) {
    return ((SlotPose*)self)->hasDarkColor();
}

void spine_slot_pose_set_has_dark_color(spine_slot_pose self, bool hasDarkColor) {
    ((SlotPose*)self)->setHasDarkColor(hasDarkColor);
}

spine_attachment spine_slot_pose_get_attachment(spine_slot_pose self) {
    return (spine_attachment)((SlotPose*)self)->getAttachment();
}

void spine_slot_pose_set_attachment(spine_slot_pose self, spine_attachment attachment) {
    ((SlotPose*)self)->setAttachment((Attachment *)attachment);
}

int spine_slot_pose_get_sequence_index(spine_slot_pose self) {
    return ((SlotPose*)self)->getSequenceIndex();
}

void spine_slot_pose_set_sequence_index(spine_slot_pose self, int sequenceIndex) {
    ((SlotPose*)self)->setSequenceIndex(sequenceIndex);
}

spine_array_float spine_slot_pose_get_deform(spine_slot_pose self) {
    return (spine_array_float)&((SlotPose*)self)->getDeform();
}
