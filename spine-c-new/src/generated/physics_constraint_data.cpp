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

#include "physics_constraint_data.h"
#include <spine/spine.h>

using namespace spine;

spine_physics_constraint_data spine_physics_constraint_data_create(const char* name) {
    PhysicsConstraintData *obj = new (__FILE__, __LINE__) PhysicsConstraintData(String(name));
    return (spine_physics_constraint_data) obj;
}

void spine_physics_constraint_data_dispose(spine_physics_constraint_data obj) {
    if (!obj) return;
    delete (PhysicsConstraintData *) obj;
}

spine_rtti spine_physics_constraint_data_get_rtti() {
    return (spine_rtti) &PhysicsConstraintData::rtti;
}

spine_constraint spine_physics_constraint_data_create(spine_physics_constraint_data obj, spine_skeleton skeleton) {
    if (!obj) return 0;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    return (spine_constraint) _obj->create(*(Skeleton*) skeleton);
}

spine_bone_data spine_physics_constraint_data_get_bone(spine_physics_constraint_data obj) {
    if (!obj) return (spine_bone_data) 0;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    return (spine_bone_data) _obj->getBone();
}

void spine_physics_constraint_data_set_bone(spine_physics_constraint_data obj, spine_bone_data value) {
    if (!obj) return;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    _obj->setBone((BoneData *) value);
}

float spine_physics_constraint_data_get_step(spine_physics_constraint_data obj) {
    if (!obj) return 0;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    return _obj->getStep();
}

void spine_physics_constraint_data_set_step(spine_physics_constraint_data obj, float value) {
    if (!obj) return;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    _obj->setStep(value);
}

float spine_physics_constraint_data_get_x(spine_physics_constraint_data obj) {
    if (!obj) return 0;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    return _obj->getX();
}

void spine_physics_constraint_data_set_x(spine_physics_constraint_data obj, float value) {
    if (!obj) return;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    _obj->setX(value);
}

float spine_physics_constraint_data_get_y(spine_physics_constraint_data obj) {
    if (!obj) return 0;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    return _obj->getY();
}

void spine_physics_constraint_data_set_y(spine_physics_constraint_data obj, float value) {
    if (!obj) return;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    _obj->setY(value);
}

float spine_physics_constraint_data_get_rotate(spine_physics_constraint_data obj) {
    if (!obj) return 0;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    return _obj->getRotate();
}

void spine_physics_constraint_data_set_rotate(spine_physics_constraint_data obj, float value) {
    if (!obj) return;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    _obj->setRotate(value);
}

float spine_physics_constraint_data_get_scale_x(spine_physics_constraint_data obj) {
    if (!obj) return 0;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    return _obj->getScaleX();
}

void spine_physics_constraint_data_set_scale_x(spine_physics_constraint_data obj, float value) {
    if (!obj) return;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    _obj->setScaleX(value);
}

float spine_physics_constraint_data_get_shear_x(spine_physics_constraint_data obj) {
    if (!obj) return 0;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    return _obj->getShearX();
}

void spine_physics_constraint_data_set_shear_x(spine_physics_constraint_data obj, float value) {
    if (!obj) return;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    _obj->setShearX(value);
}

float spine_physics_constraint_data_get_limit(spine_physics_constraint_data obj) {
    if (!obj) return 0;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    return _obj->getLimit();
}

void spine_physics_constraint_data_set_limit(spine_physics_constraint_data obj, float value) {
    if (!obj) return;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    _obj->setLimit(value);
}

bool spine_physics_constraint_data_get_inertia_global(spine_physics_constraint_data obj) {
    if (!obj) return false;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    return _obj->getInertiaGlobal();
}

void spine_physics_constraint_data_set_inertia_global(spine_physics_constraint_data obj, bool value) {
    if (!obj) return;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    _obj->setInertiaGlobal(value);
}

bool spine_physics_constraint_data_get_strength_global(spine_physics_constraint_data obj) {
    if (!obj) return false;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    return _obj->getStrengthGlobal();
}

void spine_physics_constraint_data_set_strength_global(spine_physics_constraint_data obj, bool value) {
    if (!obj) return;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    _obj->setStrengthGlobal(value);
}

bool spine_physics_constraint_data_get_damping_global(spine_physics_constraint_data obj) {
    if (!obj) return false;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    return _obj->getDampingGlobal();
}

void spine_physics_constraint_data_set_damping_global(spine_physics_constraint_data obj, bool value) {
    if (!obj) return;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    _obj->setDampingGlobal(value);
}

bool spine_physics_constraint_data_get_mass_global(spine_physics_constraint_data obj) {
    if (!obj) return false;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    return _obj->getMassGlobal();
}

void spine_physics_constraint_data_set_mass_global(spine_physics_constraint_data obj, bool value) {
    if (!obj) return;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    _obj->setMassGlobal(value);
}

bool spine_physics_constraint_data_get_wind_global(spine_physics_constraint_data obj) {
    if (!obj) return false;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    return _obj->getWindGlobal();
}

void spine_physics_constraint_data_set_wind_global(spine_physics_constraint_data obj, bool value) {
    if (!obj) return;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    _obj->setWindGlobal(value);
}

bool spine_physics_constraint_data_get_gravity_global(spine_physics_constraint_data obj) {
    if (!obj) return false;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    return _obj->getGravityGlobal();
}

void spine_physics_constraint_data_set_gravity_global(spine_physics_constraint_data obj, bool value) {
    if (!obj) return;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    _obj->setGravityGlobal(value);
}

bool spine_physics_constraint_data_get_mix_global(spine_physics_constraint_data obj) {
    if (!obj) return false;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    return _obj->getMixGlobal();
}

void spine_physics_constraint_data_set_mix_global(spine_physics_constraint_data obj, bool value) {
    if (!obj) return;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    _obj->setMixGlobal(value);
}

const char* spine_physics_constraint_data_get_name(spine_physics_constraint_data obj) {
    if (!obj) return nullptr;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    return (const char *) _obj->getName().buffer();
}

bool spine_physics_constraint_data_is_skin_required(spine_physics_constraint_data obj) {
    if (!obj) return false;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    return _obj->isSkinRequired();
}

spine_physics_constraint_pose spine_physics_constraint_data_get_setup_pose(spine_physics_constraint_data obj) {
    if (!obj) return 0;
    PhysicsConstraintData *_obj = (PhysicsConstraintData *) obj;
    return (spine_physics_constraint_pose) &_obj->getSetupPose();
}
