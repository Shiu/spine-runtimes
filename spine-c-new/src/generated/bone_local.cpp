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

#include "bone_local.h"
#include <spine/spine.h>

using namespace spine;

spine_bone_local spine_bone_local_create(void) {
    BoneLocal *obj = new (__FILE__, __LINE__) BoneLocal();
    return (spine_bone_local) obj;
}

void spine_bone_local_dispose(spine_bone_local obj) {
    if (!obj) return;
    delete (BoneLocal *) obj;
}

void spine_bone_local_set(spine_bone_local obj, spine_bone_local value) {
    if (!obj) return;
    BoneLocal *_obj = (BoneLocal *) obj;
    _obj->set(*((BoneLocal*) value));
}

float spine_bone_local_get_x(spine_bone_local obj) {
    if (!obj) return 0;
    BoneLocal *_obj = (BoneLocal *) obj;
    return _obj->getX();
}

void spine_bone_local_set_x(spine_bone_local obj, float value) {
    if (!obj) return;
    BoneLocal *_obj = (BoneLocal *) obj;
    _obj->setX(value);
}

float spine_bone_local_get_y(spine_bone_local obj) {
    if (!obj) return 0;
    BoneLocal *_obj = (BoneLocal *) obj;
    return _obj->getY();
}

void spine_bone_local_set_y(spine_bone_local obj, float value) {
    if (!obj) return;
    BoneLocal *_obj = (BoneLocal *) obj;
    _obj->setY(value);
}

void spine_bone_local_set_position(spine_bone_local obj, float x, float y) {
    if (!obj) return ;
    BoneLocal *_obj = (BoneLocal *) obj;
    _obj->setPosition(x, y);
}

float spine_bone_local_get_rotation(spine_bone_local obj) {
    if (!obj) return 0;
    BoneLocal *_obj = (BoneLocal *) obj;
    return _obj->getRotation();
}

void spine_bone_local_set_rotation(spine_bone_local obj, float value) {
    if (!obj) return;
    BoneLocal *_obj = (BoneLocal *) obj;
    _obj->setRotation(value);
}

float spine_bone_local_get_scale_x(spine_bone_local obj) {
    if (!obj) return 0;
    BoneLocal *_obj = (BoneLocal *) obj;
    return _obj->getScaleX();
}

void spine_bone_local_set_scale_x(spine_bone_local obj, float value) {
    if (!obj) return;
    BoneLocal *_obj = (BoneLocal *) obj;
    _obj->setScaleX(value);
}

float spine_bone_local_get_scale_y(spine_bone_local obj) {
    if (!obj) return 0;
    BoneLocal *_obj = (BoneLocal *) obj;
    return _obj->getScaleY();
}

void spine_bone_local_set_scale_y(spine_bone_local obj, float value) {
    if (!obj) return;
    BoneLocal *_obj = (BoneLocal *) obj;
    _obj->setScaleY(value);
}

void spine_bone_local_set_scale(spine_bone_local obj, float scaleX, float scaleY) {
    if (!obj) return ;
    BoneLocal *_obj = (BoneLocal *) obj;
    _obj->setScale(scaleX, scaleY);
}

void spine_bone_local_set_scale(spine_bone_local obj, float value) {
    if (!obj) return;
    BoneLocal *_obj = (BoneLocal *) obj;
    _obj->setScale(value);
}

float spine_bone_local_get_shear_x(spine_bone_local obj) {
    if (!obj) return 0;
    BoneLocal *_obj = (BoneLocal *) obj;
    return _obj->getShearX();
}

void spine_bone_local_set_shear_x(spine_bone_local obj, float value) {
    if (!obj) return;
    BoneLocal *_obj = (BoneLocal *) obj;
    _obj->setShearX(value);
}

float spine_bone_local_get_shear_y(spine_bone_local obj) {
    if (!obj) return 0;
    BoneLocal *_obj = (BoneLocal *) obj;
    return _obj->getShearY();
}

void spine_bone_local_set_shear_y(spine_bone_local obj, float value) {
    if (!obj) return;
    BoneLocal *_obj = (BoneLocal *) obj;
    _obj->setShearY(value);
}

spine_inherit spine_bone_local_get_inherit(spine_bone_local obj) {
    if (!obj) return (spine_inherit) 0;
    BoneLocal *_obj = (BoneLocal *) obj;
    return (spine_inherit) _obj->getInherit();
}

void spine_bone_local_set_inherit(spine_bone_local obj, spine_inherit value) {
    if (!obj) return;
    BoneLocal *_obj = (BoneLocal *) obj;
    _obj->setInherit((Inherit) value);
}
