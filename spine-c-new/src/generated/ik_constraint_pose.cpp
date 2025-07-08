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

#include "ik_constraint_pose.h"
#include <spine/spine.h>

using namespace spine;

spine_ik_constraint_pose spine_ik_constraint_pose_create(void) {
    IkConstraintPose *obj = new (__FILE__, __LINE__) IkConstraintPose();
    return (spine_ik_constraint_pose) obj;
}

void spine_ik_constraint_pose_dispose(spine_ik_constraint_pose obj) {
    if (!obj) return;
    delete (IkConstraintPose *) obj;
}

void spine_ik_constraint_pose_set(spine_ik_constraint_pose obj, spine_ik_constraint_pose value) {
    if (!obj) return;
    IkConstraintPose *_obj = (IkConstraintPose *) obj;
    _obj->set(*((IkConstraintPose*) value));
}

float spine_ik_constraint_pose_get_mix(spine_ik_constraint_pose obj) {
    if (!obj) return 0;
    IkConstraintPose *_obj = (IkConstraintPose *) obj;
    return _obj->getMix();
}

void spine_ik_constraint_pose_set_mix(spine_ik_constraint_pose obj, float value) {
    if (!obj) return;
    IkConstraintPose *_obj = (IkConstraintPose *) obj;
    _obj->setMix(value);
}

float spine_ik_constraint_pose_get_softness(spine_ik_constraint_pose obj) {
    if (!obj) return 0;
    IkConstraintPose *_obj = (IkConstraintPose *) obj;
    return _obj->getSoftness();
}

void spine_ik_constraint_pose_set_softness(spine_ik_constraint_pose obj, float value) {
    if (!obj) return;
    IkConstraintPose *_obj = (IkConstraintPose *) obj;
    _obj->setSoftness(value);
}

int spine_ik_constraint_pose_get_bend_direction(spine_ik_constraint_pose obj) {
    if (!obj) return 0;
    IkConstraintPose *_obj = (IkConstraintPose *) obj;
    return _obj->getBendDirection();
}

void spine_ik_constraint_pose_set_bend_direction(spine_ik_constraint_pose obj, int value) {
    if (!obj) return;
    IkConstraintPose *_obj = (IkConstraintPose *) obj;
    _obj->setBendDirection(value);
}

bool spine_ik_constraint_pose_get_compress(spine_ik_constraint_pose obj) {
    if (!obj) return false;
    IkConstraintPose *_obj = (IkConstraintPose *) obj;
    return _obj->getCompress();
}

void spine_ik_constraint_pose_set_compress(spine_ik_constraint_pose obj, bool value) {
    if (!obj) return;
    IkConstraintPose *_obj = (IkConstraintPose *) obj;
    _obj->setCompress(value);
}

bool spine_ik_constraint_pose_get_stretch(spine_ik_constraint_pose obj) {
    if (!obj) return false;
    IkConstraintPose *_obj = (IkConstraintPose *) obj;
    return _obj->getStretch();
}

void spine_ik_constraint_pose_set_stretch(spine_ik_constraint_pose obj, bool value) {
    if (!obj) return;
    IkConstraintPose *_obj = (IkConstraintPose *) obj;
    _obj->setStretch(value);
}
