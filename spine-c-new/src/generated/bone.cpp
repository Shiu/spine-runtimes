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

#include "bone.h"
#include <spine/spine.h>

using namespace spine;

spine_bone spine_bone_create(spine_bone_data data, spine_bone parent) {
    Bone *obj = new (__FILE__, __LINE__) Bone(*(BoneData*) data, (Bone *) parent);
    return (spine_bone) obj;
}

spine_bone spine_bone_create_with_bone_bone(spine_bone bone, spine_bone parent) {
    Bone *obj = new (__FILE__, __LINE__) Bone(*(Bone*) bone, (Bone *) parent);
    return (spine_bone) obj;
}

void spine_bone_dispose(spine_bone obj) {
    if (!obj) return;
    delete (Bone *) obj;
}

spine_rtti spine_bone_get_rtti() {
    return (spine_rtti) &Bone::rtti;
}

spine_bone spine_bone_get_parent(spine_bone obj) {
    if (!obj) return (spine_bone) 0;
    Bone *_obj = (Bone *) obj;
    return (spine_bone) _obj->getParent();
}

int32_t spine_bone_get_num_children(spine_bone obj) {
    if (!obj) return 0;
    Bone *_obj = (Bone *) obj;
    return (int32_t) _obj->getChildren().size();
}

spine_bone *spine_bone_get_children(spine_bone obj) {
    if (!obj) return nullptr;
    Bone *_obj = (Bone *) obj;
    return (spine_bone *) _obj->getChildren().buffer();
}

void spine_bone_setup_pose(spine_bone obj) {
    if (!obj) return ;
    Bone *_obj = (Bone *) obj;
    _obj->setupPose();
}

spine_bone_data spine_bone_get_data(spine_bone obj) {
    if (!obj) return (spine_bone_data) 0;
    Bone *_obj = (Bone *) obj;
    return (spine_bone_data) &_obj->getData();
}

spine_bone_local spine_bone_get_pose(spine_bone obj) {
    if (!obj) return (spine_bone_local) 0;
    Bone *_obj = (Bone *) obj;
    return (spine_bone_local) &_obj->getPose();
}

spine_bone_pose spine_bone_get_applied_pose(spine_bone obj) {
    if (!obj) return (spine_bone_pose) 0;
    Bone *_obj = (Bone *) obj;
    return (spine_bone_pose) &_obj->getAppliedPose();
}

void spine_bone_reset_constrained(spine_bone obj) {
    if (!obj) return ;
    Bone *_obj = (Bone *) obj;
    _obj->resetConstrained();
}

void spine_bone_update_pose(spine_bone obj) {
    if (!obj) return ;
    Bone *_obj = (Bone *) obj;
    _obj->pose();
}

void spine_bone_constrained(spine_bone obj) {
    if (!obj) return ;
    Bone *_obj = (Bone *) obj;
    _obj->constrained();
}

bool spine_bone_is_pose_equal_to_applied(spine_bone obj) {
    if (!obj) return false;
    Bone *_obj = (Bone *) obj;
    return _obj->isPoseEqualToApplied();
}

bool spine_bone_is_active(spine_bone obj) {
    if (!obj) return false;
    Bone *_obj = (Bone *) obj;
    return _obj->isActive();
}

void spine_bone_set_active(spine_bone obj, bool value) {
    if (!obj) return;
    Bone *_obj = (Bone *) obj;
    _obj->setActive(value);
}
