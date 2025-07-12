# Spine Runtimes Test Suite

This test suite is designed to ensure consistency across all Spine runtime implementations by comparing their outputs against the reference implementation (spine-libgdx).

## Purpose

Unlike traditional unit tests, this test suite:
- Loads skeleton data and animations in each runtime
- Outputs all internal state in a consistent, diffable text format
- Compares outputs between runtimes to detect discrepancies
- Helps maintain consistency when porting changes from the reference implementation

## HeadlessTest Locations

Each runtime has a HeadlessTest program that outputs skeleton data in a standardized format:

- **Java (Reference)**: `spine-libgdx/spine-libgdx-tests/src/com/esotericsoftware/spine/HeadlessTest.java`
- **C++**: `spine-cpp/tests/HeadlessTest.cpp`
- **C**: `spine-c/tests/headless-test.c`
- **TypeScript**: `spine-ts/spine-core/tests/HeadlessTest.ts`

## Running Individual HeadlessTests

### Java (spine-libgdx)
```bash
cd spine-libgdx
./gradlew :spine-libgdx-tests:runHeadlessTest -Pargs="<skeleton-path> <atlas-path> [animation-name]"

# Example with spineboy:
./gradlew :spine-libgdx-tests:runHeadlessTest -Pargs="../examples/spineboy/export/spineboy-pro.json ../examples/spineboy/export/spineboy.atlas walk"
```

### C++ (spine-cpp)
```bash
cd spine-cpp
./build.sh  # Build if needed
./build/headless-test <skeleton-path> <atlas-path> [animation-name]

# Example with spineboy:
./build/headless-test ../examples/spineboy/export/spineboy-pro.json ../examples/spineboy/export/spineboy.atlas walk
```

### C (spine-c)
```bash
cd spine-c
./build.sh  # Build if needed
./build/headless-test <skeleton-path> <atlas-path> [animation-name]

# Example with spineboy:
./build/headless-test ../examples/spineboy/export/spineboy-pro.json ../examples/spineboy/export/spineboy.atlas walk
```

### TypeScript (spine-ts)
```bash
cd spine-ts/spine-core
npx tsx tests/HeadlessTest.ts <skeleton-path> <atlas-path> [animation-name]

# Example with spineboy:
npx tsx tests/HeadlessTest.ts ../../examples/spineboy/export/spineboy-pro.json ../../examples/spineboy/export/spineboy.atlas walk
```

## Running the Comparison Test

The main test runner compares all runtime outputs automatically:

```bash
./tests/headless-test-runner.ts <skeleton-path> <atlas-path> [animation-name]
```

This script will:
1. Check if each runtime's HeadlessTest needs rebuilding
2. Build any out-of-date HeadlessTests
3. Run each HeadlessTest with the same inputs
4. Compare outputs and report any differences
5. Save individual outputs to `tests/output/` for manual inspection

### Example Usage

```bash
# Test with spineboy walk animation
./tests/headless-test-runner.ts \
    examples/spineboy/export/spineboy-pro.json \
    examples/spineboy/export/spineboy-pma.atlas \
    walk

# Test without animation (setup pose only)
./tests/headless-test-runner.ts \
    examples/spineboy/export/spineboy-pro.json \
    examples/spineboy/export/spineboy-pma.atlas
```

## Output Format

Each HeadlessTest outputs:
- **SKELETON DATA**: Static setup pose data (bones, slots, skins, animations metadata)
- **SKELETON STATE**: Runtime state after applying animations
- **ANIMATION STATE**: Current animation state with tracks and mixing information

The output uses consistent JSON formatting:
- Hierarchical structure with 2-space indentation
- Float values formatted to 6 decimal places
- Strings quoted, nulls explicitly shown
- Locale-independent number formatting (always uses `.` for decimals)
- Circular references marked as `"<circular>"` to prevent infinite recursion
- Each object includes a `"type"` field for easy identification

## Development Tools

### API Analyzer (Java)
Analyzes the spine-libgdx API to discover all types and their properties:
```bash
cd tests
npx tsx analyze-java-api.ts
# Output: output/analysis-result.json
```

### Serializer Generator (Java)
Generates SkeletonSerializer.java from the analysis:
```bash
cd tests
npx tsx generate-java-serializer.ts
# Output: ../spine-libgdx/spine-libgdx/src/com/esotericsoftware/spine/utils/SkeletonSerializer.java
```

### Claude Prompt Generator
Generates a prompt for Claude to help port the serializer to other runtimes:
```bash
cd tests
npx tsx generate-claude-prompt.ts
# Output: output/port-serializer-prompt.txt
```

## Troubleshooting

If outputs differ between runtimes:
1. Check `tests/output/` for the full outputs from each runtime
2. Use a diff tool to compare the files
3. Common issues:
   - Number formatting differences (should be fixed by locale settings)
   - Missing or extra fields in data structures
   - Different default values
   - Rounding differences
