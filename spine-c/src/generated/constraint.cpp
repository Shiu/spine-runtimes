#include "constraint.h"
#include <spine/spine.h>

using namespace spine;

void spine_constraint_dispose(spine_constraint self) {
    delete (Constraint*)self;
}

spine_rtti spine_constraint_get_rtti(spine_constraint self) {
    return (spine_rtti)&((Constraint*)self)->getRTTI();
}

spine_constraint_data spine_constraint_get_data(spine_constraint self) {
    return (spine_constraint_data)&((Constraint*)self)->getData();
}

void spine_constraint_sort(spine_constraint self, spine_skeleton skeleton) {
    ((Constraint*)self)->sort(*((Skeleton*)skeleton));
}

bool spine_constraint_is_source_active(spine_constraint self) {
    return ((Constraint*)self)->isSourceActive();
}

void spine_constraint_update(spine_constraint self, spine_skeleton skeleton, spine_physics physics) {
    ((Constraint*)self)->update(*((Skeleton*)skeleton), (Physics)physics);
}

spine_rtti spine_constraint_rtti(void) {
    return (spine_rtti)&Constraint::rtti;
}
