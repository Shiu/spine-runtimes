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

#ifndef Spine_PosedData_h
#define Spine_PosedData_h

#include <spine/SpineObject.h>
#include <spine/SpineString.h>

namespace spine {
    template<class P>
    class Pose;

    class SP_API PosedData : public SpineObject {
        friend class SkeletonBinary;
        friend class SkeletonJson;
        friend class BoneTimeline1;
        friend class BoneTimeline2;
        friend class RotateTimeline;
        friend class AttachmentTimeline;
        friend class RGBATimeline;
        friend class RGBTimeline;
        friend class AlphaTimeline;
        friend class RGBA2Timeline;
        friend class RGB2Timeline;
        friend class ScaleTimeline;
        friend class ScaleXTimeline;
        friend class ScaleYTimeline;
        friend class ShearTimeline;
        friend class ShearXTimeline;
        friend class ShearYTimeline;
        friend class TranslateTimeline;
        friend class TranslateXTimeline;
        friend class TranslateYTimeline;
        friend class InheritTimeline;
        friend class Skeleton;

    public:
        PosedData(const spine::String& name);
        virtual ~PosedData();

        /// The constraint's name, which is unique across all constraints in the skeleton of the same type.
        const spine::String& getName() const { return _name; };

        /// When true, Skeleton::updateWorldTransform(Physics) only updates this constraint if the Skeleton::getSkin()
        /// contains this constraint.
        ///
        /// See Skin::getConstraints().
        bool isSkinRequired() const { return _skinRequired; };
        void setSkinRequired(bool skinRequired) { _skinRequired = skinRequired; };

        protected:
            spine::String _name;
            bool _skinRequired;
    };

    inline PosedData::PosedData(const spine::String& name) : _name(name), _skinRequired(false) {
    }

    inline PosedData::~PosedData() {
    }

    /// The base class for all constrained datas.
    template<class P>
    class SP_API PosedDataGeneric : public PosedData {
        friend class SkeletonBinary;
        friend class SkeletonJson;
        friend class BoneTimeline1;
        friend class BoneTimeline2;
        friend class RotateTimeline;
        friend class AttachmentTimeline;
        friend class RGBATimeline;
        friend class RGBTimeline;
        friend class AlphaTimeline;
        friend class RGBA2Timeline;
        friend class RGB2Timeline;
        friend class ScaleTimeline;
        friend class ScaleXTimeline;
        friend class ScaleYTimeline;
        friend class ShearTimeline;
        friend class ShearXTimeline;
        friend class ShearYTimeline;
        friend class TranslateTimeline;
        friend class TranslateXTimeline;
        friend class TranslateYTimeline;
        friend class InheritTimeline;
        friend class PhysicsConstraintTimeline;
        friend class PhysicsConstraintInertiaTimeline;
        friend class PhysicsConstraintStrengthTimeline;
        friend class PhysicsConstraintDampingTimeline;
        friend class PhysicsConstraintMassTimeline;
        friend class PhysicsConstraintWindTimeline;
        friend class PhysicsConstraintGravityTimeline;

    protected:
        P _setup;

    public:
        PosedDataGeneric(const spine::String& name): PosedData(name), _setup() {
    }
        virtual ~PosedDataGeneric() {};

        P& getSetupPose() { return _setup; };
        const P& getSetupPose() const { return _setup; };
    };
}

#endif