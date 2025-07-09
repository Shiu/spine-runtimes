# Project: Spine Runtimes

Multi-language runtime libraries for Spine 2D skeletal animations. The project provides core runtimes for different programming languages and integrations for various game engines and frameworks.

## Core Runtimes (Language-specific implementations)

### spine-libgdx (Java) - Reference Implementation
- **Build**: `./gradlew build`
- **Publish**: `./gradlew publishToMavenLocal`
- All other runtimes are ports of this reference implementation

### spine-cpp (C++)
- **Build**: `cmake -B build && cmake --build build`
- Port of spine-libgdx
- Uses custom RTTI (no C++ exceptions/RTTI)

### spine-csharp (C#)
- **Build**: `msbuild spine-csharp.csproj` or `dotnet build`
- Port of spine-libgdx
- Targets .NET Framework 4.8

### spine-ts (TypeScript/JavaScript)
- **Build**: `npm install && npm run build`
- **Dev**: `npm run dev`
- Port of spine-libgdx
- Core module at spine-ts/spine-core/

### spine-haxe (Haxe)
- **Build**: `./build.sh`
- Port of spine-libgdx
- Uses Haxelib package manager

### spine-c (C)
- **Build**: `cmake -B build && cmake --build build`
- Actively maintained C implementation
- Different structure from other runtimes due to C language constraints

## Integration Runtimes (Engine/Framework-specific)

### Using spine-cpp:
- **spine-cocos2dx** - Cocos2d-x engine
- **spine-flutter** - Flutter (via spine-cpp-lite C wrapper + Dart FFI)
- **spine-glfw** - GLFW/OpenGL example
- **spine-godot** - Godot Engine
- **spine-ios** - iOS native (via spine-cpp-lite C wrapper + Swift codegen)
- **spine-sdl** - SDL (optional, can use spine-c)
- **spine-sfml/cpp** - SFML C++ version
- **spine-ue** - Unreal Engine 4.27-5.4

### Using spine-csharp:
- **spine-unity** - Unity game engine
- **spine-monogame** - MonoGame framework
- **spine-xna** - XNA Framework (legacy)

### Using spine-libgdx:
- **spine-android** - Android native

### Using spine-c:
- **spine-sdl** - SDL (optional, can use spine-cpp)
- **spine-sfml/c** - SFML C version

### Using spine-core (TypeScript):
- **spine-canvas** - HTML5 Canvas
- **spine-webgl** - Direct WebGL
- **spine-phaser** - Phaser.js (v3 & v4)
- **spine-pixi** - PixiJS (v7 & v8)
- **spine-threejs** - Three.js
- **spine-player** - Embeddable web player
- **spine-canvaskit** - Skia CanvasKit
- **spine-webcomponents** - Web Components

## Special Cases

### spine-cpp-lite
- C wrapper around spine-cpp for FFI-friendly bindings
- Located in spine-cpp/spine-cpp-lite/
- Provides simplified C API consumed by:
  - spine-flutter (via Dart FFI)
  - spine-ios (via Swift code generation)

## Commands Summary
- **Check spine-cpp**: `cd spine-cpp && cmake -B build && cmake --build build`
- **Check spine-ts**: `cd spine-ts && npm install && npm run build`
- **Check spine-libgdx**: `cd spine-libgdx && ./gradlew build`
- **Check spine-csharp**: `cd spine-csharp && msbuild spine-csharp.csproj`
- **Check spine-c**: `cd spine-c && cmake -B build && cmake --build build`

## Development Workflow
- All changes start in spine-libgdx (reference implementation)
- Port changes to other core runtimes using git diffs
- Integration runtimes automatically inherit changes from their core runtime

## Type System Documentation
For a complete reference of all types in the Spine runtime, see [spine-runtimes-types.md](spine-runtimes-types.md).
To regenerate this documentation, run: `node docs/generate-type-hierarchy.js`

## Spine Type System Overview (from spine-libgdx)

### Core Types
- **Skeleton** - Stores the current pose for a skeleton
- **SkeletonData** - Stores setup pose and stateless data
- **Bone/BoneData** - Current pose and setup data for bones
- **Slot/SlotData** - Manages attachments and drawing order
- **Skin** - Collection of attachments keyed by slot and name

### Animation System
- **Animation** - List of timelines to animate skeleton pose
- **AnimationState** - Applies animations, handles mixing and layering
- **AnimationStateData** - Stores mix (crossfade) durations

### Attachment Types (Visual Elements)
- **Attachment** - Base class for all attachments
- **RegionAttachment** - Textured quadrilateral
- **MeshAttachment** - Textured mesh with vertices
- **BoundingBoxAttachment** - Polygon for hit detection
- **ClippingAttachment** - Polygon for clipping rendering
- **PathAttachment** - Composite Bezier curve
- **PointAttachment** - Single point with rotation
- **SkeletonAttachment** - Nested skeleton

### Constraint Types
- **IkConstraint** - Inverse kinematics (1-2 bones)
- **TransformConstraint** - Copy/mix transform from target
- **PathConstraint** - Follow path attachment
- **PhysicsConstraint** - Apply physics simulation

### Pose System (new in 4.2+)
- **Pose** - Interface for pose data
- **BoneLocal/BonePose** - Local and world bone transforms
- **Update** - Interface for updateable elements
- **PosedActive/PosedData** - Base classes for runtime/setup data

### Other Core Types
- **Event/EventData** - Animation events system
- **Sequence** - Frame-by-frame texture sequences
- **SkeletonBounds** - Hit detection utilities
- **SkeletonLoader** - Base for JSON/Binary loaders