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

#include "scale_timeline.h"
#include <spine/spine.h>

using namespace spine;

spine_scale_timeline spine_scale_timeline_create(spine_size_t frameCount, spine_size_t bezierCount, int32_t boneIndex) {
    ScaleTimeline *obj = new (__FILE__, __LINE__) ScaleTimeline(frameCount, bezierCount, boneIndex);
    return (spine_scale_timeline) obj;
}

void spine_scale_timeline_dispose(spine_scale_timeline obj) {
    if (!obj) return;
    delete (ScaleTimeline *) obj;
}

spine_rtti spine_scale_timeline_get_rtti(spine_scale_timeline obj) {
    if (!obj) return nullptr;
    ScaleTimeline *_obj = (ScaleTimeline *) obj;
    return (spine_rtti) &_obj->getRTTI();
}

void spine_scale_timeline_apply(spine_scale_timeline obj, spine_skeleton skeleton, float lastTime, float time, void * pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, spine_bool appliedPose) {
    if (!obj) return ;
    ScaleTimeline *_obj = (ScaleTimeline *) obj;
    _obj->apply(skeleton, lastTime, time, (Vector<Event *> *) pEvents, alpha, blend, direction, appliedPose);
}

void spine_scale_timeline_set_frame(spine_scale_timeline obj, spine_size_t frame, float time, float value1, float value2) {
    if (!obj) return ;
    ScaleTimeline *_obj = (ScaleTimeline *) obj;
    _obj->setFrame(frame, time, value1, value2);
}

float spine_scale_timeline_get_curve_value(spine_scale_timeline obj, float time) {
    if (!obj) return 0;
    ScaleTimeline *_obj = (ScaleTimeline *) obj;
    return _obj->getCurveValue(time);
}

int32_t spine_scale_timeline_get_bone_index(spine_scale_timeline obj) {
    if (!obj) return 0;
    ScaleTimeline *_obj = (ScaleTimeline *) obj;
    return _obj->getBoneIndex();
}

void spine_scale_timeline_set_bone_index(spine_scale_timeline obj, int32_t value) {
    if (!obj) return;
    ScaleTimeline *_obj = (ScaleTimeline *) obj;
    _obj->setBoneIndex(value);
}
