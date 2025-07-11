#include "attachment.h"
#include <spine/spine.h>

using namespace spine;

void spine_attachment_dispose(spine_attachment self) {
    delete (Attachment*)self;
}

spine_rtti spine_attachment_get_rtti(spine_attachment self) {
    return (spine_rtti)&((Attachment*)self)->getRTTI();
}

const char* spine_attachment_get_name(spine_attachment self) {
    return ((Attachment*)self)->getName().buffer();
}

spine_attachment spine_attachment_copy(spine_attachment self) {
    return (spine_attachment)((Attachment*)self)->copy();
}

int spine_attachment_get_ref_count(spine_attachment self) {
    return ((Attachment*)self)->getRefCount();
}

void spine_attachment_reference(spine_attachment self) {
    ((Attachment*)self)->reference();
}

void spine_attachment_dereference(spine_attachment self) {
    ((Attachment*)self)->dereference();
}

spine_rtti spine_attachment_rtti(void) {
    return (spine_rtti)&Attachment::rtti;
}
