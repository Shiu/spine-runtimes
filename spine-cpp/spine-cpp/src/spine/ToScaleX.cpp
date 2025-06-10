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

#include <spine/ToScaleX.h>
#include <spine/TransformConstraintPose.h>
#include <spine/BonePose.h>
#include <spine/MathUtil.h>

using namespace spine;

RTTI_IMPL(ToScaleX, ToProperty)

ToScaleX::ToScaleX() {
}

ToScaleX::~ToScaleX() {
}

float ToScaleX::mix(TransformConstraintPose& pose) {
	return pose.getMixScaleX();
}

void ToScaleX::apply(TransformConstraintPose& pose, BonePose& bone, float value, bool local, bool additive) {
	if (local) {
		if (additive)
			bone.setScaleX(bone.getScaleX() * (1 + ((value - 1) * pose.getMixScaleX())));
		else if (bone.getScaleX() != 0)
			bone.setScaleX(1 + (value / bone.getScaleX() - 1) * pose.getMixScaleX());
	} else {
		float s;
		if (additive)
			s = 1 + (value - 1) * pose.getMixScaleX();
		else {
			s = MathUtil::sqrt(bone._a * bone._a + bone._c * bone._c);
			if (s != 0) s = 1 + (value / s - 1) * pose.getMixScaleX();
		}
		bone._a *= s;
		bone._c *= s;
	}
}