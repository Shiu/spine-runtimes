#!/bin/bash
set -e

cd "$(dirname "$0")"

# Source logging utilities
source ../formatters/logging/logging.sh

# Parse arguments
BUILD_TYPE="debug"
NOFILEIO=""
CLEAN=""

for arg in "$@"; do
    case $arg in
        clean)
            CLEAN="true"
            ;;
        release)
            BUILD_TYPE="release"
            ;;
        debug)
            BUILD_TYPE="debug"
            ;;
        nofileio)
            NOFILEIO="-DSPINE_NO_FILE_IO=ON"
            ;;
        *)
            log_fail "Unknown argument: $arg"
            log_detail "Usage: $0 [clean] [release|debug] [nofileio]"
            exit 1
            ;;
    esac
done

log_title "Spine-C++ Build"

# Clean if requested
if [ "$CLEAN" = "true" ]; then
    log_section "Clean"
    log_action "Removing build directory"
    rm -rf build
    log_ok "Cleaned"
fi

# Configure and build
log_section "Configure"
log_action "Configuring $BUILD_TYPE build"
if CMAKE_OUTPUT=$(cmake --preset=$BUILD_TYPE $NOFILEIO . 2>&1); then
    log_ok "Configured"
else
    log_fail "Configuration failed"
    log_detail "$CMAKE_OUTPUT"
    exit 1
fi

log_section "Build"
log_action "Building"
if BUILD_OUTPUT=$(cmake --build --preset=$BUILD_TYPE 2>&1); then
    log_ok "Build completed"
else
    log_fail "Build failed"
    log_detail "$BUILD_OUTPUT"
    exit 1
fi

log_summary "✓ Build successful"