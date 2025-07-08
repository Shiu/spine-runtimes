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

#include "slider.h"
#include <spine/spine.h>

using namespace spine;

spine_slider spine_slider_create(spine_slider_data data, spine_skeleton skeleton) {
    Slider *obj = new (__FILE__, __LINE__) Slider(*(SliderData*) data, *(Skeleton*) skeleton);
    return (spine_slider) obj;
}

void spine_slider_dispose(spine_slider obj) {
    if (!obj) return;
    delete (Slider *) obj;
}

spine_rtti spine_slider_get_rtti() {
    return (spine_rtti) &Slider::rtti;
}

spine_slider spine_slider_copy(spine_slider obj, spine_skeleton skeleton) {
    if (!obj) return (spine_slider) 0;
    Slider *_obj = (Slider *) obj;
    return (spine_slider) _obj->copy(*(Skeleton*) skeleton);
}

void spine_slider_update(spine_slider obj, spine_skeleton skeleton, spine_physics physics) {
    if (!obj) return ;
    Slider *_obj = (Slider *) obj;
    _obj->update(*(Skeleton*) skeleton, (Physics) physics);
}

void spine_slider_sort(spine_slider obj, spine_skeleton skeleton) {
    if (!obj) return ;
    Slider *_obj = (Slider *) obj;
    _obj->sort(*(Skeleton*) skeleton);
}

bool spine_slider_is_source_active(spine_slider obj) {
    if (!obj) return false;
    Slider *_obj = (Slider *) obj;
    return _obj->isSourceActive();
}

spine_bone spine_slider_get_bone(spine_slider obj) {
    if (!obj) return (spine_bone) 0;
    Slider *_obj = (Slider *) obj;
    return (spine_bone) _obj->getBone();
}

void spine_slider_set_bone(spine_slider obj, spine_bone value) {
    if (!obj) return;
    Slider *_obj = (Slider *) obj;
    _obj->setBone((Bone *) value);
}

spine_constraint_data spine_slider_get_data(spine_slider obj) {
    if (!obj) return 0;
    Slider *_obj = (Slider *) obj;
    return (spine_constraint_data) &_obj->getData();
}

void spine_slider_pose(spine_slider obj) {
    if (!obj) return ;
    Slider *_obj = (Slider *) obj;
    _obj->pose();
}

void spine_slider_setup_pose(spine_slider obj) {
    if (!obj) return ;
    Slider *_obj = (Slider *) obj;
    _obj->setupPose();
}

spine_slider_pose spine_slider_get_pose(spine_slider obj) {
    if (!obj) return (spine_slider_pose) 0;
    Slider *_obj = (Slider *) obj;
    return (spine_slider_pose) &_obj->getPose();
}

spine_slider_pose spine_slider_get_applied_pose(spine_slider obj) {
    if (!obj) return (spine_slider_pose) 0;
    Slider *_obj = (Slider *) obj;
    return (spine_slider_pose) &_obj->getAppliedPose();
}

void spine_slider_reset_constrained(spine_slider obj) {
    if (!obj) return ;
    Slider *_obj = (Slider *) obj;
    _obj->resetConstrained();
}

void spine_slider_constrained(spine_slider obj) {
    if (!obj) return ;
    Slider *_obj = (Slider *) obj;
    _obj->constrained();
}

bool spine_slider_is_pose_equal_to_applied(spine_slider obj) {
    if (!obj) return false;
    Slider *_obj = (Slider *) obj;
    return _obj->isPoseEqualToApplied();
}

bool spine_slider_is_active(spine_slider obj) {
    if (!obj) return false;
    Slider *_obj = (Slider *) obj;
    return _obj->isActive();
}

void spine_slider_set_active(spine_slider obj, bool value) {
    if (!obj) return;
    Slider *_obj = (Slider *) obj;
    _obj->setActive(value);
}
