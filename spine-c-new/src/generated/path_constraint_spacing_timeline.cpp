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

#include "path_constraint_spacing_timeline.h"
#include <spine/spine.h>

using namespace spine;

spine_path_constraint_spacing_timeline spine_path_constraint_spacing_timeline_create(size_t frameCount, size_t bezierCount, int constraintIndex) {
    PathConstraintSpacingTimeline *obj = new (__FILE__, __LINE__) PathConstraintSpacingTimeline(frameCount, bezierCount, constraintIndex);
    return (spine_path_constraint_spacing_timeline) obj;
}

void spine_path_constraint_spacing_timeline_dispose(spine_path_constraint_spacing_timeline obj) {
    if (!obj) return;
    delete (PathConstraintSpacingTimeline *) obj;
}

spine_rtti spine_path_constraint_spacing_timeline_get_rtti() {
    return (spine_rtti) &PathConstraintSpacingTimeline::rtti;
}

void spine_path_constraint_spacing_timeline_apply(spine_path_constraint_spacing_timeline obj, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    if (!obj) return ;
    PathConstraintSpacingTimeline *_obj = (PathConstraintSpacingTimeline *) obj;
    _obj->apply(*(Skeleton*) skeleton, lastTime, time, (Array<Event *> *) pEvents, alpha, (MixBlend) blend, (MixDirection) direction, appliedPose);
}

void spine_path_constraint_spacing_timeline_set_frame(spine_path_constraint_spacing_timeline obj, size_t frame, float time, float value) {
    if (!obj) return ;
    PathConstraintSpacingTimeline *_obj = (PathConstraintSpacingTimeline *) obj;
    _obj->setFrame(frame, time, value);
}

float spine_path_constraint_spacing_timeline_get_curve_value(spine_path_constraint_spacing_timeline obj, float time) {
    if (!obj) return 0;
    PathConstraintSpacingTimeline *_obj = (PathConstraintSpacingTimeline *) obj;
    return _obj->getCurveValue(time);
}

float spine_path_constraint_spacing_timeline_get_relative_value(spine_path_constraint_spacing_timeline obj, float time, float alpha, spine_mix_blend blend, float current, float setup) {
    if (!obj) return 0;
    PathConstraintSpacingTimeline *_obj = (PathConstraintSpacingTimeline *) obj;
    return _obj->getRelativeValue(time, alpha, (MixBlend) blend, current, setup);
}

float spine_path_constraint_spacing_timeline_get_absolute_value(spine_path_constraint_spacing_timeline obj, float time, float alpha, spine_mix_blend blend, float current, float setup) {
    if (!obj) return 0;
    PathConstraintSpacingTimeline *_obj = (PathConstraintSpacingTimeline *) obj;
    return _obj->getAbsoluteValue(time, alpha, (MixBlend) blend, current, setup);
}

float spine_path_constraint_spacing_timeline_get_absolute_value_6(spine_path_constraint_spacing_timeline obj, float time, float alpha, spine_mix_blend blend, float current, float setup, float value) {
    if (!obj) return 0;
    PathConstraintSpacingTimeline *_obj = (PathConstraintSpacingTimeline *) obj;
    return _obj->getAbsoluteValue(time, alpha, (MixBlend) blend, current, setup, value);
}

float spine_path_constraint_spacing_timeline_get_scale_value(spine_path_constraint_spacing_timeline obj, float time, float alpha, spine_mix_blend blend, spine_mix_direction direction, float current, float setup) {
    if (!obj) return 0;
    PathConstraintSpacingTimeline *_obj = (PathConstraintSpacingTimeline *) obj;
    return _obj->getScaleValue(time, alpha, (MixBlend) blend, (MixDirection) direction, current, setup);
}

int spine_path_constraint_spacing_timeline_get_constraint_index(spine_path_constraint_spacing_timeline obj) {
    if (!obj) return 0;
    PathConstraintSpacingTimeline *_obj = (PathConstraintSpacingTimeline *) obj;
    return _obj->getConstraintIndex();
}

void spine_path_constraint_spacing_timeline_set_constraint_index(spine_path_constraint_spacing_timeline obj, int value) {
    if (!obj) return;
    PathConstraintSpacingTimeline *_obj = (PathConstraintSpacingTimeline *) obj;
    _obj->setConstraintIndex(value);
}
