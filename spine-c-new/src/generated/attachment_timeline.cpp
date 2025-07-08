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

#include "attachment_timeline.h"
#include <spine/spine.h>

using namespace spine;

spine_attachment_timeline spine_attachment_timeline_create(size_t frameCount, int slotIndex) {
    AttachmentTimeline *obj = new (__FILE__, __LINE__) AttachmentTimeline(frameCount, slotIndex);
    return (spine_attachment_timeline) obj;
}

void spine_attachment_timeline_dispose(spine_attachment_timeline obj) {
    if (!obj) return;
    delete (AttachmentTimeline *) obj;
}

spine_rtti spine_attachment_timeline_get_rtti() {
    return (spine_rtti) &AttachmentTimeline::rtti;
}

void spine_attachment_timeline_apply(spine_attachment_timeline obj, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    if (!obj) return ;
    AttachmentTimeline *_obj = (AttachmentTimeline *) obj;
    _obj->apply(*(Skeleton*) skeleton, lastTime, time, (Array<Event *> *) pEvents, alpha, (MixBlend) blend, (MixDirection) direction, appliedPose);
}

void spine_attachment_timeline_set_frame(spine_attachment_timeline obj, int frame, float time, const char* attachmentName) {
    if (!obj) return ;
    AttachmentTimeline *_obj = (AttachmentTimeline *) obj;
    _obj->setFrame(frame, time, String(attachmentName));
}

int32_t spine_attachment_timeline_get_num_attachment_names(spine_attachment_timeline obj) {
    if (!obj) return 0;
    AttachmentTimeline *_obj = (AttachmentTimeline *) obj;
    return (int32_t) _obj->getAttachmentNames().size();
}

const char * *spine_attachment_timeline_get_attachment_names(spine_attachment_timeline obj) {
    if (!obj) return nullptr;
    AttachmentTimeline *_obj = (AttachmentTimeline *) obj;
    return (const char * *) _obj->getAttachmentNames().buffer();
}

size_t spine_attachment_timeline_get_frame_entries(spine_attachment_timeline obj) {
    if (!obj) return 0;
    AttachmentTimeline *_obj = (AttachmentTimeline *) obj;
    return _obj->getFrameEntries();
}

size_t spine_attachment_timeline_get_frame_count(spine_attachment_timeline obj) {
    if (!obj) return 0;
    AttachmentTimeline *_obj = (AttachmentTimeline *) obj;
    return _obj->getFrameCount();
}

int32_t spine_attachment_timeline_get_num_frames(spine_attachment_timeline obj) {
    if (!obj) return 0;
    AttachmentTimeline *_obj = (AttachmentTimeline *) obj;
    return (int32_t) _obj->getFrames().size();
}

float *spine_attachment_timeline_get_frames(spine_attachment_timeline obj) {
    if (!obj) return nullptr;
    AttachmentTimeline *_obj = (AttachmentTimeline *) obj;
    return (float *) _obj->getFrames().buffer();
}

float spine_attachment_timeline_get_duration(spine_attachment_timeline obj) {
    if (!obj) return 0;
    AttachmentTimeline *_obj = (AttachmentTimeline *) obj;
    return _obj->getDuration();
}

int32_t spine_attachment_timeline_get_num_property_ids(spine_attachment_timeline obj) {
    if (!obj) return 0;
    AttachmentTimeline *_obj = (AttachmentTimeline *) obj;
    return (int32_t) _obj->getPropertyIds().size();
}

int64_t *spine_attachment_timeline_get_property_ids(spine_attachment_timeline obj) {
    if (!obj) return nullptr;
    AttachmentTimeline *_obj = (AttachmentTimeline *) obj;
    return (int64_t *) _obj->getPropertyIds().buffer();
}

int spine_attachment_timeline_get_slot_index(spine_attachment_timeline obj) {
    if (!obj) return 0;
    AttachmentTimeline *_obj = (AttachmentTimeline *) obj;
    return _obj->getSlotIndex();
}

void spine_attachment_timeline_set_slot_index(spine_attachment_timeline obj, int value) {
    if (!obj) return;
    AttachmentTimeline *_obj = (AttachmentTimeline *) obj;
    _obj->setSlotIndex(value);
}
