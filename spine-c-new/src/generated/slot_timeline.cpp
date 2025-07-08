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

#include "slot_timeline.h"
#include <spine/spine.h>

using namespace spine;

spine_slot_timeline spine_slot_timeline_create(int32_t slotIndex) {
    SlotTimeline *obj = new (__FILE__, __LINE__) SlotTimeline(slotIndex);
    return (spine_slot_timeline) obj;
}

void spine_slot_timeline_dispose(spine_slot_timeline obj) {
    if (!obj) return;
    delete (SlotTimeline *) obj;
}

spine_rtti spine_slot_timeline_get_rtti(spine_slot_timeline obj) {
    if (!obj) return nullptr;
    SlotTimeline *_obj = (SlotTimeline *) obj;
    return (spine_rtti) &_obj->getRTTI();
}

int32_t spine_slot_timeline_get_slot_index(spine_slot_timeline obj) {
    if (!obj) return 0;
    SlotTimeline *_obj = (SlotTimeline *) obj;
    return _obj->getSlotIndex();
}

void spine_slot_timeline_set_slot_index(spine_slot_timeline obj, int32_t value) {
    if (!obj) return;
    SlotTimeline *_obj = (SlotTimeline *) obj;
    _obj->setSlotIndex(value);
}
