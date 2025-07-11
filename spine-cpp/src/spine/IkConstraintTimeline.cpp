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

#include <spine/IkConstraintTimeline.h>

#include <spine/Event.h>
#include <spine/Skeleton.h>

#include <spine/Animation.h>
#include <spine/IkConstraint.h>
#include <spine/IkConstraintData.h>
#include <spine/IkConstraintPose.h>
#include <spine/Property.h>
#include <spine/Slot.h>
#include <spine/SlotData.h>

using namespace spine;

RTTI_IMPL_MULTI(IkConstraintTimeline, CurveTimeline, ConstraintTimeline)

IkConstraintTimeline::IkConstraintTimeline(size_t frameCount, size_t bezierCount, int constraintIndex)
	: CurveTimeline(frameCount, IkConstraintTimeline::ENTRIES, bezierCount), ConstraintTimeline(constraintIndex) {
	PropertyId ids[] = {((PropertyId) Property_IkConstraint << 32) | constraintIndex};
	setPropertyIds(ids, 1);
}

IkConstraintTimeline::~IkConstraintTimeline() {
}

void IkConstraintTimeline::apply(Skeleton &skeleton, float lastTime, float time, Array<Event *> *pEvents, float alpha,
								 MixBlend blend, MixDirection direction, bool appliedPose) {
	SP_UNUSED(lastTime);
	SP_UNUSED(pEvents);

	IkConstraint *constraint = (IkConstraint *) skeleton._constraints[_constraintIndex];
	if (!constraint->isActive()) return;
	IkConstraintPose &pose = appliedPose ? *constraint->_applied : constraint->_pose;

	if (time < _frames[0]) {
		IkConstraintPose &setup = constraint->_data._setup;
		switch (blend) {
			case MixBlend_Setup:
				pose._mix = setup._mix;
				pose._softness = setup._softness;
				pose._bendDirection = setup._bendDirection;
				pose._compress = setup._compress;
				pose._stretch = setup._stretch;
				return;
			case MixBlend_First:
				pose._mix += (setup._mix - pose._mix) * alpha;
				pose._softness += (setup._softness - pose._softness) * alpha;
				pose._bendDirection = setup._bendDirection;
				pose._compress = setup._compress;
				pose._stretch = setup._stretch;
				return;
			default:
				return;
		}
	}

	float mix = 0, softness = 0;
	int i = Animation::search(_frames, time, ENTRIES);
	int curveType = (int) _curves[i / ENTRIES];
	switch (curveType) {
		case LINEAR: {
			float before = _frames[i];
			mix = _frames[i + MIX];
			softness = _frames[i + SOFTNESS];
			float t = (time - before) / (_frames[i + ENTRIES] - before);
			mix += (_frames[i + ENTRIES + MIX] - mix) * t;
			softness += (_frames[i + ENTRIES + SOFTNESS] - softness) * t;
			break;
		}
		case STEPPED: {
			mix = _frames[i + MIX];
			softness = _frames[i + SOFTNESS];
			break;
		}
		default: {
			mix = getBezierValue(time, i, MIX, curveType - BEZIER);
			softness = getBezierValue(time, i, SOFTNESS,
									  curveType + BEZIER_SIZE -
											  BEZIER);
		}
	}

	switch (blend) {
		case MixBlend_Setup: {
			IkConstraintPose &setup = constraint->_data._setup;
			pose._mix = setup._mix + (mix - setup._mix) * alpha;
			pose._softness = setup._softness + (softness - setup._softness) * alpha;
			if (direction == MixDirection_Out) {
				pose._bendDirection = setup._bendDirection;
				pose._compress = setup._compress;
				pose._stretch = setup._stretch;
				return;
			}
			break;
		}
		case MixBlend_First:
		case MixBlend_Replace:
			pose._mix += (mix - pose._mix) * alpha;
			pose._softness += (softness - pose._softness) * alpha;
			if (direction == MixDirection_Out) return;
			break;
		case MixBlend_Add:
			pose._mix += mix * alpha;
			pose._softness += softness * alpha;
			if (direction == MixDirection_Out) return;
			break;
	}
	pose._bendDirection = (int) _frames[i + BEND_DIRECTION];
	pose._compress = _frames[i + COMPRESS] != 0;
	pose._stretch = _frames[i + STRETCH] != 0;
}

void IkConstraintTimeline::setFrame(int frame, float time, float mix, float softness, int bendDirection, bool compress,
									bool stretch) {
	frame *= ENTRIES;
	_frames[frame] = time;
	_frames[frame + MIX] = mix;
	_frames[frame + SOFTNESS] = softness;
	_frames[frame + BEND_DIRECTION] = (float) bendDirection;
	_frames[frame + COMPRESS] = compress ? 1 : 0;
	_frames[frame + STRETCH] = stretch ? 1 : 0;
}
