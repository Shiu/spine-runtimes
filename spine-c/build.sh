#!/bin/bash
set -e

cd "$(dirname "$0")"

# Run codegen if requested
if [ "$1" = "codegen" ]; then
    npx tsx codegen/src/index.ts
    exit 0
fi

# Clean only if explicitly requested
if [ "$1" = "clean" ]; then
    rm -rf build
fi

# Always build
cmake --preset=debug .
cmake --build --preset=debug