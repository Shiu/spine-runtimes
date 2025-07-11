#!/bin/bash
set -e

cd "$(dirname "$0")"

# Clean only if explicitly requested
if [ "$1" = "clean" ]; then
    rm -rf build
fi

# Always build
mkdir -p build && cd build
[ -f CMakeCache.txt ] || cmake .. -DCMAKE_BUILD_TYPE=Debug
make -j$(sysctl -n hw.ncpu 2>/dev/null || nproc 2>/dev/null || echo 4)