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

#include "skeleton_data.h"
#include <spine/spine.h>

using namespace spine;

spine_skeleton_data spine_skeleton_data_create(void) {
    SkeletonData *obj = new (__FILE__, __LINE__) SkeletonData();
    return (spine_skeleton_data) obj;
}

void spine_skeleton_data_dispose(spine_skeleton_data obj) {
    if (!obj) return;
    delete (SkeletonData *) obj;
}

spine_bone_data spine_skeleton_data_find_bone(spine_skeleton_data obj, const char* boneName) {
    if (!obj) return (spine_bone_data) 0;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (spine_bone_data) _obj->findBone(String(boneName));
}

spine_slot_data spine_skeleton_data_find_slot(spine_skeleton_data obj, const char* slotName) {
    if (!obj) return (spine_slot_data) 0;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (spine_slot_data) _obj->findSlot(String(slotName));
}

spine_skin spine_skeleton_data_find_skin(spine_skeleton_data obj, const char* skinName) {
    if (!obj) return (spine_skin) 0;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (spine_skin) _obj->findSkin(String(skinName));
}

spine_event_data spine_skeleton_data_find_event(spine_skeleton_data obj, const char* eventDataName) {
    if (!obj) return (spine_event_data) 0;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (spine_event_data) _obj->findEvent(String(eventDataName));
}

spine_animation spine_skeleton_data_find_animation(spine_skeleton_data obj, const char* animationName) {
    if (!obj) return (spine_animation) 0;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (spine_animation) _obj->findAnimation(String(animationName));
}

spine_ik_constraint_data spine_skeleton_data_find_ik_constraint(spine_skeleton_data obj, const char* constraintName) {
    if (!obj) return 0;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (spine_ik_constraint_data) _obj->findIkConstraint(String(constraintName));
}

spine_transform_constraint_data spine_skeleton_data_find_transform_constraint(spine_skeleton_data obj, const char* constraintName) {
    if (!obj) return 0;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (spine_transform_constraint_data) _obj->findTransformConstraint(String(constraintName));
}

spine_path_constraint_data spine_skeleton_data_find_path_constraint(spine_skeleton_data obj, const char* constraintName) {
    if (!obj) return 0;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (spine_path_constraint_data) _obj->findPathConstraint(String(constraintName));
}

spine_physics_constraint_data spine_skeleton_data_find_physics_constraint(spine_skeleton_data obj, const char* constraintName) {
    if (!obj) return 0;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (spine_physics_constraint_data) _obj->findPhysicsConstraint(String(constraintName));
}

const char* spine_skeleton_data_get_name(spine_skeleton_data obj) {
    if (!obj) return nullptr;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (const char *) _obj->getName().buffer();
}

void spine_skeleton_data_set_name(spine_skeleton_data obj, const char* value) {
    if (!obj) return;
    SkeletonData *_obj = (SkeletonData *) obj;
    _obj->setName(String(value));
}

int32_t spine_skeleton_data_get_num_bones(spine_skeleton_data obj) {
    if (!obj) return 0;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (int32_t) _obj->getBones().size();
}

spine_bone_data *spine_skeleton_data_get_bones(spine_skeleton_data obj) {
    if (!obj) return nullptr;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (spine_bone_data *) _obj->getBones().buffer();
}

int32_t spine_skeleton_data_get_num_slots(spine_skeleton_data obj) {
    if (!obj) return 0;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (int32_t) _obj->getSlots().size();
}

spine_slot_data *spine_skeleton_data_get_slots(spine_skeleton_data obj) {
    if (!obj) return nullptr;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (spine_slot_data *) _obj->getSlots().buffer();
}

int32_t spine_skeleton_data_get_num_skins(spine_skeleton_data obj) {
    if (!obj) return 0;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (int32_t) _obj->getSkins().size();
}

spine_skin *spine_skeleton_data_get_skins(spine_skeleton_data obj) {
    if (!obj) return nullptr;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (spine_skin *) _obj->getSkins().buffer();
}

spine_skin spine_skeleton_data_get_default_skin(spine_skeleton_data obj) {
    if (!obj) return (spine_skin) 0;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (spine_skin) _obj->getDefaultSkin();
}

void spine_skeleton_data_set_default_skin(spine_skeleton_data obj, spine_skin value) {
    if (!obj) return;
    SkeletonData *_obj = (SkeletonData *) obj;
    _obj->setDefaultSkin((Skin *) value);
}

int32_t spine_skeleton_data_get_num_events(spine_skeleton_data obj) {
    if (!obj) return 0;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (int32_t) _obj->getEvents().size();
}

spine_event_data *spine_skeleton_data_get_events(spine_skeleton_data obj) {
    if (!obj) return nullptr;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (spine_event_data *) _obj->getEvents().buffer();
}

int32_t spine_skeleton_data_get_num_animations(spine_skeleton_data obj) {
    if (!obj) return 0;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (int32_t) _obj->getAnimations().size();
}

spine_animation *spine_skeleton_data_get_animations(spine_skeleton_data obj) {
    if (!obj) return nullptr;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (spine_animation *) _obj->getAnimations().buffer();
}

int32_t spine_skeleton_data_get_num_ik_constraints(spine_skeleton_data obj) {
    if (!obj) return 0;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (int32_t) _obj->getIkConstraints().size();
}

spine_ik_constraint_data *spine_skeleton_data_get_ik_constraints(spine_skeleton_data obj) {
    if (!obj) return nullptr;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (spine_ik_constraint_data *) _obj->getIkConstraints().buffer();
}

int32_t spine_skeleton_data_get_num_transform_constraints(spine_skeleton_data obj) {
    if (!obj) return 0;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (int32_t) _obj->getTransformConstraints().size();
}

spine_transform_constraint_data *spine_skeleton_data_get_transform_constraints(spine_skeleton_data obj) {
    if (!obj) return nullptr;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (spine_transform_constraint_data *) _obj->getTransformConstraints().buffer();
}

int32_t spine_skeleton_data_get_num_path_constraints(spine_skeleton_data obj) {
    if (!obj) return 0;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (int32_t) _obj->getPathConstraints().size();
}

spine_path_constraint_data *spine_skeleton_data_get_path_constraints(spine_skeleton_data obj) {
    if (!obj) return nullptr;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (spine_path_constraint_data *) _obj->getPathConstraints().buffer();
}

int32_t spine_skeleton_data_get_num_physics_constraints(spine_skeleton_data obj) {
    if (!obj) return 0;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (int32_t) _obj->getPhysicsConstraints().size();
}

spine_physics_constraint_data *spine_skeleton_data_get_physics_constraints(spine_skeleton_data obj) {
    if (!obj) return nullptr;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (spine_physics_constraint_data *) _obj->getPhysicsConstraints().buffer();
}

int32_t spine_skeleton_data_get_num_constraints(spine_skeleton_data obj) {
    if (!obj) return 0;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (int32_t) _obj->getConstraints().size();
}

spine_constraint_data *spine_skeleton_data_get_constraints(spine_skeleton_data obj) {
    if (!obj) return nullptr;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (spine_constraint_data *) _obj->getConstraints().buffer();
}

float spine_skeleton_data_get_x(spine_skeleton_data obj) {
    if (!obj) return 0;
    SkeletonData *_obj = (SkeletonData *) obj;
    return _obj->getX();
}

void spine_skeleton_data_set_x(spine_skeleton_data obj, float value) {
    if (!obj) return;
    SkeletonData *_obj = (SkeletonData *) obj;
    _obj->setX(value);
}

float spine_skeleton_data_get_y(spine_skeleton_data obj) {
    if (!obj) return 0;
    SkeletonData *_obj = (SkeletonData *) obj;
    return _obj->getY();
}

void spine_skeleton_data_set_y(spine_skeleton_data obj, float value) {
    if (!obj) return;
    SkeletonData *_obj = (SkeletonData *) obj;
    _obj->setY(value);
}

float spine_skeleton_data_get_width(spine_skeleton_data obj) {
    if (!obj) return 0;
    SkeletonData *_obj = (SkeletonData *) obj;
    return _obj->getWidth();
}

void spine_skeleton_data_set_width(spine_skeleton_data obj, float value) {
    if (!obj) return;
    SkeletonData *_obj = (SkeletonData *) obj;
    _obj->setWidth(value);
}

float spine_skeleton_data_get_height(spine_skeleton_data obj) {
    if (!obj) return 0;
    SkeletonData *_obj = (SkeletonData *) obj;
    return _obj->getHeight();
}

void spine_skeleton_data_set_height(spine_skeleton_data obj, float value) {
    if (!obj) return;
    SkeletonData *_obj = (SkeletonData *) obj;
    _obj->setHeight(value);
}

float spine_skeleton_data_get_reference_scale(spine_skeleton_data obj) {
    if (!obj) return 0;
    SkeletonData *_obj = (SkeletonData *) obj;
    return _obj->getReferenceScale();
}

void spine_skeleton_data_set_reference_scale(spine_skeleton_data obj, float value) {
    if (!obj) return;
    SkeletonData *_obj = (SkeletonData *) obj;
    _obj->setReferenceScale(value);
}

const char* spine_skeleton_data_get_version(spine_skeleton_data obj) {
    if (!obj) return nullptr;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (const char *) _obj->getVersion().buffer();
}

void spine_skeleton_data_set_version(spine_skeleton_data obj, const char* value) {
    if (!obj) return;
    SkeletonData *_obj = (SkeletonData *) obj;
    _obj->setVersion(String(value));
}

const char* spine_skeleton_data_get_hash(spine_skeleton_data obj) {
    if (!obj) return nullptr;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (const char *) _obj->getHash().buffer();
}

void spine_skeleton_data_set_hash(spine_skeleton_data obj, const char* value) {
    if (!obj) return;
    SkeletonData *_obj = (SkeletonData *) obj;
    _obj->setHash(String(value));
}

const char* spine_skeleton_data_get_images_path(spine_skeleton_data obj) {
    if (!obj) return nullptr;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (const char *) _obj->getImagesPath().buffer();
}

void spine_skeleton_data_set_images_path(spine_skeleton_data obj, const char* value) {
    if (!obj) return;
    SkeletonData *_obj = (SkeletonData *) obj;
    _obj->setImagesPath(String(value));
}

const char* spine_skeleton_data_get_audio_path(spine_skeleton_data obj) {
    if (!obj) return nullptr;
    SkeletonData *_obj = (SkeletonData *) obj;
    return (const char *) _obj->getAudioPath().buffer();
}

void spine_skeleton_data_set_audio_path(spine_skeleton_data obj, const char* value) {
    if (!obj) return;
    SkeletonData *_obj = (SkeletonData *) obj;
    _obj->setAudioPath(String(value));
}

float spine_skeleton_data_get_fps(spine_skeleton_data obj) {
    if (!obj) return 0;
    SkeletonData *_obj = (SkeletonData *) obj;
    return _obj->getFps();
}

void spine_skeleton_data_set_fps(spine_skeleton_data obj, float value) {
    if (!obj) return;
    SkeletonData *_obj = (SkeletonData *) obj;
    _obj->setFps(value);
}
