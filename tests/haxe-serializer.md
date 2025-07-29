# Haxe Serializer: Java Getter to Haxe Field/Method Mapping Analysis

## Overview

This document contains a comprehensive analysis of ALL patterns for transforming Java getter calls into appropriate Haxe field/method access, extracted from the java-haxe-diff.md file.

## General Patterns

### 1. Simple Field Access Pattern (Most Common)
Java getter `getX()` maps to Haxe field `x:Type`

**Examples:**
- `getName()` → `name:String`
- `getDuration()` → `duration:Float`
- `getTimeScale()` → `timeScale:Float`
- `getLoop()` → `loop:Bool`
- `getX()` → `x:Float`
- `getY()` → `y:Float`
- `getRotation()` → `rotation:Float`
- `getScaleX()` → `scaleX:Float`
- `getScaleY()` → `scaleY:Float`
- `getShearX()` → `shearX:Float`
- `getShearY()` → `shearY:Float`
- `getWidth()` → `width:Float`
- `getHeight()` → `height:Float`
- `getColor()` → `color:Color`
- `getAlpha()` → `alpha:Float`
- `getMix()` → `mix:Float`
- `getVisible()` → `visible:Bool`
- `getIndex()` → `index:Int`

### 2. Array Field Access Pattern
Java getter `getX()` returns array → Haxe field `x:Array<Type>`

**Examples:**
- `getTimelines()` → `timelines:Array<Timeline>`
- `getBones()` → `bones:Array<Int>` or `bones:Array<BoneData>` or `bones:Array<BonePose>` (context-dependent)
- `getChildren()` → `children:Array<Bone>`
- `getFrames()` → `frames:Array<Float>`
- `getAttachmentNames()` → `attachmentNames:Array<String>`
- `getVertices()` → `vertices:Array<Float>` or `vertices:Array<Array<Float>>` (context-dependent)
- `getEvents()` → `events:Array<Event>`
- `getDrawOrders()` → `drawOrders:Array<Array<Int>>`
- `getSlots()` → `slots:Array<Slot>` or `slots:Array<SlotData>` (context-dependent)
- `getTracks()` → `tracks:Array<TrackEntry>`
- `getTriangles()` → `triangles:Array<Int>`
- `getUVs()` → `uvs:Array<Float>`
- `getRegionUVs()` → `regionUVs:Array<Float>`
- `getEdges()` → `edges:Array<Int>`
- `getLengths()` → `lengths:Array<Float>`
- `getRegions()` → `regions:Array<TextureRegion>`
- `getAnimations()` → `animations:Array<Animation>`
- `getSkins()` → `skins:Array<Skin>`
- `getConstraints()` → `constraints:Array<Constraint<Dynamic, Dynamic, Dynamic>>` or `constraints:Array<ConstraintData<Dynamic, Dynamic>>`
- `getPhysicsConstraints()` → `physics:Array<PhysicsConstraint>`
- `getProperties()` → `properties:Array<FromProperty>`
- `getDeform()` → `deform:Array<Float>`

### 3. Method Remains Method Pattern
Some getters remain as methods in Haxe, typically those that perform calculations or have side effects.

**Examples:**
- `getFrameCount()` → `getFrameCount():Int`
- `getFrameEntries()` → `getFrameEntries():Int`
- `getDuration()` → `getDuration():Float` (in Timeline classes)
- `getSlotIndex()` → `getSlotIndex():Int`
- `getBoneIndex()` → `getBoneIndex():Int`
- `getConstraintIndex()` → `getConstraintIndex():Int`
- `getData()` → `getData():T` (where T is the data type)
- `getPose()` → `getPose():T` (where T is the pose type)
- `getAppliedPose()` → `getAppliedPose():T`
- `getSetupPose()` → `getSetupPose():T`
- `getAnimationTime()` → `getAnimationTime():Float`
- `getTrackComplete()` → `getTrackComplete():Float`
- `getWorldRotationX()` → `getWorldRotationX():Float`
- `getWorldRotationY()` → `getWorldRotationY():Float`
- `getWorldScaleX()` → `getWorldScaleX():Float`
- `getWorldScaleY()` → `getWorldScaleY():Float`
- `getAttachments()` → `getAttachments():Array<SkinEntry>`
- `getOffsetRotation()` → `getOffsetRotation():Float`
- `getOffsetX()` → `getOffsetX():Float`
- `getOffsetY()` → `getOffsetY():Float`
- `getOffsetScaleX()` → `getOffsetScaleX():Float`
- `getOffsetScaleY()` → `getOffsetScaleY():Float`
- `getOffsetShearY()` → `getOffsetShearY():Float`

### 4. Special Property Access Pattern
Some properties use Haxe's property syntax with get/set accessors.

**Examples:**
- `getName()` → `name(get, never):String` (in Attachment subclasses)
- `getRootBone()` → `rootBone(get, never):Bone`
- `getScaleY()` → `scaleY(get, default):Float` (in Skeleton)

### 5. Field Name Variations
Some getters have slight variations in their Haxe field names.

**Examples:**
- `getInt()` → `intValue:Int`
- `getFloat()` → `floatValue:Float`
- `getString()` → `stringValue:String`
- `getUpdateCache()` → `_updateCache:Array<Dynamic>` (with underscore prefix)
- `getPropertyIds()` → `propertyIds:Array<String>`
- `getDefaultSkin()` → `defaultSkin:Skin`

### 6. Type Reference Patterns
Getters that reference other objects.

**Examples:**
- `getParent()` → `parent:Bone` or `parent:BoneData` (context-dependent)
- `getTarget()` → `target:Bone` or `target:BoneData` (context-dependent)
- `getSource()` → `source:Bone` or `source:BoneData` (context-dependent)
- `getAttachment()` → `attachment:Attachment` or `attachment:VertexAttachment` (context-dependent)
- `getSlot()` → `slot:Slot` or `slot:SlotData` (context-dependent)
- `getBone()` → `bone:Bone` or `bone:BoneData` or `bone:BonePose` (context-dependent)
- `getSkin()` → `skin:Skin`
- `getAnimation()` → `animation:Animation`
- `getRegion()` → `region:TextureRegion`
- `getSequence()` → `sequence:Sequence`
- `getParentMesh()` → `parentMesh:MeshAttachment`
- `getEndSlot()` → `endSlot:SlotData`

## Context-Dependent Mappings

### 1. `getBones()` mapping depends on containing class:
- In `Animation`: → `bones:Array<Int>`
- In `BoneData`, `IkConstraintData`, `PathConstraintData`, `TransformConstraintData`, `Skin`: → `bones:Array<BoneData>`
- In `IkConstraint`, `PathConstraint`, `TransformConstraint`: → `bones:Array<BonePose>`
- In `BoundingBoxAttachment`, `ClippingAttachment`, `MeshAttachment`, `PathAttachment`, `VertexAttachment`: → `bones:Array<Int>`

### 2. `getVertices()` mapping depends on containing class:
- In `DeformTimeline`: → `vertices:Array<Array<Float>>` (2D array)
- In `ClippingAttachment`, `MeshAttachment`, `PathAttachment`, `VertexAttachment`: → `vertices:Array<Float>` (1D array)

### 3. `getDuration()` mapping depends on containing class:
- In `Animation`: → `duration:Float` (field)
- In Timeline classes: → `getDuration():Float` (method)

### 4. Special Cases in Timeline Classes:
All Timeline subclasses have these getters as methods:
- `getFrameCount()` → `getFrameCount():Int`
- `getFrameEntries()` → `getFrameEntries():Int`
- `getDuration()` → `getDuration():Float`
- `getPropertyIds()` → `propertyIds:Array<String>` (field)
- `getFrames()` → `frames:Array<Float>` (field)

### 5. Special Cases in Constraint Classes:
- `getData()` → `getData():T` (method returning specific data type)
- `getPose()` → `getPose():T` (method returning specific pose type)
- `getAppliedPose()` → `getAppliedPose():T` (method returning specific pose type)

## Type Transformations

### Java to Haxe Type Mappings:
- `int` → `Int`
- `float` → `Float`
- `double` → `Float`
- `boolean` → `Bool`
- `String` → `String`
- `Array`/`List` → `Array<T>`
- `IntArray` → `Array<Int>` (custom type)
- Object types remain the same (e.g., `Color` → `Color`)

## Special Edge Cases

### 1. Incomplete Mappings (marked as TODO in the file):
- `BonePose.getInherit()` → TODO
- `BoundingBoxAttachment.getVertices()` → TODO
- `BoundingBoxAttachment.getWorldVerticesLength()` → TODO
- `BoundingBoxAttachment.getTimelineAttachment()` → TODO
- `BoundingBoxAttachment.getId()` → TODO
- `BoundingBoxAttachment.getName()` → TODO

### 2. Inherited Methods:
Some getters are inherited from parent classes and noted as such:
- `getName()` in attachment classes inherits from `Attachment`
- Properties in `FromRotate`, `FromScaleX`, etc. inherit from `FromProperty`
- Properties in constraint data classes inherit from `PosedData`

### 3. Special Skeleton Fields:
- `getUpdateCache()` → `_updateCache:Array<Dynamic>` (private with underscore)
- `getRootBone()` → `rootBone(get, never):Bone` (computed property)
- `getScaleY()` → `scaleY(get, default):Float` (property with default)

### 4. DrawOrderTimeline Exception:
- `getFrameCount()` → `frameCount:Int` (field instead of method, unlike other timelines)

### 5. Enum and Constant Mappings:
- `getBlendMode()` → `blendMode:BlendMode`
- `getPositionMode()` → `positionMode:PositionMode`
- `getSpacingMode()` → `spacingMode:SpacingMode`
- `getRotateMode()` → `rotateMode:RotateMode`
- `getMixBlend()` → `mixBlend:MixBlend`
- `getInherit()` → `inherit:Inherit`

## Summary

The transformation rules can be categorized as:

1. **Default Rule**: `getX()` → `x:Type` (lowercase first letter, remove get prefix)
2. **Method Preservation**: Keep as method for calculated values or methods with side effects
3. **Special Properties**: Use Haxe property syntax for computed/readonly properties
4. **Context Awareness**: Same getter can map differently based on containing class
5. **Type Transformation**: Java primitive types map to Haxe equivalents
6. **Special Cases**: Some fields have custom names (e.g., `getInt()` → `intValue`)

When implementing the Haxe serializer generator, these patterns should be applied in order of specificity:
1. Check for exact class + getter combinations first
2. Check for class-specific patterns (e.g., all Timeline getters)
3. Apply general transformation rules
4. Handle special cases and exceptions

---

# Haxe Serializer Generator Implementation Plan

Based on the comprehensive pattern analysis above, here's the implementation plan for a new Haxe serializer generator:

## Architecture Overview

The new generator will use a **rule-based transformation system** with the following components:

1. **Mapping Database**: Load java-haxe-diff.md mappings into a structured lookup table
2. **Context-Aware Transformer**: Apply transformations based on class context
3. **Type System**: Handle Java-to-Haxe type conversions
4. **Code Generator**: Produce clean, idiomatic Haxe code

## Implementation Steps

### Phase 1: Build Mapping Infrastructure

1. **Parse java-haxe-diff.md**
   - Extract all type mappings into a structured format
   - Create lookup table: `Map<ClassName, Map<JavaGetter, HaxeMapping>>`
   - Store mapping type (field, method, property) and Haxe type info

2. **Create Transformation Rules Engine**
   - Rule priority system (specific → general)
   - Context-aware lookups (class + getter combination)
   - Fallback to general patterns

### Phase 2: Implement Core Transformations

1. **Getter-to-Field Transformer**
   - Check mapping database first
   - Apply general pattern: `getX()` → `x`
   - Handle special cases (getInt → intValue, etc.)

2. **Type Transformer**
   - Java primitives → Haxe types
   - Array handling (including nested arrays)
   - Generic type resolution

3. **Access Pattern Resolver**
   - Determine if result is field access or method call
   - Handle property syntax `name(get, never)`
   - Preserve method calls where needed

### Phase 3: Code Generation

1. **Property Code Generator**
   - Generate correct Haxe syntax based on mapping type
   - Handle nullable types properly
   - Generate enum switch statements with correct Haxe enum syntax

2. **Method Generator**
   - Handle abstract types with `Std.isOfType`
   - Generate proper casting syntax
   - Implement special methods (writeSkin, writeSkinEntry)

### Phase 4: Validation and Testing

1. **Compile-time Validation**
   - Generate code and attempt Haxe compilation
   - Report type errors with context

2. **Runtime Testing**
   - Compare serialization output with Java reference
   - Ensure all fields are properly serialized

## Key Design Decisions

1. **Data-Driven Approach**: Use the mapping file as the source of truth rather than hardcoded rules
2. **Explicit Over Implicit**: When in doubt, use the exact mapping from java-haxe-diff.md
3. **Fail-Fast**: If a mapping is missing or ambiguous, fail with a clear error message
4. **Type Safety**: Leverage Haxe's type system to catch errors at compile time

## Implementation Details

### Mapping Database Structure
```typescript
interface HaxeMapping {
  kind: 'field' | 'method' | 'property';
  haxeName: string;
  haxeType: string;
  propertyGetter?: string; // for (get, never) syntax
}

interface ClassMappings {
  className: string;
  getters: Map<string, HaxeMapping>;
}
```

### Transformation Algorithm
```
1. Load all mappings from java-haxe-diff.md
2. For each property in IR:
   a. Look up exact class + getter combination
   b. If not found, check for class-level patterns
   c. If not found, apply general transformation rules
   d. Transform type from Java to Haxe
   e. Generate appropriate access code
```

### Special Handling

1. **Timeline Classes**: All timeline getters follow consistent patterns
2. **Constraint Classes**: Handle getData/getPose/getAppliedPose consistently
3. **Array Properties**: Detect 1D vs 2D arrays based on context
4. **Enum Values**: Generate proper Haxe enum access syntax
5. **Circular References**: Maintain visitedObjects tracking

## Error Handling

1. **Missing Mappings**: Log unmapped getters with class context
2. **Type Mismatches**: Detect and report Java/Haxe type incompatibilities
3. **Compilation Errors**: Capture and display Haxe compiler output

## Testing Strategy

1. **Unit Tests**: Test individual transformation rules
2. **Integration Tests**: Generate full serializer and compile
3. **Snapshot Tests**: Compare output with reference implementation

This approach ensures accuracy, maintainability, and extensibility while leveraging the comprehensive mapping data we've collected.