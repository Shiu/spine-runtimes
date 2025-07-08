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

#include "animation.h"
#include <spine/spine.h>

using namespace spine;

spine_animation spine_animation_create(const char* name, spine_array_timeline timelines, float duration) {
    Animation *obj = new (__FILE__, __LINE__) Animation(String(name), (Array<Timeline *> &) timelines, duration);
    return (spine_animation) obj;
}

void spine_animation_dispose(spine_animation obj) {
    if (!obj) return;
    delete (Animation *) obj;
}

int32_t spine_animation_get_num_timelines(spine_animation obj) {
    if (!obj) return 0;
    Animation *_obj = (Animation *) obj;
    return (int32_t) _obj->getTimelines().size();
}

spine_timeline *spine_animation_get_timelines(spine_animation obj) {
    if (!obj) return nullptr;
    Animation *_obj = (Animation *) obj;
    return (spine_timeline *) _obj->getTimelines().buffer();
}

void spine_animation_set_timelines(spine_animation obj, spine_array_timeline value) {
    if (!obj) return;
    Animation *_obj = (Animation *) obj;
    _obj->setTimelines((Array<Timeline *> &) value);
}

bool spine_animation_has_timeline(spine_animation obj, spine_array_property_id ids) {
    if (!obj) return false;
    Animation *_obj = (Animation *) obj;
    return _obj->hasTimeline((Array<PropertyId> &) ids);
}

float spine_animation_get_duration(spine_animation obj) {
    if (!obj) return 0;
    Animation *_obj = (Animation *) obj;
    return _obj->getDuration();
}

void spine_animation_set_duration(spine_animation obj, float value) {
    if (!obj) return;
    Animation *_obj = (Animation *) obj;
    _obj->setDuration(value);
}

void spine_animation_apply(spine_animation obj, spine_skeleton skeleton, float lastTime, float time, bool loop, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    if (!obj) return ;
    Animation *_obj = (Animation *) obj;
    _obj->apply(*(Skeleton*) skeleton, lastTime, time, loop, (Array<Event *> *) pEvents, alpha, (MixBlend) blend, (MixDirection) direction, appliedPose);
}

const char* spine_animation_get_name(spine_animation obj) {
    if (!obj) return nullptr;
    Animation *_obj = (Animation *) obj;
    return (const char *) _obj->getName().buffer();
}

int32_t spine_animation_get_num_bones(spine_animation obj) {
    if (!obj) return 0;
    Animation *_obj = (Animation *) obj;
    return (int32_t) _obj->getBones().size();
}

int *spine_animation_get_bones(spine_animation obj) {
    if (!obj) return nullptr;
    Animation *_obj = (Animation *) obj;
    auto& vec = _obj->getBones();
    if (vec.size() == 0) return nullptr;
    return (int *) &vec[0];
}
