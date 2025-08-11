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

/// ArrayFloat wrapper class
@objc(SpineArrayFloat)
@objcMembers
public final class ArrayFloat: NSObject {
    internal let ptr: OpaquePointer
    private let ownsMemory: Bool

    internal init(fromPointer ptr: OpaquePointer, ownsMemory: Bool = false) {
        self.ptr = ptr
        self.ownsMemory = ownsMemory
        super.init()
    }

    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_float_create()
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int32) {
        let ptr = spine_array_float_create_with_capacity(capacity)
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var nativePtr: OpaquePointer { ptr }

    public var count: Int32 {
        return spine_array_float_size(ptr)
    }

    public subscript(index: Int32) -> Float {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_float_buffer(ptr)
            return buffer!.assumingMemoryBound(to: Float.self)[Int(index)]
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: Float) {
        spine_array_float_add(ptr, value)
    }

    /// Removes all elements from this array
    public func removeAll() {
        spine_array_float_clear(ptr)
    }

    /// Removes the element at the specified index
    public func remove(at index: Int32) {
        precondition(index >= 0 && index < count, "Index out of bounds")
        spine_array_float_remove_at(ptr, index)
    }

    /// Sets the size of this array
    public func resize(to newSize: Int32) {
        spine_array_float_set_size(ptr, newSize, 0.0)
    }

    /// Ensures the array has at least the specified capacity
    public func ensureCapacity(_ capacity: Int32) {
        spine_array_float_ensure_capacity(ptr, capacity)
    }

    deinit {
        if ownsMemory {
        }
    }
}

/// ArrayInt wrapper class
@objc(SpineArrayInt)
@objcMembers
public final class ArrayInt: NSObject {
    internal let ptr: OpaquePointer
    private let ownsMemory: Bool

    internal init(fromPointer ptr: OpaquePointer, ownsMemory: Bool = false) {
        self.ptr = ptr
        self.ownsMemory = ownsMemory
        super.init()
    }

    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_int_create()
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int32) {
        let ptr = spine_array_int_create_with_capacity(capacity)
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var nativePtr: OpaquePointer { ptr }

    public var count: Int32 {
        return spine_array_int_size(ptr)
    }

    public subscript(index: Int32) -> Int32 {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_int_buffer(ptr)
            return buffer!.assumingMemoryBound(to: Int32.self)[Int(index)]
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: Int32) {
        spine_array_int_add(ptr, value)
    }

    /// Removes all elements from this array
    public func removeAll() {
        spine_array_int_clear(ptr)
    }

    /// Removes the element at the specified index
    public func remove(at index: Int32) {
        precondition(index >= 0 && index < count, "Index out of bounds")
        spine_array_int_remove_at(ptr, index)
    }

    /// Sets the size of this array
    public func resize(to newSize: Int32) {
        spine_array_int_set_size(ptr, newSize, 0)
    }

    /// Ensures the array has at least the specified capacity
    public func ensureCapacity(_ capacity: Int32) {
        spine_array_int_ensure_capacity(ptr, capacity)
    }

    deinit {
        if ownsMemory {
        }
    }
}

/// ArrayUnsignedShort wrapper class
@objc(SpineArrayUnsignedShort)
@objcMembers
public final class ArrayUnsignedShort: NSObject {
    internal let ptr: OpaquePointer
    private let ownsMemory: Bool

    internal init(fromPointer ptr: OpaquePointer, ownsMemory: Bool = false) {
        self.ptr = ptr
        self.ownsMemory = ownsMemory
        super.init()
    }

    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_unsigned_short_create()
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int32) {
        let ptr = spine_array_unsigned_short_create_with_capacity(capacity)
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var nativePtr: OpaquePointer { ptr }

    public var count: Int32 {
        return spine_array_unsigned_short_size(ptr)
    }

    public subscript(index: Int32) -> UInt16 {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_unsigned_short_buffer(ptr)
            return buffer!.assumingMemoryBound(to: UInt16.self)[Int(index)]
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: UInt16) {
        spine_array_unsigned_short_add(ptr, value)
    }

    /// Removes all elements from this array
    public func removeAll() {
        spine_array_unsigned_short_clear(ptr)
    }

    /// Removes the element at the specified index
    public func remove(at index: Int32) {
        precondition(index >= 0 && index < count, "Index out of bounds")
        spine_array_unsigned_short_remove_at(ptr, index)
    }

    /// Sets the size of this array
    public func resize(to newSize: Int32) {
        spine_array_unsigned_short_set_size(ptr, newSize, 0)
    }

    /// Ensures the array has at least the specified capacity
    public func ensureCapacity(_ capacity: Int32) {
        spine_array_unsigned_short_ensure_capacity(ptr, capacity)
    }

    deinit {
        if ownsMemory {
        }
    }
}

/// ArrayPropertyId wrapper class
@objc(SpineArrayPropertyId)
@objcMembers
public final class ArrayPropertyId: NSObject {
    internal let ptr: OpaquePointer
    private let ownsMemory: Bool

    internal init(fromPointer ptr: OpaquePointer, ownsMemory: Bool = false) {
        self.ptr = ptr
        self.ownsMemory = ownsMemory
        super.init()
    }

    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_property_id_create()
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int32) {
        let ptr = spine_array_property_id_create_with_capacity(capacity)
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var nativePtr: OpaquePointer { ptr }

    public var count: Int32 {
        return spine_array_property_id_size(ptr)
    }

    public subscript(index: Int32) -> Int64 {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_property_id_buffer(ptr)
            return buffer!.assumingMemoryBound(to: Int64.self)[Int(index)]
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: Int64) {
        spine_array_property_id_add(ptr, value)
    }

    /// Removes all elements from this array
    public func removeAll() {
        spine_array_property_id_clear(ptr)
    }

    /// Removes the element at the specified index
    public func remove(at index: Int32) {
        precondition(index >= 0 && index < count, "Index out of bounds")
        spine_array_property_id_remove_at(ptr, index)
    }

    /// Sets the size of this array
    public func resize(to newSize: Int32) {
        spine_array_property_id_set_size(ptr, newSize, 0)
    }

    /// Ensures the array has at least the specified capacity
    public func ensureCapacity(_ capacity: Int32) {
        spine_array_property_id_ensure_capacity(ptr, capacity)
    }

    deinit {
        if ownsMemory {
        }
    }
}

/// ArrayAnimation wrapper class
@objc(SpineArrayAnimation)
@objcMembers
public final class ArrayAnimation: NSObject {
    internal let ptr: OpaquePointer
    private let ownsMemory: Bool

    internal init(fromPointer ptr: OpaquePointer, ownsMemory: Bool = false) {
        self.ptr = ptr
        self.ownsMemory = ownsMemory
        super.init()
    }

    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_animation_create()
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int32) {
        let ptr = spine_array_animation_create_with_capacity(capacity)
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var nativePtr: OpaquePointer { ptr }

    public var count: Int32 {
        return spine_array_animation_size(ptr)
    }

    public subscript(index: Int32) -> Animation? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_animation_buffer(ptr)
            let elementPtr = buffer!.assumingMemoryBound(to: OpaquePointer?.self)[Int(index)]
            return elementPtr == nil ? nil : Animation(fromPointer: elementPtr!)
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: Animation?) {
        spine_array_animation_add(ptr, value?.nativePtr)
    }

    /// Removes all elements from this array
    public func removeAll() {
        spine_array_animation_clear(ptr)
    }

    /// Removes the element at the specified index
    public func remove(at index: Int32) {
        precondition(index >= 0 && index < count, "Index out of bounds")
        spine_array_animation_remove_at(ptr, index)
    }

    /// Sets the size of this array
    public func resize(to newSize: Int32) {
        spine_array_animation_set_size(ptr, newSize, nil)
    }

    /// Ensures the array has at least the specified capacity
    public func ensureCapacity(_ capacity: Int32) {
        spine_array_animation_ensure_capacity(ptr, capacity)
    }

    deinit {
        if ownsMemory {
        }
    }
}

/// ArrayAtlasPage wrapper class
@objc(SpineArrayAtlasPage)
@objcMembers
public final class ArrayAtlasPage: NSObject {
    internal let ptr: OpaquePointer
    private let ownsMemory: Bool

    internal init(fromPointer ptr: OpaquePointer, ownsMemory: Bool = false) {
        self.ptr = ptr
        self.ownsMemory = ownsMemory
        super.init()
    }

    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_atlas_page_create()
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int32) {
        let ptr = spine_array_atlas_page_create_with_capacity(capacity)
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var nativePtr: OpaquePointer { ptr }

    public var count: Int32 {
        return spine_array_atlas_page_size(ptr)
    }

    public subscript(index: Int32) -> AtlasPage? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_atlas_page_buffer(ptr)
            let elementPtr = buffer!.assumingMemoryBound(to: OpaquePointer?.self)[Int(index)]
            return elementPtr == nil ? nil : AtlasPage(fromPointer: elementPtr!)
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: AtlasPage?) {
        spine_array_atlas_page_add(ptr, value?.nativePtr)
    }

    /// Removes all elements from this array
    public func removeAll() {
        spine_array_atlas_page_clear(ptr)
    }

    /// Removes the element at the specified index
    public func remove(at index: Int32) {
        precondition(index >= 0 && index < count, "Index out of bounds")
        spine_array_atlas_page_remove_at(ptr, index)
    }

    /// Sets the size of this array
    public func resize(to newSize: Int32) {
        spine_array_atlas_page_set_size(ptr, newSize, nil)
    }

    /// Ensures the array has at least the specified capacity
    public func ensureCapacity(_ capacity: Int32) {
        spine_array_atlas_page_ensure_capacity(ptr, capacity)
    }

    deinit {
        if ownsMemory {
        }
    }
}

/// ArrayAtlasRegion wrapper class
@objc(SpineArrayAtlasRegion)
@objcMembers
public final class ArrayAtlasRegion: NSObject {
    internal let ptr: OpaquePointer
    private let ownsMemory: Bool

    internal init(fromPointer ptr: OpaquePointer, ownsMemory: Bool = false) {
        self.ptr = ptr
        self.ownsMemory = ownsMemory
        super.init()
    }

    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_atlas_region_create()
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int32) {
        let ptr = spine_array_atlas_region_create_with_capacity(capacity)
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var nativePtr: OpaquePointer { ptr }

    public var count: Int32 {
        return spine_array_atlas_region_size(ptr)
    }

    public subscript(index: Int32) -> AtlasRegion? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_atlas_region_buffer(ptr)
            let elementPtr = buffer!.assumingMemoryBound(to: OpaquePointer?.self)[Int(index)]
            return elementPtr == nil ? nil : AtlasRegion(fromPointer: elementPtr!)
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: AtlasRegion?) {
        spine_array_atlas_region_add(ptr, value?.nativePtr)
    }

    /// Removes all elements from this array
    public func removeAll() {
        spine_array_atlas_region_clear(ptr)
    }

    /// Removes the element at the specified index
    public func remove(at index: Int32) {
        precondition(index >= 0 && index < count, "Index out of bounds")
        spine_array_atlas_region_remove_at(ptr, index)
    }

    /// Sets the size of this array
    public func resize(to newSize: Int32) {
        spine_array_atlas_region_set_size(ptr, newSize, nil)
    }

    /// Ensures the array has at least the specified capacity
    public func ensureCapacity(_ capacity: Int32) {
        spine_array_atlas_region_ensure_capacity(ptr, capacity)
    }

    deinit {
        if ownsMemory {
        }
    }
}

/// ArrayAttachment wrapper class
@objc(SpineArrayAttachment)
@objcMembers
public final class ArrayAttachment: NSObject {
    internal let ptr: OpaquePointer
    private let ownsMemory: Bool

    internal init(fromPointer ptr: OpaquePointer, ownsMemory: Bool = false) {
        self.ptr = ptr
        self.ownsMemory = ownsMemory
        super.init()
    }

    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_attachment_create()
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int32) {
        let ptr = spine_array_attachment_create_with_capacity(capacity)
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var nativePtr: OpaquePointer { ptr }

    public var count: Int32 {
        return spine_array_attachment_size(ptr)
    }

    public subscript(index: Int32) -> Attachment? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_attachment_buffer(ptr)
            let elementPtr = buffer!.assumingMemoryBound(to: OpaquePointer?.self)[Int(index)]
            return elementPtr == nil ? nil : Attachment(fromPointer: elementPtr!)
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: Attachment?) {
        spine_array_attachment_add(ptr, value?.nativePtr)
    }

    /// Removes all elements from this array
    public func removeAll() {
        spine_array_attachment_clear(ptr)
    }

    /// Removes the element at the specified index
    public func remove(at index: Int32) {
        precondition(index >= 0 && index < count, "Index out of bounds")
        spine_array_attachment_remove_at(ptr, index)
    }

    /// Sets the size of this array
    public func resize(to newSize: Int32) {
        spine_array_attachment_set_size(ptr, newSize, nil)
    }

    /// Ensures the array has at least the specified capacity
    public func ensureCapacity(_ capacity: Int32) {
        spine_array_attachment_ensure_capacity(ptr, capacity)
    }

    deinit {
        if ownsMemory {
        }
    }
}

/// ArrayBone wrapper class
@objc(SpineArrayBone)
@objcMembers
public final class ArrayBone: NSObject {
    internal let ptr: OpaquePointer
    private let ownsMemory: Bool

    internal init(fromPointer ptr: OpaquePointer, ownsMemory: Bool = false) {
        self.ptr = ptr
        self.ownsMemory = ownsMemory
        super.init()
    }

    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_bone_create()
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int32) {
        let ptr = spine_array_bone_create_with_capacity(capacity)
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var nativePtr: OpaquePointer { ptr }

    public var count: Int32 {
        return spine_array_bone_size(ptr)
    }

    public subscript(index: Int32) -> Bone? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_bone_buffer(ptr)
            let elementPtr = buffer!.assumingMemoryBound(to: OpaquePointer?.self)[Int(index)]
            return elementPtr == nil ? nil : Bone(fromPointer: elementPtr!)
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: Bone?) {
        spine_array_bone_add(ptr, value?.nativePtr)
    }

    /// Removes all elements from this array
    public func removeAll() {
        spine_array_bone_clear(ptr)
    }

    /// Removes the element at the specified index
    public func remove(at index: Int32) {
        precondition(index >= 0 && index < count, "Index out of bounds")
        spine_array_bone_remove_at(ptr, index)
    }

    /// Sets the size of this array
    public func resize(to newSize: Int32) {
        spine_array_bone_set_size(ptr, newSize, nil)
    }

    /// Ensures the array has at least the specified capacity
    public func ensureCapacity(_ capacity: Int32) {
        spine_array_bone_ensure_capacity(ptr, capacity)
    }

    deinit {
        if ownsMemory {
        }
    }
}

/// ArrayBoneData wrapper class
@objc(SpineArrayBoneData)
@objcMembers
public final class ArrayBoneData: NSObject {
    internal let ptr: OpaquePointer
    private let ownsMemory: Bool

    internal init(fromPointer ptr: OpaquePointer, ownsMemory: Bool = false) {
        self.ptr = ptr
        self.ownsMemory = ownsMemory
        super.init()
    }

    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_bone_data_create()
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int32) {
        let ptr = spine_array_bone_data_create_with_capacity(capacity)
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var nativePtr: OpaquePointer { ptr }

    public var count: Int32 {
        return spine_array_bone_data_size(ptr)
    }

    public subscript(index: Int32) -> BoneData? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_bone_data_buffer(ptr)
            let elementPtr = buffer!.assumingMemoryBound(to: OpaquePointer?.self)[Int(index)]
            return elementPtr == nil ? nil : BoneData(fromPointer: elementPtr!)
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: BoneData?) {
        spine_array_bone_data_add(ptr, value?.nativePtr)
    }

    /// Removes all elements from this array
    public func removeAll() {
        spine_array_bone_data_clear(ptr)
    }

    /// Removes the element at the specified index
    public func remove(at index: Int32) {
        precondition(index >= 0 && index < count, "Index out of bounds")
        spine_array_bone_data_remove_at(ptr, index)
    }

    /// Sets the size of this array
    public func resize(to newSize: Int32) {
        spine_array_bone_data_set_size(ptr, newSize, nil)
    }

    /// Ensures the array has at least the specified capacity
    public func ensureCapacity(_ capacity: Int32) {
        spine_array_bone_data_ensure_capacity(ptr, capacity)
    }

    deinit {
        if ownsMemory {
        }
    }
}

/// ArrayBonePose wrapper class
@objc(SpineArrayBonePose)
@objcMembers
public final class ArrayBonePose: NSObject {
    internal let ptr: OpaquePointer
    private let ownsMemory: Bool

    internal init(fromPointer ptr: OpaquePointer, ownsMemory: Bool = false) {
        self.ptr = ptr
        self.ownsMemory = ownsMemory
        super.init()
    }

    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_bone_pose_create()
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int32) {
        let ptr = spine_array_bone_pose_create_with_capacity(capacity)
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var nativePtr: OpaquePointer { ptr }

    public var count: Int32 {
        return spine_array_bone_pose_size(ptr)
    }

    public subscript(index: Int32) -> BonePose? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_bone_pose_buffer(ptr)
            let elementPtr = buffer!.assumingMemoryBound(to: OpaquePointer?.self)[Int(index)]
            return elementPtr == nil ? nil : BonePose(fromPointer: elementPtr!)
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: BonePose?) {
        spine_array_bone_pose_add(ptr, value?.nativePtr)
    }

    /// Removes all elements from this array
    public func removeAll() {
        spine_array_bone_pose_clear(ptr)
    }

    /// Removes the element at the specified index
    public func remove(at index: Int32) {
        precondition(index >= 0 && index < count, "Index out of bounds")
        spine_array_bone_pose_remove_at(ptr, index)
    }

    /// Sets the size of this array
    public func resize(to newSize: Int32) {
        spine_array_bone_pose_set_size(ptr, newSize, nil)
    }

    /// Ensures the array has at least the specified capacity
    public func ensureCapacity(_ capacity: Int32) {
        spine_array_bone_pose_ensure_capacity(ptr, capacity)
    }

    deinit {
        if ownsMemory {
        }
    }
}

/// ArrayBoundingBoxAttachment wrapper class
@objc(SpineArrayBoundingBoxAttachment)
@objcMembers
public final class ArrayBoundingBoxAttachment: NSObject {
    internal let ptr: OpaquePointer
    private let ownsMemory: Bool

    internal init(fromPointer ptr: OpaquePointer, ownsMemory: Bool = false) {
        self.ptr = ptr
        self.ownsMemory = ownsMemory
        super.init()
    }

    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_bounding_box_attachment_create()
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int32) {
        let ptr = spine_array_bounding_box_attachment_create_with_capacity(capacity)
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var nativePtr: OpaquePointer { ptr }

    public var count: Int32 {
        return spine_array_bounding_box_attachment_size(ptr)
    }

    public subscript(index: Int32) -> BoundingBoxAttachment? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_bounding_box_attachment_buffer(ptr)
            let elementPtr = buffer!.assumingMemoryBound(to: OpaquePointer?.self)[Int(index)]
            return elementPtr == nil ? nil : BoundingBoxAttachment(fromPointer: elementPtr!)
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: BoundingBoxAttachment?) {
        spine_array_bounding_box_attachment_add(ptr, value?.nativePtr)
    }

    /// Removes all elements from this array
    public func removeAll() {
        spine_array_bounding_box_attachment_clear(ptr)
    }

    /// Removes the element at the specified index
    public func remove(at index: Int32) {
        precondition(index >= 0 && index < count, "Index out of bounds")
        spine_array_bounding_box_attachment_remove_at(ptr, index)
    }

    /// Sets the size of this array
    public func resize(to newSize: Int32) {
        spine_array_bounding_box_attachment_set_size(ptr, newSize, nil)
    }

    /// Ensures the array has at least the specified capacity
    public func ensureCapacity(_ capacity: Int32) {
        spine_array_bounding_box_attachment_ensure_capacity(ptr, capacity)
    }

    deinit {
        if ownsMemory {
        }
    }
}

/// ArrayConstraint wrapper class
@objc(SpineArrayConstraint)
@objcMembers
public final class ArrayConstraint: NSObject {
    internal let ptr: OpaquePointer
    private let ownsMemory: Bool

    internal init(fromPointer ptr: OpaquePointer, ownsMemory: Bool = false) {
        self.ptr = ptr
        self.ownsMemory = ownsMemory
        super.init()
    }

    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_constraint_create()
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int32) {
        let ptr = spine_array_constraint_create_with_capacity(capacity)
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var nativePtr: OpaquePointer { ptr }

    public var count: Int32 {
        return spine_array_constraint_size(ptr)
    }

    public subscript(index: Int32) -> Constraint? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_constraint_buffer(ptr)
            let elementPtr = buffer!.assumingMemoryBound(to: OpaquePointer?.self)[Int(index)]
            return elementPtr == nil ? nil : Constraint(fromPointer: elementPtr!)
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: Constraint?) {
        spine_array_constraint_add(ptr, value?.nativePtr)
    }

    /// Removes all elements from this array
    public func removeAll() {
        spine_array_constraint_clear(ptr)
    }

    /// Removes the element at the specified index
    public func remove(at index: Int32) {
        precondition(index >= 0 && index < count, "Index out of bounds")
        spine_array_constraint_remove_at(ptr, index)
    }

    /// Sets the size of this array
    public func resize(to newSize: Int32) {
        spine_array_constraint_set_size(ptr, newSize, nil)
    }

    /// Ensures the array has at least the specified capacity
    public func ensureCapacity(_ capacity: Int32) {
        spine_array_constraint_ensure_capacity(ptr, capacity)
    }

    deinit {
        if ownsMemory {
        }
    }
}

/// ArrayConstraintData wrapper class
@objc(SpineArrayConstraintData)
@objcMembers
public final class ArrayConstraintData: NSObject {
    internal let ptr: OpaquePointer
    private let ownsMemory: Bool

    internal init(fromPointer ptr: OpaquePointer, ownsMemory: Bool = false) {
        self.ptr = ptr
        self.ownsMemory = ownsMemory
        super.init()
    }

    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_constraint_data_create()
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int32) {
        let ptr = spine_array_constraint_data_create_with_capacity(capacity)
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var nativePtr: OpaquePointer { ptr }

    public var count: Int32 {
        return spine_array_constraint_data_size(ptr)
    }

    public subscript(index: Int32) -> ConstraintData? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_constraint_data_buffer(ptr)
            let elementPtr = buffer!.assumingMemoryBound(to: OpaquePointer?.self)[Int(index)]
            return elementPtr == nil ? nil : ConstraintData(fromPointer: elementPtr!)
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: ConstraintData?) {
        spine_array_constraint_data_add(ptr, value?.nativePtr)
    }

    /// Removes all elements from this array
    public func removeAll() {
        spine_array_constraint_data_clear(ptr)
    }

    /// Removes the element at the specified index
    public func remove(at index: Int32) {
        precondition(index >= 0 && index < count, "Index out of bounds")
        spine_array_constraint_data_remove_at(ptr, index)
    }

    /// Sets the size of this array
    public func resize(to newSize: Int32) {
        spine_array_constraint_data_set_size(ptr, newSize, nil)
    }

    /// Ensures the array has at least the specified capacity
    public func ensureCapacity(_ capacity: Int32) {
        spine_array_constraint_data_ensure_capacity(ptr, capacity)
    }

    deinit {
        if ownsMemory {
        }
    }
}

/// ArrayEvent wrapper class
@objc(SpineArrayEvent)
@objcMembers
public final class ArrayEvent: NSObject {
    internal let ptr: OpaquePointer
    private let ownsMemory: Bool

    internal init(fromPointer ptr: OpaquePointer, ownsMemory: Bool = false) {
        self.ptr = ptr
        self.ownsMemory = ownsMemory
        super.init()
    }

    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_event_create()
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int32) {
        let ptr = spine_array_event_create_with_capacity(capacity)
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var nativePtr: OpaquePointer { ptr }

    public var count: Int32 {
        return spine_array_event_size(ptr)
    }

    public subscript(index: Int32) -> Event? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_event_buffer(ptr)
            let elementPtr = buffer!.assumingMemoryBound(to: OpaquePointer?.self)[Int(index)]
            return elementPtr == nil ? nil : Event(fromPointer: elementPtr!)
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: Event?) {
        spine_array_event_add(ptr, value?.nativePtr)
    }

    /// Removes all elements from this array
    public func removeAll() {
        spine_array_event_clear(ptr)
    }

    /// Removes the element at the specified index
    public func remove(at index: Int32) {
        precondition(index >= 0 && index < count, "Index out of bounds")
        spine_array_event_remove_at(ptr, index)
    }

    /// Sets the size of this array
    public func resize(to newSize: Int32) {
        spine_array_event_set_size(ptr, newSize, nil)
    }

    /// Ensures the array has at least the specified capacity
    public func ensureCapacity(_ capacity: Int32) {
        spine_array_event_ensure_capacity(ptr, capacity)
    }

    deinit {
        if ownsMemory {
        }
    }
}

/// ArrayEventData wrapper class
@objc(SpineArrayEventData)
@objcMembers
public final class ArrayEventData: NSObject {
    internal let ptr: OpaquePointer
    private let ownsMemory: Bool

    internal init(fromPointer ptr: OpaquePointer, ownsMemory: Bool = false) {
        self.ptr = ptr
        self.ownsMemory = ownsMemory
        super.init()
    }

    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_event_data_create()
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int32) {
        let ptr = spine_array_event_data_create_with_capacity(capacity)
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var nativePtr: OpaquePointer { ptr }

    public var count: Int32 {
        return spine_array_event_data_size(ptr)
    }

    public subscript(index: Int32) -> EventData? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_event_data_buffer(ptr)
            let elementPtr = buffer!.assumingMemoryBound(to: OpaquePointer?.self)[Int(index)]
            return elementPtr == nil ? nil : EventData(fromPointer: elementPtr!)
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: EventData?) {
        spine_array_event_data_add(ptr, value?.nativePtr)
    }

    /// Removes all elements from this array
    public func removeAll() {
        spine_array_event_data_clear(ptr)
    }

    /// Removes the element at the specified index
    public func remove(at index: Int32) {
        precondition(index >= 0 && index < count, "Index out of bounds")
        spine_array_event_data_remove_at(ptr, index)
    }

    /// Sets the size of this array
    public func resize(to newSize: Int32) {
        spine_array_event_data_set_size(ptr, newSize, nil)
    }

    /// Ensures the array has at least the specified capacity
    public func ensureCapacity(_ capacity: Int32) {
        spine_array_event_data_ensure_capacity(ptr, capacity)
    }

    deinit {
        if ownsMemory {
        }
    }
}

/// ArrayFromProperty wrapper class
@objc(SpineArrayFromProperty)
@objcMembers
public final class ArrayFromProperty: NSObject {
    internal let ptr: OpaquePointer
    private let ownsMemory: Bool

    internal init(fromPointer ptr: OpaquePointer, ownsMemory: Bool = false) {
        self.ptr = ptr
        self.ownsMemory = ownsMemory
        super.init()
    }

    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_from_property_create()
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int32) {
        let ptr = spine_array_from_property_create_with_capacity(capacity)
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var nativePtr: OpaquePointer { ptr }

    public var count: Int32 {
        return spine_array_from_property_size(ptr)
    }

    public subscript(index: Int32) -> FromProperty? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_from_property_buffer(ptr)
            let elementPtr = buffer!.assumingMemoryBound(to: OpaquePointer?.self)[Int(index)]
            return elementPtr == nil ? nil : FromProperty(fromPointer: elementPtr!)
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: FromProperty?) {
        spine_array_from_property_add(ptr, value?.nativePtr)
    }

    /// Removes all elements from this array
    public func removeAll() {
        spine_array_from_property_clear(ptr)
    }

    /// Removes the element at the specified index
    public func remove(at index: Int32) {
        precondition(index >= 0 && index < count, "Index out of bounds")
        spine_array_from_property_remove_at(ptr, index)
    }

    /// Sets the size of this array
    public func resize(to newSize: Int32) {
        spine_array_from_property_set_size(ptr, newSize, nil)
    }

    /// Ensures the array has at least the specified capacity
    public func ensureCapacity(_ capacity: Int32) {
        spine_array_from_property_ensure_capacity(ptr, capacity)
    }

    deinit {
        if ownsMemory {
        }
    }
}

/// ArrayPhysicsConstraint wrapper class
@objc(SpineArrayPhysicsConstraint)
@objcMembers
public final class ArrayPhysicsConstraint: NSObject {
    internal let ptr: OpaquePointer
    private let ownsMemory: Bool

    internal init(fromPointer ptr: OpaquePointer, ownsMemory: Bool = false) {
        self.ptr = ptr
        self.ownsMemory = ownsMemory
        super.init()
    }

    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_physics_constraint_create()
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int32) {
        let ptr = spine_array_physics_constraint_create_with_capacity(capacity)
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var nativePtr: OpaquePointer { ptr }

    public var count: Int32 {
        return spine_array_physics_constraint_size(ptr)
    }

    public subscript(index: Int32) -> PhysicsConstraint? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_physics_constraint_buffer(ptr)
            let elementPtr = buffer!.assumingMemoryBound(to: OpaquePointer?.self)[Int(index)]
            return elementPtr == nil ? nil : PhysicsConstraint(fromPointer: elementPtr!)
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: PhysicsConstraint?) {
        spine_array_physics_constraint_add(ptr, value?.nativePtr)
    }

    /// Removes all elements from this array
    public func removeAll() {
        spine_array_physics_constraint_clear(ptr)
    }

    /// Removes the element at the specified index
    public func remove(at index: Int32) {
        precondition(index >= 0 && index < count, "Index out of bounds")
        spine_array_physics_constraint_remove_at(ptr, index)
    }

    /// Sets the size of this array
    public func resize(to newSize: Int32) {
        spine_array_physics_constraint_set_size(ptr, newSize, nil)
    }

    /// Ensures the array has at least the specified capacity
    public func ensureCapacity(_ capacity: Int32) {
        spine_array_physics_constraint_ensure_capacity(ptr, capacity)
    }

    deinit {
        if ownsMemory {
        }
    }
}

/// ArrayPolygon wrapper class
@objc(SpineArrayPolygon)
@objcMembers
public final class ArrayPolygon: NSObject {
    internal let ptr: OpaquePointer
    private let ownsMemory: Bool

    internal init(fromPointer ptr: OpaquePointer, ownsMemory: Bool = false) {
        self.ptr = ptr
        self.ownsMemory = ownsMemory
        super.init()
    }

    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_polygon_create()
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int32) {
        let ptr = spine_array_polygon_create_with_capacity(capacity)
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var nativePtr: OpaquePointer { ptr }

    public var count: Int32 {
        return spine_array_polygon_size(ptr)
    }

    public subscript(index: Int32) -> Polygon? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_polygon_buffer(ptr)
            let elementPtr = buffer!.assumingMemoryBound(to: OpaquePointer?.self)[Int(index)]
            return elementPtr == nil ? nil : Polygon(fromPointer: elementPtr!)
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: Polygon?) {
        spine_array_polygon_add(ptr, value?.nativePtr)
    }

    /// Removes all elements from this array
    public func removeAll() {
        spine_array_polygon_clear(ptr)
    }

    /// Removes the element at the specified index
    public func remove(at index: Int32) {
        precondition(index >= 0 && index < count, "Index out of bounds")
        spine_array_polygon_remove_at(ptr, index)
    }

    /// Sets the size of this array
    public func resize(to newSize: Int32) {
        spine_array_polygon_set_size(ptr, newSize, nil)
    }

    /// Ensures the array has at least the specified capacity
    public func ensureCapacity(_ capacity: Int32) {
        spine_array_polygon_ensure_capacity(ptr, capacity)
    }

    deinit {
        if ownsMemory {
        }
    }
}

/// ArraySkin wrapper class
@objc(SpineArraySkin)
@objcMembers
public final class ArraySkin: NSObject {
    internal let ptr: OpaquePointer
    private let ownsMemory: Bool

    internal init(fromPointer ptr: OpaquePointer, ownsMemory: Bool = false) {
        self.ptr = ptr
        self.ownsMemory = ownsMemory
        super.init()
    }

    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_skin_create()
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int32) {
        let ptr = spine_array_skin_create_with_capacity(capacity)
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var nativePtr: OpaquePointer { ptr }

    public var count: Int32 {
        return spine_array_skin_size(ptr)
    }

    public subscript(index: Int32) -> Skin? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_skin_buffer(ptr)
            let elementPtr = buffer!.assumingMemoryBound(to: OpaquePointer?.self)[Int(index)]
            return elementPtr == nil ? nil : Skin(fromPointer: elementPtr!)
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: Skin?) {
        spine_array_skin_add(ptr, value?.nativePtr)
    }

    /// Removes all elements from this array
    public func removeAll() {
        spine_array_skin_clear(ptr)
    }

    /// Removes the element at the specified index
    public func remove(at index: Int32) {
        precondition(index >= 0 && index < count, "Index out of bounds")
        spine_array_skin_remove_at(ptr, index)
    }

    /// Sets the size of this array
    public func resize(to newSize: Int32) {
        spine_array_skin_set_size(ptr, newSize, nil)
    }

    /// Ensures the array has at least the specified capacity
    public func ensureCapacity(_ capacity: Int32) {
        spine_array_skin_ensure_capacity(ptr, capacity)
    }

    deinit {
        if ownsMemory {
        }
    }
}

/// ArraySlot wrapper class
@objc(SpineArraySlot)
@objcMembers
public final class ArraySlot: NSObject {
    internal let ptr: OpaquePointer
    private let ownsMemory: Bool

    internal init(fromPointer ptr: OpaquePointer, ownsMemory: Bool = false) {
        self.ptr = ptr
        self.ownsMemory = ownsMemory
        super.init()
    }

    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_slot_create()
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int32) {
        let ptr = spine_array_slot_create_with_capacity(capacity)
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var nativePtr: OpaquePointer { ptr }

    public var count: Int32 {
        return spine_array_slot_size(ptr)
    }

    public subscript(index: Int32) -> Slot? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_slot_buffer(ptr)
            let elementPtr = buffer!.assumingMemoryBound(to: OpaquePointer?.self)[Int(index)]
            return elementPtr == nil ? nil : Slot(fromPointer: elementPtr!)
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: Slot?) {
        spine_array_slot_add(ptr, value?.nativePtr)
    }

    /// Removes all elements from this array
    public func removeAll() {
        spine_array_slot_clear(ptr)
    }

    /// Removes the element at the specified index
    public func remove(at index: Int32) {
        precondition(index >= 0 && index < count, "Index out of bounds")
        spine_array_slot_remove_at(ptr, index)
    }

    /// Sets the size of this array
    public func resize(to newSize: Int32) {
        spine_array_slot_set_size(ptr, newSize, nil)
    }

    /// Ensures the array has at least the specified capacity
    public func ensureCapacity(_ capacity: Int32) {
        spine_array_slot_ensure_capacity(ptr, capacity)
    }

    deinit {
        if ownsMemory {
        }
    }
}

/// ArraySlotData wrapper class
@objc(SpineArraySlotData)
@objcMembers
public final class ArraySlotData: NSObject {
    internal let ptr: OpaquePointer
    private let ownsMemory: Bool

    internal init(fromPointer ptr: OpaquePointer, ownsMemory: Bool = false) {
        self.ptr = ptr
        self.ownsMemory = ownsMemory
        super.init()
    }

    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_slot_data_create()
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int32) {
        let ptr = spine_array_slot_data_create_with_capacity(capacity)
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var nativePtr: OpaquePointer { ptr }

    public var count: Int32 {
        return spine_array_slot_data_size(ptr)
    }

    public subscript(index: Int32) -> SlotData? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_slot_data_buffer(ptr)
            let elementPtr = buffer!.assumingMemoryBound(to: OpaquePointer?.self)[Int(index)]
            return elementPtr == nil ? nil : SlotData(fromPointer: elementPtr!)
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: SlotData?) {
        spine_array_slot_data_add(ptr, value?.nativePtr)
    }

    /// Removes all elements from this array
    public func removeAll() {
        spine_array_slot_data_clear(ptr)
    }

    /// Removes the element at the specified index
    public func remove(at index: Int32) {
        precondition(index >= 0 && index < count, "Index out of bounds")
        spine_array_slot_data_remove_at(ptr, index)
    }

    /// Sets the size of this array
    public func resize(to newSize: Int32) {
        spine_array_slot_data_set_size(ptr, newSize, nil)
    }

    /// Ensures the array has at least the specified capacity
    public func ensureCapacity(_ capacity: Int32) {
        spine_array_slot_data_ensure_capacity(ptr, capacity)
    }

    deinit {
        if ownsMemory {
        }
    }
}

/// ArrayTextureRegion wrapper class
@objc(SpineArrayTextureRegion)
@objcMembers
public final class ArrayTextureRegion: NSObject {
    internal let ptr: OpaquePointer
    private let ownsMemory: Bool

    internal init(fromPointer ptr: OpaquePointer, ownsMemory: Bool = false) {
        self.ptr = ptr
        self.ownsMemory = ownsMemory
        super.init()
    }

    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_texture_region_create()
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int32) {
        let ptr = spine_array_texture_region_create_with_capacity(capacity)
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var nativePtr: OpaquePointer { ptr }

    public var count: Int32 {
        return spine_array_texture_region_size(ptr)
    }

    public subscript(index: Int32) -> TextureRegion? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_texture_region_buffer(ptr)
            let elementPtr = buffer!.assumingMemoryBound(to: OpaquePointer?.self)[Int(index)]
            return elementPtr == nil ? nil : TextureRegion(fromPointer: elementPtr!)
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: TextureRegion?) {
        spine_array_texture_region_add(ptr, value?.nativePtr)
    }

    /// Removes all elements from this array
    public func removeAll() {
        spine_array_texture_region_clear(ptr)
    }

    /// Removes the element at the specified index
    public func remove(at index: Int32) {
        precondition(index >= 0 && index < count, "Index out of bounds")
        spine_array_texture_region_remove_at(ptr, index)
    }

    /// Sets the size of this array
    public func resize(to newSize: Int32) {
        spine_array_texture_region_set_size(ptr, newSize, nil)
    }

    /// Ensures the array has at least the specified capacity
    public func ensureCapacity(_ capacity: Int32) {
        spine_array_texture_region_ensure_capacity(ptr, capacity)
    }

    deinit {
        if ownsMemory {
        }
    }
}

/// ArrayTimeline wrapper class
@objc(SpineArrayTimeline)
@objcMembers
public final class ArrayTimeline: NSObject {
    internal let ptr: OpaquePointer
    private let ownsMemory: Bool

    internal init(fromPointer ptr: OpaquePointer, ownsMemory: Bool = false) {
        self.ptr = ptr
        self.ownsMemory = ownsMemory
        super.init()
    }

    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_timeline_create()
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int32) {
        let ptr = spine_array_timeline_create_with_capacity(capacity)
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var nativePtr: OpaquePointer { ptr }

    public var count: Int32 {
        return spine_array_timeline_size(ptr)
    }

    public subscript(index: Int32) -> Timeline? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_timeline_buffer(ptr)
            let elementPtr = buffer!.assumingMemoryBound(to: OpaquePointer?.self)[Int(index)]
            return elementPtr == nil ? nil : Timeline(fromPointer: elementPtr!)
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: Timeline?) {
        spine_array_timeline_add(ptr, value?.nativePtr)
    }

    /// Removes all elements from this array
    public func removeAll() {
        spine_array_timeline_clear(ptr)
    }

    /// Removes the element at the specified index
    public func remove(at index: Int32) {
        precondition(index >= 0 && index < count, "Index out of bounds")
        spine_array_timeline_remove_at(ptr, index)
    }

    /// Sets the size of this array
    public func resize(to newSize: Int32) {
        spine_array_timeline_set_size(ptr, newSize, nil)
    }

    /// Ensures the array has at least the specified capacity
    public func ensureCapacity(_ capacity: Int32) {
        spine_array_timeline_ensure_capacity(ptr, capacity)
    }

    deinit {
        if ownsMemory {
        }
    }
}

/// ArrayToProperty wrapper class
@objc(SpineArrayToProperty)
@objcMembers
public final class ArrayToProperty: NSObject {
    internal let ptr: OpaquePointer
    private let ownsMemory: Bool

    internal init(fromPointer ptr: OpaquePointer, ownsMemory: Bool = false) {
        self.ptr = ptr
        self.ownsMemory = ownsMemory
        super.init()
    }

    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_to_property_create()
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int32) {
        let ptr = spine_array_to_property_create_with_capacity(capacity)
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var nativePtr: OpaquePointer { ptr }

    public var count: Int32 {
        return spine_array_to_property_size(ptr)
    }

    public subscript(index: Int32) -> ToProperty? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_to_property_buffer(ptr)
            let elementPtr = buffer!.assumingMemoryBound(to: OpaquePointer?.self)[Int(index)]
            return elementPtr == nil ? nil : ToProperty(fromPointer: elementPtr!)
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: ToProperty?) {
        spine_array_to_property_add(ptr, value?.nativePtr)
    }

    /// Removes all elements from this array
    public func removeAll() {
        spine_array_to_property_clear(ptr)
    }

    /// Removes the element at the specified index
    public func remove(at index: Int32) {
        precondition(index >= 0 && index < count, "Index out of bounds")
        spine_array_to_property_remove_at(ptr, index)
    }

    /// Sets the size of this array
    public func resize(to newSize: Int32) {
        spine_array_to_property_set_size(ptr, newSize, nil)
    }

    /// Ensures the array has at least the specified capacity
    public func ensureCapacity(_ capacity: Int32) {
        spine_array_to_property_ensure_capacity(ptr, capacity)
    }

    deinit {
        if ownsMemory {
        }
    }
}

/// ArrayTrackEntry wrapper class
@objc(SpineArrayTrackEntry)
@objcMembers
public final class ArrayTrackEntry: NSObject {
    internal let ptr: OpaquePointer
    private let ownsMemory: Bool

    internal init(fromPointer ptr: OpaquePointer, ownsMemory: Bool = false) {
        self.ptr = ptr
        self.ownsMemory = ownsMemory
        super.init()
    }

    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_track_entry_create()
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int32) {
        let ptr = spine_array_track_entry_create_with_capacity(capacity)
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var nativePtr: OpaquePointer { ptr }

    public var count: Int32 {
        return spine_array_track_entry_size(ptr)
    }

    public subscript(index: Int32) -> TrackEntry? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_track_entry_buffer(ptr)
            let elementPtr = buffer!.assumingMemoryBound(to: OpaquePointer?.self)[Int(index)]
            return elementPtr == nil ? nil : TrackEntry(fromPointer: elementPtr!)
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: TrackEntry?) {
        spine_array_track_entry_add(ptr, value?.nativePtr)
    }

    /// Removes all elements from this array
    public func removeAll() {
        spine_array_track_entry_clear(ptr)
    }

    /// Removes the element at the specified index
    public func remove(at index: Int32) {
        precondition(index >= 0 && index < count, "Index out of bounds")
        spine_array_track_entry_remove_at(ptr, index)
    }

    /// Sets the size of this array
    public func resize(to newSize: Int32) {
        spine_array_track_entry_set_size(ptr, newSize, nil)
    }

    /// Ensures the array has at least the specified capacity
    public func ensureCapacity(_ capacity: Int32) {
        spine_array_track_entry_ensure_capacity(ptr, capacity)
    }

    deinit {
        if ownsMemory {
        }
    }
}

/// ArrayUpdate wrapper class
@objc(SpineArrayUpdate)
@objcMembers
public final class ArrayUpdate: NSObject {
    internal let ptr: OpaquePointer
    private let ownsMemory: Bool

    internal init(fromPointer ptr: OpaquePointer, ownsMemory: Bool = false) {
        self.ptr = ptr
        self.ownsMemory = ownsMemory
        super.init()
    }

    /// Create a new empty array
    public convenience init() {
        let ptr = spine_array_update_create()
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    /// Create a new array with the specified initial capacity
    public convenience init(capacity: Int32) {
        let ptr = spine_array_update_create_with_capacity(capacity)
        self.init(fromPointer: ptr, ownsMemory: true)
    }

    public var nativePtr: OpaquePointer { ptr }

    public var count: Int32 {
        return spine_array_update_size(ptr)
    }

    public subscript(index: Int32) -> Update? {
        get {
            precondition(index >= 0 && index < count, "Index out of bounds")
            let buffer = spine_array_update_buffer(ptr)
            let elementPtr = buffer!.assumingMemoryBound(to: OpaquePointer?.self)[Int(index)]
            return elementPtr == nil ? nil : Update(fromPointer: elementPtr!)
        }
    }

    /// Adds a value to the end of this array
    public func add(_ value: Update?) {
        spine_array_update_add(ptr, value?.nativePtr)
    }

    /// Removes all elements from this array
    public func removeAll() {
        spine_array_update_clear(ptr)
    }

    /// Removes the element at the specified index
    public func remove(at index: Int32) {
        precondition(index >= 0 && index < count, "Index out of bounds")
        spine_array_update_remove_at(ptr, index)
    }

    /// Sets the size of this array
    public func resize(to newSize: Int32) {
        spine_array_update_set_size(ptr, newSize, nil)
    }

    /// Ensures the array has at least the specified capacity
    public func ensureCapacity(_ capacity: Int32) {
        spine_array_update_ensure_capacity(ptr, capacity)
    }

    deinit {
        if ownsMemory {
        }
    }
}
