#!/bin/bash
set -e

cd "$(dirname "$0")"

# Display help information
show_help() {
    echo "spine-c build script"
    echo ""
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
    npx tsx codegen/src/index.ts
    # Format the generated C++ files
    echo "Formatting generated C++ files..."
    ../formatters/format.sh cpp
    exit 0
fi

# Clean only if explicitly requested
if [ "$1" = "clean" ]; then
    rm -rf build
fi

# Determine build type
BUILD_TYPE="debug"
if [ "$1" = "release" ]; then
    BUILD_TYPE="release"
fi

# Always build
cmake --preset=$BUILD_TYPE .
cmake --build --preset=$BUILD_TYPE