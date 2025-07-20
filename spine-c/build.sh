#!/bin/bash
set -e

cd "$(dirname "$0")"

# Source logging utilities
source ../formatters/logging/logging.sh

# Display help information
show_help() {
    log_title "Spine-C Build Script"
    echo "Usage: ./build.sh [option]"
    echo ""
    echo "Options:"
    echo "  --help, -h    Show this help message"
    echo "  codegen       Run code generation to regenerate C bindings from C++ sources"
    echo "  clean         Clean build directory before building"
    echo "  release       Build in release mode (default is debug)"
    echo "  (no option)   Build the project in debug mode (default)"
    echo ""
    echo "Examples:"
    echo "  ./build.sh              # Build debug version"
    echo "  ./build.sh release      # Build release version"
    echo "  ./build.sh clean        # Clean and rebuild debug"
    echo "  ./build.sh codegen      # Regenerate C bindings"
    echo "  ./build.sh --help       # Show this help"
    exit 0
}

# Check for help flag
if [ "$1" = "--help" ] || [ "$1" = "-h" ]; then
    show_help
fi

# Run codegen if requested
if [ "$1" = "codegen" ]; then
    log_title "Spine-C Code Generation"
    
    log_section "Generate"
    log_action "Generating C bindings"
    if CODEGEN_OUTPUT=$(npx -y tsx codegen/src/index.ts 2>&1); then
        log_ok "Code generation completed"
    else
        log_fail "Code generation failed"
        log_detail "$CODEGEN_OUTPUT"
        exit 1
    fi
    
    log_section "Format"
    log_action "Formatting generated C++ files"
    ../formatters/format.sh cpp
    
    log_summary "✓ Code generation successful"
    exit 0
fi

log_title "Spine-C Build"

# Clean only if explicitly requested
if [ "$1" = "clean" ]; then
    log_section "Clean"
    log_action "Removing build directory"
    rm -rf build
    log_ok "Cleaned"
fi

# Determine build type
BUILD_TYPE="debug"
if [ "$1" = "release" ]; then
    BUILD_TYPE="release"
fi

# Configure and build
log_section "Configure"
log_action "Configuring $BUILD_TYPE build"
if CMAKE_OUTPUT=$(cmake --preset=$BUILD_TYPE . 2>&1); then
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