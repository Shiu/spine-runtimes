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

#include "event_timeline.h"
#include <spine/spine.h>

using namespace spine;

spine_event_timeline spine_event_timeline_create(spine_size_t frameCount) {
    EventTimeline *obj = new (__FILE__, __LINE__) EventTimeline(frameCount);
    return (spine_event_timeline) obj;
}

void spine_event_timeline_dispose(spine_event_timeline obj) {
    if (!obj) return;
    delete (EventTimeline *) obj;
}

spine_rtti spine_event_timeline_get_rtti(spine_event_timeline obj) {
    if (!obj) return nullptr;
    EventTimeline *_obj = (EventTimeline *) obj;
    return (spine_rtti) &_obj->getRTTI();
}

void spine_event_timeline_apply(spine_event_timeline obj, spine_skeleton skeleton, float lastTime, float time, void * pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, spine_bool appliedPose) {
    if (!obj) return ;
    EventTimeline *_obj = (EventTimeline *) obj;
    _obj->apply(skeleton, lastTime, time, (Vector<Event *> *) pEvents, alpha, blend, direction, appliedPose);
}

spine_size_t spine_event_timeline_get_frame_count(spine_event_timeline obj) {
    if (!obj) return nullptr;
    EventTimeline *_obj = (EventTimeline *) obj;
    return _obj->getFrameCount();
}

void * spine_event_timeline_get_events(spine_event_timeline obj) {
    if (!obj) return nullptr;
    EventTimeline *_obj = (EventTimeline *) obj;
    return (void *) _obj->getEvents();
}

int32_t spine_event_timeline_get_num_events(spine_event_timeline obj) {
    if (!obj) return 0;
    EventTimeline *_obj = (EventTimeline *) obj;
    return (int32_t) _obj->getEvents().size();
}

spine_event *spine_event_timeline_get_events(spine_event_timeline obj) {
    if (!obj) return nullptr;
    EventTimeline *_obj = (EventTimeline *) obj;
    return (spine_event *) _obj->getEvents().buffer();
}

void spine_event_timeline_set_frame(spine_event_timeline obj, spine_size_t frame, spine_event event) {
    if (!obj) return ;
    EventTimeline *_obj = (EventTimeline *) obj;
    _obj->setFrame(frame, (Event *) event);
}

spine_size_t spine_event_timeline_get_frame_entries(spine_event_timeline obj) {
    if (!obj) return nullptr;
    EventTimeline *_obj = (EventTimeline *) obj;
    return _obj->getFrameEntries();
}

void * spine_event_timeline_get_frames(spine_event_timeline obj) {
    if (!obj) return nullptr;
    EventTimeline *_obj = (EventTimeline *) obj;
    return _obj->getFrames();
}

int32_t spine_event_timeline_get_num_frames(spine_event_timeline obj) {
    if (!obj) return 0;
    EventTimeline *_obj = (EventTimeline *) obj;
    return (int32_t) _obj->getFrames().size();
}

spine_float *spine_event_timeline_get_frames(spine_event_timeline obj) {
    if (!obj) return nullptr;
    EventTimeline *_obj = (EventTimeline *) obj;
    return (spine_float *) _obj->getFrames().buffer();
}

float spine_event_timeline_get_duration(spine_event_timeline obj) {
    if (!obj) return 0;
    EventTimeline *_obj = (EventTimeline *) obj;
    return _obj->getDuration();
}

void * spine_event_timeline_get_property_ids(spine_event_timeline obj) {
    if (!obj) return nullptr;
    EventTimeline *_obj = (EventTimeline *) obj;
    return _obj->getPropertyIds();
}

int32_t spine_event_timeline_get_num_property_ids(spine_event_timeline obj) {
    if (!obj) return 0;
    EventTimeline *_obj = (EventTimeline *) obj;
    return (int32_t) _obj->getPropertyIds().size();
}

spine_property_id *spine_event_timeline_get_property_ids(spine_event_timeline obj) {
    if (!obj) return nullptr;
    EventTimeline *_obj = (EventTimeline *) obj;
    return (spine_property_id *) _obj->getPropertyIds().buffer();
}
