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

#ifndef SPINE_C_POSED_H
#define SPINE_C_POSED_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../custom.h"

SPINE_OPAQUE_TYPE(spine_posed)

SPINE_C_EXPORT spine_posed spine_posed_create(void);
SPINE_C_EXPORT void spine_posed_dispose(spine_posed obj);
SPINE_C_EXPORT void spine_posed_setup_pose(spine_posed obj);
SPINE_C_EXPORT void spine_posed_pose(spine_posed obj);
SPINE_C_EXPORT void spine_posed_constrained(spine_posed obj);
SPINE_C_EXPORT void spine_posed_reset_constrained(spine_posed obj);
SPINE_C_EXPORT spine_bool spine_posed_is_pose_equal_to_applied(spine_posed obj);
struct spine_posed_generic_wrapper;
typedef struct spine_posed_generic_wrapper *spine_posed_generic;

typedef enum spine_posed_type {
    SPINE_TYPE_POSED_POSED_GENERIC = 0
} spine_posed_type;

SPINE_C_EXPORT spine_bool spine_posed_is_type(spine_posed obj, spine_posed_type type);
SPINE_C_EXPORT spine_posed_generic spine_posed_as_posed_generic(spine_posed obj);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_POSED_H