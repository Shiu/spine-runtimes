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

#include "sequence.h"
#include <spine/spine.h>

using namespace spine;

spine_sequence spine_sequence_create(int32_t count) {
    Sequence *obj = new (__FILE__, __LINE__) Sequence(count);
    return (spine_sequence) obj;
}

void spine_sequence_dispose(spine_sequence obj) {
    if (!obj) return;
    delete (Sequence *) obj;
}

spine_sequence spine_sequence_copy(spine_sequence obj) {
    if (!obj) return nullptr;
    Sequence *_obj = (Sequence *) obj;
    return (spine_sequence) _obj->copy();
}

void spine_sequence_apply(spine_sequence obj, spine_slot_pose slot, spine_attachment attachment) {
    if (!obj) return ;
    Sequence *_obj = (Sequence *) obj;
    _obj->apply((SlotPose *) slot, (Attachment *) attachment);
}

const utf8 * spine_sequence_get_path(spine_sequence obj, const utf8 * basePath, int32_t index) {
    if (!obj) return nullptr;
    Sequence *_obj = (Sequence *) obj;
    return (const utf8 *) _obj->getPath(String(basePath), index).buffer();
}

int32_t spine_sequence_get_id(spine_sequence obj) {
    if (!obj) return 0;
    Sequence *_obj = (Sequence *) obj;
    return _obj->getId();
}

void spine_sequence_set_id(spine_sequence obj, int32_t value) {
    if (!obj) return;
    Sequence *_obj = (Sequence *) obj;
    _obj->setId(value);
}

int32_t spine_sequence_get_start(spine_sequence obj) {
    if (!obj) return 0;
    Sequence *_obj = (Sequence *) obj;
    return _obj->getStart();
}

void spine_sequence_set_start(spine_sequence obj, int32_t value) {
    if (!obj) return;
    Sequence *_obj = (Sequence *) obj;
    _obj->setStart(value);
}

int32_t spine_sequence_get_digits(spine_sequence obj) {
    if (!obj) return 0;
    Sequence *_obj = (Sequence *) obj;
    return _obj->getDigits();
}

void spine_sequence_set_digits(spine_sequence obj, int32_t value) {
    if (!obj) return;
    Sequence *_obj = (Sequence *) obj;
    _obj->setDigits(value);
}

int32_t spine_sequence_get_setup_index(spine_sequence obj) {
    if (!obj) return 0;
    Sequence *_obj = (Sequence *) obj;
    return _obj->getSetupIndex();
}

void spine_sequence_set_setup_index(spine_sequence obj, int32_t value) {
    if (!obj) return;
    Sequence *_obj = (Sequence *) obj;
    _obj->setSetupIndex(value);
}

void * spine_sequence_get_regions(spine_sequence obj) {
    if (!obj) return nullptr;
    Sequence *_obj = (Sequence *) obj;
    return (void *) _obj->getRegions();
}

int32_t spine_sequence_get_num_regions(spine_sequence obj) {
    if (!obj) return 0;
    Sequence *_obj = (Sequence *) obj;
    return (int32_t) _obj->getRegions().size();
}

spine_texture_region *spine_sequence_get_regions(spine_sequence obj) {
    if (!obj) return nullptr;
    Sequence *_obj = (Sequence *) obj;
    return (spine_texture_region *) _obj->getRegions().buffer();
}
