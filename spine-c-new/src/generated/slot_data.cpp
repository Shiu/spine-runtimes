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

#include "slot_data.h"
#include <spine/spine.h>

using namespace spine;

spine_slot_data spine_slot_data_create(int32_t index, const utf8 * name, spine_bone_data boneData) {
    SlotData *obj = new (__FILE__, __LINE__) SlotData(index, String(name), boneData);
    return (spine_slot_data) obj;
}

void spine_slot_data_dispose(spine_slot_data obj) {
    if (!obj) return;
    delete (SlotData *) obj;
}

int32_t spine_slot_data_get_index(spine_slot_data obj) {
    if (!obj) return 0;
    SlotData *_obj = (SlotData *) obj;
    return _obj->getIndex();
}

spine_bone_data spine_slot_data_get_bone_data(spine_slot_data obj) {
    if (!obj) return nullptr;
    SlotData *_obj = (SlotData *) obj;
    return _obj->getBoneData();
}

void spine_slot_data_set_attachment_name(spine_slot_data obj, const utf8 * value) {
    if (!obj) return;
    SlotData *_obj = (SlotData *) obj;
    _obj->setAttachmentName(String(value));
}

const utf8 * spine_slot_data_get_attachment_name(spine_slot_data obj) {
    if (!obj) return nullptr;
    SlotData *_obj = (SlotData *) obj;
    return (const utf8 *) _obj->getAttachmentName().buffer();
}

spine_blend_mode spine_slot_data_get_blend_mode(spine_slot_data obj) {
    if (!obj) return nullptr;
    SlotData *_obj = (SlotData *) obj;
    return _obj->getBlendMode();
}

void spine_slot_data_set_blend_mode(spine_slot_data obj, spine_blend_mode value) {
    if (!obj) return;
    SlotData *_obj = (SlotData *) obj;
    _obj->setBlendMode(value);
}

spine_bool spine_slot_data_get_visible(spine_slot_data obj) {
    if (!obj) return 0;
    SlotData *_obj = (SlotData *) obj;
    return _obj->getVisible();
}

void spine_slot_data_set_visible(spine_slot_data obj, spine_bool value) {
    if (!obj) return;
    SlotData *_obj = (SlotData *) obj;
    _obj->setVisible(value);
}

spine_slot_pose spine_slot_data_get_setup_pose(spine_slot_data obj) {
    if (!obj) return nullptr;
    SlotData *_obj = (SlotData *) obj;
    return _obj->getSetupPose();
}

spine_slot_pose spine_slot_data_get_setup_pose(spine_slot_data obj) {
    if (!obj) return nullptr;
    SlotData *_obj = (SlotData *) obj;
    return _obj->getSetupPose();
}

spine_spine::string spine_slot_data_get_name(spine_slot_data obj) {
    if (!obj) return nullptr;
    SlotData *_obj = (SlotData *) obj;
    return _obj->getName();
}

spine_bool spine_slot_data_is_skin_required(spine_slot_data obj) {
    if (!obj) return 0;
    SlotData *_obj = (SlotData *) obj;
    return _obj->isSkinRequired();
}

void spine_slot_data_set_skin_required(spine_slot_data obj, spine_bool value) {
    if (!obj) return;
    SlotData *_obj = (SlotData *) obj;
    _obj->setSkinRequired(value);
}
