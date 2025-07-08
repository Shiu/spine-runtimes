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

#include "arrays.h"
#include <spine/Array.h>
#include <spine/spine.h>

using namespace spine;

spine_array_animation spine_array_animation_create() {
    return (spine_array_animation) new (__FILE__, __LINE__) Array<Animation *>();
}

void spine_array_animation_dispose(spine_array_animation array) {
    if (!array) return;
    delete (Array<Animation *>*) array;
}

spine_animation spine_array_animation_get(spine_array_animation array, int index) {
    if (!array) return nullptr;
    Array<Animation *> *_array = (Array<Animation *>*) array;
    return (spine_animation) (*_array)[index];
}

void spine_array_animation_set(spine_array_animation array, int index, spine_animation value) {
    if (!array) return;
    Array<Animation *> *_array = (Array<Animation *>*) array;
    (*_array)[index] = (Animation *) value;
}

void spine_array_animation_clear(spine_array_animation array) {
    if (!array) return;
    Array<Animation *> *_array = (Array<Animation *>*) array;
    _array->clear();
}

size_t spine_array_animation_get_capacity(spine_array_animation array) {
    if (!array) return 0;
    Array<Animation *> *_array = (Array<Animation *>*) array;
    return _array->getCapacity();
}

size_t spine_array_animation_size(spine_array_animation array) {
    if (!array) return 0;
    Array<Animation *> *_array = (Array<Animation *>*) array;
    return _array->size();
}

void spine_array_animation_ensure_capacity(spine_array_animation array, size_t newCapacity) {
    if (!array) return;
    Array<Animation *> *_array = (Array<Animation *>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_animation_add(spine_array_animation array, spine_animation inValue) {
    if (!array) return;
    Array<Animation *> *_array = (Array<Animation *>*) array;
    _array->add((Animation *) inValue);
}

void spine_array_animation_remove_at(spine_array_animation array, size_t inIndex) {
    if (!array) return;
    Array<Animation *> *_array = (Array<Animation *>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_animation_contains(spine_array_animation array, spine_animation inValue) {
    if (!array) return false;
    Array<Animation *> *_array = (Array<Animation *>*) array;
    return _array->contains((Animation *) inValue);
}

int spine_array_animation_index_of(spine_array_animation array, spine_animation inValue) {
    if (!array) return 0;
    Array<Animation *> *_array = (Array<Animation *>*) array;
    return _array->indexOf((Animation *) inValue);
}

spine_animation spine_array_animation_buffer(spine_array_animation array) {
    if (!array) return nullptr;
    Array<Animation *> *_array = (Array<Animation *>*) array;
    return (spine_animation) _array->buffer();
}

spine_array_atlas_page spine_array_atlas_page_create() {
    return (spine_array_atlas_page) new (__FILE__, __LINE__) Array<AtlasPage *>();
}

void spine_array_atlas_page_dispose(spine_array_atlas_page array) {
    if (!array) return;
    delete (Array<AtlasPage *>*) array;
}

spine_atlas_page spine_array_atlas_page_get(spine_array_atlas_page array, int index) {
    if (!array) return nullptr;
    Array<AtlasPage *> *_array = (Array<AtlasPage *>*) array;
    return (spine_atlas_page) (*_array)[index];
}

void spine_array_atlas_page_set(spine_array_atlas_page array, int index, spine_atlas_page value) {
    if (!array) return;
    Array<AtlasPage *> *_array = (Array<AtlasPage *>*) array;
    (*_array)[index] = (AtlasPage *) value;
}

void spine_array_atlas_page_clear(spine_array_atlas_page array) {
    if (!array) return;
    Array<AtlasPage *> *_array = (Array<AtlasPage *>*) array;
    _array->clear();
}

size_t spine_array_atlas_page_get_capacity(spine_array_atlas_page array) {
    if (!array) return 0;
    Array<AtlasPage *> *_array = (Array<AtlasPage *>*) array;
    return _array->getCapacity();
}

size_t spine_array_atlas_page_size(spine_array_atlas_page array) {
    if (!array) return 0;
    Array<AtlasPage *> *_array = (Array<AtlasPage *>*) array;
    return _array->size();
}

void spine_array_atlas_page_ensure_capacity(spine_array_atlas_page array, size_t newCapacity) {
    if (!array) return;
    Array<AtlasPage *> *_array = (Array<AtlasPage *>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_atlas_page_add(spine_array_atlas_page array, spine_atlas_page inValue) {
    if (!array) return;
    Array<AtlasPage *> *_array = (Array<AtlasPage *>*) array;
    _array->add((AtlasPage *) inValue);
}

void spine_array_atlas_page_remove_at(spine_array_atlas_page array, size_t inIndex) {
    if (!array) return;
    Array<AtlasPage *> *_array = (Array<AtlasPage *>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_atlas_page_contains(spine_array_atlas_page array, spine_atlas_page inValue) {
    if (!array) return false;
    Array<AtlasPage *> *_array = (Array<AtlasPage *>*) array;
    return _array->contains((AtlasPage *) inValue);
}

int spine_array_atlas_page_index_of(spine_array_atlas_page array, spine_atlas_page inValue) {
    if (!array) return 0;
    Array<AtlasPage *> *_array = (Array<AtlasPage *>*) array;
    return _array->indexOf((AtlasPage *) inValue);
}

spine_atlas_page spine_array_atlas_page_buffer(spine_array_atlas_page array) {
    if (!array) return nullptr;
    Array<AtlasPage *> *_array = (Array<AtlasPage *>*) array;
    return (spine_atlas_page) _array->buffer();
}

spine_array_atlas_region spine_array_atlas_region_create() {
    return (spine_array_atlas_region) new (__FILE__, __LINE__) Array<AtlasRegion *>();
}

void spine_array_atlas_region_dispose(spine_array_atlas_region array) {
    if (!array) return;
    delete (Array<AtlasRegion *>*) array;
}

spine_atlas_region spine_array_atlas_region_get(spine_array_atlas_region array, int index) {
    if (!array) return nullptr;
    Array<AtlasRegion *> *_array = (Array<AtlasRegion *>*) array;
    return (spine_atlas_region) (*_array)[index];
}

void spine_array_atlas_region_set(spine_array_atlas_region array, int index, spine_atlas_region value) {
    if (!array) return;
    Array<AtlasRegion *> *_array = (Array<AtlasRegion *>*) array;
    (*_array)[index] = (AtlasRegion *) value;
}

void spine_array_atlas_region_clear(spine_array_atlas_region array) {
    if (!array) return;
    Array<AtlasRegion *> *_array = (Array<AtlasRegion *>*) array;
    _array->clear();
}

size_t spine_array_atlas_region_get_capacity(spine_array_atlas_region array) {
    if (!array) return 0;
    Array<AtlasRegion *> *_array = (Array<AtlasRegion *>*) array;
    return _array->getCapacity();
}

size_t spine_array_atlas_region_size(spine_array_atlas_region array) {
    if (!array) return 0;
    Array<AtlasRegion *> *_array = (Array<AtlasRegion *>*) array;
    return _array->size();
}

void spine_array_atlas_region_ensure_capacity(spine_array_atlas_region array, size_t newCapacity) {
    if (!array) return;
    Array<AtlasRegion *> *_array = (Array<AtlasRegion *>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_atlas_region_add(spine_array_atlas_region array, spine_atlas_region inValue) {
    if (!array) return;
    Array<AtlasRegion *> *_array = (Array<AtlasRegion *>*) array;
    _array->add((AtlasRegion *) inValue);
}

void spine_array_atlas_region_remove_at(spine_array_atlas_region array, size_t inIndex) {
    if (!array) return;
    Array<AtlasRegion *> *_array = (Array<AtlasRegion *>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_atlas_region_contains(spine_array_atlas_region array, spine_atlas_region inValue) {
    if (!array) return false;
    Array<AtlasRegion *> *_array = (Array<AtlasRegion *>*) array;
    return _array->contains((AtlasRegion *) inValue);
}

int spine_array_atlas_region_index_of(spine_array_atlas_region array, spine_atlas_region inValue) {
    if (!array) return 0;
    Array<AtlasRegion *> *_array = (Array<AtlasRegion *>*) array;
    return _array->indexOf((AtlasRegion *) inValue);
}

spine_atlas_region spine_array_atlas_region_buffer(spine_array_atlas_region array) {
    if (!array) return nullptr;
    Array<AtlasRegion *> *_array = (Array<AtlasRegion *>*) array;
    return (spine_atlas_region) _array->buffer();
}

spine_array_attachment spine_array_attachment_create() {
    return (spine_array_attachment) new (__FILE__, __LINE__) Array<Attachment *>();
}

void spine_array_attachment_dispose(spine_array_attachment array) {
    if (!array) return;
    delete (Array<Attachment *>*) array;
}

spine_attachment spine_array_attachment_get(spine_array_attachment array, int index) {
    if (!array) return nullptr;
    Array<Attachment *> *_array = (Array<Attachment *>*) array;
    return (spine_attachment) (*_array)[index];
}

void spine_array_attachment_set(spine_array_attachment array, int index, spine_attachment value) {
    if (!array) return;
    Array<Attachment *> *_array = (Array<Attachment *>*) array;
    (*_array)[index] = (Attachment *) value;
}

void spine_array_attachment_clear(spine_array_attachment array) {
    if (!array) return;
    Array<Attachment *> *_array = (Array<Attachment *>*) array;
    _array->clear();
}

size_t spine_array_attachment_get_capacity(spine_array_attachment array) {
    if (!array) return 0;
    Array<Attachment *> *_array = (Array<Attachment *>*) array;
    return _array->getCapacity();
}

size_t spine_array_attachment_size(spine_array_attachment array) {
    if (!array) return 0;
    Array<Attachment *> *_array = (Array<Attachment *>*) array;
    return _array->size();
}

void spine_array_attachment_ensure_capacity(spine_array_attachment array, size_t newCapacity) {
    if (!array) return;
    Array<Attachment *> *_array = (Array<Attachment *>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_attachment_add(spine_array_attachment array, spine_attachment inValue) {
    if (!array) return;
    Array<Attachment *> *_array = (Array<Attachment *>*) array;
    _array->add((Attachment *) inValue);
}

void spine_array_attachment_remove_at(spine_array_attachment array, size_t inIndex) {
    if (!array) return;
    Array<Attachment *> *_array = (Array<Attachment *>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_attachment_contains(spine_array_attachment array, spine_attachment inValue) {
    if (!array) return false;
    Array<Attachment *> *_array = (Array<Attachment *>*) array;
    return _array->contains((Attachment *) inValue);
}

int spine_array_attachment_index_of(spine_array_attachment array, spine_attachment inValue) {
    if (!array) return 0;
    Array<Attachment *> *_array = (Array<Attachment *>*) array;
    return _array->indexOf((Attachment *) inValue);
}

spine_attachment spine_array_attachment_buffer(spine_array_attachment array) {
    if (!array) return nullptr;
    Array<Attachment *> *_array = (Array<Attachment *>*) array;
    return (spine_attachment) _array->buffer();
}

spine_array_bone spine_array_bone_create() {
    return (spine_array_bone) new (__FILE__, __LINE__) Array<Bone *>();
}

void spine_array_bone_dispose(spine_array_bone array) {
    if (!array) return;
    delete (Array<Bone *>*) array;
}

spine_bone spine_array_bone_get(spine_array_bone array, int index) {
    if (!array) return nullptr;
    Array<Bone *> *_array = (Array<Bone *>*) array;
    return (spine_bone) (*_array)[index];
}

void spine_array_bone_set(spine_array_bone array, int index, spine_bone value) {
    if (!array) return;
    Array<Bone *> *_array = (Array<Bone *>*) array;
    (*_array)[index] = (Bone *) value;
}

void spine_array_bone_clear(spine_array_bone array) {
    if (!array) return;
    Array<Bone *> *_array = (Array<Bone *>*) array;
    _array->clear();
}

size_t spine_array_bone_get_capacity(spine_array_bone array) {
    if (!array) return 0;
    Array<Bone *> *_array = (Array<Bone *>*) array;
    return _array->getCapacity();
}

size_t spine_array_bone_size(spine_array_bone array) {
    if (!array) return 0;
    Array<Bone *> *_array = (Array<Bone *>*) array;
    return _array->size();
}

void spine_array_bone_ensure_capacity(spine_array_bone array, size_t newCapacity) {
    if (!array) return;
    Array<Bone *> *_array = (Array<Bone *>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_bone_add(spine_array_bone array, spine_bone inValue) {
    if (!array) return;
    Array<Bone *> *_array = (Array<Bone *>*) array;
    _array->add((Bone *) inValue);
}

void spine_array_bone_remove_at(spine_array_bone array, size_t inIndex) {
    if (!array) return;
    Array<Bone *> *_array = (Array<Bone *>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_bone_contains(spine_array_bone array, spine_bone inValue) {
    if (!array) return false;
    Array<Bone *> *_array = (Array<Bone *>*) array;
    return _array->contains((Bone *) inValue);
}

int spine_array_bone_index_of(spine_array_bone array, spine_bone inValue) {
    if (!array) return 0;
    Array<Bone *> *_array = (Array<Bone *>*) array;
    return _array->indexOf((Bone *) inValue);
}

spine_bone spine_array_bone_buffer(spine_array_bone array) {
    if (!array) return nullptr;
    Array<Bone *> *_array = (Array<Bone *>*) array;
    return (spine_bone) _array->buffer();
}

spine_array_bone_data spine_array_bone_data_create() {
    return (spine_array_bone_data) new (__FILE__, __LINE__) Array<BoneData *>();
}

void spine_array_bone_data_dispose(spine_array_bone_data array) {
    if (!array) return;
    delete (Array<BoneData *>*) array;
}

spine_bone_data spine_array_bone_data_get(spine_array_bone_data array, int index) {
    if (!array) return nullptr;
    Array<BoneData *> *_array = (Array<BoneData *>*) array;
    return (spine_bone_data) (*_array)[index];
}

void spine_array_bone_data_set(spine_array_bone_data array, int index, spine_bone_data value) {
    if (!array) return;
    Array<BoneData *> *_array = (Array<BoneData *>*) array;
    (*_array)[index] = (BoneData *) value;
}

void spine_array_bone_data_clear(spine_array_bone_data array) {
    if (!array) return;
    Array<BoneData *> *_array = (Array<BoneData *>*) array;
    _array->clear();
}

size_t spine_array_bone_data_get_capacity(spine_array_bone_data array) {
    if (!array) return 0;
    Array<BoneData *> *_array = (Array<BoneData *>*) array;
    return _array->getCapacity();
}

size_t spine_array_bone_data_size(spine_array_bone_data array) {
    if (!array) return 0;
    Array<BoneData *> *_array = (Array<BoneData *>*) array;
    return _array->size();
}

void spine_array_bone_data_ensure_capacity(spine_array_bone_data array, size_t newCapacity) {
    if (!array) return;
    Array<BoneData *> *_array = (Array<BoneData *>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_bone_data_add(spine_array_bone_data array, spine_bone_data inValue) {
    if (!array) return;
    Array<BoneData *> *_array = (Array<BoneData *>*) array;
    _array->add((BoneData *) inValue);
}

void spine_array_bone_data_remove_at(spine_array_bone_data array, size_t inIndex) {
    if (!array) return;
    Array<BoneData *> *_array = (Array<BoneData *>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_bone_data_contains(spine_array_bone_data array, spine_bone_data inValue) {
    if (!array) return false;
    Array<BoneData *> *_array = (Array<BoneData *>*) array;
    return _array->contains((BoneData *) inValue);
}

int spine_array_bone_data_index_of(spine_array_bone_data array, spine_bone_data inValue) {
    if (!array) return 0;
    Array<BoneData *> *_array = (Array<BoneData *>*) array;
    return _array->indexOf((BoneData *) inValue);
}

spine_bone_data spine_array_bone_data_buffer(spine_array_bone_data array) {
    if (!array) return nullptr;
    Array<BoneData *> *_array = (Array<BoneData *>*) array;
    return (spine_bone_data) _array->buffer();
}

spine_array_bone_pose spine_array_bone_pose_create() {
    return (spine_array_bone_pose) new (__FILE__, __LINE__) Array<BonePose *>();
}

void spine_array_bone_pose_dispose(spine_array_bone_pose array) {
    if (!array) return;
    delete (Array<BonePose *>*) array;
}

spine_bone_pose spine_array_bone_pose_get(spine_array_bone_pose array, int index) {
    if (!array) return nullptr;
    Array<BonePose *> *_array = (Array<BonePose *>*) array;
    return (spine_bone_pose) (*_array)[index];
}

void spine_array_bone_pose_set(spine_array_bone_pose array, int index, spine_bone_pose value) {
    if (!array) return;
    Array<BonePose *> *_array = (Array<BonePose *>*) array;
    (*_array)[index] = (BonePose *) value;
}

void spine_array_bone_pose_clear(spine_array_bone_pose array) {
    if (!array) return;
    Array<BonePose *> *_array = (Array<BonePose *>*) array;
    _array->clear();
}

size_t spine_array_bone_pose_get_capacity(spine_array_bone_pose array) {
    if (!array) return 0;
    Array<BonePose *> *_array = (Array<BonePose *>*) array;
    return _array->getCapacity();
}

size_t spine_array_bone_pose_size(spine_array_bone_pose array) {
    if (!array) return 0;
    Array<BonePose *> *_array = (Array<BonePose *>*) array;
    return _array->size();
}

void spine_array_bone_pose_ensure_capacity(spine_array_bone_pose array, size_t newCapacity) {
    if (!array) return;
    Array<BonePose *> *_array = (Array<BonePose *>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_bone_pose_add(spine_array_bone_pose array, spine_bone_pose inValue) {
    if (!array) return;
    Array<BonePose *> *_array = (Array<BonePose *>*) array;
    _array->add((BonePose *) inValue);
}

void spine_array_bone_pose_remove_at(spine_array_bone_pose array, size_t inIndex) {
    if (!array) return;
    Array<BonePose *> *_array = (Array<BonePose *>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_bone_pose_contains(spine_array_bone_pose array, spine_bone_pose inValue) {
    if (!array) return false;
    Array<BonePose *> *_array = (Array<BonePose *>*) array;
    return _array->contains((BonePose *) inValue);
}

int spine_array_bone_pose_index_of(spine_array_bone_pose array, spine_bone_pose inValue) {
    if (!array) return 0;
    Array<BonePose *> *_array = (Array<BonePose *>*) array;
    return _array->indexOf((BonePose *) inValue);
}

spine_bone_pose spine_array_bone_pose_buffer(spine_array_bone_pose array) {
    if (!array) return nullptr;
    Array<BonePose *> *_array = (Array<BonePose *>*) array;
    return (spine_bone_pose) _array->buffer();
}

spine_array_bounding_box_attachment spine_array_bounding_box_attachment_create() {
    return (spine_array_bounding_box_attachment) new (__FILE__, __LINE__) Array<BoundingBoxAttachment *>();
}

void spine_array_bounding_box_attachment_dispose(spine_array_bounding_box_attachment array) {
    if (!array) return;
    delete (Array<BoundingBoxAttachment *>*) array;
}

spine_bounding_box_attachment spine_array_bounding_box_attachment_get(spine_array_bounding_box_attachment array, int index) {
    if (!array) return nullptr;
    Array<BoundingBoxAttachment *> *_array = (Array<BoundingBoxAttachment *>*) array;
    return (spine_bounding_box_attachment) (*_array)[index];
}

void spine_array_bounding_box_attachment_set(spine_array_bounding_box_attachment array, int index, spine_bounding_box_attachment value) {
    if (!array) return;
    Array<BoundingBoxAttachment *> *_array = (Array<BoundingBoxAttachment *>*) array;
    (*_array)[index] = (BoundingBoxAttachment *) value;
}

void spine_array_bounding_box_attachment_clear(spine_array_bounding_box_attachment array) {
    if (!array) return;
    Array<BoundingBoxAttachment *> *_array = (Array<BoundingBoxAttachment *>*) array;
    _array->clear();
}

size_t spine_array_bounding_box_attachment_get_capacity(spine_array_bounding_box_attachment array) {
    if (!array) return 0;
    Array<BoundingBoxAttachment *> *_array = (Array<BoundingBoxAttachment *>*) array;
    return _array->getCapacity();
}

size_t spine_array_bounding_box_attachment_size(spine_array_bounding_box_attachment array) {
    if (!array) return 0;
    Array<BoundingBoxAttachment *> *_array = (Array<BoundingBoxAttachment *>*) array;
    return _array->size();
}

void spine_array_bounding_box_attachment_ensure_capacity(spine_array_bounding_box_attachment array, size_t newCapacity) {
    if (!array) return;
    Array<BoundingBoxAttachment *> *_array = (Array<BoundingBoxAttachment *>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_bounding_box_attachment_add(spine_array_bounding_box_attachment array, spine_bounding_box_attachment inValue) {
    if (!array) return;
    Array<BoundingBoxAttachment *> *_array = (Array<BoundingBoxAttachment *>*) array;
    _array->add((BoundingBoxAttachment *) inValue);
}

void spine_array_bounding_box_attachment_remove_at(spine_array_bounding_box_attachment array, size_t inIndex) {
    if (!array) return;
    Array<BoundingBoxAttachment *> *_array = (Array<BoundingBoxAttachment *>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_bounding_box_attachment_contains(spine_array_bounding_box_attachment array, spine_bounding_box_attachment inValue) {
    if (!array) return false;
    Array<BoundingBoxAttachment *> *_array = (Array<BoundingBoxAttachment *>*) array;
    return _array->contains((BoundingBoxAttachment *) inValue);
}

int spine_array_bounding_box_attachment_index_of(spine_array_bounding_box_attachment array, spine_bounding_box_attachment inValue) {
    if (!array) return 0;
    Array<BoundingBoxAttachment *> *_array = (Array<BoundingBoxAttachment *>*) array;
    return _array->indexOf((BoundingBoxAttachment *) inValue);
}

spine_bounding_box_attachment spine_array_bounding_box_attachment_buffer(spine_array_bounding_box_attachment array) {
    if (!array) return nullptr;
    Array<BoundingBoxAttachment *> *_array = (Array<BoundingBoxAttachment *>*) array;
    return (spine_bounding_box_attachment) _array->buffer();
}

spine_array_constraint spine_array_constraint_create() {
    return (spine_array_constraint) new (__FILE__, __LINE__) Array<Constraint *>();
}

void spine_array_constraint_dispose(spine_array_constraint array) {
    if (!array) return;
    delete (Array<Constraint *>*) array;
}

spine_constraint spine_array_constraint_get(spine_array_constraint array, int index) {
    if (!array) return nullptr;
    Array<Constraint *> *_array = (Array<Constraint *>*) array;
    return (spine_constraint) (*_array)[index];
}

void spine_array_constraint_set(spine_array_constraint array, int index, spine_constraint value) {
    if (!array) return;
    Array<Constraint *> *_array = (Array<Constraint *>*) array;
    (*_array)[index] = (Constraint *) value;
}

void spine_array_constraint_clear(spine_array_constraint array) {
    if (!array) return;
    Array<Constraint *> *_array = (Array<Constraint *>*) array;
    _array->clear();
}

size_t spine_array_constraint_get_capacity(spine_array_constraint array) {
    if (!array) return 0;
    Array<Constraint *> *_array = (Array<Constraint *>*) array;
    return _array->getCapacity();
}

size_t spine_array_constraint_size(spine_array_constraint array) {
    if (!array) return 0;
    Array<Constraint *> *_array = (Array<Constraint *>*) array;
    return _array->size();
}

void spine_array_constraint_ensure_capacity(spine_array_constraint array, size_t newCapacity) {
    if (!array) return;
    Array<Constraint *> *_array = (Array<Constraint *>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_constraint_add(spine_array_constraint array, spine_constraint inValue) {
    if (!array) return;
    Array<Constraint *> *_array = (Array<Constraint *>*) array;
    _array->add((Constraint *) inValue);
}

void spine_array_constraint_remove_at(spine_array_constraint array, size_t inIndex) {
    if (!array) return;
    Array<Constraint *> *_array = (Array<Constraint *>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_constraint_contains(spine_array_constraint array, spine_constraint inValue) {
    if (!array) return false;
    Array<Constraint *> *_array = (Array<Constraint *>*) array;
    return _array->contains((Constraint *) inValue);
}

int spine_array_constraint_index_of(spine_array_constraint array, spine_constraint inValue) {
    if (!array) return 0;
    Array<Constraint *> *_array = (Array<Constraint *>*) array;
    return _array->indexOf((Constraint *) inValue);
}

spine_constraint spine_array_constraint_buffer(spine_array_constraint array) {
    if (!array) return nullptr;
    Array<Constraint *> *_array = (Array<Constraint *>*) array;
    return (spine_constraint) _array->buffer();
}

spine_array_constraint_data spine_array_constraint_data_create() {
    return (spine_array_constraint_data) new (__FILE__, __LINE__) Array<ConstraintData *>();
}

void spine_array_constraint_data_dispose(spine_array_constraint_data array) {
    if (!array) return;
    delete (Array<ConstraintData *>*) array;
}

spine_constraint_data spine_array_constraint_data_get(spine_array_constraint_data array, int index) {
    if (!array) return nullptr;
    Array<ConstraintData *> *_array = (Array<ConstraintData *>*) array;
    return (spine_constraint_data) (*_array)[index];
}

void spine_array_constraint_data_set(spine_array_constraint_data array, int index, spine_constraint_data value) {
    if (!array) return;
    Array<ConstraintData *> *_array = (Array<ConstraintData *>*) array;
    (*_array)[index] = (ConstraintData *) value;
}

void spine_array_constraint_data_clear(spine_array_constraint_data array) {
    if (!array) return;
    Array<ConstraintData *> *_array = (Array<ConstraintData *>*) array;
    _array->clear();
}

size_t spine_array_constraint_data_get_capacity(spine_array_constraint_data array) {
    if (!array) return 0;
    Array<ConstraintData *> *_array = (Array<ConstraintData *>*) array;
    return _array->getCapacity();
}

size_t spine_array_constraint_data_size(spine_array_constraint_data array) {
    if (!array) return 0;
    Array<ConstraintData *> *_array = (Array<ConstraintData *>*) array;
    return _array->size();
}

void spine_array_constraint_data_ensure_capacity(spine_array_constraint_data array, size_t newCapacity) {
    if (!array) return;
    Array<ConstraintData *> *_array = (Array<ConstraintData *>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_constraint_data_add(spine_array_constraint_data array, spine_constraint_data inValue) {
    if (!array) return;
    Array<ConstraintData *> *_array = (Array<ConstraintData *>*) array;
    _array->add((ConstraintData *) inValue);
}

void spine_array_constraint_data_remove_at(spine_array_constraint_data array, size_t inIndex) {
    if (!array) return;
    Array<ConstraintData *> *_array = (Array<ConstraintData *>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_constraint_data_contains(spine_array_constraint_data array, spine_constraint_data inValue) {
    if (!array) return false;
    Array<ConstraintData *> *_array = (Array<ConstraintData *>*) array;
    return _array->contains((ConstraintData *) inValue);
}

int spine_array_constraint_data_index_of(spine_array_constraint_data array, spine_constraint_data inValue) {
    if (!array) return 0;
    Array<ConstraintData *> *_array = (Array<ConstraintData *>*) array;
    return _array->indexOf((ConstraintData *) inValue);
}

spine_constraint_data spine_array_constraint_data_buffer(spine_array_constraint_data array) {
    if (!array) return nullptr;
    Array<ConstraintData *> *_array = (Array<ConstraintData *>*) array;
    return (spine_constraint_data) _array->buffer();
}

spine_array_event spine_array_event_create() {
    return (spine_array_event) new (__FILE__, __LINE__) Array<Event *>();
}

void spine_array_event_dispose(spine_array_event array) {
    if (!array) return;
    delete (Array<Event *>*) array;
}

spine_event spine_array_event_get(spine_array_event array, int index) {
    if (!array) return nullptr;
    Array<Event *> *_array = (Array<Event *>*) array;
    return (spine_event) (*_array)[index];
}

void spine_array_event_set(spine_array_event array, int index, spine_event value) {
    if (!array) return;
    Array<Event *> *_array = (Array<Event *>*) array;
    (*_array)[index] = (Event *) value;
}

void spine_array_event_clear(spine_array_event array) {
    if (!array) return;
    Array<Event *> *_array = (Array<Event *>*) array;
    _array->clear();
}

size_t spine_array_event_get_capacity(spine_array_event array) {
    if (!array) return 0;
    Array<Event *> *_array = (Array<Event *>*) array;
    return _array->getCapacity();
}

size_t spine_array_event_size(spine_array_event array) {
    if (!array) return 0;
    Array<Event *> *_array = (Array<Event *>*) array;
    return _array->size();
}

void spine_array_event_ensure_capacity(spine_array_event array, size_t newCapacity) {
    if (!array) return;
    Array<Event *> *_array = (Array<Event *>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_event_add(spine_array_event array, spine_event inValue) {
    if (!array) return;
    Array<Event *> *_array = (Array<Event *>*) array;
    _array->add((Event *) inValue);
}

void spine_array_event_remove_at(spine_array_event array, size_t inIndex) {
    if (!array) return;
    Array<Event *> *_array = (Array<Event *>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_event_contains(spine_array_event array, spine_event inValue) {
    if (!array) return false;
    Array<Event *> *_array = (Array<Event *>*) array;
    return _array->contains((Event *) inValue);
}

int spine_array_event_index_of(spine_array_event array, spine_event inValue) {
    if (!array) return 0;
    Array<Event *> *_array = (Array<Event *>*) array;
    return _array->indexOf((Event *) inValue);
}

spine_event spine_array_event_buffer(spine_array_event array) {
    if (!array) return nullptr;
    Array<Event *> *_array = (Array<Event *>*) array;
    return (spine_event) _array->buffer();
}

spine_array_event_data spine_array_event_data_create() {
    return (spine_array_event_data) new (__FILE__, __LINE__) Array<EventData *>();
}

void spine_array_event_data_dispose(spine_array_event_data array) {
    if (!array) return;
    delete (Array<EventData *>*) array;
}

spine_event_data spine_array_event_data_get(spine_array_event_data array, int index) {
    if (!array) return nullptr;
    Array<EventData *> *_array = (Array<EventData *>*) array;
    return (spine_event_data) (*_array)[index];
}

void spine_array_event_data_set(spine_array_event_data array, int index, spine_event_data value) {
    if (!array) return;
    Array<EventData *> *_array = (Array<EventData *>*) array;
    (*_array)[index] = (EventData *) value;
}

void spine_array_event_data_clear(spine_array_event_data array) {
    if (!array) return;
    Array<EventData *> *_array = (Array<EventData *>*) array;
    _array->clear();
}

size_t spine_array_event_data_get_capacity(spine_array_event_data array) {
    if (!array) return 0;
    Array<EventData *> *_array = (Array<EventData *>*) array;
    return _array->getCapacity();
}

size_t spine_array_event_data_size(spine_array_event_data array) {
    if (!array) return 0;
    Array<EventData *> *_array = (Array<EventData *>*) array;
    return _array->size();
}

void spine_array_event_data_ensure_capacity(spine_array_event_data array, size_t newCapacity) {
    if (!array) return;
    Array<EventData *> *_array = (Array<EventData *>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_event_data_add(spine_array_event_data array, spine_event_data inValue) {
    if (!array) return;
    Array<EventData *> *_array = (Array<EventData *>*) array;
    _array->add((EventData *) inValue);
}

void spine_array_event_data_remove_at(spine_array_event_data array, size_t inIndex) {
    if (!array) return;
    Array<EventData *> *_array = (Array<EventData *>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_event_data_contains(spine_array_event_data array, spine_event_data inValue) {
    if (!array) return false;
    Array<EventData *> *_array = (Array<EventData *>*) array;
    return _array->contains((EventData *) inValue);
}

int spine_array_event_data_index_of(spine_array_event_data array, spine_event_data inValue) {
    if (!array) return 0;
    Array<EventData *> *_array = (Array<EventData *>*) array;
    return _array->indexOf((EventData *) inValue);
}

spine_event_data spine_array_event_data_buffer(spine_array_event_data array) {
    if (!array) return nullptr;
    Array<EventData *> *_array = (Array<EventData *>*) array;
    return (spine_event_data) _array->buffer();
}

spine_array_float spine_array_float_create() {
    return (spine_array_float) new (__FILE__, __LINE__) Array<float>();
}

void spine_array_float_dispose(spine_array_float array) {
    if (!array) return;
    delete (Array<float>*) array;
}

float spine_array_float_get(spine_array_float array, int index) {
    if (!array) return 0;
    Array<float> *_array = (Array<float>*) array;
    return (*_array)[index];
}

void spine_array_float_set(spine_array_float array, int index, float value) {
    if (!array) return;
    Array<float> *_array = (Array<float>*) array;
    (*_array)[index] = value;
}

void spine_array_float_clear(spine_array_float array) {
    if (!array) return;
    Array<float> *_array = (Array<float>*) array;
    _array->clear();
}

size_t spine_array_float_get_capacity(spine_array_float array) {
    if (!array) return 0;
    Array<float> *_array = (Array<float>*) array;
    return _array->getCapacity();
}

size_t spine_array_float_size(spine_array_float array) {
    if (!array) return 0;
    Array<float> *_array = (Array<float>*) array;
    return _array->size();
}

void spine_array_float_ensure_capacity(spine_array_float array, size_t newCapacity) {
    if (!array) return;
    Array<float> *_array = (Array<float>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_float_add(spine_array_float array, float inValue) {
    if (!array) return;
    Array<float> *_array = (Array<float>*) array;
    _array->add(inValue);
}

void spine_array_float_remove_at(spine_array_float array, size_t inIndex) {
    if (!array) return;
    Array<float> *_array = (Array<float>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_float_contains(spine_array_float array, float inValue) {
    if (!array) return false;
    Array<float> *_array = (Array<float>*) array;
    return _array->contains(inValue);
}

int spine_array_float_index_of(spine_array_float array, float inValue) {
    if (!array) return 0;
    Array<float> *_array = (Array<float>*) array;
    return _array->indexOf(inValue);
}

float *spine_array_float_buffer(spine_array_float array) {
    if (!array) return nullptr;
    Array<float> *_array = (Array<float>*) array;
    return _array->buffer();
}

spine_array_from_property spine_array_from_property_create() {
    return (spine_array_from_property) new (__FILE__, __LINE__) Array<class FromProperty *>();
}

void spine_array_from_property_dispose(spine_array_from_property array) {
    if (!array) return;
    delete (Array<class FromProperty *>*) array;
}

spine_from_property spine_array_from_property_get(spine_array_from_property array, int index) {
    if (!array) return nullptr;
    Array<class FromProperty *> *_array = (Array<class FromProperty *>*) array;
    return (spine_from_property) (*_array)[index];
}

void spine_array_from_property_set(spine_array_from_property array, int index, spine_from_property value) {
    if (!array) return;
    Array<class FromProperty *> *_array = (Array<class FromProperty *>*) array;
    (*_array)[index] = (class FromProperty *) value;
}

void spine_array_from_property_clear(spine_array_from_property array) {
    if (!array) return;
    Array<class FromProperty *> *_array = (Array<class FromProperty *>*) array;
    _array->clear();
}

size_t spine_array_from_property_get_capacity(spine_array_from_property array) {
    if (!array) return 0;
    Array<class FromProperty *> *_array = (Array<class FromProperty *>*) array;
    return _array->getCapacity();
}

size_t spine_array_from_property_size(spine_array_from_property array) {
    if (!array) return 0;
    Array<class FromProperty *> *_array = (Array<class FromProperty *>*) array;
    return _array->size();
}

void spine_array_from_property_ensure_capacity(spine_array_from_property array, size_t newCapacity) {
    if (!array) return;
    Array<class FromProperty *> *_array = (Array<class FromProperty *>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_from_property_add(spine_array_from_property array, spine_from_property inValue) {
    if (!array) return;
    Array<class FromProperty *> *_array = (Array<class FromProperty *>*) array;
    _array->add((class FromProperty *) inValue);
}

void spine_array_from_property_remove_at(spine_array_from_property array, size_t inIndex) {
    if (!array) return;
    Array<class FromProperty *> *_array = (Array<class FromProperty *>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_from_property_contains(spine_array_from_property array, spine_from_property inValue) {
    if (!array) return false;
    Array<class FromProperty *> *_array = (Array<class FromProperty *>*) array;
    return _array->contains((class FromProperty *) inValue);
}

int spine_array_from_property_index_of(spine_array_from_property array, spine_from_property inValue) {
    if (!array) return 0;
    Array<class FromProperty *> *_array = (Array<class FromProperty *>*) array;
    return _array->indexOf((class FromProperty *) inValue);
}

spine_from_property spine_array_from_property_buffer(spine_array_from_property array) {
    if (!array) return nullptr;
    Array<class FromProperty *> *_array = (Array<class FromProperty *>*) array;
    return (spine_from_property) _array->buffer();
}

spine_array_ik_constraint_data spine_array_ik_constraint_data_create() {
    return (spine_array_ik_constraint_data) new (__FILE__, __LINE__) Array<IkConstraintData *>();
}

void spine_array_ik_constraint_data_dispose(spine_array_ik_constraint_data array) {
    if (!array) return;
    delete (Array<IkConstraintData *>*) array;
}

spine_ik_constraint_data spine_array_ik_constraint_data_get(spine_array_ik_constraint_data array, int index) {
    if (!array) return nullptr;
    Array<IkConstraintData *> *_array = (Array<IkConstraintData *>*) array;
    return (spine_ik_constraint_data) (*_array)[index];
}

void spine_array_ik_constraint_data_set(spine_array_ik_constraint_data array, int index, spine_ik_constraint_data value) {
    if (!array) return;
    Array<IkConstraintData *> *_array = (Array<IkConstraintData *>*) array;
    (*_array)[index] = (IkConstraintData *) value;
}

void spine_array_ik_constraint_data_clear(spine_array_ik_constraint_data array) {
    if (!array) return;
    Array<IkConstraintData *> *_array = (Array<IkConstraintData *>*) array;
    _array->clear();
}

size_t spine_array_ik_constraint_data_get_capacity(spine_array_ik_constraint_data array) {
    if (!array) return 0;
    Array<IkConstraintData *> *_array = (Array<IkConstraintData *>*) array;
    return _array->getCapacity();
}

size_t spine_array_ik_constraint_data_size(spine_array_ik_constraint_data array) {
    if (!array) return 0;
    Array<IkConstraintData *> *_array = (Array<IkConstraintData *>*) array;
    return _array->size();
}

void spine_array_ik_constraint_data_ensure_capacity(spine_array_ik_constraint_data array, size_t newCapacity) {
    if (!array) return;
    Array<IkConstraintData *> *_array = (Array<IkConstraintData *>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_ik_constraint_data_add(spine_array_ik_constraint_data array, spine_ik_constraint_data inValue) {
    if (!array) return;
    Array<IkConstraintData *> *_array = (Array<IkConstraintData *>*) array;
    _array->add((IkConstraintData *) inValue);
}

void spine_array_ik_constraint_data_remove_at(spine_array_ik_constraint_data array, size_t inIndex) {
    if (!array) return;
    Array<IkConstraintData *> *_array = (Array<IkConstraintData *>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_ik_constraint_data_contains(spine_array_ik_constraint_data array, spine_ik_constraint_data inValue) {
    if (!array) return false;
    Array<IkConstraintData *> *_array = (Array<IkConstraintData *>*) array;
    return _array->contains((IkConstraintData *) inValue);
}

int spine_array_ik_constraint_data_index_of(spine_array_ik_constraint_data array, spine_ik_constraint_data inValue) {
    if (!array) return 0;
    Array<IkConstraintData *> *_array = (Array<IkConstraintData *>*) array;
    return _array->indexOf((IkConstraintData *) inValue);
}

spine_ik_constraint_data spine_array_ik_constraint_data_buffer(spine_array_ik_constraint_data array) {
    if (!array) return nullptr;
    Array<IkConstraintData *> *_array = (Array<IkConstraintData *>*) array;
    return (spine_ik_constraint_data) _array->buffer();
}

spine_array_int spine_array_int_create() {
    return (spine_array_int) new (__FILE__, __LINE__) Array<int>();
}

void spine_array_int_dispose(spine_array_int array) {
    if (!array) return;
    delete (Array<int>*) array;
}

int spine_array_int_get(spine_array_int array, int index) {
    if (!array) return 0;
    Array<int> *_array = (Array<int>*) array;
    return (*_array)[index];
}

void spine_array_int_set(spine_array_int array, int index, int value) {
    if (!array) return;
    Array<int> *_array = (Array<int>*) array;
    (*_array)[index] = value;
}

void spine_array_int_clear(spine_array_int array) {
    if (!array) return;
    Array<int> *_array = (Array<int>*) array;
    _array->clear();
}

size_t spine_array_int_get_capacity(spine_array_int array) {
    if (!array) return 0;
    Array<int> *_array = (Array<int>*) array;
    return _array->getCapacity();
}

size_t spine_array_int_size(spine_array_int array) {
    if (!array) return 0;
    Array<int> *_array = (Array<int>*) array;
    return _array->size();
}

void spine_array_int_ensure_capacity(spine_array_int array, size_t newCapacity) {
    if (!array) return;
    Array<int> *_array = (Array<int>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_int_add(spine_array_int array, int inValue) {
    if (!array) return;
    Array<int> *_array = (Array<int>*) array;
    _array->add(inValue);
}

void spine_array_int_remove_at(spine_array_int array, size_t inIndex) {
    if (!array) return;
    Array<int> *_array = (Array<int>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_int_contains(spine_array_int array, int inValue) {
    if (!array) return false;
    Array<int> *_array = (Array<int>*) array;
    return _array->contains(inValue);
}

int spine_array_int_index_of(spine_array_int array, int inValue) {
    if (!array) return 0;
    Array<int> *_array = (Array<int>*) array;
    return _array->indexOf(inValue);
}

int *spine_array_int_buffer(spine_array_int array) {
    if (!array) return nullptr;
    Array<int> *_array = (Array<int>*) array;
    return _array->buffer();
}

spine_array_path_constraint_data spine_array_path_constraint_data_create() {
    return (spine_array_path_constraint_data) new (__FILE__, __LINE__) Array<PathConstraintData *>();
}

void spine_array_path_constraint_data_dispose(spine_array_path_constraint_data array) {
    if (!array) return;
    delete (Array<PathConstraintData *>*) array;
}

spine_path_constraint_data spine_array_path_constraint_data_get(spine_array_path_constraint_data array, int index) {
    if (!array) return nullptr;
    Array<PathConstraintData *> *_array = (Array<PathConstraintData *>*) array;
    return (spine_path_constraint_data) (*_array)[index];
}

void spine_array_path_constraint_data_set(spine_array_path_constraint_data array, int index, spine_path_constraint_data value) {
    if (!array) return;
    Array<PathConstraintData *> *_array = (Array<PathConstraintData *>*) array;
    (*_array)[index] = (PathConstraintData *) value;
}

void spine_array_path_constraint_data_clear(spine_array_path_constraint_data array) {
    if (!array) return;
    Array<PathConstraintData *> *_array = (Array<PathConstraintData *>*) array;
    _array->clear();
}

size_t spine_array_path_constraint_data_get_capacity(spine_array_path_constraint_data array) {
    if (!array) return 0;
    Array<PathConstraintData *> *_array = (Array<PathConstraintData *>*) array;
    return _array->getCapacity();
}

size_t spine_array_path_constraint_data_size(spine_array_path_constraint_data array) {
    if (!array) return 0;
    Array<PathConstraintData *> *_array = (Array<PathConstraintData *>*) array;
    return _array->size();
}

void spine_array_path_constraint_data_ensure_capacity(spine_array_path_constraint_data array, size_t newCapacity) {
    if (!array) return;
    Array<PathConstraintData *> *_array = (Array<PathConstraintData *>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_path_constraint_data_add(spine_array_path_constraint_data array, spine_path_constraint_data inValue) {
    if (!array) return;
    Array<PathConstraintData *> *_array = (Array<PathConstraintData *>*) array;
    _array->add((PathConstraintData *) inValue);
}

void spine_array_path_constraint_data_remove_at(spine_array_path_constraint_data array, size_t inIndex) {
    if (!array) return;
    Array<PathConstraintData *> *_array = (Array<PathConstraintData *>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_path_constraint_data_contains(spine_array_path_constraint_data array, spine_path_constraint_data inValue) {
    if (!array) return false;
    Array<PathConstraintData *> *_array = (Array<PathConstraintData *>*) array;
    return _array->contains((PathConstraintData *) inValue);
}

int spine_array_path_constraint_data_index_of(spine_array_path_constraint_data array, spine_path_constraint_data inValue) {
    if (!array) return 0;
    Array<PathConstraintData *> *_array = (Array<PathConstraintData *>*) array;
    return _array->indexOf((PathConstraintData *) inValue);
}

spine_path_constraint_data spine_array_path_constraint_data_buffer(spine_array_path_constraint_data array) {
    if (!array) return nullptr;
    Array<PathConstraintData *> *_array = (Array<PathConstraintData *>*) array;
    return (spine_path_constraint_data) _array->buffer();
}

spine_array_physics_constraint spine_array_physics_constraint_create() {
    return (spine_array_physics_constraint) new (__FILE__, __LINE__) Array<PhysicsConstraint *>();
}

void spine_array_physics_constraint_dispose(spine_array_physics_constraint array) {
    if (!array) return;
    delete (Array<PhysicsConstraint *>*) array;
}

spine_physics_constraint spine_array_physics_constraint_get(spine_array_physics_constraint array, int index) {
    if (!array) return nullptr;
    Array<PhysicsConstraint *> *_array = (Array<PhysicsConstraint *>*) array;
    return (spine_physics_constraint) (*_array)[index];
}

void spine_array_physics_constraint_set(spine_array_physics_constraint array, int index, spine_physics_constraint value) {
    if (!array) return;
    Array<PhysicsConstraint *> *_array = (Array<PhysicsConstraint *>*) array;
    (*_array)[index] = (PhysicsConstraint *) value;
}

void spine_array_physics_constraint_clear(spine_array_physics_constraint array) {
    if (!array) return;
    Array<PhysicsConstraint *> *_array = (Array<PhysicsConstraint *>*) array;
    _array->clear();
}

size_t spine_array_physics_constraint_get_capacity(spine_array_physics_constraint array) {
    if (!array) return 0;
    Array<PhysicsConstraint *> *_array = (Array<PhysicsConstraint *>*) array;
    return _array->getCapacity();
}

size_t spine_array_physics_constraint_size(spine_array_physics_constraint array) {
    if (!array) return 0;
    Array<PhysicsConstraint *> *_array = (Array<PhysicsConstraint *>*) array;
    return _array->size();
}

void spine_array_physics_constraint_ensure_capacity(spine_array_physics_constraint array, size_t newCapacity) {
    if (!array) return;
    Array<PhysicsConstraint *> *_array = (Array<PhysicsConstraint *>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_physics_constraint_add(spine_array_physics_constraint array, spine_physics_constraint inValue) {
    if (!array) return;
    Array<PhysicsConstraint *> *_array = (Array<PhysicsConstraint *>*) array;
    _array->add((PhysicsConstraint *) inValue);
}

void spine_array_physics_constraint_remove_at(spine_array_physics_constraint array, size_t inIndex) {
    if (!array) return;
    Array<PhysicsConstraint *> *_array = (Array<PhysicsConstraint *>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_physics_constraint_contains(spine_array_physics_constraint array, spine_physics_constraint inValue) {
    if (!array) return false;
    Array<PhysicsConstraint *> *_array = (Array<PhysicsConstraint *>*) array;
    return _array->contains((PhysicsConstraint *) inValue);
}

int spine_array_physics_constraint_index_of(spine_array_physics_constraint array, spine_physics_constraint inValue) {
    if (!array) return 0;
    Array<PhysicsConstraint *> *_array = (Array<PhysicsConstraint *>*) array;
    return _array->indexOf((PhysicsConstraint *) inValue);
}

spine_physics_constraint spine_array_physics_constraint_buffer(spine_array_physics_constraint array) {
    if (!array) return nullptr;
    Array<PhysicsConstraint *> *_array = (Array<PhysicsConstraint *>*) array;
    return (spine_physics_constraint) _array->buffer();
}

spine_array_physics_constraint_data spine_array_physics_constraint_data_create() {
    return (spine_array_physics_constraint_data) new (__FILE__, __LINE__) Array<PhysicsConstraintData *>();
}

void spine_array_physics_constraint_data_dispose(spine_array_physics_constraint_data array) {
    if (!array) return;
    delete (Array<PhysicsConstraintData *>*) array;
}

spine_physics_constraint_data spine_array_physics_constraint_data_get(spine_array_physics_constraint_data array, int index) {
    if (!array) return nullptr;
    Array<PhysicsConstraintData *> *_array = (Array<PhysicsConstraintData *>*) array;
    return (spine_physics_constraint_data) (*_array)[index];
}

void spine_array_physics_constraint_data_set(spine_array_physics_constraint_data array, int index, spine_physics_constraint_data value) {
    if (!array) return;
    Array<PhysicsConstraintData *> *_array = (Array<PhysicsConstraintData *>*) array;
    (*_array)[index] = (PhysicsConstraintData *) value;
}

void spine_array_physics_constraint_data_clear(spine_array_physics_constraint_data array) {
    if (!array) return;
    Array<PhysicsConstraintData *> *_array = (Array<PhysicsConstraintData *>*) array;
    _array->clear();
}

size_t spine_array_physics_constraint_data_get_capacity(spine_array_physics_constraint_data array) {
    if (!array) return 0;
    Array<PhysicsConstraintData *> *_array = (Array<PhysicsConstraintData *>*) array;
    return _array->getCapacity();
}

size_t spine_array_physics_constraint_data_size(spine_array_physics_constraint_data array) {
    if (!array) return 0;
    Array<PhysicsConstraintData *> *_array = (Array<PhysicsConstraintData *>*) array;
    return _array->size();
}

void spine_array_physics_constraint_data_ensure_capacity(spine_array_physics_constraint_data array, size_t newCapacity) {
    if (!array) return;
    Array<PhysicsConstraintData *> *_array = (Array<PhysicsConstraintData *>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_physics_constraint_data_add(spine_array_physics_constraint_data array, spine_physics_constraint_data inValue) {
    if (!array) return;
    Array<PhysicsConstraintData *> *_array = (Array<PhysicsConstraintData *>*) array;
    _array->add((PhysicsConstraintData *) inValue);
}

void spine_array_physics_constraint_data_remove_at(spine_array_physics_constraint_data array, size_t inIndex) {
    if (!array) return;
    Array<PhysicsConstraintData *> *_array = (Array<PhysicsConstraintData *>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_physics_constraint_data_contains(spine_array_physics_constraint_data array, spine_physics_constraint_data inValue) {
    if (!array) return false;
    Array<PhysicsConstraintData *> *_array = (Array<PhysicsConstraintData *>*) array;
    return _array->contains((PhysicsConstraintData *) inValue);
}

int spine_array_physics_constraint_data_index_of(spine_array_physics_constraint_data array, spine_physics_constraint_data inValue) {
    if (!array) return 0;
    Array<PhysicsConstraintData *> *_array = (Array<PhysicsConstraintData *>*) array;
    return _array->indexOf((PhysicsConstraintData *) inValue);
}

spine_physics_constraint_data spine_array_physics_constraint_data_buffer(spine_array_physics_constraint_data array) {
    if (!array) return nullptr;
    Array<PhysicsConstraintData *> *_array = (Array<PhysicsConstraintData *>*) array;
    return (spine_physics_constraint_data) _array->buffer();
}

spine_array_polygon spine_array_polygon_create() {
    return (spine_array_polygon) new (__FILE__, __LINE__) Array<Polygon *>();
}

void spine_array_polygon_dispose(spine_array_polygon array) {
    if (!array) return;
    delete (Array<Polygon *>*) array;
}

spine_polygon spine_array_polygon_get(spine_array_polygon array, int index) {
    if (!array) return nullptr;
    Array<Polygon *> *_array = (Array<Polygon *>*) array;
    return (spine_polygon) (*_array)[index];
}

void spine_array_polygon_set(spine_array_polygon array, int index, spine_polygon value) {
    if (!array) return;
    Array<Polygon *> *_array = (Array<Polygon *>*) array;
    (*_array)[index] = (Polygon *) value;
}

void spine_array_polygon_clear(spine_array_polygon array) {
    if (!array) return;
    Array<Polygon *> *_array = (Array<Polygon *>*) array;
    _array->clear();
}

size_t spine_array_polygon_get_capacity(spine_array_polygon array) {
    if (!array) return 0;
    Array<Polygon *> *_array = (Array<Polygon *>*) array;
    return _array->getCapacity();
}

size_t spine_array_polygon_size(spine_array_polygon array) {
    if (!array) return 0;
    Array<Polygon *> *_array = (Array<Polygon *>*) array;
    return _array->size();
}

void spine_array_polygon_ensure_capacity(spine_array_polygon array, size_t newCapacity) {
    if (!array) return;
    Array<Polygon *> *_array = (Array<Polygon *>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_polygon_add(spine_array_polygon array, spine_polygon inValue) {
    if (!array) return;
    Array<Polygon *> *_array = (Array<Polygon *>*) array;
    _array->add((Polygon *) inValue);
}

void spine_array_polygon_remove_at(spine_array_polygon array, size_t inIndex) {
    if (!array) return;
    Array<Polygon *> *_array = (Array<Polygon *>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_polygon_contains(spine_array_polygon array, spine_polygon inValue) {
    if (!array) return false;
    Array<Polygon *> *_array = (Array<Polygon *>*) array;
    return _array->contains((Polygon *) inValue);
}

int spine_array_polygon_index_of(spine_array_polygon array, spine_polygon inValue) {
    if (!array) return 0;
    Array<Polygon *> *_array = (Array<Polygon *>*) array;
    return _array->indexOf((Polygon *) inValue);
}

spine_polygon spine_array_polygon_buffer(spine_array_polygon array) {
    if (!array) return nullptr;
    Array<Polygon *> *_array = (Array<Polygon *>*) array;
    return (spine_polygon) _array->buffer();
}

spine_array_property_id spine_array_property_id_create() {
    return (spine_array_property_id) new (__FILE__, __LINE__) Array<PropertyId>();
}

void spine_array_property_id_dispose(spine_array_property_id array) {
    if (!array) return;
    delete (Array<PropertyId>*) array;
}

int64_t spine_array_property_id_get(spine_array_property_id array, int index) {
    if (!array) return 0;
    Array<PropertyId> *_array = (Array<PropertyId>*) array;
    return (*_array)[index];
}

void spine_array_property_id_set(spine_array_property_id array, int index, int64_t value) {
    if (!array) return;
    Array<PropertyId> *_array = (Array<PropertyId>*) array;
    (*_array)[index] = value;
}

void spine_array_property_id_clear(spine_array_property_id array) {
    if (!array) return;
    Array<PropertyId> *_array = (Array<PropertyId>*) array;
    _array->clear();
}

size_t spine_array_property_id_get_capacity(spine_array_property_id array) {
    if (!array) return 0;
    Array<PropertyId> *_array = (Array<PropertyId>*) array;
    return _array->getCapacity();
}

size_t spine_array_property_id_size(spine_array_property_id array) {
    if (!array) return 0;
    Array<PropertyId> *_array = (Array<PropertyId>*) array;
    return _array->size();
}

void spine_array_property_id_ensure_capacity(spine_array_property_id array, size_t newCapacity) {
    if (!array) return;
    Array<PropertyId> *_array = (Array<PropertyId>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_property_id_add(spine_array_property_id array, int64_t inValue) {
    if (!array) return;
    Array<PropertyId> *_array = (Array<PropertyId>*) array;
    _array->add(inValue);
}

void spine_array_property_id_remove_at(spine_array_property_id array, size_t inIndex) {
    if (!array) return;
    Array<PropertyId> *_array = (Array<PropertyId>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_property_id_contains(spine_array_property_id array, int64_t inValue) {
    if (!array) return false;
    Array<PropertyId> *_array = (Array<PropertyId>*) array;
    return _array->contains(inValue);
}

int spine_array_property_id_index_of(spine_array_property_id array, int64_t inValue) {
    if (!array) return 0;
    Array<PropertyId> *_array = (Array<PropertyId>*) array;
    return _array->indexOf(inValue);
}

int64_t *spine_array_property_id_buffer(spine_array_property_id array) {
    if (!array) return nullptr;
    Array<PropertyId> *_array = (Array<PropertyId>*) array;
    return _array->buffer();
}

spine_array_skin spine_array_skin_create() {
    return (spine_array_skin) new (__FILE__, __LINE__) Array<Skin *>();
}

void spine_array_skin_dispose(spine_array_skin array) {
    if (!array) return;
    delete (Array<Skin *>*) array;
}

spine_skin spine_array_skin_get(spine_array_skin array, int index) {
    if (!array) return nullptr;
    Array<Skin *> *_array = (Array<Skin *>*) array;
    return (spine_skin) (*_array)[index];
}

void spine_array_skin_set(spine_array_skin array, int index, spine_skin value) {
    if (!array) return;
    Array<Skin *> *_array = (Array<Skin *>*) array;
    (*_array)[index] = (Skin *) value;
}

void spine_array_skin_clear(spine_array_skin array) {
    if (!array) return;
    Array<Skin *> *_array = (Array<Skin *>*) array;
    _array->clear();
}

size_t spine_array_skin_get_capacity(spine_array_skin array) {
    if (!array) return 0;
    Array<Skin *> *_array = (Array<Skin *>*) array;
    return _array->getCapacity();
}

size_t spine_array_skin_size(spine_array_skin array) {
    if (!array) return 0;
    Array<Skin *> *_array = (Array<Skin *>*) array;
    return _array->size();
}

void spine_array_skin_ensure_capacity(spine_array_skin array, size_t newCapacity) {
    if (!array) return;
    Array<Skin *> *_array = (Array<Skin *>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_skin_add(spine_array_skin array, spine_skin inValue) {
    if (!array) return;
    Array<Skin *> *_array = (Array<Skin *>*) array;
    _array->add((Skin *) inValue);
}

void spine_array_skin_remove_at(spine_array_skin array, size_t inIndex) {
    if (!array) return;
    Array<Skin *> *_array = (Array<Skin *>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_skin_contains(spine_array_skin array, spine_skin inValue) {
    if (!array) return false;
    Array<Skin *> *_array = (Array<Skin *>*) array;
    return _array->contains((Skin *) inValue);
}

int spine_array_skin_index_of(spine_array_skin array, spine_skin inValue) {
    if (!array) return 0;
    Array<Skin *> *_array = (Array<Skin *>*) array;
    return _array->indexOf((Skin *) inValue);
}

spine_skin spine_array_skin_buffer(spine_array_skin array) {
    if (!array) return nullptr;
    Array<Skin *> *_array = (Array<Skin *>*) array;
    return (spine_skin) _array->buffer();
}

spine_array_slot spine_array_slot_create() {
    return (spine_array_slot) new (__FILE__, __LINE__) Array<Slot *>();
}

void spine_array_slot_dispose(spine_array_slot array) {
    if (!array) return;
    delete (Array<Slot *>*) array;
}

spine_slot spine_array_slot_get(spine_array_slot array, int index) {
    if (!array) return nullptr;
    Array<Slot *> *_array = (Array<Slot *>*) array;
    return (spine_slot) (*_array)[index];
}

void spine_array_slot_set(spine_array_slot array, int index, spine_slot value) {
    if (!array) return;
    Array<Slot *> *_array = (Array<Slot *>*) array;
    (*_array)[index] = (Slot *) value;
}

void spine_array_slot_clear(spine_array_slot array) {
    if (!array) return;
    Array<Slot *> *_array = (Array<Slot *>*) array;
    _array->clear();
}

size_t spine_array_slot_get_capacity(spine_array_slot array) {
    if (!array) return 0;
    Array<Slot *> *_array = (Array<Slot *>*) array;
    return _array->getCapacity();
}

size_t spine_array_slot_size(spine_array_slot array) {
    if (!array) return 0;
    Array<Slot *> *_array = (Array<Slot *>*) array;
    return _array->size();
}

void spine_array_slot_ensure_capacity(spine_array_slot array, size_t newCapacity) {
    if (!array) return;
    Array<Slot *> *_array = (Array<Slot *>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_slot_add(spine_array_slot array, spine_slot inValue) {
    if (!array) return;
    Array<Slot *> *_array = (Array<Slot *>*) array;
    _array->add((Slot *) inValue);
}

void spine_array_slot_remove_at(spine_array_slot array, size_t inIndex) {
    if (!array) return;
    Array<Slot *> *_array = (Array<Slot *>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_slot_contains(spine_array_slot array, spine_slot inValue) {
    if (!array) return false;
    Array<Slot *> *_array = (Array<Slot *>*) array;
    return _array->contains((Slot *) inValue);
}

int spine_array_slot_index_of(spine_array_slot array, spine_slot inValue) {
    if (!array) return 0;
    Array<Slot *> *_array = (Array<Slot *>*) array;
    return _array->indexOf((Slot *) inValue);
}

spine_slot spine_array_slot_buffer(spine_array_slot array) {
    if (!array) return nullptr;
    Array<Slot *> *_array = (Array<Slot *>*) array;
    return (spine_slot) _array->buffer();
}

spine_array_slot_data spine_array_slot_data_create() {
    return (spine_array_slot_data) new (__FILE__, __LINE__) Array<SlotData *>();
}

void spine_array_slot_data_dispose(spine_array_slot_data array) {
    if (!array) return;
    delete (Array<SlotData *>*) array;
}

spine_slot_data spine_array_slot_data_get(spine_array_slot_data array, int index) {
    if (!array) return nullptr;
    Array<SlotData *> *_array = (Array<SlotData *>*) array;
    return (spine_slot_data) (*_array)[index];
}

void spine_array_slot_data_set(spine_array_slot_data array, int index, spine_slot_data value) {
    if (!array) return;
    Array<SlotData *> *_array = (Array<SlotData *>*) array;
    (*_array)[index] = (SlotData *) value;
}

void spine_array_slot_data_clear(spine_array_slot_data array) {
    if (!array) return;
    Array<SlotData *> *_array = (Array<SlotData *>*) array;
    _array->clear();
}

size_t spine_array_slot_data_get_capacity(spine_array_slot_data array) {
    if (!array) return 0;
    Array<SlotData *> *_array = (Array<SlotData *>*) array;
    return _array->getCapacity();
}

size_t spine_array_slot_data_size(spine_array_slot_data array) {
    if (!array) return 0;
    Array<SlotData *> *_array = (Array<SlotData *>*) array;
    return _array->size();
}

void spine_array_slot_data_ensure_capacity(spine_array_slot_data array, size_t newCapacity) {
    if (!array) return;
    Array<SlotData *> *_array = (Array<SlotData *>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_slot_data_add(spine_array_slot_data array, spine_slot_data inValue) {
    if (!array) return;
    Array<SlotData *> *_array = (Array<SlotData *>*) array;
    _array->add((SlotData *) inValue);
}

void spine_array_slot_data_remove_at(spine_array_slot_data array, size_t inIndex) {
    if (!array) return;
    Array<SlotData *> *_array = (Array<SlotData *>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_slot_data_contains(spine_array_slot_data array, spine_slot_data inValue) {
    if (!array) return false;
    Array<SlotData *> *_array = (Array<SlotData *>*) array;
    return _array->contains((SlotData *) inValue);
}

int spine_array_slot_data_index_of(spine_array_slot_data array, spine_slot_data inValue) {
    if (!array) return 0;
    Array<SlotData *> *_array = (Array<SlotData *>*) array;
    return _array->indexOf((SlotData *) inValue);
}

spine_slot_data spine_array_slot_data_buffer(spine_array_slot_data array) {
    if (!array) return nullptr;
    Array<SlotData *> *_array = (Array<SlotData *>*) array;
    return (spine_slot_data) _array->buffer();
}

spine_array_texture_region spine_array_texture_region_create() {
    return (spine_array_texture_region) new (__FILE__, __LINE__) Array<TextureRegion *>();
}

void spine_array_texture_region_dispose(spine_array_texture_region array) {
    if (!array) return;
    delete (Array<TextureRegion *>*) array;
}

spine_texture_region spine_array_texture_region_get(spine_array_texture_region array, int index) {
    if (!array) return nullptr;
    Array<TextureRegion *> *_array = (Array<TextureRegion *>*) array;
    return (spine_texture_region) (*_array)[index];
}

void spine_array_texture_region_set(spine_array_texture_region array, int index, spine_texture_region value) {
    if (!array) return;
    Array<TextureRegion *> *_array = (Array<TextureRegion *>*) array;
    (*_array)[index] = (TextureRegion *) value;
}

void spine_array_texture_region_clear(spine_array_texture_region array) {
    if (!array) return;
    Array<TextureRegion *> *_array = (Array<TextureRegion *>*) array;
    _array->clear();
}

size_t spine_array_texture_region_get_capacity(spine_array_texture_region array) {
    if (!array) return 0;
    Array<TextureRegion *> *_array = (Array<TextureRegion *>*) array;
    return _array->getCapacity();
}

size_t spine_array_texture_region_size(spine_array_texture_region array) {
    if (!array) return 0;
    Array<TextureRegion *> *_array = (Array<TextureRegion *>*) array;
    return _array->size();
}

void spine_array_texture_region_ensure_capacity(spine_array_texture_region array, size_t newCapacity) {
    if (!array) return;
    Array<TextureRegion *> *_array = (Array<TextureRegion *>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_texture_region_add(spine_array_texture_region array, spine_texture_region inValue) {
    if (!array) return;
    Array<TextureRegion *> *_array = (Array<TextureRegion *>*) array;
    _array->add((TextureRegion *) inValue);
}

void spine_array_texture_region_remove_at(spine_array_texture_region array, size_t inIndex) {
    if (!array) return;
    Array<TextureRegion *> *_array = (Array<TextureRegion *>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_texture_region_contains(spine_array_texture_region array, spine_texture_region inValue) {
    if (!array) return false;
    Array<TextureRegion *> *_array = (Array<TextureRegion *>*) array;
    return _array->contains((TextureRegion *) inValue);
}

int spine_array_texture_region_index_of(spine_array_texture_region array, spine_texture_region inValue) {
    if (!array) return 0;
    Array<TextureRegion *> *_array = (Array<TextureRegion *>*) array;
    return _array->indexOf((TextureRegion *) inValue);
}

spine_texture_region spine_array_texture_region_buffer(spine_array_texture_region array) {
    if (!array) return nullptr;
    Array<TextureRegion *> *_array = (Array<TextureRegion *>*) array;
    return (spine_texture_region) _array->buffer();
}

spine_array_timeline spine_array_timeline_create() {
    return (spine_array_timeline) new (__FILE__, __LINE__) Array<Timeline *>();
}

void spine_array_timeline_dispose(spine_array_timeline array) {
    if (!array) return;
    delete (Array<Timeline *>*) array;
}

spine_timeline spine_array_timeline_get(spine_array_timeline array, int index) {
    if (!array) return nullptr;
    Array<Timeline *> *_array = (Array<Timeline *>*) array;
    return (spine_timeline) (*_array)[index];
}

void spine_array_timeline_set(spine_array_timeline array, int index, spine_timeline value) {
    if (!array) return;
    Array<Timeline *> *_array = (Array<Timeline *>*) array;
    (*_array)[index] = (Timeline *) value;
}

void spine_array_timeline_clear(spine_array_timeline array) {
    if (!array) return;
    Array<Timeline *> *_array = (Array<Timeline *>*) array;
    _array->clear();
}

size_t spine_array_timeline_get_capacity(spine_array_timeline array) {
    if (!array) return 0;
    Array<Timeline *> *_array = (Array<Timeline *>*) array;
    return _array->getCapacity();
}

size_t spine_array_timeline_size(spine_array_timeline array) {
    if (!array) return 0;
    Array<Timeline *> *_array = (Array<Timeline *>*) array;
    return _array->size();
}

void spine_array_timeline_ensure_capacity(spine_array_timeline array, size_t newCapacity) {
    if (!array) return;
    Array<Timeline *> *_array = (Array<Timeline *>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_timeline_add(spine_array_timeline array, spine_timeline inValue) {
    if (!array) return;
    Array<Timeline *> *_array = (Array<Timeline *>*) array;
    _array->add((Timeline *) inValue);
}

void spine_array_timeline_remove_at(spine_array_timeline array, size_t inIndex) {
    if (!array) return;
    Array<Timeline *> *_array = (Array<Timeline *>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_timeline_contains(spine_array_timeline array, spine_timeline inValue) {
    if (!array) return false;
    Array<Timeline *> *_array = (Array<Timeline *>*) array;
    return _array->contains((Timeline *) inValue);
}

int spine_array_timeline_index_of(spine_array_timeline array, spine_timeline inValue) {
    if (!array) return 0;
    Array<Timeline *> *_array = (Array<Timeline *>*) array;
    return _array->indexOf((Timeline *) inValue);
}

spine_timeline spine_array_timeline_buffer(spine_array_timeline array) {
    if (!array) return nullptr;
    Array<Timeline *> *_array = (Array<Timeline *>*) array;
    return (spine_timeline) _array->buffer();
}

spine_array_to_property spine_array_to_property_create() {
    return (spine_array_to_property) new (__FILE__, __LINE__) Array<class ToProperty *>();
}

void spine_array_to_property_dispose(spine_array_to_property array) {
    if (!array) return;
    delete (Array<class ToProperty *>*) array;
}

spine_to_property spine_array_to_property_get(spine_array_to_property array, int index) {
    if (!array) return nullptr;
    Array<class ToProperty *> *_array = (Array<class ToProperty *>*) array;
    return (spine_to_property) (*_array)[index];
}

void spine_array_to_property_set(spine_array_to_property array, int index, spine_to_property value) {
    if (!array) return;
    Array<class ToProperty *> *_array = (Array<class ToProperty *>*) array;
    (*_array)[index] = (class ToProperty *) value;
}

void spine_array_to_property_clear(spine_array_to_property array) {
    if (!array) return;
    Array<class ToProperty *> *_array = (Array<class ToProperty *>*) array;
    _array->clear();
}

size_t spine_array_to_property_get_capacity(spine_array_to_property array) {
    if (!array) return 0;
    Array<class ToProperty *> *_array = (Array<class ToProperty *>*) array;
    return _array->getCapacity();
}

size_t spine_array_to_property_size(spine_array_to_property array) {
    if (!array) return 0;
    Array<class ToProperty *> *_array = (Array<class ToProperty *>*) array;
    return _array->size();
}

void spine_array_to_property_ensure_capacity(spine_array_to_property array, size_t newCapacity) {
    if (!array) return;
    Array<class ToProperty *> *_array = (Array<class ToProperty *>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_to_property_add(spine_array_to_property array, spine_to_property inValue) {
    if (!array) return;
    Array<class ToProperty *> *_array = (Array<class ToProperty *>*) array;
    _array->add((class ToProperty *) inValue);
}

void spine_array_to_property_remove_at(spine_array_to_property array, size_t inIndex) {
    if (!array) return;
    Array<class ToProperty *> *_array = (Array<class ToProperty *>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_to_property_contains(spine_array_to_property array, spine_to_property inValue) {
    if (!array) return false;
    Array<class ToProperty *> *_array = (Array<class ToProperty *>*) array;
    return _array->contains((class ToProperty *) inValue);
}

int spine_array_to_property_index_of(spine_array_to_property array, spine_to_property inValue) {
    if (!array) return 0;
    Array<class ToProperty *> *_array = (Array<class ToProperty *>*) array;
    return _array->indexOf((class ToProperty *) inValue);
}

spine_to_property spine_array_to_property_buffer(spine_array_to_property array) {
    if (!array) return nullptr;
    Array<class ToProperty *> *_array = (Array<class ToProperty *>*) array;
    return (spine_to_property) _array->buffer();
}

spine_array_track_entry spine_array_track_entry_create() {
    return (spine_array_track_entry) new (__FILE__, __LINE__) Array<TrackEntry *>();
}

void spine_array_track_entry_dispose(spine_array_track_entry array) {
    if (!array) return;
    delete (Array<TrackEntry *>*) array;
}

spine_track_entry spine_array_track_entry_get(spine_array_track_entry array, int index) {
    if (!array) return nullptr;
    Array<TrackEntry *> *_array = (Array<TrackEntry *>*) array;
    return (spine_track_entry) (*_array)[index];
}

void spine_array_track_entry_set(spine_array_track_entry array, int index, spine_track_entry value) {
    if (!array) return;
    Array<TrackEntry *> *_array = (Array<TrackEntry *>*) array;
    (*_array)[index] = (TrackEntry *) value;
}

void spine_array_track_entry_clear(spine_array_track_entry array) {
    if (!array) return;
    Array<TrackEntry *> *_array = (Array<TrackEntry *>*) array;
    _array->clear();
}

size_t spine_array_track_entry_get_capacity(spine_array_track_entry array) {
    if (!array) return 0;
    Array<TrackEntry *> *_array = (Array<TrackEntry *>*) array;
    return _array->getCapacity();
}

size_t spine_array_track_entry_size(spine_array_track_entry array) {
    if (!array) return 0;
    Array<TrackEntry *> *_array = (Array<TrackEntry *>*) array;
    return _array->size();
}

void spine_array_track_entry_ensure_capacity(spine_array_track_entry array, size_t newCapacity) {
    if (!array) return;
    Array<TrackEntry *> *_array = (Array<TrackEntry *>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_track_entry_add(spine_array_track_entry array, spine_track_entry inValue) {
    if (!array) return;
    Array<TrackEntry *> *_array = (Array<TrackEntry *>*) array;
    _array->add((TrackEntry *) inValue);
}

void spine_array_track_entry_remove_at(spine_array_track_entry array, size_t inIndex) {
    if (!array) return;
    Array<TrackEntry *> *_array = (Array<TrackEntry *>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_track_entry_contains(spine_array_track_entry array, spine_track_entry inValue) {
    if (!array) return false;
    Array<TrackEntry *> *_array = (Array<TrackEntry *>*) array;
    return _array->contains((TrackEntry *) inValue);
}

int spine_array_track_entry_index_of(spine_array_track_entry array, spine_track_entry inValue) {
    if (!array) return 0;
    Array<TrackEntry *> *_array = (Array<TrackEntry *>*) array;
    return _array->indexOf((TrackEntry *) inValue);
}

spine_track_entry spine_array_track_entry_buffer(spine_array_track_entry array) {
    if (!array) return nullptr;
    Array<TrackEntry *> *_array = (Array<TrackEntry *>*) array;
    return (spine_track_entry) _array->buffer();
}

spine_array_transform_constraint_data spine_array_transform_constraint_data_create() {
    return (spine_array_transform_constraint_data) new (__FILE__, __LINE__) Array<TransformConstraintData *>();
}

void spine_array_transform_constraint_data_dispose(spine_array_transform_constraint_data array) {
    if (!array) return;
    delete (Array<TransformConstraintData *>*) array;
}

spine_transform_constraint_data spine_array_transform_constraint_data_get(spine_array_transform_constraint_data array, int index) {
    if (!array) return nullptr;
    Array<TransformConstraintData *> *_array = (Array<TransformConstraintData *>*) array;
    return (spine_transform_constraint_data) (*_array)[index];
}

void spine_array_transform_constraint_data_set(spine_array_transform_constraint_data array, int index, spine_transform_constraint_data value) {
    if (!array) return;
    Array<TransformConstraintData *> *_array = (Array<TransformConstraintData *>*) array;
    (*_array)[index] = (TransformConstraintData *) value;
}

void spine_array_transform_constraint_data_clear(spine_array_transform_constraint_data array) {
    if (!array) return;
    Array<TransformConstraintData *> *_array = (Array<TransformConstraintData *>*) array;
    _array->clear();
}

size_t spine_array_transform_constraint_data_get_capacity(spine_array_transform_constraint_data array) {
    if (!array) return 0;
    Array<TransformConstraintData *> *_array = (Array<TransformConstraintData *>*) array;
    return _array->getCapacity();
}

size_t spine_array_transform_constraint_data_size(spine_array_transform_constraint_data array) {
    if (!array) return 0;
    Array<TransformConstraintData *> *_array = (Array<TransformConstraintData *>*) array;
    return _array->size();
}

void spine_array_transform_constraint_data_ensure_capacity(spine_array_transform_constraint_data array, size_t newCapacity) {
    if (!array) return;
    Array<TransformConstraintData *> *_array = (Array<TransformConstraintData *>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_transform_constraint_data_add(spine_array_transform_constraint_data array, spine_transform_constraint_data inValue) {
    if (!array) return;
    Array<TransformConstraintData *> *_array = (Array<TransformConstraintData *>*) array;
    _array->add((TransformConstraintData *) inValue);
}

void spine_array_transform_constraint_data_remove_at(spine_array_transform_constraint_data array, size_t inIndex) {
    if (!array) return;
    Array<TransformConstraintData *> *_array = (Array<TransformConstraintData *>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_transform_constraint_data_contains(spine_array_transform_constraint_data array, spine_transform_constraint_data inValue) {
    if (!array) return false;
    Array<TransformConstraintData *> *_array = (Array<TransformConstraintData *>*) array;
    return _array->contains((TransformConstraintData *) inValue);
}

int spine_array_transform_constraint_data_index_of(spine_array_transform_constraint_data array, spine_transform_constraint_data inValue) {
    if (!array) return 0;
    Array<TransformConstraintData *> *_array = (Array<TransformConstraintData *>*) array;
    return _array->indexOf((TransformConstraintData *) inValue);
}

spine_transform_constraint_data spine_array_transform_constraint_data_buffer(spine_array_transform_constraint_data array) {
    if (!array) return nullptr;
    Array<TransformConstraintData *> *_array = (Array<TransformConstraintData *>*) array;
    return (spine_transform_constraint_data) _array->buffer();
}

spine_array_unsigned_short spine_array_unsigned_short_create() {
    return (spine_array_unsigned_short) new (__FILE__, __LINE__) Array<unsigned short>();
}

void spine_array_unsigned_short_dispose(spine_array_unsigned_short array) {
    if (!array) return;
    delete (Array<unsigned short>*) array;
}

unsigned short spine_array_unsigned_short_get(spine_array_unsigned_short array, int index) {
    if (!array) return 0;
    Array<unsigned short> *_array = (Array<unsigned short>*) array;
    return (*_array)[index];
}

void spine_array_unsigned_short_set(spine_array_unsigned_short array, int index, unsigned short value) {
    if (!array) return;
    Array<unsigned short> *_array = (Array<unsigned short>*) array;
    (*_array)[index] = value;
}

void spine_array_unsigned_short_clear(spine_array_unsigned_short array) {
    if (!array) return;
    Array<unsigned short> *_array = (Array<unsigned short>*) array;
    _array->clear();
}

size_t spine_array_unsigned_short_get_capacity(spine_array_unsigned_short array) {
    if (!array) return 0;
    Array<unsigned short> *_array = (Array<unsigned short>*) array;
    return _array->getCapacity();
}

size_t spine_array_unsigned_short_size(spine_array_unsigned_short array) {
    if (!array) return 0;
    Array<unsigned short> *_array = (Array<unsigned short>*) array;
    return _array->size();
}

void spine_array_unsigned_short_ensure_capacity(spine_array_unsigned_short array, size_t newCapacity) {
    if (!array) return;
    Array<unsigned short> *_array = (Array<unsigned short>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_unsigned_short_add(spine_array_unsigned_short array, unsigned short inValue) {
    if (!array) return;
    Array<unsigned short> *_array = (Array<unsigned short>*) array;
    _array->add(inValue);
}

void spine_array_unsigned_short_remove_at(spine_array_unsigned_short array, size_t inIndex) {
    if (!array) return;
    Array<unsigned short> *_array = (Array<unsigned short>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_unsigned_short_contains(spine_array_unsigned_short array, unsigned short inValue) {
    if (!array) return false;
    Array<unsigned short> *_array = (Array<unsigned short>*) array;
    return _array->contains(inValue);
}

int spine_array_unsigned_short_index_of(spine_array_unsigned_short array, unsigned short inValue) {
    if (!array) return 0;
    Array<unsigned short> *_array = (Array<unsigned short>*) array;
    return _array->indexOf(inValue);
}

unsigned short *spine_array_unsigned_short_buffer(spine_array_unsigned_short array) {
    if (!array) return nullptr;
    Array<unsigned short> *_array = (Array<unsigned short>*) array;
    return _array->buffer();
}

spine_array_update spine_array_update_create() {
    return (spine_array_update) new (__FILE__, __LINE__) Array<Update *>();
}

void spine_array_update_dispose(spine_array_update array) {
    if (!array) return;
    delete (Array<Update *>*) array;
}

spine_update spine_array_update_get(spine_array_update array, int index) {
    if (!array) return nullptr;
    Array<Update *> *_array = (Array<Update *>*) array;
    return (spine_update) (*_array)[index];
}

void spine_array_update_set(spine_array_update array, int index, spine_update value) {
    if (!array) return;
    Array<Update *> *_array = (Array<Update *>*) array;
    (*_array)[index] = (Update *) value;
}

void spine_array_update_clear(spine_array_update array) {
    if (!array) return;
    Array<Update *> *_array = (Array<Update *>*) array;
    _array->clear();
}

size_t spine_array_update_get_capacity(spine_array_update array) {
    if (!array) return 0;
    Array<Update *> *_array = (Array<Update *>*) array;
    return _array->getCapacity();
}

size_t spine_array_update_size(spine_array_update array) {
    if (!array) return 0;
    Array<Update *> *_array = (Array<Update *>*) array;
    return _array->size();
}

void spine_array_update_ensure_capacity(spine_array_update array, size_t newCapacity) {
    if (!array) return;
    Array<Update *> *_array = (Array<Update *>*) array;
    _array->ensureCapacity(newCapacity);
}

void spine_array_update_add(spine_array_update array, spine_update inValue) {
    if (!array) return;
    Array<Update *> *_array = (Array<Update *>*) array;
    _array->add((Update *) inValue);
}

void spine_array_update_remove_at(spine_array_update array, size_t inIndex) {
    if (!array) return;
    Array<Update *> *_array = (Array<Update *>*) array;
    _array->removeAt(inIndex);
}

bool spine_array_update_contains(spine_array_update array, spine_update inValue) {
    if (!array) return false;
    Array<Update *> *_array = (Array<Update *>*) array;
    return _array->contains((Update *) inValue);
}

int spine_array_update_index_of(spine_array_update array, spine_update inValue) {
    if (!array) return 0;
    Array<Update *> *_array = (Array<Update *>*) array;
    return _array->indexOf((Update *) inValue);
}

spine_update spine_array_update_buffer(spine_array_update array) {
    if (!array) return nullptr;
    Array<Update *> *_array = (Array<Update *>*) array;
    return (spine_update) _array->buffer();
}
