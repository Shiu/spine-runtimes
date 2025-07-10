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
#include <spine/spine.h>

using namespace spine;

spine_array_float spine_array_float_create(void) {
    return (spine_array_float) new (__FILE__, __LINE__) Array<float>();
}

spine_array_float spine_array_float_create_with_capacity(size_t initialCapacity) {
    return (spine_array_float) new (__FILE__, __LINE__) Array<float>(initialCapacity);
}
void spine_array_float_dispose(spine_array_float array) {
    delete (Array<float>*)array;
}
void spine_array_float_clear(spine_array_float array) {
    ((Array<float>*)array)->clear();
}

size_t spine_array_float_get_capacity(spine_array_float array) {
    return ((Array<float>*)array)->getCapacity();
}

size_t spine_array_float_size(spine_array_float array) {
    return ((Array<float>*)array)->size();
}

spine_array_float spine_array_float_set_size(spine_array_float array, size_t newSize, float defaultValue) {
    return (spine_array_float)&((Array<float>*)array)->setSize(newSize, defaultValue);
}

void spine_array_float_ensure_capacity(spine_array_float array, size_t newCapacity) {
    ((Array<float>*)array)->ensureCapacity(newCapacity);
}

void spine_array_float_add(spine_array_float array, float inValue) {
    ((Array<float>*)array)->add(inValue);
}

void spine_array_float_add_all(spine_array_float array, spine_array_float inValue) {
    ((Array<float>*)array)->addAll(*((const Array<float>*)inValue));
}

void spine_array_float_clear_and_add_all(spine_array_float array, spine_array_float inValue) {
    ((Array<float>*)array)->clearAndAddAll(*((const Array<float>*)inValue));
}

void spine_array_float_remove_at(spine_array_float array, size_t inIndex) {
    ((Array<float>*)array)->removeAt(inIndex);
}

bool spine_array_float_contains(spine_array_float array, float inValue) {
    return ((Array<float>*)array)->contains(inValue);
}

int spine_array_float_index_of(spine_array_float array, float inValue) {
    return ((Array<float>*)array)->indexOf(inValue);
}

float * spine_array_float_buffer(spine_array_float array) {
    return ((Array<float>*)array)->buffer();
}

spine_array_int spine_array_int_create(void) {
    return (spine_array_int) new (__FILE__, __LINE__) Array<int>();
}

spine_array_int spine_array_int_create_with_capacity(size_t initialCapacity) {
    return (spine_array_int) new (__FILE__, __LINE__) Array<int>(initialCapacity);
}
void spine_array_int_dispose(spine_array_int array) {
    delete (Array<int>*)array;
}
void spine_array_int_clear(spine_array_int array) {
    ((Array<int>*)array)->clear();
}

size_t spine_array_int_get_capacity(spine_array_int array) {
    return ((Array<int>*)array)->getCapacity();
}

size_t spine_array_int_size(spine_array_int array) {
    return ((Array<int>*)array)->size();
}

spine_array_int spine_array_int_set_size(spine_array_int array, size_t newSize, int defaultValue) {
    return (spine_array_int)&((Array<int>*)array)->setSize(newSize, defaultValue);
}

void spine_array_int_ensure_capacity(spine_array_int array, size_t newCapacity) {
    ((Array<int>*)array)->ensureCapacity(newCapacity);
}

void spine_array_int_add(spine_array_int array, int inValue) {
    ((Array<int>*)array)->add(inValue);
}

void spine_array_int_add_all(spine_array_int array, spine_array_int inValue) {
    ((Array<int>*)array)->addAll(*((const Array<int>*)inValue));
}

void spine_array_int_clear_and_add_all(spine_array_int array, spine_array_int inValue) {
    ((Array<int>*)array)->clearAndAddAll(*((const Array<int>*)inValue));
}

void spine_array_int_remove_at(spine_array_int array, size_t inIndex) {
    ((Array<int>*)array)->removeAt(inIndex);
}

bool spine_array_int_contains(spine_array_int array, int inValue) {
    return ((Array<int>*)array)->contains(inValue);
}

int spine_array_int_index_of(spine_array_int array, int inValue) {
    return ((Array<int>*)array)->indexOf(inValue);
}

int * spine_array_int_buffer(spine_array_int array) {
    return ((Array<int>*)array)->buffer();
}

spine_array_unsigned_short spine_array_unsigned_short_create(void) {
    return (spine_array_unsigned_short) new (__FILE__, __LINE__) Array<unsigned short>();
}

spine_array_unsigned_short spine_array_unsigned_short_create_with_capacity(size_t initialCapacity) {
    return (spine_array_unsigned_short) new (__FILE__, __LINE__) Array<unsigned short>(initialCapacity);
}
void spine_array_unsigned_short_dispose(spine_array_unsigned_short array) {
    delete (Array<unsigned short>*)array;
}
void spine_array_unsigned_short_clear(spine_array_unsigned_short array) {
    ((Array<unsigned short>*)array)->clear();
}

size_t spine_array_unsigned_short_get_capacity(spine_array_unsigned_short array) {
    return ((Array<unsigned short>*)array)->getCapacity();
}

size_t spine_array_unsigned_short_size(spine_array_unsigned_short array) {
    return ((Array<unsigned short>*)array)->size();
}

spine_array_unsigned_short spine_array_unsigned_short_set_size(spine_array_unsigned_short array, size_t newSize, unsigned short defaultValue) {
    return (spine_array_unsigned_short)&((Array<unsigned short>*)array)->setSize(newSize, defaultValue);
}

void spine_array_unsigned_short_ensure_capacity(spine_array_unsigned_short array, size_t newCapacity) {
    ((Array<unsigned short>*)array)->ensureCapacity(newCapacity);
}

void spine_array_unsigned_short_add(spine_array_unsigned_short array, unsigned short inValue) {
    ((Array<unsigned short>*)array)->add(inValue);
}

void spine_array_unsigned_short_add_all(spine_array_unsigned_short array, spine_array_unsigned_short inValue) {
    ((Array<unsigned short>*)array)->addAll(*((const Array<unsigned short>*)inValue));
}

void spine_array_unsigned_short_clear_and_add_all(spine_array_unsigned_short array, spine_array_unsigned_short inValue) {
    ((Array<unsigned short>*)array)->clearAndAddAll(*((const Array<unsigned short>*)inValue));
}

void spine_array_unsigned_short_remove_at(spine_array_unsigned_short array, size_t inIndex) {
    ((Array<unsigned short>*)array)->removeAt(inIndex);
}

bool spine_array_unsigned_short_contains(spine_array_unsigned_short array, unsigned short inValue) {
    return ((Array<unsigned short>*)array)->contains(inValue);
}

int spine_array_unsigned_short_index_of(spine_array_unsigned_short array, unsigned short inValue) {
    return ((Array<unsigned short>*)array)->indexOf(inValue);
}

unsigned short * spine_array_unsigned_short_buffer(spine_array_unsigned_short array) {
    return ((Array<unsigned short>*)array)->buffer();
}

spine_array_property_id spine_array_property_id_create(void) {
    return (spine_array_property_id) new (__FILE__, __LINE__) Array<PropertyId>();
}

spine_array_property_id spine_array_property_id_create_with_capacity(size_t initialCapacity) {
    return (spine_array_property_id) new (__FILE__, __LINE__) Array<PropertyId>(initialCapacity);
}
void spine_array_property_id_dispose(spine_array_property_id array) {
    delete (Array<PropertyId>*)array;
}
void spine_array_property_id_clear(spine_array_property_id array) {
    ((Array<PropertyId>*)array)->clear();
}

size_t spine_array_property_id_get_capacity(spine_array_property_id array) {
    return ((Array<PropertyId>*)array)->getCapacity();
}

size_t spine_array_property_id_size(spine_array_property_id array) {
    return ((Array<PropertyId>*)array)->size();
}

spine_array_property_id spine_array_property_id_set_size(spine_array_property_id array, size_t newSize, int64_t defaultValue) {
    return (spine_array_property_id)&((Array<PropertyId>*)array)->setSize(newSize, *((const PropertyId*)defaultValue));
}

void spine_array_property_id_ensure_capacity(spine_array_property_id array, size_t newCapacity) {
    ((Array<PropertyId>*)array)->ensureCapacity(newCapacity);
}

void spine_array_property_id_add(spine_array_property_id array, int64_t inValue) {
    ((Array<PropertyId>*)array)->add(*((const PropertyId*)inValue));
}

void spine_array_property_id_add_all(spine_array_property_id array, spine_array_property_id inValue) {
    ((Array<PropertyId>*)array)->addAll(*((const Array<PropertyId>*)inValue));
}

void spine_array_property_id_clear_and_add_all(spine_array_property_id array, spine_array_property_id inValue) {
    ((Array<PropertyId>*)array)->clearAndAddAll(*((const Array<PropertyId>*)inValue));
}

void spine_array_property_id_remove_at(spine_array_property_id array, size_t inIndex) {
    ((Array<PropertyId>*)array)->removeAt(inIndex);
}

bool spine_array_property_id_contains(spine_array_property_id array, int64_t inValue) {
    return ((Array<PropertyId>*)array)->contains(*((const PropertyId*)inValue));
}

int spine_array_property_id_index_of(spine_array_property_id array, int64_t inValue) {
    return ((Array<PropertyId>*)array)->indexOf(*((const PropertyId*)inValue));
}

spine_property_id spine_array_property_id_buffer(spine_array_property_id array) {
    return (spine_property_id)((Array<PropertyId>*)array)->buffer();
}

spine_array_animation spine_array_animation_create(void) {
    return (spine_array_animation) new (__FILE__, __LINE__) Array<Animation *>();
}

spine_array_animation spine_array_animation_create_with_capacity(size_t initialCapacity) {
    return (spine_array_animation) new (__FILE__, __LINE__) Array<Animation *>(initialCapacity);
}
void spine_array_animation_dispose(spine_array_animation array) {
    delete (Array<Animation *>*)array;
}
void spine_array_animation_clear(spine_array_animation array) {
    ((Array<Animation *>*)array)->clear();
}

size_t spine_array_animation_get_capacity(spine_array_animation array) {
    return ((Array<Animation *>*)array)->getCapacity();
}

size_t spine_array_animation_size(spine_array_animation array) {
    return ((Array<Animation *>*)array)->size();
}

spine_array_animation spine_array_animation_set_size(spine_array_animation array, size_t newSize, spine_animation defaultValue) {
    return (spine_array_animation)&((Array<Animation *>*)array)->setSize(newSize, (Animation *)defaultValue);
}

void spine_array_animation_ensure_capacity(spine_array_animation array, size_t newCapacity) {
    ((Array<Animation *>*)array)->ensureCapacity(newCapacity);
}

void spine_array_animation_add(spine_array_animation array, spine_animation inValue) {
    ((Array<Animation *>*)array)->add((Animation *)inValue);
}

void spine_array_animation_add_all(spine_array_animation array, spine_array_animation inValue) {
    ((Array<Animation *>*)array)->addAll(*((const Array<Animation *>*)inValue));
}

void spine_array_animation_clear_and_add_all(spine_array_animation array, spine_array_animation inValue) {
    ((Array<Animation *>*)array)->clearAndAddAll(*((const Array<Animation *>*)inValue));
}

void spine_array_animation_remove_at(spine_array_animation array, size_t inIndex) {
    ((Array<Animation *>*)array)->removeAt(inIndex);
}

bool spine_array_animation_contains(spine_array_animation array, spine_animation inValue) {
    return ((Array<Animation *>*)array)->contains((Animation *)inValue);
}

int spine_array_animation_index_of(spine_array_animation array, spine_animation inValue) {
    return ((Array<Animation *>*)array)->indexOf((Animation *)inValue);
}

spine_animation * spine_array_animation_buffer(spine_array_animation array) {
    return (spine_animation *)((Array<Animation *>*)array)->buffer();
}

spine_array_atlas_page spine_array_atlas_page_create(void) {
    return (spine_array_atlas_page) new (__FILE__, __LINE__) Array<AtlasPage *>();
}

spine_array_atlas_page spine_array_atlas_page_create_with_capacity(size_t initialCapacity) {
    return (spine_array_atlas_page) new (__FILE__, __LINE__) Array<AtlasPage *>(initialCapacity);
}
void spine_array_atlas_page_dispose(spine_array_atlas_page array) {
    delete (Array<AtlasPage *>*)array;
}
void spine_array_atlas_page_clear(spine_array_atlas_page array) {
    ((Array<AtlasPage *>*)array)->clear();
}

size_t spine_array_atlas_page_get_capacity(spine_array_atlas_page array) {
    return ((Array<AtlasPage *>*)array)->getCapacity();
}

size_t spine_array_atlas_page_size(spine_array_atlas_page array) {
    return ((Array<AtlasPage *>*)array)->size();
}

spine_array_atlas_page spine_array_atlas_page_set_size(spine_array_atlas_page array, size_t newSize, spine_atlas_page defaultValue) {
    return (spine_array_atlas_page)&((Array<AtlasPage *>*)array)->setSize(newSize, (AtlasPage *)defaultValue);
}

void spine_array_atlas_page_ensure_capacity(spine_array_atlas_page array, size_t newCapacity) {
    ((Array<AtlasPage *>*)array)->ensureCapacity(newCapacity);
}

void spine_array_atlas_page_add(spine_array_atlas_page array, spine_atlas_page inValue) {
    ((Array<AtlasPage *>*)array)->add((AtlasPage *)inValue);
}

void spine_array_atlas_page_add_all(spine_array_atlas_page array, spine_array_atlas_page inValue) {
    ((Array<AtlasPage *>*)array)->addAll(*((const Array<AtlasPage *>*)inValue));
}

void spine_array_atlas_page_clear_and_add_all(spine_array_atlas_page array, spine_array_atlas_page inValue) {
    ((Array<AtlasPage *>*)array)->clearAndAddAll(*((const Array<AtlasPage *>*)inValue));
}

void spine_array_atlas_page_remove_at(spine_array_atlas_page array, size_t inIndex) {
    ((Array<AtlasPage *>*)array)->removeAt(inIndex);
}

bool spine_array_atlas_page_contains(spine_array_atlas_page array, spine_atlas_page inValue) {
    return ((Array<AtlasPage *>*)array)->contains((AtlasPage *)inValue);
}

int spine_array_atlas_page_index_of(spine_array_atlas_page array, spine_atlas_page inValue) {
    return ((Array<AtlasPage *>*)array)->indexOf((AtlasPage *)inValue);
}

spine_atlas_page * spine_array_atlas_page_buffer(spine_array_atlas_page array) {
    return (spine_atlas_page *)((Array<AtlasPage *>*)array)->buffer();
}

spine_array_atlas_region spine_array_atlas_region_create(void) {
    return (spine_array_atlas_region) new (__FILE__, __LINE__) Array<AtlasRegion *>();
}

spine_array_atlas_region spine_array_atlas_region_create_with_capacity(size_t initialCapacity) {
    return (spine_array_atlas_region) new (__FILE__, __LINE__) Array<AtlasRegion *>(initialCapacity);
}
void spine_array_atlas_region_dispose(spine_array_atlas_region array) {
    delete (Array<AtlasRegion *>*)array;
}
void spine_array_atlas_region_clear(spine_array_atlas_region array) {
    ((Array<AtlasRegion *>*)array)->clear();
}

size_t spine_array_atlas_region_get_capacity(spine_array_atlas_region array) {
    return ((Array<AtlasRegion *>*)array)->getCapacity();
}

size_t spine_array_atlas_region_size(spine_array_atlas_region array) {
    return ((Array<AtlasRegion *>*)array)->size();
}

spine_array_atlas_region spine_array_atlas_region_set_size(spine_array_atlas_region array, size_t newSize, spine_atlas_region defaultValue) {
    return (spine_array_atlas_region)&((Array<AtlasRegion *>*)array)->setSize(newSize, (AtlasRegion *)defaultValue);
}

void spine_array_atlas_region_ensure_capacity(spine_array_atlas_region array, size_t newCapacity) {
    ((Array<AtlasRegion *>*)array)->ensureCapacity(newCapacity);
}

void spine_array_atlas_region_add(spine_array_atlas_region array, spine_atlas_region inValue) {
    ((Array<AtlasRegion *>*)array)->add((AtlasRegion *)inValue);
}

void spine_array_atlas_region_add_all(spine_array_atlas_region array, spine_array_atlas_region inValue) {
    ((Array<AtlasRegion *>*)array)->addAll(*((const Array<AtlasRegion *>*)inValue));
}

void spine_array_atlas_region_clear_and_add_all(spine_array_atlas_region array, spine_array_atlas_region inValue) {
    ((Array<AtlasRegion *>*)array)->clearAndAddAll(*((const Array<AtlasRegion *>*)inValue));
}

void spine_array_atlas_region_remove_at(spine_array_atlas_region array, size_t inIndex) {
    ((Array<AtlasRegion *>*)array)->removeAt(inIndex);
}

bool spine_array_atlas_region_contains(spine_array_atlas_region array, spine_atlas_region inValue) {
    return ((Array<AtlasRegion *>*)array)->contains((AtlasRegion *)inValue);
}

int spine_array_atlas_region_index_of(spine_array_atlas_region array, spine_atlas_region inValue) {
    return ((Array<AtlasRegion *>*)array)->indexOf((AtlasRegion *)inValue);
}

spine_atlas_region * spine_array_atlas_region_buffer(spine_array_atlas_region array) {
    return (spine_atlas_region *)((Array<AtlasRegion *>*)array)->buffer();
}

spine_array_attachment spine_array_attachment_create(void) {
    return (spine_array_attachment) new (__FILE__, __LINE__) Array<Attachment *>();
}

spine_array_attachment spine_array_attachment_create_with_capacity(size_t initialCapacity) {
    return (spine_array_attachment) new (__FILE__, __LINE__) Array<Attachment *>(initialCapacity);
}
void spine_array_attachment_dispose(spine_array_attachment array) {
    delete (Array<Attachment *>*)array;
}
void spine_array_attachment_clear(spine_array_attachment array) {
    ((Array<Attachment *>*)array)->clear();
}

size_t spine_array_attachment_get_capacity(spine_array_attachment array) {
    return ((Array<Attachment *>*)array)->getCapacity();
}

size_t spine_array_attachment_size(spine_array_attachment array) {
    return ((Array<Attachment *>*)array)->size();
}

spine_array_attachment spine_array_attachment_set_size(spine_array_attachment array, size_t newSize, spine_attachment defaultValue) {
    return (spine_array_attachment)&((Array<Attachment *>*)array)->setSize(newSize, (Attachment *)defaultValue);
}

void spine_array_attachment_ensure_capacity(spine_array_attachment array, size_t newCapacity) {
    ((Array<Attachment *>*)array)->ensureCapacity(newCapacity);
}

void spine_array_attachment_add(spine_array_attachment array, spine_attachment inValue) {
    ((Array<Attachment *>*)array)->add((Attachment *)inValue);
}

void spine_array_attachment_add_all(spine_array_attachment array, spine_array_attachment inValue) {
    ((Array<Attachment *>*)array)->addAll(*((const Array<Attachment *>*)inValue));
}

void spine_array_attachment_clear_and_add_all(spine_array_attachment array, spine_array_attachment inValue) {
    ((Array<Attachment *>*)array)->clearAndAddAll(*((const Array<Attachment *>*)inValue));
}

void spine_array_attachment_remove_at(spine_array_attachment array, size_t inIndex) {
    ((Array<Attachment *>*)array)->removeAt(inIndex);
}

bool spine_array_attachment_contains(spine_array_attachment array, spine_attachment inValue) {
    return ((Array<Attachment *>*)array)->contains((Attachment *)inValue);
}

int spine_array_attachment_index_of(spine_array_attachment array, spine_attachment inValue) {
    return ((Array<Attachment *>*)array)->indexOf((Attachment *)inValue);
}

spine_attachment * spine_array_attachment_buffer(spine_array_attachment array) {
    return (spine_attachment *)((Array<Attachment *>*)array)->buffer();
}

spine_array_bone spine_array_bone_create(void) {
    return (spine_array_bone) new (__FILE__, __LINE__) Array<Bone *>();
}

spine_array_bone spine_array_bone_create_with_capacity(size_t initialCapacity) {
    return (spine_array_bone) new (__FILE__, __LINE__) Array<Bone *>(initialCapacity);
}
void spine_array_bone_dispose(spine_array_bone array) {
    delete (Array<Bone *>*)array;
}
void spine_array_bone_clear(spine_array_bone array) {
    ((Array<Bone *>*)array)->clear();
}

size_t spine_array_bone_get_capacity(spine_array_bone array) {
    return ((Array<Bone *>*)array)->getCapacity();
}

size_t spine_array_bone_size(spine_array_bone array) {
    return ((Array<Bone *>*)array)->size();
}

spine_array_bone spine_array_bone_set_size(spine_array_bone array, size_t newSize, spine_bone defaultValue) {
    return (spine_array_bone)&((Array<Bone *>*)array)->setSize(newSize, (Bone *)defaultValue);
}

void spine_array_bone_ensure_capacity(spine_array_bone array, size_t newCapacity) {
    ((Array<Bone *>*)array)->ensureCapacity(newCapacity);
}

void spine_array_bone_add(spine_array_bone array, spine_bone inValue) {
    ((Array<Bone *>*)array)->add((Bone *)inValue);
}

void spine_array_bone_add_all(spine_array_bone array, spine_array_bone inValue) {
    ((Array<Bone *>*)array)->addAll(*((const Array<Bone *>*)inValue));
}

void spine_array_bone_clear_and_add_all(spine_array_bone array, spine_array_bone inValue) {
    ((Array<Bone *>*)array)->clearAndAddAll(*((const Array<Bone *>*)inValue));
}

void spine_array_bone_remove_at(spine_array_bone array, size_t inIndex) {
    ((Array<Bone *>*)array)->removeAt(inIndex);
}

bool spine_array_bone_contains(spine_array_bone array, spine_bone inValue) {
    return ((Array<Bone *>*)array)->contains((Bone *)inValue);
}

int spine_array_bone_index_of(spine_array_bone array, spine_bone inValue) {
    return ((Array<Bone *>*)array)->indexOf((Bone *)inValue);
}

spine_bone * spine_array_bone_buffer(spine_array_bone array) {
    return (spine_bone *)((Array<Bone *>*)array)->buffer();
}

spine_array_bone_data spine_array_bone_data_create(void) {
    return (spine_array_bone_data) new (__FILE__, __LINE__) Array<BoneData *>();
}

spine_array_bone_data spine_array_bone_data_create_with_capacity(size_t initialCapacity) {
    return (spine_array_bone_data) new (__FILE__, __LINE__) Array<BoneData *>(initialCapacity);
}
void spine_array_bone_data_dispose(spine_array_bone_data array) {
    delete (Array<BoneData *>*)array;
}
void spine_array_bone_data_clear(spine_array_bone_data array) {
    ((Array<BoneData *>*)array)->clear();
}

size_t spine_array_bone_data_get_capacity(spine_array_bone_data array) {
    return ((Array<BoneData *>*)array)->getCapacity();
}

size_t spine_array_bone_data_size(spine_array_bone_data array) {
    return ((Array<BoneData *>*)array)->size();
}

spine_array_bone_data spine_array_bone_data_set_size(spine_array_bone_data array, size_t newSize, spine_bone_data defaultValue) {
    return (spine_array_bone_data)&((Array<BoneData *>*)array)->setSize(newSize, (BoneData *)defaultValue);
}

void spine_array_bone_data_ensure_capacity(spine_array_bone_data array, size_t newCapacity) {
    ((Array<BoneData *>*)array)->ensureCapacity(newCapacity);
}

void spine_array_bone_data_add(spine_array_bone_data array, spine_bone_data inValue) {
    ((Array<BoneData *>*)array)->add((BoneData *)inValue);
}

void spine_array_bone_data_add_all(spine_array_bone_data array, spine_array_bone_data inValue) {
    ((Array<BoneData *>*)array)->addAll(*((const Array<BoneData *>*)inValue));
}

void spine_array_bone_data_clear_and_add_all(spine_array_bone_data array, spine_array_bone_data inValue) {
    ((Array<BoneData *>*)array)->clearAndAddAll(*((const Array<BoneData *>*)inValue));
}

void spine_array_bone_data_remove_at(spine_array_bone_data array, size_t inIndex) {
    ((Array<BoneData *>*)array)->removeAt(inIndex);
}

bool spine_array_bone_data_contains(spine_array_bone_data array, spine_bone_data inValue) {
    return ((Array<BoneData *>*)array)->contains((BoneData *)inValue);
}

int spine_array_bone_data_index_of(spine_array_bone_data array, spine_bone_data inValue) {
    return ((Array<BoneData *>*)array)->indexOf((BoneData *)inValue);
}

spine_bone_data * spine_array_bone_data_buffer(spine_array_bone_data array) {
    return (spine_bone_data *)((Array<BoneData *>*)array)->buffer();
}

spine_array_bone_pose spine_array_bone_pose_create(void) {
    return (spine_array_bone_pose) new (__FILE__, __LINE__) Array<BonePose *>();
}

spine_array_bone_pose spine_array_bone_pose_create_with_capacity(size_t initialCapacity) {
    return (spine_array_bone_pose) new (__FILE__, __LINE__) Array<BonePose *>(initialCapacity);
}
void spine_array_bone_pose_dispose(spine_array_bone_pose array) {
    delete (Array<BonePose *>*)array;
}
void spine_array_bone_pose_clear(spine_array_bone_pose array) {
    ((Array<BonePose *>*)array)->clear();
}

size_t spine_array_bone_pose_get_capacity(spine_array_bone_pose array) {
    return ((Array<BonePose *>*)array)->getCapacity();
}

size_t spine_array_bone_pose_size(spine_array_bone_pose array) {
    return ((Array<BonePose *>*)array)->size();
}

spine_array_bone_pose spine_array_bone_pose_set_size(spine_array_bone_pose array, size_t newSize, spine_bone_pose defaultValue) {
    return (spine_array_bone_pose)&((Array<BonePose *>*)array)->setSize(newSize, (BonePose *)defaultValue);
}

void spine_array_bone_pose_ensure_capacity(spine_array_bone_pose array, size_t newCapacity) {
    ((Array<BonePose *>*)array)->ensureCapacity(newCapacity);
}

void spine_array_bone_pose_add(spine_array_bone_pose array, spine_bone_pose inValue) {
    ((Array<BonePose *>*)array)->add((BonePose *)inValue);
}

void spine_array_bone_pose_add_all(spine_array_bone_pose array, spine_array_bone_pose inValue) {
    ((Array<BonePose *>*)array)->addAll(*((const Array<BonePose *>*)inValue));
}

void spine_array_bone_pose_clear_and_add_all(spine_array_bone_pose array, spine_array_bone_pose inValue) {
    ((Array<BonePose *>*)array)->clearAndAddAll(*((const Array<BonePose *>*)inValue));
}

void spine_array_bone_pose_remove_at(spine_array_bone_pose array, size_t inIndex) {
    ((Array<BonePose *>*)array)->removeAt(inIndex);
}

bool spine_array_bone_pose_contains(spine_array_bone_pose array, spine_bone_pose inValue) {
    return ((Array<BonePose *>*)array)->contains((BonePose *)inValue);
}

int spine_array_bone_pose_index_of(spine_array_bone_pose array, spine_bone_pose inValue) {
    return ((Array<BonePose *>*)array)->indexOf((BonePose *)inValue);
}

spine_bone_pose * spine_array_bone_pose_buffer(spine_array_bone_pose array) {
    return (spine_bone_pose *)((Array<BonePose *>*)array)->buffer();
}

spine_array_bounding_box_attachment spine_array_bounding_box_attachment_create(void) {
    return (spine_array_bounding_box_attachment) new (__FILE__, __LINE__) Array<BoundingBoxAttachment *>();
}

spine_array_bounding_box_attachment spine_array_bounding_box_attachment_create_with_capacity(size_t initialCapacity) {
    return (spine_array_bounding_box_attachment) new (__FILE__, __LINE__) Array<BoundingBoxAttachment *>(initialCapacity);
}
void spine_array_bounding_box_attachment_dispose(spine_array_bounding_box_attachment array) {
    delete (Array<BoundingBoxAttachment *>*)array;
}
void spine_array_bounding_box_attachment_clear(spine_array_bounding_box_attachment array) {
    ((Array<BoundingBoxAttachment *>*)array)->clear();
}

size_t spine_array_bounding_box_attachment_get_capacity(spine_array_bounding_box_attachment array) {
    return ((Array<BoundingBoxAttachment *>*)array)->getCapacity();
}

size_t spine_array_bounding_box_attachment_size(spine_array_bounding_box_attachment array) {
    return ((Array<BoundingBoxAttachment *>*)array)->size();
}

spine_array_bounding_box_attachment spine_array_bounding_box_attachment_set_size(spine_array_bounding_box_attachment array, size_t newSize, spine_bounding_box_attachment defaultValue) {
    return (spine_array_bounding_box_attachment)&((Array<BoundingBoxAttachment *>*)array)->setSize(newSize, (BoundingBoxAttachment *)defaultValue);
}

void spine_array_bounding_box_attachment_ensure_capacity(spine_array_bounding_box_attachment array, size_t newCapacity) {
    ((Array<BoundingBoxAttachment *>*)array)->ensureCapacity(newCapacity);
}

void spine_array_bounding_box_attachment_add(spine_array_bounding_box_attachment array, spine_bounding_box_attachment inValue) {
    ((Array<BoundingBoxAttachment *>*)array)->add((BoundingBoxAttachment *)inValue);
}

void spine_array_bounding_box_attachment_add_all(spine_array_bounding_box_attachment array, spine_array_bounding_box_attachment inValue) {
    ((Array<BoundingBoxAttachment *>*)array)->addAll(*((const Array<BoundingBoxAttachment *>*)inValue));
}

void spine_array_bounding_box_attachment_clear_and_add_all(spine_array_bounding_box_attachment array, spine_array_bounding_box_attachment inValue) {
    ((Array<BoundingBoxAttachment *>*)array)->clearAndAddAll(*((const Array<BoundingBoxAttachment *>*)inValue));
}

void spine_array_bounding_box_attachment_remove_at(spine_array_bounding_box_attachment array, size_t inIndex) {
    ((Array<BoundingBoxAttachment *>*)array)->removeAt(inIndex);
}

bool spine_array_bounding_box_attachment_contains(spine_array_bounding_box_attachment array, spine_bounding_box_attachment inValue) {
    return ((Array<BoundingBoxAttachment *>*)array)->contains((BoundingBoxAttachment *)inValue);
}

int spine_array_bounding_box_attachment_index_of(spine_array_bounding_box_attachment array, spine_bounding_box_attachment inValue) {
    return ((Array<BoundingBoxAttachment *>*)array)->indexOf((BoundingBoxAttachment *)inValue);
}

spine_bounding_box_attachment * spine_array_bounding_box_attachment_buffer(spine_array_bounding_box_attachment array) {
    return (spine_bounding_box_attachment *)((Array<BoundingBoxAttachment *>*)array)->buffer();
}

spine_array_constraint spine_array_constraint_create(void) {
    return (spine_array_constraint) new (__FILE__, __LINE__) Array<Constraint *>();
}

spine_array_constraint spine_array_constraint_create_with_capacity(size_t initialCapacity) {
    return (spine_array_constraint) new (__FILE__, __LINE__) Array<Constraint *>(initialCapacity);
}
void spine_array_constraint_dispose(spine_array_constraint array) {
    delete (Array<Constraint *>*)array;
}
void spine_array_constraint_clear(spine_array_constraint array) {
    ((Array<Constraint *>*)array)->clear();
}

size_t spine_array_constraint_get_capacity(spine_array_constraint array) {
    return ((Array<Constraint *>*)array)->getCapacity();
}

size_t spine_array_constraint_size(spine_array_constraint array) {
    return ((Array<Constraint *>*)array)->size();
}

spine_array_constraint spine_array_constraint_set_size(spine_array_constraint array, size_t newSize, spine_constraint defaultValue) {
    return (spine_array_constraint)&((Array<Constraint *>*)array)->setSize(newSize, (Constraint *)defaultValue);
}

void spine_array_constraint_ensure_capacity(spine_array_constraint array, size_t newCapacity) {
    ((Array<Constraint *>*)array)->ensureCapacity(newCapacity);
}

void spine_array_constraint_add(spine_array_constraint array, spine_constraint inValue) {
    ((Array<Constraint *>*)array)->add((Constraint *)inValue);
}

void spine_array_constraint_add_all(spine_array_constraint array, spine_array_constraint inValue) {
    ((Array<Constraint *>*)array)->addAll(*((const Array<Constraint *>*)inValue));
}

void spine_array_constraint_clear_and_add_all(spine_array_constraint array, spine_array_constraint inValue) {
    ((Array<Constraint *>*)array)->clearAndAddAll(*((const Array<Constraint *>*)inValue));
}

void spine_array_constraint_remove_at(spine_array_constraint array, size_t inIndex) {
    ((Array<Constraint *>*)array)->removeAt(inIndex);
}

bool spine_array_constraint_contains(spine_array_constraint array, spine_constraint inValue) {
    return ((Array<Constraint *>*)array)->contains((Constraint *)inValue);
}

int spine_array_constraint_index_of(spine_array_constraint array, spine_constraint inValue) {
    return ((Array<Constraint *>*)array)->indexOf((Constraint *)inValue);
}

spine_constraint * spine_array_constraint_buffer(spine_array_constraint array) {
    return (spine_constraint *)((Array<Constraint *>*)array)->buffer();
}

spine_array_constraint_data spine_array_constraint_data_create(void) {
    return (spine_array_constraint_data) new (__FILE__, __LINE__) Array<ConstraintData *>();
}

spine_array_constraint_data spine_array_constraint_data_create_with_capacity(size_t initialCapacity) {
    return (spine_array_constraint_data) new (__FILE__, __LINE__) Array<ConstraintData *>(initialCapacity);
}
void spine_array_constraint_data_dispose(spine_array_constraint_data array) {
    delete (Array<ConstraintData *>*)array;
}
void spine_array_constraint_data_clear(spine_array_constraint_data array) {
    ((Array<ConstraintData *>*)array)->clear();
}

size_t spine_array_constraint_data_get_capacity(spine_array_constraint_data array) {
    return ((Array<ConstraintData *>*)array)->getCapacity();
}

size_t spine_array_constraint_data_size(spine_array_constraint_data array) {
    return ((Array<ConstraintData *>*)array)->size();
}

spine_array_constraint_data spine_array_constraint_data_set_size(spine_array_constraint_data array, size_t newSize, spine_constraint_data defaultValue) {
    return (spine_array_constraint_data)&((Array<ConstraintData *>*)array)->setSize(newSize, (ConstraintData *)defaultValue);
}

void spine_array_constraint_data_ensure_capacity(spine_array_constraint_data array, size_t newCapacity) {
    ((Array<ConstraintData *>*)array)->ensureCapacity(newCapacity);
}

void spine_array_constraint_data_add(spine_array_constraint_data array, spine_constraint_data inValue) {
    ((Array<ConstraintData *>*)array)->add((ConstraintData *)inValue);
}

void spine_array_constraint_data_add_all(spine_array_constraint_data array, spine_array_constraint_data inValue) {
    ((Array<ConstraintData *>*)array)->addAll(*((const Array<ConstraintData *>*)inValue));
}

void spine_array_constraint_data_clear_and_add_all(spine_array_constraint_data array, spine_array_constraint_data inValue) {
    ((Array<ConstraintData *>*)array)->clearAndAddAll(*((const Array<ConstraintData *>*)inValue));
}

void spine_array_constraint_data_remove_at(spine_array_constraint_data array, size_t inIndex) {
    ((Array<ConstraintData *>*)array)->removeAt(inIndex);
}

bool spine_array_constraint_data_contains(spine_array_constraint_data array, spine_constraint_data inValue) {
    return ((Array<ConstraintData *>*)array)->contains((ConstraintData *)inValue);
}

int spine_array_constraint_data_index_of(spine_array_constraint_data array, spine_constraint_data inValue) {
    return ((Array<ConstraintData *>*)array)->indexOf((ConstraintData *)inValue);
}

spine_constraint_data * spine_array_constraint_data_buffer(spine_array_constraint_data array) {
    return (spine_constraint_data *)((Array<ConstraintData *>*)array)->buffer();
}

spine_array_event spine_array_event_create(void) {
    return (spine_array_event) new (__FILE__, __LINE__) Array<Event *>();
}

spine_array_event spine_array_event_create_with_capacity(size_t initialCapacity) {
    return (spine_array_event) new (__FILE__, __LINE__) Array<Event *>(initialCapacity);
}
void spine_array_event_dispose(spine_array_event array) {
    delete (Array<Event *>*)array;
}
void spine_array_event_clear(spine_array_event array) {
    ((Array<Event *>*)array)->clear();
}

size_t spine_array_event_get_capacity(spine_array_event array) {
    return ((Array<Event *>*)array)->getCapacity();
}

size_t spine_array_event_size(spine_array_event array) {
    return ((Array<Event *>*)array)->size();
}

spine_array_event spine_array_event_set_size(spine_array_event array, size_t newSize, spine_event defaultValue) {
    return (spine_array_event)&((Array<Event *>*)array)->setSize(newSize, (Event *)defaultValue);
}

void spine_array_event_ensure_capacity(spine_array_event array, size_t newCapacity) {
    ((Array<Event *>*)array)->ensureCapacity(newCapacity);
}

void spine_array_event_add(spine_array_event array, spine_event inValue) {
    ((Array<Event *>*)array)->add((Event *)inValue);
}

void spine_array_event_add_all(spine_array_event array, spine_array_event inValue) {
    ((Array<Event *>*)array)->addAll(*((const Array<Event *>*)inValue));
}

void spine_array_event_clear_and_add_all(spine_array_event array, spine_array_event inValue) {
    ((Array<Event *>*)array)->clearAndAddAll(*((const Array<Event *>*)inValue));
}

void spine_array_event_remove_at(spine_array_event array, size_t inIndex) {
    ((Array<Event *>*)array)->removeAt(inIndex);
}

bool spine_array_event_contains(spine_array_event array, spine_event inValue) {
    return ((Array<Event *>*)array)->contains((Event *)inValue);
}

int spine_array_event_index_of(spine_array_event array, spine_event inValue) {
    return ((Array<Event *>*)array)->indexOf((Event *)inValue);
}

spine_event * spine_array_event_buffer(spine_array_event array) {
    return (spine_event *)((Array<Event *>*)array)->buffer();
}

spine_array_event_data spine_array_event_data_create(void) {
    return (spine_array_event_data) new (__FILE__, __LINE__) Array<EventData *>();
}

spine_array_event_data spine_array_event_data_create_with_capacity(size_t initialCapacity) {
    return (spine_array_event_data) new (__FILE__, __LINE__) Array<EventData *>(initialCapacity);
}
void spine_array_event_data_dispose(spine_array_event_data array) {
    delete (Array<EventData *>*)array;
}
void spine_array_event_data_clear(spine_array_event_data array) {
    ((Array<EventData *>*)array)->clear();
}

size_t spine_array_event_data_get_capacity(spine_array_event_data array) {
    return ((Array<EventData *>*)array)->getCapacity();
}

size_t spine_array_event_data_size(spine_array_event_data array) {
    return ((Array<EventData *>*)array)->size();
}

spine_array_event_data spine_array_event_data_set_size(spine_array_event_data array, size_t newSize, spine_event_data defaultValue) {
    return (spine_array_event_data)&((Array<EventData *>*)array)->setSize(newSize, (EventData *)defaultValue);
}

void spine_array_event_data_ensure_capacity(spine_array_event_data array, size_t newCapacity) {
    ((Array<EventData *>*)array)->ensureCapacity(newCapacity);
}

void spine_array_event_data_add(spine_array_event_data array, spine_event_data inValue) {
    ((Array<EventData *>*)array)->add((EventData *)inValue);
}

void spine_array_event_data_add_all(spine_array_event_data array, spine_array_event_data inValue) {
    ((Array<EventData *>*)array)->addAll(*((const Array<EventData *>*)inValue));
}

void spine_array_event_data_clear_and_add_all(spine_array_event_data array, spine_array_event_data inValue) {
    ((Array<EventData *>*)array)->clearAndAddAll(*((const Array<EventData *>*)inValue));
}

void spine_array_event_data_remove_at(spine_array_event_data array, size_t inIndex) {
    ((Array<EventData *>*)array)->removeAt(inIndex);
}

bool spine_array_event_data_contains(spine_array_event_data array, spine_event_data inValue) {
    return ((Array<EventData *>*)array)->contains((EventData *)inValue);
}

int spine_array_event_data_index_of(spine_array_event_data array, spine_event_data inValue) {
    return ((Array<EventData *>*)array)->indexOf((EventData *)inValue);
}

spine_event_data * spine_array_event_data_buffer(spine_array_event_data array) {
    return (spine_event_data *)((Array<EventData *>*)array)->buffer();
}

spine_array_from_property spine_array_from_property_create(void) {
    return (spine_array_from_property) new (__FILE__, __LINE__) Array<FromProperty *>();
}

spine_array_from_property spine_array_from_property_create_with_capacity(size_t initialCapacity) {
    return (spine_array_from_property) new (__FILE__, __LINE__) Array<FromProperty *>(initialCapacity);
}
void spine_array_from_property_dispose(spine_array_from_property array) {
    delete (Array<FromProperty *>*)array;
}
void spine_array_from_property_clear(spine_array_from_property array) {
    ((Array<FromProperty *>*)array)->clear();
}

size_t spine_array_from_property_get_capacity(spine_array_from_property array) {
    return ((Array<FromProperty *>*)array)->getCapacity();
}

size_t spine_array_from_property_size(spine_array_from_property array) {
    return ((Array<FromProperty *>*)array)->size();
}

spine_array_from_property spine_array_from_property_set_size(spine_array_from_property array, size_t newSize, spine_from_property defaultValue) {
    return (spine_array_from_property)&((Array<FromProperty *>*)array)->setSize(newSize, (FromProperty *)defaultValue);
}

void spine_array_from_property_ensure_capacity(spine_array_from_property array, size_t newCapacity) {
    ((Array<FromProperty *>*)array)->ensureCapacity(newCapacity);
}

void spine_array_from_property_add(spine_array_from_property array, spine_from_property inValue) {
    ((Array<FromProperty *>*)array)->add((FromProperty *)inValue);
}

void spine_array_from_property_add_all(spine_array_from_property array, spine_array_from_property inValue) {
    ((Array<FromProperty *>*)array)->addAll(*((const Array<FromProperty *>*)inValue));
}

void spine_array_from_property_clear_and_add_all(spine_array_from_property array, spine_array_from_property inValue) {
    ((Array<FromProperty *>*)array)->clearAndAddAll(*((const Array<FromProperty *>*)inValue));
}

void spine_array_from_property_remove_at(spine_array_from_property array, size_t inIndex) {
    ((Array<FromProperty *>*)array)->removeAt(inIndex);
}

bool spine_array_from_property_contains(spine_array_from_property array, spine_from_property inValue) {
    return ((Array<FromProperty *>*)array)->contains((FromProperty *)inValue);
}

int spine_array_from_property_index_of(spine_array_from_property array, spine_from_property inValue) {
    return ((Array<FromProperty *>*)array)->indexOf((FromProperty *)inValue);
}

spine_from_property * spine_array_from_property_buffer(spine_array_from_property array) {
    return (spine_from_property *)((Array<FromProperty *>*)array)->buffer();
}

spine_array_ik_constraint_data spine_array_ik_constraint_data_create(void) {
    return (spine_array_ik_constraint_data) new (__FILE__, __LINE__) Array<IkConstraintData *>();
}

spine_array_ik_constraint_data spine_array_ik_constraint_data_create_with_capacity(size_t initialCapacity) {
    return (spine_array_ik_constraint_data) new (__FILE__, __LINE__) Array<IkConstraintData *>(initialCapacity);
}
void spine_array_ik_constraint_data_dispose(spine_array_ik_constraint_data array) {
    delete (Array<IkConstraintData *>*)array;
}
void spine_array_ik_constraint_data_clear(spine_array_ik_constraint_data array) {
    ((Array<IkConstraintData *>*)array)->clear();
}

size_t spine_array_ik_constraint_data_get_capacity(spine_array_ik_constraint_data array) {
    return ((Array<IkConstraintData *>*)array)->getCapacity();
}

size_t spine_array_ik_constraint_data_size(spine_array_ik_constraint_data array) {
    return ((Array<IkConstraintData *>*)array)->size();
}

spine_array_ik_constraint_data spine_array_ik_constraint_data_set_size(spine_array_ik_constraint_data array, size_t newSize, spine_ik_constraint_data defaultValue) {
    return (spine_array_ik_constraint_data)&((Array<IkConstraintData *>*)array)->setSize(newSize, (IkConstraintData *)defaultValue);
}

void spine_array_ik_constraint_data_ensure_capacity(spine_array_ik_constraint_data array, size_t newCapacity) {
    ((Array<IkConstraintData *>*)array)->ensureCapacity(newCapacity);
}

void spine_array_ik_constraint_data_add(spine_array_ik_constraint_data array, spine_ik_constraint_data inValue) {
    ((Array<IkConstraintData *>*)array)->add((IkConstraintData *)inValue);
}

void spine_array_ik_constraint_data_add_all(spine_array_ik_constraint_data array, spine_array_ik_constraint_data inValue) {
    ((Array<IkConstraintData *>*)array)->addAll(*((const Array<IkConstraintData *>*)inValue));
}

void spine_array_ik_constraint_data_clear_and_add_all(spine_array_ik_constraint_data array, spine_array_ik_constraint_data inValue) {
    ((Array<IkConstraintData *>*)array)->clearAndAddAll(*((const Array<IkConstraintData *>*)inValue));
}

void spine_array_ik_constraint_data_remove_at(spine_array_ik_constraint_data array, size_t inIndex) {
    ((Array<IkConstraintData *>*)array)->removeAt(inIndex);
}

bool spine_array_ik_constraint_data_contains(spine_array_ik_constraint_data array, spine_ik_constraint_data inValue) {
    return ((Array<IkConstraintData *>*)array)->contains((IkConstraintData *)inValue);
}

int spine_array_ik_constraint_data_index_of(spine_array_ik_constraint_data array, spine_ik_constraint_data inValue) {
    return ((Array<IkConstraintData *>*)array)->indexOf((IkConstraintData *)inValue);
}

spine_ik_constraint_data * spine_array_ik_constraint_data_buffer(spine_array_ik_constraint_data array) {
    return (spine_ik_constraint_data *)((Array<IkConstraintData *>*)array)->buffer();
}

spine_array_path_constraint_data spine_array_path_constraint_data_create(void) {
    return (spine_array_path_constraint_data) new (__FILE__, __LINE__) Array<PathConstraintData *>();
}

spine_array_path_constraint_data spine_array_path_constraint_data_create_with_capacity(size_t initialCapacity) {
    return (spine_array_path_constraint_data) new (__FILE__, __LINE__) Array<PathConstraintData *>(initialCapacity);
}
void spine_array_path_constraint_data_dispose(spine_array_path_constraint_data array) {
    delete (Array<PathConstraintData *>*)array;
}
void spine_array_path_constraint_data_clear(spine_array_path_constraint_data array) {
    ((Array<PathConstraintData *>*)array)->clear();
}

size_t spine_array_path_constraint_data_get_capacity(spine_array_path_constraint_data array) {
    return ((Array<PathConstraintData *>*)array)->getCapacity();
}

size_t spine_array_path_constraint_data_size(spine_array_path_constraint_data array) {
    return ((Array<PathConstraintData *>*)array)->size();
}

spine_array_path_constraint_data spine_array_path_constraint_data_set_size(spine_array_path_constraint_data array, size_t newSize, spine_path_constraint_data defaultValue) {
    return (spine_array_path_constraint_data)&((Array<PathConstraintData *>*)array)->setSize(newSize, (PathConstraintData *)defaultValue);
}

void spine_array_path_constraint_data_ensure_capacity(spine_array_path_constraint_data array, size_t newCapacity) {
    ((Array<PathConstraintData *>*)array)->ensureCapacity(newCapacity);
}

void spine_array_path_constraint_data_add(spine_array_path_constraint_data array, spine_path_constraint_data inValue) {
    ((Array<PathConstraintData *>*)array)->add((PathConstraintData *)inValue);
}

void spine_array_path_constraint_data_add_all(spine_array_path_constraint_data array, spine_array_path_constraint_data inValue) {
    ((Array<PathConstraintData *>*)array)->addAll(*((const Array<PathConstraintData *>*)inValue));
}

void spine_array_path_constraint_data_clear_and_add_all(spine_array_path_constraint_data array, spine_array_path_constraint_data inValue) {
    ((Array<PathConstraintData *>*)array)->clearAndAddAll(*((const Array<PathConstraintData *>*)inValue));
}

void spine_array_path_constraint_data_remove_at(spine_array_path_constraint_data array, size_t inIndex) {
    ((Array<PathConstraintData *>*)array)->removeAt(inIndex);
}

bool spine_array_path_constraint_data_contains(spine_array_path_constraint_data array, spine_path_constraint_data inValue) {
    return ((Array<PathConstraintData *>*)array)->contains((PathConstraintData *)inValue);
}

int spine_array_path_constraint_data_index_of(spine_array_path_constraint_data array, spine_path_constraint_data inValue) {
    return ((Array<PathConstraintData *>*)array)->indexOf((PathConstraintData *)inValue);
}

spine_path_constraint_data * spine_array_path_constraint_data_buffer(spine_array_path_constraint_data array) {
    return (spine_path_constraint_data *)((Array<PathConstraintData *>*)array)->buffer();
}

spine_array_physics_constraint spine_array_physics_constraint_create(void) {
    return (spine_array_physics_constraint) new (__FILE__, __LINE__) Array<PhysicsConstraint *>();
}

spine_array_physics_constraint spine_array_physics_constraint_create_with_capacity(size_t initialCapacity) {
    return (spine_array_physics_constraint) new (__FILE__, __LINE__) Array<PhysicsConstraint *>(initialCapacity);
}
void spine_array_physics_constraint_dispose(spine_array_physics_constraint array) {
    delete (Array<PhysicsConstraint *>*)array;
}
void spine_array_physics_constraint_clear(spine_array_physics_constraint array) {
    ((Array<PhysicsConstraint *>*)array)->clear();
}

size_t spine_array_physics_constraint_get_capacity(spine_array_physics_constraint array) {
    return ((Array<PhysicsConstraint *>*)array)->getCapacity();
}

size_t spine_array_physics_constraint_size(spine_array_physics_constraint array) {
    return ((Array<PhysicsConstraint *>*)array)->size();
}

spine_array_physics_constraint spine_array_physics_constraint_set_size(spine_array_physics_constraint array, size_t newSize, spine_physics_constraint defaultValue) {
    return (spine_array_physics_constraint)&((Array<PhysicsConstraint *>*)array)->setSize(newSize, (PhysicsConstraint *)defaultValue);
}

void spine_array_physics_constraint_ensure_capacity(spine_array_physics_constraint array, size_t newCapacity) {
    ((Array<PhysicsConstraint *>*)array)->ensureCapacity(newCapacity);
}

void spine_array_physics_constraint_add(spine_array_physics_constraint array, spine_physics_constraint inValue) {
    ((Array<PhysicsConstraint *>*)array)->add((PhysicsConstraint *)inValue);
}

void spine_array_physics_constraint_add_all(spine_array_physics_constraint array, spine_array_physics_constraint inValue) {
    ((Array<PhysicsConstraint *>*)array)->addAll(*((const Array<PhysicsConstraint *>*)inValue));
}

void spine_array_physics_constraint_clear_and_add_all(spine_array_physics_constraint array, spine_array_physics_constraint inValue) {
    ((Array<PhysicsConstraint *>*)array)->clearAndAddAll(*((const Array<PhysicsConstraint *>*)inValue));
}

void spine_array_physics_constraint_remove_at(spine_array_physics_constraint array, size_t inIndex) {
    ((Array<PhysicsConstraint *>*)array)->removeAt(inIndex);
}

bool spine_array_physics_constraint_contains(spine_array_physics_constraint array, spine_physics_constraint inValue) {
    return ((Array<PhysicsConstraint *>*)array)->contains((PhysicsConstraint *)inValue);
}

int spine_array_physics_constraint_index_of(spine_array_physics_constraint array, spine_physics_constraint inValue) {
    return ((Array<PhysicsConstraint *>*)array)->indexOf((PhysicsConstraint *)inValue);
}

spine_physics_constraint * spine_array_physics_constraint_buffer(spine_array_physics_constraint array) {
    return (spine_physics_constraint *)((Array<PhysicsConstraint *>*)array)->buffer();
}

spine_array_physics_constraint_data spine_array_physics_constraint_data_create(void) {
    return (spine_array_physics_constraint_data) new (__FILE__, __LINE__) Array<PhysicsConstraintData *>();
}

spine_array_physics_constraint_data spine_array_physics_constraint_data_create_with_capacity(size_t initialCapacity) {
    return (spine_array_physics_constraint_data) new (__FILE__, __LINE__) Array<PhysicsConstraintData *>(initialCapacity);
}
void spine_array_physics_constraint_data_dispose(spine_array_physics_constraint_data array) {
    delete (Array<PhysicsConstraintData *>*)array;
}
void spine_array_physics_constraint_data_clear(spine_array_physics_constraint_data array) {
    ((Array<PhysicsConstraintData *>*)array)->clear();
}

size_t spine_array_physics_constraint_data_get_capacity(spine_array_physics_constraint_data array) {
    return ((Array<PhysicsConstraintData *>*)array)->getCapacity();
}

size_t spine_array_physics_constraint_data_size(spine_array_physics_constraint_data array) {
    return ((Array<PhysicsConstraintData *>*)array)->size();
}

spine_array_physics_constraint_data spine_array_physics_constraint_data_set_size(spine_array_physics_constraint_data array, size_t newSize, spine_physics_constraint_data defaultValue) {
    return (spine_array_physics_constraint_data)&((Array<PhysicsConstraintData *>*)array)->setSize(newSize, (PhysicsConstraintData *)defaultValue);
}

void spine_array_physics_constraint_data_ensure_capacity(spine_array_physics_constraint_data array, size_t newCapacity) {
    ((Array<PhysicsConstraintData *>*)array)->ensureCapacity(newCapacity);
}

void spine_array_physics_constraint_data_add(spine_array_physics_constraint_data array, spine_physics_constraint_data inValue) {
    ((Array<PhysicsConstraintData *>*)array)->add((PhysicsConstraintData *)inValue);
}

void spine_array_physics_constraint_data_add_all(spine_array_physics_constraint_data array, spine_array_physics_constraint_data inValue) {
    ((Array<PhysicsConstraintData *>*)array)->addAll(*((const Array<PhysicsConstraintData *>*)inValue));
}

void spine_array_physics_constraint_data_clear_and_add_all(spine_array_physics_constraint_data array, spine_array_physics_constraint_data inValue) {
    ((Array<PhysicsConstraintData *>*)array)->clearAndAddAll(*((const Array<PhysicsConstraintData *>*)inValue));
}

void spine_array_physics_constraint_data_remove_at(spine_array_physics_constraint_data array, size_t inIndex) {
    ((Array<PhysicsConstraintData *>*)array)->removeAt(inIndex);
}

bool spine_array_physics_constraint_data_contains(spine_array_physics_constraint_data array, spine_physics_constraint_data inValue) {
    return ((Array<PhysicsConstraintData *>*)array)->contains((PhysicsConstraintData *)inValue);
}

int spine_array_physics_constraint_data_index_of(spine_array_physics_constraint_data array, spine_physics_constraint_data inValue) {
    return ((Array<PhysicsConstraintData *>*)array)->indexOf((PhysicsConstraintData *)inValue);
}

spine_physics_constraint_data * spine_array_physics_constraint_data_buffer(spine_array_physics_constraint_data array) {
    return (spine_physics_constraint_data *)((Array<PhysicsConstraintData *>*)array)->buffer();
}

spine_array_polygon spine_array_polygon_create(void) {
    return (spine_array_polygon) new (__FILE__, __LINE__) Array<Polygon *>();
}

spine_array_polygon spine_array_polygon_create_with_capacity(size_t initialCapacity) {
    return (spine_array_polygon) new (__FILE__, __LINE__) Array<Polygon *>(initialCapacity);
}
void spine_array_polygon_dispose(spine_array_polygon array) {
    delete (Array<Polygon *>*)array;
}
void spine_array_polygon_clear(spine_array_polygon array) {
    ((Array<Polygon *>*)array)->clear();
}

size_t spine_array_polygon_get_capacity(spine_array_polygon array) {
    return ((Array<Polygon *>*)array)->getCapacity();
}

size_t spine_array_polygon_size(spine_array_polygon array) {
    return ((Array<Polygon *>*)array)->size();
}

spine_array_polygon spine_array_polygon_set_size(spine_array_polygon array, size_t newSize, spine_polygon defaultValue) {
    return (spine_array_polygon)&((Array<Polygon *>*)array)->setSize(newSize, (Polygon *)defaultValue);
}

void spine_array_polygon_ensure_capacity(spine_array_polygon array, size_t newCapacity) {
    ((Array<Polygon *>*)array)->ensureCapacity(newCapacity);
}

void spine_array_polygon_add(spine_array_polygon array, spine_polygon inValue) {
    ((Array<Polygon *>*)array)->add((Polygon *)inValue);
}

void spine_array_polygon_add_all(spine_array_polygon array, spine_array_polygon inValue) {
    ((Array<Polygon *>*)array)->addAll(*((const Array<Polygon *>*)inValue));
}

void spine_array_polygon_clear_and_add_all(spine_array_polygon array, spine_array_polygon inValue) {
    ((Array<Polygon *>*)array)->clearAndAddAll(*((const Array<Polygon *>*)inValue));
}

void spine_array_polygon_remove_at(spine_array_polygon array, size_t inIndex) {
    ((Array<Polygon *>*)array)->removeAt(inIndex);
}

bool spine_array_polygon_contains(spine_array_polygon array, spine_polygon inValue) {
    return ((Array<Polygon *>*)array)->contains((Polygon *)inValue);
}

int spine_array_polygon_index_of(spine_array_polygon array, spine_polygon inValue) {
    return ((Array<Polygon *>*)array)->indexOf((Polygon *)inValue);
}

spine_polygon * spine_array_polygon_buffer(spine_array_polygon array) {
    return (spine_polygon *)((Array<Polygon *>*)array)->buffer();
}

spine_array_skin spine_array_skin_create(void) {
    return (spine_array_skin) new (__FILE__, __LINE__) Array<Skin *>();
}

spine_array_skin spine_array_skin_create_with_capacity(size_t initialCapacity) {
    return (spine_array_skin) new (__FILE__, __LINE__) Array<Skin *>(initialCapacity);
}
void spine_array_skin_dispose(spine_array_skin array) {
    delete (Array<Skin *>*)array;
}
void spine_array_skin_clear(spine_array_skin array) {
    ((Array<Skin *>*)array)->clear();
}

size_t spine_array_skin_get_capacity(spine_array_skin array) {
    return ((Array<Skin *>*)array)->getCapacity();
}

size_t spine_array_skin_size(spine_array_skin array) {
    return ((Array<Skin *>*)array)->size();
}

spine_array_skin spine_array_skin_set_size(spine_array_skin array, size_t newSize, spine_skin defaultValue) {
    return (spine_array_skin)&((Array<Skin *>*)array)->setSize(newSize, (Skin *)defaultValue);
}

void spine_array_skin_ensure_capacity(spine_array_skin array, size_t newCapacity) {
    ((Array<Skin *>*)array)->ensureCapacity(newCapacity);
}

void spine_array_skin_add(spine_array_skin array, spine_skin inValue) {
    ((Array<Skin *>*)array)->add((Skin *)inValue);
}

void spine_array_skin_add_all(spine_array_skin array, spine_array_skin inValue) {
    ((Array<Skin *>*)array)->addAll(*((const Array<Skin *>*)inValue));
}

void spine_array_skin_clear_and_add_all(spine_array_skin array, spine_array_skin inValue) {
    ((Array<Skin *>*)array)->clearAndAddAll(*((const Array<Skin *>*)inValue));
}

void spine_array_skin_remove_at(spine_array_skin array, size_t inIndex) {
    ((Array<Skin *>*)array)->removeAt(inIndex);
}

bool spine_array_skin_contains(spine_array_skin array, spine_skin inValue) {
    return ((Array<Skin *>*)array)->contains((Skin *)inValue);
}

int spine_array_skin_index_of(spine_array_skin array, spine_skin inValue) {
    return ((Array<Skin *>*)array)->indexOf((Skin *)inValue);
}

spine_skin * spine_array_skin_buffer(spine_array_skin array) {
    return (spine_skin *)((Array<Skin *>*)array)->buffer();
}

spine_array_slot spine_array_slot_create(void) {
    return (spine_array_slot) new (__FILE__, __LINE__) Array<Slot *>();
}

spine_array_slot spine_array_slot_create_with_capacity(size_t initialCapacity) {
    return (spine_array_slot) new (__FILE__, __LINE__) Array<Slot *>(initialCapacity);
}
void spine_array_slot_dispose(spine_array_slot array) {
    delete (Array<Slot *>*)array;
}
void spine_array_slot_clear(spine_array_slot array) {
    ((Array<Slot *>*)array)->clear();
}

size_t spine_array_slot_get_capacity(spine_array_slot array) {
    return ((Array<Slot *>*)array)->getCapacity();
}

size_t spine_array_slot_size(spine_array_slot array) {
    return ((Array<Slot *>*)array)->size();
}

spine_array_slot spine_array_slot_set_size(spine_array_slot array, size_t newSize, spine_slot defaultValue) {
    return (spine_array_slot)&((Array<Slot *>*)array)->setSize(newSize, (Slot *)defaultValue);
}

void spine_array_slot_ensure_capacity(spine_array_slot array, size_t newCapacity) {
    ((Array<Slot *>*)array)->ensureCapacity(newCapacity);
}

void spine_array_slot_add(spine_array_slot array, spine_slot inValue) {
    ((Array<Slot *>*)array)->add((Slot *)inValue);
}

void spine_array_slot_add_all(spine_array_slot array, spine_array_slot inValue) {
    ((Array<Slot *>*)array)->addAll(*((const Array<Slot *>*)inValue));
}

void spine_array_slot_clear_and_add_all(spine_array_slot array, spine_array_slot inValue) {
    ((Array<Slot *>*)array)->clearAndAddAll(*((const Array<Slot *>*)inValue));
}

void spine_array_slot_remove_at(spine_array_slot array, size_t inIndex) {
    ((Array<Slot *>*)array)->removeAt(inIndex);
}

bool spine_array_slot_contains(spine_array_slot array, spine_slot inValue) {
    return ((Array<Slot *>*)array)->contains((Slot *)inValue);
}

int spine_array_slot_index_of(spine_array_slot array, spine_slot inValue) {
    return ((Array<Slot *>*)array)->indexOf((Slot *)inValue);
}

spine_slot * spine_array_slot_buffer(spine_array_slot array) {
    return (spine_slot *)((Array<Slot *>*)array)->buffer();
}

spine_array_slot_data spine_array_slot_data_create(void) {
    return (spine_array_slot_data) new (__FILE__, __LINE__) Array<SlotData *>();
}

spine_array_slot_data spine_array_slot_data_create_with_capacity(size_t initialCapacity) {
    return (spine_array_slot_data) new (__FILE__, __LINE__) Array<SlotData *>(initialCapacity);
}
void spine_array_slot_data_dispose(spine_array_slot_data array) {
    delete (Array<SlotData *>*)array;
}
void spine_array_slot_data_clear(spine_array_slot_data array) {
    ((Array<SlotData *>*)array)->clear();
}

size_t spine_array_slot_data_get_capacity(spine_array_slot_data array) {
    return ((Array<SlotData *>*)array)->getCapacity();
}

size_t spine_array_slot_data_size(spine_array_slot_data array) {
    return ((Array<SlotData *>*)array)->size();
}

spine_array_slot_data spine_array_slot_data_set_size(spine_array_slot_data array, size_t newSize, spine_slot_data defaultValue) {
    return (spine_array_slot_data)&((Array<SlotData *>*)array)->setSize(newSize, (SlotData *)defaultValue);
}

void spine_array_slot_data_ensure_capacity(spine_array_slot_data array, size_t newCapacity) {
    ((Array<SlotData *>*)array)->ensureCapacity(newCapacity);
}

void spine_array_slot_data_add(spine_array_slot_data array, spine_slot_data inValue) {
    ((Array<SlotData *>*)array)->add((SlotData *)inValue);
}

void spine_array_slot_data_add_all(spine_array_slot_data array, spine_array_slot_data inValue) {
    ((Array<SlotData *>*)array)->addAll(*((const Array<SlotData *>*)inValue));
}

void spine_array_slot_data_clear_and_add_all(spine_array_slot_data array, spine_array_slot_data inValue) {
    ((Array<SlotData *>*)array)->clearAndAddAll(*((const Array<SlotData *>*)inValue));
}

void spine_array_slot_data_remove_at(spine_array_slot_data array, size_t inIndex) {
    ((Array<SlotData *>*)array)->removeAt(inIndex);
}

bool spine_array_slot_data_contains(spine_array_slot_data array, spine_slot_data inValue) {
    return ((Array<SlotData *>*)array)->contains((SlotData *)inValue);
}

int spine_array_slot_data_index_of(spine_array_slot_data array, spine_slot_data inValue) {
    return ((Array<SlotData *>*)array)->indexOf((SlotData *)inValue);
}

spine_slot_data * spine_array_slot_data_buffer(spine_array_slot_data array) {
    return (spine_slot_data *)((Array<SlotData *>*)array)->buffer();
}

spine_array_texture_region spine_array_texture_region_create(void) {
    return (spine_array_texture_region) new (__FILE__, __LINE__) Array<TextureRegion *>();
}

spine_array_texture_region spine_array_texture_region_create_with_capacity(size_t initialCapacity) {
    return (spine_array_texture_region) new (__FILE__, __LINE__) Array<TextureRegion *>(initialCapacity);
}
void spine_array_texture_region_dispose(spine_array_texture_region array) {
    delete (Array<TextureRegion *>*)array;
}
void spine_array_texture_region_clear(spine_array_texture_region array) {
    ((Array<TextureRegion *>*)array)->clear();
}

size_t spine_array_texture_region_get_capacity(spine_array_texture_region array) {
    return ((Array<TextureRegion *>*)array)->getCapacity();
}

size_t spine_array_texture_region_size(spine_array_texture_region array) {
    return ((Array<TextureRegion *>*)array)->size();
}

spine_array_texture_region spine_array_texture_region_set_size(spine_array_texture_region array, size_t newSize, spine_texture_region defaultValue) {
    return (spine_array_texture_region)&((Array<TextureRegion *>*)array)->setSize(newSize, (TextureRegion *)defaultValue);
}

void spine_array_texture_region_ensure_capacity(spine_array_texture_region array, size_t newCapacity) {
    ((Array<TextureRegion *>*)array)->ensureCapacity(newCapacity);
}

void spine_array_texture_region_add(spine_array_texture_region array, spine_texture_region inValue) {
    ((Array<TextureRegion *>*)array)->add((TextureRegion *)inValue);
}

void spine_array_texture_region_add_all(spine_array_texture_region array, spine_array_texture_region inValue) {
    ((Array<TextureRegion *>*)array)->addAll(*((const Array<TextureRegion *>*)inValue));
}

void spine_array_texture_region_clear_and_add_all(spine_array_texture_region array, spine_array_texture_region inValue) {
    ((Array<TextureRegion *>*)array)->clearAndAddAll(*((const Array<TextureRegion *>*)inValue));
}

void spine_array_texture_region_remove_at(spine_array_texture_region array, size_t inIndex) {
    ((Array<TextureRegion *>*)array)->removeAt(inIndex);
}

bool spine_array_texture_region_contains(spine_array_texture_region array, spine_texture_region inValue) {
    return ((Array<TextureRegion *>*)array)->contains((TextureRegion *)inValue);
}

int spine_array_texture_region_index_of(spine_array_texture_region array, spine_texture_region inValue) {
    return ((Array<TextureRegion *>*)array)->indexOf((TextureRegion *)inValue);
}

spine_texture_region * spine_array_texture_region_buffer(spine_array_texture_region array) {
    return (spine_texture_region *)((Array<TextureRegion *>*)array)->buffer();
}

spine_array_timeline spine_array_timeline_create(void) {
    return (spine_array_timeline) new (__FILE__, __LINE__) Array<Timeline *>();
}

spine_array_timeline spine_array_timeline_create_with_capacity(size_t initialCapacity) {
    return (spine_array_timeline) new (__FILE__, __LINE__) Array<Timeline *>(initialCapacity);
}
void spine_array_timeline_dispose(spine_array_timeline array) {
    delete (Array<Timeline *>*)array;
}
void spine_array_timeline_clear(spine_array_timeline array) {
    ((Array<Timeline *>*)array)->clear();
}

size_t spine_array_timeline_get_capacity(spine_array_timeline array) {
    return ((Array<Timeline *>*)array)->getCapacity();
}

size_t spine_array_timeline_size(spine_array_timeline array) {
    return ((Array<Timeline *>*)array)->size();
}

spine_array_timeline spine_array_timeline_set_size(spine_array_timeline array, size_t newSize, spine_timeline defaultValue) {
    return (spine_array_timeline)&((Array<Timeline *>*)array)->setSize(newSize, (Timeline *)defaultValue);
}

void spine_array_timeline_ensure_capacity(spine_array_timeline array, size_t newCapacity) {
    ((Array<Timeline *>*)array)->ensureCapacity(newCapacity);
}

void spine_array_timeline_add(spine_array_timeline array, spine_timeline inValue) {
    ((Array<Timeline *>*)array)->add((Timeline *)inValue);
}

void spine_array_timeline_add_all(spine_array_timeline array, spine_array_timeline inValue) {
    ((Array<Timeline *>*)array)->addAll(*((const Array<Timeline *>*)inValue));
}

void spine_array_timeline_clear_and_add_all(spine_array_timeline array, spine_array_timeline inValue) {
    ((Array<Timeline *>*)array)->clearAndAddAll(*((const Array<Timeline *>*)inValue));
}

void spine_array_timeline_remove_at(spine_array_timeline array, size_t inIndex) {
    ((Array<Timeline *>*)array)->removeAt(inIndex);
}

bool spine_array_timeline_contains(spine_array_timeline array, spine_timeline inValue) {
    return ((Array<Timeline *>*)array)->contains((Timeline *)inValue);
}

int spine_array_timeline_index_of(spine_array_timeline array, spine_timeline inValue) {
    return ((Array<Timeline *>*)array)->indexOf((Timeline *)inValue);
}

spine_timeline * spine_array_timeline_buffer(spine_array_timeline array) {
    return (spine_timeline *)((Array<Timeline *>*)array)->buffer();
}

spine_array_to_property spine_array_to_property_create(void) {
    return (spine_array_to_property) new (__FILE__, __LINE__) Array<ToProperty *>();
}

spine_array_to_property spine_array_to_property_create_with_capacity(size_t initialCapacity) {
    return (spine_array_to_property) new (__FILE__, __LINE__) Array<ToProperty *>(initialCapacity);
}
void spine_array_to_property_dispose(spine_array_to_property array) {
    delete (Array<ToProperty *>*)array;
}
void spine_array_to_property_clear(spine_array_to_property array) {
    ((Array<ToProperty *>*)array)->clear();
}

size_t spine_array_to_property_get_capacity(spine_array_to_property array) {
    return ((Array<ToProperty *>*)array)->getCapacity();
}

size_t spine_array_to_property_size(spine_array_to_property array) {
    return ((Array<ToProperty *>*)array)->size();
}

spine_array_to_property spine_array_to_property_set_size(spine_array_to_property array, size_t newSize, spine_to_property defaultValue) {
    return (spine_array_to_property)&((Array<ToProperty *>*)array)->setSize(newSize, (ToProperty *)defaultValue);
}

void spine_array_to_property_ensure_capacity(spine_array_to_property array, size_t newCapacity) {
    ((Array<ToProperty *>*)array)->ensureCapacity(newCapacity);
}

void spine_array_to_property_add(spine_array_to_property array, spine_to_property inValue) {
    ((Array<ToProperty *>*)array)->add((ToProperty *)inValue);
}

void spine_array_to_property_add_all(spine_array_to_property array, spine_array_to_property inValue) {
    ((Array<ToProperty *>*)array)->addAll(*((const Array<ToProperty *>*)inValue));
}

void spine_array_to_property_clear_and_add_all(spine_array_to_property array, spine_array_to_property inValue) {
    ((Array<ToProperty *>*)array)->clearAndAddAll(*((const Array<ToProperty *>*)inValue));
}

void spine_array_to_property_remove_at(spine_array_to_property array, size_t inIndex) {
    ((Array<ToProperty *>*)array)->removeAt(inIndex);
}

bool spine_array_to_property_contains(spine_array_to_property array, spine_to_property inValue) {
    return ((Array<ToProperty *>*)array)->contains((ToProperty *)inValue);
}

int spine_array_to_property_index_of(spine_array_to_property array, spine_to_property inValue) {
    return ((Array<ToProperty *>*)array)->indexOf((ToProperty *)inValue);
}

spine_to_property * spine_array_to_property_buffer(spine_array_to_property array) {
    return (spine_to_property *)((Array<ToProperty *>*)array)->buffer();
}

spine_array_track_entry spine_array_track_entry_create(void) {
    return (spine_array_track_entry) new (__FILE__, __LINE__) Array<TrackEntry *>();
}

spine_array_track_entry spine_array_track_entry_create_with_capacity(size_t initialCapacity) {
    return (spine_array_track_entry) new (__FILE__, __LINE__) Array<TrackEntry *>(initialCapacity);
}
void spine_array_track_entry_dispose(spine_array_track_entry array) {
    delete (Array<TrackEntry *>*)array;
}
void spine_array_track_entry_clear(spine_array_track_entry array) {
    ((Array<TrackEntry *>*)array)->clear();
}

size_t spine_array_track_entry_get_capacity(spine_array_track_entry array) {
    return ((Array<TrackEntry *>*)array)->getCapacity();
}

size_t spine_array_track_entry_size(spine_array_track_entry array) {
    return ((Array<TrackEntry *>*)array)->size();
}

spine_array_track_entry spine_array_track_entry_set_size(spine_array_track_entry array, size_t newSize, spine_track_entry defaultValue) {
    return (spine_array_track_entry)&((Array<TrackEntry *>*)array)->setSize(newSize, (TrackEntry *)defaultValue);
}

void spine_array_track_entry_ensure_capacity(spine_array_track_entry array, size_t newCapacity) {
    ((Array<TrackEntry *>*)array)->ensureCapacity(newCapacity);
}

void spine_array_track_entry_add(spine_array_track_entry array, spine_track_entry inValue) {
    ((Array<TrackEntry *>*)array)->add((TrackEntry *)inValue);
}

void spine_array_track_entry_add_all(spine_array_track_entry array, spine_array_track_entry inValue) {
    ((Array<TrackEntry *>*)array)->addAll(*((const Array<TrackEntry *>*)inValue));
}

void spine_array_track_entry_clear_and_add_all(spine_array_track_entry array, spine_array_track_entry inValue) {
    ((Array<TrackEntry *>*)array)->clearAndAddAll(*((const Array<TrackEntry *>*)inValue));
}

void spine_array_track_entry_remove_at(spine_array_track_entry array, size_t inIndex) {
    ((Array<TrackEntry *>*)array)->removeAt(inIndex);
}

bool spine_array_track_entry_contains(spine_array_track_entry array, spine_track_entry inValue) {
    return ((Array<TrackEntry *>*)array)->contains((TrackEntry *)inValue);
}

int spine_array_track_entry_index_of(spine_array_track_entry array, spine_track_entry inValue) {
    return ((Array<TrackEntry *>*)array)->indexOf((TrackEntry *)inValue);
}

spine_track_entry * spine_array_track_entry_buffer(spine_array_track_entry array) {
    return (spine_track_entry *)((Array<TrackEntry *>*)array)->buffer();
}

spine_array_transform_constraint_data spine_array_transform_constraint_data_create(void) {
    return (spine_array_transform_constraint_data) new (__FILE__, __LINE__) Array<TransformConstraintData *>();
}

spine_array_transform_constraint_data spine_array_transform_constraint_data_create_with_capacity(size_t initialCapacity) {
    return (spine_array_transform_constraint_data) new (__FILE__, __LINE__) Array<TransformConstraintData *>(initialCapacity);
}
void spine_array_transform_constraint_data_dispose(spine_array_transform_constraint_data array) {
    delete (Array<TransformConstraintData *>*)array;
}
void spine_array_transform_constraint_data_clear(spine_array_transform_constraint_data array) {
    ((Array<TransformConstraintData *>*)array)->clear();
}

size_t spine_array_transform_constraint_data_get_capacity(spine_array_transform_constraint_data array) {
    return ((Array<TransformConstraintData *>*)array)->getCapacity();
}

size_t spine_array_transform_constraint_data_size(spine_array_transform_constraint_data array) {
    return ((Array<TransformConstraintData *>*)array)->size();
}

spine_array_transform_constraint_data spine_array_transform_constraint_data_set_size(spine_array_transform_constraint_data array, size_t newSize, spine_transform_constraint_data defaultValue) {
    return (spine_array_transform_constraint_data)&((Array<TransformConstraintData *>*)array)->setSize(newSize, (TransformConstraintData *)defaultValue);
}

void spine_array_transform_constraint_data_ensure_capacity(spine_array_transform_constraint_data array, size_t newCapacity) {
    ((Array<TransformConstraintData *>*)array)->ensureCapacity(newCapacity);
}

void spine_array_transform_constraint_data_add(spine_array_transform_constraint_data array, spine_transform_constraint_data inValue) {
    ((Array<TransformConstraintData *>*)array)->add((TransformConstraintData *)inValue);
}

void spine_array_transform_constraint_data_add_all(spine_array_transform_constraint_data array, spine_array_transform_constraint_data inValue) {
    ((Array<TransformConstraintData *>*)array)->addAll(*((const Array<TransformConstraintData *>*)inValue));
}

void spine_array_transform_constraint_data_clear_and_add_all(spine_array_transform_constraint_data array, spine_array_transform_constraint_data inValue) {
    ((Array<TransformConstraintData *>*)array)->clearAndAddAll(*((const Array<TransformConstraintData *>*)inValue));
}

void spine_array_transform_constraint_data_remove_at(spine_array_transform_constraint_data array, size_t inIndex) {
    ((Array<TransformConstraintData *>*)array)->removeAt(inIndex);
}

bool spine_array_transform_constraint_data_contains(spine_array_transform_constraint_data array, spine_transform_constraint_data inValue) {
    return ((Array<TransformConstraintData *>*)array)->contains((TransformConstraintData *)inValue);
}

int spine_array_transform_constraint_data_index_of(spine_array_transform_constraint_data array, spine_transform_constraint_data inValue) {
    return ((Array<TransformConstraintData *>*)array)->indexOf((TransformConstraintData *)inValue);
}

spine_transform_constraint_data * spine_array_transform_constraint_data_buffer(spine_array_transform_constraint_data array) {
    return (spine_transform_constraint_data *)((Array<TransformConstraintData *>*)array)->buffer();
}

spine_array_update spine_array_update_create(void) {
    return (spine_array_update) new (__FILE__, __LINE__) Array<Update *>();
}

spine_array_update spine_array_update_create_with_capacity(size_t initialCapacity) {
    return (spine_array_update) new (__FILE__, __LINE__) Array<Update *>(initialCapacity);
}
void spine_array_update_dispose(spine_array_update array) {
    delete (Array<Update *>*)array;
}
void spine_array_update_clear(spine_array_update array) {
    ((Array<Update *>*)array)->clear();
}

size_t spine_array_update_get_capacity(spine_array_update array) {
    return ((Array<Update *>*)array)->getCapacity();
}

size_t spine_array_update_size(spine_array_update array) {
    return ((Array<Update *>*)array)->size();
}

spine_array_update spine_array_update_set_size(spine_array_update array, size_t newSize, spine_update defaultValue) {
    return (spine_array_update)&((Array<Update *>*)array)->setSize(newSize, (Update *)defaultValue);
}

void spine_array_update_ensure_capacity(spine_array_update array, size_t newCapacity) {
    ((Array<Update *>*)array)->ensureCapacity(newCapacity);
}

void spine_array_update_add(spine_array_update array, spine_update inValue) {
    ((Array<Update *>*)array)->add((Update *)inValue);
}

void spine_array_update_add_all(spine_array_update array, spine_array_update inValue) {
    ((Array<Update *>*)array)->addAll(*((const Array<Update *>*)inValue));
}

void spine_array_update_clear_and_add_all(spine_array_update array, spine_array_update inValue) {
    ((Array<Update *>*)array)->clearAndAddAll(*((const Array<Update *>*)inValue));
}

void spine_array_update_remove_at(spine_array_update array, size_t inIndex) {
    ((Array<Update *>*)array)->removeAt(inIndex);
}

bool spine_array_update_contains(spine_array_update array, spine_update inValue) {
    return ((Array<Update *>*)array)->contains((Update *)inValue);
}

int spine_array_update_index_of(spine_array_update array, spine_update inValue) {
    return ((Array<Update *>*)array)->indexOf((Update *)inValue);
}

spine_update * spine_array_update_buffer(spine_array_update array) {
    return (spine_update *)((Array<Update *>*)array)->buffer();
}
