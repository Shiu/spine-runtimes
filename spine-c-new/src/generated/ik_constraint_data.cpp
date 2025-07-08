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

#include "ik_constraint_data.h"
#include <spine/spine.h>

using namespace spine;

spine_ik_constraint_data spine_ik_constraint_data_create(const char* name) {
    IkConstraintData *obj = new (__FILE__, __LINE__) IkConstraintData(String(name));
    return (spine_ik_constraint_data) obj;
}

void spine_ik_constraint_data_dispose(spine_ik_constraint_data obj) {
    if (!obj) return;
    delete (IkConstraintData *) obj;
}

spine_rtti spine_ik_constraint_data_get_rtti() {
    return (spine_rtti) &IkConstraintData::rtti;
}

spine_constraint spine_ik_constraint_data_create(spine_ik_constraint_data obj, spine_skeleton skeleton) {
    if (!obj) return 0;
    IkConstraintData *_obj = (IkConstraintData *) obj;
    return (spine_constraint) _obj->create(*(Skeleton*) skeleton);
}

int32_t spine_ik_constraint_data_get_num_bones(spine_ik_constraint_data obj) {
    if (!obj) return 0;
    IkConstraintData *_obj = (IkConstraintData *) obj;
    return (int32_t) _obj->getBones().size();
}

spine_bone_data *spine_ik_constraint_data_get_bones(spine_ik_constraint_data obj) {
    if (!obj) return nullptr;
    IkConstraintData *_obj = (IkConstraintData *) obj;
    return (spine_bone_data *) _obj->getBones().buffer();
}

spine_bone_data spine_ik_constraint_data_get_target(spine_ik_constraint_data obj) {
    if (!obj) return (spine_bone_data) 0;
    IkConstraintData *_obj = (IkConstraintData *) obj;
    return (spine_bone_data) _obj->getTarget();
}

void spine_ik_constraint_data_set_target(spine_ik_constraint_data obj, spine_bone_data value) {
    if (!obj) return;
    IkConstraintData *_obj = (IkConstraintData *) obj;
    _obj->setTarget((BoneData *) value);
}

bool spine_ik_constraint_data_get_uniform(spine_ik_constraint_data obj) {
    if (!obj) return false;
    IkConstraintData *_obj = (IkConstraintData *) obj;
    return _obj->getUniform();
}

void spine_ik_constraint_data_set_uniform(spine_ik_constraint_data obj, bool value) {
    if (!obj) return;
    IkConstraintData *_obj = (IkConstraintData *) obj;
    _obj->setUniform(value);
}

const char* spine_ik_constraint_data_get_name(spine_ik_constraint_data obj) {
    if (!obj) return nullptr;
    IkConstraintData *_obj = (IkConstraintData *) obj;
    return (const char *) _obj->getName().buffer();
}

bool spine_ik_constraint_data_is_skin_required(spine_ik_constraint_data obj) {
    if (!obj) return false;
    IkConstraintData *_obj = (IkConstraintData *) obj;
    return _obj->isSkinRequired();
}

spine_ik_constraint_pose spine_ik_constraint_data_get_setup_pose(spine_ik_constraint_data obj) {
    if (!obj) return 0;
    IkConstraintData *_obj = (IkConstraintData *) obj;
    return (spine_ik_constraint_pose) &_obj->getSetupPose();
}
