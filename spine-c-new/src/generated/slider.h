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

#ifndef SPINE_C_SLIDER_H
#define SPINE_C_SLIDER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"

SPINE_C_EXPORT spine_slider spine_slider_create(spine_slider_data data, spine_skeleton skeleton);
SPINE_C_EXPORT void spine_slider_dispose(spine_slider obj);
SPINE_C_EXPORT spine_rtti spine_slider_get_rtti();
SPINE_C_EXPORT spine_slider spine_slider_copy(spine_slider obj, spine_skeleton skeleton);
SPINE_C_EXPORT void spine_slider_update(spine_slider obj, spine_skeleton skeleton, spine_physics physics);
SPINE_C_EXPORT void spine_slider_sort(spine_slider obj, spine_skeleton skeleton);
SPINE_C_EXPORT bool spine_slider_is_source_active(spine_slider obj);
SPINE_C_EXPORT spine_bone spine_slider_get_bone(spine_slider obj);
SPINE_C_EXPORT void spine_slider_set_bone(spine_slider obj, spine_bone value);
SPINE_C_EXPORT spine_constraint_data spine_slider_get_data(spine_slider obj);
SPINE_C_EXPORT void spine_slider_pose(spine_slider obj);
SPINE_C_EXPORT void spine_slider_setup_pose(spine_slider obj);
SPINE_C_EXPORT spine_slider_pose spine_slider_get_pose(spine_slider obj);
SPINE_C_EXPORT spine_slider_pose spine_slider_get_applied_pose(spine_slider obj);
SPINE_C_EXPORT void spine_slider_reset_constrained(spine_slider obj);
SPINE_C_EXPORT void spine_slider_constrained(spine_slider obj);
SPINE_C_EXPORT bool spine_slider_is_pose_equal_to_applied(spine_slider obj);
SPINE_C_EXPORT bool spine_slider_is_active(spine_slider obj);
SPINE_C_EXPORT void spine_slider_set_active(spine_slider obj, bool value);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_SLIDER_H