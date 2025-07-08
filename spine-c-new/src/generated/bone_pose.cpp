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

#include "bone_pose.h"
#include <spine/spine.h>

using namespace spine;

spine_bone_pose spine_bone_pose_create(void) {
    BonePose *obj = new (__FILE__, __LINE__) BonePose();
    return (spine_bone_pose) obj;
}

void spine_bone_pose_dispose(spine_bone_pose obj) {
    if (!obj) return;
    delete (BonePose *) obj;
}

void spine_bone_pose_update(spine_bone_pose obj, spine_skeleton skeleton, spine_physics physics) {
    if (!obj) return ;
    BonePose *_obj = (BonePose *) obj;
    _obj->update(skeleton, physics);
}

void spine_bone_pose_update_world_transform(spine_bone_pose obj, spine_skeleton skeleton) {
    if (!obj) return ;
    BonePose *_obj = (BonePose *) obj;
    _obj->updateWorldTransform(skeleton);
}

void spine_bone_pose_update_local_transform(spine_bone_pose obj, spine_skeleton skeleton) {
    if (!obj) return ;
    BonePose *_obj = (BonePose *) obj;
    _obj->updateLocalTransform(skeleton);
}

void spine_bone_pose_validate_local_transform(spine_bone_pose obj, spine_skeleton skeleton) {
    if (!obj) return ;
    BonePose *_obj = (BonePose *) obj;
    _obj->validateLocalTransform(skeleton);
}

void spine_bone_pose_modify_local(spine_bone_pose obj, spine_skeleton skeleton) {
    if (!obj) return ;
    BonePose *_obj = (BonePose *) obj;
    _obj->modifyLocal(skeleton);
}

void spine_bone_pose_modify_world(spine_bone_pose obj, int32_t update) {
    if (!obj) return ;
    BonePose *_obj = (BonePose *) obj;
    _obj->modifyWorld(update);
}

void spine_bone_pose_reset_world(spine_bone_pose obj, int32_t update) {
    if (!obj) return ;
    BonePose *_obj = (BonePose *) obj;
    _obj->resetWorld(update);
}

float spine_bone_pose_get_a(spine_bone_pose obj) {
    if (!obj) return 0;
    BonePose *_obj = (BonePose *) obj;
    return _obj->getA();
}

void spine_bone_pose_set_a(spine_bone_pose obj, float value) {
    if (!obj) return;
    BonePose *_obj = (BonePose *) obj;
    _obj->setA(value);
}

float spine_bone_pose_get_b(spine_bone_pose obj) {
    if (!obj) return 0;
    BonePose *_obj = (BonePose *) obj;
    return _obj->getB();
}

void spine_bone_pose_set_b(spine_bone_pose obj, float value) {
    if (!obj) return;
    BonePose *_obj = (BonePose *) obj;
    _obj->setB(value);
}

float spine_bone_pose_get_c(spine_bone_pose obj) {
    if (!obj) return 0;
    BonePose *_obj = (BonePose *) obj;
    return _obj->getC();
}

void spine_bone_pose_set_c(spine_bone_pose obj, float value) {
    if (!obj) return;
    BonePose *_obj = (BonePose *) obj;
    _obj->setC(value);
}

float spine_bone_pose_get_d(spine_bone_pose obj) {
    if (!obj) return 0;
    BonePose *_obj = (BonePose *) obj;
    return _obj->getD();
}

void spine_bone_pose_set_d(spine_bone_pose obj, float value) {
    if (!obj) return;
    BonePose *_obj = (BonePose *) obj;
    _obj->setD(value);
}

float spine_bone_pose_get_world_x(spine_bone_pose obj) {
    if (!obj) return 0;
    BonePose *_obj = (BonePose *) obj;
    return _obj->getWorldX();
}

void spine_bone_pose_set_world_x(spine_bone_pose obj, float value) {
    if (!obj) return;
    BonePose *_obj = (BonePose *) obj;
    _obj->setWorldX(value);
}

float spine_bone_pose_get_world_y(spine_bone_pose obj) {
    if (!obj) return 0;
    BonePose *_obj = (BonePose *) obj;
    return _obj->getWorldY();
}

void spine_bone_pose_set_world_y(spine_bone_pose obj, float value) {
    if (!obj) return;
    BonePose *_obj = (BonePose *) obj;
    _obj->setWorldY(value);
}

float spine_bone_pose_get_world_rotation_x(spine_bone_pose obj) {
    if (!obj) return 0;
    BonePose *_obj = (BonePose *) obj;
    return _obj->getWorldRotationX();
}

float spine_bone_pose_get_world_rotation_y(spine_bone_pose obj) {
    if (!obj) return 0;
    BonePose *_obj = (BonePose *) obj;
    return _obj->getWorldRotationY();
}

float spine_bone_pose_get_world_scale_x(spine_bone_pose obj) {
    if (!obj) return 0;
    BonePose *_obj = (BonePose *) obj;
    return _obj->getWorldScaleX();
}

float spine_bone_pose_get_world_scale_y(spine_bone_pose obj) {
    if (!obj) return 0;
    BonePose *_obj = (BonePose *) obj;
    return _obj->getWorldScaleY();
}

void spine_bone_pose_world_to_local(spine_bone_pose obj, float worldX, float worldY, float outLocalX, float outLocalY) {
    if (!obj) return ;
    BonePose *_obj = (BonePose *) obj;
    _obj->worldToLocal(worldX, worldY, outLocalX, outLocalY);
}

void spine_bone_pose_local_to_world(spine_bone_pose obj, float localX, float localY, float outWorldX, float outWorldY) {
    if (!obj) return ;
    BonePose *_obj = (BonePose *) obj;
    _obj->localToWorld(localX, localY, outWorldX, outWorldY);
}

void spine_bone_pose_world_to_parent(spine_bone_pose obj, float worldX, float worldY, float outParentX, float outParentY) {
    if (!obj) return ;
    BonePose *_obj = (BonePose *) obj;
    _obj->worldToParent(worldX, worldY, outParentX, outParentY);
}

void spine_bone_pose_parent_to_world(spine_bone_pose obj, float parentX, float parentY, float outWorldX, float outWorldY) {
    if (!obj) return ;
    BonePose *_obj = (BonePose *) obj;
    _obj->parentToWorld(parentX, parentY, outWorldX, outWorldY);
}

float spine_bone_pose_world_to_local_rotation(spine_bone_pose obj, float worldRotation) {
    if (!obj) return 0;
    BonePose *_obj = (BonePose *) obj;
    return _obj->worldToLocalRotation(worldRotation);
}

float spine_bone_pose_local_to_world_rotation(spine_bone_pose obj, float localRotation) {
    if (!obj) return 0;
    BonePose *_obj = (BonePose *) obj;
    return _obj->localToWorldRotation(localRotation);
}

void spine_bone_pose_rotate_world(spine_bone_pose obj, float degrees) {
    if (!obj) return ;
    BonePose *_obj = (BonePose *) obj;
    _obj->rotateWorld(degrees);
}

void spine_bone_pose_set(spine_bone_pose obj, spine_bone_local value) {
    if (!obj) return;
    BonePose *_obj = (BonePose *) obj;
    _obj->set(value);
}

float spine_bone_pose_get_x(spine_bone_pose obj) {
    if (!obj) return 0;
    BonePose *_obj = (BonePose *) obj;
    return _obj->getX();
}

void spine_bone_pose_set_x(spine_bone_pose obj, float value) {
    if (!obj) return;
    BonePose *_obj = (BonePose *) obj;
    _obj->setX(value);
}

float spine_bone_pose_get_y(spine_bone_pose obj) {
    if (!obj) return 0;
    BonePose *_obj = (BonePose *) obj;
    return _obj->getY();
}

void spine_bone_pose_set_y(spine_bone_pose obj, float value) {
    if (!obj) return;
    BonePose *_obj = (BonePose *) obj;
    _obj->setY(value);
}

void spine_bone_pose_set_position(spine_bone_pose obj, float x, float y) {
    if (!obj) return ;
    BonePose *_obj = (BonePose *) obj;
    _obj->setPosition(x, y);
}

float spine_bone_pose_get_rotation(spine_bone_pose obj) {
    if (!obj) return 0;
    BonePose *_obj = (BonePose *) obj;
    return _obj->getRotation();
}

void spine_bone_pose_set_rotation(spine_bone_pose obj, float value) {
    if (!obj) return;
    BonePose *_obj = (BonePose *) obj;
    _obj->setRotation(value);
}

float spine_bone_pose_get_scale_x(spine_bone_pose obj) {
    if (!obj) return 0;
    BonePose *_obj = (BonePose *) obj;
    return _obj->getScaleX();
}

void spine_bone_pose_set_scale_x(spine_bone_pose obj, float value) {
    if (!obj) return;
    BonePose *_obj = (BonePose *) obj;
    _obj->setScaleX(value);
}

float spine_bone_pose_get_scale_y(spine_bone_pose obj) {
    if (!obj) return 0;
    BonePose *_obj = (BonePose *) obj;
    return _obj->getScaleY();
}

void spine_bone_pose_set_scale_y(spine_bone_pose obj, float value) {
    if (!obj) return;
    BonePose *_obj = (BonePose *) obj;
    _obj->setScaleY(value);
}

void spine_bone_pose_set_scale(spine_bone_pose obj, float scaleX, float scaleY) {
    if (!obj) return ;
    BonePose *_obj = (BonePose *) obj;
    _obj->setScale(scaleX, scaleY);
}

void spine_bone_pose_set_scale(spine_bone_pose obj, float value) {
    if (!obj) return;
    BonePose *_obj = (BonePose *) obj;
    _obj->setScale(value);
}

float spine_bone_pose_get_shear_x(spine_bone_pose obj) {
    if (!obj) return 0;
    BonePose *_obj = (BonePose *) obj;
    return _obj->getShearX();
}

void spine_bone_pose_set_shear_x(spine_bone_pose obj, float value) {
    if (!obj) return;
    BonePose *_obj = (BonePose *) obj;
    _obj->setShearX(value);
}

float spine_bone_pose_get_shear_y(spine_bone_pose obj) {
    if (!obj) return 0;
    BonePose *_obj = (BonePose *) obj;
    return _obj->getShearY();
}

void spine_bone_pose_set_shear_y(spine_bone_pose obj, float value) {
    if (!obj) return;
    BonePose *_obj = (BonePose *) obj;
    _obj->setShearY(value);
}

spine_inherit spine_bone_pose_get_inherit(spine_bone_pose obj) {
    if (!obj) return nullptr;
    BonePose *_obj = (BonePose *) obj;
    return _obj->getInherit();
}

void spine_bone_pose_set_inherit(spine_bone_pose obj, spine_inherit value) {
    if (!obj) return;
    BonePose *_obj = (BonePose *) obj;
    _obj->setInherit(value);
}

spine_rtti spine_bone_pose_get_rtti(spine_bone_pose obj) {
    if (!obj) return nullptr;
    BonePose *_obj = (BonePose *) obj;
    return (spine_rtti) &_obj->getRTTI();
}
