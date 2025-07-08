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

#include "vertex_attachment.h"
#include <spine/spine.h>

using namespace spine;

void spine_vertex_attachment_dispose(spine_vertex_attachment obj) {
    if (!obj) return;
    delete (VertexAttachment *) obj;
}

spine_rtti spine_vertex_attachment_get_rtti() {
    return (spine_rtti) &VertexAttachment::rtti;
}

void spine_vertex_attachment_compute_world_vertices(spine_vertex_attachment obj, spine_skeleton skeleton, spine_slot slot, size_t start, size_t count, float * worldVertices, size_t offset, size_t stride) {
    if (!obj) return ;
    VertexAttachment *_obj = (VertexAttachment *) obj;
    _obj->computeWorldVertices(*(Skeleton*) skeleton, *(Slot*) slot, start, count, (float *) worldVertices, offset, stride);
}

void spine_vertex_attachment_compute_world_vertices_7(spine_vertex_attachment obj, spine_skeleton skeleton, spine_slot slot, size_t start, size_t count, spine_array_float worldVertices, size_t offset, size_t stride) {
    if (!obj) return ;
    VertexAttachment *_obj = (VertexAttachment *) obj;
    _obj->computeWorldVertices(*(Skeleton*) skeleton, *(Slot*) slot, start, count, (Array<float> &) worldVertices, offset, stride);
}

int spine_vertex_attachment_get_id(spine_vertex_attachment obj) {
    if (!obj) return 0;
    VertexAttachment *_obj = (VertexAttachment *) obj;
    return _obj->getId();
}

int32_t spine_vertex_attachment_get_num_bones(spine_vertex_attachment obj) {
    if (!obj) return 0;
    VertexAttachment *_obj = (VertexAttachment *) obj;
    return (int32_t) _obj->getBones().size();
}

int *spine_vertex_attachment_get_bones(spine_vertex_attachment obj) {
    if (!obj) return nullptr;
    VertexAttachment *_obj = (VertexAttachment *) obj;
    return (int *) _obj->getBones().buffer();
}

void spine_vertex_attachment_set_bones(spine_vertex_attachment obj, spine_array_int value) {
    if (!obj) return;
    VertexAttachment *_obj = (VertexAttachment *) obj;
    _obj->setBones((Array<int> &) value);
}

int32_t spine_vertex_attachment_get_num_vertices(spine_vertex_attachment obj) {
    if (!obj) return 0;
    VertexAttachment *_obj = (VertexAttachment *) obj;
    return (int32_t) _obj->getVertices().size();
}

float *spine_vertex_attachment_get_vertices(spine_vertex_attachment obj) {
    if (!obj) return nullptr;
    VertexAttachment *_obj = (VertexAttachment *) obj;
    return (float *) _obj->getVertices().buffer();
}

void spine_vertex_attachment_set_vertices(spine_vertex_attachment obj, spine_array_float value) {
    if (!obj) return;
    VertexAttachment *_obj = (VertexAttachment *) obj;
    _obj->setVertices((Array<float> &) value);
}

size_t spine_vertex_attachment_get_world_vertices_length(spine_vertex_attachment obj) {
    if (!obj) return 0;
    VertexAttachment *_obj = (VertexAttachment *) obj;
    return _obj->getWorldVerticesLength();
}

void spine_vertex_attachment_set_world_vertices_length(spine_vertex_attachment obj, size_t value) {
    if (!obj) return;
    VertexAttachment *_obj = (VertexAttachment *) obj;
    _obj->setWorldVerticesLength(value);
}

spine_attachment spine_vertex_attachment_get_timeline_attachment(spine_vertex_attachment obj) {
    if (!obj) return (spine_attachment) 0;
    VertexAttachment *_obj = (VertexAttachment *) obj;
    return (spine_attachment) _obj->getTimelineAttachment();
}

void spine_vertex_attachment_set_timeline_attachment(spine_vertex_attachment obj, spine_attachment value) {
    if (!obj) return;
    VertexAttachment *_obj = (VertexAttachment *) obj;
    _obj->setTimelineAttachment((Attachment *) value);
}

void spine_vertex_attachment_copy_to(spine_vertex_attachment obj, spine_vertex_attachment other) {
    if (!obj) return ;
    VertexAttachment *_obj = (VertexAttachment *) obj;
    _obj->copyTo((VertexAttachment *) other);
}

const char* spine_vertex_attachment_get_name(spine_vertex_attachment obj) {
    if (!obj) return nullptr;
    VertexAttachment *_obj = (VertexAttachment *) obj;
    return (const char *) _obj->getName().buffer();
}

spine_attachment spine_vertex_attachment_copy(spine_vertex_attachment obj) {
    if (!obj) return (spine_attachment) 0;
    VertexAttachment *_obj = (VertexAttachment *) obj;
    return (spine_attachment) _obj->copy();
}

int spine_vertex_attachment_get_ref_count(spine_vertex_attachment obj) {
    if (!obj) return 0;
    VertexAttachment *_obj = (VertexAttachment *) obj;
    return _obj->getRefCount();
}

void spine_vertex_attachment_reference(spine_vertex_attachment obj) {
    if (!obj) return ;
    VertexAttachment *_obj = (VertexAttachment *) obj;
    _obj->reference();
}

void spine_vertex_attachment_dereference(spine_vertex_attachment obj) {
    if (!obj) return ;
    VertexAttachment *_obj = (VertexAttachment *) obj;
    _obj->dereference();
}
