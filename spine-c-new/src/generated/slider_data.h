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

#ifndef SPINE_C_SLIDERDATA_H
#define SPINE_C_SLIDERDATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"

SPINE_C_EXPORT spine_slider_data spine_slider_data_create(const char* name);
SPINE_C_EXPORT void spine_slider_data_dispose(spine_slider_data obj);
SPINE_C_EXPORT spine_rtti spine_slider_data_get_rtti();
SPINE_C_EXPORT spine_constraint spine_slider_data_create(spine_slider_data obj, spine_skeleton skeleton);
SPINE_C_EXPORT spine_animation spine_slider_data_get_animation(spine_slider_data obj);
SPINE_C_EXPORT void spine_slider_data_set_animation(spine_slider_data obj, spine_animation value);
SPINE_C_EXPORT bool spine_slider_data_get_additive(spine_slider_data obj);
SPINE_C_EXPORT void spine_slider_data_set_additive(spine_slider_data obj, bool value);
SPINE_C_EXPORT bool spine_slider_data_get_loop(spine_slider_data obj);
SPINE_C_EXPORT void spine_slider_data_set_loop(spine_slider_data obj, bool value);
SPINE_C_EXPORT spine_bone_data spine_slider_data_get_bone(spine_slider_data obj);
SPINE_C_EXPORT void spine_slider_data_set_bone(spine_slider_data obj, spine_bone_data value);
SPINE_C_EXPORT spine_from_property spine_slider_data_get_property(spine_slider_data obj);
SPINE_C_EXPORT void spine_slider_data_set_property(spine_slider_data obj, spine_from_property value);
SPINE_C_EXPORT float spine_slider_data_get_scale(spine_slider_data obj);
SPINE_C_EXPORT void spine_slider_data_set_scale(spine_slider_data obj, float value);
SPINE_C_EXPORT float spine_slider_data_get_offset(spine_slider_data obj);
SPINE_C_EXPORT void spine_slider_data_set_offset(spine_slider_data obj, float value);
SPINE_C_EXPORT bool spine_slider_data_get_local(spine_slider_data obj);
SPINE_C_EXPORT void spine_slider_data_set_local(spine_slider_data obj, bool value);
SPINE_C_EXPORT const char* spine_slider_data_get_name(spine_slider_data obj);
SPINE_C_EXPORT bool spine_slider_data_is_skin_required(spine_slider_data obj);
SPINE_C_EXPORT spine_slider_pose spine_slider_data_get_setup_pose(spine_slider_data obj);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_SLIDERDATA_H