#!/bin/bash
set -e

cd "$(dirname "$0")"

# Clean only if explicitly requested
if [ "$1" = "clean" ]; then
    rm -rf build
fi

# Always build
cmake --preset=debug .
cmake --build --preset=debug