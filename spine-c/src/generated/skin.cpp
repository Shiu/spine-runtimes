#include "skin.h"
#include <spine/spine.h>

using namespace spine;

spine_skin spine_skin_create(const char* name) {
    return (spine_skin) new (__FILE__, __LINE__) Skin(String(name));
}

void spine_skin_dispose(spine_skin self) {
    delete (Skin*)self;
}

void spine_skin_set_attachment(spine_skin self, size_t slotIndex, const char* name, spine_attachment attachment) {
    ((Skin*)self)->setAttachment(slotIndex, String(name), (Attachment *)attachment);
}

spine_attachment spine_skin_get_attachment(spine_skin self, size_t slotIndex, const char* name) {
    return (spine_attachment)((Skin*)self)->getAttachment(slotIndex, String(name));
}

void spine_skin_remove_attachment(spine_skin self, size_t slotIndex, const char* name) {
    ((Skin*)self)->removeAttachment(slotIndex, String(name));
}

void spine_skin_find_attachments_for_slot(spine_skin self, size_t slotIndex, spine_array_attachment attachments) {
    ((Skin*)self)->findAttachmentsForSlot(slotIndex, *((Array<Attachment *>*)attachments));
}

const char* spine_skin_get_name(spine_skin self) {
    return ((Skin*)self)->getName().buffer();
}

void spine_skin_add_skin(spine_skin self, spine_skin other) {
    ((Skin*)self)->addSkin((Skin *)other);
}

void spine_skin_copy_skin(spine_skin self, spine_skin other) {
    ((Skin*)self)->copySkin((Skin *)other);
}

spine_array_bone_data spine_skin_get_bones(spine_skin self) {
    return (spine_array_bone_data)&((Skin*)self)->getBones();
}

spine_array_constraint_data spine_skin_get_constraints(spine_skin self) {
    return (spine_array_constraint_data)&((Skin*)self)->getConstraints();
}

spine_color spine_skin_get_color(spine_skin self) {
    return (spine_color)&((Skin*)self)->getColor();
}
