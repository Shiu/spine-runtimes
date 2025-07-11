#include "slot_data.h"
#include <spine/spine.h>

using namespace spine;

spine_slot_data spine_slot_data_create(int index, const char* name, spine_bone_data boneData) {
    return (spine_slot_data) new (__FILE__, __LINE__) SlotData(index, String(name), *((BoneData*)boneData));
}

void spine_slot_data_dispose(spine_slot_data self) {
    delete (SlotData*)self;
}

int spine_slot_data_get_index(spine_slot_data self) {
    return ((SlotData*)self)->getIndex();
}

spine_bone_data spine_slot_data_get_bone_data(spine_slot_data self) {
    return (spine_bone_data)&((SlotData*)self)->getBoneData();
}

void spine_slot_data_set_attachment_name(spine_slot_data self, const char* attachmentName) {
    ((SlotData*)self)->setAttachmentName(String(attachmentName));
}

const char* spine_slot_data_get_attachment_name(spine_slot_data self) {
    return (const char*)&((SlotData*)self)->getAttachmentName();
}

spine_blend_mode spine_slot_data_get_blend_mode(spine_slot_data self) {
    return (spine_blend_mode)((SlotData*)self)->getBlendMode();
}

void spine_slot_data_set_blend_mode(spine_slot_data self, spine_blend_mode blendMode) {
    ((SlotData*)self)->setBlendMode((BlendMode)blendMode);
}

bool spine_slot_data_get_visible(spine_slot_data self) {
    return ((SlotData*)self)->getVisible();
}

void spine_slot_data_set_visible(spine_slot_data self, bool visible) {
    ((SlotData*)self)->setVisible(visible);
}

spine_slot_pose spine_slot_data_get_setup_pose(spine_slot_data self) {
    return (spine_slot_pose)&((PosedDataGeneric<SlotPose>*)(SlotData*)self)->getSetupPose();
}

const char* spine_slot_data_get_name(spine_slot_data self) {
    return (const char*)&((PosedDataGeneric<SlotPose>*)(SlotData*)self)->getName();
}

bool spine_slot_data_is_skin_required(spine_slot_data self) {
    return ((PosedDataGeneric<SlotPose>*)(SlotData*)self)->isSkinRequired();
}

void spine_slot_data_set_skin_required(spine_slot_data self, bool skinRequired) {
    ((PosedDataGeneric<SlotPose>*)(SlotData*)self)->setSkinRequired(skinRequired);
}
