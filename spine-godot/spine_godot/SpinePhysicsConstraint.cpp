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

#include "SpinePhysicsConstraint.h"
#include "SpineCommon.h"
#include "SpineSprite.h"

void SpinePhysicsConstraint::_bind_methods() {
	ClassDB::bind_method(D_METHOD("update", "skeleton", "physics"), &SpinePhysicsConstraint::update);
	ClassDB::bind_method(D_METHOD("get_bone"), &SpinePhysicsConstraint::get_bone);
	ClassDB::bind_method(D_METHOD("set_inertia", "value"), &SpinePhysicsConstraint::set_inertia);
	ClassDB::bind_method(D_METHOD("get_inertia"), &SpinePhysicsConstraint::get_inertia);
	ClassDB::bind_method(D_METHOD("set_strength", "value"), &SpinePhysicsConstraint::set_strength);
	ClassDB::bind_method(D_METHOD("get_strength"), &SpinePhysicsConstraint::get_strength);
	ClassDB::bind_method(D_METHOD("set_damping", "value"), &SpinePhysicsConstraint::set_damping);
	ClassDB::bind_method(D_METHOD("get_damping"), &SpinePhysicsConstraint::get_damping);
	ClassDB::bind_method(D_METHOD("set_mass_inverse", "value"), &SpinePhysicsConstraint::set_mass_inverse);
	ClassDB::bind_method(D_METHOD("get_mass_inverse"), &SpinePhysicsConstraint::get_mass_inverse);
	ClassDB::bind_method(D_METHOD("set_wind", "value"), &SpinePhysicsConstraint::set_wind);
	ClassDB::bind_method(D_METHOD("get_wind"), &SpinePhysicsConstraint::get_wind);
	ClassDB::bind_method(D_METHOD("set_gravity", "value"), &SpinePhysicsConstraint::set_gravity);
	ClassDB::bind_method(D_METHOD("get_gravity"), &SpinePhysicsConstraint::get_gravity);
	ClassDB::bind_method(D_METHOD("set_mix", "value"), &SpinePhysicsConstraint::set_mix);
	ClassDB::bind_method(D_METHOD("get_mix"), &SpinePhysicsConstraint::get_mix);
	ClassDB::bind_method(D_METHOD("reset", "skeleton"), &SpinePhysicsConstraint::reset);
	ClassDB::bind_method(D_METHOD("translate", "x", "y"), &SpinePhysicsConstraint::translate);
	ClassDB::bind_method(D_METHOD("rotate", "x", "y", "degrees"), &SpinePhysicsConstraint::rotate);
}

void SpinePhysicsConstraint::update(Ref<SpineSkeleton> skeleton, SpineConstant::Physics physics) {
	SPINE_CHECK(get_spine_object(), )
	get_spine_object()->update(*skeleton->get_spine_object(), (spine::Physics) physics);
}

Ref<SpinePhysicsConstraintData> SpinePhysicsConstraint::get_data() {
	SPINE_CHECK(get_spine_object(), nullptr)
	auto &data = get_spine_object()->getData();
	Ref<SpinePhysicsConstraintData> data_ref(memnew(SpinePhysicsConstraintData));
	data_ref->set_spine_object(*get_spine_owner()->get_skeleton_data_res(), &data);
	return data_ref;
}

Ref<SpineBone> SpinePhysicsConstraint::get_bone() {
	SPINE_CHECK(get_spine_object(), nullptr)
	auto target = &get_spine_object()->getBone();
	if (!target) return nullptr;
	Ref<SpineBone> target_ref(memnew(SpineBone));
	target_ref->set_spine_object(get_spine_owner(), target);
	return target_ref;
}

void SpinePhysicsConstraint::set_bone(Ref<SpineBone> v) {
	SPINE_CHECK(get_spine_object(), )
	if (v.is_valid() && v->get_spine_object()) {
		get_spine_object()->setBone(v->get_spine_object());
	}
}

void SpinePhysicsConstraint::set_inertia(float value) {
	SPINE_CHECK(get_spine_object(), )
	get_spine_object()->getPose().setInertia(value);
}

float SpinePhysicsConstraint::get_inertia() {
	SPINE_CHECK(get_spine_object(), 0)
	return get_spine_object()->getPose().getInertia();
}

void SpinePhysicsConstraint::set_strength(float value) {
	SPINE_CHECK(get_spine_object(), )
	get_spine_object()->getPose().setStrength(value);
}

float SpinePhysicsConstraint::get_strength() {
	SPINE_CHECK(get_spine_object(), 0)
	return get_spine_object()->getPose().getStrength();
}

void SpinePhysicsConstraint::set_damping(float value) {
	SPINE_CHECK(get_spine_object(), )
	get_spine_object()->getPose().setDamping(value);
}

float SpinePhysicsConstraint::get_damping() {
	SPINE_CHECK(get_spine_object(), 0)
	return get_spine_object()->getPose().getDamping();
}

void SpinePhysicsConstraint::set_mass_inverse(float value) {
	SPINE_CHECK(get_spine_object(), )
	get_spine_object()->getPose().setMassInverse(value);
}

float SpinePhysicsConstraint::get_mass_inverse() {
	SPINE_CHECK(get_spine_object(), 0)
	return get_spine_object()->getPose().getMassInverse();
}

void SpinePhysicsConstraint::set_wind(float value) {
	SPINE_CHECK(get_spine_object(), )
	get_spine_object()->getPose().setWind(value);
}

float SpinePhysicsConstraint::get_wind() {
	SPINE_CHECK(get_spine_object(), 0)
	return get_spine_object()->getPose().getWind();
}

void SpinePhysicsConstraint::set_gravity(float value) {
	SPINE_CHECK(get_spine_object(), )
	get_spine_object()->getPose().setGravity(value);
}

float SpinePhysicsConstraint::get_gravity() {
	SPINE_CHECK(get_spine_object(), 0)
	return get_spine_object()->getPose().getGravity();
}

void SpinePhysicsConstraint::set_mix(float value) {
	SPINE_CHECK(get_spine_object(), )
	get_spine_object()->getPose().setMix(value);
}

float SpinePhysicsConstraint::get_mix() {
	SPINE_CHECK(get_spine_object(), 0)
	return get_spine_object()->getPose().getMix();
}

void SpinePhysicsConstraint::reset(Ref<SpineSkeleton> skeleton) {
	SPINE_CHECK(get_spine_object(), )
	get_spine_object()->reset(*skeleton->get_spine_object());
}

void SpinePhysicsConstraint::translate(float x, float y) {
	SPINE_CHECK(get_spine_object(), )
	get_spine_object()->translate(x, y);
}

void SpinePhysicsConstraint::rotate(float x, float y, float degrees) {
	SPINE_CHECK(get_spine_object(), )
	get_spine_object()->rotate(x, y, degrees);
}
