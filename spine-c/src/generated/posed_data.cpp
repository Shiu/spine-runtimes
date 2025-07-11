#include "posed_data.h"
#include <spine/spine.h>

using namespace spine;

spine_posed_data spine_posed_data_create(const char* name) {
    return (spine_posed_data) new (__FILE__, __LINE__) PosedData(String(name));
}

void spine_posed_data_dispose(spine_posed_data self) {
    delete (PosedData*)self;
}

const char* spine_posed_data_get_name(spine_posed_data self) {
    return (const char*)&((PosedData*)self)->getName();
}

bool spine_posed_data_is_skin_required(spine_posed_data self) {
    return ((PosedData*)self)->isSkinRequired();
}

void spine_posed_data_set_skin_required(spine_posed_data self, bool skinRequired) {
    ((PosedData*)self)->setSkinRequired(skinRequired);
}
