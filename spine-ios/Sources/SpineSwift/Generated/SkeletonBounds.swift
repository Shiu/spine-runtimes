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

import Foundation
import SpineC

@objc(SpineSkeletonBounds)
@objcMembers
public final class SkeletonBounds: NSObject {
    internal let wrappee: spine_skeleton_bounds

    internal init(_ wrappee: spine_skeleton_bounds) {
        self.wrappee = wrappee
        super.init()
    }

    public override func isEqual(_ object: Any?) -> Bool {
        guard let other = object as? SkeletonBounds else { return false }
        return self.wrappee == other.wrappee
    }

    public override var hash: Int {
        var hasher = Hasher()
        hasher.combine(self.wrappee)
        return hasher.finalize()
    }

    public convenience init() {
        let ptr = spine_skeleton_bounds_create()
        self.init(ptr)
    }

    public func update(skeleton: Skeleton, updateAabb: Bool) {
        spine_skeleton_bounds_update(wrappee, skeleton.wrappee, updateAabb ? 1 : 0)
    }

    public func aabbContainsPoint(x: Float, y: Float) -> Bool {
        return spine_skeleton_bounds_aabb_contains_point(wrappee, x, y) != 0
    }

    public func aabbIntersectsSegment(x1: Float, y1: Float, x2: Float, y2: Float) -> Bool {
        return spine_skeleton_bounds_aabb_intersects_segment(wrappee, x1, y1, x2, y2) != 0
    }

    public func aabbIntersectsSkeleton(bounds: SkeletonBounds) -> Bool {
        return spine_skeleton_bounds_aabb_intersects_skeleton(wrappee, bounds.wrappee) != 0
    }

    public func containsPoint(polygon: Polygon, x: Float, y: Float) -> Bool {
        return spine_skeleton_bounds_contains_point_1(wrappee, polygon.wrappee, x, y) != 0
    }

    public func containsPoint(x: Float, y: Float) -> BoundingBoxAttachment {
        let result = spine_skeleton_bounds_contains_point_2(wrappee, x, y)
        return BoundingBoxAttachment(result)
    }

    public func intersectsSegment(x1: Float, y1: Float, x2: Float, y2: Float) -> BoundingBoxAttachment {
        let result = spine_skeleton_bounds_intersects_segment_1(wrappee, x1, y1, x2, y2)
        return BoundingBoxAttachment(result)
    }

    public func intersectsSegment(polygon: Polygon, x1: Float, y1: Float, x2: Float, y2: Float) -> Bool {
        return spine_skeleton_bounds_intersects_segment_2(wrappee, polygon.wrappee, x1, y1, x2, y2) != 0
    }

    public func getPolygon(attachment: BoundingBoxAttachment) -> Polygon {
        let result = spine_skeleton_bounds_get_polygon(wrappee, attachment.wrappee)
        return Polygon(result)
    }

    public func getBoundingBox(polygon: Polygon) -> BoundingBoxAttachment {
        let result = spine_skeleton_bounds_get_bounding_box(wrappee, polygon.wrappee)
        return BoundingBoxAttachment(result)
    }

    public func getPolygons() -> ArrayPolygon {
        return spine_skeleton_bounds_get_polygons(wrappee)
    }

    public func getBoundingBoxes() -> ArrayBoundingBoxAttachment {
        return spine_skeleton_bounds_get_bounding_boxes(wrappee)
    }

    public func getMinX() -> Float {
        return spine_skeleton_bounds_get_min_x(wrappee)
    }

    public func getMinY() -> Float {
        return spine_skeleton_bounds_get_min_y(wrappee)
    }

    public func getMaxX() -> Float {
        return spine_skeleton_bounds_get_max_x(wrappee)
    }

    public func getMaxY() -> Float {
        return spine_skeleton_bounds_get_max_y(wrappee)
    }

    public func getWidth() -> Float {
        return spine_skeleton_bounds_get_width(wrappee)
    }

    public func getHeight() -> Float {
        return spine_skeleton_bounds_get_height(wrappee)
    }

    deinit {
        spine_skeleton_bounds_dispose(wrappee)
    }
}