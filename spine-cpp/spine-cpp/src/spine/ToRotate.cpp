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

#include <spine/ToRotate.h>
#include <spine/TransformConstraintPose.h>
#include <spine/BonePose.h>
#include <spine/MathUtil.h>

using namespace spine;

RTTI_IMPL(ToRotate, ToProperty)

ToRotate::ToRotate() {
}

ToRotate::~ToRotate() {
}

float ToRotate::mix(TransformConstraintPose& pose) {
	return pose.getMixRotate();
}

void ToRotate::apply(TransformConstraintPose& pose, BonePose& bone, float value, bool local, bool additive) {
	if (local) {
		if (!additive) value -= bone.getRotation();
		bone.setRotation(bone.getRotation() + value * pose.getMixRotate());
	} else {
		float a = bone._a, b = bone._b, c = bone._c, d = bone._d;
		value *= MathUtil::Deg_Rad;
		if (!additive) value -= MathUtil::atan2(c, a);
		if (value > MathUtil::Pi)
			value -= MathUtil::Pi * 2;
		else if (value < -MathUtil::Pi)
			value += MathUtil::Pi * 2;
		value *= pose.getMixRotate();
		float cosVal = MathUtil::cos(value), sinVal = MathUtil::sin(value);
		bone._a = cosVal * a - sinVal * c;
		bone._b = cosVal * b - sinVal * d;
		bone._c = sinVal * a + cosVal * c;
		bone._d = sinVal * b + cosVal * d;
	}
}