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

#include "path_constraint_data.h"
#include <spine/spine.h>

using namespace spine;

spine_path_constraint_data spine_path_constraint_data_create(const utf8 * name) {
    PathConstraintData *obj = new (__FILE__, __LINE__) PathConstraintData(String(name));
    return (spine_path_constraint_data) obj;
}

void spine_path_constraint_data_dispose(spine_path_constraint_data obj) {
    if (!obj) return;
    delete (PathConstraintData *) obj;
}

spine_rtti spine_path_constraint_data_get_rtti(spine_path_constraint_data obj) {
    if (!obj) return nullptr;
    PathConstraintData *_obj = (PathConstraintData *) obj;
    return (spine_rtti) &_obj->getRTTI();
}

spine_constraint spine_path_constraint_data_create(spine_path_constraint_data obj, spine_skeleton skeleton) {
    if (!obj) return 0;
    PathConstraintData *_obj = (PathConstraintData *) obj;
    return (spine_constraint) _obj->create(skeleton);
}

void * spine_path_constraint_data_get_bones(spine_path_constraint_data obj) {
    if (!obj) return nullptr;
    PathConstraintData *_obj = (PathConstraintData *) obj;
    return (void *) _obj->getBones();
}

int32_t spine_path_constraint_data_get_num_bones(spine_path_constraint_data obj) {
    if (!obj) return 0;
    PathConstraintData *_obj = (PathConstraintData *) obj;
    return (int32_t) _obj->getBones().size();
}

spine_bone_data *spine_path_constraint_data_get_bones(spine_path_constraint_data obj) {
    if (!obj) return nullptr;
    PathConstraintData *_obj = (PathConstraintData *) obj;
    return (spine_bone_data *) _obj->getBones().buffer();
}

spine_slot_data spine_path_constraint_data_get_slot(spine_path_constraint_data obj) {
    if (!obj) return nullptr;
    PathConstraintData *_obj = (PathConstraintData *) obj;
    return (spine_slot_data) _obj->getSlot();
}

void spine_path_constraint_data_set_slot(spine_path_constraint_data obj, spine_slot_data value) {
    if (!obj) return;
    PathConstraintData *_obj = (PathConstraintData *) obj;
    _obj->setSlot((SlotData *) value);
}

spine_position_mode spine_path_constraint_data_get_position_mode(spine_path_constraint_data obj) {
    if (!obj) return nullptr;
    PathConstraintData *_obj = (PathConstraintData *) obj;
    return _obj->getPositionMode();
}

void spine_path_constraint_data_set_position_mode(spine_path_constraint_data obj, spine_position_mode value) {
    if (!obj) return;
    PathConstraintData *_obj = (PathConstraintData *) obj;
    _obj->setPositionMode(value);
}

spine_spacing_mode spine_path_constraint_data_get_spacing_mode(spine_path_constraint_data obj) {
    if (!obj) return nullptr;
    PathConstraintData *_obj = (PathConstraintData *) obj;
    return _obj->getSpacingMode();
}

void spine_path_constraint_data_set_spacing_mode(spine_path_constraint_data obj, spine_spacing_mode value) {
    if (!obj) return;
    PathConstraintData *_obj = (PathConstraintData *) obj;
    _obj->setSpacingMode(value);
}

spine_rotate_mode spine_path_constraint_data_get_rotate_mode(spine_path_constraint_data obj) {
    if (!obj) return nullptr;
    PathConstraintData *_obj = (PathConstraintData *) obj;
    return _obj->getRotateMode();
}

void spine_path_constraint_data_set_rotate_mode(spine_path_constraint_data obj, spine_rotate_mode value) {
    if (!obj) return;
    PathConstraintData *_obj = (PathConstraintData *) obj;
    _obj->setRotateMode(value);
}

float spine_path_constraint_data_get_offset_rotation(spine_path_constraint_data obj) {
    if (!obj) return 0;
    PathConstraintData *_obj = (PathConstraintData *) obj;
    return _obj->getOffsetRotation();
}

void spine_path_constraint_data_set_offset_rotation(spine_path_constraint_data obj, float value) {
    if (!obj) return;
    PathConstraintData *_obj = (PathConstraintData *) obj;
    _obj->setOffsetRotation(value);
}

const utf8 * spine_path_constraint_data_get_name(spine_path_constraint_data obj) {
    if (!obj) return nullptr;
    PathConstraintData *_obj = (PathConstraintData *) obj;
    return (const utf8 *) _obj->getName().buffer();
}

spine_bool spine_path_constraint_data_is_skin_required(spine_path_constraint_data obj) {
    if (!obj) return 0;
    PathConstraintData *_obj = (PathConstraintData *) obj;
    return _obj->isSkinRequired();
}

spine_path_constraint_pose spine_path_constraint_data_get_setup_pose(spine_path_constraint_data obj) {
    if (!obj) return 0;
    PathConstraintData *_obj = (PathConstraintData *) obj;
    return _obj->getSetupPose();
}

spine_path_constraint_pose spine_path_constraint_data_get_setup_pose(spine_path_constraint_data obj) {
    if (!obj) return 0;
    PathConstraintData *_obj = (PathConstraintData *) obj;
    return _obj->getSetupPose();
}
