#include "bone_data.h"
#include <spine/spine.h>

using namespace spine;

spine_bone_data spine_bone_data_create(int index, const char* name, spine_bone_data parent) {
    return (spine_bone_data) new (__FILE__, __LINE__) BoneData(index, *((const String*)name), (BoneData *)parent);
}

void spine_bone_data_dispose(spine_bone_data self) {
    delete (BoneData*)self;
}

int spine_bone_data_get_index(spine_bone_data self) {
    return ((BoneData*)self)->getIndex();
}

spine_bone_data spine_bone_data_get_parent(spine_bone_data self) {
    return (spine_bone_data)((BoneData*)self)->getParent();
}

float spine_bone_data_get_length(spine_bone_data self) {
    return ((BoneData*)self)->getLength();
}

void spine_bone_data_set_length(spine_bone_data self, float inValue) {
    ((BoneData*)self)->setLength(inValue);
}

spine_color spine_bone_data_get_color(spine_bone_data self) {
    return (spine_color)&((BoneData*)self)->getColor();
}

const char* spine_bone_data_get_icon(spine_bone_data self) {
    return (const char*)&((BoneData*)self)->getIcon();
}

void spine_bone_data_set_icon(spine_bone_data self, const char* icon) {
    ((BoneData*)self)->setIcon(*((const String*)icon));
}

bool spine_bone_data_get_visible(spine_bone_data self) {
    return ((BoneData*)self)->getVisible();
}

void spine_bone_data_set_visible(spine_bone_data self, bool inValue) {
    ((BoneData*)self)->setVisible(inValue);
}

spine_bone_local spine_bone_data_get_setup_pose(spine_bone_data self) {
    return (spine_bone_local)&((PosedDataGeneric<BoneLocal>*)(BoneData*)self)->getSetupPose();
}

const char* spine_bone_data_get_name(spine_bone_data self) {
    return (const char*)&((PosedDataGeneric<BoneLocal>*)(BoneData*)self)->getName();
}

bool spine_bone_data_is_skin_required(spine_bone_data self) {
    return ((PosedDataGeneric<BoneLocal>*)(BoneData*)self)->isSkinRequired();
}

void spine_bone_data_set_skin_required(spine_bone_data self, bool skinRequired) {
    ((PosedDataGeneric<BoneLocal>*)(BoneData*)self)->setSkinRequired(skinRequired);
}
