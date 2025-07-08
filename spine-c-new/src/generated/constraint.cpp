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

#include "constraint.h"
#include <spine/spine.h>

using namespace spine;

spine_constraint spine_constraint_create(void) {
    Constraint *obj = new (__FILE__, __LINE__) Constraint();
    return (spine_constraint) obj;
}

void spine_constraint_dispose(spine_constraint obj) {
    if (!obj) return;
    delete (Constraint *) obj;
}

spine_rtti spine_constraint_get_rtti(spine_constraint obj) {
    if (!obj) return nullptr;
    Constraint *_obj = (Constraint *) obj;
    return (spine_rtti) &_obj->getRTTI();
}

spine_constraint_data spine_constraint_get_data(spine_constraint obj) {
    if (!obj) return 0;
    Constraint *_obj = (Constraint *) obj;
    return _obj->getData();
}

void spine_constraint_sort(spine_constraint obj, spine_skeleton skeleton) {
    if (!obj) return ;
    Constraint *_obj = (Constraint *) obj;
    _obj->sort(skeleton);
}

spine_bool spine_constraint_is_source_active(spine_constraint obj) {
    if (!obj) return 0;
    Constraint *_obj = (Constraint *) obj;
    return _obj->isSourceActive();
}

void spine_constraint_pose(spine_constraint obj) {
    if (!obj) return ;
    Constraint *_obj = (Constraint *) obj;
    _obj->pose();
}

void spine_constraint_setup_pose(spine_constraint obj) {
    if (!obj) return ;
    Constraint *_obj = (Constraint *) obj;
    _obj->setupPose();
}

void spine_constraint_update(spine_constraint obj, spine_skeleton skeleton, spine_physics physics) {
    if (!obj) return ;
    Constraint *_obj = (Constraint *) obj;
    _obj->update(skeleton, physics);
}

spine_bool spine_constraint_is_type(spine_constraint obj, spine_constraint_type type) {
    if (!obj) return 0;
    Constraint *_obj = (Constraint *) obj;
    
    switch (type) {
        case SPINE_TYPE_CONSTRAINT_CONSTRAINT_GENERIC:
            return _obj->getRTTI().instanceOf(ConstraintGeneric::rtti);
    }
    return 0;
}

spine_constraint_generic spine_constraint_as_constraint_generic(spine_constraint obj) {
    if (!obj) return nullptr;
    Constraint *_obj = (Constraint *) obj;
    if (!_obj->getRTTI().instanceOf(ConstraintGeneric::rtti)) return nullptr;
    return (spine_constraint_generic) obj;
}
