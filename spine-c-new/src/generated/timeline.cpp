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

spine_timeline spine_timeline_create(spine_size_t frameCount, spine_size_t frameEntries) {
    Timeline *obj = new (__FILE__, __LINE__) Timeline(frameCount, frameEntries);
    return (spine_timeline) obj;
}

void spine_timeline_dispose(spine_timeline obj) {
    if (!obj) return;
    delete (Timeline *) obj;
}

spine_rtti spine_timeline_get_rtti(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    return (spine_rtti) &_obj->getRTTI();
}

void spine_timeline_apply(spine_timeline obj, spine_skeleton skeleton, float lastTime, float time, void * pEvents, float alpha, spine_mix_blend blend, spine_mix_direction direction, spine_bool appliedPose) {
    if (!obj) return ;
    Timeline *_obj = (Timeline *) obj;
    _obj->apply(skeleton, lastTime, time, (Vector<Event *> *) pEvents, alpha, blend, direction, appliedPose);
}

spine_size_t spine_timeline_get_frame_entries(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    return _obj->getFrameEntries();
}

spine_size_t spine_timeline_get_frame_count(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    return _obj->getFrameCount();
}

void * spine_timeline_get_frames(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    return _obj->getFrames();
}

int32_t spine_timeline_get_num_frames(spine_timeline obj) {
    if (!obj) return 0;
    Timeline *_obj = (Timeline *) obj;
    return (int32_t) _obj->getFrames().size();
}

spine_float *spine_timeline_get_frames(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    return (spine_float *) _obj->getFrames().buffer();
}

float spine_timeline_get_duration(spine_timeline obj) {
    if (!obj) return 0;
    Timeline *_obj = (Timeline *) obj;
    return _obj->getDuration();
}

void * spine_timeline_get_property_ids(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    return _obj->getPropertyIds();
}

int32_t spine_timeline_get_num_property_ids(spine_timeline obj) {
    if (!obj) return 0;
    Timeline *_obj = (Timeline *) obj;
    return (int32_t) _obj->getPropertyIds().size();
}

spine_property_id *spine_timeline_get_property_ids(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    return (spine_property_id *) _obj->getPropertyIds().buffer();
}

spine_bool spine_timeline_is_type(spine_timeline obj, spine_timeline_type type) {
    if (!obj) return 0;
    Timeline *_obj = (Timeline *) obj;
    
    switch (type) {
        case SPINE_TYPE_TIMELINE_ATTACHMENT_TIMELINE:
            return _obj->getRTTI().instanceOf(AttachmentTimeline::rtti);
        case SPINE_TYPE_TIMELINE_ROTATE_TIMELINE:
            return _obj->getRTTI().instanceOf(RotateTimeline::rtti);
        case SPINE_TYPE_TIMELINE_SCALE_X_TIMELINE:
            return _obj->getRTTI().instanceOf(ScaleXTimeline::rtti);
        case SPINE_TYPE_TIMELINE_SCALE_Y_TIMELINE:
            return _obj->getRTTI().instanceOf(ScaleYTimeline::rtti);
        case SPINE_TYPE_TIMELINE_SHEAR_X_TIMELINE:
            return _obj->getRTTI().instanceOf(ShearXTimeline::rtti);
        case SPINE_TYPE_TIMELINE_SHEAR_Y_TIMELINE:
            return _obj->getRTTI().instanceOf(ShearYTimeline::rtti);
        case SPINE_TYPE_TIMELINE_TRANSLATE_X_TIMELINE:
            return _obj->getRTTI().instanceOf(TranslateXTimeline::rtti);
        case SPINE_TYPE_TIMELINE_TRANSLATE_Y_TIMELINE:
            return _obj->getRTTI().instanceOf(TranslateYTimeline::rtti);
        case SPINE_TYPE_TIMELINE_ALPHA_TIMELINE:
            return _obj->getRTTI().instanceOf(AlphaTimeline::rtti);
        case SPINE_TYPE_TIMELINE_PATH_CONSTRAINT_POSITION_TIMELINE:
            return _obj->getRTTI().instanceOf(PathConstraintPositionTimeline::rtti);
        case SPINE_TYPE_TIMELINE_PATH_CONSTRAINT_SPACING_TIMELINE:
            return _obj->getRTTI().instanceOf(PathConstraintSpacingTimeline::rtti);
        case SPINE_TYPE_TIMELINE_SLIDER_MIX_TIMELINE:
            return _obj->getRTTI().instanceOf(SliderMixTimeline::rtti);
        case SPINE_TYPE_TIMELINE_SLIDER_TIMELINE:
            return _obj->getRTTI().instanceOf(SliderTimeline::rtti);
        case SPINE_TYPE_TIMELINE_PHYSICS_CONSTRAINT_INERTIA_TIMELINE:
            return _obj->getRTTI().instanceOf(PhysicsConstraintInertiaTimeline::rtti);
        case SPINE_TYPE_TIMELINE_PHYSICS_CONSTRAINT_STRENGTH_TIMELINE:
            return _obj->getRTTI().instanceOf(PhysicsConstraintStrengthTimeline::rtti);
        case SPINE_TYPE_TIMELINE_PHYSICS_CONSTRAINT_DAMPING_TIMELINE:
            return _obj->getRTTI().instanceOf(PhysicsConstraintDampingTimeline::rtti);
        case SPINE_TYPE_TIMELINE_PHYSICS_CONSTRAINT_MASS_TIMELINE:
            return _obj->getRTTI().instanceOf(PhysicsConstraintMassTimeline::rtti);
        case SPINE_TYPE_TIMELINE_PHYSICS_CONSTRAINT_WIND_TIMELINE:
            return _obj->getRTTI().instanceOf(PhysicsConstraintWindTimeline::rtti);
        case SPINE_TYPE_TIMELINE_PHYSICS_CONSTRAINT_GRAVITY_TIMELINE:
            return _obj->getRTTI().instanceOf(PhysicsConstraintGravityTimeline::rtti);
        case SPINE_TYPE_TIMELINE_PHYSICS_CONSTRAINT_MIX_TIMELINE:
            return _obj->getRTTI().instanceOf(PhysicsConstraintMixTimeline::rtti);
        case SPINE_TYPE_TIMELINE_SCALE_TIMELINE:
            return _obj->getRTTI().instanceOf(ScaleTimeline::rtti);
        case SPINE_TYPE_TIMELINE_SHEAR_TIMELINE:
            return _obj->getRTTI().instanceOf(ShearTimeline::rtti);
        case SPINE_TYPE_TIMELINE_TRANSLATE_TIMELINE:
            return _obj->getRTTI().instanceOf(TranslateTimeline::rtti);
        case SPINE_TYPE_TIMELINE_IK_CONSTRAINT_TIMELINE:
            return _obj->getRTTI().instanceOf(IkConstraintTimeline::rtti);
        case SPINE_TYPE_TIMELINE_PATH_CONSTRAINT_MIX_TIMELINE:
            return _obj->getRTTI().instanceOf(PathConstraintMixTimeline::rtti);
        case SPINE_TYPE_TIMELINE_RGBA_TIMELINE:
            return _obj->getRTTI().instanceOf(RGBATimeline::rtti);
        case SPINE_TYPE_TIMELINE_RGB_TIMELINE:
            return _obj->getRTTI().instanceOf(RGBTimeline::rtti);
        case SPINE_TYPE_TIMELINE_RGBA2_TIMELINE:
            return _obj->getRTTI().instanceOf(RGBA2Timeline::rtti);
        case SPINE_TYPE_TIMELINE_RGB2_TIMELINE:
            return _obj->getRTTI().instanceOf(RGB2Timeline::rtti);
        case SPINE_TYPE_TIMELINE_DEFORM_TIMELINE:
            return _obj->getRTTI().instanceOf(DeformTimeline::rtti);
        case SPINE_TYPE_TIMELINE_TRANSFORM_CONSTRAINT_TIMELINE:
            return _obj->getRTTI().instanceOf(TransformConstraintTimeline::rtti);
        case SPINE_TYPE_TIMELINE_DRAW_ORDER_TIMELINE:
            return _obj->getRTTI().instanceOf(DrawOrderTimeline::rtti);
        case SPINE_TYPE_TIMELINE_EVENT_TIMELINE:
            return _obj->getRTTI().instanceOf(EventTimeline::rtti);
        case SPINE_TYPE_TIMELINE_INHERIT_TIMELINE:
            return _obj->getRTTI().instanceOf(InheritTimeline::rtti);
        case SPINE_TYPE_TIMELINE_PHYSICS_CONSTRAINT_RESET_TIMELINE:
            return _obj->getRTTI().instanceOf(PhysicsConstraintResetTimeline::rtti);
        case SPINE_TYPE_TIMELINE_SEQUENCE_TIMELINE:
            return _obj->getRTTI().instanceOf(SequenceTimeline::rtti);
    }
    return 0;
}

spine_attachment_timeline spine_timeline_as_attachment_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(AttachmentTimeline::rtti)) return nullptr;
    return (spine_attachment_timeline) obj;
}

spine_rotate_timeline spine_timeline_as_rotate_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(RotateTimeline::rtti)) return nullptr;
    return (spine_rotate_timeline) obj;
}

spine_scale_x_timeline spine_timeline_as_scale_x_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(ScaleXTimeline::rtti)) return nullptr;
    return (spine_scale_x_timeline) obj;
}

spine_scale_y_timeline spine_timeline_as_scale_y_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(ScaleYTimeline::rtti)) return nullptr;
    return (spine_scale_y_timeline) obj;
}

spine_shear_x_timeline spine_timeline_as_shear_x_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(ShearXTimeline::rtti)) return nullptr;
    return (spine_shear_x_timeline) obj;
}

spine_shear_y_timeline spine_timeline_as_shear_y_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(ShearYTimeline::rtti)) return nullptr;
    return (spine_shear_y_timeline) obj;
}

spine_translate_x_timeline spine_timeline_as_translate_x_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(TranslateXTimeline::rtti)) return nullptr;
    return (spine_translate_x_timeline) obj;
}

spine_translate_y_timeline spine_timeline_as_translate_y_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(TranslateYTimeline::rtti)) return nullptr;
    return (spine_translate_y_timeline) obj;
}

spine_alpha_timeline spine_timeline_as_alpha_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(AlphaTimeline::rtti)) return nullptr;
    return (spine_alpha_timeline) obj;
}

spine_path_constraint_position_timeline spine_timeline_as_path_constraint_position_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(PathConstraintPositionTimeline::rtti)) return nullptr;
    return (spine_path_constraint_position_timeline) obj;
}

spine_path_constraint_spacing_timeline spine_timeline_as_path_constraint_spacing_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(PathConstraintSpacingTimeline::rtti)) return nullptr;
    return (spine_path_constraint_spacing_timeline) obj;
}

spine_slider_mix_timeline spine_timeline_as_slider_mix_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(SliderMixTimeline::rtti)) return nullptr;
    return (spine_slider_mix_timeline) obj;
}

spine_slider_timeline spine_timeline_as_slider_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(SliderTimeline::rtti)) return nullptr;
    return (spine_slider_timeline) obj;
}

spine_physics_constraint_inertia_timeline spine_timeline_as_physics_constraint_inertia_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(PhysicsConstraintInertiaTimeline::rtti)) return nullptr;
    return (spine_physics_constraint_inertia_timeline) obj;
}

spine_physics_constraint_strength_timeline spine_timeline_as_physics_constraint_strength_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(PhysicsConstraintStrengthTimeline::rtti)) return nullptr;
    return (spine_physics_constraint_strength_timeline) obj;
}

spine_physics_constraint_damping_timeline spine_timeline_as_physics_constraint_damping_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(PhysicsConstraintDampingTimeline::rtti)) return nullptr;
    return (spine_physics_constraint_damping_timeline) obj;
}

spine_physics_constraint_mass_timeline spine_timeline_as_physics_constraint_mass_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(PhysicsConstraintMassTimeline::rtti)) return nullptr;
    return (spine_physics_constraint_mass_timeline) obj;
}

spine_physics_constraint_wind_timeline spine_timeline_as_physics_constraint_wind_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(PhysicsConstraintWindTimeline::rtti)) return nullptr;
    return (spine_physics_constraint_wind_timeline) obj;
}

spine_physics_constraint_gravity_timeline spine_timeline_as_physics_constraint_gravity_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(PhysicsConstraintGravityTimeline::rtti)) return nullptr;
    return (spine_physics_constraint_gravity_timeline) obj;
}

spine_physics_constraint_mix_timeline spine_timeline_as_physics_constraint_mix_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(PhysicsConstraintMixTimeline::rtti)) return nullptr;
    return (spine_physics_constraint_mix_timeline) obj;
}

spine_scale_timeline spine_timeline_as_scale_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(ScaleTimeline::rtti)) return nullptr;
    return (spine_scale_timeline) obj;
}

spine_shear_timeline spine_timeline_as_shear_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(ShearTimeline::rtti)) return nullptr;
    return (spine_shear_timeline) obj;
}

spine_translate_timeline spine_timeline_as_translate_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(TranslateTimeline::rtti)) return nullptr;
    return (spine_translate_timeline) obj;
}

spine_ik_constraint_timeline spine_timeline_as_ik_constraint_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(IkConstraintTimeline::rtti)) return nullptr;
    return (spine_ik_constraint_timeline) obj;
}

spine_path_constraint_mix_timeline spine_timeline_as_path_constraint_mix_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(PathConstraintMixTimeline::rtti)) return nullptr;
    return (spine_path_constraint_mix_timeline) obj;
}

spine_rgba_timeline spine_timeline_as_rgba_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(RGBATimeline::rtti)) return nullptr;
    return (spine_rgba_timeline) obj;
}

spine_rgb_timeline spine_timeline_as_rgb_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(RGBTimeline::rtti)) return nullptr;
    return (spine_rgb_timeline) obj;
}

spine_rgba2_timeline spine_timeline_as_rgba2_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(RGBA2Timeline::rtti)) return nullptr;
    return (spine_rgba2_timeline) obj;
}

spine_rgb2_timeline spine_timeline_as_rgb2_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(RGB2Timeline::rtti)) return nullptr;
    return (spine_rgb2_timeline) obj;
}

spine_deform_timeline spine_timeline_as_deform_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(DeformTimeline::rtti)) return nullptr;
    return (spine_deform_timeline) obj;
}

spine_transform_constraint_timeline spine_timeline_as_transform_constraint_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(TransformConstraintTimeline::rtti)) return nullptr;
    return (spine_transform_constraint_timeline) obj;
}

spine_draw_order_timeline spine_timeline_as_draw_order_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(DrawOrderTimeline::rtti)) return nullptr;
    return (spine_draw_order_timeline) obj;
}

spine_event_timeline spine_timeline_as_event_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(EventTimeline::rtti)) return nullptr;
    return (spine_event_timeline) obj;
}

spine_inherit_timeline spine_timeline_as_inherit_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(InheritTimeline::rtti)) return nullptr;
    return (spine_inherit_timeline) obj;
}

spine_physics_constraint_reset_timeline spine_timeline_as_physics_constraint_reset_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(PhysicsConstraintResetTimeline::rtti)) return nullptr;
    return (spine_physics_constraint_reset_timeline) obj;
}

spine_sequence_timeline spine_timeline_as_sequence_timeline(spine_timeline obj) {
    if (!obj) return nullptr;
    Timeline *_obj = (Timeline *) obj;
    if (!_obj->getRTTI().instanceOf(SequenceTimeline::rtti)) return nullptr;
    return (spine_sequence_timeline) obj;
}
