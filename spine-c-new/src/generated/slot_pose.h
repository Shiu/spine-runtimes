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

#ifndef SPINE_C_SLOTPOSE_H
#define SPINE_C_SLOTPOSE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"

SPINE_C_EXPORT spine_slot_pose spine_slot_pose_create(void);
SPINE_C_EXPORT void spine_slot_pose_dispose(spine_slot_pose obj);
SPINE_C_EXPORT void spine_slot_pose_set(spine_slot_pose obj, spine_slot_pose value);
SPINE_C_EXPORT spine_color spine_slot_pose_get_color(spine_slot_pose obj);
SPINE_C_EXPORT spine_color spine_slot_pose_get_dark_color(spine_slot_pose obj);
SPINE_C_EXPORT bool spine_slot_pose_has_dark_color(spine_slot_pose obj);
SPINE_C_EXPORT void spine_slot_pose_set_has_dark_color(spine_slot_pose obj, bool value);
SPINE_C_EXPORT spine_attachment spine_slot_pose_get_attachment(spine_slot_pose obj);
SPINE_C_EXPORT void spine_slot_pose_set_attachment(spine_slot_pose obj, spine_attachment value);
SPINE_C_EXPORT int spine_slot_pose_get_sequence_index(spine_slot_pose obj);
SPINE_C_EXPORT void spine_slot_pose_set_sequence_index(spine_slot_pose obj, int value);
SPINE_C_EXPORT int32_t spine_slot_pose_get_num_deform(spine_slot_pose obj);
SPINE_C_EXPORT float *spine_slot_pose_get_deform(spine_slot_pose obj);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_SLOTPOSE_H