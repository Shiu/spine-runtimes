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

#include "skeleton_json.h"
#include <spine/spine.h>

using namespace spine;

spine_skeleton_json spine_skeleton_json_create(spine_atlas atlas) {
    SkeletonJson *obj = new (__FILE__, __LINE__) SkeletonJson((Atlas *) atlas);
    return (spine_skeleton_json) obj;
}

spine_skeleton_json spine_skeleton_json_create_with_attachment_loader_bool(spine_attachment_loader attachmentLoader, spine_bool ownsLoader) {
    SkeletonJson *obj = new (__FILE__, __LINE__) SkeletonJson((AttachmentLoader *) attachmentLoader, ownsLoader);
    return (spine_skeleton_json) obj;
}

void spine_skeleton_json_dispose(spine_skeleton_json obj) {
    if (!obj) return;
    delete (SkeletonJson *) obj;
}

spine_skeleton_data spine_skeleton_json_read_skeleton_data_file(spine_skeleton_json obj, const utf8 * path) {
    if (!obj) return nullptr;
    SkeletonJson *_obj = (SkeletonJson *) obj;
    return (spine_skeleton_data) _obj->readSkeletonDataFile(String(path));
}

spine_skeleton_data spine_skeleton_json_read_skeleton_data(spine_skeleton_json obj, const utf8 * json) {
    if (!obj) return nullptr;
    SkeletonJson *_obj = (SkeletonJson *) obj;
    return (spine_skeleton_data) _obj->readSkeletonData((const char *) json);
}

void spine_skeleton_json_set_scale(spine_skeleton_json obj, float value) {
    if (!obj) return;
    SkeletonJson *_obj = (SkeletonJson *) obj;
    _obj->setScale(value);
}

const utf8 * spine_skeleton_json_get_error(spine_skeleton_json obj) {
    if (!obj) return nullptr;
    SkeletonJson *_obj = (SkeletonJson *) obj;
    return (const utf8 *) _obj->getError().buffer();
}
