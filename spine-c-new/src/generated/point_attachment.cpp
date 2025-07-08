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

#include "point_attachment.h"
#include <spine/spine.h>

using namespace spine;

spine_point_attachment spine_point_attachment_create(const char* name) {
    PointAttachment *obj = new (__FILE__, __LINE__) PointAttachment(String(name));
    return (spine_point_attachment) obj;
}

void spine_point_attachment_dispose(spine_point_attachment obj) {
    if (!obj) return;
    delete (PointAttachment *) obj;
}

spine_rtti spine_point_attachment_get_rtti() {
    return (spine_rtti) &PointAttachment::rtti;
}

float spine_point_attachment_get_x(spine_point_attachment obj) {
    if (!obj) return 0;
    PointAttachment *_obj = (PointAttachment *) obj;
    return _obj->getX();
}

void spine_point_attachment_set_x(spine_point_attachment obj, float value) {
    if (!obj) return;
    PointAttachment *_obj = (PointAttachment *) obj;
    _obj->setX(value);
}

float spine_point_attachment_get_y(spine_point_attachment obj) {
    if (!obj) return 0;
    PointAttachment *_obj = (PointAttachment *) obj;
    return _obj->getY();
}

void spine_point_attachment_set_y(spine_point_attachment obj, float value) {
    if (!obj) return;
    PointAttachment *_obj = (PointAttachment *) obj;
    _obj->setY(value);
}

float spine_point_attachment_get_rotation(spine_point_attachment obj) {
    if (!obj) return 0;
    PointAttachment *_obj = (PointAttachment *) obj;
    return _obj->getRotation();
}

void spine_point_attachment_set_rotation(spine_point_attachment obj, float value) {
    if (!obj) return;
    PointAttachment *_obj = (PointAttachment *) obj;
    _obj->setRotation(value);
}

spine_color spine_point_attachment_get_color(spine_point_attachment obj) {
    if (!obj) return (spine_color) 0;
    PointAttachment *_obj = (PointAttachment *) obj;
    return (spine_color) &_obj->getColor();
}

void spine_point_attachment_compute_world_position(spine_point_attachment obj, spine_bone_pose bone, float* ox, float* oy) {
    if (!obj) return ;
    PointAttachment *_obj = (PointAttachment *) obj;
    _obj->computeWorldPosition(*(BonePose*) bone, *ox, *oy);
}

float spine_point_attachment_compute_world_rotation(spine_point_attachment obj, spine_bone_pose bone) {
    if (!obj) return 0;
    PointAttachment *_obj = (PointAttachment *) obj;
    return _obj->computeWorldRotation(*(BonePose*) bone);
}

spine_attachment spine_point_attachment_copy(spine_point_attachment obj) {
    if (!obj) return (spine_attachment) 0;
    PointAttachment *_obj = (PointAttachment *) obj;
    return (spine_attachment) _obj->copy();
}

const char* spine_point_attachment_get_name(spine_point_attachment obj) {
    if (!obj) return nullptr;
    PointAttachment *_obj = (PointAttachment *) obj;
    return (const char *) _obj->getName().buffer();
}

int spine_point_attachment_get_ref_count(spine_point_attachment obj) {
    if (!obj) return 0;
    PointAttachment *_obj = (PointAttachment *) obj;
    return _obj->getRefCount();
}

void spine_point_attachment_reference(spine_point_attachment obj) {
    if (!obj) return ;
    PointAttachment *_obj = (PointAttachment *) obj;
    _obj->reference();
}

void spine_point_attachment_dereference(spine_point_attachment obj) {
    if (!obj) return ;
    PointAttachment *_obj = (PointAttachment *) obj;
    _obj->dereference();
}
