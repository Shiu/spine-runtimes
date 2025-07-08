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

#include "transform_constraint_pose.h"
#include <spine/spine.h>

using namespace spine;

spine_transform_constraint_pose spine_transform_constraint_pose_create(void) {
    TransformConstraintPose *obj = new (__FILE__, __LINE__) TransformConstraintPose();
    return (spine_transform_constraint_pose) obj;
}

void spine_transform_constraint_pose_dispose(spine_transform_constraint_pose obj) {
    if (!obj) return;
    delete (TransformConstraintPose *) obj;
}

void spine_transform_constraint_pose_set(spine_transform_constraint_pose obj, spine_transform_constraint_pose value) {
    if (!obj) return;
    TransformConstraintPose *_obj = (TransformConstraintPose *) obj;
    _obj->set(value);
}

float spine_transform_constraint_pose_get_mix_rotate(spine_transform_constraint_pose obj) {
    if (!obj) return 0;
    TransformConstraintPose *_obj = (TransformConstraintPose *) obj;
    return _obj->getMixRotate();
}

void spine_transform_constraint_pose_set_mix_rotate(spine_transform_constraint_pose obj, float value) {
    if (!obj) return;
    TransformConstraintPose *_obj = (TransformConstraintPose *) obj;
    _obj->setMixRotate(value);
}

float spine_transform_constraint_pose_get_mix_x(spine_transform_constraint_pose obj) {
    if (!obj) return 0;
    TransformConstraintPose *_obj = (TransformConstraintPose *) obj;
    return _obj->getMixX();
}

void spine_transform_constraint_pose_set_mix_x(spine_transform_constraint_pose obj, float value) {
    if (!obj) return;
    TransformConstraintPose *_obj = (TransformConstraintPose *) obj;
    _obj->setMixX(value);
}

float spine_transform_constraint_pose_get_mix_y(spine_transform_constraint_pose obj) {
    if (!obj) return 0;
    TransformConstraintPose *_obj = (TransformConstraintPose *) obj;
    return _obj->getMixY();
}

void spine_transform_constraint_pose_set_mix_y(spine_transform_constraint_pose obj, float value) {
    if (!obj) return;
    TransformConstraintPose *_obj = (TransformConstraintPose *) obj;
    _obj->setMixY(value);
}

float spine_transform_constraint_pose_get_mix_scale_x(spine_transform_constraint_pose obj) {
    if (!obj) return 0;
    TransformConstraintPose *_obj = (TransformConstraintPose *) obj;
    return _obj->getMixScaleX();
}

void spine_transform_constraint_pose_set_mix_scale_x(spine_transform_constraint_pose obj, float value) {
    if (!obj) return;
    TransformConstraintPose *_obj = (TransformConstraintPose *) obj;
    _obj->setMixScaleX(value);
}

float spine_transform_constraint_pose_get_mix_scale_y(spine_transform_constraint_pose obj) {
    if (!obj) return 0;
    TransformConstraintPose *_obj = (TransformConstraintPose *) obj;
    return _obj->getMixScaleY();
}

void spine_transform_constraint_pose_set_mix_scale_y(spine_transform_constraint_pose obj, float value) {
    if (!obj) return;
    TransformConstraintPose *_obj = (TransformConstraintPose *) obj;
    _obj->setMixScaleY(value);
}

float spine_transform_constraint_pose_get_mix_shear_y(spine_transform_constraint_pose obj) {
    if (!obj) return 0;
    TransformConstraintPose *_obj = (TransformConstraintPose *) obj;
    return _obj->getMixShearY();
}

void spine_transform_constraint_pose_set_mix_shear_y(spine_transform_constraint_pose obj, float value) {
    if (!obj) return;
    TransformConstraintPose *_obj = (TransformConstraintPose *) obj;
    _obj->setMixShearY(value);
}
