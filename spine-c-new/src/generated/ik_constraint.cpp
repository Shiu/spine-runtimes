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

#include "ik_constraint.h"
#include <spine/spine.h>

using namespace spine;

spine_ik_constraint spine_ik_constraint_create(spine_ik_constraint_data data, spine_skeleton skeleton) {
    IkConstraint *obj = new (__FILE__, __LINE__) IkConstraint(*(IkConstraintData*) data, *(Skeleton*) skeleton);
    return (spine_ik_constraint) obj;
}

void spine_ik_constraint_dispose(spine_ik_constraint obj) {
    if (!obj) return;
    delete (IkConstraint *) obj;
}

spine_rtti spine_ik_constraint_get_rtti() {
    return (spine_rtti) &IkConstraint::rtti;
}

spine_ik_constraint spine_ik_constraint_copy(spine_ik_constraint obj, spine_skeleton skeleton) {
    if (!obj) return 0;
    IkConstraint *_obj = (IkConstraint *) obj;
    return (spine_ik_constraint) _obj->copy(*(Skeleton*) skeleton);
}

void spine_ik_constraint_update(spine_ik_constraint obj, spine_skeleton skeleton, spine_physics physics) {
    if (!obj) return ;
    IkConstraint *_obj = (IkConstraint *) obj;
    _obj->update(*(Skeleton*) skeleton, (Physics) physics);
}

void spine_ik_constraint_sort(spine_ik_constraint obj, spine_skeleton skeleton) {
    if (!obj) return ;
    IkConstraint *_obj = (IkConstraint *) obj;
    _obj->sort(*(Skeleton*) skeleton);
}

bool spine_ik_constraint_is_source_active(spine_ik_constraint obj) {
    if (!obj) return false;
    IkConstraint *_obj = (IkConstraint *) obj;
    return _obj->isSourceActive();
}

spine_ik_constraint_data spine_ik_constraint_get_data(spine_ik_constraint obj) {
    if (!obj) return 0;
    IkConstraint *_obj = (IkConstraint *) obj;
    return (spine_ik_constraint_data) &_obj->getData();
}

int32_t spine_ik_constraint_get_num_bones(spine_ik_constraint obj) {
    if (!obj) return 0;
    IkConstraint *_obj = (IkConstraint *) obj;
    return (int32_t) _obj->getBones().size();
}

spine_bone_pose *spine_ik_constraint_get_bones(spine_ik_constraint obj) {
    if (!obj) return nullptr;
    IkConstraint *_obj = (IkConstraint *) obj;
    return (spine_bone_pose *) _obj->getBones().buffer();
}

spine_bone spine_ik_constraint_get_target(spine_ik_constraint obj) {
    if (!obj) return (spine_bone) 0;
    IkConstraint *_obj = (IkConstraint *) obj;
    return (spine_bone) _obj->getTarget();
}

void spine_ik_constraint_set_target(spine_ik_constraint obj, spine_bone value) {
    if (!obj) return;
    IkConstraint *_obj = (IkConstraint *) obj;
    _obj->setTarget((Bone *) value);
}

void spine_ik_constraint_pose(spine_ik_constraint obj) {
    if (!obj) return ;
    IkConstraint *_obj = (IkConstraint *) obj;
    _obj->pose();
}

void spine_ik_constraint_setup_pose(spine_ik_constraint obj) {
    if (!obj) return ;
    IkConstraint *_obj = (IkConstraint *) obj;
    _obj->setupPose();
}

spine_ik_constraint_pose spine_ik_constraint_get_pose(spine_ik_constraint obj) {
    if (!obj) return 0;
    IkConstraint *_obj = (IkConstraint *) obj;
    return (spine_ik_constraint_pose) &_obj->getPose();
}

spine_ik_constraint_pose spine_ik_constraint_get_applied_pose(spine_ik_constraint obj) {
    if (!obj) return 0;
    IkConstraint *_obj = (IkConstraint *) obj;
    return (spine_ik_constraint_pose) &_obj->getAppliedPose();
}

void spine_ik_constraint_reset_constrained(spine_ik_constraint obj) {
    if (!obj) return ;
    IkConstraint *_obj = (IkConstraint *) obj;
    _obj->resetConstrained();
}

void spine_ik_constraint_constrained(spine_ik_constraint obj) {
    if (!obj) return ;
    IkConstraint *_obj = (IkConstraint *) obj;
    _obj->constrained();
}

bool spine_ik_constraint_is_pose_equal_to_applied(spine_ik_constraint obj) {
    if (!obj) return false;
    IkConstraint *_obj = (IkConstraint *) obj;
    return _obj->isPoseEqualToApplied();
}

bool spine_ik_constraint_is_active(spine_ik_constraint obj) {
    if (!obj) return false;
    IkConstraint *_obj = (IkConstraint *) obj;
    return _obj->isActive();
}

void spine_ik_constraint_set_active(spine_ik_constraint obj, bool value) {
    if (!obj) return;
    IkConstraint *_obj = (IkConstraint *) obj;
    _obj->setActive(value);
}
