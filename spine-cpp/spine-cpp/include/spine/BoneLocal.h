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

#ifndef Spine_BoneLocal_h
#define Spine_BoneLocal_h

#include <spine/Pose.h>
#include <spine/Inherit.h>
#include <spine/SpineObject.h>

namespace spine {
	/// Stores a bone's local pose.
	class SP_API BoneLocal : public SpineObject, public Pose<BoneLocal> {
	public:
		BoneLocal();

		virtual ~BoneLocal();

		virtual void set(const BoneLocal& pose) override;

		/// The local x translation.
		float getX() const;
		void setX(float x);

		/// The local y translation.
		float getY() const;
		void setY(float y);

		void setPosition(float x, float y);

		/// The local rotation in degrees, counter clockwise.
		float getRotation() const;
		void setRotation(float rotation);

		/// The local scaleX.
		float getScaleX() const;
		void setScaleX(float scaleX);

		/// The local scaleY.
		float getScaleY() const;
		void setScaleY(float scaleY);

		void setScale(float scaleX, float scaleY);
		void setScale(float scale);

		/// The local shearX.
		float getShearX() const;
		void setShearX(float shearX);

		/// The local shearY.
		float getShearY() const;
		void setShearY(float shearY);

		/// Determines how parent world transforms affect this bone.
		Inherit getInherit() const;
		void setInherit(Inherit inherit);

	protected:
		float _x, _y, _rotation, _scaleX, _scaleY, _shearX, _shearY;
		Inherit _inherit;
	};
}

#endif /* Spine_BoneLocal_h */