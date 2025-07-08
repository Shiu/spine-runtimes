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

#include "path_attachment.h"
#include <spine/spine.h>

using namespace spine;

spine_path_attachment spine_path_attachment_create(const char* name) {
    PathAttachment *obj = new (__FILE__, __LINE__) PathAttachment(String(name));
    return (spine_path_attachment) obj;
}

void spine_path_attachment_dispose(spine_path_attachment obj) {
    if (!obj) return;
    delete (PathAttachment *) obj;
}

spine_rtti spine_path_attachment_get_rtti() {
    return (spine_rtti) &PathAttachment::rtti;
}

int32_t spine_path_attachment_get_num_lengths(spine_path_attachment obj) {
    if (!obj) return 0;
    PathAttachment *_obj = (PathAttachment *) obj;
    return (int32_t) _obj->getLengths().size();
}

float *spine_path_attachment_get_lengths(spine_path_attachment obj) {
    if (!obj) return nullptr;
    PathAttachment *_obj = (PathAttachment *) obj;
    return (float *) _obj->getLengths().buffer();
}

void spine_path_attachment_set_lengths(spine_path_attachment obj, spine_array_float value) {
    if (!obj) return;
    PathAttachment *_obj = (PathAttachment *) obj;
    _obj->setLengths((Array<float> &) value);
}

bool spine_path_attachment_is_closed(spine_path_attachment obj) {
    if (!obj) return false;
    PathAttachment *_obj = (PathAttachment *) obj;
    return _obj->isClosed();
}

void spine_path_attachment_set_closed(spine_path_attachment obj, bool value) {
    if (!obj) return;
    PathAttachment *_obj = (PathAttachment *) obj;
    _obj->setClosed(value);
}

bool spine_path_attachment_is_constant_speed(spine_path_attachment obj) {
    if (!obj) return false;
    PathAttachment *_obj = (PathAttachment *) obj;
    return _obj->isConstantSpeed();
}

void spine_path_attachment_set_constant_speed(spine_path_attachment obj, bool value) {
    if (!obj) return;
    PathAttachment *_obj = (PathAttachment *) obj;
    _obj->setConstantSpeed(value);
}

spine_color spine_path_attachment_get_color(spine_path_attachment obj) {
    if (!obj) return (spine_color) 0;
    PathAttachment *_obj = (PathAttachment *) obj;
    return (spine_color) &_obj->getColor();
}

spine_attachment spine_path_attachment_copy(spine_path_attachment obj) {
    if (!obj) return (spine_attachment) 0;
    PathAttachment *_obj = (PathAttachment *) obj;
    return (spine_attachment) _obj->copy();
}

void spine_path_attachment_compute_world_vertices(spine_path_attachment obj, spine_skeleton skeleton, spine_slot slot, size_t start, size_t count, float * worldVertices, size_t offset, size_t stride) {
    if (!obj) return ;
    PathAttachment *_obj = (PathAttachment *) obj;
    _obj->computeWorldVertices(*(Skeleton*) skeleton, *(Slot*) slot, start, count, (float *) worldVertices, offset, stride);
}

void spine_path_attachment_compute_world_vertices_7(spine_path_attachment obj, spine_skeleton skeleton, spine_slot slot, size_t start, size_t count, spine_array_float worldVertices, size_t offset, size_t stride) {
    if (!obj) return ;
    PathAttachment *_obj = (PathAttachment *) obj;
    _obj->computeWorldVertices(*(Skeleton*) skeleton, *(Slot*) slot, start, count, (Array<float> &) worldVertices, offset, stride);
}

int spine_path_attachment_get_id(spine_path_attachment obj) {
    if (!obj) return 0;
    PathAttachment *_obj = (PathAttachment *) obj;
    return _obj->getId();
}

int32_t spine_path_attachment_get_num_bones(spine_path_attachment obj) {
    if (!obj) return 0;
    PathAttachment *_obj = (PathAttachment *) obj;
    return (int32_t) _obj->getBones().size();
}

int *spine_path_attachment_get_bones(spine_path_attachment obj) {
    if (!obj) return nullptr;
    PathAttachment *_obj = (PathAttachment *) obj;
    return (int *) _obj->getBones().buffer();
}

void spine_path_attachment_set_bones(spine_path_attachment obj, spine_array_int value) {
    if (!obj) return;
    PathAttachment *_obj = (PathAttachment *) obj;
    _obj->setBones((Array<int> &) value);
}

int32_t spine_path_attachment_get_num_vertices(spine_path_attachment obj) {
    if (!obj) return 0;
    PathAttachment *_obj = (PathAttachment *) obj;
    return (int32_t) _obj->getVertices().size();
}

float *spine_path_attachment_get_vertices(spine_path_attachment obj) {
    if (!obj) return nullptr;
    PathAttachment *_obj = (PathAttachment *) obj;
    return (float *) _obj->getVertices().buffer();
}

void spine_path_attachment_set_vertices(spine_path_attachment obj, spine_array_float value) {
    if (!obj) return;
    PathAttachment *_obj = (PathAttachment *) obj;
    _obj->setVertices((Array<float> &) value);
}

size_t spine_path_attachment_get_world_vertices_length(spine_path_attachment obj) {
    if (!obj) return 0;
    PathAttachment *_obj = (PathAttachment *) obj;
    return _obj->getWorldVerticesLength();
}

void spine_path_attachment_set_world_vertices_length(spine_path_attachment obj, size_t value) {
    if (!obj) return;
    PathAttachment *_obj = (PathAttachment *) obj;
    _obj->setWorldVerticesLength(value);
}

spine_attachment spine_path_attachment_get_timeline_attachment(spine_path_attachment obj) {
    if (!obj) return (spine_attachment) 0;
    PathAttachment *_obj = (PathAttachment *) obj;
    return (spine_attachment) _obj->getTimelineAttachment();
}

void spine_path_attachment_set_timeline_attachment(spine_path_attachment obj, spine_attachment value) {
    if (!obj) return;
    PathAttachment *_obj = (PathAttachment *) obj;
    _obj->setTimelineAttachment((Attachment *) value);
}

void spine_path_attachment_copy_to(spine_path_attachment obj, spine_vertex_attachment other) {
    if (!obj) return ;
    PathAttachment *_obj = (PathAttachment *) obj;
    _obj->copyTo((VertexAttachment *) other);
}
