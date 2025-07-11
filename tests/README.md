# Spine Runtimes Test Suite

This test suite is designed to ensure consistency across all Spine runtime implementations by comparing their outputs against the reference implementation (spine-libgdx).

## Purpose

Unlike traditional unit tests, this test suite:
- Loads skeleton data and animations in each runtime
- Outputs all internal state in a consistent, diffable text format
- Compares outputs between runtimes to detect discrepancies
- Helps maintain consistency when porting changes from the reference implementation

## DebugPrinter Locations

Each runtime has a DebugPrinter program that outputs skeleton data in a standardized format:

- **Java (Reference)**: `spine-libgdx/spine-libgdx-tests/src/com/esotericsoftware/spine/DebugPrinter.java`
- **C++**: `spine-cpp/tests/DebugPrinter.cpp`
- **C**: `spine-c/tests/debug-printer.c`
- **TypeScript**: `spine-ts/spine-core/tests/DebugPrinter.ts`

## Running Individual DebugPrinters

### Java (spine-libgdx)
```bash
cd spine-libgdx
./gradlew :spine-libgdx-tests:runDebugPrinter -Pargs="<skeleton-path> <atlas-path> [animation-name]"
```

### C++ (spine-cpp)
```bash
cd spine-cpp
./build.sh  # Build if needed
./build/debug-printer <skeleton-path> <atlas-path> [animation-name]
```

### C (spine-c)
```bash
cd spine-c
./build.sh  # Build if needed
./build/debug-printer <skeleton-path> <atlas-path> [animation-name]
```

### TypeScript (spine-ts)
```bash
cd spine-ts/spine-core
npx tsx tests/DebugPrinter.ts <skeleton-path> <atlas-path> [animation-name]
```

## Running the Comparison Test

The main test runner compares all runtime outputs automatically:

```bash
./tests/compare-with-reference-impl.ts <skeleton-path> <atlas-path> [animation-name]
```

This script will:
1. Check if each runtime's DebugPrinter needs rebuilding
2. Build any out-of-date DebugPrinters
3. Run each DebugPrinter with the same inputs
4. Compare outputs and report any differences
5. Save individual outputs to `tests/output/` for manual inspection

### Example Usage

```bash
# Test with spineboy walk animation
./tests/compare-with-reference-impl.ts \
    examples/spineboy/export/spineboy-pro.json \
    examples/spineboy/export/spineboy-pma.atlas \
    walk

# Test without animation (setup pose only)
./tests/compare-with-reference-impl.ts \
    examples/spineboy/export/spineboy-pro.json \
    examples/spineboy/export/spineboy-pma.atlas
```

## Output Format

Each DebugPrinter outputs:
- **SKELETON DATA**: Static setup pose data (bones, slots, skins, animations metadata)
- **SKELETON STATE**: Runtime state after applying animations

The output uses consistent formatting:
- Hierarchical structure with 2-space indentation
- Float values formatted to 6 decimal places
- Strings quoted, nulls explicitly shown
- Locale-independent number formatting (always uses `.` for decimals)