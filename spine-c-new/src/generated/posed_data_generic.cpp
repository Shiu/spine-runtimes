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

#include "posed_data_generic.h"
#include <spine/spine.h>

using namespace spine;

spine_posed_data_generic spine_posed_data_generic_create(spine_spine::string name) {
    PosedDataGeneric *obj = new (__FILE__, __LINE__) PosedDataGeneric(name);
    return (spine_posed_data_generic) obj;
}

void spine_posed_data_generic_dispose(spine_posed_data_generic obj) {
    if (!obj) return;
    delete (PosedDataGeneric *) obj;
}

spine_p spine_posed_data_generic_get_setup_pose(spine_posed_data_generic obj) {
    if (!obj) return nullptr;
    PosedDataGeneric *_obj = (PosedDataGeneric *) obj;
    return _obj->getSetupPose();
}

spine_p spine_posed_data_generic_get_setup_pose(spine_posed_data_generic obj) {
    if (!obj) return nullptr;
    PosedDataGeneric *_obj = (PosedDataGeneric *) obj;
    return _obj->getSetupPose();
}

spine_spine::string spine_posed_data_generic_get_name(spine_posed_data_generic obj) {
    if (!obj) return nullptr;
    PosedDataGeneric *_obj = (PosedDataGeneric *) obj;
    return _obj->getName();
}

spine_bool spine_posed_data_generic_is_skin_required(spine_posed_data_generic obj) {
    if (!obj) return 0;
    PosedDataGeneric *_obj = (PosedDataGeneric *) obj;
    return _obj->isSkinRequired();
}

void spine_posed_data_generic_set_skin_required(spine_posed_data_generic obj, spine_bool value) {
    if (!obj) return;
    PosedDataGeneric *_obj = (PosedDataGeneric *) obj;
    _obj->setSkinRequired(value);
}
