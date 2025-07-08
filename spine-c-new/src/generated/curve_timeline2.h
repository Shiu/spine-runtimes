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

#ifndef SPINE_C_CURVETIMELINE2_H
#define SPINE_C_CURVETIMELINE2_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../custom.h"

SPINE_OPAQUE_TYPE(spine_curve_timeline2)

SPINE_C_EXPORT spine_curve_timeline2 spine_curve_timeline2_create(spine_size_t frameCount, spine_size_t bezierCount);
SPINE_C_EXPORT void spine_curve_timeline2_dispose(spine_curve_timeline2 obj);
SPINE_C_EXPORT spine_rtti spine_curve_timeline2_get_rtti(spine_curve_timeline2 obj);
SPINE_C_EXPORT void spine_curve_timeline2_set_frame(spine_curve_timeline2 obj, spine_size_t frame, float time, float value1, float value2);
SPINE_C_EXPORT float spine_curve_timeline2_get_curve_value(spine_curve_timeline2 obj, float time);
SPINE_C_EXPORT void spine_curve_timeline2_set_linear(spine_curve_timeline2 obj, spine_size_t value);
SPINE_C_EXPORT void spine_curve_timeline2_set_stepped(spine_curve_timeline2 obj, spine_size_t value);
SPINE_C_EXPORT void spine_curve_timeline2_set_bezier(spine_curve_timeline2 obj, spine_size_t bezier, spine_size_t frame, float value, float time1, float value1, float cx1, float cy1, float cx2, float cy2, float time2, float value2);
SPINE_C_EXPORT float spine_curve_timeline2_get_bezier_value(spine_curve_timeline2 obj, float time, spine_size_t frame, spine_size_t valueOffset, spine_size_t i);
SPINE_C_EXPORT void * spine_curve_timeline2_get_curves(spine_curve_timeline2 obj);
SPINE_C_EXPORT int32_t spine_curve_timeline2_get_num_curves(spine_curve_timeline2 obj);
SPINE_C_EXPORT spine_float *spine_curve_timeline2_get_curves(spine_curve_timeline2 obj);
SPINE_C_EXPORT void spine_curve_timeline2_apply(spine_curve_timeline2 obj, spine_skeleton skeleton, float lastTime, float time, void * pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, spine_bool appliedPose);
SPINE_C_EXPORT spine_size_t spine_curve_timeline2_get_frame_entries(spine_curve_timeline2 obj);
SPINE_C_EXPORT spine_size_t spine_curve_timeline2_get_frame_count(spine_curve_timeline2 obj);
SPINE_C_EXPORT void * spine_curve_timeline2_get_frames(spine_curve_timeline2 obj);
SPINE_C_EXPORT int32_t spine_curve_timeline2_get_num_frames(spine_curve_timeline2 obj);
SPINE_C_EXPORT spine_float *spine_curve_timeline2_get_frames(spine_curve_timeline2 obj);
SPINE_C_EXPORT float spine_curve_timeline2_get_duration(spine_curve_timeline2 obj);
SPINE_C_EXPORT void * spine_curve_timeline2_get_property_ids(spine_curve_timeline2 obj);
SPINE_C_EXPORT int32_t spine_curve_timeline2_get_num_property_ids(spine_curve_timeline2 obj);
SPINE_C_EXPORT spine_property_id *spine_curve_timeline2_get_property_ids(spine_curve_timeline2 obj);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_CURVETIMELINE2_H