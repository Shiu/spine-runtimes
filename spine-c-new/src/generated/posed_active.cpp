#include "posed_active.h"
#include <spine/spine.h>

using namespace spine;

void spine_posed_active_dispose(spine_posed_active self) {
    delete (PosedActive*)self;
}

bool spine_posed_active_is_active(spine_posed_active self) {
    return ((PosedActive*)self)->isActive();
}

void spine_posed_active_set_active(spine_posed_active self, bool active) {
    ((PosedActive*)self)->setActive(active);
}
