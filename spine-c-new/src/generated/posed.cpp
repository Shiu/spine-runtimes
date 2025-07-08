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

#include "posed.h"
#include <spine/spine.h>

using namespace spine;

spine_posed spine_posed_create(void) {
    Posed *obj = new (__FILE__, __LINE__) Posed();
    return (spine_posed) obj;
}

void spine_posed_dispose(spine_posed obj) {
    if (!obj) return;
    delete (Posed *) obj;
}

void spine_posed_setup_pose(spine_posed obj) {
    if (!obj) return ;
    Posed *_obj = (Posed *) obj;
    _obj->setupPose();
}

void spine_posed_pose(spine_posed obj) {
    if (!obj) return ;
    Posed *_obj = (Posed *) obj;
    _obj->pose();
}

void spine_posed_constrained(spine_posed obj) {
    if (!obj) return ;
    Posed *_obj = (Posed *) obj;
    _obj->constrained();
}

void spine_posed_reset_constrained(spine_posed obj) {
    if (!obj) return ;
    Posed *_obj = (Posed *) obj;
    _obj->resetConstrained();
}

spine_bool spine_posed_is_pose_equal_to_applied(spine_posed obj) {
    if (!obj) return 0;
    Posed *_obj = (Posed *) obj;
    return _obj->isPoseEqualToApplied();
}

spine_bool spine_posed_is_type(spine_posed obj, spine_posed_type type) {
    if (!obj) return 0;
    Posed *_obj = (Posed *) obj;
    
    switch (type) {
        case SPINE_TYPE_POSED_POSED_GENERIC:
            return _obj->getRTTI().instanceOf(PosedGeneric::rtti);
    }
    return 0;
}

spine_posed_generic spine_posed_as_posed_generic(spine_posed obj) {
    if (!obj) return nullptr;
    Posed *_obj = (Posed *) obj;
    if (!_obj->getRTTI().instanceOf(PosedGeneric::rtti)) return nullptr;
    return (spine_posed_generic) obj;
}
