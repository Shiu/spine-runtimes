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

#include <spine/TranslateTimeline.h>

#include <spine/Event.h>
#include <spine/Skeleton.h>
#include <spine/Animation.h>

#include <spine/Bone.h>
#include <spine/BoneData.h>
#include <spine/Slot.h>
#include <spine/SlotData.h>

using namespace spine;

RTTI_IMPL(TranslateTimeline, BoneTimeline2)

TranslateTimeline::TranslateTimeline(size_t frameCount, size_t bezierCount, int boneIndex)
	: BoneTimeline2(frameCount, bezierCount, boneIndex, Property_X, Property_Y) {
}

void TranslateTimeline::apply(BoneLocal &pose, BoneLocal &setup, float time, float alpha, MixBlend blend, MixDirection direction) {
	if (time < _frames[0]) {
		switch (blend) {
			case MixBlend_Setup:
				pose._x = setup._x;
				pose._y = setup._y;
				return;
			case MixBlend_First:
				pose._x += (setup._x - pose._x) * alpha;
				pose._y += (setup._y - pose._y) * alpha;
			default: {
			}
		}
		return;
	}

	float x, y;
	int i = Animation::search(_frames, time, CurveTimeline2::ENTRIES);
	int curveType = (int) _curves[i / CurveTimeline2::ENTRIES];
	switch (curveType) {
		case CurveTimeline::LINEAR: {
			float before = _frames[i];
			x = _frames[i + CurveTimeline2::VALUE1];
			y = _frames[i + CurveTimeline2::VALUE2];
			float t = (time - before) / (_frames[i + CurveTimeline2::ENTRIES] - before);
			x += (_frames[i + CurveTimeline2::ENTRIES + CurveTimeline2::VALUE1] - x) * t;
			y += (_frames[i + CurveTimeline2::ENTRIES + CurveTimeline2::VALUE2] - y) * t;
			break;
		}
		case CurveTimeline::STEPPED: {
			x = _frames[i + CurveTimeline2::VALUE1];
			y = _frames[i + CurveTimeline2::VALUE2];
			break;
		}
		default: {
			x = getBezierValue(time, i, CurveTimeline2::VALUE1, curveType - CurveTimeline2::BEZIER);
			y = getBezierValue(time, i, CurveTimeline2::VALUE2, curveType + CurveTimeline2::BEZIER_SIZE - CurveTimeline2::BEZIER);
		}
	}

	switch (blend) {
		case MixBlend_Setup:
			pose._x = setup._x + x * alpha;
			pose._y = setup._y + y * alpha;
			break;
		case MixBlend_First:
		case MixBlend_Replace:
			pose._x += (setup._x + x - pose._x) * alpha;
			pose._y += (setup._y + y - pose._y) * alpha;
			break;
		case MixBlend_Add:
			pose._x += x * alpha;
			pose._y += y * alpha;
	}
}

RTTI_IMPL(TranslateXTimeline, BoneTimeline1)

TranslateXTimeline::TranslateXTimeline(size_t frameCount, size_t bezierCount, int boneIndex)
	: BoneTimeline1(frameCount, bezierCount, boneIndex, Property_X) {
}

void TranslateXTimeline::apply(BoneLocal &pose, BoneLocal &setup, float time, float alpha, MixBlend blend, MixDirection direction) {
	pose._x = getRelativeValue(time, alpha, blend, pose._x, setup._x);
}

RTTI_IMPL(TranslateYTimeline, BoneTimeline1)

TranslateYTimeline::TranslateYTimeline(size_t frameCount, size_t bezierCount, int boneIndex)
	: BoneTimeline1(frameCount, bezierCount, boneIndex, Property_Y) {
}

void TranslateYTimeline::apply(BoneLocal &pose, BoneLocal &setup, float time, float alpha, MixBlend blend, MixDirection direction) {
	pose._y = getRelativeValue(time, alpha, blend, pose._y, setup._y);
}