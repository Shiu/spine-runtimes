# Spine-C Rust WASM Test

A minimal test demonstrating Rust FFI with spine-c, proving the no-cpprt workflow for WASM compilation.

## What This Does

This test:
1. Loads a Spine atlas with texture callbacks (`spine_atlas_load_callback`)
2. Loads binary skeleton data (`spine_skeleton_data_load_binary`)
3. Creates a skeleton instance (`spine_skeleton_create`)
4. Runs basic skeleton operations (`spine_skeleton_setup_pose`, `spine_skeleton_update_world_transform_1`)
5. Reads skeleton position (`spine_skeleton_get_x/y`)
6. Cleans up all resources including atlas disposal with texture callbacks

## Build Process

The build script compiles:
- spine-cpp with no-cpprt variant (eliminates C++ standard library)
- spine-c wrapper (provides C-compatible FFI)
- Generates complete Rust FFI bindings via bindgen from spine-c.h
- Links everything into a single Rust executable/library

**Full API Coverage**: Bindgen automatically generates Rust bindings for the entire spine-c API, exposing all public functions without manual FFI maintenance.

spine-c/spine-cpp only rely on libc for `malloc`, `free` and various math functions, which can be easily stubbed on any target platform.

This proves Rust projects can use Spine without C++ stdlib dependencies, enabling WASM compilation via Rust toolchain instead of Emscripten.

## Files

- `src/lib.rs` - Rust FFI test calling spine-c functions via bindgen-generated bindings
- `build.rs` - Compiles spine-cpp-no-cpprt + spine-c via cc crate, generates FFI bindings with bindgen
- Test data: `../../../examples/spineboy/export/spineboy-*` (atlas, skeleton, texture)

## Usage

```bash
cargo test -- --nocapture    # Run test with debug output
cargo build                  # Build native
cargo build --target wasm32-unknown-unknown  # Build WASM
```

**Status**: Fully working. Test executable: 1.8 MB. All spine-c functionality operational including atlas disposal.