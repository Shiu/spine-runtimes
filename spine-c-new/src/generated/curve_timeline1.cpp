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

#include "curve_timeline1.h"
#include <spine/spine.h>

using namespace spine;

spine_curve_timeline1 spine_curve_timeline1_create(spine_size_t frameCount, spine_size_t bezierCount) {
    CurveTimeline1 *obj = new (__FILE__, __LINE__) CurveTimeline1(frameCount, bezierCount);
    return (spine_curve_timeline1) obj;
}

void spine_curve_timeline1_dispose(spine_curve_timeline1 obj) {
    if (!obj) return;
    delete (CurveTimeline1 *) obj;
}

spine_rtti spine_curve_timeline1_get_rtti(spine_curve_timeline1 obj) {
    if (!obj) return nullptr;
    CurveTimeline1 *_obj = (CurveTimeline1 *) obj;
    return (spine_rtti) &_obj->getRTTI();
}

void spine_curve_timeline1_set_frame(spine_curve_timeline1 obj, spine_size_t frame, float time, float value) {
    if (!obj) return ;
    CurveTimeline1 *_obj = (CurveTimeline1 *) obj;
    _obj->setFrame(frame, time, value);
}

float spine_curve_timeline1_get_curve_value(spine_curve_timeline1 obj, float time) {
    if (!obj) return 0;
    CurveTimeline1 *_obj = (CurveTimeline1 *) obj;
    return _obj->getCurveValue(time);
}

float spine_curve_timeline1_get_relative_value(spine_curve_timeline1 obj, float time, float alpha, spine_mix_blend blend, float current, float setup) {
    if (!obj) return 0;
    CurveTimeline1 *_obj = (CurveTimeline1 *) obj;
    return _obj->getRelativeValue(time, alpha, blend, current, setup);
}

float spine_curve_timeline1_get_absolute_value(spine_curve_timeline1 obj, float time, float alpha, spine_mix_blend blend, float current, float setup) {
    if (!obj) return 0;
    CurveTimeline1 *_obj = (CurveTimeline1 *) obj;
    return _obj->getAbsoluteValue(time, alpha, blend, current, setup);
}

float spine_curve_timeline1_get_absolute_value(spine_curve_timeline1 obj, float time, float alpha, spine_mix_blend blend, float current, float setup, float value) {
    if (!obj) return 0;
    CurveTimeline1 *_obj = (CurveTimeline1 *) obj;
    return _obj->getAbsoluteValue(time, alpha, blend, current, setup, value);
}

float spine_curve_timeline1_get_scale_value(spine_curve_timeline1 obj, float time, float alpha, spine_mix_blend blend, spine_mix_direction direction, float current, float setup) {
    if (!obj) return 0;
    CurveTimeline1 *_obj = (CurveTimeline1 *) obj;
    return _obj->getScaleValue(time, alpha, blend, direction, current, setup);
}

void spine_curve_timeline1_set_linear(spine_curve_timeline1 obj, spine_size_t value) {
    if (!obj) return;
    CurveTimeline1 *_obj = (CurveTimeline1 *) obj;
    _obj->setLinear(value);
}

void spine_curve_timeline1_set_stepped(spine_curve_timeline1 obj, spine_size_t value) {
    if (!obj) return;
    CurveTimeline1 *_obj = (CurveTimeline1 *) obj;
    _obj->setStepped(value);
}

void spine_curve_timeline1_set_bezier(spine_curve_timeline1 obj, spine_size_t bezier, spine_size_t frame, float value, float time1, float value1, float cx1, float cy1, float cx2, float cy2, float time2, float value2) {
    if (!obj) return ;
    CurveTimeline1 *_obj = (CurveTimeline1 *) obj;
    _obj->setBezier(bezier, frame, value, time1, value1, cx1, cy1, cx2, cy2, time2, value2);
}

float spine_curve_timeline1_get_bezier_value(spine_curve_timeline1 obj, float time, spine_size_t frame, spine_size_t valueOffset, spine_size_t i) {
    if (!obj) return 0;
    CurveTimeline1 *_obj = (CurveTimeline1 *) obj;
    return _obj->getBezierValue(time, frame, valueOffset, i);
}

void * spine_curve_timeline1_get_curves(spine_curve_timeline1 obj) {
    if (!obj) return nullptr;
    CurveTimeline1 *_obj = (CurveTimeline1 *) obj;
    return _obj->getCurves();
}

int32_t spine_curve_timeline1_get_num_curves(spine_curve_timeline1 obj) {
    if (!obj) return 0;
    CurveTimeline1 *_obj = (CurveTimeline1 *) obj;
    return (int32_t) _obj->getCurves().size();
}

spine_float *spine_curve_timeline1_get_curves(spine_curve_timeline1 obj) {
    if (!obj) return nullptr;
    CurveTimeline1 *_obj = (CurveTimeline1 *) obj;
    return (spine_float *) _obj->getCurves().buffer();
}

void spine_curve_timeline1_apply(spine_curve_timeline1 obj, spine_skeleton skeleton, float lastTime, float time, void * pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, spine_bool appliedPose) {
    if (!obj) return ;
    CurveTimeline1 *_obj = (CurveTimeline1 *) obj;
    _obj->apply(skeleton, lastTime, time, (Vector<Event *> *) pEvents, alpha, blend, direction, appliedPose);
}

spine_size_t spine_curve_timeline1_get_frame_entries(spine_curve_timeline1 obj) {
    if (!obj) return nullptr;
    CurveTimeline1 *_obj = (CurveTimeline1 *) obj;
    return _obj->getFrameEntries();
}

spine_size_t spine_curve_timeline1_get_frame_count(spine_curve_timeline1 obj) {
    if (!obj) return nullptr;
    CurveTimeline1 *_obj = (CurveTimeline1 *) obj;
    return _obj->getFrameCount();
}

void * spine_curve_timeline1_get_frames(spine_curve_timeline1 obj) {
    if (!obj) return nullptr;
    CurveTimeline1 *_obj = (CurveTimeline1 *) obj;
    return _obj->getFrames();
}

int32_t spine_curve_timeline1_get_num_frames(spine_curve_timeline1 obj) {
    if (!obj) return 0;
    CurveTimeline1 *_obj = (CurveTimeline1 *) obj;
    return (int32_t) _obj->getFrames().size();
}

spine_float *spine_curve_timeline1_get_frames(spine_curve_timeline1 obj) {
    if (!obj) return nullptr;
    CurveTimeline1 *_obj = (CurveTimeline1 *) obj;
    return (spine_float *) _obj->getFrames().buffer();
}

float spine_curve_timeline1_get_duration(spine_curve_timeline1 obj) {
    if (!obj) return 0;
    CurveTimeline1 *_obj = (CurveTimeline1 *) obj;
    return _obj->getDuration();
}

void * spine_curve_timeline1_get_property_ids(spine_curve_timeline1 obj) {
    if (!obj) return nullptr;
    CurveTimeline1 *_obj = (CurveTimeline1 *) obj;
    return _obj->getPropertyIds();
}

int32_t spine_curve_timeline1_get_num_property_ids(spine_curve_timeline1 obj) {
    if (!obj) return 0;
    CurveTimeline1 *_obj = (CurveTimeline1 *) obj;
    return (int32_t) _obj->getPropertyIds().size();
}

spine_property_id *spine_curve_timeline1_get_property_ids(spine_curve_timeline1 obj) {
    if (!obj) return nullptr;
    CurveTimeline1 *_obj = (CurveTimeline1 *) obj;
    return (spine_property_id *) _obj->getPropertyIds().buffer();
}
