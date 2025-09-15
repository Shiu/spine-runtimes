#ifndef SPINE_SPINE_SKELETON_H
#define SPINE_SPINE_SKELETON_H

#include "../base.h"
#include "types.h"
#include "arrays.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_skeleton spine_skeleton_create(spine_skeleton_data skeletonData);

SPINE_C_API void spine_skeleton_dispose(spine_skeleton self);

/**
 * Caches information about bones and constraints. Must be called if bones,
 * constraints or weighted path attachments are added or removed.
 */
SPINE_C_API void spine_skeleton_update_cache(spine_skeleton self);
SPINE_C_API void spine_skeleton_print_update_cache(spine_skeleton self);
SPINE_C_API void spine_skeleton_constrained(spine_skeleton self, spine_posed object);
SPINE_C_API void spine_skeleton_sort_bone(spine_skeleton self, /*@null*/ spine_bone bone);
SPINE_C_API void spine_skeleton_sort_reset(spine_array_bone bones);
/**
 * Updates the world transform for each bone and applies all constraints.
 *
 * See [World
 * transforms](http://esotericsoftware.com/spine-runtime-skeletons#World-transforms)
 * in the Spine Runtimes Guide.
 */
SPINE_C_API void spine_skeleton_update_world_transform(spine_skeleton self, spine_physics physics);
/**
 * Sets the bones, constraints, and slots to their setup pose values.
 */
SPINE_C_API void spine_skeleton_setup_pose(spine_skeleton self);
/**
 * Sets the bones and constraints to their setup pose values.
 */
SPINE_C_API void spine_skeleton_setup_pose_bones(spine_skeleton self);
SPINE_C_API void spine_skeleton_setup_pose_slots(spine_skeleton self);
SPINE_C_API spine_skeleton_data spine_skeleton_get_data(spine_skeleton self);
SPINE_C_API spine_array_bone spine_skeleton_get_bones(spine_skeleton self);
SPINE_C_API spine_array_update spine_skeleton_get_update_cache(spine_skeleton self);
SPINE_C_API /*@null*/ spine_bone spine_skeleton_get_root_bone(spine_skeleton self);
/**
 *
 * @return May be NULL.
 */
SPINE_C_API /*@null*/ spine_bone spine_skeleton_find_bone(spine_skeleton self, const char *boneName);
SPINE_C_API spine_array_slot spine_skeleton_get_slots(spine_skeleton self);
/**
 *
 * @return May be NULL.
 */
SPINE_C_API /*@null*/ spine_slot spine_skeleton_find_slot(spine_skeleton self, const char *slotName);
SPINE_C_API spine_array_slot spine_skeleton_get_draw_order(spine_skeleton self);
SPINE_C_API /*@null*/ spine_skin spine_skeleton_get_skin(spine_skeleton self);
/**
 * Sets a skin by name (see setSkin).
 */
SPINE_C_API void spine_skeleton_set_skin_1(spine_skeleton self, const char *skinName);
/**
 * Attachments from the new skin are attached if the corresponding attachment
 * from the old skin was attached. If there was no old skin, each slot's setup
 * mode attachment is attached from the new skin. After changing the skin, the
 * visible attachments can be reset to those attached in the setup pose by
 * calling See Skeleton::setSlotsToSetupPose() Also, often
 * AnimationState::apply(Skeleton & ) is called before the next time the
 * skeleton is rendered to allow any attachment keys in the current animation(s)
 * to hide or show attachments from the new skin.
 *
 * @param newSkin May be NULL.
 */
SPINE_C_API void spine_skeleton_set_skin_2(spine_skeleton self, /*@null*/ spine_skin newSkin);
/**
 *
 * @return May be NULL.
 */
SPINE_C_API /*@null*/ spine_attachment spine_skeleton_get_attachment_1(spine_skeleton self, const char *slotName, const char *attachmentName);
/**
 *
 * @return May be NULL.
 */
SPINE_C_API /*@null*/ spine_attachment spine_skeleton_get_attachment_2(spine_skeleton self, int slotIndex, const char *attachmentName);
/**
 *
 * @param attachmentName May be empty.
 */
SPINE_C_API void spine_skeleton_set_attachment(spine_skeleton self, const char *slotName, const char *attachmentName);
SPINE_C_API spine_array_constraint spine_skeleton_get_constraints(spine_skeleton self);
SPINE_C_API spine_array_physics_constraint spine_skeleton_get_physics_constraints(spine_skeleton self);
/**
 * Returns the axis aligned bounding box (AABB) of the region and mesh
 * attachments for the current pose.
 *
 * @param outX The horizontal distance between the skeleton origin and the left side of the AABB.
 * @param outY The vertical distance between the skeleton origin and the bottom side of the AABB.
 * @param outWidth The width of the AABB
 * @param outHeight The height of the AABB.
 */
SPINE_C_API void spine_skeleton_get_bounds_1(spine_skeleton self, float *outX, float *outY, float *outWidth, float *outHeight);
/**
 * Returns the axis aligned bounding box (AABB) of the region and mesh
 * attachments for the current pose.
 *
 * @param outX The horizontal distance between the skeleton origin and the left side of the AABB.
 * @param outY The vertical distance between the skeleton origin and the bottom side of the AABB.
 * @param outWidth The width of the AABB
 * @param outHeight The height of the AABB.
 * @param outVertexBuffer Reference to hold an array of floats. This method will assign it with new floats as needed.
 * @param clipping Pointer to a SkeletonClipping instance or NULL. If a clipper is given, clipping attachments will be taken into account.
 */
SPINE_C_API void spine_skeleton_get_bounds_2(spine_skeleton self, float *outX, float *outY, float *outWidth, float *outHeight,
											 spine_array_float outVertexBuffer, /*@null*/ spine_skeleton_clipping clipping);
SPINE_C_API spine_color spine_skeleton_get_color(spine_skeleton self);
SPINE_C_API void spine_skeleton_set_color_1(spine_skeleton self, spine_color color);
SPINE_C_API void spine_skeleton_set_color_2(spine_skeleton self, float r, float g, float b, float a);
SPINE_C_API float spine_skeleton_get_scale_x(spine_skeleton self);
SPINE_C_API void spine_skeleton_set_scale_x(spine_skeleton self, float inValue);
SPINE_C_API float spine_skeleton_get_scale_y(spine_skeleton self);
SPINE_C_API void spine_skeleton_set_scale_y(spine_skeleton self, float inValue);
SPINE_C_API void spine_skeleton_set_scale(spine_skeleton self, float scaleX, float scaleY);
SPINE_C_API float spine_skeleton_get_x(spine_skeleton self);
SPINE_C_API void spine_skeleton_set_x(spine_skeleton self, float inValue);
SPINE_C_API float spine_skeleton_get_y(spine_skeleton self);
SPINE_C_API void spine_skeleton_set_y(spine_skeleton self, float inValue);
SPINE_C_API void spine_skeleton_set_position(spine_skeleton self, float x, float y);
SPINE_C_API void spine_skeleton_get_position(spine_skeleton self, float *x, float *y);
SPINE_C_API float spine_skeleton_get_wind_x(spine_skeleton self);
SPINE_C_API void spine_skeleton_set_wind_x(spine_skeleton self, float windX);
SPINE_C_API float spine_skeleton_get_wind_y(spine_skeleton self);
SPINE_C_API void spine_skeleton_set_wind_y(spine_skeleton self, float windY);
SPINE_C_API float spine_skeleton_get_gravity_x(spine_skeleton self);
SPINE_C_API void spine_skeleton_set_gravity_x(spine_skeleton self, float gravityX);
SPINE_C_API float spine_skeleton_get_gravity_y(spine_skeleton self);
SPINE_C_API void spine_skeleton_set_gravity_y(spine_skeleton self, float gravityY);
/**
 * Rotates the physics constraint so next {
 */
SPINE_C_API void spine_skeleton_physics_translate(spine_skeleton self, float x, float y);
/**
 * Calls {
 */
SPINE_C_API void spine_skeleton_physics_rotate(spine_skeleton self, float x, float y, float degrees);
SPINE_C_API float spine_skeleton_get_time(spine_skeleton self);
SPINE_C_API void spine_skeleton_set_time(spine_skeleton self, float time);
SPINE_C_API void spine_skeleton_update(spine_skeleton self, float delta);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_SKELETON_H */
