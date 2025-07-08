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

#include "transform_constraint_data.h"
#include <spine/spine.h>

using namespace spine;

spine_transform_constraint_data spine_transform_constraint_data_create(const utf8 * name) {
    TransformConstraintData *obj = new (__FILE__, __LINE__) TransformConstraintData(String(name));
    return (spine_transform_constraint_data) obj;
}

void spine_transform_constraint_data_dispose(spine_transform_constraint_data obj) {
    if (!obj) return;
    delete (TransformConstraintData *) obj;
}

spine_rtti spine_transform_constraint_data_get_rtti(spine_transform_constraint_data obj) {
    if (!obj) return nullptr;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    return (spine_rtti) &_obj->getRTTI();
}

spine_constraint spine_transform_constraint_data_create(spine_transform_constraint_data obj, spine_skeleton skeleton) {
    if (!obj) return 0;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    return (spine_constraint) _obj->create(skeleton);
}

void * spine_transform_constraint_data_get_bones(spine_transform_constraint_data obj) {
    if (!obj) return nullptr;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    return (void *) _obj->getBones();
}

int32_t spine_transform_constraint_data_get_num_bones(spine_transform_constraint_data obj) {
    if (!obj) return 0;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    return (int32_t) _obj->getBones().size();
}

spine_bone_data *spine_transform_constraint_data_get_bones(spine_transform_constraint_data obj) {
    if (!obj) return nullptr;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    return (spine_bone_data *) _obj->getBones().buffer();
}

spine_bone_data spine_transform_constraint_data_get_source(spine_transform_constraint_data obj) {
    if (!obj) return nullptr;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    return (spine_bone_data) _obj->getSource();
}

void spine_transform_constraint_data_set_source(spine_transform_constraint_data obj, spine_bone_data value) {
    if (!obj) return;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    _obj->setSource((BoneData *) value);
}

float spine_transform_constraint_data_get_offset_rotation(spine_transform_constraint_data obj) {
    if (!obj) return 0;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    return _obj->getOffsetRotation();
}

void spine_transform_constraint_data_set_offset_rotation(spine_transform_constraint_data obj, float value) {
    if (!obj) return;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    _obj->setOffsetRotation(value);
}

float spine_transform_constraint_data_get_offset_x(spine_transform_constraint_data obj) {
    if (!obj) return 0;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    return _obj->getOffsetX();
}

void spine_transform_constraint_data_set_offset_x(spine_transform_constraint_data obj, float value) {
    if (!obj) return;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    _obj->setOffsetX(value);
}

float spine_transform_constraint_data_get_offset_y(spine_transform_constraint_data obj) {
    if (!obj) return 0;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    return _obj->getOffsetY();
}

void spine_transform_constraint_data_set_offset_y(spine_transform_constraint_data obj, float value) {
    if (!obj) return;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    _obj->setOffsetY(value);
}

float spine_transform_constraint_data_get_offset_scale_x(spine_transform_constraint_data obj) {
    if (!obj) return 0;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    return _obj->getOffsetScaleX();
}

void spine_transform_constraint_data_set_offset_scale_x(spine_transform_constraint_data obj, float value) {
    if (!obj) return;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    _obj->setOffsetScaleX(value);
}

float spine_transform_constraint_data_get_offset_scale_y(spine_transform_constraint_data obj) {
    if (!obj) return 0;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    return _obj->getOffsetScaleY();
}

void spine_transform_constraint_data_set_offset_scale_y(spine_transform_constraint_data obj, float value) {
    if (!obj) return;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    _obj->setOffsetScaleY(value);
}

float spine_transform_constraint_data_get_offset_shear_y(spine_transform_constraint_data obj) {
    if (!obj) return 0;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    return _obj->getOffsetShearY();
}

void spine_transform_constraint_data_set_offset_shear_y(spine_transform_constraint_data obj, float value) {
    if (!obj) return;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    _obj->setOffsetShearY(value);
}

spine_bool spine_transform_constraint_data_get_local_source(spine_transform_constraint_data obj) {
    if (!obj) return 0;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    return _obj->getLocalSource();
}

void spine_transform_constraint_data_set_local_source(spine_transform_constraint_data obj, spine_bool value) {
    if (!obj) return;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    _obj->setLocalSource(value);
}

spine_bool spine_transform_constraint_data_get_local_target(spine_transform_constraint_data obj) {
    if (!obj) return 0;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    return _obj->getLocalTarget();
}

void spine_transform_constraint_data_set_local_target(spine_transform_constraint_data obj, spine_bool value) {
    if (!obj) return;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    _obj->setLocalTarget(value);
}

spine_bool spine_transform_constraint_data_get_additive(spine_transform_constraint_data obj) {
    if (!obj) return 0;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    return _obj->getAdditive();
}

void spine_transform_constraint_data_set_additive(spine_transform_constraint_data obj, spine_bool value) {
    if (!obj) return;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    _obj->setAdditive(value);
}

spine_bool spine_transform_constraint_data_get_clamp(spine_transform_constraint_data obj) {
    if (!obj) return 0;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    return _obj->getClamp();
}

void spine_transform_constraint_data_set_clamp(spine_transform_constraint_data obj, spine_bool value) {
    if (!obj) return;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    _obj->setClamp(value);
}

void * spine_transform_constraint_data_get_properties(spine_transform_constraint_data obj) {
    if (!obj) return nullptr;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    return (void *) _obj->getProperties();
}

int32_t spine_transform_constraint_data_get_num_properties(spine_transform_constraint_data obj) {
    if (!obj) return 0;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    return (int32_t) _obj->getProperties().size();
}

spine_class from_property *spine_transform_constraint_data_get_properties(spine_transform_constraint_data obj) {
    if (!obj) return nullptr;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    return (spine_class from_property *) _obj->getProperties().buffer();
}

const utf8 * spine_transform_constraint_data_get_name(spine_transform_constraint_data obj) {
    if (!obj) return nullptr;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    return (const utf8 *) _obj->getName().buffer();
}

spine_bool spine_transform_constraint_data_is_skin_required(spine_transform_constraint_data obj) {
    if (!obj) return 0;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    return _obj->isSkinRequired();
}

spine_transform_constraint_pose spine_transform_constraint_data_get_setup_pose(spine_transform_constraint_data obj) {
    if (!obj) return 0;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    return _obj->getSetupPose();
}

spine_transform_constraint_pose spine_transform_constraint_data_get_setup_pose(spine_transform_constraint_data obj) {
    if (!obj) return 0;
    TransformConstraintData *_obj = (TransformConstraintData *) obj;
    return _obj->getSetupPose();
}
