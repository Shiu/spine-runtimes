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

#ifndef SPINE_C_POSEDDATA_H
#define SPINE_C_POSEDDATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "../custom.h"

SPINE_OPAQUE_TYPE(spine_posed_data)

SPINE_C_EXPORT spine_posed_data spine_posed_data_create(spine_spine::string name);
SPINE_C_EXPORT void spine_posed_data_dispose(spine_posed_data obj);
SPINE_C_EXPORT spine_spine::string spine_posed_data_get_name(spine_posed_data obj);
SPINE_C_EXPORT spine_bool spine_posed_data_is_skin_required(spine_posed_data obj);
SPINE_C_EXPORT void spine_posed_data_set_skin_required(spine_posed_data obj, spine_bool value);
struct spine_posed_data_generic_wrapper;
typedef struct spine_posed_data_generic_wrapper *spine_posed_data_generic;

typedef enum spine_posed_data_type {
    SPINE_TYPE_POSED_DATA_POSED_DATA_GENERIC = 0
} spine_posed_data_type;

SPINE_C_EXPORT spine_bool spine_posed_data_is_type(spine_posed_data obj, spine_posed_data_type type);
SPINE_C_EXPORT spine_posed_data_generic spine_posed_data_as_posed_data_generic(spine_posed_data obj);

#ifdef __cplusplus
}
#endif

#endif // SPINE_C_POSEDDATA_H