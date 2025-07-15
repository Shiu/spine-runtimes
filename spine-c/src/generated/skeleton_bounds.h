#ifndef SPINE_SPINE_SKELETON_BOUNDS_H
#define SPINE_SPINE_SKELETON_BOUNDS_H

#include "../base.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

SPINE_C_API spine_skeleton_bounds spine_skeleton_bounds_create(void);

SPINE_C_API void spine_skeleton_bounds_dispose(spine_skeleton_bounds self);

SPINE_C_API void spine_skeleton_bounds_update(spine_skeleton_bounds self, spine_skeleton skeleton, bool updateAabb);
SPINE_C_API bool spine_skeleton_bounds_aabb_contains_point(spine_skeleton_bounds self, float x, float y);
SPINE_C_API bool spine_skeleton_bounds_aabb_intersects_segment(spine_skeleton_bounds self, float x1, float y1, float x2, float y2);
SPINE_C_API bool spine_skeleton_bounds_aabb_intersects_skeleton(spine_skeleton_bounds self, spine_skeleton_bounds bounds);
SPINE_C_API bool spine_skeleton_bounds_contains_point_1(spine_skeleton_bounds self, spine_polygon polygon, float x, float y);
SPINE_C_API spine_bounding_box_attachment spine_skeleton_bounds_contains_point_2(spine_skeleton_bounds self, float x, float y);
SPINE_C_API spine_bounding_box_attachment spine_skeleton_bounds_intersects_segment_1(spine_skeleton_bounds self, float x1, float y1, float x2,
																					 float y2);
SPINE_C_API bool spine_skeleton_bounds_intersects_segment_2(spine_skeleton_bounds self, spine_polygon polygon, float x1, float y1, float x2,
															float y2);
SPINE_C_API spine_polygon spine_skeleton_bounds_get_polygon(spine_skeleton_bounds self, spine_bounding_box_attachment attachment);
SPINE_C_API spine_bounding_box_attachment spine_skeleton_bounds_get_bounding_box(spine_skeleton_bounds self, spine_polygon polygon);
SPINE_C_API spine_array_polygon spine_skeleton_bounds_get_polygons(spine_skeleton_bounds self);
SPINE_C_API spine_array_bounding_box_attachment spine_skeleton_bounds_get_bounding_boxes(spine_skeleton_bounds self);
SPINE_C_API float spine_skeleton_bounds_get_min_x(spine_skeleton_bounds self);
SPINE_C_API float spine_skeleton_bounds_get_min_y(spine_skeleton_bounds self);
SPINE_C_API float spine_skeleton_bounds_get_max_x(spine_skeleton_bounds self);
SPINE_C_API float spine_skeleton_bounds_get_max_y(spine_skeleton_bounds self);
SPINE_C_API float spine_skeleton_bounds_get_width(spine_skeleton_bounds self);
SPINE_C_API float spine_skeleton_bounds_get_height(spine_skeleton_bounds self);

#ifdef __cplusplus
}
#endif

#endif /* SPINE_SPINE_SKELETON_BOUNDS_H */
