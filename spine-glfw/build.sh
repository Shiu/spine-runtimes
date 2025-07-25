#!/bin/bash
set -e

cd "$(dirname "$0")"

# Source logging utilities
source ../formatters/logging/logging.sh

# Parse arguments
BUILD_TYPE="debug"
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
        *)
            log_fail "Unknown argument: $arg"
            log_detail "Usage: $0 [clean] [release|debug]"
            exit 1
            ;;
    esac
done

log_title "spine-glfw build"

# Clean if requested
if [ "$CLEAN" = "true" ]; then
    log_action "Cleaning build directory"
    rm -rf build
    log_ok
fi

# Configure and build
log_action "Configuring $BUILD_TYPE build"
if CMAKE_OUTPUT=$(cmake --preset=$BUILD_TYPE . 2>&1); then
    log_ok
else
    log_fail
    log_error_output "$CMAKE_OUTPUT"
    exit 1
fi

log_action "Building"
if BUILD_OUTPUT=$(cmake --build --preset=$BUILD_TYPE 2>&1); then
    log_ok
else
    log_fail
    log_error_output "$BUILD_OUTPUT"
    exit 1
fi

log_summary "✓ Build successful"