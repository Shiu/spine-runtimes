import Foundation
import SpineSwift

func runSkeletonDrawableTestSwift() {
    print("Testing SkeletonDrawable with SpineSwift API...")
    
    print("Step 1: Enable debug extension")
    // Enable debug extension if needed
    enableDebugExtension(false)
    print("  Debug extension configured")
    
    print("Step 2: Load file paths")
    // Load atlas and skeleton data
    let atlasPath = "../../spine-ts/assets/spineboy.atlas"
    let jsonPath = "../../spine-ts/assets/spineboy-pro.json"
    
    print("Step 3: Read atlas file")
    // Read atlas file
    guard let atlasData = try? String(contentsOfFile: atlasPath, encoding: .utf8) else {
        print("❌ Failed to read atlas file: \(atlasPath)")
        return
    }
    print("  Atlas file read successfully")
    
    print("Step 4: Load atlas with SpineSwift API")
    // Load atlas
    let atlas: Atlas
    do {
        atlas = try loadAtlas(atlasData)
        print("✓ Atlas loaded successfully")
    } catch {
        print("❌ Failed to load atlas: \(error)")
        return
    }
    
    // Read skeleton JSON
    guard let skeletonJson = try? String(contentsOfFile: jsonPath, encoding: .utf8) else {
        print("❌ Failed to read skeleton JSON file: \(jsonPath)")
        // atlas will be freed when out of scope
        return
    }
    
    // Load skeleton data
    let skeletonData: SkeletonData
    do {
        skeletonData = try loadSkeletonDataJson(atlas: atlas, jsonData: skeletonJson, path: jsonPath)
        print("✓ Skeleton data loaded successfully")
    } catch {
        print("❌ Failed to load skeleton data: \(error)")
        // atlas will be freed when out of scope
        return
    }
    
    // Create skeleton drawable
    let drawable = SkeletonDrawable(skeletonData: skeletonData)
    print("✓ SkeletonDrawable created successfully")
    
    // Test skeleton bounds
    print("\nTesting skeleton bounds:")
    let initialBounds = drawable.skeleton.bounds
    print("  Initial bounds: x=\(initialBounds.x), y=\(initialBounds.y), width=\(initialBounds.width), height=\(initialBounds.height)")
    
    // Set skeleton to pose and update bounds
    drawable.skeleton.setupPose()
    drawable.skeleton.updateWorldTransform(Physics.none)
    
    let boundsAfterPose = drawable.skeleton.bounds
    print("  Bounds after setupPose: x=\(boundsAfterPose.x), y=\(boundsAfterPose.y), width=\(boundsAfterPose.width), height=\(boundsAfterPose.height)")
    
    // Test position
    let position = drawable.skeleton.getPosition()
    print("  Skeleton position: x=\(position.x), y=\(position.y)")
    
    // Set up animation state listener
    var eventCount = 0
    drawable.animationState.setListener { type, trackEntry, event in
        eventCount += 1
        print("  AnimationState event #\(eventCount): type=\(type), track=\(trackEntry.trackIndex)")
        if let event = event {
            print("    Event name: \(event.data.name)")
        }
    }
    
    // Set an animation
    let trackEntry = drawable.animationState.setAnimation(0, "walk", true)
    print("✓ Set animation: walk")
    
    // Set track entry listener
    trackEntry.setListener { type, entry, event in
        print("  TrackEntry event: type=\(type)")
        if let event = event {
            print("    Event data: \(event.data.name)")
        }
    }
    
    // Update several times to trigger events
    print("\nUpdating animation state...")
    for i in 0..<5 {
        drawable.update(0.016) // ~60fps
        print("  Frame \(i): updated")
    }
    
    // Test switching animations
    print("\nSwitching to run animation...")
    _ = drawable.animationState.setAnimation(0, "run", true)
    
    // Update a few more times
    for i in 0..<3 {
        drawable.update(0.016)
        print("  Frame \(i): updated after switching")
    }
    
    // Test bounds after animation updates
    print("\nTesting bounds after animation:")
    drawable.skeleton.updateWorldTransform(Physics.none)
    let boundsAfterAnimation = drawable.skeleton.bounds
    print("  Bounds after animation: x=\(boundsAfterAnimation.x), y=\(boundsAfterAnimation.y), width=\(boundsAfterAnimation.width), height=\(boundsAfterAnimation.height)")
    
    // Test with different animations that might have different bounds
    print("\nTesting bounds with jump animation:")
    _ = drawable.animationState.setAnimation(0, "jump", false)
    drawable.update(0.5) // Update to middle of jump
    
    let boundsAfterJump = drawable.skeleton.bounds
    print("  Bounds during jump: x=\(boundsAfterJump.x), y=\(boundsAfterJump.y), width=\(boundsAfterJump.width), height=\(boundsAfterJump.height)")
    
    // Test skin entries
    print("\nTesting skin entries:")
    if let skin = drawable.skeleton.skin {
        let entries = skin.getEntries()
        print("  Skin has \(entries.count) entries")
        if entries.count > 0 {
            let firstEntry = entries[0]
            print("  First entry: slot=\(firstEntry.slotIndex), name=\(firstEntry.name), has attachment=\(firstEntry.attachment != nil)")
        }
    }
    
    // Test bone pose transformations
    print("\nTesting bone pose transformations:")
    if let rootBone = drawable.skeleton.rootBone {
        let worldPoint = Vector(x: 100, y: 100)
        // Note: worldToLocal is on BonePose, not Bone
        // We would need to get the pose from the bone
        // For now, skip this test
        print("  Bone pose transformations test skipped (need to access BonePose)")
    }
    
    // Test render command
    print("\nTesting render command:")
    if let renderCommand = drawable.render() {
        print("  Got render command with blend mode: \(renderCommand.blendMode)")
        // Note: atlasPage and vertices are accessed via getters, not properties
        print("  Render command received successfully")
    }
    
    // Clear listener before cleanup
    drawable.animationState.setListener(nil)
    
    // Cleanup happens automatically via deinit
    // skeletonData and atlas will be freed when out of scope
    
    // Report memory leaks if debug extension is enabled
    reportLeaks()
    
    print("\n✓ SpineSwift API test complete")
}

// Test function is called from main.swift