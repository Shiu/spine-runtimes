/******************************************************************************
 * Spine Runtimes License Agreement
 * Last updated April 5, 2025. Replaces all prior versions.
 *
 * Copyright (c) 2013-2025, Esoteric Software LLC
 *
 * Integration of the Spine Runtimes into software or otherwise creating
 * derivative works of the Spine Runtimes is permitted under the terms and
 * conditions of Section 2 of the Spine Editor License Agreement:
 * http://esotericsoftware.com/spine-editor-license
 *
 * Otherwise, it is permitted to integrate the Spine Runtimes into software
 * or otherwise create derivative works of the Spine Runtimes (collectively,
 * "Products"), provided that each user of the Products must obtain their own
 * Spine Editor license and redistribution of the Products in any form must
 * include this license and copyright notice.
 *
 * THE SPINE RUNTIMES ARE PROVIDED BY ESOTERIC SOFTWARE LLC "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ESOTERIC SOFTWARE LLC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES,
 * BUSINESS INTERRUPTION, OR LOSS OF USE, DATA, OR PROFITS) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THE SPINE RUNTIMES, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#include "slot.h"
#include <spine/spine.h>

using namespace spine;

spine_slot spine_slot_create(spine_slot_data data, spine_skeleton skeleton) {
    Slot *obj = new (__FILE__, __LINE__) Slot(data, skeleton);
    return (spine_slot) obj;
}

void spine_slot_dispose(spine_slot obj) {
    if (!obj) return;
    delete (Slot *) obj;
}

spine_bone spine_slot_get_bone(spine_slot obj) {
    if (!obj) return nullptr;
    Slot *_obj = (Slot *) obj;
    return _obj->getBone();
}

void spine_slot_setup_pose(spine_slot obj) {
    if (!obj) return ;
    Slot *_obj = (Slot *) obj;
    _obj->setupPose();
}

spine_slot_data spine_slot_get_data(spine_slot obj) {
    if (!obj) return nullptr;
    Slot *_obj = (Slot *) obj;
    return _obj->getData();
}

spine_slot_pose spine_slot_get_pose(spine_slot obj) {
    if (!obj) return nullptr;
    Slot *_obj = (Slot *) obj;
    return _obj->getPose();
}

spine_slot_pose spine_slot_get_applied_pose(spine_slot obj) {
    if (!obj) return nullptr;
    Slot *_obj = (Slot *) obj;
    return _obj->getAppliedPose();
}

void spine_slot_reset_constrained(spine_slot obj) {
    if (!obj) return ;
    Slot *_obj = (Slot *) obj;
    _obj->resetConstrained();
}

void spine_slot_pose(spine_slot obj) {
    if (!obj) return ;
    Slot *_obj = (Slot *) obj;
    _obj->pose();
}

void spine_slot_constrained(spine_slot obj) {
    if (!obj) return ;
    Slot *_obj = (Slot *) obj;
    _obj->constrained();
}

spine_bool spine_slot_is_pose_equal_to_applied(spine_slot obj) {
    if (!obj) return 0;
    Slot *_obj = (Slot *) obj;
    return _obj->isPoseEqualToApplied();
}
