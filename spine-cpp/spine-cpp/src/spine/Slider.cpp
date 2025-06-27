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

#include <spine/Slider.h>
#include <spine/Skeleton.h>
#include <spine/Bone.h>
#include <spine/BoneData.h>
#include <spine/BonePose.h>
#include <spine/Animation.h>
#include <spine/Timeline.h>
#include <spine/SlotTimeline.h>
#include <spine/ConstraintTimeline.h>
#include <spine/PhysicsConstraintTimeline.h>
#include <spine/SliderData.h>
#include <spine/SliderPose.h>
#include <spine/Slot.h>
#include <spine/PhysicsConstraint.h>
#include <spine/TransformConstraintData.h>
#include <spine/MathUtil.h>

using namespace spine;

RTTI_IMPL(Slider, Constraint)

float Slider::_offsets[6];

Slider::Slider(SliderData &data, Skeleton &skeleton) : ConstraintGeneric<Slider, SliderData, SliderPose>(data), _bone(NULL) {
	if (data._bone != NULL) {
		_bone = skeleton._bones[data._bone->getIndex()];
	}
}

Slider *Slider::copy(Skeleton &skeleton) {
	Slider *copy = new (__FILE__, __LINE__) Slider(_data, skeleton);
	copy->_pose.set(_pose);
	return copy;
}

void Slider::update(Skeleton &skeleton, Physics physics) {
	SliderPose &p = *_applied;
	if (p._mix == 0) return;

	Animation *animation = _data._animation;
	if (_bone != NULL) {
		if (!_bone->isActive()) return;
		if (_data._local) _bone->_applied->validateLocalTransform(skeleton);
		p._time = _data._offset
			+ (_data._property->value(skeleton, *_bone->_applied, _data._local, _offsets) - _data._property->offset) * _data._scale;
		if (_data._loop)
			p._time = animation->getDuration() + MathUtil::fmod(p._time, animation->getDuration());
		else
			p._time = MathUtil::max(0.0f, p._time);
	}

	Vector<Bone *> &bones = skeleton._bones;
	const Vector<int> &indices = animation->getBones();
	for (size_t i = 0, n = indices.size(); i < n; i++)
		bones[indices[i]]->_applied->modifyLocal(skeleton);

	animation->apply(skeleton, p._time, p._time, _data._loop, NULL, p._mix, _data._additive ? MixBlend_Add : MixBlend_Replace,
		MixDirection_In, true);
}

void Slider::sort(Skeleton &skeleton) {
	if (_bone != NULL && !_data._local) skeleton.sortBone(_bone);
	skeleton._updateCache.add(this);

	Vector<Bone *> &bones = skeleton._bones;
	const Vector<int> &indices = _data._animation->getBones();
	for (size_t i = 0, n = indices.size(); i < n; i++) {
		Bone *bone = bones[indices[i]];
		bone->_sorted = false;
		skeleton.sortReset(bone->getChildren());
		skeleton.constrained(*bone);
	}

	Vector<Timeline *> &timelines = _data._animation->getTimelines();
	Vector<Slot *> &slots = skeleton._slots;
	Vector<Constraint *> &constraints = skeleton._constraints;
	Vector<PhysicsConstraint *> &physics = skeleton._physics;
	size_t physicsCount = physics.size();
	for (size_t i = 0, n = timelines.size(); i < n; i++) {
		Timeline *t = timelines[i];

		if (t->getRTTI().instanceOf(SlotTimeline::rtti)) {
			SlotTimeline *timeline = (SlotTimeline *)t;
			skeleton.constrained(*slots[timeline->getSlotIndex()]);
		} else if (t->getRTTI().instanceOf(PhysicsConstraintTimeline::rtti)) {
			PhysicsConstraintTimeline *timeline = (PhysicsConstraintTimeline *)t;
			if (timeline->getConstraintIndex() == -1) {
				for (size_t ii = 0; ii < physicsCount; ii++)
					skeleton.constrained(*physics[ii]);
			} else
				skeleton.constrained((Posed &)*constraints[timeline->getConstraintIndex()]);
		} else if (t->getRTTI().instanceOf(ConstraintTimeline::rtti)) {
			ConstraintTimeline *timeline = (ConstraintTimeline *)t;
			skeleton.constrained((Posed &)*constraints[timeline->getConstraintIndex()]);
		}
	}
}

bool Slider::isSourceActive() {
	return _bone == NULL || _bone->isActive();
}

Bone *Slider::getBone() {
	return _bone;
}

void Slider::setBone(Bone *bone) {
	_bone = bone;
}