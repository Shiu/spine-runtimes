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

#ifndef SPINE_BONEPOSE_H_
#define SPINE_BONEPOSE_H_

#include <spine/BoneLocal.h>
#include <spine/Update.h>
#include <spine/RTTI.h>

namespace spine {
	class Bone;
	class Skeleton;

	class SP_API BonePose : public BoneLocal, public Update {
		friend class IkConstraint;
		RTTI_DECL

	public:
		Bone* _bone;
		float _a, _b, _worldX;
		float _c, _d, _worldY;
		int _world, _local;

		BonePose();
		virtual ~BonePose();

		/// Called by Skeleton::updateCache() to compute the world transform, if needed.
		virtual void update(Skeleton& skeleton, Physics physics) override;

		/// Computes the world transform using the parent bone's applied pose and this pose. Child bones are not updated.
		/// 
		/// See <a href="https://esotericsoftware.com/spine-runtime-skeletons#World-transforms">World transforms</a> in the Spine
		/// Runtimes Guide.
		void updateWorldTransform(Skeleton& skeleton);

		/// Computes the local transform values from the world transform.
		/// 
		/// If the world transform is modified (by a constraint, rotateWorld(), etc) then this method should be called so
		/// the local transform matches the world transform. The local transform may be needed by other code (eg to apply another
		/// constraint).
		/// 
		/// Some information is ambiguous in the world transform, such as -1,-1 scale versus 180 rotation. The local transform after
		/// calling this method is equivalent to the local transform used to compute the world transform, but may not be identical.
		void updateLocalTransform(Skeleton& skeleton);

		/// If the world transform has been modified and the local transform no longer matches, updateLocalTransform() is called.
		void validateLocalTransform(Skeleton& skeleton);

		void modifyLocal(Skeleton& skeleton);
		void modifyWorld(int update);
		void resetWorld(int update);

		/// Part of the world transform matrix for the X axis. If changed, updateLocalTransform() should be called.
		float getA();
		void setA(float a);

		/// Part of the world transform matrix for the Y axis. If changed, updateLocalTransform() should be called.
		float getB();
		void setB(float b);

		/// Part of the world transform matrix for the X axis. If changed, updateLocalTransform() should be called.
		float getC();
		void setC(float c);

		/// Part of the world transform matrix for the Y axis. If changed, updateLocalTransform() should be called.
		float getD();
		void setD(float d);

		/// The world X position. If changed, updateLocalTransform() should be called.
		float getWorldX();
		void setWorldX(float worldX);

		/// The world Y position. If changed, updateLocalTransform() should be called.
		float getWorldY();
		void setWorldY(float worldY);

		/// The world rotation for the X axis, calculated using a and c.
		float getWorldRotationX();

		/// The world rotation for the Y axis, calculated using b and d.
		float getWorldRotationY();

		/// The magnitude (always positive) of the world scale X, calculated using a and c.
		float getWorldScaleX();

		/// The magnitude (always positive) of the world scale Y, calculated using b and d.
		float getWorldScaleY();

		/// Transforms a point from world coordinates to the bone's local coordinates.
		void worldToLocal(float worldX, float worldY, float& outLocalX, float& outLocalY);

		/// Transforms a point from the bone's local coordinates to world coordinates.
		void localToWorld(float localX, float localY, float& outWorldX, float& outWorldY);

		/// Transforms a point from world coordinates to the parent bone's local coordinates.
		void worldToParent(float worldX, float worldY, float& outParentX, float& outParentY);

		/// Transforms a point from the parent bone's coordinates to world coordinates.
		void parentToWorld(float parentX, float parentY, float& outWorldX, float& outWorldY);

		/// Transforms a world rotation to a local rotation.
		float worldToLocalRotation(float worldRotation);

		/// Transforms a local rotation to a world rotation.
		float localToWorldRotation(float localRotation);

		/// Rotates the world transform the specified amount.
		/// 
		/// After changes are made to the world transform, updateLocalTransform() should be called on this bone and any
		/// child bones, recursively.
		void rotateWorld(float degrees);
	};
}

#endif /* SPINE_BONEPOSE_H_ */