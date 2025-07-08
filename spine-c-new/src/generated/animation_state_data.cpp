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

#include "animation_state_data.h"
#include <spine/spine.h>

using namespace spine;

spine_animation_state_data spine_animation_state_data_create(spine_skeleton_data skeletonData) {
    AnimationStateData *obj = new (__FILE__, __LINE__) AnimationStateData((SkeletonData *) skeletonData);
    return (spine_animation_state_data) obj;
}

void spine_animation_state_data_dispose(spine_animation_state_data obj) {
    if (!obj) return;
    delete (AnimationStateData *) obj;
}

spine_skeleton_data spine_animation_state_data_get_skeleton_data(spine_animation_state_data obj) {
    if (!obj) return nullptr;
    AnimationStateData *_obj = (AnimationStateData *) obj;
    return (spine_skeleton_data) _obj->getSkeletonData();
}

float spine_animation_state_data_get_default_mix(spine_animation_state_data obj) {
    if (!obj) return 0;
    AnimationStateData *_obj = (AnimationStateData *) obj;
    return _obj->getDefaultMix();
}

void spine_animation_state_data_set_default_mix(spine_animation_state_data obj, float value) {
    if (!obj) return;
    AnimationStateData *_obj = (AnimationStateData *) obj;
    _obj->setDefaultMix(value);
}

void spine_animation_state_data_set_mix(spine_animation_state_data obj, const utf8 * fromName, const utf8 * toName, float duration) {
    if (!obj) return ;
    AnimationStateData *_obj = (AnimationStateData *) obj;
    _obj->setMix(String(fromName), String(toName), duration);
}

void spine_animation_state_data_set_mix(spine_animation_state_data obj, spine_animation from, spine_animation to, float duration) {
    if (!obj) return ;
    AnimationStateData *_obj = (AnimationStateData *) obj;
    _obj->setMix((Animation *) from, (Animation *) to, duration);
}

float spine_animation_state_data_get_mix(spine_animation_state_data obj, spine_animation from, spine_animation to) {
    if (!obj) return 0;
    AnimationStateData *_obj = (AnimationStateData *) obj;
    return _obj->getMix((Animation *) from, (Animation *) to);
}

void spine_animation_state_data_clear(spine_animation_state_data obj) {
    if (!obj) return ;
    AnimationStateData *_obj = (AnimationStateData *) obj;
    _obj->clear();
}
