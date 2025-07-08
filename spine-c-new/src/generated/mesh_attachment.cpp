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

#include "mesh_attachment.h"
#include <spine/spine.h>

using namespace spine;

spine_mesh_attachment spine_mesh_attachment_create(const char* name) {
    MeshAttachment *obj = new (__FILE__, __LINE__) MeshAttachment(String(name));
    return (spine_mesh_attachment) obj;
}

void spine_mesh_attachment_dispose(spine_mesh_attachment obj) {
    if (!obj) return;
    delete (MeshAttachment *) obj;
}

spine_rtti spine_mesh_attachment_get_rtti() {
    return (spine_rtti) &MeshAttachment::rtti;
}

void spine_mesh_attachment_compute_world_vertices(spine_mesh_attachment obj, spine_skeleton skeleton, spine_slot slot, size_t start, size_t count, float * worldVertices, size_t offset, size_t stride) {
    if (!obj) return ;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    _obj->computeWorldVertices(*(Skeleton*) skeleton, *(Slot*) slot, start, count, (float *) worldVertices, offset, stride);
}

void spine_mesh_attachment_update_region(spine_mesh_attachment obj) {
    if (!obj) return ;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    _obj->updateRegion();
}

int spine_mesh_attachment_get_hull_length(spine_mesh_attachment obj) {
    if (!obj) return 0;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    return _obj->getHullLength();
}

void spine_mesh_attachment_set_hull_length(spine_mesh_attachment obj, int value) {
    if (!obj) return;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    _obj->setHullLength(value);
}

int32_t spine_mesh_attachment_get_num_region_u_vs(spine_mesh_attachment obj) {
    if (!obj) return 0;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    return (int32_t) _obj->getRegionUVs().size();
}

float *spine_mesh_attachment_get_region_u_vs(spine_mesh_attachment obj) {
    if (!obj) return nullptr;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    return (float *) _obj->getRegionUVs().buffer();
}

void spine_mesh_attachment_set_region_u_vs(spine_mesh_attachment obj, spine_array_float value) {
    if (!obj) return;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    _obj->setRegionUVs((Array<float> &) value);
}

int32_t spine_mesh_attachment_get_num_u_vs(spine_mesh_attachment obj) {
    if (!obj) return 0;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    return (int32_t) _obj->getUVs().size();
}

float *spine_mesh_attachment_get_u_vs(spine_mesh_attachment obj) {
    if (!obj) return nullptr;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    return (float *) _obj->getUVs().buffer();
}

int32_t spine_mesh_attachment_get_num_triangles(spine_mesh_attachment obj) {
    if (!obj) return 0;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    return (int32_t) _obj->getTriangles().size();
}

spine_unsigned short *spine_mesh_attachment_get_triangles(spine_mesh_attachment obj) {
    if (!obj) return nullptr;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    return (spine_unsigned short *) _obj->getTriangles().buffer();
}

void spine_mesh_attachment_set_triangles(spine_mesh_attachment obj, spine_array_unsigned_short value) {
    if (!obj) return;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    _obj->setTriangles((Array<unsigned short> &) value);
}

spine_color spine_mesh_attachment_get_color(spine_mesh_attachment obj) {
    if (!obj) return (spine_color) 0;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    return (spine_color) &_obj->getColor();
}

const char* spine_mesh_attachment_get_path(spine_mesh_attachment obj) {
    if (!obj) return nullptr;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    return (const char *) _obj->getPath().buffer();
}

void spine_mesh_attachment_set_path(spine_mesh_attachment obj, const char* value) {
    if (!obj) return;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    _obj->setPath(String(value));
}

spine_texture_region spine_mesh_attachment_get_region(spine_mesh_attachment obj) {
    if (!obj) return (spine_texture_region) 0;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    return (spine_texture_region) _obj->getRegion();
}

void spine_mesh_attachment_set_region(spine_mesh_attachment obj, spine_texture_region value) {
    if (!obj) return;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    _obj->setRegion((TextureRegion *) value);
}

spine_sequence spine_mesh_attachment_get_sequence(spine_mesh_attachment obj) {
    if (!obj) return (spine_sequence) 0;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    return (spine_sequence) _obj->getSequence();
}

void spine_mesh_attachment_set_sequence(spine_mesh_attachment obj, spine_sequence value) {
    if (!obj) return;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    _obj->setSequence((Sequence *) value);
}

spine_mesh_attachment spine_mesh_attachment_get_parent_mesh(spine_mesh_attachment obj) {
    if (!obj) return (spine_mesh_attachment) 0;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    return (spine_mesh_attachment) _obj->getParentMesh();
}

void spine_mesh_attachment_set_parent_mesh(spine_mesh_attachment obj, spine_mesh_attachment value) {
    if (!obj) return;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    _obj->setParentMesh((MeshAttachment *) value);
}

int32_t spine_mesh_attachment_get_num_edges(spine_mesh_attachment obj) {
    if (!obj) return 0;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    return (int32_t) _obj->getEdges().size();
}

spine_unsigned short *spine_mesh_attachment_get_edges(spine_mesh_attachment obj) {
    if (!obj) return nullptr;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    return (spine_unsigned short *) _obj->getEdges().buffer();
}

void spine_mesh_attachment_set_edges(spine_mesh_attachment obj, spine_array_unsigned_short value) {
    if (!obj) return;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    _obj->setEdges((Array<unsigned short> &) value);
}

float spine_mesh_attachment_get_width(spine_mesh_attachment obj) {
    if (!obj) return 0;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    return _obj->getWidth();
}

void spine_mesh_attachment_set_width(spine_mesh_attachment obj, float value) {
    if (!obj) return;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    _obj->setWidth(value);
}

float spine_mesh_attachment_get_height(spine_mesh_attachment obj) {
    if (!obj) return 0;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    return _obj->getHeight();
}

void spine_mesh_attachment_set_height(spine_mesh_attachment obj, float value) {
    if (!obj) return;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    _obj->setHeight(value);
}

spine_attachment spine_mesh_attachment_copy(spine_mesh_attachment obj) {
    if (!obj) return (spine_attachment) 0;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    return (spine_attachment) _obj->copy();
}

spine_mesh_attachment spine_mesh_attachment_new_linked_mesh(spine_mesh_attachment obj) {
    if (!obj) return (spine_mesh_attachment) 0;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    return (spine_mesh_attachment) _obj->newLinkedMesh();
}

void spine_mesh_attachment_compute_world_vertices_7(spine_mesh_attachment obj, spine_skeleton skeleton, spine_slot slot, size_t start, size_t count, spine_array_float worldVertices, size_t offset, size_t stride) {
    if (!obj) return ;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    _obj->computeWorldVertices(*(Skeleton*) skeleton, *(Slot*) slot, start, count, (Array<float> &) worldVertices, offset, stride);
}

int spine_mesh_attachment_get_id(spine_mesh_attachment obj) {
    if (!obj) return 0;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    return _obj->getId();
}

int32_t spine_mesh_attachment_get_num_bones(spine_mesh_attachment obj) {
    if (!obj) return 0;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    return (int32_t) _obj->getBones().size();
}

int *spine_mesh_attachment_get_bones(spine_mesh_attachment obj) {
    if (!obj) return nullptr;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    return (int *) _obj->getBones().buffer();
}

void spine_mesh_attachment_set_bones(spine_mesh_attachment obj, spine_array_int value) {
    if (!obj) return;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    _obj->setBones((Array<int> &) value);
}

int32_t spine_mesh_attachment_get_num_vertices(spine_mesh_attachment obj) {
    if (!obj) return 0;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    return (int32_t) _obj->getVertices().size();
}

float *spine_mesh_attachment_get_vertices(spine_mesh_attachment obj) {
    if (!obj) return nullptr;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    return (float *) _obj->getVertices().buffer();
}

void spine_mesh_attachment_set_vertices(spine_mesh_attachment obj, spine_array_float value) {
    if (!obj) return;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    _obj->setVertices((Array<float> &) value);
}

size_t spine_mesh_attachment_get_world_vertices_length(spine_mesh_attachment obj) {
    if (!obj) return 0;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    return _obj->getWorldVerticesLength();
}

void spine_mesh_attachment_set_world_vertices_length(spine_mesh_attachment obj, size_t value) {
    if (!obj) return;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    _obj->setWorldVerticesLength(value);
}

spine_attachment spine_mesh_attachment_get_timeline_attachment(spine_mesh_attachment obj) {
    if (!obj) return (spine_attachment) 0;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    return (spine_attachment) _obj->getTimelineAttachment();
}

void spine_mesh_attachment_set_timeline_attachment(spine_mesh_attachment obj, spine_attachment value) {
    if (!obj) return;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    _obj->setTimelineAttachment((Attachment *) value);
}

void spine_mesh_attachment_copy_to(spine_mesh_attachment obj, spine_vertex_attachment other) {
    if (!obj) return ;
    MeshAttachment *_obj = (MeshAttachment *) obj;
    _obj->copyTo((VertexAttachment *) other);
}
