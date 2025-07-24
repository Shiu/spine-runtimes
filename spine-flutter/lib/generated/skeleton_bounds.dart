//
// Spine Runtimes License Agreement
// Last updated April 5, 2025. Replaces all prior versions.
//
// Copyright (c) 2013-2025, Esoteric Software LLC
//
// Integration of the Spine Runtimes into software or otherwise creating
// derivative works of the Spine Runtimes is permitted under the terms and
// conditions of Section 2 of the Spine Editor License Agreement:
// http://esotericsoftware.com/spine-editor-license
//
// Otherwise, it is permitted to integrate the Spine Runtimes into software
// or otherwise create derivative works of the Spine Runtimes (collectively,
// "Products"), provided that each user of the Products must obtain their own
// Spine Editor license and redistribution of the Products in any form must
// include this license and copyright notice.
//
// THE SPINE RUNTIMES ARE PROVIDED BY ESOTERIC SOFTWARE LLC "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL ESOTERIC SOFTWARE LLC BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES,
// BUSINESS INTERRUPTION, OR LOSS OF USE, DATA, OR PROFITS) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THE SPINE RUNTIMES, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

// AUTO GENERATED FILE, DO NOT EDIT.

import 'dart:ffi';
import 'spine_dart_bindings_generated.dart';
import '../spine_bindings.dart';
import 'arrays.dart';
import 'bounding_box_attachment.dart';
import 'polygon.dart';
import 'skeleton.dart';

/// SkeletonBounds wrapper
class SkeletonBounds {
  final Pointer<spine_skeleton_bounds_wrapper> _ptr;

  SkeletonBounds.fromPointer(this._ptr);

  /// Get the native pointer for FFI calls
  Pointer get nativePtr => _ptr;

  factory SkeletonBounds() {
    final ptr = SpineBindings.bindings.spine_skeleton_bounds_create();
    return SkeletonBounds.fromPointer(ptr);
  }

  void dispose() {
    SpineBindings.bindings.spine_skeleton_bounds_dispose(_ptr);
  }

  void update(Skeleton skeleton, bool updateAabb) {
    SpineBindings.bindings.spine_skeleton_bounds_update(_ptr, skeleton.nativePtr.cast(), updateAabb);
  }

  bool aabbContainsPoint(double x, double y) {
    final result = SpineBindings.bindings.spine_skeleton_bounds_aabb_contains_point(_ptr, x, y);
    return result;
  }

  bool aabbIntersectsSegment(double x1, double y1, double x2, double y2) {
    final result = SpineBindings.bindings.spine_skeleton_bounds_aabb_intersects_segment(_ptr, x1, y1, x2, y2);
    return result;
  }

  bool aabbIntersectsSkeleton(SkeletonBounds bounds) {
    final result = SpineBindings.bindings.spine_skeleton_bounds_aabb_intersects_skeleton(_ptr, bounds.nativePtr.cast());
    return result;
  }

  Polygon getPolygon(BoundingBoxAttachment attachment) {
    final result = SpineBindings.bindings.spine_skeleton_bounds_get_polygon(_ptr, attachment.nativePtr.cast());
    return Polygon.fromPointer(result);
  }

  BoundingBoxAttachment getBoundingBox(Polygon polygon) {
    final result = SpineBindings.bindings.spine_skeleton_bounds_get_bounding_box(_ptr, polygon.nativePtr.cast());
    return BoundingBoxAttachment.fromPointer(result);
  }

  ArrayPolygon get polygons {
    final result = SpineBindings.bindings.spine_skeleton_bounds_get_polygons(_ptr);
    return ArrayPolygon.fromPointer(result);
  }

  ArrayBoundingBoxAttachment get boundingBoxes {
    final result = SpineBindings.bindings.spine_skeleton_bounds_get_bounding_boxes(_ptr);
    return ArrayBoundingBoxAttachment.fromPointer(result);
  }

  double get minX {
    final result = SpineBindings.bindings.spine_skeleton_bounds_get_min_x(_ptr);
    return result;
  }

  double get minY {
    final result = SpineBindings.bindings.spine_skeleton_bounds_get_min_y(_ptr);
    return result;
  }

  double get maxX {
    final result = SpineBindings.bindings.spine_skeleton_bounds_get_max_x(_ptr);
    return result;
  }

  double get maxY {
    final result = SpineBindings.bindings.spine_skeleton_bounds_get_max_y(_ptr);
    return result;
  }

  double get width {
    final result = SpineBindings.bindings.spine_skeleton_bounds_get_width(_ptr);
    return result;
  }

  double get height {
    final result = SpineBindings.bindings.spine_skeleton_bounds_get_height(_ptr);
    return result;
  }

  bool containsPoint(Polygon polygon, double x, double y) {
    final result = SpineBindings.bindings.spine_skeleton_bounds_contains_point_1(_ptr, polygon.nativePtr.cast(), x, y);
    return result;
  }

  BoundingBoxAttachment containsPoint2(double x, double y) {
    final result = SpineBindings.bindings.spine_skeleton_bounds_contains_point_2(_ptr, x, y);
    return BoundingBoxAttachment.fromPointer(result);
  }

  BoundingBoxAttachment intersectsSegment(double x1, double y1, double x2, double y2) {
    final result = SpineBindings.bindings.spine_skeleton_bounds_intersects_segment_1(_ptr, x1, y1, x2, y2);
    return BoundingBoxAttachment.fromPointer(result);
  }

  bool intersectsSegment2(Polygon polygon, double x1, double y1, double x2, double y2) {
    final result = SpineBindings.bindings
        .spine_skeleton_bounds_intersects_segment_2(_ptr, polygon.nativePtr.cast(), x1, y1, x2, y2);
    return result;
  }
}
