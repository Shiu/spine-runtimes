#include "slot.h"
#include <spine/spine.h>

using namespace spine;

spine_slot spine_slot_create(spine_slot_data data, spine_skeleton skeleton) {
    return (spine_slot) new (__FILE__, __LINE__) Slot(*((SlotData*)data), *((Skeleton*)skeleton));
}

void spine_slot_dispose(spine_slot self) {
    delete (Slot*)self;
}

spine_bone spine_slot_get_bone(spine_slot self) {
    return (spine_bone)&((Slot*)self)->getBone();
}

void spine_slot_setup_pose(spine_slot self) {
    ((Slot*)self)->setupPose();
}

spine_slot_data spine_slot_get_data(spine_slot self) {
    return (spine_slot_data)&((PosedGeneric<SlotData, SlotPose, SlotPose>*)(Slot*)self)->getData();
}

spine_slot_pose spine_slot_get_pose(spine_slot self) {
    return (spine_slot_pose)&((PosedGeneric<SlotData, SlotPose, SlotPose>*)(Slot*)self)->getPose();
}

spine_slot_pose spine_slot_get_applied_pose(spine_slot self) {
    return (spine_slot_pose)&((PosedGeneric<SlotData, SlotPose, SlotPose>*)(Slot*)self)->getAppliedPose();
}

void spine_slot_reset_constrained(spine_slot self) {
    ((PosedGeneric<SlotData, SlotPose, SlotPose>*)(Slot*)self)->resetConstrained();
}

void spine_slot_constrained(spine_slot self) {
    ((PosedGeneric<SlotData, SlotPose, SlotPose>*)(Slot*)self)->constrained();
}

bool spine_slot_is_pose_equal_to_applied(spine_slot self) {
    return ((PosedGeneric<SlotData, SlotPose, SlotPose>*)(Slot*)self)->isPoseEqualToApplied();
}
