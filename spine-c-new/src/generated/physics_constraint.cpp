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

#include "physics_constraint.h"
#include <spine/spine.h>

using namespace spine;

spine_physics_constraint spine_physics_constraint_create(spine_physics_constraint_data data, spine_skeleton skeleton) {
    PhysicsConstraint *obj = new (__FILE__, __LINE__) PhysicsConstraint(*(PhysicsConstraintData*) data, *(Skeleton*) skeleton);
    return (spine_physics_constraint) obj;
}

void spine_physics_constraint_dispose(spine_physics_constraint obj) {
    if (!obj) return;
    delete (PhysicsConstraint *) obj;
}

spine_rtti spine_physics_constraint_get_rtti() {
    return (spine_rtti) &PhysicsConstraint::rtti;
}

void spine_physics_constraint_update(spine_physics_constraint obj, spine_skeleton skeleton, spine_physics physics) {
    if (!obj) return ;
    PhysicsConstraint *_obj = (PhysicsConstraint *) obj;
    _obj->update(*(Skeleton*) skeleton, (Physics) physics);
}

void spine_physics_constraint_sort(spine_physics_constraint obj, spine_skeleton skeleton) {
    if (!obj) return ;
    PhysicsConstraint *_obj = (PhysicsConstraint *) obj;
    _obj->sort(*(Skeleton*) skeleton);
}

bool spine_physics_constraint_is_source_active(spine_physics_constraint obj) {
    if (!obj) return false;
    PhysicsConstraint *_obj = (PhysicsConstraint *) obj;
    return _obj->isSourceActive();
}

spine_physics_constraint spine_physics_constraint_copy(spine_physics_constraint obj, spine_skeleton skeleton) {
    if (!obj) return 0;
    PhysicsConstraint *_obj = (PhysicsConstraint *) obj;
    return (spine_physics_constraint) _obj->copy(*(Skeleton*) skeleton);
}

void spine_physics_constraint_reset(spine_physics_constraint obj, spine_skeleton skeleton) {
    if (!obj) return ;
    PhysicsConstraint *_obj = (PhysicsConstraint *) obj;
    _obj->reset(*(Skeleton*) skeleton);
}

void spine_physics_constraint_translate(spine_physics_constraint obj, float x, float y) {
    if (!obj) return ;
    PhysicsConstraint *_obj = (PhysicsConstraint *) obj;
    _obj->translate(x, y);
}

void spine_physics_constraint_rotate(spine_physics_constraint obj, float x, float y, float degrees) {
    if (!obj) return ;
    PhysicsConstraint *_obj = (PhysicsConstraint *) obj;
    _obj->rotate(x, y, degrees);
}

spine_bone_pose spine_physics_constraint_get_bone(spine_physics_constraint obj) {
    if (!obj) return (spine_bone_pose) 0;
    PhysicsConstraint *_obj = (PhysicsConstraint *) obj;
    return (spine_bone_pose) &_obj->getBone();
}

void spine_physics_constraint_set_bone(spine_physics_constraint obj, spine_bone_pose value) {
    if (!obj) return;
    PhysicsConstraint *_obj = (PhysicsConstraint *) obj;
    _obj->setBone(*((BonePose*) value));
}

spine_constraint_data spine_physics_constraint_get_data(spine_physics_constraint obj) {
    if (!obj) return 0;
    PhysicsConstraint *_obj = (PhysicsConstraint *) obj;
    return (spine_constraint_data) &_obj->getData();
}

void spine_physics_constraint_pose(spine_physics_constraint obj) {
    if (!obj) return ;
    PhysicsConstraint *_obj = (PhysicsConstraint *) obj;
    _obj->pose();
}

void spine_physics_constraint_setup_pose(spine_physics_constraint obj) {
    if (!obj) return ;
    PhysicsConstraint *_obj = (PhysicsConstraint *) obj;
    _obj->setupPose();
}

spine_physics_constraint_pose spine_physics_constraint_get_pose(spine_physics_constraint obj) {
    if (!obj) return 0;
    PhysicsConstraint *_obj = (PhysicsConstraint *) obj;
    return (spine_physics_constraint_pose) &_obj->getPose();
}

spine_physics_constraint_pose spine_physics_constraint_get_applied_pose(spine_physics_constraint obj) {
    if (!obj) return 0;
    PhysicsConstraint *_obj = (PhysicsConstraint *) obj;
    return (spine_physics_constraint_pose) &_obj->getAppliedPose();
}

void spine_physics_constraint_reset_constrained(spine_physics_constraint obj) {
    if (!obj) return ;
    PhysicsConstraint *_obj = (PhysicsConstraint *) obj;
    _obj->resetConstrained();
}

void spine_physics_constraint_constrained(spine_physics_constraint obj) {
    if (!obj) return ;
    PhysicsConstraint *_obj = (PhysicsConstraint *) obj;
    _obj->constrained();
}

bool spine_physics_constraint_is_pose_equal_to_applied(spine_physics_constraint obj) {
    if (!obj) return false;
    PhysicsConstraint *_obj = (PhysicsConstraint *) obj;
    return _obj->isPoseEqualToApplied();
}

bool spine_physics_constraint_is_active(spine_physics_constraint obj) {
    if (!obj) return false;
    PhysicsConstraint *_obj = (PhysicsConstraint *) obj;
    return _obj->isActive();
}

void spine_physics_constraint_set_active(spine_physics_constraint obj, bool value) {
    if (!obj) return;
    PhysicsConstraint *_obj = (PhysicsConstraint *) obj;
    _obj->setActive(value);
}
