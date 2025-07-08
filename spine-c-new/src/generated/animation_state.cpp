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

#include "animation_state.h"
#include <spine/spine.h>

using namespace spine;

spine_animation_state spine_animation_state_create(spine_animation_state_data data) {
    AnimationState *obj = new (__FILE__, __LINE__) AnimationState((AnimationStateData *) data);
    return (spine_animation_state) obj;
}

void spine_animation_state_dispose(spine_animation_state obj) {
    if (!obj) return;
    delete (AnimationState *) obj;
}

void spine_animation_state_update(spine_animation_state obj, float delta) {
    if (!obj) return ;
    AnimationState *_obj = (AnimationState *) obj;
    _obj->update(delta);
}

bool spine_animation_state_apply(spine_animation_state obj, spine_skeleton skeleton) {
    if (!obj) return false;
    AnimationState *_obj = (AnimationState *) obj;
    return _obj->apply(*(Skeleton*) skeleton);
}

void spine_animation_state_clear_tracks(spine_animation_state obj) {
    if (!obj) return ;
    AnimationState *_obj = (AnimationState *) obj;
    _obj->clearTracks();
}

void spine_animation_state_clear_track(spine_animation_state obj, size_t trackIndex) {
    if (!obj) return ;
    AnimationState *_obj = (AnimationState *) obj;
    _obj->clearTrack(trackIndex);
}

spine_track_entry spine_animation_state_set_animation(spine_animation_state obj, size_t trackIndex, const char* animationName, bool loop) {
    if (!obj) return (spine_track_entry) 0;
    AnimationState *_obj = (AnimationState *) obj;
    return (spine_track_entry) _obj->setAnimation(trackIndex, String(animationName), loop);
}

spine_track_entry spine_animation_state_set_animation_3(spine_animation_state obj, size_t trackIndex, spine_animation animation, bool loop) {
    if (!obj) return (spine_track_entry) 0;
    AnimationState *_obj = (AnimationState *) obj;
    return (spine_track_entry) _obj->setAnimation(trackIndex, (Animation *) animation, loop);
}

spine_track_entry spine_animation_state_add_animation(spine_animation_state obj, size_t trackIndex, const char* animationName, bool loop, float delay) {
    if (!obj) return (spine_track_entry) 0;
    AnimationState *_obj = (AnimationState *) obj;
    return (spine_track_entry) _obj->addAnimation(trackIndex, String(animationName), loop, delay);
}

spine_track_entry spine_animation_state_add_animation_4(spine_animation_state obj, size_t trackIndex, spine_animation animation, bool loop, float delay) {
    if (!obj) return (spine_track_entry) 0;
    AnimationState *_obj = (AnimationState *) obj;
    return (spine_track_entry) _obj->addAnimation(trackIndex, (Animation *) animation, loop, delay);
}

spine_track_entry spine_animation_state_set_empty_animation(spine_animation_state obj, size_t trackIndex, float mixDuration) {
    if (!obj) return (spine_track_entry) 0;
    AnimationState *_obj = (AnimationState *) obj;
    return (spine_track_entry) _obj->setEmptyAnimation(trackIndex, mixDuration);
}

spine_track_entry spine_animation_state_add_empty_animation(spine_animation_state obj, size_t trackIndex, float mixDuration, float delay) {
    if (!obj) return (spine_track_entry) 0;
    AnimationState *_obj = (AnimationState *) obj;
    return (spine_track_entry) _obj->addEmptyAnimation(trackIndex, mixDuration, delay);
}

void spine_animation_state_set_empty_animations(spine_animation_state obj, float value) {
    if (!obj) return;
    AnimationState *_obj = (AnimationState *) obj;
    _obj->setEmptyAnimations(value);
}

spine_track_entry spine_animation_state_get_current(spine_animation_state obj, size_t trackIndex) {
    if (!obj) return (spine_track_entry) 0;
    AnimationState *_obj = (AnimationState *) obj;
    return (spine_track_entry) _obj->getCurrent(trackIndex);
}

spine_animation_state_data spine_animation_state_get_data(spine_animation_state obj) {
    if (!obj) return (spine_animation_state_data) 0;
    AnimationState *_obj = (AnimationState *) obj;
    return (spine_animation_state_data) _obj->getData();
}

int32_t spine_animation_state_get_num_tracks(spine_animation_state obj) {
    if (!obj) return 0;
    AnimationState *_obj = (AnimationState *) obj;
    return (int32_t) _obj->getTracks().size();
}

spine_track_entry *spine_animation_state_get_tracks(spine_animation_state obj) {
    if (!obj) return nullptr;
    AnimationState *_obj = (AnimationState *) obj;
    return (spine_track_entry *) _obj->getTracks().buffer();
}

float spine_animation_state_get_time_scale(spine_animation_state obj) {
    if (!obj) return 0;
    AnimationState *_obj = (AnimationState *) obj;
    return _obj->getTimeScale();
}

void spine_animation_state_set_time_scale(spine_animation_state obj, float value) {
    if (!obj) return;
    AnimationState *_obj = (AnimationState *) obj;
    _obj->setTimeScale(value);
}

void spine_animation_state_disable_queue(spine_animation_state obj) {
    if (!obj) return ;
    AnimationState *_obj = (AnimationState *) obj;
    _obj->disableQueue();
}

void spine_animation_state_enable_queue(spine_animation_state obj) {
    if (!obj) return ;
    AnimationState *_obj = (AnimationState *) obj;
    _obj->enableQueue();
}

void spine_animation_state_set_manual_track_entry_disposal(spine_animation_state obj, bool value) {
    if (!obj) return;
    AnimationState *_obj = (AnimationState *) obj;
    _obj->setManualTrackEntryDisposal(value);
}

bool spine_animation_state_get_manual_track_entry_disposal(spine_animation_state obj) {
    if (!obj) return false;
    AnimationState *_obj = (AnimationState *) obj;
    return _obj->getManualTrackEntryDisposal();
}

void spine_animation_state_dispose_track_entry(spine_animation_state obj, spine_track_entry entry) {
    if (!obj) return ;
    AnimationState *_obj = (AnimationState *) obj;
    _obj->disposeTrackEntry((TrackEntry *) entry);
}

void * spine_animation_state_get_renderer_object(spine_animation_state obj) {
    if (!obj) return nullptr;
    AnimationState *_obj = (AnimationState *) obj;
    return (void *) _obj->getRendererObject();
}
