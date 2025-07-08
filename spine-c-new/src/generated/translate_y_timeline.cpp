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

#include "translate_y_timeline.h"
#include <spine/spine.h>

using namespace spine;

spine_translate_y_timeline spine_translate_y_timeline_create(spine_size_t frameCount, spine_size_t bezierCount, int32_t boneIndex) {
    TranslateYTimeline *obj = new (__FILE__, __LINE__) TranslateYTimeline(frameCount, bezierCount, boneIndex);
    return (spine_translate_y_timeline) obj;
}

void spine_translate_y_timeline_dispose(spine_translate_y_timeline obj) {
    if (!obj) return;
    delete (TranslateYTimeline *) obj;
}

spine_rtti spine_translate_y_timeline_get_rtti(spine_translate_y_timeline obj) {
    if (!obj) return nullptr;
    TranslateYTimeline *_obj = (TranslateYTimeline *) obj;
    return (spine_rtti) &_obj->getRTTI();
}

void spine_translate_y_timeline_apply(spine_translate_y_timeline obj, spine_skeleton skeleton, float lastTime, float time, void * pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, spine_bool appliedPose) {
    if (!obj) return ;
    TranslateYTimeline *_obj = (TranslateYTimeline *) obj;
    _obj->apply(skeleton, lastTime, time, (Vector<Event *> *) pEvents, alpha, blend, direction, appliedPose);
}

void spine_translate_y_timeline_set_frame(spine_translate_y_timeline obj, spine_size_t frame, float time, float value) {
    if (!obj) return ;
    TranslateYTimeline *_obj = (TranslateYTimeline *) obj;
    _obj->setFrame(frame, time, value);
}

float spine_translate_y_timeline_get_curve_value(spine_translate_y_timeline obj, float time) {
    if (!obj) return 0;
    TranslateYTimeline *_obj = (TranslateYTimeline *) obj;
    return _obj->getCurveValue(time);
}

float spine_translate_y_timeline_get_relative_value(spine_translate_y_timeline obj, float time, float alpha, spine_mix_blend blend, float current, float setup) {
    if (!obj) return 0;
    TranslateYTimeline *_obj = (TranslateYTimeline *) obj;
    return _obj->getRelativeValue(time, alpha, blend, current, setup);
}

float spine_translate_y_timeline_get_absolute_value(spine_translate_y_timeline obj, float time, float alpha, spine_mix_blend blend, float current, float setup) {
    if (!obj) return 0;
    TranslateYTimeline *_obj = (TranslateYTimeline *) obj;
    return _obj->getAbsoluteValue(time, alpha, blend, current, setup);
}

float spine_translate_y_timeline_get_absolute_value(spine_translate_y_timeline obj, float time, float alpha, spine_mix_blend blend, float current, float setup, float value) {
    if (!obj) return 0;
    TranslateYTimeline *_obj = (TranslateYTimeline *) obj;
    return _obj->getAbsoluteValue(time, alpha, blend, current, setup, value);
}

float spine_translate_y_timeline_get_scale_value(spine_translate_y_timeline obj, float time, float alpha, spine_mix_blend blend, spine_mix_direction direction, float current, float setup) {
    if (!obj) return 0;
    TranslateYTimeline *_obj = (TranslateYTimeline *) obj;
    return _obj->getScaleValue(time, alpha, blend, direction, current, setup);
}

int32_t spine_translate_y_timeline_get_bone_index(spine_translate_y_timeline obj) {
    if (!obj) return 0;
    TranslateYTimeline *_obj = (TranslateYTimeline *) obj;
    return _obj->getBoneIndex();
}

void spine_translate_y_timeline_set_bone_index(spine_translate_y_timeline obj, int32_t value) {
    if (!obj) return;
    TranslateYTimeline *_obj = (TranslateYTimeline *) obj;
    _obj->setBoneIndex(value);
}
