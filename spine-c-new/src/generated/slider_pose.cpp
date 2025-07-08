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

#include "slider_pose.h"
#include <spine/spine.h>

using namespace spine;

spine_slider_pose spine_slider_pose_create(void) {
    SliderPose *obj = new (__FILE__, __LINE__) SliderPose();
    return (spine_slider_pose) obj;
}

void spine_slider_pose_dispose(spine_slider_pose obj) {
    if (!obj) return;
    delete (SliderPose *) obj;
}

void spine_slider_pose_set(spine_slider_pose obj, spine_slider_pose value) {
    if (!obj) return;
    SliderPose *_obj = (SliderPose *) obj;
    _obj->set(value);
}

float spine_slider_pose_get_time(spine_slider_pose obj) {
    if (!obj) return 0;
    SliderPose *_obj = (SliderPose *) obj;
    return _obj->getTime();
}

void spine_slider_pose_set_time(spine_slider_pose obj, float value) {
    if (!obj) return;
    SliderPose *_obj = (SliderPose *) obj;
    _obj->setTime(value);
}

float spine_slider_pose_get_mix(spine_slider_pose obj) {
    if (!obj) return 0;
    SliderPose *_obj = (SliderPose *) obj;
    return _obj->getMix();
}

void spine_slider_pose_set_mix(spine_slider_pose obj, float value) {
    if (!obj) return;
    SliderPose *_obj = (SliderPose *) obj;
    _obj->setMix(value);
}
