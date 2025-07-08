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

#include "skin.h"
#include <spine/spine.h>

using namespace spine;

spine_skin spine_skin_create(const utf8 * name) {
    Skin *obj = new (__FILE__, __LINE__) Skin(String(name));
    return (spine_skin) obj;
}

void spine_skin_dispose(spine_skin obj) {
    if (!obj) return;
    delete (Skin *) obj;
}

void spine_skin_set_attachment(spine_skin obj, spine_size_t slotIndex, const utf8 * name, spine_attachment attachment) {
    if (!obj) return ;
    Skin *_obj = (Skin *) obj;
    _obj->setAttachment(slotIndex, String(name), (Attachment *) attachment);
}

spine_attachment spine_skin_get_attachment(spine_skin obj, spine_size_t slotIndex, const utf8 * name) {
    if (!obj) return nullptr;
    Skin *_obj = (Skin *) obj;
    return (spine_attachment) _obj->getAttachment(slotIndex, String(name));
}

void spine_skin_remove_attachment(spine_skin obj, spine_size_t slotIndex, const utf8 * name) {
    if (!obj) return ;
    Skin *_obj = (Skin *) obj;
    _obj->removeAttachment(slotIndex, String(name));
}

void spine_skin_find_names_for_slot(spine_skin obj, spine_size_t slotIndex, void * names) {
    if (!obj) return ;
    Skin *_obj = (Skin *) obj;
    _obj->findNamesForSlot(slotIndex, (Vector<String> &) names);
}

void spine_skin_find_attachments_for_slot(spine_skin obj, spine_size_t slotIndex, void * attachments) {
    if (!obj) return ;
    Skin *_obj = (Skin *) obj;
    _obj->findAttachmentsForSlot(slotIndex, (Vector<Attachment *> &) attachments);
}

const utf8 * spine_skin_get_name(spine_skin obj) {
    if (!obj) return nullptr;
    Skin *_obj = (Skin *) obj;
    return (const utf8 *) _obj->getName().buffer();
}

void spine_skin_add_skin(spine_skin obj, spine_skin other) {
    if (!obj) return ;
    Skin *_obj = (Skin *) obj;
    _obj->addSkin((Skin *) other);
}

void spine_skin_copy_skin(spine_skin obj, spine_skin other) {
    if (!obj) return ;
    Skin *_obj = (Skin *) obj;
    _obj->copySkin((Skin *) other);
}

spine_attachment_map::entries spine_skin_get_attachments(spine_skin obj) {
    if (!obj) return nullptr;
    Skin *_obj = (Skin *) obj;
    return _obj->getAttachments();
}

void * spine_skin_get_bones(spine_skin obj) {
    if (!obj) return nullptr;
    Skin *_obj = (Skin *) obj;
    return (void *) _obj->getBones();
}

int32_t spine_skin_get_num_bones(spine_skin obj) {
    if (!obj) return 0;
    Skin *_obj = (Skin *) obj;
    return (int32_t) _obj->getBones().size();
}

spine_bone_data *spine_skin_get_bones(spine_skin obj) {
    if (!obj) return nullptr;
    Skin *_obj = (Skin *) obj;
    return (spine_bone_data *) _obj->getBones().buffer();
}

void * spine_skin_get_constraints(spine_skin obj) {
    if (!obj) return nullptr;
    Skin *_obj = (Skin *) obj;
    return (void *) _obj->getConstraints();
}

int32_t spine_skin_get_num_constraints(spine_skin obj) {
    if (!obj) return 0;
    Skin *_obj = (Skin *) obj;
    return (int32_t) _obj->getConstraints().size();
}

spine_constraint_data *spine_skin_get_constraints(spine_skin obj) {
    if (!obj) return nullptr;
    Skin *_obj = (Skin *) obj;
    return (spine_constraint_data *) _obj->getConstraints().buffer();
}

spine_color spine_skin_get_color(spine_skin obj) {
    if (!obj) return nullptr;
    Skin *_obj = (Skin *) obj;
    return (spine_color) &_obj->getColor();
}
