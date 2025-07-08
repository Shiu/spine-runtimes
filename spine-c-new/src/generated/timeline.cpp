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

#include "timeline.h"
#include <spine/spine.h>

using namespace spine;

void spine_timeline_dispose(spine_timeline obj) {
    if (!obj) return;
    delete (Timeline *) obj;
}

spine_rtti spine_timeline_get_rtti() {
    return (spine_rtti) &Timeline::rtti;
}

void spine_timeline_apply(spine_timeline obj, spine_skeleton skeleton, float lastTime, float time, spine_array_event pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, bool appliedPose) {
    if (!obj) return ;
    Timeline *_obj = (Timeline *) obj;
    _obj->apply(*(Skeleton*) skeleton, lastTime, time, (Array<Event *> *) pEvents, alpha, (MixBlend) blend, (MixDirection) direction, appliedPose);
}

size_t spine_timeline_get_frame_entries(spine_timeline obj) {
    if (!obj) return 0;
    Timeline *_obj = (Timeline *) obj;
    return _obj->getFrameEntries();
}

size_t spine_timeline_get_frame_count(spine_timeline obj) {
    if (!obj) return 0;
    Timeline *_obj = (Timeline *) obj;
    return _obj->getFrameCount();
}

int32_t spine_timeline_get_num_frames(spine_timeline obj) {
    if (!obj) return 0;
    Timeline *_obj = (Timeline *) obj;
    return (int32_t) _obj->getFrames().size();
}

float *spine_timeline_get_frames(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    return (float *) _obj->getFrames().buffer();
}

float spine_timeline_get_duration(spine_timeline obj) {
    if (!obj) return 0;
    Timeline *_obj = (Timeline *) obj;
    return _obj->getDuration();
}

int32_t spine_timeline_get_num_property_ids(spine_timeline obj) {
    if (!obj) return 0;
    Timeline *_obj = (Timeline *) obj;
    return (int32_t) _obj->getPropertyIds().size();
}

int64_t *spine_timeline_get_property_ids(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    return (int64_t *) _obj->getPropertyIds().buffer();
}
