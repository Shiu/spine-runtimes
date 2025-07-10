#include "sequence.h"
#include <spine/spine.h>

using namespace spine;

spine_sequence spine_sequence_create(int count) {
    return (spine_sequence) new (__FILE__, __LINE__) Sequence(count);
}

void spine_sequence_dispose(spine_sequence self) {
    delete (Sequence*)self;
}

spine_sequence spine_sequence_copy(spine_sequence self) {
    return (spine_sequence)((Sequence*)self)->copy();
}

void spine_sequence_apply(spine_sequence self, spine_slot_pose slot, spine_attachment attachment) {
    ((Sequence*)self)->apply((SlotPose *)slot, (Attachment *)attachment);
}

const char* spine_sequence_get_path(spine_sequence self, const char* basePath, int index) {
    return ((Sequence*)self)->getPath(*((const String*)basePath), index).buffer();
}

int spine_sequence_get_id(spine_sequence self) {
    return ((Sequence*)self)->getId();
}

void spine_sequence_set_id(spine_sequence self, int id) {
    ((Sequence*)self)->setId(id);
}

int spine_sequence_get_start(spine_sequence self) {
    return ((Sequence*)self)->getStart();
}

void spine_sequence_set_start(spine_sequence self, int start) {
    ((Sequence*)self)->setStart(start);
}

int spine_sequence_get_digits(spine_sequence self) {
    return ((Sequence*)self)->getDigits();
}

void spine_sequence_set_digits(spine_sequence self, int digits) {
    ((Sequence*)self)->setDigits(digits);
}

int spine_sequence_get_setup_index(spine_sequence self) {
    return ((Sequence*)self)->getSetupIndex();
}

void spine_sequence_set_setup_index(spine_sequence self, int setupIndex) {
    ((Sequence*)self)->setSetupIndex(setupIndex);
}

spine_array_texture_region spine_sequence_get_regions(spine_sequence self) {
    return (spine_array_texture_region)&((Sequence*)self)->getRegions();
}
