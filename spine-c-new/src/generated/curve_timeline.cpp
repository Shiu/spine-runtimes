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

#include "curve_timeline.h"
#include <spine/spine.h>

using namespace spine;

void spine_curve_timeline_dispose(spine_curve_timeline obj) {
    if (!obj) return;
    delete (CurveTimeline *) obj;
}

spine_rtti spine_curve_timeline_get_rtti() {
    return (spine_rtti) &CurveTimeline::rtti;
}

void spine_curve_timeline_set_linear(spine_curve_timeline obj, size_t value) {
    if (!obj) return;
    CurveTimeline *_obj = (CurveTimeline *) obj;
    _obj->setLinear(value);
}

void spine_curve_timeline_set_stepped(spine_curve_timeline obj, size_t value) {
    if (!obj) return;
    CurveTimeline *_obj = (CurveTimeline *) obj;
    _obj->setStepped(value);
}

void spine_curve_timeline_set_bezier(spine_curve_timeline obj, size_t bezier, size_t frame, float value, float time1, float value1, float cx1, float cy1, float cx2, float cy2, float time2, float value2) {
    if (!obj) return ;
    CurveTimeline *_obj = (CurveTimeline *) obj;
    _obj->setBezier(bezier, frame, value, time1, value1, cx1, cy1, cx2, cy2, time2, value2);
}

float spine_curve_timeline_get_bezier_value(spine_curve_timeline obj, float time, size_t frame, size_t valueOffset, size_t i) {
    if (!obj) return 0;
    CurveTimeline *_obj = (CurveTimeline *) obj;
    return _obj->getBezierValue(time, frame, valueOffset, i);
}

int32_t spine_curve_timeline_get_num_curves(spine_curve_timeline obj) {
    if (!obj) return 0;
    CurveTimeline *_obj = (CurveTimeline *) obj;
    return (int32_t) _obj->getCurves().size();
}

float *spine_curve_timeline_get_curves(spine_curve_timeline obj) {
    if (!obj) return nullptr;
    CurveTimeline *_obj = (CurveTimeline *) obj;
    return (float *) _obj->getCurves().buffer();
}

void spine_curve_timeline_apply(spine_curve_timeline obj, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    if (!obj) return ;
    CurveTimeline *_obj = (CurveTimeline *) obj;
    _obj->apply(*(Skeleton*) skeleton, lastTime, time, (Array<Event *> *) pEvents, alpha, (MixBlend) blend, (MixDirection) direction, appliedPose);
}

size_t spine_curve_timeline_get_frame_entries(spine_curve_timeline obj) {
    if (!obj) return 0;
    CurveTimeline *_obj = (CurveTimeline *) obj;
    return _obj->getFrameEntries();
}

size_t spine_curve_timeline_get_frame_count(spine_curve_timeline obj) {
    if (!obj) return 0;
    CurveTimeline *_obj = (CurveTimeline *) obj;
    return _obj->getFrameCount();
}

int32_t spine_curve_timeline_get_num_frames(spine_curve_timeline obj) {
    if (!obj) return 0;
    CurveTimeline *_obj = (CurveTimeline *) obj;
    return (int32_t) _obj->getFrames().size();
}

float *spine_curve_timeline_get_frames(spine_curve_timeline obj) {
    if (!obj) return nullptr;
    CurveTimeline *_obj = (CurveTimeline *) obj;
    return (float *) _obj->getFrames().buffer();
}

float spine_curve_timeline_get_duration(spine_curve_timeline obj) {
    if (!obj) return 0;
    CurveTimeline *_obj = (CurveTimeline *) obj;
    return _obj->getDuration();
}

int32_t spine_curve_timeline_get_num_property_ids(spine_curve_timeline obj) {
    if (!obj) return 0;
    CurveTimeline *_obj = (CurveTimeline *) obj;
    return (int32_t) _obj->getPropertyIds().size();
}

int64_t *spine_curve_timeline_get_property_ids(spine_curve_timeline obj) {
    if (!obj) return nullptr;
    CurveTimeline *_obj = (CurveTimeline *) obj;
    return (int64_t *) _obj->getPropertyIds().buffer();
}
