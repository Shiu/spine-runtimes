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

#include "skeleton_bounds.h"
#include <spine/spine.h>

using namespace spine;

spine_skeleton_bounds spine_skeleton_bounds_create(void) {
    SkeletonBounds *obj = new (__FILE__, __LINE__) SkeletonBounds();
    return (spine_skeleton_bounds) obj;
}

void spine_skeleton_bounds_dispose(spine_skeleton_bounds obj) {
    if (!obj) return;
    delete (SkeletonBounds *) obj;
}

void spine_skeleton_bounds_update(spine_skeleton_bounds obj, spine_skeleton skeleton, spine_bool updateAabb) {
    if (!obj) return ;
    SkeletonBounds *_obj = (SkeletonBounds *) obj;
    _obj->update(skeleton, updateAabb);
}

spine_bool spine_skeleton_bounds_aabb_contains_point(spine_skeleton_bounds obj, float x, float y) {
    if (!obj) return 0;
    SkeletonBounds *_obj = (SkeletonBounds *) obj;
    return _obj->aabbContainsPoint(x, y);
}

spine_bool spine_skeleton_bounds_aabb_intersects_segment(spine_skeleton_bounds obj, float x1, float y1, float x2, float y2) {
    if (!obj) return 0;
    SkeletonBounds *_obj = (SkeletonBounds *) obj;
    return _obj->aabbIntersectsSegment(x1, y1, x2, y2);
}

spine_bool spine_skeleton_bounds_aabb_intersects_skeleton(spine_skeleton_bounds obj, spine_skeleton_bounds bounds) {
    if (!obj) return 0;
    SkeletonBounds *_obj = (SkeletonBounds *) obj;
    return _obj->aabbIntersectsSkeleton(bounds);
}

spine_bool spine_skeleton_bounds_contains_point(spine_skeleton_bounds obj, spine_polygon polygon, float x, float y) {
    if (!obj) return 0;
    SkeletonBounds *_obj = (SkeletonBounds *) obj;
    return _obj->containsPoint((Polygon *) polygon, x, y);
}

spine_bounding_box_attachment spine_skeleton_bounds_contains_point(spine_skeleton_bounds obj, float x, float y) {
    if (!obj) return nullptr;
    SkeletonBounds *_obj = (SkeletonBounds *) obj;
    return (spine_bounding_box_attachment) _obj->containsPoint(x, y);
}

spine_bounding_box_attachment spine_skeleton_bounds_intersects_segment(spine_skeleton_bounds obj, float x1, float y1, float x2, float y2) {
    if (!obj) return nullptr;
    SkeletonBounds *_obj = (SkeletonBounds *) obj;
    return (spine_bounding_box_attachment) _obj->intersectsSegment(x1, y1, x2, y2);
}

spine_bool spine_skeleton_bounds_intersects_segment(spine_skeleton_bounds obj, spine_polygon polygon, float x1, float y1, float x2, float y2) {
    if (!obj) return 0;
    SkeletonBounds *_obj = (SkeletonBounds *) obj;
    return _obj->intersectsSegment((Polygon *) polygon, x1, y1, x2, y2);
}

spine_polygon spine_skeleton_bounds_get_polygon(spine_skeleton_bounds obj, spine_bounding_box_attachment attachment) {
    if (!obj) return nullptr;
    SkeletonBounds *_obj = (SkeletonBounds *) obj;
    return (spine_polygon) _obj->getPolygon((BoundingBoxAttachment *) attachment);
}

spine_bounding_box_attachment spine_skeleton_bounds_get_bounding_box(spine_skeleton_bounds obj, spine_polygon polygon) {
    if (!obj) return nullptr;
    SkeletonBounds *_obj = (SkeletonBounds *) obj;
    return (spine_bounding_box_attachment) _obj->getBoundingBox((Polygon *) polygon);
}

void * spine_skeleton_bounds_get_polygons(spine_skeleton_bounds obj) {
    if (!obj) return nullptr;
    SkeletonBounds *_obj = (SkeletonBounds *) obj;
    return (void *) _obj->getPolygons();
}

int32_t spine_skeleton_bounds_get_num_polygons(spine_skeleton_bounds obj) {
    if (!obj) return 0;
    SkeletonBounds *_obj = (SkeletonBounds *) obj;
    return (int32_t) _obj->getPolygons().size();
}

spine_polygon *spine_skeleton_bounds_get_polygons(spine_skeleton_bounds obj) {
    if (!obj) return nullptr;
    SkeletonBounds *_obj = (SkeletonBounds *) obj;
    return (spine_polygon *) _obj->getPolygons().buffer();
}

void * spine_skeleton_bounds_get_bounding_boxes(spine_skeleton_bounds obj) {
    if (!obj) return nullptr;
    SkeletonBounds *_obj = (SkeletonBounds *) obj;
    return (void *) _obj->getBoundingBoxes();
}

int32_t spine_skeleton_bounds_get_num_bounding_boxes(spine_skeleton_bounds obj) {
    if (!obj) return 0;
    SkeletonBounds *_obj = (SkeletonBounds *) obj;
    return (int32_t) _obj->getBoundingBoxes().size();
}

spine_bounding_box_attachment *spine_skeleton_bounds_get_bounding_boxes(spine_skeleton_bounds obj) {
    if (!obj) return nullptr;
    SkeletonBounds *_obj = (SkeletonBounds *) obj;
    return (spine_bounding_box_attachment *) _obj->getBoundingBoxes().buffer();
}

float spine_skeleton_bounds_get_min_x(spine_skeleton_bounds obj) {
    if (!obj) return 0;
    SkeletonBounds *_obj = (SkeletonBounds *) obj;
    return _obj->getMinX();
}

float spine_skeleton_bounds_get_min_y(spine_skeleton_bounds obj) {
    if (!obj) return 0;
    SkeletonBounds *_obj = (SkeletonBounds *) obj;
    return _obj->getMinY();
}

float spine_skeleton_bounds_get_max_x(spine_skeleton_bounds obj) {
    if (!obj) return 0;
    SkeletonBounds *_obj = (SkeletonBounds *) obj;
    return _obj->getMaxX();
}

float spine_skeleton_bounds_get_max_y(spine_skeleton_bounds obj) {
    if (!obj) return 0;
    SkeletonBounds *_obj = (SkeletonBounds *) obj;
    return _obj->getMaxY();
}

float spine_skeleton_bounds_get_width(spine_skeleton_bounds obj) {
    if (!obj) return 0;
    SkeletonBounds *_obj = (SkeletonBounds *) obj;
    return _obj->getWidth();
}

float spine_skeleton_bounds_get_height(spine_skeleton_bounds obj) {
    if (!obj) return 0;
    SkeletonBounds *_obj = (SkeletonBounds *) obj;
    return _obj->getHeight();
}
