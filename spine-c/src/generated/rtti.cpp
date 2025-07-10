#include "rtti.h"
#include <spine/spine.h>

using namespace spine;

void spine_rtti_dispose(spine_rtti self) {
    delete (RTTI*)self;
}

const char * spine_rtti_get_class_name(spine_rtti self) {
    return ((RTTI*)self)->getClassName();
}

bool spine_rtti_is_exactly(spine_rtti self, spine_rtti rtti) {
    return ((RTTI*)self)->isExactly(*((const RTTI*)rtti));
}

bool spine_rtti_instance_of(spine_rtti self, spine_rtti rtti) {
    return ((RTTI*)self)->instanceOf(*((const RTTI*)rtti));
}
