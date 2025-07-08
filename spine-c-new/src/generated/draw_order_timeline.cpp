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

#include "draw_order_timeline.h"
#include <spine/spine.h>

using namespace spine;

spine_draw_order_timeline spine_draw_order_timeline_create(spine_size_t frameCount) {
    DrawOrderTimeline *obj = new (__FILE__, __LINE__) DrawOrderTimeline(frameCount);
    return (spine_draw_order_timeline) obj;
}

void spine_draw_order_timeline_dispose(spine_draw_order_timeline obj) {
    if (!obj) return;
    delete (DrawOrderTimeline *) obj;
}

spine_rtti spine_draw_order_timeline_get_rtti(spine_draw_order_timeline obj) {
    if (!obj) return nullptr;
    DrawOrderTimeline *_obj = (DrawOrderTimeline *) obj;
    return (spine_rtti) &_obj->getRTTI();
}

void spine_draw_order_timeline_apply(spine_draw_order_timeline obj, spine_skeleton skeleton, float lastTime, float time, void * pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, spine_bool appliedPose) {
    if (!obj) return ;
    DrawOrderTimeline *_obj = (DrawOrderTimeline *) obj;
    _obj->apply(skeleton, lastTime, time, (Vector<Event *> *) pEvents, alpha, blend, direction, appliedPose);
}

spine_size_t spine_draw_order_timeline_get_frame_count(spine_draw_order_timeline obj) {
    if (!obj) return nullptr;
    DrawOrderTimeline *_obj = (DrawOrderTimeline *) obj;
    return _obj->getFrameCount();
}

void * spine_draw_order_timeline_get_draw_orders(spine_draw_order_timeline obj) {
    if (!obj) return nullptr;
    DrawOrderTimeline *_obj = (DrawOrderTimeline *) obj;
    return _obj->getDrawOrders();
}

int32_t spine_draw_order_timeline_get_num_draw_orders(spine_draw_order_timeline obj) {
    if (!obj) return 0;
    DrawOrderTimeline *_obj = (DrawOrderTimeline *) obj;
    return (int32_t) _obj->getDrawOrders().size();
}

spine_vector<int *spine_draw_order_timeline_get_draw_orders(spine_draw_order_timeline obj) {
    if (!obj) return nullptr;
    DrawOrderTimeline *_obj = (DrawOrderTimeline *) obj;
    return (spine_vector<int *) _obj->getDrawOrders().buffer();
}

void spine_draw_order_timeline_set_frame(spine_draw_order_timeline obj, spine_size_t frame, float time, int32_t * drawOrder) {
    if (!obj) return ;
    DrawOrderTimeline *_obj = (DrawOrderTimeline *) obj;
    _obj->setFrame(frame, time, (Vector<int> *) drawOrder);
}

spine_size_t spine_draw_order_timeline_get_frame_entries(spine_draw_order_timeline obj) {
    if (!obj) return nullptr;
    DrawOrderTimeline *_obj = (DrawOrderTimeline *) obj;
    return _obj->getFrameEntries();
}

void * spine_draw_order_timeline_get_frames(spine_draw_order_timeline obj) {
    if (!obj) return nullptr;
    DrawOrderTimeline *_obj = (DrawOrderTimeline *) obj;
    return _obj->getFrames();
}

int32_t spine_draw_order_timeline_get_num_frames(spine_draw_order_timeline obj) {
    if (!obj) return 0;
    DrawOrderTimeline *_obj = (DrawOrderTimeline *) obj;
    return (int32_t) _obj->getFrames().size();
}

spine_float *spine_draw_order_timeline_get_frames(spine_draw_order_timeline obj) {
    if (!obj) return nullptr;
    DrawOrderTimeline *_obj = (DrawOrderTimeline *) obj;
    return (spine_float *) _obj->getFrames().buffer();
}

float spine_draw_order_timeline_get_duration(spine_draw_order_timeline obj) {
    if (!obj) return 0;
    DrawOrderTimeline *_obj = (DrawOrderTimeline *) obj;
    return _obj->getDuration();
}

void * spine_draw_order_timeline_get_property_ids(spine_draw_order_timeline obj) {
    if (!obj) return nullptr;
    DrawOrderTimeline *_obj = (DrawOrderTimeline *) obj;
    return _obj->getPropertyIds();
}

int32_t spine_draw_order_timeline_get_num_property_ids(spine_draw_order_timeline obj) {
    if (!obj) return 0;
    DrawOrderTimeline *_obj = (DrawOrderTimeline *) obj;
    return (int32_t) _obj->getPropertyIds().size();
}

spine_property_id *spine_draw_order_timeline_get_property_ids(spine_draw_order_timeline obj) {
    if (!obj) return nullptr;
    DrawOrderTimeline *_obj = (DrawOrderTimeline *) obj;
    return (spine_property_id *) _obj->getPropertyIds().buffer();
}
