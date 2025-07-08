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

#ifndef SPINE_C_DEFORMTIMELINE_H
#define SPINE_C_DEFORMTIMELINE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"

SPINE_C_EXPORT spine_deform_timeline spine_deform_timeline_create(size_t frameCount, size_t bezierCount, int slotIndex, spine_vertex_attachment attachment);
SPINE_C_EXPORT void spine_deform_timeline_dispose(spine_deform_timeline obj);
SPINE_C_EXPORT spine_rtti spine_deform_timeline_get_rtti();
SPINE_C_EXPORT void spine_deform_timeline_set_frame(spine_deform_timeline obj, int frameIndex, float time, spine_array_float vertices);
SPINE_C_EXPORT int32_t spine_deform_timeline_get_num_vertices(spine_deform_timeline obj);
SPINE_C_EXPORT spine_array<float *spine_deform_timeline_get_vertices(spine_deform_timeline obj);
SPINE_C_EXPORT spine_vertex_attachment spine_deform_timeline_get_attachment(spine_deform_timeline obj);
SPINE_C_EXPORT void spine_deform_timeline_set_attachment(spine_deform_timeline obj, spine_vertex_attachment value);
SPINE_C_EXPORT void spine_deform_timeline_set_bezier(spine_deform_timeline obj, size_t bezier, size_t frame, float value, float time1, float value1, float cx1, float cy1, float cx2, float cy2, float time2, float value2);
SPINE_C_EXPORT float spine_deform_timeline_get_curve_percent(spine_deform_timeline obj, float time, int frame);
SPINE_C_EXPORT size_t spine_deform_timeline_get_frame_count(spine_deform_timeline obj);
SPINE_C_EXPORT void spine_deform_timeline_apply(spine_deform_timeline obj, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_DEFORMTIMELINE_H