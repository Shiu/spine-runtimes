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

#include "atlas_attachment_loader.h"
#include <spine/spine.h>

using namespace spine;

spine_atlas_attachment_loader spine_atlas_attachment_loader_create(spine_atlas atlas) {
    AtlasAttachmentLoader *obj = new (__FILE__, __LINE__) AtlasAttachmentLoader((Atlas *) atlas);
    return (spine_atlas_attachment_loader) obj;
}

void spine_atlas_attachment_loader_dispose(spine_atlas_attachment_loader obj) {
    if (!obj) return;
    delete (AtlasAttachmentLoader *) obj;
}

spine_region_attachment spine_atlas_attachment_loader_new_region_attachment(spine_atlas_attachment_loader obj, spine_skin skin, const char* name, const char* path, spine_sequence sequence) {
    if (!obj) return (spine_region_attachment) 0;
    AtlasAttachmentLoader *_obj = (AtlasAttachmentLoader *) obj;
    return (spine_region_attachment) _obj->newRegionAttachment(*(Skin*) skin, String(name), String(path), (Sequence *) sequence);
}

spine_mesh_attachment spine_atlas_attachment_loader_new_mesh_attachment(spine_atlas_attachment_loader obj, spine_skin skin, const char* name, const char* path, spine_sequence sequence) {
    if (!obj) return (spine_mesh_attachment) 0;
    AtlasAttachmentLoader *_obj = (AtlasAttachmentLoader *) obj;
    return (spine_mesh_attachment) _obj->newMeshAttachment(*(Skin*) skin, String(name), String(path), (Sequence *) sequence);
}

spine_bounding_box_attachment spine_atlas_attachment_loader_new_bounding_box_attachment(spine_atlas_attachment_loader obj, spine_skin skin, const char* name) {
    if (!obj) return (spine_bounding_box_attachment) 0;
    AtlasAttachmentLoader *_obj = (AtlasAttachmentLoader *) obj;
    return (spine_bounding_box_attachment) _obj->newBoundingBoxAttachment(*(Skin*) skin, String(name));
}

spine_path_attachment spine_atlas_attachment_loader_new_path_attachment(spine_atlas_attachment_loader obj, spine_skin skin, const char* name) {
    if (!obj) return (spine_path_attachment) 0;
    AtlasAttachmentLoader *_obj = (AtlasAttachmentLoader *) obj;
    return (spine_path_attachment) _obj->newPathAttachment(*(Skin*) skin, String(name));
}

spine_point_attachment spine_atlas_attachment_loader_new_point_attachment(spine_atlas_attachment_loader obj, spine_skin skin, const char* name) {
    if (!obj) return 0;
    AtlasAttachmentLoader *_obj = (AtlasAttachmentLoader *) obj;
    return (spine_point_attachment) _obj->newPointAttachment(*(Skin*) skin, String(name));
}

spine_clipping_attachment spine_atlas_attachment_loader_new_clipping_attachment(spine_atlas_attachment_loader obj, spine_skin skin, const char* name) {
    if (!obj) return (spine_clipping_attachment) 0;
    AtlasAttachmentLoader *_obj = (AtlasAttachmentLoader *) obj;
    return (spine_clipping_attachment) _obj->newClippingAttachment(*(Skin*) skin, String(name));
}

spine_atlas_region spine_atlas_attachment_loader_find_region(spine_atlas_attachment_loader obj, const char* name) {
    if (!obj) return (spine_atlas_region) 0;
    AtlasAttachmentLoader *_obj = (AtlasAttachmentLoader *) obj;
    return (spine_atlas_region) _obj->findRegion(String(name));
}
