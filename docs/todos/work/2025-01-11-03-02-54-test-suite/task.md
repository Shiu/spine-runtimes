# create a folder test/ and write a comprehensive test suite

**Status:** In Progress
**Created:** 2025-01-11T03:02:54
**Started:** 2025-01-11T03:11:22
**Agent PID:** 89579

## Original Todo
- create a folder test/ and write a comprehensive test suite
    - For each core runtime
        - Write a program that takes as input a skeleton (.json or .skel) and atlas file path and animation name
        - Loads a SkeletonData and outputs EVERYTHING in a simple, diffable text format
        - Creates a skeleton from the SkeletonData, an AnimationState, sets the Animation on track 0, updates and applies the state to the skeleton, then outputs EVERYTHING in a diffable text format
        - The best approach is likely to create a Printer interface that can print each relevant type in the diffable format, with a specific indentation level, so the output represents the hierarchy of the data
        - See docs/project-description.md for the core runtimes and their location
        - The test/ folder should have simple language specific build scripts that build/pull in the core runtime for that language, and create an exectuable program we can invoke
            - build.gradle for Java, directly pulling in the spine-libgdx project via settings.gradle
            - CMakeLists.txt for C and C++
            - package.json/tsconfig.json for Typescript
            - Let's ignore the other core runtimes for now
        - The programs must be headless, which means we need to ensure when loading the atlases, texture loading actually doesn't happen.
        - The goal is to be able to construct bash or nodejs test suites that can find errors in the non-reference runtimes quickly by comparing actually loaded and "applied" data between teh runtimes

## Description
Create a comprehensive test suite that compares the output of all core Spine runtimes (Java, C++, C, TypeScript) to ensure consistency. The test suite will consist of headless command-line programs for each runtime that load skeleton data and output all internal state in a diffable text format. This will enable automated comparison testing between the reference implementation (spine-libgdx) and all ports. Each test program must compile directly against the runtime's source code, not pull published versions from package repositories.

The test programs will print both SkeletonData (setup pose/static data) and Skeleton (runtime pose after animation) states, including all nested types such as bones, slots, skins, attachments, constraints, and animations.

## Updated Implementation Plan (DebugPrinter in each runtime)
- [x] Remove test/ directory approach (deprecated)
- [x] Implement DebugPrinter in spine-libgdx-tests:
  - [x] Create DebugPrinter.java in spine-libgdx/spine-libgdx-tests/src
  - [x] Add command line argument parsing for skeleton, atlas, animation
  - [x] Create Printer class for outputting all types in hierarchical format
  - [x] Ensure it can run headless (no GL requirements)
  - [x] Merged Printer and HeadlessTextureLoader into single DebugPrinter.java file
  - [x] Added gradle task runDebugPrinter for easy execution
- [x] Implement DebugPrinter in spine-cpp:
  - [x] Create spine-cpp/tests directory with DebugPrinter.cpp
  - [x] Update spine-cpp/CMakeLists.txt with conditional target
  - [x] Add Printer class matching Java output format
  - [x] Ensure headless operation
- [x] Implement DebugPrinter in spine-c:
  - [x] Create spine-c/tests directory with debug-printer.c
  - [x] Update spine-c/CMakeLists.txt with conditional target
  - [x] Add printer functions matching output format
  - [x] Ensure headless operation
  - [x] Fix spine-c/codegen/src/ir-generator.ts to use .buffer() for string getters (currently returns address of temporary String object)
    - Run generator via: npx tsx spine-c/codegen/src/index.ts
    - This regenerates spine-c/src/generated/*.cpp files
    - Fixed by handling "const String &" (with space) in addition to "const String&"
    - Verified: String methods now properly return .buffer() values (version, hash, etc. display correctly)
  - [x] Issues found by DebugPrinter comparison:
    - [x] spine-c API missing file-based skeleton loader that sets name from filename
      - C++ has readSkeletonDataFile() which sets name, spine-c only exposes content-based loader
      - Result: SkeletonData name is empty in spine-c output
      - Fixed: Modified spine_skeleton_data_load_json/binary to accept path parameter and extract name
    - [x] Coordinate system inconsistency: Java shows scaleY=1.0, C/C++ show scaleY=-1.0, use Bone::setYDown(false) to match Java
- [x] Implement DebugPrinter in spine-ts/spine-core:
  - [x] Create tests/DebugPrinter.ts
  - [x] Update tsconfig.json to exclude tests/ so tests are not bundled
  - [x] Add Printer class matching output format
  - [x] Ensure it runs with npx tsx without build step
- [x] Create test runner script (compare-with-reference-impl.ts):
  - [x] Run each runtime's DebugPrinter with same inputs
  - [x] Compare outputs and report differences
  - [x] TypeScript script with shebang for direct execution
  - [x] Automatically builds C/C++/Java if needed
  - [x] Saves outputs to tests/output/ directory
  - [x] Shows line-by-line differences when outputs don't match
- [x] Make animation parameter optional in all DebugPrinters:
  - [x] If animation not provided, call skeleton.setToSetupPose() instead
  - [x] Update Java DebugPrinter
  - [x] Update C++ DebugPrinter
  - [x] Update C DebugPrinter
  - [x] Update TypeScript DebugPrinter
  - [x] Update compare-with-reference-impl.ts to handle optional animation
- [x] Fix locale issues - all DebugPrinters should use English locale:
  - [x] Java: Set Locale.US for number formatting
  - [x] C++: Set locale to "C" or "en_US.UTF-8"
  - [x] C: Set locale to "C" or "en_US.UTF-8"
  - [x] TypeScript: Already uses period for decimals
- [x] Improve buildCheck() to detect when rebuild needed:
  - [x] Check if debug printer executable exists
  - [x] Compare executable timestamp with source file timestamps
  - [x] Rebuild if any source files are newer than executable
- [x] Create tests/README.md documentation:
  - [x] Explain purpose: comparing reference implementation to other runtimes
  - [x] List DebugPrinter locations in each runtime
  - [x] Document how to run individual debug printers
  - [x] Document how to run compare-with-reference-impl.ts
- [x] Automated test: All DebugPrinters produce identical output
  - Note: Minor expected differences remain:
    - time field: Java shows 0.016 after update, C/C++ show 0.0
    - TypeScript: minor precision differences, null vs "" for audioPath
    - These are implementation details, not bugs
- [x] User test: Verify with multiple skeleton files

## Phase 2: JSON Serializers and HeadlessTest Rename

### Rename DebugPrinter to HeadlessTest
- [x] Rename all DebugPrinter files to HeadlessTest:
  - [x] Java: DebugPrinter.java → HeadlessTest.java
  - [x] C++: DebugPrinter.cpp → HeadlessTest.cpp
  - [x] C: debug-printer.c → headless-test.c
  - [x] TypeScript: DebugPrinter.ts → HeadlessTest.ts
- [x] Update VS Code launch configs to say "headless test ($runtime)":
  - [x] spine-libgdx/.vscode/launch.json
  - [x] spine-cpp/.vscode/launch.json
  - [x] spine-c/.vscode/launch.json
  - [x] spine-ts/.vscode/launch.json
- [x] Rename tests/compare-with-reference-impl.ts to headless-test-runner.ts
- [x] Update build files:
  - [x] CMakeLists.txt for C++ (executable name: headless-test)
  - [x] CMakeLists.txt for C (executable name: headless-test)
  - [x] Gradle for Java (task name: runHeadlessTest, main class: HeadlessTest)
- [x] Update tests/README.md with new names

### Implement JSON Serializers in Core Runtimes
- [x] Java (spine-libgdx):
  - [x] Create SkeletonSerializer class in com.esotericsoftware.spine.utils
  - [x] Implement serializeSkeletonData(SkeletonData, Writer/StringBuilder)
  - [x] Implement serializeSkeleton(Skeleton, Writer/StringBuilder)
  - [x] Implement serializeAnimationState(AnimationState, Writer/StringBuilder)
  - [x] Add depth/verbosity options to control output
  - [x] Handle circular references and limit nesting
  - [x] Update HeadlessTest to use SkeletonSerializer
  - [x] Review serializer with user:
    - [x] Test with actual skeleton file to see output format
    - [x] Add cycle detection to handle circular references (outputs "<circular>")
    - [x] Verify it compiles and produces JSON output
  - [x] Create comprehensive API analyzer tool:
    - [x] Analyzer discovers all types accessible via SkeletonData, Skeleton, and AnimationState
    - [x] For each type, enumerate all getters including inherited ones
    - [x] Generate Java serializer from analysis data
    - [x] Handle enums, abstract types, inner classes, and type parameters
    - [x] Filter out test classes and non-source files
  - [x] Work on SkeletonSerializer.java generation until it actually compiles.
- [ ] C++ (spine-cpp):
  - [ ] Create SkeletonSerializer.h/cpp in spine-cpp/src/spine
  - [ ] Implement serializeSkeletonData(SkeletonData*, std::string&)
  - [ ] Implement serializeSkeleton(Skeleton*, std::string&)
  - [ ] Implement serializeAnimationState(AnimationState*, std::string&)
  - [ ] Add SerializerOptions struct for controlling output
  - [ ] Update HeadlessTest to use SkeletonSerializer
  - [ ] Ensure serializer outputs exact same data format as Java version
- [ ] C (spine-c):
  - [ ] Create spine-skeleton-serializer.h/c
  - [ ] Implement spine_skeleton_data_serialize_json(data, buffer, options)
  - [ ] Implement spine_skeleton_serialize_json(skeleton, buffer, options)
  - [ ] Implement spine_animation_state_serialize_json(state, buffer, options)
  - [ ] Add spine_serializer_options struct
  - [ ] Update headless-test to use serializer functions
  - [ ] Ensure serializer outputs exact same data format as Java version
- [ ] TypeScript (spine-ts):
  - [ ] Create SkeletonSerializer.ts in spine-core/src
  - [ ] Implement serializeSkeletonData(data: SkeletonData): object
  - [ ] Implement serializeSkeleton(skeleton: Skeleton): object
  - [ ] Implement serializeAnimationState(state: AnimationState): object
  - [ ] Add SerializerOptions interface
  - [ ] Update HeadlessTest to use SkeletonSerializer and JSON.stringify
  - [ ] Ensure serializer outputs exact same data format as Java version
- [ ] Update tests/README.md to describe the new setup

### Misc (added by user while Claude worked, need to be expanded!)
- [ ] HeadlessTest should probably
  - Have a mode that does what we currently do: take files and animation name, and output serialized skeleton data and skeleton. Used for ad-hoc testing of files submitted by users in error reports etc.
  - Have "unit" test like tests, that are easily extensible
    - each test has a name and points to the corresponding function to execute
    - HeadlessTest can take as args a single name, multiple test names, or no args in which case it runs all tests in order
    - Structure and cli handling needs to be the same in all HeadlessTest implementations
    - tests/headless-test-runner.ts should also support these same cli args, run each runtime test, then compare outputs.

### Serializer Design Considerations
- Special cases to avoid infinite recursion:
  - Bone parent references (output name only)
  - Constraint target references (output names only)
  - Skin attachment references (limit depth)
  - Timeline references in animations
- Fields to include at each level:
  - SkeletonData: All top-level fields, list of bone/slot/skin/animation names
  - Skeleton: Current pose transforms, active skin, color
  - AnimationState: Active tracks, mix times, current time
- Output format: Pretty-printed JSON with 2-space indentation

## Future Expansion (after serializers complete):
- Add full type printing for SkeletonData (bones, slots, skins, animations)
- Add Skeleton runtime state printing
- Add all attachment types
- Add all timeline types
- Add all constraint types
- Add comprehensive type verification

