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

#include "slider_data.h"
#include <spine/spine.h>

using namespace spine;

spine_slider_data spine_slider_data_create(const char* name) {
    SliderData *obj = new (__FILE__, __LINE__) SliderData(String(name));
    return (spine_slider_data) obj;
}

void spine_slider_data_dispose(spine_slider_data obj) {
    if (!obj) return;
    delete (SliderData *) obj;
}

spine_rtti spine_slider_data_get_rtti() {
    return (spine_rtti) &SliderData::rtti;
}

spine_constraint spine_slider_data_create(spine_slider_data obj, spine_skeleton skeleton) {
    if (!obj) return 0;
    SliderData *_obj = (SliderData *) obj;
    return (spine_constraint) _obj->create(*(Skeleton*) skeleton);
}

spine_animation spine_slider_data_get_animation(spine_slider_data obj) {
    if (!obj) return (spine_animation) 0;
    SliderData *_obj = (SliderData *) obj;
    return (spine_animation) _obj->getAnimation();
}

void spine_slider_data_set_animation(spine_slider_data obj, spine_animation value) {
    if (!obj) return;
    SliderData *_obj = (SliderData *) obj;
    _obj->setAnimation((Animation *) value);
}

bool spine_slider_data_get_additive(spine_slider_data obj) {
    if (!obj) return false;
    SliderData *_obj = (SliderData *) obj;
    return _obj->getAdditive();
}

void spine_slider_data_set_additive(spine_slider_data obj, bool value) {
    if (!obj) return;
    SliderData *_obj = (SliderData *) obj;
    _obj->setAdditive(value);
}

bool spine_slider_data_get_loop(spine_slider_data obj) {
    if (!obj) return false;
    SliderData *_obj = (SliderData *) obj;
    return _obj->getLoop();
}

void spine_slider_data_set_loop(spine_slider_data obj, bool value) {
    if (!obj) return;
    SliderData *_obj = (SliderData *) obj;
    _obj->setLoop(value);
}

spine_bone_data spine_slider_data_get_bone(spine_slider_data obj) {
    if (!obj) return (spine_bone_data) 0;
    SliderData *_obj = (SliderData *) obj;
    return (spine_bone_data) _obj->getBone();
}

void spine_slider_data_set_bone(spine_slider_data obj, spine_bone_data value) {
    if (!obj) return;
    SliderData *_obj = (SliderData *) obj;
    _obj->setBone((BoneData *) value);
}

spine_from_property spine_slider_data_get_property(spine_slider_data obj) {
    if (!obj) return (spine_from_property) 0;
    SliderData *_obj = (SliderData *) obj;
    return (spine_from_property) _obj->getProperty();
}

void spine_slider_data_set_property(spine_slider_data obj, spine_from_property value) {
    if (!obj) return;
    SliderData *_obj = (SliderData *) obj;
    _obj->setProperty((FromProperty *) value);
}

float spine_slider_data_get_scale(spine_slider_data obj) {
    if (!obj) return 0;
    SliderData *_obj = (SliderData *) obj;
    return _obj->getScale();
}

void spine_slider_data_set_scale(spine_slider_data obj, float value) {
    if (!obj) return;
    SliderData *_obj = (SliderData *) obj;
    _obj->setScale(value);
}

float spine_slider_data_get_offset(spine_slider_data obj) {
    if (!obj) return 0;
    SliderData *_obj = (SliderData *) obj;
    return _obj->getOffset();
}

void spine_slider_data_set_offset(spine_slider_data obj, float value) {
    if (!obj) return;
    SliderData *_obj = (SliderData *) obj;
    _obj->setOffset(value);
}

bool spine_slider_data_get_local(spine_slider_data obj) {
    if (!obj) return false;
    SliderData *_obj = (SliderData *) obj;
    return _obj->getLocal();
}

void spine_slider_data_set_local(spine_slider_data obj, bool value) {
    if (!obj) return;
    SliderData *_obj = (SliderData *) obj;
    _obj->setLocal(value);
}

const char* spine_slider_data_get_name(spine_slider_data obj) {
    if (!obj) return nullptr;
    SliderData *_obj = (SliderData *) obj;
    return (const char *) _obj->getName().buffer();
}

bool spine_slider_data_is_skin_required(spine_slider_data obj) {
    if (!obj) return false;
    SliderData *_obj = (SliderData *) obj;
    return _obj->isSkinRequired();
}

spine_slider_pose spine_slider_data_get_setup_pose(spine_slider_data obj) {
    if (!obj) return (spine_slider_pose) 0;
    SliderData *_obj = (SliderData *) obj;
    return (spine_slider_pose) &_obj->getSetupPose();
}
