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

#include "attachment.h"
#include <spine/spine.h>

using namespace spine;

spine_attachment spine_attachment_create(const utf8 * name) {
    Attachment *obj = new (__FILE__, __LINE__) Attachment(String(name));
    return (spine_attachment) obj;
}

void spine_attachment_dispose(spine_attachment obj) {
    if (!obj) return;
    delete (Attachment *) obj;
}

spine_rtti spine_attachment_get_rtti(spine_attachment obj) {
    if (!obj) return nullptr;
    Attachment *_obj = (Attachment *) obj;
    return (spine_rtti) &_obj->getRTTI();
}

const utf8 * spine_attachment_get_name(spine_attachment obj) {
    if (!obj) return nullptr;
    Attachment *_obj = (Attachment *) obj;
    return (const utf8 *) _obj->getName().buffer();
}

spine_attachment spine_attachment_copy(spine_attachment obj) {
    if (!obj) return nullptr;
    Attachment *_obj = (Attachment *) obj;
    return (spine_attachment) _obj->copy();
}

int32_t spine_attachment_get_ref_count(spine_attachment obj) {
    if (!obj) return 0;
    Attachment *_obj = (Attachment *) obj;
    return _obj->getRefCount();
}

void spine_attachment_reference(spine_attachment obj) {
    if (!obj) return ;
    Attachment *_obj = (Attachment *) obj;
    _obj->reference();
}

void spine_attachment_dereference(spine_attachment obj) {
    if (!obj) return ;
    Attachment *_obj = (Attachment *) obj;
    _obj->dereference();
}

spine_bool spine_attachment_is_type(spine_attachment obj, spine_attachment_type type) {
    if (!obj) return 0;
    Attachment *_obj = (Attachment *) obj;
    
    switch (type) {
        case SPINE_TYPE_ATTACHMENT_POINT_ATTACHMENT:
            return _obj->getRTTI().instanceOf(PointAttachment::rtti);
        case SPINE_TYPE_ATTACHMENT_REGION_ATTACHMENT:
            return _obj->getRTTI().instanceOf(RegionAttachment::rtti);
        case SPINE_TYPE_ATTACHMENT_BOUNDING_BOX_ATTACHMENT:
            return _obj->getRTTI().instanceOf(BoundingBoxAttachment::rtti);
        case SPINE_TYPE_ATTACHMENT_CLIPPING_ATTACHMENT:
            return _obj->getRTTI().instanceOf(ClippingAttachment::rtti);
        case SPINE_TYPE_ATTACHMENT_MESH_ATTACHMENT:
            return _obj->getRTTI().instanceOf(MeshAttachment::rtti);
        case SPINE_TYPE_ATTACHMENT_PATH_ATTACHMENT:
            return _obj->getRTTI().instanceOf(PathAttachment::rtti);
    }
    return 0;
}

spine_point_attachment spine_attachment_as_point_attachment(spine_attachment obj) {
    if (!obj) return nullptr;
    Attachment *_obj = (Attachment *) obj;
    if (!_obj->getRTTI().instanceOf(PointAttachment::rtti)) return nullptr;
    return (spine_point_attachment) obj;
}

spine_region_attachment spine_attachment_as_region_attachment(spine_attachment obj) {
    if (!obj) return nullptr;
    Attachment *_obj = (Attachment *) obj;
    if (!_obj->getRTTI().instanceOf(RegionAttachment::rtti)) return nullptr;
    return (spine_region_attachment) obj;
}

spine_bounding_box_attachment spine_attachment_as_bounding_box_attachment(spine_attachment obj) {
    if (!obj) return nullptr;
    Attachment *_obj = (Attachment *) obj;
    if (!_obj->getRTTI().instanceOf(BoundingBoxAttachment::rtti)) return nullptr;
    return (spine_bounding_box_attachment) obj;
}

spine_clipping_attachment spine_attachment_as_clipping_attachment(spine_attachment obj) {
    if (!obj) return nullptr;
    Attachment *_obj = (Attachment *) obj;
    if (!_obj->getRTTI().instanceOf(ClippingAttachment::rtti)) return nullptr;
    return (spine_clipping_attachment) obj;
}

spine_mesh_attachment spine_attachment_as_mesh_attachment(spine_attachment obj) {
    if (!obj) return nullptr;
    Attachment *_obj = (Attachment *) obj;
    if (!_obj->getRTTI().instanceOf(MeshAttachment::rtti)) return nullptr;
    return (spine_mesh_attachment) obj;
}

spine_path_attachment spine_attachment_as_path_attachment(spine_attachment obj) {
    if (!obj) return nullptr;
    Attachment *_obj = (Attachment *) obj;
    if (!_obj->getRTTI().instanceOf(PathAttachment::rtti)) return nullptr;
    return (spine_path_attachment) obj;
}
