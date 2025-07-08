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

#include "bone_timeline1.h"
#include <spine/spine.h>

using namespace spine;

spine_bone_timeline1 spine_bone_timeline1_create(size_t frameCount, size_t bezierCount, int boneIndex, spine_property property) {
    BoneTimeline1 *obj = new (__FILE__, __LINE__) BoneTimeline1(frameCount, bezierCount, boneIndex, property);
    return (spine_bone_timeline1) obj;
}

void spine_bone_timeline1_dispose(spine_bone_timeline1 obj) {
    if (!obj) return;
    delete (BoneTimeline1 *) obj;
}

spine_rtti spine_bone_timeline1_get_rtti() {
    return (spine_rtti) &BoneTimeline1::rtti;
}

void spine_bone_timeline1_apply(spine_bone_timeline1 obj, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    if (!obj) return ;
    BoneTimeline1 *_obj = (BoneTimeline1 *) obj;
    _obj->apply(*(Skeleton*) skeleton, lastTime, time, (Array<Event *> *) pEvents, alpha, (MixBlend) blend, (MixDirection) direction, appliedPose);
}

void spine_bone_timeline1_set_frame(spine_bone_timeline1 obj, size_t frame, float time, float value) {
    if (!obj) return ;
    BoneTimeline1 *_obj = (BoneTimeline1 *) obj;
    _obj->setFrame(frame, time, value);
}

float spine_bone_timeline1_get_curve_value(spine_bone_timeline1 obj, float time) {
    if (!obj) return 0;
    BoneTimeline1 *_obj = (BoneTimeline1 *) obj;
    return _obj->getCurveValue(time);
}

float spine_bone_timeline1_get_relative_value(spine_bone_timeline1 obj, float time, float alpha, spine_mix_blend blend, float current, float setup) {
    if (!obj) return 0;
    BoneTimeline1 *_obj = (BoneTimeline1 *) obj;
    return _obj->getRelativeValue(time, alpha, (MixBlend) blend, current, setup);
}

float spine_bone_timeline1_get_absolute_value(spine_bone_timeline1 obj, float time, float alpha, spine_mix_blend blend, float current, float setup) {
    if (!obj) return 0;
    BoneTimeline1 *_obj = (BoneTimeline1 *) obj;
    return _obj->getAbsoluteValue(time, alpha, (MixBlend) blend, current, setup);
}

float spine_bone_timeline1_get_absolute_value_6(spine_bone_timeline1 obj, float time, float alpha, spine_mix_blend blend, float current, float setup, float value) {
    if (!obj) return 0;
    BoneTimeline1 *_obj = (BoneTimeline1 *) obj;
    return _obj->getAbsoluteValue(time, alpha, (MixBlend) blend, current, setup, value);
}

float spine_bone_timeline1_get_scale_value(spine_bone_timeline1 obj, float time, float alpha, spine_mix_blend blend, spine_mix_direction direction, float current, float setup) {
    if (!obj) return 0;
    BoneTimeline1 *_obj = (BoneTimeline1 *) obj;
    return _obj->getScaleValue(time, alpha, (MixBlend) blend, (MixDirection) direction, current, setup);
}

int spine_bone_timeline1_get_bone_index(spine_bone_timeline1 obj) {
    if (!obj) return 0;
    BoneTimeline1 *_obj = (BoneTimeline1 *) obj;
    return _obj->getBoneIndex();
}

void spine_bone_timeline1_set_bone_index(spine_bone_timeline1 obj, int value) {
    if (!obj) return;
    BoneTimeline1 *_obj = (BoneTimeline1 *) obj;
    _obj->setBoneIndex(value);
}
