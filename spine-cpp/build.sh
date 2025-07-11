#!/bin/bash
set -e

cd "$(dirname "$0")"

for arg in "${@:-clean build}"; do
    case $arg in
        clean) rm -rf build ;;
        build) 
            mkdir -p build && cd build
            [ -f CMakeCache.txt ] || cmake .. -DCMAKE_BUILD_TYPE=Debug
            make -j$(sysctl -n hw.ncpu 2>/dev/null || nproc 2>/dev/null || echo 4)
            cd ..
            ;;
    esac
done