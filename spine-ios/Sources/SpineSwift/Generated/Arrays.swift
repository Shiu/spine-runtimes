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

import Foundation
import SpineC

/// ArrayFloat wrapper
public class ArrayFloat {
    public let _ptr: UnsafeMutableRawPointer
    private let _ownsMemory: Bool

    public init(fromPointer ptr: spine_array_float, ownsMemory: Bool = false) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        self._ownsMemory = ownsMemory
    }


    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_float_create()!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int) {
        let ptr = spine_array_float_create_with_capacity(capacity)!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var count: Int {
        return Int(spine_array_float_size(_ptr.assumingMemoryBound(to: spine_array_float_wrapper.self)))
    }

    public subscript(index: Int) -> Float {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_float_buffer(_ptr.assumingMemoryBound(to: spine_array_float_wrapper.self))!
            return buffer[Int(index)]
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: Float) {
        spine_array_float_add(_ptr.assumingMemoryBound(to: spine_array_float_wrapper.self), value)
    }

    /// Removes all elements from this array
    public func clear() {
        spine_array_float_clear(_ptr.assumingMemoryBound(to: spine_array_float_wrapper.self))
    }

    /// Removes the element at the given index
    @discardableResult
    public func removeAt(_ index: Int) -> Float {
        precondition(index >= 0 && index < count, "Index out of bounds")
        let value = self[index]
        spine_array_float_remove_at(_ptr.assumingMemoryBound(to: spine_array_float_wrapper.self), index)
        return value
    }

    /// Sets the size of this array
    public var length: Int {
        get { count }
        set {
            spine_array_float_set_size(_ptr.assumingMemoryBound(to: spine_array_float_wrapper.self), newValue, 0.0)
        }
    }

    /// Ensures this array has at least the given capacity
    public func ensureCapacity(_ capacity: Int) {
        spine_array_float_ensure_capacity(_ptr.assumingMemoryBound(to: spine_array_float_wrapper.self), capacity)
    }

    deinit {
        if _ownsMemory {
            spine_array_float_dispose(_ptr.assumingMemoryBound(to: spine_array_float_wrapper.self))
        }
    }
}

/// ArrayInt wrapper
public class ArrayInt {
    public let _ptr: UnsafeMutableRawPointer
    private let _ownsMemory: Bool

    public init(fromPointer ptr: spine_array_int, ownsMemory: Bool = false) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        self._ownsMemory = ownsMemory
    }


    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_int_create()!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int) {
        let ptr = spine_array_int_create_with_capacity(capacity)!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var count: Int {
        return Int(spine_array_int_size(_ptr.assumingMemoryBound(to: spine_array_int_wrapper.self)))
    }

    public subscript(index: Int) -> Int32 {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_int_buffer(_ptr.assumingMemoryBound(to: spine_array_int_wrapper.self))!
            return buffer[Int(index)]
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: Int32) {
        spine_array_int_add(_ptr.assumingMemoryBound(to: spine_array_int_wrapper.self), value)
    }

    /// Removes all elements from this array
    public func clear() {
        spine_array_int_clear(_ptr.assumingMemoryBound(to: spine_array_int_wrapper.self))
    }

    /// Removes the element at the given index
    @discardableResult
    public func removeAt(_ index: Int) -> Int32 {
        precondition(index >= 0 && index < count, "Index out of bounds")
        let value = self[index]
        spine_array_int_remove_at(_ptr.assumingMemoryBound(to: spine_array_int_wrapper.self), index)
        return value
    }

    /// Sets the size of this array
    public var length: Int {
        get { count }
        set {
            spine_array_int_set_size(_ptr.assumingMemoryBound(to: spine_array_int_wrapper.self), newValue, 0)
        }
    }

    /// Ensures this array has at least the given capacity
    public func ensureCapacity(_ capacity: Int) {
        spine_array_int_ensure_capacity(_ptr.assumingMemoryBound(to: spine_array_int_wrapper.self), capacity)
    }

    deinit {
        if _ownsMemory {
            spine_array_int_dispose(_ptr.assumingMemoryBound(to: spine_array_int_wrapper.self))
        }
    }
}

/// ArrayUnsignedShort wrapper
public class ArrayUnsignedShort {
    public let _ptr: UnsafeMutableRawPointer
    private let _ownsMemory: Bool

    public init(fromPointer ptr: spine_array_unsigned_short, ownsMemory: Bool = false) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        self._ownsMemory = ownsMemory
    }


    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_unsigned_short_create()!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int) {
        let ptr = spine_array_unsigned_short_create_with_capacity(capacity)!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var count: Int {
        return Int(spine_array_unsigned_short_size(_ptr.assumingMemoryBound(to: spine_array_unsigned_short_wrapper.self)))
    }

    public subscript(index: Int) -> UInt16 {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_unsigned_short_buffer(_ptr.assumingMemoryBound(to: spine_array_unsigned_short_wrapper.self))!
            return buffer[Int(index)]
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: UInt16) {
        spine_array_unsigned_short_add(_ptr.assumingMemoryBound(to: spine_array_unsigned_short_wrapper.self), value)
    }

    /// Removes all elements from this array
    public func clear() {
        spine_array_unsigned_short_clear(_ptr.assumingMemoryBound(to: spine_array_unsigned_short_wrapper.self))
    }

    /// Removes the element at the given index
    @discardableResult
    public func removeAt(_ index: Int) -> UInt16 {
        precondition(index >= 0 && index < count, "Index out of bounds")
        let value = self[index]
        spine_array_unsigned_short_remove_at(_ptr.assumingMemoryBound(to: spine_array_unsigned_short_wrapper.self), index)
        return value
    }

    /// Sets the size of this array
    public var length: Int {
        get { count }
        set {
            spine_array_unsigned_short_set_size(_ptr.assumingMemoryBound(to: spine_array_unsigned_short_wrapper.self), newValue, 0)
        }
    }

    /// Ensures this array has at least the given capacity
    public func ensureCapacity(_ capacity: Int) {
        spine_array_unsigned_short_ensure_capacity(_ptr.assumingMemoryBound(to: spine_array_unsigned_short_wrapper.self), capacity)
    }

    deinit {
        if _ownsMemory {
            spine_array_unsigned_short_dispose(_ptr.assumingMemoryBound(to: spine_array_unsigned_short_wrapper.self))
        }
    }
}

/// ArrayPropertyId wrapper
public class ArrayPropertyId {
    public let _ptr: UnsafeMutableRawPointer
    private let _ownsMemory: Bool

    public init(fromPointer ptr: spine_array_property_id, ownsMemory: Bool = false) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        self._ownsMemory = ownsMemory
    }


    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_property_id_create()!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int) {
        let ptr = spine_array_property_id_create_with_capacity(capacity)!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var count: Int {
        return Int(spine_array_property_id_size(_ptr.assumingMemoryBound(to: spine_array_property_id_wrapper.self)))
    }

    public subscript(index: Int) -> Int64 {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_property_id_buffer(_ptr.assumingMemoryBound(to: spine_array_property_id_wrapper.self))!
            return buffer[Int(index)]
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: Int64) {
        spine_array_property_id_add(_ptr.assumingMemoryBound(to: spine_array_property_id_wrapper.self), value)
    }

    /// Removes all elements from this array
    public func clear() {
        spine_array_property_id_clear(_ptr.assumingMemoryBound(to: spine_array_property_id_wrapper.self))
    }

    /// Removes the element at the given index
    @discardableResult
    public func removeAt(_ index: Int) -> Int64 {
        precondition(index >= 0 && index < count, "Index out of bounds")
        let value = self[index]
        spine_array_property_id_remove_at(_ptr.assumingMemoryBound(to: spine_array_property_id_wrapper.self), index)
        return value
    }

    /// Sets the size of this array
    public var length: Int {
        get { count }
        set {
            spine_array_property_id_set_size(_ptr.assumingMemoryBound(to: spine_array_property_id_wrapper.self), newValue, 0)
        }
    }

    /// Ensures this array has at least the given capacity
    public func ensureCapacity(_ capacity: Int) {
        spine_array_property_id_ensure_capacity(_ptr.assumingMemoryBound(to: spine_array_property_id_wrapper.self), capacity)
    }

    deinit {
        if _ownsMemory {
            spine_array_property_id_dispose(_ptr.assumingMemoryBound(to: spine_array_property_id_wrapper.self))
        }
    }
}

/// ArrayAnimation wrapper
public class ArrayAnimation {
    public let _ptr: UnsafeMutableRawPointer
    private let _ownsMemory: Bool

    public init(fromPointer ptr: spine_array_animation, ownsMemory: Bool = false) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        self._ownsMemory = ownsMemory
    }


    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_animation_create()!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int) {
        let ptr = spine_array_animation_create_with_capacity(capacity)!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var count: Int {
        return Int(spine_array_animation_size(_ptr.assumingMemoryBound(to: spine_array_animation_wrapper.self)))
    }

    public subscript(index: Int) -> Animation? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_animation_buffer(_ptr.assumingMemoryBound(to: spine_array_animation_wrapper.self))!
            let elementPtr = buffer[Int(index)]
            return elementPtr.map { Animation(fromPointer: $0) }
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: Animation?) {
        spine_array_animation_add(_ptr.assumingMemoryBound(to: spine_array_animation_wrapper.self), value?._ptr.assumingMemoryBound(to: spine_animation_wrapper.self))
    }

    /// Removes all elements from this array
    public func clear() {
        spine_array_animation_clear(_ptr.assumingMemoryBound(to: spine_array_animation_wrapper.self))
    }

    /// Removes the element at the given index
    @discardableResult
    public func removeAt(_ index: Int) -> Animation? {
        precondition(index >= 0 && index < count, "Index out of bounds")
        let value = self[index]
        spine_array_animation_remove_at(_ptr.assumingMemoryBound(to: spine_array_animation_wrapper.self), index)
        return value
    }

    /// Sets the size of this array
    public var length: Int {
        get { count }
        set {
            spine_array_animation_set_size(_ptr.assumingMemoryBound(to: spine_array_animation_wrapper.self), newValue, nil)
        }
    }

    /// Ensures this array has at least the given capacity
    public func ensureCapacity(_ capacity: Int) {
        spine_array_animation_ensure_capacity(_ptr.assumingMemoryBound(to: spine_array_animation_wrapper.self), capacity)
    }

    deinit {
        if _ownsMemory {
            spine_array_animation_dispose(_ptr.assumingMemoryBound(to: spine_array_animation_wrapper.self))
        }
    }
}

/// ArrayAtlasPage wrapper
public class ArrayAtlasPage {
    public let _ptr: UnsafeMutableRawPointer
    private let _ownsMemory: Bool

    public init(fromPointer ptr: spine_array_atlas_page, ownsMemory: Bool = false) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        self._ownsMemory = ownsMemory
    }


    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_atlas_page_create()!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int) {
        let ptr = spine_array_atlas_page_create_with_capacity(capacity)!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var count: Int {
        return Int(spine_array_atlas_page_size(_ptr.assumingMemoryBound(to: spine_array_atlas_page_wrapper.self)))
    }

    public subscript(index: Int) -> AtlasPage? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_atlas_page_buffer(_ptr.assumingMemoryBound(to: spine_array_atlas_page_wrapper.self))!
            let elementPtr = buffer[Int(index)]
            return elementPtr.map { AtlasPage(fromPointer: $0) }
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: AtlasPage?) {
        spine_array_atlas_page_add(_ptr.assumingMemoryBound(to: spine_array_atlas_page_wrapper.self), value?._ptr.assumingMemoryBound(to: spine_atlas_page_wrapper.self))
    }

    /// Removes all elements from this array
    public func clear() {
        spine_array_atlas_page_clear(_ptr.assumingMemoryBound(to: spine_array_atlas_page_wrapper.self))
    }

    /// Removes the element at the given index
    @discardableResult
    public func removeAt(_ index: Int) -> AtlasPage? {
        precondition(index >= 0 && index < count, "Index out of bounds")
        let value = self[index]
        spine_array_atlas_page_remove_at(_ptr.assumingMemoryBound(to: spine_array_atlas_page_wrapper.self), index)
        return value
    }

    /// Sets the size of this array
    public var length: Int {
        get { count }
        set {
            spine_array_atlas_page_set_size(_ptr.assumingMemoryBound(to: spine_array_atlas_page_wrapper.self), newValue, nil)
        }
    }

    /// Ensures this array has at least the given capacity
    public func ensureCapacity(_ capacity: Int) {
        spine_array_atlas_page_ensure_capacity(_ptr.assumingMemoryBound(to: spine_array_atlas_page_wrapper.self), capacity)
    }

    deinit {
        if _ownsMemory {
            spine_array_atlas_page_dispose(_ptr.assumingMemoryBound(to: spine_array_atlas_page_wrapper.self))
        }
    }
}

/// ArrayAtlasRegion wrapper
public class ArrayAtlasRegion {
    public let _ptr: UnsafeMutableRawPointer
    private let _ownsMemory: Bool

    public init(fromPointer ptr: spine_array_atlas_region, ownsMemory: Bool = false) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        self._ownsMemory = ownsMemory
    }


    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_atlas_region_create()!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int) {
        let ptr = spine_array_atlas_region_create_with_capacity(capacity)!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var count: Int {
        return Int(spine_array_atlas_region_size(_ptr.assumingMemoryBound(to: spine_array_atlas_region_wrapper.self)))
    }

    public subscript(index: Int) -> AtlasRegion? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_atlas_region_buffer(_ptr.assumingMemoryBound(to: spine_array_atlas_region_wrapper.self))!
            let elementPtr = buffer[Int(index)]
            return elementPtr.map { AtlasRegion(fromPointer: $0) }
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: AtlasRegion?) {
        spine_array_atlas_region_add(_ptr.assumingMemoryBound(to: spine_array_atlas_region_wrapper.self), value?._ptr.assumingMemoryBound(to: spine_atlas_region_wrapper.self))
    }

    /// Removes all elements from this array
    public func clear() {
        spine_array_atlas_region_clear(_ptr.assumingMemoryBound(to: spine_array_atlas_region_wrapper.self))
    }

    /// Removes the element at the given index
    @discardableResult
    public func removeAt(_ index: Int) -> AtlasRegion? {
        precondition(index >= 0 && index < count, "Index out of bounds")
        let value = self[index]
        spine_array_atlas_region_remove_at(_ptr.assumingMemoryBound(to: spine_array_atlas_region_wrapper.self), index)
        return value
    }

    /// Sets the size of this array
    public var length: Int {
        get { count }
        set {
            spine_array_atlas_region_set_size(_ptr.assumingMemoryBound(to: spine_array_atlas_region_wrapper.self), newValue, nil)
        }
    }

    /// Ensures this array has at least the given capacity
    public func ensureCapacity(_ capacity: Int) {
        spine_array_atlas_region_ensure_capacity(_ptr.assumingMemoryBound(to: spine_array_atlas_region_wrapper.self), capacity)
    }

    deinit {
        if _ownsMemory {
            spine_array_atlas_region_dispose(_ptr.assumingMemoryBound(to: spine_array_atlas_region_wrapper.self))
        }
    }
}

/// ArrayAttachment wrapper
public class ArrayAttachment {
    public let _ptr: UnsafeMutableRawPointer
    private let _ownsMemory: Bool

    public init(fromPointer ptr: spine_array_attachment, ownsMemory: Bool = false) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        self._ownsMemory = ownsMemory
    }


    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_attachment_create()!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int) {
        let ptr = spine_array_attachment_create_with_capacity(capacity)!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var count: Int {
        return Int(spine_array_attachment_size(_ptr.assumingMemoryBound(to: spine_array_attachment_wrapper.self)))
    }

    public subscript(index: Int) -> Attachment? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_attachment_buffer(_ptr.assumingMemoryBound(to: spine_array_attachment_wrapper.self))!
            let elementPtr = buffer[Int(index)]
            guard let ptr = elementPtr else { return nil }
            let rtti = spine_attachment_get_rtti(ptr)
        let className = String(cString: spine_rtti_get_class_name(rtti)!)
        switch className {
        case "spine_bounding_box_attachment":
            return BoundingBoxAttachment(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_bounding_box_attachment_wrapper.self))
        case "spine_clipping_attachment":
            return ClippingAttachment(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_clipping_attachment_wrapper.self))
        case "spine_mesh_attachment":
            return MeshAttachment(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_mesh_attachment_wrapper.self))
        case "spine_path_attachment":
            return PathAttachment(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_path_attachment_wrapper.self))
        case "spine_point_attachment":
            return PointAttachment(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_point_attachment_wrapper.self))
        case "spine_region_attachment":
            return RegionAttachment(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_region_attachment_wrapper.self))
        default:
            fatalError("Unknown concrete type: \(className) for abstract class Attachment")
        }
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: Attachment?) {
        spine_array_attachment_add(_ptr.assumingMemoryBound(to: spine_array_attachment_wrapper.self), value?._ptr.assumingMemoryBound(to: spine_attachment_wrapper.self))
    }

    /// Removes all elements from this array
    public func clear() {
        spine_array_attachment_clear(_ptr.assumingMemoryBound(to: spine_array_attachment_wrapper.self))
    }

    /// Removes the element at the given index
    @discardableResult
    public func removeAt(_ index: Int) -> Attachment? {
        precondition(index >= 0 && index < count, "Index out of bounds")
        let value = self[index]
        spine_array_attachment_remove_at(_ptr.assumingMemoryBound(to: spine_array_attachment_wrapper.self), index)
        return value
    }

    /// Sets the size of this array
    public var length: Int {
        get { count }
        set {
            spine_array_attachment_set_size(_ptr.assumingMemoryBound(to: spine_array_attachment_wrapper.self), newValue, nil)
        }
    }

    /// Ensures this array has at least the given capacity
    public func ensureCapacity(_ capacity: Int) {
        spine_array_attachment_ensure_capacity(_ptr.assumingMemoryBound(to: spine_array_attachment_wrapper.self), capacity)
    }

    deinit {
        if _ownsMemory {
            spine_array_attachment_dispose(_ptr.assumingMemoryBound(to: spine_array_attachment_wrapper.self))
        }
    }
}

/// ArrayBone wrapper
public class ArrayBone {
    public let _ptr: UnsafeMutableRawPointer
    private let _ownsMemory: Bool

    public init(fromPointer ptr: spine_array_bone, ownsMemory: Bool = false) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        self._ownsMemory = ownsMemory
    }


    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_bone_create()!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int) {
        let ptr = spine_array_bone_create_with_capacity(capacity)!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var count: Int {
        return Int(spine_array_bone_size(_ptr.assumingMemoryBound(to: spine_array_bone_wrapper.self)))
    }

    public subscript(index: Int) -> Bone? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_bone_buffer(_ptr.assumingMemoryBound(to: spine_array_bone_wrapper.self))!
            let elementPtr = buffer[Int(index)]
            return elementPtr.map { Bone(fromPointer: $0) }
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: Bone?) {
        spine_array_bone_add(_ptr.assumingMemoryBound(to: spine_array_bone_wrapper.self), value?._ptr.assumingMemoryBound(to: spine_bone_wrapper.self))
    }

    /// Removes all elements from this array
    public func clear() {
        spine_array_bone_clear(_ptr.assumingMemoryBound(to: spine_array_bone_wrapper.self))
    }

    /// Removes the element at the given index
    @discardableResult
    public func removeAt(_ index: Int) -> Bone? {
        precondition(index >= 0 && index < count, "Index out of bounds")
        let value = self[index]
        spine_array_bone_remove_at(_ptr.assumingMemoryBound(to: spine_array_bone_wrapper.self), index)
        return value
    }

    /// Sets the size of this array
    public var length: Int {
        get { count }
        set {
            spine_array_bone_set_size(_ptr.assumingMemoryBound(to: spine_array_bone_wrapper.self), newValue, nil)
        }
    }

    /// Ensures this array has at least the given capacity
    public func ensureCapacity(_ capacity: Int) {
        spine_array_bone_ensure_capacity(_ptr.assumingMemoryBound(to: spine_array_bone_wrapper.self), capacity)
    }

    deinit {
        if _ownsMemory {
            spine_array_bone_dispose(_ptr.assumingMemoryBound(to: spine_array_bone_wrapper.self))
        }
    }
}

/// ArrayBoneData wrapper
public class ArrayBoneData {
    public let _ptr: UnsafeMutableRawPointer
    private let _ownsMemory: Bool

    public init(fromPointer ptr: spine_array_bone_data, ownsMemory: Bool = false) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        self._ownsMemory = ownsMemory
    }


    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_bone_data_create()!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int) {
        let ptr = spine_array_bone_data_create_with_capacity(capacity)!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var count: Int {
        return Int(spine_array_bone_data_size(_ptr.assumingMemoryBound(to: spine_array_bone_data_wrapper.self)))
    }

    public subscript(index: Int) -> BoneData? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_bone_data_buffer(_ptr.assumingMemoryBound(to: spine_array_bone_data_wrapper.self))!
            let elementPtr = buffer[Int(index)]
            return elementPtr.map { BoneData(fromPointer: $0) }
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: BoneData?) {
        spine_array_bone_data_add(_ptr.assumingMemoryBound(to: spine_array_bone_data_wrapper.self), value?._ptr.assumingMemoryBound(to: spine_bone_data_wrapper.self))
    }

    /// Removes all elements from this array
    public func clear() {
        spine_array_bone_data_clear(_ptr.assumingMemoryBound(to: spine_array_bone_data_wrapper.self))
    }

    /// Removes the element at the given index
    @discardableResult
    public func removeAt(_ index: Int) -> BoneData? {
        precondition(index >= 0 && index < count, "Index out of bounds")
        let value = self[index]
        spine_array_bone_data_remove_at(_ptr.assumingMemoryBound(to: spine_array_bone_data_wrapper.self), index)
        return value
    }

    /// Sets the size of this array
    public var length: Int {
        get { count }
        set {
            spine_array_bone_data_set_size(_ptr.assumingMemoryBound(to: spine_array_bone_data_wrapper.self), newValue, nil)
        }
    }

    /// Ensures this array has at least the given capacity
    public func ensureCapacity(_ capacity: Int) {
        spine_array_bone_data_ensure_capacity(_ptr.assumingMemoryBound(to: spine_array_bone_data_wrapper.self), capacity)
    }

    deinit {
        if _ownsMemory {
            spine_array_bone_data_dispose(_ptr.assumingMemoryBound(to: spine_array_bone_data_wrapper.self))
        }
    }
}

/// ArrayBonePose wrapper
public class ArrayBonePose {
    public let _ptr: UnsafeMutableRawPointer
    private let _ownsMemory: Bool

    public init(fromPointer ptr: spine_array_bone_pose, ownsMemory: Bool = false) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        self._ownsMemory = ownsMemory
    }


    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_bone_pose_create()!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int) {
        let ptr = spine_array_bone_pose_create_with_capacity(capacity)!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var count: Int {
        return Int(spine_array_bone_pose_size(_ptr.assumingMemoryBound(to: spine_array_bone_pose_wrapper.self)))
    }

    public subscript(index: Int) -> BonePose? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_bone_pose_buffer(_ptr.assumingMemoryBound(to: spine_array_bone_pose_wrapper.self))!
            let elementPtr = buffer[Int(index)]
            return elementPtr.map { BonePose(fromPointer: $0) }
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: BonePose?) {
        spine_array_bone_pose_add(_ptr.assumingMemoryBound(to: spine_array_bone_pose_wrapper.self), value?._ptr.assumingMemoryBound(to: spine_bone_pose_wrapper.self))
    }

    /// Removes all elements from this array
    public func clear() {
        spine_array_bone_pose_clear(_ptr.assumingMemoryBound(to: spine_array_bone_pose_wrapper.self))
    }

    /// Removes the element at the given index
    @discardableResult
    public func removeAt(_ index: Int) -> BonePose? {
        precondition(index >= 0 && index < count, "Index out of bounds")
        let value = self[index]
        spine_array_bone_pose_remove_at(_ptr.assumingMemoryBound(to: spine_array_bone_pose_wrapper.self), index)
        return value
    }

    /// Sets the size of this array
    public var length: Int {
        get { count }
        set {
            spine_array_bone_pose_set_size(_ptr.assumingMemoryBound(to: spine_array_bone_pose_wrapper.self), newValue, nil)
        }
    }

    /// Ensures this array has at least the given capacity
    public func ensureCapacity(_ capacity: Int) {
        spine_array_bone_pose_ensure_capacity(_ptr.assumingMemoryBound(to: spine_array_bone_pose_wrapper.self), capacity)
    }

    deinit {
        if _ownsMemory {
            spine_array_bone_pose_dispose(_ptr.assumingMemoryBound(to: spine_array_bone_pose_wrapper.self))
        }
    }
}

/// ArrayBoundingBoxAttachment wrapper
public class ArrayBoundingBoxAttachment {
    public let _ptr: UnsafeMutableRawPointer
    private let _ownsMemory: Bool

    public init(fromPointer ptr: spine_array_bounding_box_attachment, ownsMemory: Bool = false) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        self._ownsMemory = ownsMemory
    }


    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_bounding_box_attachment_create()!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int) {
        let ptr = spine_array_bounding_box_attachment_create_with_capacity(capacity)!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var count: Int {
        return Int(spine_array_bounding_box_attachment_size(_ptr.assumingMemoryBound(to: spine_array_bounding_box_attachment_wrapper.self)))
    }

    public subscript(index: Int) -> BoundingBoxAttachment? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_bounding_box_attachment_buffer(_ptr.assumingMemoryBound(to: spine_array_bounding_box_attachment_wrapper.self))!
            let elementPtr = buffer[Int(index)]
            return elementPtr.map { BoundingBoxAttachment(fromPointer: $0) }
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: BoundingBoxAttachment?) {
        spine_array_bounding_box_attachment_add(_ptr.assumingMemoryBound(to: spine_array_bounding_box_attachment_wrapper.self), value?._ptr.assumingMemoryBound(to: spine_bounding_box_attachment_wrapper.self))
    }

    /// Removes all elements from this array
    public func clear() {
        spine_array_bounding_box_attachment_clear(_ptr.assumingMemoryBound(to: spine_array_bounding_box_attachment_wrapper.self))
    }

    /// Removes the element at the given index
    @discardableResult
    public func removeAt(_ index: Int) -> BoundingBoxAttachment? {
        precondition(index >= 0 && index < count, "Index out of bounds")
        let value = self[index]
        spine_array_bounding_box_attachment_remove_at(_ptr.assumingMemoryBound(to: spine_array_bounding_box_attachment_wrapper.self), index)
        return value
    }

    /// Sets the size of this array
    public var length: Int {
        get { count }
        set {
            spine_array_bounding_box_attachment_set_size(_ptr.assumingMemoryBound(to: spine_array_bounding_box_attachment_wrapper.self), newValue, nil)
        }
    }

    /// Ensures this array has at least the given capacity
    public func ensureCapacity(_ capacity: Int) {
        spine_array_bounding_box_attachment_ensure_capacity(_ptr.assumingMemoryBound(to: spine_array_bounding_box_attachment_wrapper.self), capacity)
    }

    deinit {
        if _ownsMemory {
            spine_array_bounding_box_attachment_dispose(_ptr.assumingMemoryBound(to: spine_array_bounding_box_attachment_wrapper.self))
        }
    }
}

/// ArrayConstraint wrapper
public class ArrayConstraint {
    public let _ptr: UnsafeMutableRawPointer
    private let _ownsMemory: Bool

    public init(fromPointer ptr: spine_array_constraint, ownsMemory: Bool = false) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        self._ownsMemory = ownsMemory
    }


    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_constraint_create()!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int) {
        let ptr = spine_array_constraint_create_with_capacity(capacity)!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var count: Int {
        return Int(spine_array_constraint_size(_ptr.assumingMemoryBound(to: spine_array_constraint_wrapper.self)))
    }

    public subscript(index: Int) -> Constraint? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_constraint_buffer(_ptr.assumingMemoryBound(to: spine_array_constraint_wrapper.self))!
            let elementPtr = buffer[Int(index)]
            guard let ptr = elementPtr else { return nil }
            let rtti = spine_constraint_get_rtti(ptr)
        let className = String(cString: spine_rtti_get_class_name(rtti)!)
        switch className {
        case "spine_ik_constraint":
            return IkConstraint(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_ik_constraint_wrapper.self))
        case "spine_path_constraint":
            return PathConstraint(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_path_constraint_wrapper.self))
        case "spine_physics_constraint":
            return PhysicsConstraint(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_physics_constraint_wrapper.self))
        case "spine_slider":
            return Slider(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_slider_wrapper.self))
        case "spine_transform_constraint":
            return TransformConstraint(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_transform_constraint_wrapper.self))
        default:
            fatalError("Unknown concrete type: \(className) for abstract class Constraint")
        }
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: Constraint?) {
        spine_array_constraint_add(_ptr.assumingMemoryBound(to: spine_array_constraint_wrapper.self), value?._ptr.assumingMemoryBound(to: spine_constraint_wrapper.self))
    }

    /// Removes all elements from this array
    public func clear() {
        spine_array_constraint_clear(_ptr.assumingMemoryBound(to: spine_array_constraint_wrapper.self))
    }

    /// Removes the element at the given index
    @discardableResult
    public func removeAt(_ index: Int) -> Constraint? {
        precondition(index >= 0 && index < count, "Index out of bounds")
        let value = self[index]
        spine_array_constraint_remove_at(_ptr.assumingMemoryBound(to: spine_array_constraint_wrapper.self), index)
        return value
    }

    /// Sets the size of this array
    public var length: Int {
        get { count }
        set {
            spine_array_constraint_set_size(_ptr.assumingMemoryBound(to: spine_array_constraint_wrapper.self), newValue, nil)
        }
    }

    /// Ensures this array has at least the given capacity
    public func ensureCapacity(_ capacity: Int) {
        spine_array_constraint_ensure_capacity(_ptr.assumingMemoryBound(to: spine_array_constraint_wrapper.self), capacity)
    }

    deinit {
        if _ownsMemory {
            spine_array_constraint_dispose(_ptr.assumingMemoryBound(to: spine_array_constraint_wrapper.self))
        }
    }
}

/// ArrayConstraintData wrapper
public class ArrayConstraintData {
    public let _ptr: UnsafeMutableRawPointer
    private let _ownsMemory: Bool

    public init(fromPointer ptr: spine_array_constraint_data, ownsMemory: Bool = false) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        self._ownsMemory = ownsMemory
    }


    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_constraint_data_create()!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int) {
        let ptr = spine_array_constraint_data_create_with_capacity(capacity)!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var count: Int {
        return Int(spine_array_constraint_data_size(_ptr.assumingMemoryBound(to: spine_array_constraint_data_wrapper.self)))
    }

    public subscript(index: Int) -> ConstraintData? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_constraint_data_buffer(_ptr.assumingMemoryBound(to: spine_array_constraint_data_wrapper.self))!
            let elementPtr = buffer[Int(index)]
            guard let ptr = elementPtr else { return nil }
            let rtti = spine_constraint_data_get_rtti(ptr)
        let className = String(cString: spine_rtti_get_class_name(rtti)!)
        switch className {
        case "spine_ik_constraint_data":
            return IkConstraintData(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_ik_constraint_data_wrapper.self))
        case "spine_path_constraint_data":
            return PathConstraintData(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_path_constraint_data_wrapper.self))
        case "spine_physics_constraint_data":
            return PhysicsConstraintData(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_physics_constraint_data_wrapper.self))
        case "spine_slider_data":
            return SliderData(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_slider_data_wrapper.self))
        case "spine_transform_constraint_data":
            return TransformConstraintData(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_transform_constraint_data_wrapper.self))
        default:
            fatalError("Unknown concrete type: \(className) for abstract class ConstraintData")
        }
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: ConstraintData?) {
        spine_array_constraint_data_add(_ptr.assumingMemoryBound(to: spine_array_constraint_data_wrapper.self), value?._ptr.assumingMemoryBound(to: spine_constraint_data_wrapper.self))
    }

    /// Removes all elements from this array
    public func clear() {
        spine_array_constraint_data_clear(_ptr.assumingMemoryBound(to: spine_array_constraint_data_wrapper.self))
    }

    /// Removes the element at the given index
    @discardableResult
    public func removeAt(_ index: Int) -> ConstraintData? {
        precondition(index >= 0 && index < count, "Index out of bounds")
        let value = self[index]
        spine_array_constraint_data_remove_at(_ptr.assumingMemoryBound(to: spine_array_constraint_data_wrapper.self), index)
        return value
    }

    /// Sets the size of this array
    public var length: Int {
        get { count }
        set {
            spine_array_constraint_data_set_size(_ptr.assumingMemoryBound(to: spine_array_constraint_data_wrapper.self), newValue, nil)
        }
    }

    /// Ensures this array has at least the given capacity
    public func ensureCapacity(_ capacity: Int) {
        spine_array_constraint_data_ensure_capacity(_ptr.assumingMemoryBound(to: spine_array_constraint_data_wrapper.self), capacity)
    }

    deinit {
        if _ownsMemory {
            spine_array_constraint_data_dispose(_ptr.assumingMemoryBound(to: spine_array_constraint_data_wrapper.self))
        }
    }
}

/// ArrayEvent wrapper
public class ArrayEvent {
    public let _ptr: UnsafeMutableRawPointer
    private let _ownsMemory: Bool

    public init(fromPointer ptr: spine_array_event, ownsMemory: Bool = false) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        self._ownsMemory = ownsMemory
    }


    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_event_create()!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int) {
        let ptr = spine_array_event_create_with_capacity(capacity)!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var count: Int {
        return Int(spine_array_event_size(_ptr.assumingMemoryBound(to: spine_array_event_wrapper.self)))
    }

    public subscript(index: Int) -> Event? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_event_buffer(_ptr.assumingMemoryBound(to: spine_array_event_wrapper.self))!
            let elementPtr = buffer[Int(index)]
            return elementPtr.map { Event(fromPointer: $0) }
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: Event?) {
        spine_array_event_add(_ptr.assumingMemoryBound(to: spine_array_event_wrapper.self), value?._ptr.assumingMemoryBound(to: spine_event_wrapper.self))
    }

    /// Removes all elements from this array
    public func clear() {
        spine_array_event_clear(_ptr.assumingMemoryBound(to: spine_array_event_wrapper.self))
    }

    /// Removes the element at the given index
    @discardableResult
    public func removeAt(_ index: Int) -> Event? {
        precondition(index >= 0 && index < count, "Index out of bounds")
        let value = self[index]
        spine_array_event_remove_at(_ptr.assumingMemoryBound(to: spine_array_event_wrapper.self), index)
        return value
    }

    /// Sets the size of this array
    public var length: Int {
        get { count }
        set {
            spine_array_event_set_size(_ptr.assumingMemoryBound(to: spine_array_event_wrapper.self), newValue, nil)
        }
    }

    /// Ensures this array has at least the given capacity
    public func ensureCapacity(_ capacity: Int) {
        spine_array_event_ensure_capacity(_ptr.assumingMemoryBound(to: spine_array_event_wrapper.self), capacity)
    }

    deinit {
        if _ownsMemory {
            spine_array_event_dispose(_ptr.assumingMemoryBound(to: spine_array_event_wrapper.self))
        }
    }
}

/// ArrayEventData wrapper
public class ArrayEventData {
    public let _ptr: UnsafeMutableRawPointer
    private let _ownsMemory: Bool

    public init(fromPointer ptr: spine_array_event_data, ownsMemory: Bool = false) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        self._ownsMemory = ownsMemory
    }


    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_event_data_create()!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int) {
        let ptr = spine_array_event_data_create_with_capacity(capacity)!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var count: Int {
        return Int(spine_array_event_data_size(_ptr.assumingMemoryBound(to: spine_array_event_data_wrapper.self)))
    }

    public subscript(index: Int) -> EventData? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_event_data_buffer(_ptr.assumingMemoryBound(to: spine_array_event_data_wrapper.self))!
            let elementPtr = buffer[Int(index)]
            return elementPtr.map { EventData(fromPointer: $0) }
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: EventData?) {
        spine_array_event_data_add(_ptr.assumingMemoryBound(to: spine_array_event_data_wrapper.self), value?._ptr.assumingMemoryBound(to: spine_event_data_wrapper.self))
    }

    /// Removes all elements from this array
    public func clear() {
        spine_array_event_data_clear(_ptr.assumingMemoryBound(to: spine_array_event_data_wrapper.self))
    }

    /// Removes the element at the given index
    @discardableResult
    public func removeAt(_ index: Int) -> EventData? {
        precondition(index >= 0 && index < count, "Index out of bounds")
        let value = self[index]
        spine_array_event_data_remove_at(_ptr.assumingMemoryBound(to: spine_array_event_data_wrapper.self), index)
        return value
    }

    /// Sets the size of this array
    public var length: Int {
        get { count }
        set {
            spine_array_event_data_set_size(_ptr.assumingMemoryBound(to: spine_array_event_data_wrapper.self), newValue, nil)
        }
    }

    /// Ensures this array has at least the given capacity
    public func ensureCapacity(_ capacity: Int) {
        spine_array_event_data_ensure_capacity(_ptr.assumingMemoryBound(to: spine_array_event_data_wrapper.self), capacity)
    }

    deinit {
        if _ownsMemory {
            spine_array_event_data_dispose(_ptr.assumingMemoryBound(to: spine_array_event_data_wrapper.self))
        }
    }
}

/// ArrayFromProperty wrapper
public class ArrayFromProperty {
    public let _ptr: UnsafeMutableRawPointer
    private let _ownsMemory: Bool

    public init(fromPointer ptr: spine_array_from_property, ownsMemory: Bool = false) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        self._ownsMemory = ownsMemory
    }


    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_from_property_create()!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int) {
        let ptr = spine_array_from_property_create_with_capacity(capacity)!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var count: Int {
        return Int(spine_array_from_property_size(_ptr.assumingMemoryBound(to: spine_array_from_property_wrapper.self)))
    }

    public subscript(index: Int) -> FromProperty? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_from_property_buffer(_ptr.assumingMemoryBound(to: spine_array_from_property_wrapper.self))!
            let elementPtr = buffer[Int(index)]
            guard let ptr = elementPtr else { return nil }
            let rtti = spine_from_property_get_rtti(ptr)
        let className = String(cString: spine_rtti_get_class_name(rtti)!)
        switch className {
        case "spine_from_rotate":
            return FromRotate(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_from_rotate_wrapper.self))
        case "spine_from_scale_x":
            return FromScaleX(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_from_scale_x_wrapper.self))
        case "spine_from_scale_y":
            return FromScaleY(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_from_scale_y_wrapper.self))
        case "spine_from_shear_y":
            return FromShearY(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_from_shear_y_wrapper.self))
        case "spine_from_x":
            return FromX(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_from_x_wrapper.self))
        case "spine_from_y":
            return FromY(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_from_y_wrapper.self))
        default:
            fatalError("Unknown concrete type: \(className) for abstract class FromProperty")
        }
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: FromProperty?) {
        spine_array_from_property_add(_ptr.assumingMemoryBound(to: spine_array_from_property_wrapper.self), value?._ptr.assumingMemoryBound(to: spine_from_property_wrapper.self))
    }

    /// Removes all elements from this array
    public func clear() {
        spine_array_from_property_clear(_ptr.assumingMemoryBound(to: spine_array_from_property_wrapper.self))
    }

    /// Removes the element at the given index
    @discardableResult
    public func removeAt(_ index: Int) -> FromProperty? {
        precondition(index >= 0 && index < count, "Index out of bounds")
        let value = self[index]
        spine_array_from_property_remove_at(_ptr.assumingMemoryBound(to: spine_array_from_property_wrapper.self), index)
        return value
    }

    /// Sets the size of this array
    public var length: Int {
        get { count }
        set {
            spine_array_from_property_set_size(_ptr.assumingMemoryBound(to: spine_array_from_property_wrapper.self), newValue, nil)
        }
    }

    /// Ensures this array has at least the given capacity
    public func ensureCapacity(_ capacity: Int) {
        spine_array_from_property_ensure_capacity(_ptr.assumingMemoryBound(to: spine_array_from_property_wrapper.self), capacity)
    }

    deinit {
        if _ownsMemory {
            spine_array_from_property_dispose(_ptr.assumingMemoryBound(to: spine_array_from_property_wrapper.self))
        }
    }
}

/// ArrayPhysicsConstraint wrapper
public class ArrayPhysicsConstraint {
    public let _ptr: UnsafeMutableRawPointer
    private let _ownsMemory: Bool

    public init(fromPointer ptr: spine_array_physics_constraint, ownsMemory: Bool = false) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        self._ownsMemory = ownsMemory
    }


    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_physics_constraint_create()!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int) {
        let ptr = spine_array_physics_constraint_create_with_capacity(capacity)!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var count: Int {
        return Int(spine_array_physics_constraint_size(_ptr.assumingMemoryBound(to: spine_array_physics_constraint_wrapper.self)))
    }

    public subscript(index: Int) -> PhysicsConstraint? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_physics_constraint_buffer(_ptr.assumingMemoryBound(to: spine_array_physics_constraint_wrapper.self))!
            let elementPtr = buffer[Int(index)]
            return elementPtr.map { PhysicsConstraint(fromPointer: $0) }
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: PhysicsConstraint?) {
        spine_array_physics_constraint_add(_ptr.assumingMemoryBound(to: spine_array_physics_constraint_wrapper.self), value?._ptr.assumingMemoryBound(to: spine_physics_constraint_wrapper.self))
    }

    /// Removes all elements from this array
    public func clear() {
        spine_array_physics_constraint_clear(_ptr.assumingMemoryBound(to: spine_array_physics_constraint_wrapper.self))
    }

    /// Removes the element at the given index
    @discardableResult
    public func removeAt(_ index: Int) -> PhysicsConstraint? {
        precondition(index >= 0 && index < count, "Index out of bounds")
        let value = self[index]
        spine_array_physics_constraint_remove_at(_ptr.assumingMemoryBound(to: spine_array_physics_constraint_wrapper.self), index)
        return value
    }

    /// Sets the size of this array
    public var length: Int {
        get { count }
        set {
            spine_array_physics_constraint_set_size(_ptr.assumingMemoryBound(to: spine_array_physics_constraint_wrapper.self), newValue, nil)
        }
    }

    /// Ensures this array has at least the given capacity
    public func ensureCapacity(_ capacity: Int) {
        spine_array_physics_constraint_ensure_capacity(_ptr.assumingMemoryBound(to: spine_array_physics_constraint_wrapper.self), capacity)
    }

    deinit {
        if _ownsMemory {
            spine_array_physics_constraint_dispose(_ptr.assumingMemoryBound(to: spine_array_physics_constraint_wrapper.self))
        }
    }
}

/// ArrayPolygon wrapper
public class ArrayPolygon {
    public let _ptr: UnsafeMutableRawPointer
    private let _ownsMemory: Bool

    public init(fromPointer ptr: spine_array_polygon, ownsMemory: Bool = false) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        self._ownsMemory = ownsMemory
    }


    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_polygon_create()!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int) {
        let ptr = spine_array_polygon_create_with_capacity(capacity)!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var count: Int {
        return Int(spine_array_polygon_size(_ptr.assumingMemoryBound(to: spine_array_polygon_wrapper.self)))
    }

    public subscript(index: Int) -> Polygon? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_polygon_buffer(_ptr.assumingMemoryBound(to: spine_array_polygon_wrapper.self))!
            let elementPtr = buffer[Int(index)]
            return elementPtr.map { Polygon(fromPointer: $0) }
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: Polygon?) {
        spine_array_polygon_add(_ptr.assumingMemoryBound(to: spine_array_polygon_wrapper.self), value?._ptr.assumingMemoryBound(to: spine_polygon_wrapper.self))
    }

    /// Removes all elements from this array
    public func clear() {
        spine_array_polygon_clear(_ptr.assumingMemoryBound(to: spine_array_polygon_wrapper.self))
    }

    /// Removes the element at the given index
    @discardableResult
    public func removeAt(_ index: Int) -> Polygon? {
        precondition(index >= 0 && index < count, "Index out of bounds")
        let value = self[index]
        spine_array_polygon_remove_at(_ptr.assumingMemoryBound(to: spine_array_polygon_wrapper.self), index)
        return value
    }

    /// Sets the size of this array
    public var length: Int {
        get { count }
        set {
            spine_array_polygon_set_size(_ptr.assumingMemoryBound(to: spine_array_polygon_wrapper.self), newValue, nil)
        }
    }

    /// Ensures this array has at least the given capacity
    public func ensureCapacity(_ capacity: Int) {
        spine_array_polygon_ensure_capacity(_ptr.assumingMemoryBound(to: spine_array_polygon_wrapper.self), capacity)
    }

    deinit {
        if _ownsMemory {
            spine_array_polygon_dispose(_ptr.assumingMemoryBound(to: spine_array_polygon_wrapper.self))
        }
    }
}

/// ArraySkin wrapper
public class ArraySkin {
    public let _ptr: UnsafeMutableRawPointer
    private let _ownsMemory: Bool

    public init(fromPointer ptr: spine_array_skin, ownsMemory: Bool = false) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        self._ownsMemory = ownsMemory
    }


    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_skin_create()!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int) {
        let ptr = spine_array_skin_create_with_capacity(capacity)!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var count: Int {
        return Int(spine_array_skin_size(_ptr.assumingMemoryBound(to: spine_array_skin_wrapper.self)))
    }

    public subscript(index: Int) -> Skin? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_skin_buffer(_ptr.assumingMemoryBound(to: spine_array_skin_wrapper.self))!
            let elementPtr = buffer[Int(index)]
            return elementPtr.map { Skin(fromPointer: $0) }
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: Skin?) {
        spine_array_skin_add(_ptr.assumingMemoryBound(to: spine_array_skin_wrapper.self), value?._ptr.assumingMemoryBound(to: spine_skin_wrapper.self))
    }

    /// Removes all elements from this array
    public func clear() {
        spine_array_skin_clear(_ptr.assumingMemoryBound(to: spine_array_skin_wrapper.self))
    }

    /// Removes the element at the given index
    @discardableResult
    public func removeAt(_ index: Int) -> Skin? {
        precondition(index >= 0 && index < count, "Index out of bounds")
        let value = self[index]
        spine_array_skin_remove_at(_ptr.assumingMemoryBound(to: spine_array_skin_wrapper.self), index)
        return value
    }

    /// Sets the size of this array
    public var length: Int {
        get { count }
        set {
            spine_array_skin_set_size(_ptr.assumingMemoryBound(to: spine_array_skin_wrapper.self), newValue, nil)
        }
    }

    /// Ensures this array has at least the given capacity
    public func ensureCapacity(_ capacity: Int) {
        spine_array_skin_ensure_capacity(_ptr.assumingMemoryBound(to: spine_array_skin_wrapper.self), capacity)
    }

    deinit {
        if _ownsMemory {
            spine_array_skin_dispose(_ptr.assumingMemoryBound(to: spine_array_skin_wrapper.self))
        }
    }
}

/// ArraySlot wrapper
public class ArraySlot {
    public let _ptr: UnsafeMutableRawPointer
    private let _ownsMemory: Bool

    public init(fromPointer ptr: spine_array_slot, ownsMemory: Bool = false) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        self._ownsMemory = ownsMemory
    }


    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_slot_create()!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int) {
        let ptr = spine_array_slot_create_with_capacity(capacity)!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var count: Int {
        return Int(spine_array_slot_size(_ptr.assumingMemoryBound(to: spine_array_slot_wrapper.self)))
    }

    public subscript(index: Int) -> Slot? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_slot_buffer(_ptr.assumingMemoryBound(to: spine_array_slot_wrapper.self))!
            let elementPtr = buffer[Int(index)]
            return elementPtr.map { Slot(fromPointer: $0) }
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: Slot?) {
        spine_array_slot_add(_ptr.assumingMemoryBound(to: spine_array_slot_wrapper.self), value?._ptr.assumingMemoryBound(to: spine_slot_wrapper.self))
    }

    /// Removes all elements from this array
    public func clear() {
        spine_array_slot_clear(_ptr.assumingMemoryBound(to: spine_array_slot_wrapper.self))
    }

    /// Removes the element at the given index
    @discardableResult
    public func removeAt(_ index: Int) -> Slot? {
        precondition(index >= 0 && index < count, "Index out of bounds")
        let value = self[index]
        spine_array_slot_remove_at(_ptr.assumingMemoryBound(to: spine_array_slot_wrapper.self), index)
        return value
    }

    /// Sets the size of this array
    public var length: Int {
        get { count }
        set {
            spine_array_slot_set_size(_ptr.assumingMemoryBound(to: spine_array_slot_wrapper.self), newValue, nil)
        }
    }

    /// Ensures this array has at least the given capacity
    public func ensureCapacity(_ capacity: Int) {
        spine_array_slot_ensure_capacity(_ptr.assumingMemoryBound(to: spine_array_slot_wrapper.self), capacity)
    }

    deinit {
        if _ownsMemory {
            spine_array_slot_dispose(_ptr.assumingMemoryBound(to: spine_array_slot_wrapper.self))
        }
    }
}

/// ArraySlotData wrapper
public class ArraySlotData {
    public let _ptr: UnsafeMutableRawPointer
    private let _ownsMemory: Bool

    public init(fromPointer ptr: spine_array_slot_data, ownsMemory: Bool = false) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        self._ownsMemory = ownsMemory
    }


    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_slot_data_create()!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int) {
        let ptr = spine_array_slot_data_create_with_capacity(capacity)!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var count: Int {
        return Int(spine_array_slot_data_size(_ptr.assumingMemoryBound(to: spine_array_slot_data_wrapper.self)))
    }

    public subscript(index: Int) -> SlotData? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_slot_data_buffer(_ptr.assumingMemoryBound(to: spine_array_slot_data_wrapper.self))!
            let elementPtr = buffer[Int(index)]
            return elementPtr.map { SlotData(fromPointer: $0) }
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: SlotData?) {
        spine_array_slot_data_add(_ptr.assumingMemoryBound(to: spine_array_slot_data_wrapper.self), value?._ptr.assumingMemoryBound(to: spine_slot_data_wrapper.self))
    }

    /// Removes all elements from this array
    public func clear() {
        spine_array_slot_data_clear(_ptr.assumingMemoryBound(to: spine_array_slot_data_wrapper.self))
    }

    /// Removes the element at the given index
    @discardableResult
    public func removeAt(_ index: Int) -> SlotData? {
        precondition(index >= 0 && index < count, "Index out of bounds")
        let value = self[index]
        spine_array_slot_data_remove_at(_ptr.assumingMemoryBound(to: spine_array_slot_data_wrapper.self), index)
        return value
    }

    /// Sets the size of this array
    public var length: Int {
        get { count }
        set {
            spine_array_slot_data_set_size(_ptr.assumingMemoryBound(to: spine_array_slot_data_wrapper.self), newValue, nil)
        }
    }

    /// Ensures this array has at least the given capacity
    public func ensureCapacity(_ capacity: Int) {
        spine_array_slot_data_ensure_capacity(_ptr.assumingMemoryBound(to: spine_array_slot_data_wrapper.self), capacity)
    }

    deinit {
        if _ownsMemory {
            spine_array_slot_data_dispose(_ptr.assumingMemoryBound(to: spine_array_slot_data_wrapper.self))
        }
    }
}

/// ArrayTextureRegion wrapper
public class ArrayTextureRegion {
    public let _ptr: UnsafeMutableRawPointer
    private let _ownsMemory: Bool

    public init(fromPointer ptr: spine_array_texture_region, ownsMemory: Bool = false) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        self._ownsMemory = ownsMemory
    }


    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_texture_region_create()!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int) {
        let ptr = spine_array_texture_region_create_with_capacity(capacity)!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var count: Int {
        return Int(spine_array_texture_region_size(_ptr.assumingMemoryBound(to: spine_array_texture_region_wrapper.self)))
    }

    public subscript(index: Int) -> TextureRegion? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_texture_region_buffer(_ptr.assumingMemoryBound(to: spine_array_texture_region_wrapper.self))!
            let elementPtr = buffer[Int(index)]
            return elementPtr.map { TextureRegion(fromPointer: $0) }
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: TextureRegion?) {
        spine_array_texture_region_add(_ptr.assumingMemoryBound(to: spine_array_texture_region_wrapper.self), value?._ptr.assumingMemoryBound(to: spine_texture_region_wrapper.self))
    }

    /// Removes all elements from this array
    public func clear() {
        spine_array_texture_region_clear(_ptr.assumingMemoryBound(to: spine_array_texture_region_wrapper.self))
    }

    /// Removes the element at the given index
    @discardableResult
    public func removeAt(_ index: Int) -> TextureRegion? {
        precondition(index >= 0 && index < count, "Index out of bounds")
        let value = self[index]
        spine_array_texture_region_remove_at(_ptr.assumingMemoryBound(to: spine_array_texture_region_wrapper.self), index)
        return value
    }

    /// Sets the size of this array
    public var length: Int {
        get { count }
        set {
            spine_array_texture_region_set_size(_ptr.assumingMemoryBound(to: spine_array_texture_region_wrapper.self), newValue, nil)
        }
    }

    /// Ensures this array has at least the given capacity
    public func ensureCapacity(_ capacity: Int) {
        spine_array_texture_region_ensure_capacity(_ptr.assumingMemoryBound(to: spine_array_texture_region_wrapper.self), capacity)
    }

    deinit {
        if _ownsMemory {
            spine_array_texture_region_dispose(_ptr.assumingMemoryBound(to: spine_array_texture_region_wrapper.self))
        }
    }
}

/// ArrayTimeline wrapper
public class ArrayTimeline {
    public let _ptr: UnsafeMutableRawPointer
    private let _ownsMemory: Bool

    public init(fromPointer ptr: spine_array_timeline, ownsMemory: Bool = false) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        self._ownsMemory = ownsMemory
    }


    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_timeline_create()!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int) {
        let ptr = spine_array_timeline_create_with_capacity(capacity)!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var count: Int {
        return Int(spine_array_timeline_size(_ptr.assumingMemoryBound(to: spine_array_timeline_wrapper.self)))
    }

    public subscript(index: Int) -> Timeline? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_timeline_buffer(_ptr.assumingMemoryBound(to: spine_array_timeline_wrapper.self))!
            let elementPtr = buffer[Int(index)]
            guard let ptr = elementPtr else { return nil }
            let rtti = spine_timeline_get_rtti(ptr)
        let className = String(cString: spine_rtti_get_class_name(rtti)!)
        switch className {
        case "spine_alpha_timeline":
            return AlphaTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_alpha_timeline_wrapper.self))
        case "spine_attachment_timeline":
            return AttachmentTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_attachment_timeline_wrapper.self))
        case "spine_deform_timeline":
            return DeformTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_deform_timeline_wrapper.self))
        case "spine_draw_order_timeline":
            return DrawOrderTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_draw_order_timeline_wrapper.self))
        case "spine_event_timeline":
            return EventTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_event_timeline_wrapper.self))
        case "spine_ik_constraint_timeline":
            return IkConstraintTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_ik_constraint_timeline_wrapper.self))
        case "spine_inherit_timeline":
            return InheritTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_inherit_timeline_wrapper.self))
        case "spine_path_constraint_mix_timeline":
            return PathConstraintMixTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_path_constraint_mix_timeline_wrapper.self))
        case "spine_path_constraint_position_timeline":
            return PathConstraintPositionTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_path_constraint_position_timeline_wrapper.self))
        case "spine_path_constraint_spacing_timeline":
            return PathConstraintSpacingTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_path_constraint_spacing_timeline_wrapper.self))
        case "spine_physics_constraint_damping_timeline":
            return PhysicsConstraintDampingTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_physics_constraint_damping_timeline_wrapper.self))
        case "spine_physics_constraint_gravity_timeline":
            return PhysicsConstraintGravityTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_physics_constraint_gravity_timeline_wrapper.self))
        case "spine_physics_constraint_inertia_timeline":
            return PhysicsConstraintInertiaTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_physics_constraint_inertia_timeline_wrapper.self))
        case "spine_physics_constraint_mass_timeline":
            return PhysicsConstraintMassTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_physics_constraint_mass_timeline_wrapper.self))
        case "spine_physics_constraint_mix_timeline":
            return PhysicsConstraintMixTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_physics_constraint_mix_timeline_wrapper.self))
        case "spine_physics_constraint_reset_timeline":
            return PhysicsConstraintResetTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_physics_constraint_reset_timeline_wrapper.self))
        case "spine_physics_constraint_strength_timeline":
            return PhysicsConstraintStrengthTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_physics_constraint_strength_timeline_wrapper.self))
        case "spine_physics_constraint_wind_timeline":
            return PhysicsConstraintWindTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_physics_constraint_wind_timeline_wrapper.self))
        case "spine_rgb2_timeline":
            return Rgb2Timeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_rgb2_timeline_wrapper.self))
        case "spine_rgba2_timeline":
            return Rgba2Timeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_rgba2_timeline_wrapper.self))
        case "spine_rgba_timeline":
            return RgbaTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_rgba_timeline_wrapper.self))
        case "spine_rgb_timeline":
            return RgbTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_rgb_timeline_wrapper.self))
        case "spine_rotate_timeline":
            return RotateTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_rotate_timeline_wrapper.self))
        case "spine_scale_timeline":
            return ScaleTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_scale_timeline_wrapper.self))
        case "spine_scale_x_timeline":
            return ScaleXTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_scale_x_timeline_wrapper.self))
        case "spine_scale_y_timeline":
            return ScaleYTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_scale_y_timeline_wrapper.self))
        case "spine_sequence_timeline":
            return SequenceTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_sequence_timeline_wrapper.self))
        case "spine_shear_timeline":
            return ShearTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_shear_timeline_wrapper.self))
        case "spine_shear_x_timeline":
            return ShearXTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_shear_x_timeline_wrapper.self))
        case "spine_shear_y_timeline":
            return ShearYTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_shear_y_timeline_wrapper.self))
        case "spine_slider_mix_timeline":
            return SliderMixTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_slider_mix_timeline_wrapper.self))
        case "spine_slider_timeline":
            return SliderTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_slider_timeline_wrapper.self))
        case "spine_transform_constraint_timeline":
            return TransformConstraintTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_transform_constraint_timeline_wrapper.self))
        case "spine_translate_timeline":
            return TranslateTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_translate_timeline_wrapper.self))
        case "spine_translate_x_timeline":
            return TranslateXTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_translate_x_timeline_wrapper.self))
        case "spine_translate_y_timeline":
            return TranslateYTimeline(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_translate_y_timeline_wrapper.self))
        default:
            fatalError("Unknown concrete type: \(className) for abstract class Timeline")
        }
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: Timeline?) {
        spine_array_timeline_add(_ptr.assumingMemoryBound(to: spine_array_timeline_wrapper.self), value?._ptr.assumingMemoryBound(to: spine_timeline_wrapper.self))
    }

    /// Removes all elements from this array
    public func clear() {
        spine_array_timeline_clear(_ptr.assumingMemoryBound(to: spine_array_timeline_wrapper.self))
    }

    /// Removes the element at the given index
    @discardableResult
    public func removeAt(_ index: Int) -> Timeline? {
        precondition(index >= 0 && index < count, "Index out of bounds")
        let value = self[index]
        spine_array_timeline_remove_at(_ptr.assumingMemoryBound(to: spine_array_timeline_wrapper.self), index)
        return value
    }

    /// Sets the size of this array
    public var length: Int {
        get { count }
        set {
            spine_array_timeline_set_size(_ptr.assumingMemoryBound(to: spine_array_timeline_wrapper.self), newValue, nil)
        }
    }

    /// Ensures this array has at least the given capacity
    public func ensureCapacity(_ capacity: Int) {
        spine_array_timeline_ensure_capacity(_ptr.assumingMemoryBound(to: spine_array_timeline_wrapper.self), capacity)
    }

    deinit {
        if _ownsMemory {
            spine_array_timeline_dispose(_ptr.assumingMemoryBound(to: spine_array_timeline_wrapper.self))
        }
    }
}

/// ArrayToProperty wrapper
public class ArrayToProperty {
    public let _ptr: UnsafeMutableRawPointer
    private let _ownsMemory: Bool

    public init(fromPointer ptr: spine_array_to_property, ownsMemory: Bool = false) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        self._ownsMemory = ownsMemory
    }


    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_to_property_create()!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int) {
        let ptr = spine_array_to_property_create_with_capacity(capacity)!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var count: Int {
        return Int(spine_array_to_property_size(_ptr.assumingMemoryBound(to: spine_array_to_property_wrapper.self)))
    }

    public subscript(index: Int) -> ToProperty? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_to_property_buffer(_ptr.assumingMemoryBound(to: spine_array_to_property_wrapper.self))!
            let elementPtr = buffer[Int(index)]
            guard let ptr = elementPtr else { return nil }
            let rtti = spine_to_property_get_rtti(ptr)
        let className = String(cString: spine_rtti_get_class_name(rtti)!)
        switch className {
        case "spine_to_rotate":
            return ToRotate(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_to_rotate_wrapper.self))
        case "spine_to_scale_x":
            return ToScaleX(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_to_scale_x_wrapper.self))
        case "spine_to_scale_y":
            return ToScaleY(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_to_scale_y_wrapper.self))
        case "spine_to_shear_y":
            return ToShearY(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_to_shear_y_wrapper.self))
        case "spine_to_x":
            return ToX(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_to_x_wrapper.self))
        case "spine_to_y":
            return ToY(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_to_y_wrapper.self))
        default:
            fatalError("Unknown concrete type: \(className) for abstract class ToProperty")
        }
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: ToProperty?) {
        spine_array_to_property_add(_ptr.assumingMemoryBound(to: spine_array_to_property_wrapper.self), value?._ptr.assumingMemoryBound(to: spine_to_property_wrapper.self))
    }

    /// Removes all elements from this array
    public func clear() {
        spine_array_to_property_clear(_ptr.assumingMemoryBound(to: spine_array_to_property_wrapper.self))
    }

    /// Removes the element at the given index
    @discardableResult
    public func removeAt(_ index: Int) -> ToProperty? {
        precondition(index >= 0 && index < count, "Index out of bounds")
        let value = self[index]
        spine_array_to_property_remove_at(_ptr.assumingMemoryBound(to: spine_array_to_property_wrapper.self), index)
        return value
    }

    /// Sets the size of this array
    public var length: Int {
        get { count }
        set {
            spine_array_to_property_set_size(_ptr.assumingMemoryBound(to: spine_array_to_property_wrapper.self), newValue, nil)
        }
    }

    /// Ensures this array has at least the given capacity
    public func ensureCapacity(_ capacity: Int) {
        spine_array_to_property_ensure_capacity(_ptr.assumingMemoryBound(to: spine_array_to_property_wrapper.self), capacity)
    }

    deinit {
        if _ownsMemory {
            spine_array_to_property_dispose(_ptr.assumingMemoryBound(to: spine_array_to_property_wrapper.self))
        }
    }
}

/// ArrayTrackEntry wrapper
public class ArrayTrackEntry {
    public let _ptr: UnsafeMutableRawPointer
    private let _ownsMemory: Bool

    public init(fromPointer ptr: spine_array_track_entry, ownsMemory: Bool = false) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        self._ownsMemory = ownsMemory
    }


    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_track_entry_create()!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int) {
        let ptr = spine_array_track_entry_create_with_capacity(capacity)!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var count: Int {
        return Int(spine_array_track_entry_size(_ptr.assumingMemoryBound(to: spine_array_track_entry_wrapper.self)))
    }

    public subscript(index: Int) -> TrackEntry? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_track_entry_buffer(_ptr.assumingMemoryBound(to: spine_array_track_entry_wrapper.self))!
            let elementPtr = buffer[Int(index)]
            return elementPtr.map { TrackEntry(fromPointer: $0) }
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: TrackEntry?) {
        spine_array_track_entry_add(_ptr.assumingMemoryBound(to: spine_array_track_entry_wrapper.self), value?._ptr.assumingMemoryBound(to: spine_track_entry_wrapper.self))
    }

    /// Removes all elements from this array
    public func clear() {
        spine_array_track_entry_clear(_ptr.assumingMemoryBound(to: spine_array_track_entry_wrapper.self))
    }

    /// Removes the element at the given index
    @discardableResult
    public func removeAt(_ index: Int) -> TrackEntry? {
        precondition(index >= 0 && index < count, "Index out of bounds")
        let value = self[index]
        spine_array_track_entry_remove_at(_ptr.assumingMemoryBound(to: spine_array_track_entry_wrapper.self), index)
        return value
    }

    /// Sets the size of this array
    public var length: Int {
        get { count }
        set {
            spine_array_track_entry_set_size(_ptr.assumingMemoryBound(to: spine_array_track_entry_wrapper.self), newValue, nil)
        }
    }

    /// Ensures this array has at least the given capacity
    public func ensureCapacity(_ capacity: Int) {
        spine_array_track_entry_ensure_capacity(_ptr.assumingMemoryBound(to: spine_array_track_entry_wrapper.self), capacity)
    }

    deinit {
        if _ownsMemory {
            spine_array_track_entry_dispose(_ptr.assumingMemoryBound(to: spine_array_track_entry_wrapper.self))
        }
    }
}

/// ArrayUpdate wrapper
public class ArrayUpdate {
    public let _ptr: UnsafeMutableRawPointer
    private let _ownsMemory: Bool

    public init(fromPointer ptr: spine_array_update, ownsMemory: Bool = false) {
        self._ptr = UnsafeMutableRawPointer(ptr)
        self._ownsMemory = ownsMemory
    }


    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_update_create()!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int) {
        let ptr = spine_array_update_create_with_capacity(capacity)!
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var count: Int {
        return Int(spine_array_update_size(_ptr.assumingMemoryBound(to: spine_array_update_wrapper.self)))
    }

    public subscript(index: Int) -> Update? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_update_buffer(_ptr.assumingMemoryBound(to: spine_array_update_wrapper.self))!
            let elementPtr = buffer[Int(index)]
            guard let ptr = elementPtr else { return nil }
            let rtti = spine_update_get_rtti(ptr)
        let className = String(cString: spine_rtti_get_class_name(rtti)!)
        switch className {
        case "spine_bone":
            return Bone(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_bone_wrapper.self))
        case "spine_bone_pose":
            return BonePose(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_bone_pose_wrapper.self))
        case "spine_ik_constraint":
            return IkConstraint(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_ik_constraint_wrapper.self))
        case "spine_path_constraint":
            return PathConstraint(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_path_constraint_wrapper.self))
        case "spine_physics_constraint":
            return PhysicsConstraint(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_physics_constraint_wrapper.self))
        case "spine_slider":
            return Slider(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_slider_wrapper.self))
        case "spine_transform_constraint":
            return TransformConstraint(fromPointer: UnsafeMutableRawPointer(ptr).assumingMemoryBound(to: spine_transform_constraint_wrapper.self))
        default:
            fatalError("Unknown concrete type: \(className) for abstract class Update")
        }
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: Update?) {
        spine_array_update_add(_ptr.assumingMemoryBound(to: spine_array_update_wrapper.self), value?._ptr.assumingMemoryBound(to: spine_update_wrapper.self))
    }

    /// Removes all elements from this array
    public func clear() {
        spine_array_update_clear(_ptr.assumingMemoryBound(to: spine_array_update_wrapper.self))
    }

    /// Removes the element at the given index
    @discardableResult
    public func removeAt(_ index: Int) -> Update? {
        precondition(index >= 0 && index < count, "Index out of bounds")
        let value = self[index]
        spine_array_update_remove_at(_ptr.assumingMemoryBound(to: spine_array_update_wrapper.self), index)
        return value
    }

    /// Sets the size of this array
    public var length: Int {
        get { count }
        set {
            spine_array_update_set_size(_ptr.assumingMemoryBound(to: spine_array_update_wrapper.self), newValue, nil)
        }
    }

    /// Ensures this array has at least the given capacity
    public func ensureCapacity(_ capacity: Int) {
        spine_array_update_ensure_capacity(_ptr.assumingMemoryBound(to: spine_array_update_wrapper.self), capacity)
    }

    deinit {
        if _ownsMemory {
            spine_array_update_dispose(_ptr.assumingMemoryBound(to: spine_array_update_wrapper.self))
        }
    }
}