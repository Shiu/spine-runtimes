#!/bin/bash
set -e

cd "$(dirname "$0")"

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
            echo "Unknown argument: $arg"
            echo "Usage: $0 [clean] [release|debug] [nofileio]"
            exit 1
            ;;
    esac
done

# Clean if requested
if [ "$CLEAN" = "true" ]; then
    rm -rf build
fi

# Configure and build
cmake --preset=$BUILD_TYPE $NOFILEIO .
cmake --build --preset=$BUILD_TYPE