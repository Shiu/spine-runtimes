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

#include <spine/BoneTimeline.h>

#include <spine/Event.h>
#include <spine/Skeleton.h>
#include <spine/Bone.h>
#include <spine/BoneData.h>
#include <spine/BoneLocal.h>
#include <spine/Property.h>

using namespace spine;

RTTI_IMPL_NOPARENT(BoneTimeline)

RTTI_IMPL(BoneTimeline1, CurveTimeline1)

BoneTimeline1::BoneTimeline1(size_t frameCount, size_t bezierCount, int boneIndex, Property property) : BoneTimeline(boneIndex),
																										CurveTimeline1(frameCount, bezierCount) {
	PropertyId ids[] = {((PropertyId) property << 32) | boneIndex};
	setPropertyIds(ids, 1);
}

void BoneTimeline1::apply(Skeleton &skeleton, float lastTime, float time, Vector<Event *> *pEvents, float alpha,
						  MixBlend blend, MixDirection direction, bool appliedPose) {
	SP_UNUSED(lastTime);
	SP_UNUSED(pEvents);

	Bone *bone = skeleton._bones[_boneIndex];
	if (bone->isActive()) {
		apply(appliedPose ? *bone->_applied : bone->_pose, bone->_data._setup, time, alpha, blend, direction);
	}
}

RTTI_IMPL(BoneTimeline2, CurveTimeline2)

BoneTimeline2::BoneTimeline2(size_t frameCount, size_t bezierCount, int boneIndex, Property property1, Property property2) : BoneTimeline(boneIndex),
																															 CurveTimeline2(frameCount, bezierCount) {
	PropertyId ids[] = {((PropertyId) property1 << 32) | boneIndex, ((PropertyId) property2 << 32) | boneIndex};
	setPropertyIds(ids, 2);
}

void BoneTimeline2::apply(Skeleton &skeleton, float lastTime, float time, Vector<Event *> *pEvents, float alpha,
						  MixBlend blend, MixDirection direction, bool appliedPose) {
	SP_UNUSED(lastTime);
	SP_UNUSED(pEvents);

	Bone *bone = skeleton._bones[_boneIndex];
	if (bone->isActive()) {
		apply(appliedPose ? *bone->_applied : bone->_pose, bone->_data._setup, time, alpha, blend, direction);
	}
}