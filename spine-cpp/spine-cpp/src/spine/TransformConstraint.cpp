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

#include <spine/TransformConstraint.h>

#include <spine/Bone.h>
#include <spine/BonePose.h>
#include <spine/Skeleton.h>
#include <spine/TransformConstraintData.h>
#include <spine/MathUtil.h>

#include <spine/BoneData.h>

using namespace spine;

RTTI_IMPL_NOPARENT(TransformConstraint)

TransformConstraint::TransformConstraint(TransformConstraintData& data, Skeleton& skeleton) : 
	Constraint<TransformConstraint, TransformConstraintData, TransformConstraintPose>(data) {
	if (&skeleton == NULL) throw;

	_bones.ensureCapacity(data.getBones().size());
	for (size_t i = 0; i < data.getBones().size(); i++) {
		BoneData* boneData = data.getBones()[i];
		_bones.add(&skeleton.findBone(boneData->getName())->getAppliedPose());
	}

	_source = skeleton.findBone(data.getSource()->getName());
}

TransformConstraint TransformConstraint::copy(Skeleton& skeleton) {
	TransformConstraint copy(_data, skeleton);
	copy._applied->set(*_applied);
	return copy;
}

/// Applies the constraint to the constrained bones.
void TransformConstraint::update(Skeleton& skeleton, Physics physics) {
	TransformConstraintPose& p = *_applied;
	if (p.getMixRotate() == 0 && p.getMixX() == 0 && p.getMixY() == 0 && p.getMixScaleX() == 0 && p.getMixScaleY() == 0 && p.getMixShearY() == 0) return;

	TransformConstraintData& data = _data;
	bool localSource = data.getLocalSource(), localTarget = data.getLocalTarget(), additive = data.getAdditive(), clamp = data.getClamp();
	float* offsets = data._offsets; // Access friend field directly
	BonePose& source = _source->getAppliedPose();
	if (localSource) {
		source.validateLocalTransform(skeleton);
	}
	Vector<FromProperty*>& properties = data.getProperties();
	FromProperty** fromItems = properties.buffer();
	size_t fn = properties.size();
	int update = 1; // TODO: Add skeleton.update field
	BonePose** bones = _bones.buffer();
	for (size_t i = 0, n = _bones.size(); i < n; i++) {
		BonePose* bone = bones[i];
		if (localTarget) {
			bone->modifyLocal(skeleton);
		} else {
			bone->modifyWorld(update);
		}
		for (size_t f = 0; f < fn; f++) {
			FromProperty* from = fromItems[f];
			float value = from->value(source, localSource, offsets) - from->offset;
			Vector<ToProperty*>& toProps = from->to;
			ToProperty** toItems = toProps.buffer();
			for (size_t t = 0, tn = toProps.size(); t < tn; t++) {
				ToProperty* to = toItems[t];
				if (to->mix(p) != 0) {
					float clamped = to->offset + value * to->scale;
					if (clamp) {
						if (to->offset < to->max)
							clamped = MathUtil::clamp(clamped, to->offset, to->max);
						else
							clamped = MathUtil::clamp(clamped, to->max, to->offset);
					}
					to->apply(p, *bone, clamped, localTarget, additive);
				}
			}
		}
	}
}

void TransformConstraint::sort(Skeleton& skeleton) {
	// if (!_data.getLocalSource()) skeleton.sortBone(_source); // TODO: sortBone is private, need friend access
	BonePose** bones = _bones.buffer();
	size_t boneCount = _bones.size();
	bool worldTarget = !_data.getLocalTarget();
	// if (worldTarget) {
	// 	for (size_t i = 0; i < boneCount; i++)
	// 		skeleton.sortBone(bones[i]->_bone); // TODO: sortBone is private, need friend access
	// }
	// skeleton._updateCache.add(this); // TODO: _updateCache is private, need friend access
	// for (size_t i = 0; i < boneCount; i++) {
	// 	Bone* bone = bones[i]->_bone;
	// 	skeleton.sortReset(bone->getChildren()); // TODO: sortReset is private, need friend access
	// 	// skeleton.constrained(bone); // TODO: Add constrained() method to Skeleton class
	// }
	// for (size_t i = 0; i < boneCount; i++)
	// 	bones[i]->_bone->_sorted = worldTarget; // TODO: _sorted is private, need friend access
}

bool TransformConstraint::isSourceActive() {
	return _source->isActive();
}

/// The bones that will be modified by this transform constraint.
Vector<BonePose*>& TransformConstraint::getBones() {
	return _bones;
}

/// The bone whose world transform will be copied to the constrained bones.
Bone* TransformConstraint::getSource() {
	return _source;
}

void TransformConstraint::setSource(Bone* source) {
	if (source == NULL) throw;
	_source = source;
}