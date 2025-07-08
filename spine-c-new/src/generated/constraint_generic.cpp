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

#include "constraint_generic.h"
#include <spine/spine.h>

using namespace spine;

spine_constraint_generic spine_constraint_generic_create(spine_d data) {
    ConstraintGeneric *obj = new (__FILE__, __LINE__) ConstraintGeneric(data);
    return (spine_constraint_generic) obj;
}

void spine_constraint_generic_dispose(spine_constraint_generic obj) {
    if (!obj) return;
    delete (ConstraintGeneric *) obj;
}

spine_constraint_data spine_constraint_generic_get_data(spine_constraint_generic obj) {
    if (!obj) return 0;
    ConstraintGeneric *_obj = (ConstraintGeneric *) obj;
    return _obj->getData();
}

void spine_constraint_generic_pose(spine_constraint_generic obj) {
    if (!obj) return ;
    ConstraintGeneric *_obj = (ConstraintGeneric *) obj;
    _obj->pose();
}

void spine_constraint_generic_setup_pose(spine_constraint_generic obj) {
    if (!obj) return ;
    ConstraintGeneric *_obj = (ConstraintGeneric *) obj;
    _obj->setupPose();
}

spine_p spine_constraint_generic_get_pose(spine_constraint_generic obj) {
    if (!obj) return nullptr;
    ConstraintGeneric *_obj = (ConstraintGeneric *) obj;
    return _obj->getPose();
}

spine_p spine_constraint_generic_get_applied_pose(spine_constraint_generic obj) {
    if (!obj) return nullptr;
    ConstraintGeneric *_obj = (ConstraintGeneric *) obj;
    return _obj->getAppliedPose();
}

void spine_constraint_generic_reset_constrained(spine_constraint_generic obj) {
    if (!obj) return ;
    ConstraintGeneric *_obj = (ConstraintGeneric *) obj;
    _obj->resetConstrained();
}

void spine_constraint_generic_constrained(spine_constraint_generic obj) {
    if (!obj) return ;
    ConstraintGeneric *_obj = (ConstraintGeneric *) obj;
    _obj->constrained();
}

spine_bool spine_constraint_generic_is_pose_equal_to_applied(spine_constraint_generic obj) {
    if (!obj) return 0;
    ConstraintGeneric *_obj = (ConstraintGeneric *) obj;
    return _obj->isPoseEqualToApplied();
}

spine_bool spine_constraint_generic_is_active(spine_constraint_generic obj) {
    if (!obj) return 0;
    ConstraintGeneric *_obj = (ConstraintGeneric *) obj;
    return _obj->isActive();
}

void spine_constraint_generic_set_active(spine_constraint_generic obj, spine_bool value) {
    if (!obj) return;
    ConstraintGeneric *_obj = (ConstraintGeneric *) obj;
    _obj->setActive(value);
}

spine_rtti spine_constraint_generic_get_rtti(spine_constraint_generic obj) {
    if (!obj) return nullptr;
    ConstraintGeneric *_obj = (ConstraintGeneric *) obj;
    return (spine_rtti) &_obj->getRTTI();
}

void spine_constraint_generic_sort(spine_constraint_generic obj, spine_skeleton skeleton) {
    if (!obj) return ;
    ConstraintGeneric *_obj = (ConstraintGeneric *) obj;
    _obj->sort(skeleton);
}

spine_bool spine_constraint_generic_is_source_active(spine_constraint_generic obj) {
    if (!obj) return 0;
    ConstraintGeneric *_obj = (ConstraintGeneric *) obj;
    return _obj->isSourceActive();
}

void spine_constraint_generic_update(spine_constraint_generic obj, spine_skeleton skeleton, spine_physics physics) {
    if (!obj) return ;
    ConstraintGeneric *_obj = (ConstraintGeneric *) obj;
    _obj->update(skeleton, physics);
}
