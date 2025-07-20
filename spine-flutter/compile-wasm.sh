#!/bin/bash
set -e
cd "$(dirname "$0")"

# Source logging utilities
source ../formatters/logging/logging.sh

log_title "Spine Flutter WASM Compiler"

log_section "Preparing Build Environment"
log_action "Creating assets directory"
if mkdir -p lib/assets/; then
    log_ok "Assets directory created"
else
    log_fail "Failed to create assets directory"
    exit 1
fi

log_action "Creating pre.js module file"
if echo "const module = {};" > pre.js; then
    log_ok "pre.js created successfully"
else
    log_fail "Failed to create pre.js"
    exit 1
fi

log_section "Compiling WASM"
log_detail "Using -O2 optimization to preserve function names"
log_detail "The Closure compiler in -O3 would scramble native function names"
log_action "Compiling spine-cpp to WASM"

# Build the emscripten command
if output=$(em++ \
    -Isrc/spine-cpp/include \
    -O2 --closure 1 -fno-rtti -fno-exceptions \
    -s STRICT=1 \
    -s EXPORTED_RUNTIME_METHODS=wasmExports \
    -s ERROR_ON_UNDEFINED_SYMBOLS=1 \
    -s MODULARIZE=1 \
    -s ALLOW_MEMORY_GROWTH=1 \
    -s ALLOW_TABLE_GROWTH \
    -s MALLOC=emmalloc \
    -s EXPORT_ALL=1 \
    -s EXPORTED_FUNCTIONS='["_malloc", "_free"]' \
    --no-entry \
    --extern-pre-js pre.js \
    -s EXPORT_NAME=libspine_flutter \
    src/spine-cpp-lite/spine-cpp-lite.cpp $(find src/spine-cpp/src -type f) \
    -o lib/assets/libspine_flutter.js 2>&1); then
    log_ok "WASM compilation completed successfully"
else
    log_fail "WASM compilation failed"
    log_detail "$output"
    rm -f pre.js
    exit 1
fi

log_section "Build Results"
log_action "Listing generated assets"
if ls -lah lib/assets; then
    log_ok "Assets generated successfully"
else
    log_warn "Could not list assets directory"
fi

log_action "Cleaning up temporary files"
if rm pre.js; then
    log_ok "Cleaned up pre.js"
else
    log_warn "Could not remove pre.js"
fi

log_summary "WASM compilation completed successfully"