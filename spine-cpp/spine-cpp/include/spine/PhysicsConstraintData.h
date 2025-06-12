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

#ifndef Spine_PhysicsConstraintData_h
#define Spine_PhysicsConstraintData_h

#include <spine/ConstraintData.h>
#include <spine/PhysicsConstraintPose.h>

namespace spine {
	class BoneData;
	class PhysicsConstraint;

	/// Stores the setup pose for a PhysicsConstraint.
	///
	/// See https://esotericsoftware.com/spine-physics-constraints Physics constraints in the Spine User Guide.
	class SP_API PhysicsConstraintData : public ConstraintDataGeneric<PhysicsConstraint, PhysicsConstraintPose> {
		friend class SkeletonBinary;
		friend class SkeletonJson;
		friend class PhysicsConstraint;
		friend class Skeleton;

		RTTI_DECL
	public:
		explicit PhysicsConstraintData(const String &name);

		/// The bone constrained by this physics constraint.
		BoneData* getBone();
		void setBone(BoneData* bone);

		float getStep();
		void setStep(float step);

		float getX();
		void setX(float x);

		float getY();
		void setY(float y);

		float getRotate();
		void setRotate(float rotate);

		float getScaleX();
		void setScaleX(float scaleX);

		float getShearX();
		void setShearX(float shearX);

		float getLimit();
		void setLimit(float limit);

		bool getInertiaGlobal();
		void setInertiaGlobal(bool inertiaGlobal);

		bool getStrengthGlobal();
		void setStrengthGlobal(bool strengthGlobal);

		bool getDampingGlobal();
		void setDampingGlobal(bool dampingGlobal);

		bool getMassGlobal();
		void setMassGlobal(bool massGlobal);

		bool getWindGlobal();
		void setWindGlobal(bool windGlobal);

		bool getGravityGlobal();
		void setGravityGlobal(bool gravityGlobal);

		bool getMixGlobal();
		void setMixGlobal(bool mixGlobal);

	private:
		BoneData* _bone;
		float _x, _y, _rotate, _scaleX, _shearX, _limit, _step;
		bool _inertiaGlobal, _strengthGlobal, _dampingGlobal, _massGlobal, _windGlobal, _gravityGlobal, _mixGlobal;
	};
}

#endif /* Spine_PhysicsConstraintData_h */