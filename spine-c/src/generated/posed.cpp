#include "posed.h"
#include <spine/spine.h>

using namespace spine;

void spine_posed_dispose(spine_posed self) {
    delete (Posed*)self;
}

void spine_posed_constrained(spine_posed self) {
    ((Posed*)self)->constrained();
}

void spine_posed_reset_constrained(spine_posed self) {
    ((Posed*)self)->resetConstrained();
}

bool spine_posed_is_pose_equal_to_applied(spine_posed self) {
    return ((Posed*)self)->isPoseEqualToApplied();
}
