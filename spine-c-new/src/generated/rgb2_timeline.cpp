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

#include "rgb2_timeline.h"
#include <spine/spine.h>

using namespace spine;

spine_rgb2_timeline spine_rgb2_timeline_create(spine_size_t frameCount, spine_size_t bezierCount, int32_t slotIndex) {
    RGB2Timeline *obj = new (__FILE__, __LINE__) RGB2Timeline(frameCount, bezierCount, slotIndex);
    return (spine_rgb2_timeline) obj;
}

void spine_rgb2_timeline_dispose(spine_rgb2_timeline obj) {
    if (!obj) return;
    delete (RGB2Timeline *) obj;
}

spine_rtti spine_rgb2_timeline_get_rtti(spine_rgb2_timeline obj) {
    if (!obj) return nullptr;
    RGB2Timeline *_obj = (RGB2Timeline *) obj;
    return (spine_rtti) &_obj->getRTTI();
}

void spine_rgb2_timeline_set_frame(spine_rgb2_timeline obj, int32_t frame, float time, float r, float g, float b, float r2, float g2, float b2) {
    if (!obj) return ;
    RGB2Timeline *_obj = (RGB2Timeline *) obj;
    _obj->setFrame(frame, time, r, g, b, r2, g2, b2);
}

void spine_rgb2_timeline_apply(spine_rgb2_timeline obj, spine_skeleton skeleton, float lastTime, float time, void * pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, spine_bool appliedPose) {
    if (!obj) return ;
    RGB2Timeline *_obj = (RGB2Timeline *) obj;
    _obj->apply(skeleton, lastTime, time, (Vector<Event *> *) pEvents, alpha, blend, direction, appliedPose);
}
