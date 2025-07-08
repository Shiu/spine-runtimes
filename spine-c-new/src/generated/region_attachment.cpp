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

#include "region_attachment.h"
#include <spine/spine.h>

using namespace spine;

spine_region_attachment spine_region_attachment_create(const char* name) {
    RegionAttachment *obj = new (__FILE__, __LINE__) RegionAttachment(String(name));
    return (spine_region_attachment) obj;
}

void spine_region_attachment_dispose(spine_region_attachment obj) {
    if (!obj) return;
    delete (RegionAttachment *) obj;
}

spine_rtti spine_region_attachment_get_rtti() {
    return (spine_rtti) &RegionAttachment::rtti;
}

void spine_region_attachment_update_region(spine_region_attachment obj) {
    if (!obj) return ;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    _obj->updateRegion();
}

void spine_region_attachment_compute_world_vertices(spine_region_attachment obj, spine_slot slot, float * worldVertices, size_t offset, size_t stride) {
    if (!obj) return ;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    _obj->computeWorldVertices(*(Slot*) slot, (float *) worldVertices, offset, stride);
}

void spine_region_attachment_compute_world_vertices_4(spine_region_attachment obj, spine_slot slot, spine_array_float worldVertices, size_t offset, size_t stride) {
    if (!obj) return ;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    _obj->computeWorldVertices(*(Slot*) slot, (Array<float> &) worldVertices, offset, stride);
}

float spine_region_attachment_get_x(spine_region_attachment obj) {
    if (!obj) return 0;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    return _obj->getX();
}

void spine_region_attachment_set_x(spine_region_attachment obj, float value) {
    if (!obj) return;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    _obj->setX(value);
}

float spine_region_attachment_get_y(spine_region_attachment obj) {
    if (!obj) return 0;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    return _obj->getY();
}

void spine_region_attachment_set_y(spine_region_attachment obj, float value) {
    if (!obj) return;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    _obj->setY(value);
}

float spine_region_attachment_get_rotation(spine_region_attachment obj) {
    if (!obj) return 0;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    return _obj->getRotation();
}

void spine_region_attachment_set_rotation(spine_region_attachment obj, float value) {
    if (!obj) return;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    _obj->setRotation(value);
}

float spine_region_attachment_get_scale_x(spine_region_attachment obj) {
    if (!obj) return 0;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    return _obj->getScaleX();
}

void spine_region_attachment_set_scale_x(spine_region_attachment obj, float value) {
    if (!obj) return;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    _obj->setScaleX(value);
}

float spine_region_attachment_get_scale_y(spine_region_attachment obj) {
    if (!obj) return 0;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    return _obj->getScaleY();
}

void spine_region_attachment_set_scale_y(spine_region_attachment obj, float value) {
    if (!obj) return;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    _obj->setScaleY(value);
}

float spine_region_attachment_get_width(spine_region_attachment obj) {
    if (!obj) return 0;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    return _obj->getWidth();
}

void spine_region_attachment_set_width(spine_region_attachment obj, float value) {
    if (!obj) return;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    _obj->setWidth(value);
}

float spine_region_attachment_get_height(spine_region_attachment obj) {
    if (!obj) return 0;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    return _obj->getHeight();
}

void spine_region_attachment_set_height(spine_region_attachment obj, float value) {
    if (!obj) return;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    _obj->setHeight(value);
}

spine_color spine_region_attachment_get_color(spine_region_attachment obj) {
    if (!obj) return (spine_color) 0;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    return (spine_color) &_obj->getColor();
}

const char* spine_region_attachment_get_path(spine_region_attachment obj) {
    if (!obj) return nullptr;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    return (const char *) _obj->getPath().buffer();
}

void spine_region_attachment_set_path(spine_region_attachment obj, const char* value) {
    if (!obj) return;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    _obj->setPath(String(value));
}

spine_texture_region spine_region_attachment_get_region(spine_region_attachment obj) {
    if (!obj) return (spine_texture_region) 0;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    return (spine_texture_region) _obj->getRegion();
}

void spine_region_attachment_set_region(spine_region_attachment obj, spine_texture_region value) {
    if (!obj) return;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    _obj->setRegion((TextureRegion *) value);
}

spine_sequence spine_region_attachment_get_sequence(spine_region_attachment obj) {
    if (!obj) return (spine_sequence) 0;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    return (spine_sequence) _obj->getSequence();
}

void spine_region_attachment_set_sequence(spine_region_attachment obj, spine_sequence value) {
    if (!obj) return;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    _obj->setSequence((Sequence *) value);
}

int32_t spine_region_attachment_get_num_offset(spine_region_attachment obj) {
    if (!obj) return 0;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    return (int32_t) _obj->getOffset().size();
}

float *spine_region_attachment_get_offset(spine_region_attachment obj) {
    if (!obj) return nullptr;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    return (float *) _obj->getOffset().buffer();
}

int32_t spine_region_attachment_get_num_u_vs(spine_region_attachment obj) {
    if (!obj) return 0;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    return (int32_t) _obj->getUVs().size();
}

float *spine_region_attachment_get_u_vs(spine_region_attachment obj) {
    if (!obj) return nullptr;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    return (float *) _obj->getUVs().buffer();
}

spine_attachment spine_region_attachment_copy(spine_region_attachment obj) {
    if (!obj) return (spine_attachment) 0;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    return (spine_attachment) _obj->copy();
}

const char* spine_region_attachment_get_name(spine_region_attachment obj) {
    if (!obj) return nullptr;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    return (const char *) _obj->getName().buffer();
}

int spine_region_attachment_get_ref_count(spine_region_attachment obj) {
    if (!obj) return 0;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    return _obj->getRefCount();
}

void spine_region_attachment_reference(spine_region_attachment obj) {
    if (!obj) return ;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    _obj->reference();
}

void spine_region_attachment_dereference(spine_region_attachment obj) {
    if (!obj) return ;
    RegionAttachment *_obj = (RegionAttachment *) obj;
    _obj->dereference();
}
