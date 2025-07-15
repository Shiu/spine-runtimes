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

#include <spine/PathConstraintMixTimeline.h>

#include <spine/Event.h>
#include <spine/Skeleton.h>

#include <spine/Animation.h>
#include <spine/PathConstraint.h>
#include <spine/PathConstraintData.h>
#include <spine/PathConstraintPose.h>
#include <spine/Property.h>
#include <spine/Slot.h>
#include <spine/SlotData.h>

using namespace spine;

RTTI_IMPL_MULTI(PathConstraintMixTimeline, CurveTimeline, ConstraintTimeline)

PathConstraintMixTimeline::PathConstraintMixTimeline(size_t frameCount, size_t bezierCount, int constraintIndex)
	: CurveTimeline(frameCount, PathConstraintMixTimeline::ENTRIES, bezierCount), ConstraintTimeline(constraintIndex) {
	PropertyId ids[] = {((PropertyId) Property_PathConstraintMix << 32) | constraintIndex};
	setPropertyIds(ids, 1);
}

PathConstraintMixTimeline::~PathConstraintMixTimeline() {
}

void PathConstraintMixTimeline::apply(Skeleton &skeleton, float lastTime, float time, Array<Event *> *pEvents, float alpha, MixBlend blend,
									  MixDirection direction, bool appliedPose) {
	SP_UNUSED(lastTime);
	SP_UNUSED(pEvents);
	SP_UNUSED(direction);

	PathConstraint *constraint = (PathConstraint *) skeleton._constraints[_constraintIndex];
	if (!constraint->isActive()) return;
	PathConstraintPose &pose = appliedPose ? *constraint->_applied : constraint->_pose;

	if (time < _frames[0]) {
		PathConstraintPose &setup = constraint->_data._setup;
		switch (blend) {
			case MixBlend_Setup:
				pose._mixRotate = setup._mixRotate;
				pose._mixX = setup._mixX;
				pose._mixY = setup._mixY;
				return;
			case MixBlend_First:
				pose._mixRotate += (setup._mixRotate - pose._mixRotate) * alpha;
				pose._mixX += (setup._mixX - pose._mixX) * alpha;
				pose._mixY += (setup._mixY - pose._mixY) * alpha;
				return;
			default:
				return;
		}
	}

	float rotate, x, y;
	int i = Animation::search(_frames, time, PathConstraintMixTimeline::ENTRIES);
	int curveType = (int) _curves[i >> 2];
	switch (curveType) {
		case LINEAR: {
			float before = _frames[i];
			rotate = _frames[i + ROTATE];
			x = _frames[i + X];
			y = _frames[i + Y];
			float t = (time - before) / (_frames[i + ENTRIES] - before);
			rotate += (_frames[i + ENTRIES + ROTATE] - rotate) * t;
			x += (_frames[i + ENTRIES + X] - x) * t;
			y += (_frames[i + ENTRIES + Y] - y) * t;
			break;
		}
		case STEPPED: {
			rotate = _frames[i + ROTATE];
			x = _frames[i + X];
			y = _frames[i + Y];
			break;
		}
		default: {
			rotate = getBezierValue(time, i, ROTATE, curveType - BEZIER);
			x = getBezierValue(time, i, X, curveType + BEZIER_SIZE - BEZIER);
			y = getBezierValue(time, i, Y, curveType + BEZIER_SIZE * 2 - BEZIER);
		}
	}

	switch (blend) {
		case MixBlend_Setup: {
			PathConstraintPose &setup = constraint->_data._setup;
			pose._mixRotate = setup._mixRotate + (rotate - setup._mixRotate) * alpha;
			pose._mixX = setup._mixX + (x - setup._mixX) * alpha;
			pose._mixY = setup._mixY + (y - setup._mixY) * alpha;
			break;
		}
		case MixBlend_First:
		case MixBlend_Replace:
			pose._mixRotate += (rotate - pose._mixRotate) * alpha;
			pose._mixX += (x - pose._mixX) * alpha;
			pose._mixY += (y - pose._mixY) * alpha;
			break;
		case MixBlend_Add:
			pose._mixRotate += rotate * alpha;
			pose._mixX += x * alpha;
			pose._mixY += y * alpha;
			break;
	}
}

void PathConstraintMixTimeline::setFrame(int frame, float time, float mixRotate, float mixX, float mixY) {
	frame *= ENTRIES;
	_frames[frame] = time;
	_frames[frame + ROTATE] = mixRotate;
	_frames[frame + X] = mixX;
	_frames[frame + Y] = mixY;
}
