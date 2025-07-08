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

#include "skeleton.h"
#include <spine/spine.h>

using namespace spine;

spine_skeleton spine_skeleton_create(spine_skeleton_data skeletonData) {
    Skeleton *obj = new (__FILE__, __LINE__) Skeleton(skeletonData);
    return (spine_skeleton) obj;
}

void spine_skeleton_dispose(spine_skeleton obj) {
    if (!obj) return;
    delete (Skeleton *) obj;
}

void spine_skeleton_constrained(spine_skeleton obj, spine_posed object) {
    if (!obj) return ;
    Skeleton *_obj = (Skeleton *) obj;
    _obj->constrained(object);
}

void spine_skeleton_sort_bone(spine_skeleton obj, spine_bone bone) {
    if (!obj) return ;
    Skeleton *_obj = (Skeleton *) obj;
    _obj->sortBone((Bone *) bone);
}

void spine_skeleton_update_world_transform(spine_skeleton obj, spine_physics physics) {
    if (!obj) return ;
    Skeleton *_obj = (Skeleton *) obj;
    _obj->updateWorldTransform(physics);
}

void spine_skeleton_update_world_transform(spine_skeleton obj, spine_physics physics, spine_bone_pose parent) {
    if (!obj) return ;
    Skeleton *_obj = (Skeleton *) obj;
    _obj->updateWorldTransform(physics, (BonePose *) parent);
}

void spine_skeleton_setup_pose(spine_skeleton obj) {
    if (!obj) return ;
    Skeleton *_obj = (Skeleton *) obj;
    _obj->setupPose();
}

void spine_skeleton_setup_pose_bones(spine_skeleton obj) {
    if (!obj) return ;
    Skeleton *_obj = (Skeleton *) obj;
    _obj->setupPoseBones();
}

void spine_skeleton_setup_pose_slots(spine_skeleton obj) {
    if (!obj) return ;
    Skeleton *_obj = (Skeleton *) obj;
    _obj->setupPoseSlots();
}

spine_skeleton_data spine_skeleton_get_data(spine_skeleton obj) {
    if (!obj) return nullptr;
    Skeleton *_obj = (Skeleton *) obj;
    return (spine_skeleton_data) _obj->getData();
}

void * spine_skeleton_get_bones(spine_skeleton obj) {
    if (!obj) return nullptr;
    Skeleton *_obj = (Skeleton *) obj;
    return (void *) _obj->getBones();
}

int32_t spine_skeleton_get_num_bones(spine_skeleton obj) {
    if (!obj) return 0;
    Skeleton *_obj = (Skeleton *) obj;
    return (int32_t) _obj->getBones().size();
}

spine_bone *spine_skeleton_get_bones(spine_skeleton obj) {
    if (!obj) return nullptr;
    Skeleton *_obj = (Skeleton *) obj;
    return (spine_bone *) _obj->getBones().buffer();
}

void * spine_skeleton_get_update_cache(spine_skeleton obj) {
    if (!obj) return nullptr;
    Skeleton *_obj = (Skeleton *) obj;
    return (void *) _obj->getUpdateCache();
}

int32_t spine_skeleton_get_num_update_cache(spine_skeleton obj) {
    if (!obj) return 0;
    Skeleton *_obj = (Skeleton *) obj;
    return (int32_t) _obj->getUpdateCache().size();
}

spine_update *spine_skeleton_get_update_cache(spine_skeleton obj) {
    if (!obj) return nullptr;
    Skeleton *_obj = (Skeleton *) obj;
    return (spine_update *) _obj->getUpdateCache().buffer();
}

spine_bone spine_skeleton_get_root_bone(spine_skeleton obj) {
    if (!obj) return nullptr;
    Skeleton *_obj = (Skeleton *) obj;
    return (spine_bone) _obj->getRootBone();
}

spine_bone spine_skeleton_find_bone(spine_skeleton obj, const utf8 * boneName) {
    if (!obj) return nullptr;
    Skeleton *_obj = (Skeleton *) obj;
    return (spine_bone) _obj->findBone(String(boneName));
}

void * spine_skeleton_get_slots(spine_skeleton obj) {
    if (!obj) return nullptr;
    Skeleton *_obj = (Skeleton *) obj;
    return (void *) _obj->getSlots();
}

int32_t spine_skeleton_get_num_slots(spine_skeleton obj) {
    if (!obj) return 0;
    Skeleton *_obj = (Skeleton *) obj;
    return (int32_t) _obj->getSlots().size();
}

spine_slot *spine_skeleton_get_slots(spine_skeleton obj) {
    if (!obj) return nullptr;
    Skeleton *_obj = (Skeleton *) obj;
    return (spine_slot *) _obj->getSlots().buffer();
}

spine_slot spine_skeleton_find_slot(spine_skeleton obj, const utf8 * slotName) {
    if (!obj) return nullptr;
    Skeleton *_obj = (Skeleton *) obj;
    return (spine_slot) _obj->findSlot(String(slotName));
}

void * spine_skeleton_get_draw_order(spine_skeleton obj) {
    if (!obj) return nullptr;
    Skeleton *_obj = (Skeleton *) obj;
    return (void *) _obj->getDrawOrder();
}

int32_t spine_skeleton_get_num_draw_order(spine_skeleton obj) {
    if (!obj) return 0;
    Skeleton *_obj = (Skeleton *) obj;
    return (int32_t) _obj->getDrawOrder().size();
}

spine_slot *spine_skeleton_get_draw_order(spine_skeleton obj) {
    if (!obj) return nullptr;
    Skeleton *_obj = (Skeleton *) obj;
    return (spine_slot *) _obj->getDrawOrder().buffer();
}

spine_skin spine_skeleton_get_skin(spine_skeleton obj) {
    if (!obj) return nullptr;
    Skeleton *_obj = (Skeleton *) obj;
    return (spine_skin) _obj->getSkin();
}

void spine_skeleton_set_skin(spine_skeleton obj, const utf8 * value) {
    if (!obj) return;
    Skeleton *_obj = (Skeleton *) obj;
    _obj->setSkin(String(value));
}

void spine_skeleton_set_skin(spine_skeleton obj, spine_skin value) {
    if (!obj) return;
    Skeleton *_obj = (Skeleton *) obj;
    _obj->setSkin((Skin *) value);
}

spine_attachment spine_skeleton_get_attachment(spine_skeleton obj, const utf8 * slotName, const utf8 * attachmentName) {
    if (!obj) return nullptr;
    Skeleton *_obj = (Skeleton *) obj;
    return (spine_attachment) _obj->getAttachment(String(slotName), String(attachmentName));
}

spine_attachment spine_skeleton_get_attachment(spine_skeleton obj, int32_t slotIndex, const utf8 * attachmentName) {
    if (!obj) return nullptr;
    Skeleton *_obj = (Skeleton *) obj;
    return (spine_attachment) _obj->getAttachment(slotIndex, String(attachmentName));
}

void spine_skeleton_set_attachment(spine_skeleton obj, const utf8 * slotName, const utf8 * attachmentName) {
    if (!obj) return ;
    Skeleton *_obj = (Skeleton *) obj;
    _obj->setAttachment(String(slotName), String(attachmentName));
}

void * spine_skeleton_get_constraints(spine_skeleton obj) {
    if (!obj) return nullptr;
    Skeleton *_obj = (Skeleton *) obj;
    return (void *) _obj->getConstraints();
}

int32_t spine_skeleton_get_num_constraints(spine_skeleton obj) {
    if (!obj) return 0;
    Skeleton *_obj = (Skeleton *) obj;
    return (int32_t) _obj->getConstraints().size();
}

spine_constraint *spine_skeleton_get_constraints(spine_skeleton obj) {
    if (!obj) return nullptr;
    Skeleton *_obj = (Skeleton *) obj;
    return (spine_constraint *) _obj->getConstraints().buffer();
}

void * spine_skeleton_get_physics_constraints(spine_skeleton obj) {
    if (!obj) return nullptr;
    Skeleton *_obj = (Skeleton *) obj;
    return (void *) _obj->getPhysicsConstraints();
}

int32_t spine_skeleton_get_num_physics_constraints(spine_skeleton obj) {
    if (!obj) return 0;
    Skeleton *_obj = (Skeleton *) obj;
    return (int32_t) _obj->getPhysicsConstraints().size();
}

spine_physics_constraint *spine_skeleton_get_physics_constraints(spine_skeleton obj) {
    if (!obj) return nullptr;
    Skeleton *_obj = (Skeleton *) obj;
    return (spine_physics_constraint *) _obj->getPhysicsConstraints().buffer();
}

void spine_skeleton_get_bounds(spine_skeleton obj, float outX, float outY, float outWidth, float outHeight, void * outVertexBuffer) {
    if (!obj) return ;
    Skeleton *_obj = (Skeleton *) obj;
    _obj->getBounds(outX, outY, outWidth, outHeight, (Vector<float> &) outVertexBuffer);
}

void spine_skeleton_get_bounds(spine_skeleton obj, float outX, float outY, float outWidth, float outHeight, void * outVertexBuffer, spine_skeleton_clipping clipper) {
    if (!obj) return ;
    Skeleton *_obj = (Skeleton *) obj;
    _obj->getBounds(outX, outY, outWidth, outHeight, (Vector<float> &) outVertexBuffer, (SkeletonClipping *) clipper);
}

spine_color spine_skeleton_get_color(spine_skeleton obj) {
    if (!obj) return nullptr;
    Skeleton *_obj = (Skeleton *) obj;
    return (spine_color) &_obj->getColor();
}

void spine_skeleton_set_color(spine_skeleton obj, spine_color value) {
    if (!obj) return;
    Skeleton *_obj = (Skeleton *) obj;
    _obj->setColor(value);
}

void spine_skeleton_set_color(spine_skeleton obj, float r, float g, float b, float a) {
    if (!obj) return ;
    Skeleton *_obj = (Skeleton *) obj;
    _obj->setColor(r, g, b, a);
}

float spine_skeleton_get_scale_x(spine_skeleton obj) {
    if (!obj) return 0;
    Skeleton *_obj = (Skeleton *) obj;
    return _obj->getScaleX();
}

void spine_skeleton_set_scale_x(spine_skeleton obj, float value) {
    if (!obj) return;
    Skeleton *_obj = (Skeleton *) obj;
    _obj->setScaleX(value);
}

float spine_skeleton_get_scale_y(spine_skeleton obj) {
    if (!obj) return 0;
    Skeleton *_obj = (Skeleton *) obj;
    return _obj->getScaleY();
}

void spine_skeleton_set_scale_y(spine_skeleton obj, float value) {
    if (!obj) return;
    Skeleton *_obj = (Skeleton *) obj;
    _obj->setScaleY(value);
}

void spine_skeleton_set_scale(spine_skeleton obj, float scaleX, float scaleY) {
    if (!obj) return ;
    Skeleton *_obj = (Skeleton *) obj;
    _obj->setScale(scaleX, scaleY);
}

float spine_skeleton_get_x(spine_skeleton obj) {
    if (!obj) return 0;
    Skeleton *_obj = (Skeleton *) obj;
    return _obj->getX();
}

void spine_skeleton_set_x(spine_skeleton obj, float value) {
    if (!obj) return;
    Skeleton *_obj = (Skeleton *) obj;
    _obj->setX(value);
}

float spine_skeleton_get_y(spine_skeleton obj) {
    if (!obj) return 0;
    Skeleton *_obj = (Skeleton *) obj;
    return _obj->getY();
}

void spine_skeleton_set_y(spine_skeleton obj, float value) {
    if (!obj) return;
    Skeleton *_obj = (Skeleton *) obj;
    _obj->setY(value);
}

void spine_skeleton_set_position(spine_skeleton obj, float x, float y) {
    if (!obj) return ;
    Skeleton *_obj = (Skeleton *) obj;
    _obj->setPosition(x, y);
}

float spine_skeleton_get_wind_x(spine_skeleton obj) {
    if (!obj) return 0;
    Skeleton *_obj = (Skeleton *) obj;
    return _obj->getWindX();
}

void spine_skeleton_set_wind_x(spine_skeleton obj, float value) {
    if (!obj) return;
    Skeleton *_obj = (Skeleton *) obj;
    _obj->setWindX(value);
}

float spine_skeleton_get_wind_y(spine_skeleton obj) {
    if (!obj) return 0;
    Skeleton *_obj = (Skeleton *) obj;
    return _obj->getWindY();
}

void spine_skeleton_set_wind_y(spine_skeleton obj, float value) {
    if (!obj) return;
    Skeleton *_obj = (Skeleton *) obj;
    _obj->setWindY(value);
}

float spine_skeleton_get_gravity_x(spine_skeleton obj) {
    if (!obj) return 0;
    Skeleton *_obj = (Skeleton *) obj;
    return _obj->getGravityX();
}

void spine_skeleton_set_gravity_x(spine_skeleton obj, float value) {
    if (!obj) return;
    Skeleton *_obj = (Skeleton *) obj;
    _obj->setGravityX(value);
}

float spine_skeleton_get_gravity_y(spine_skeleton obj) {
    if (!obj) return 0;
    Skeleton *_obj = (Skeleton *) obj;
    return _obj->getGravityY();
}

void spine_skeleton_set_gravity_y(spine_skeleton obj, float value) {
    if (!obj) return;
    Skeleton *_obj = (Skeleton *) obj;
    _obj->setGravityY(value);
}

void spine_skeleton_physics_translate(spine_skeleton obj, float x, float y) {
    if (!obj) return ;
    Skeleton *_obj = (Skeleton *) obj;
    _obj->physicsTranslate(x, y);
}

void spine_skeleton_physics_rotate(spine_skeleton obj, float x, float y, float degrees) {
    if (!obj) return ;
    Skeleton *_obj = (Skeleton *) obj;
    _obj->physicsRotate(x, y, degrees);
}

float spine_skeleton_get_time(spine_skeleton obj) {
    if (!obj) return 0;
    Skeleton *_obj = (Skeleton *) obj;
    return _obj->getTime();
}

void spine_skeleton_set_time(spine_skeleton obj, float value) {
    if (!obj) return;
    Skeleton *_obj = (Skeleton *) obj;
    _obj->setTime(value);
}

void spine_skeleton_update(spine_skeleton obj, float delta) {
    if (!obj) return ;
    Skeleton *_obj = (Skeleton *) obj;
    _obj->update(delta);
}
