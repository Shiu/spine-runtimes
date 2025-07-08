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

#include "posed_generic.h"
#include <spine/spine.h>

using namespace spine;

spine_posed_generic spine_posed_generic_create(spine_d data) {
    PosedGeneric *obj = new (__FILE__, __LINE__) PosedGeneric(data);
    return (spine_posed_generic) obj;
}

void spine_posed_generic_dispose(spine_posed_generic obj) {
    if (!obj) return;
    delete (PosedGeneric *) obj;
}

void spine_posed_generic_setup_pose(spine_posed_generic obj) {
    if (!obj) return ;
    PosedGeneric *_obj = (PosedGeneric *) obj;
    _obj->setupPose();
}

spine_d spine_posed_generic_get_data(spine_posed_generic obj) {
    if (!obj) return nullptr;
    PosedGeneric *_obj = (PosedGeneric *) obj;
    return _obj->getData();
}

spine_p spine_posed_generic_get_pose(spine_posed_generic obj) {
    if (!obj) return nullptr;
    PosedGeneric *_obj = (PosedGeneric *) obj;
    return _obj->getPose();
}

spine_a spine_posed_generic_get_applied_pose(spine_posed_generic obj) {
    if (!obj) return nullptr;
    PosedGeneric *_obj = (PosedGeneric *) obj;
    return _obj->getAppliedPose();
}

void spine_posed_generic_reset_constrained(spine_posed_generic obj) {
    if (!obj) return ;
    PosedGeneric *_obj = (PosedGeneric *) obj;
    _obj->resetConstrained();
}

void spine_posed_generic_pose(spine_posed_generic obj) {
    if (!obj) return ;
    PosedGeneric *_obj = (PosedGeneric *) obj;
    _obj->pose();
}

void spine_posed_generic_constrained(spine_posed_generic obj) {
    if (!obj) return ;
    PosedGeneric *_obj = (PosedGeneric *) obj;
    _obj->constrained();
}

spine_bool spine_posed_generic_is_pose_equal_to_applied(spine_posed_generic obj) {
    if (!obj) return 0;
    PosedGeneric *_obj = (PosedGeneric *) obj;
    return _obj->isPoseEqualToApplied();
}
