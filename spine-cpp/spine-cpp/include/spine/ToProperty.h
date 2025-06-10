/******************************************************************************
 * Spine Runtimes License Agreement
 * Last updated July 28, 2023. Replaces all prior versions.
 *
 * Copyright (c) 2013-2023, Esoteric Software LLC
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

#ifndef SPINE_TOPROPERTY_H_
#define SPINE_TOPROPERTY_H_

#include <spine/dll.h>
#include <spine/RTTI.h>

namespace spine {
	class TransformConstraintPose;
	class BonePose;

	/// Constrained property for a TransformConstraint.
	class SP_API ToProperty {
		RTTI_DECL
	public:
		ToProperty();
		virtual ~ToProperty();

	protected:
		/// The value of this property that corresponds to FromProperty::offset.
		float offset;

		/// The maximum value of this property when TransformConstraintData::clamp clamped.
		float max;

		/// The scale of the FromProperty value in relation to this property.
		float scale;

	public:
		/// Reads the mix for this property from the specified pose.
		virtual float mix(TransformConstraintPose& pose) = 0;

		/// Applies the value to this property.
		virtual void apply(TransformConstraintPose& pose, BonePose& bone, float value, bool local, bool additive) = 0;
	};
}

#endif /* SPINE_TOPROPERTY_H_ */