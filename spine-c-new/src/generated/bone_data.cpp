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

#include "bone_data.h"
#include <spine/spine.h>

using namespace spine;

spine_bone_data spine_bone_data_create(int index, const char* name, spine_bone_data parent) {
    BoneData *obj = new (__FILE__, __LINE__) BoneData(index, String(name), (BoneData *) parent);
    return (spine_bone_data) obj;
}

void spine_bone_data_dispose(spine_bone_data obj) {
    if (!obj) return;
    delete (BoneData *) obj;
}

int spine_bone_data_get_index(spine_bone_data obj) {
    if (!obj) return 0;
    BoneData *_obj = (BoneData *) obj;
    return _obj->getIndex();
}

spine_bone_data spine_bone_data_get_parent(spine_bone_data obj) {
    if (!obj) return (spine_bone_data) 0;
    BoneData *_obj = (BoneData *) obj;
    return (spine_bone_data) _obj->getParent();
}

float spine_bone_data_get_length(spine_bone_data obj) {
    if (!obj) return 0;
    BoneData *_obj = (BoneData *) obj;
    return _obj->getLength();
}

void spine_bone_data_set_length(spine_bone_data obj, float value) {
    if (!obj) return;
    BoneData *_obj = (BoneData *) obj;
    _obj->setLength(value);
}

spine_color spine_bone_data_get_color(spine_bone_data obj) {
    if (!obj) return (spine_color) 0;
    BoneData *_obj = (BoneData *) obj;
    return (spine_color) &_obj->getColor();
}

const char* spine_bone_data_get_icon(spine_bone_data obj) {
    if (!obj) return nullptr;
    BoneData *_obj = (BoneData *) obj;
    return (const char *) _obj->getIcon().buffer();
}

void spine_bone_data_set_icon(spine_bone_data obj, const char* value) {
    if (!obj) return;
    BoneData *_obj = (BoneData *) obj;
    _obj->setIcon(String(value));
}

bool spine_bone_data_get_visible(spine_bone_data obj) {
    if (!obj) return false;
    BoneData *_obj = (BoneData *) obj;
    return _obj->getVisible();
}

void spine_bone_data_set_visible(spine_bone_data obj, bool value) {
    if (!obj) return;
    BoneData *_obj = (BoneData *) obj;
    _obj->setVisible(value);
}

spine_bone_local spine_bone_data_get_setup_pose(spine_bone_data obj) {
    if (!obj) return (spine_bone_local) 0;
    BoneData *_obj = (BoneData *) obj;
    return (spine_bone_local) &_obj->getSetupPose();
}
