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

#include "track_entry.h"
#include <spine/spine.h>

using namespace spine;

spine_track_entry spine_track_entry_create(void) {
    TrackEntry *obj = new (__FILE__, __LINE__) TrackEntry();
    return (spine_track_entry) obj;
}

void spine_track_entry_dispose(spine_track_entry obj) {
    if (!obj) return;
    delete (TrackEntry *) obj;
}

int spine_track_entry_get_track_index(spine_track_entry obj) {
    if (!obj) return 0;
    TrackEntry *_obj = (TrackEntry *) obj;
    return _obj->getTrackIndex();
}

spine_animation spine_track_entry_get_animation(spine_track_entry obj) {
    if (!obj) return (spine_animation) 0;
    TrackEntry *_obj = (TrackEntry *) obj;
    return (spine_animation) _obj->getAnimation();
}

void spine_track_entry_set_animation(spine_track_entry obj, spine_animation value) {
    if (!obj) return;
    TrackEntry *_obj = (TrackEntry *) obj;
    _obj->setAnimation((Animation *) value);
}

spine_track_entry spine_track_entry_get_previous(spine_track_entry obj) {
    if (!obj) return (spine_track_entry) 0;
    TrackEntry *_obj = (TrackEntry *) obj;
    return (spine_track_entry) _obj->getPrevious();
}

bool spine_track_entry_get_loop(spine_track_entry obj) {
    if (!obj) return false;
    TrackEntry *_obj = (TrackEntry *) obj;
    return _obj->getLoop();
}

void spine_track_entry_set_loop(spine_track_entry obj, bool value) {
    if (!obj) return;
    TrackEntry *_obj = (TrackEntry *) obj;
    _obj->setLoop(value);
}

bool spine_track_entry_get_hold_previous(spine_track_entry obj) {
    if (!obj) return false;
    TrackEntry *_obj = (TrackEntry *) obj;
    return _obj->getHoldPrevious();
}

void spine_track_entry_set_hold_previous(spine_track_entry obj, bool value) {
    if (!obj) return;
    TrackEntry *_obj = (TrackEntry *) obj;
    _obj->setHoldPrevious(value);
}

bool spine_track_entry_get_reverse(spine_track_entry obj) {
    if (!obj) return false;
    TrackEntry *_obj = (TrackEntry *) obj;
    return _obj->getReverse();
}

void spine_track_entry_set_reverse(spine_track_entry obj, bool value) {
    if (!obj) return;
    TrackEntry *_obj = (TrackEntry *) obj;
    _obj->setReverse(value);
}

bool spine_track_entry_get_shortest_rotation(spine_track_entry obj) {
    if (!obj) return false;
    TrackEntry *_obj = (TrackEntry *) obj;
    return _obj->getShortestRotation();
}

void spine_track_entry_set_shortest_rotation(spine_track_entry obj, bool value) {
    if (!obj) return;
    TrackEntry *_obj = (TrackEntry *) obj;
    _obj->setShortestRotation(value);
}

float spine_track_entry_get_delay(spine_track_entry obj) {
    if (!obj) return 0;
    TrackEntry *_obj = (TrackEntry *) obj;
    return _obj->getDelay();
}

void spine_track_entry_set_delay(spine_track_entry obj, float value) {
    if (!obj) return;
    TrackEntry *_obj = (TrackEntry *) obj;
    _obj->setDelay(value);
}

float spine_track_entry_get_track_time(spine_track_entry obj) {
    if (!obj) return 0;
    TrackEntry *_obj = (TrackEntry *) obj;
    return _obj->getTrackTime();
}

void spine_track_entry_set_track_time(spine_track_entry obj, float value) {
    if (!obj) return;
    TrackEntry *_obj = (TrackEntry *) obj;
    _obj->setTrackTime(value);
}

float spine_track_entry_get_track_end(spine_track_entry obj) {
    if (!obj) return 0;
    TrackEntry *_obj = (TrackEntry *) obj;
    return _obj->getTrackEnd();
}

void spine_track_entry_set_track_end(spine_track_entry obj, float value) {
    if (!obj) return;
    TrackEntry *_obj = (TrackEntry *) obj;
    _obj->setTrackEnd(value);
}

float spine_track_entry_get_animation_start(spine_track_entry obj) {
    if (!obj) return 0;
    TrackEntry *_obj = (TrackEntry *) obj;
    return _obj->getAnimationStart();
}

void spine_track_entry_set_animation_start(spine_track_entry obj, float value) {
    if (!obj) return;
    TrackEntry *_obj = (TrackEntry *) obj;
    _obj->setAnimationStart(value);
}

float spine_track_entry_get_animation_end(spine_track_entry obj) {
    if (!obj) return 0;
    TrackEntry *_obj = (TrackEntry *) obj;
    return _obj->getAnimationEnd();
}

void spine_track_entry_set_animation_end(spine_track_entry obj, float value) {
    if (!obj) return;
    TrackEntry *_obj = (TrackEntry *) obj;
    _obj->setAnimationEnd(value);
}

float spine_track_entry_get_animation_last(spine_track_entry obj) {
    if (!obj) return 0;
    TrackEntry *_obj = (TrackEntry *) obj;
    return _obj->getAnimationLast();
}

void spine_track_entry_set_animation_last(spine_track_entry obj, float value) {
    if (!obj) return;
    TrackEntry *_obj = (TrackEntry *) obj;
    _obj->setAnimationLast(value);
}

float spine_track_entry_get_animation_time(spine_track_entry obj) {
    if (!obj) return 0;
    TrackEntry *_obj = (TrackEntry *) obj;
    return _obj->getAnimationTime();
}

float spine_track_entry_get_time_scale(spine_track_entry obj) {
    if (!obj) return 0;
    TrackEntry *_obj = (TrackEntry *) obj;
    return _obj->getTimeScale();
}

void spine_track_entry_set_time_scale(spine_track_entry obj, float value) {
    if (!obj) return;
    TrackEntry *_obj = (TrackEntry *) obj;
    _obj->setTimeScale(value);
}

float spine_track_entry_get_alpha(spine_track_entry obj) {
    if (!obj) return 0;
    TrackEntry *_obj = (TrackEntry *) obj;
    return _obj->getAlpha();
}

void spine_track_entry_set_alpha(spine_track_entry obj, float value) {
    if (!obj) return;
    TrackEntry *_obj = (TrackEntry *) obj;
    _obj->setAlpha(value);
}

float spine_track_entry_get_event_threshold(spine_track_entry obj) {
    if (!obj) return 0;
    TrackEntry *_obj = (TrackEntry *) obj;
    return _obj->getEventThreshold();
}

void spine_track_entry_set_event_threshold(spine_track_entry obj, float value) {
    if (!obj) return;
    TrackEntry *_obj = (TrackEntry *) obj;
    _obj->setEventThreshold(value);
}

float spine_track_entry_get_mix_attachment_threshold(spine_track_entry obj) {
    if (!obj) return 0;
    TrackEntry *_obj = (TrackEntry *) obj;
    return _obj->getMixAttachmentThreshold();
}

void spine_track_entry_set_mix_attachment_threshold(spine_track_entry obj, float value) {
    if (!obj) return;
    TrackEntry *_obj = (TrackEntry *) obj;
    _obj->setMixAttachmentThreshold(value);
}

float spine_track_entry_get_alpha_attachment_threshold(spine_track_entry obj) {
    if (!obj) return 0;
    TrackEntry *_obj = (TrackEntry *) obj;
    return _obj->getAlphaAttachmentThreshold();
}

void spine_track_entry_set_alpha_attachment_threshold(spine_track_entry obj, float value) {
    if (!obj) return;
    TrackEntry *_obj = (TrackEntry *) obj;
    _obj->setAlphaAttachmentThreshold(value);
}

float spine_track_entry_get_mix_draw_order_threshold(spine_track_entry obj) {
    if (!obj) return 0;
    TrackEntry *_obj = (TrackEntry *) obj;
    return _obj->getMixDrawOrderThreshold();
}

void spine_track_entry_set_mix_draw_order_threshold(spine_track_entry obj, float value) {
    if (!obj) return;
    TrackEntry *_obj = (TrackEntry *) obj;
    _obj->setMixDrawOrderThreshold(value);
}

spine_track_entry spine_track_entry_get_next(spine_track_entry obj) {
    if (!obj) return (spine_track_entry) 0;
    TrackEntry *_obj = (TrackEntry *) obj;
    return (spine_track_entry) _obj->getNext();
}

bool spine_track_entry_is_complete(spine_track_entry obj) {
    if (!obj) return false;
    TrackEntry *_obj = (TrackEntry *) obj;
    return _obj->isComplete();
}

float spine_track_entry_get_mix_time(spine_track_entry obj) {
    if (!obj) return 0;
    TrackEntry *_obj = (TrackEntry *) obj;
    return _obj->getMixTime();
}

void spine_track_entry_set_mix_time(spine_track_entry obj, float value) {
    if (!obj) return;
    TrackEntry *_obj = (TrackEntry *) obj;
    _obj->setMixTime(value);
}

float spine_track_entry_get_mix_duration(spine_track_entry obj) {
    if (!obj) return 0;
    TrackEntry *_obj = (TrackEntry *) obj;
    return _obj->getMixDuration();
}

void spine_track_entry_set_mix_duration(spine_track_entry obj, float value) {
    if (!obj) return;
    TrackEntry *_obj = (TrackEntry *) obj;
    _obj->setMixDuration(value);
}

void spine_track_entry_set_mix_duration(spine_track_entry obj, float mixDuration, float delay) {
    if (!obj) return ;
    TrackEntry *_obj = (TrackEntry *) obj;
    _obj->setMixDuration(mixDuration, delay);
}

spine_mix_blend spine_track_entry_get_mix_blend(spine_track_entry obj) {
    if (!obj) return (spine_mix_blend) 0;
    TrackEntry *_obj = (TrackEntry *) obj;
    return (spine_mix_blend) _obj->getMixBlend();
}

void spine_track_entry_set_mix_blend(spine_track_entry obj, spine_mix_blend value) {
    if (!obj) return;
    TrackEntry *_obj = (TrackEntry *) obj;
    _obj->setMixBlend((MixBlend) value);
}

spine_track_entry spine_track_entry_get_mixing_from(spine_track_entry obj) {
    if (!obj) return (spine_track_entry) 0;
    TrackEntry *_obj = (TrackEntry *) obj;
    return (spine_track_entry) _obj->getMixingFrom();
}

spine_track_entry spine_track_entry_get_mixing_to(spine_track_entry obj) {
    if (!obj) return (spine_track_entry) 0;
    TrackEntry *_obj = (TrackEntry *) obj;
    return (spine_track_entry) _obj->getMixingTo();
}

void spine_track_entry_reset_rotation_directions(spine_track_entry obj) {
    if (!obj) return ;
    TrackEntry *_obj = (TrackEntry *) obj;
    _obj->resetRotationDirections();
}

float spine_track_entry_get_track_complete(spine_track_entry obj) {
    if (!obj) return 0;
    TrackEntry *_obj = (TrackEntry *) obj;
    return _obj->getTrackComplete();
}

bool spine_track_entry_is_empty_animation(spine_track_entry obj) {
    if (!obj) return false;
    TrackEntry *_obj = (TrackEntry *) obj;
    return _obj->isEmptyAnimation();
}

bool spine_track_entry_was_applied(spine_track_entry obj) {
    if (!obj) return false;
    TrackEntry *_obj = (TrackEntry *) obj;
    return _obj->wasApplied();
}

bool spine_track_entry_is_next_ready(spine_track_entry obj) {
    if (!obj) return false;
    TrackEntry *_obj = (TrackEntry *) obj;
    return _obj->isNextReady();
}

void * spine_track_entry_get_renderer_object(spine_track_entry obj) {
    if (!obj) return nullptr;
    TrackEntry *_obj = (TrackEntry *) obj;
    return (void *) _obj->getRendererObject();
}
