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

#include "bounding_box_attachment.h"
#include <spine/spine.h>

using namespace spine;

spine_bounding_box_attachment spine_bounding_box_attachment_create(const utf8 * name) {
    BoundingBoxAttachment *obj = new (__FILE__, __LINE__) BoundingBoxAttachment(String(name));
    return (spine_bounding_box_attachment) obj;
}

void spine_bounding_box_attachment_dispose(spine_bounding_box_attachment obj) {
    if (!obj) return;
    delete (BoundingBoxAttachment *) obj;
}

spine_rtti spine_bounding_box_attachment_get_rtti(spine_bounding_box_attachment obj) {
    if (!obj) return nullptr;
    BoundingBoxAttachment *_obj = (BoundingBoxAttachment *) obj;
    return (spine_rtti) &_obj->getRTTI();
}

spine_color spine_bounding_box_attachment_get_color(spine_bounding_box_attachment obj) {
    if (!obj) return nullptr;
    BoundingBoxAttachment *_obj = (BoundingBoxAttachment *) obj;
    return (spine_color) &_obj->getColor();
}

spine_attachment spine_bounding_box_attachment_copy(spine_bounding_box_attachment obj) {
    if (!obj) return nullptr;
    BoundingBoxAttachment *_obj = (BoundingBoxAttachment *) obj;
    return (spine_attachment) _obj->copy();
}

void spine_bounding_box_attachment_compute_world_vertices(spine_bounding_box_attachment obj, spine_skeleton skeleton, spine_slot slot, spine_size_t start, spine_size_t count, spine_float worldVertices, spine_size_t offset, spine_size_t stride) {
    if (!obj) return ;
    BoundingBoxAttachment *_obj = (BoundingBoxAttachment *) obj;
    _obj->computeWorldVertices(skeleton, slot, start, count, (float *) worldVertices, offset, stride);
}

void spine_bounding_box_attachment_compute_world_vertices(spine_bounding_box_attachment obj, spine_skeleton skeleton, spine_slot slot, spine_size_t start, spine_size_t count, void * worldVertices, spine_size_t offset, spine_size_t stride) {
    if (!obj) return ;
    BoundingBoxAttachment *_obj = (BoundingBoxAttachment *) obj;
    _obj->computeWorldVertices(skeleton, slot, start, count, (Vector<float> &) worldVertices, offset, stride);
}

int32_t spine_bounding_box_attachment_get_id(spine_bounding_box_attachment obj) {
    if (!obj) return 0;
    BoundingBoxAttachment *_obj = (BoundingBoxAttachment *) obj;
    return _obj->getId();
}

int32_t * spine_bounding_box_attachment_get_bones(spine_bounding_box_attachment obj) {
    if (!obj) return 0;
    BoundingBoxAttachment *_obj = (BoundingBoxAttachment *) obj;
    return _obj->getBones();
}

int32_t spine_bounding_box_attachment_get_num_bones(spine_bounding_box_attachment obj) {
    if (!obj) return 0;
    BoundingBoxAttachment *_obj = (BoundingBoxAttachment *) obj;
    return (int32_t) _obj->getBones().size();
}

int32_t *spine_bounding_box_attachment_get_bones(spine_bounding_box_attachment obj) {
    if (!obj) return nullptr;
    BoundingBoxAttachment *_obj = (BoundingBoxAttachment *) obj;
    return (int32_t *) _obj->getBones().buffer();
}

void spine_bounding_box_attachment_set_bones(spine_bounding_box_attachment obj, int32_t * value) {
    if (!obj) return;
    BoundingBoxAttachment *_obj = (BoundingBoxAttachment *) obj;
    _obj->setBones((Vector<int> &) value);
}

void * spine_bounding_box_attachment_get_vertices(spine_bounding_box_attachment obj) {
    if (!obj) return nullptr;
    BoundingBoxAttachment *_obj = (BoundingBoxAttachment *) obj;
    return _obj->getVertices();
}

int32_t spine_bounding_box_attachment_get_num_vertices(spine_bounding_box_attachment obj) {
    if (!obj) return 0;
    BoundingBoxAttachment *_obj = (BoundingBoxAttachment *) obj;
    return (int32_t) _obj->getVertices().size();
}

spine_float *spine_bounding_box_attachment_get_vertices(spine_bounding_box_attachment obj) {
    if (!obj) return nullptr;
    BoundingBoxAttachment *_obj = (BoundingBoxAttachment *) obj;
    return (spine_float *) _obj->getVertices().buffer();
}

void spine_bounding_box_attachment_set_vertices(spine_bounding_box_attachment obj, void * value) {
    if (!obj) return;
    BoundingBoxAttachment *_obj = (BoundingBoxAttachment *) obj;
    _obj->setVertices((Vector<float> &) value);
}

spine_size_t spine_bounding_box_attachment_get_world_vertices_length(spine_bounding_box_attachment obj) {
    if (!obj) return nullptr;
    BoundingBoxAttachment *_obj = (BoundingBoxAttachment *) obj;
    return _obj->getWorldVerticesLength();
}

void spine_bounding_box_attachment_set_world_vertices_length(spine_bounding_box_attachment obj, spine_size_t value) {
    if (!obj) return;
    BoundingBoxAttachment *_obj = (BoundingBoxAttachment *) obj;
    _obj->setWorldVerticesLength(value);
}

spine_attachment spine_bounding_box_attachment_get_timeline_attachment(spine_bounding_box_attachment obj) {
    if (!obj) return nullptr;
    BoundingBoxAttachment *_obj = (BoundingBoxAttachment *) obj;
    return (spine_attachment) _obj->getTimelineAttachment();
}

void spine_bounding_box_attachment_set_timeline_attachment(spine_bounding_box_attachment obj, spine_attachment value) {
    if (!obj) return;
    BoundingBoxAttachment *_obj = (BoundingBoxAttachment *) obj;
    _obj->setTimelineAttachment((Attachment *) value);
}

void spine_bounding_box_attachment_copy_to(spine_bounding_box_attachment obj, spine_vertex_attachment other) {
    if (!obj) return ;
    BoundingBoxAttachment *_obj = (BoundingBoxAttachment *) obj;
    _obj->copyTo((VertexAttachment *) other);
}
