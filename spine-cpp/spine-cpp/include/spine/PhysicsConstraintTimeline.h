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

#ifndef Spine_PhysicsConstraintTimeline_h
#define Spine_PhysicsConstraintTimeline_h

#include <spine/CurveTimeline.h>
#include <spine/PhysicsConstraint.h>
#include <spine/PhysicsConstraintData.h>
#include <spine/PhysicsConstraintPose.h>
#include <spine/ConstraintTimeline.h>

namespace spine {

	class SP_API PhysicsConstraintTimeline : public CurveTimeline1, public ConstraintTimeline {
		friend class SkeletonBinary;

		friend class SkeletonJson;

	RTTI_DECL

	public:
		explicit PhysicsConstraintTimeline(size_t frameCount, size_t bezierCount, int physicsConstraintIndex, Property property);

		virtual void
		apply(Skeleton &skeleton, float lastTime, float time, Vector<Event *> *pEvents, float alpha, MixBlend blend,
			  MixDirection direction, bool appliedPose) override;

    protected:
        virtual float get(PhysicsConstraintPose &pose) = 0;
        virtual void set(PhysicsConstraintPose &pose, float value) = 0;
        virtual bool global(PhysicsConstraintData &constraintData) = 0;

	private:
		int _constraintIndex;
	};

    /// Changes a physics constraint's PhysicsConstraintPose::getInertia().
    class SP_API PhysicsConstraintInertiaTimeline : public PhysicsConstraintTimeline {
        friend class SkeletonBinary;

        friend class SkeletonJson;

    RTTI_DECL

    public:
        explicit PhysicsConstraintInertiaTimeline(size_t frameCount, size_t bezierCount, int physicsConstraintIndex): PhysicsConstraintTimeline(frameCount, bezierCount, physicsConstraintIndex, Property_PhysicsConstraintInertia) {};

    protected:
        float get(PhysicsConstraintPose &pose) override {
            return pose.getInertia();
        }

        void set(PhysicsConstraintPose &pose, float value) override {
            pose.setInertia(value);
        }

        bool global(PhysicsConstraintData &constraintData) override {
            return constraintData.getInertiaGlobal();
        }
    };

    class SP_API PhysicsConstraintStrengthTimeline : public PhysicsConstraintTimeline {
        friend class SkeletonBinary;

        friend class SkeletonJson;

    RTTI_DECL

    public:
        explicit PhysicsConstraintStrengthTimeline(size_t frameCount, size_t bezierCount, int physicsConstraintIndex): PhysicsConstraintTimeline(frameCount, bezierCount, physicsConstraintIndex, Property_PhysicsConstraintStrength) {};

    protected:
        float get(PhysicsConstraintPose &pose) override {
            return pose.getStrength();
        }

        void set(PhysicsConstraintPose &pose, float value) override {
            pose.setStrength(value);
        }

        bool global(PhysicsConstraintData &constraintData) override {
            return constraintData.getStrengthGlobal();
        }
    };

    /// Changes a physics constraint's PhysicsConstraintPose::getDamping().
    class SP_API PhysicsConstraintDampingTimeline : public PhysicsConstraintTimeline {
        friend class SkeletonBinary;

        friend class SkeletonJson;

    RTTI_DECL

    public:
        explicit PhysicsConstraintDampingTimeline(size_t frameCount, size_t bezierCount, int physicsConstraintIndex): PhysicsConstraintTimeline(frameCount, bezierCount, physicsConstraintIndex, Property_PhysicsConstraintDamping) {};

    protected:
        float get(PhysicsConstraintPose &pose) override {
            return pose.getDamping();
        }

        void set(PhysicsConstraintPose &pose, float value) override {
            pose.setDamping(value);
        }

        bool global(PhysicsConstraintData &constraintData) override {
            return constraintData.getDampingGlobal();
        }
    };

    /// Changes a physics constraint's PhysicsConstraintPose::getMassInverse(). The timeline values are not inverted.
    class SP_API PhysicsConstraintMassTimeline : public PhysicsConstraintTimeline {
        friend class SkeletonBinary;

        friend class SkeletonJson;

    RTTI_DECL

    public:
        explicit PhysicsConstraintMassTimeline(size_t frameCount, size_t bezierCount, int physicsConstraintIndex): PhysicsConstraintTimeline(frameCount, bezierCount, physicsConstraintIndex, Property_PhysicsConstraintMass) {};

    protected:
        float get(PhysicsConstraintPose &pose) override {
            return 1 / pose.getMassInverse();
        }

        void set(PhysicsConstraintPose &pose, float value) override {
            pose.setMassInverse(1 / value);
        }

        bool global(PhysicsConstraintData &constraintData) override {
            return constraintData.getMassGlobal();
        }
    };

    class SP_API PhysicsConstraintWindTimeline : public PhysicsConstraintTimeline {
        friend class SkeletonBinary;

        friend class SkeletonJson;

    RTTI_DECL

    public:
        explicit PhysicsConstraintWindTimeline(size_t frameCount, size_t bezierCount, int physicsConstraintIndex): PhysicsConstraintTimeline(frameCount, bezierCount, physicsConstraintIndex, Property_PhysicsConstraintWind) {};

    protected:
        float get(PhysicsConstraintPose &pose) override {
            return pose.getWind();
        }

        void set(PhysicsConstraintPose &pose, float value) override {
            pose.setWind(value);
        }

        bool global(PhysicsConstraintData &constraintData) override {
            return constraintData.getWindGlobal();
        }
    };

    /// Changes a physics constraint's PhysicsConstraintPose::getGravity().
    class SP_API PhysicsConstraintGravityTimeline : public PhysicsConstraintTimeline {
        friend class SkeletonBinary;

        friend class SkeletonJson;

    RTTI_DECL

    public:
        explicit PhysicsConstraintGravityTimeline(size_t frameCount, size_t bezierCount, int physicsConstraintIndex): PhysicsConstraintTimeline(frameCount, bezierCount, physicsConstraintIndex, Property_PhysicsConstraintGravity) {};

    protected:
        float get(PhysicsConstraintPose &pose) override {
            return pose.getGravity();
        }

        void set(PhysicsConstraintPose &pose, float value) override {
            pose.setGravity(value);
        }

        bool global(PhysicsConstraintData &constraintData) override {
            return constraintData.getGravityGlobal();
        }
    };

    /// Changes a physics constraint's PhysicsConstraintPose::getMix().
    class SP_API PhysicsConstraintMixTimeline : public PhysicsConstraintTimeline {
        friend class SkeletonBinary;

        friend class SkeletonJson;

    RTTI_DECL

    public:
        explicit PhysicsConstraintMixTimeline(size_t frameCount, size_t bezierCount, int physicsConstraintIndex): PhysicsConstraintTimeline(frameCount, bezierCount, physicsConstraintIndex, Property_PhysicsConstraintMix) {};

    protected:
        float get(PhysicsConstraintPose &pose) override {
            return pose.getMix();
        }

        void set(PhysicsConstraintPose &pose, float value) override {
            pose.setMix(value);
        }

        bool global(PhysicsConstraintData &constraintData) override {
            return constraintData.getMixGlobal();
        }
    };

    /// Resets a physics constraint when specific animation times are reached.
    class SP_API PhysicsConstraintResetTimeline : public Timeline, public ConstraintTimeline {
        friend class SkeletonBinary;

        friend class SkeletonJson;

    RTTI_DECL

    public:
        /// @param constraintIndex -1 for all physics constraints in the skeleton.
        explicit PhysicsConstraintResetTimeline(size_t frameCount, int constraintIndex): Timeline(frameCount, 1), ConstraintTimeline(constraintIndex) {
            PropertyId ids[] = {((PropertyId)Property_PhysicsConstraintReset) << 32};
            setPropertyIds(ids, 1);
        }

        virtual void
        apply(Skeleton &skeleton, float lastTime, float time, Vector<Event *> *pEvents, float alpha, MixBlend blend,
              MixDirection direction, bool appliedPose) override;

        int getFrameCount() { return (int)_frames.size(); }

        /// The index of the physics constraint in Skeleton::getConstraints() that will be reset when this timeline is
        /// applied, or -1 if all physics constraints in the skeleton will be reset.
        virtual int getConstraintIndex() override { return _constraintIndex; }

        /// Sets the time for the specified frame.
        void setFrame(int frame, float time) {
            _frames[frame] = time;
        }
    private:
        int _constraintIndex;
    };
}

#endif /* Spine_PhysicsConstraintTimeline_h */
