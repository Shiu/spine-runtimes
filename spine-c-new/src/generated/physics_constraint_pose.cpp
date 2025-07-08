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

#include "physics_constraint_pose.h"
#include <spine/spine.h>

using namespace spine;

spine_physics_constraint_pose spine_physics_constraint_pose_create(void) {
    PhysicsConstraintPose *obj = new (__FILE__, __LINE__) PhysicsConstraintPose();
    return (spine_physics_constraint_pose) obj;
}

void spine_physics_constraint_pose_dispose(spine_physics_constraint_pose obj) {
    if (!obj) return;
    delete (PhysicsConstraintPose *) obj;
}

void spine_physics_constraint_pose_set(spine_physics_constraint_pose obj, spine_physics_constraint_pose value) {
    if (!obj) return;
    PhysicsConstraintPose *_obj = (PhysicsConstraintPose *) obj;
    _obj->set(*((PhysicsConstraintPose*) value));
}

float spine_physics_constraint_pose_get_inertia(spine_physics_constraint_pose obj) {
    if (!obj) return 0;
    PhysicsConstraintPose *_obj = (PhysicsConstraintPose *) obj;
    return _obj->getInertia();
}

void spine_physics_constraint_pose_set_inertia(spine_physics_constraint_pose obj, float value) {
    if (!obj) return;
    PhysicsConstraintPose *_obj = (PhysicsConstraintPose *) obj;
    _obj->setInertia(value);
}

float spine_physics_constraint_pose_get_strength(spine_physics_constraint_pose obj) {
    if (!obj) return 0;
    PhysicsConstraintPose *_obj = (PhysicsConstraintPose *) obj;
    return _obj->getStrength();
}

void spine_physics_constraint_pose_set_strength(spine_physics_constraint_pose obj, float value) {
    if (!obj) return;
    PhysicsConstraintPose *_obj = (PhysicsConstraintPose *) obj;
    _obj->setStrength(value);
}

float spine_physics_constraint_pose_get_damping(spine_physics_constraint_pose obj) {
    if (!obj) return 0;
    PhysicsConstraintPose *_obj = (PhysicsConstraintPose *) obj;
    return _obj->getDamping();
}

void spine_physics_constraint_pose_set_damping(spine_physics_constraint_pose obj, float value) {
    if (!obj) return;
    PhysicsConstraintPose *_obj = (PhysicsConstraintPose *) obj;
    _obj->setDamping(value);
}

float spine_physics_constraint_pose_get_mass_inverse(spine_physics_constraint_pose obj) {
    if (!obj) return 0;
    PhysicsConstraintPose *_obj = (PhysicsConstraintPose *) obj;
    return _obj->getMassInverse();
}

void spine_physics_constraint_pose_set_mass_inverse(spine_physics_constraint_pose obj, float value) {
    if (!obj) return;
    PhysicsConstraintPose *_obj = (PhysicsConstraintPose *) obj;
    _obj->setMassInverse(value);
}

float spine_physics_constraint_pose_get_wind(spine_physics_constraint_pose obj) {
    if (!obj) return 0;
    PhysicsConstraintPose *_obj = (PhysicsConstraintPose *) obj;
    return _obj->getWind();
}

void spine_physics_constraint_pose_set_wind(spine_physics_constraint_pose obj, float value) {
    if (!obj) return;
    PhysicsConstraintPose *_obj = (PhysicsConstraintPose *) obj;
    _obj->setWind(value);
}

float spine_physics_constraint_pose_get_gravity(spine_physics_constraint_pose obj) {
    if (!obj) return 0;
    PhysicsConstraintPose *_obj = (PhysicsConstraintPose *) obj;
    return _obj->getGravity();
}

void spine_physics_constraint_pose_set_gravity(spine_physics_constraint_pose obj, float value) {
    if (!obj) return;
    PhysicsConstraintPose *_obj = (PhysicsConstraintPose *) obj;
    _obj->setGravity(value);
}

float spine_physics_constraint_pose_get_mix(spine_physics_constraint_pose obj) {
    if (!obj) return 0;
    PhysicsConstraintPose *_obj = (PhysicsConstraintPose *) obj;
    return _obj->getMix();
}

void spine_physics_constraint_pose_set_mix(spine_physics_constraint_pose obj, float value) {
    if (!obj) return;
    PhysicsConstraintPose *_obj = (PhysicsConstraintPose *) obj;
    _obj->setMix(value);
}
