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

#include "posed_data.h"
#include <spine/spine.h>

using namespace spine;

spine_posed_data spine_posed_data_create(spine_spine::string name) {
    PosedData *obj = new (__FILE__, __LINE__) PosedData(name);
    return (spine_posed_data) obj;
}

void spine_posed_data_dispose(spine_posed_data obj) {
    if (!obj) return;
    delete (PosedData *) obj;
}

spine_spine::string spine_posed_data_get_name(spine_posed_data obj) {
    if (!obj) return nullptr;
    PosedData *_obj = (PosedData *) obj;
    return _obj->getName();
}

spine_bool spine_posed_data_is_skin_required(spine_posed_data obj) {
    if (!obj) return 0;
    PosedData *_obj = (PosedData *) obj;
    return _obj->isSkinRequired();
}

void spine_posed_data_set_skin_required(spine_posed_data obj, spine_bool value) {
    if (!obj) return;
    PosedData *_obj = (PosedData *) obj;
    _obj->setSkinRequired(value);
}

spine_bool spine_posed_data_is_type(spine_posed_data obj, spine_posed_data_type type) {
    if (!obj) return 0;
    PosedData *_obj = (PosedData *) obj;
    
    switch (type) {
        case SPINE_TYPE_POSED_DATA_POSED_DATA_GENERIC:
            return _obj->getRTTI().instanceOf(PosedDataGeneric::rtti);
    }
    return 0;
}

spine_posed_data_generic spine_posed_data_as_posed_data_generic(spine_posed_data obj) {
    if (!obj) return nullptr;
    PosedData *_obj = (PosedData *) obj;
    if (!_obj->getRTTI().instanceOf(PosedDataGeneric::rtti)) return nullptr;
    return (spine_posed_data_generic) obj;
}
