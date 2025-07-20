#!/bin/bash
set -e

cd "$(dirname "$0")"

# Build or reuse Docker image
IMAGE_NAME="spine-cpp-nostdcpp-test"
if ! docker image inspect $IMAGE_NAME >/dev/null 2>&1; then
    echo "Building Docker image (one-time setup)..."
    docker build -t $IMAGE_NAME - <<'EOF'
FROM ubuntu:22.04
RUN apt-get update >/dev/null 2>&1 && \
    apt-get install -y build-essential cmake ninja-build git file >/dev/null 2>&1 && \
    rm -rf /var/lib/apt/lists/*
EOF
fi

echo "Running spine-cpp nostdcpp test..."

# Run Docker container with spine-runtimes directory mounted
docker run --rm \
    -v "$(pwd)/..:/workspace/spine-runtimes" \
    -w /workspace/spine-runtimes/spine-cpp \
    $IMAGE_NAME \
    bash -c "
        
        # Build everything first
        echo '=== Building all variants ==='
        ./build.sh clean release >/dev/null 2>&1
        
        # Try to build static regular executable
        echo 'Building static regular executable...'
        g++ -static -o build/headless-test-static build/CMakeFiles/headless-test.dir/tests/HeadlessTest.cpp.o build/libspine-cpp.a >/dev/null 2>&1 || echo 'Static regular build failed'
        
        # Try to build static nostdcpp executable (multiple approaches)
        echo 'Building static nostdcpp executable...'
        
        # Approach 1: Try with -static-libgcc and -static-libstdc++ but no libstdc++
        if g++ -static -static-libgcc -Wl,--exclude-libs,libstdc++.a -o build/headless-test-nostdcpp-static build/CMakeFiles/headless-test-nostdcpp.dir/tests/HeadlessTest.cpp.o build/libspine-cpp-nostdcpp.a -lm -lc 2>/dev/null; then
            echo 'SUCCESS: Static nostdcpp built (approach 1)'
        # Approach 2: Try minimal static linking
        elif g++ -static -o build/headless-test-nostdcpp-static-minimal build/CMakeFiles/headless-test-nostdcpp.dir/tests/HeadlessTest.cpp.o build/libspine-cpp-nostdcpp.a 2>/dev/null; then
            echo 'SUCCESS: Static nostdcpp built (approach 2 - minimal)'
        else
            echo 'All static nostdcpp approaches failed - static linking may not be practical on this system'
        fi
        
        echo ''
        echo '=== FINAL RESULTS ==='
        echo ''
        echo 'File sizes:'
        for exe in build/headless-test*; do
            if [ -f \"\$exe\" ]; then
                ls -lah \"\$exe\" | awk '{printf \"%-30s %s\\n\", \$9, \$5}'
            fi
        done
        
        echo ''
        echo 'Dependencies:'
        for exe in build/headless-test*; do
            if [ -f \"\$exe\" ]; then
                echo \"\$(basename \$exe):\"
                ldd \"\$exe\" 2>/dev/null || echo \"  (statically linked)\"
                echo ''
            fi
        done
        
        echo 'Functional test:'
        if [ -f build/headless-test-nostdcpp ]; then
            echo 'Testing headless-test-nostdcpp with spineboy...'
            if OUTPUT=\$(./build/headless-test-nostdcpp ../examples/spineboy/export/spineboy-pro.skel ../examples/spineboy/export/spineboy-pma.atlas idle 2>&1); then
                echo \"\$OUTPUT\" | head -10
                echo '... (output truncated)'
                echo 'SUCCESS: nostdcpp executable works!'
            else
                echo 'FAILED: nostdcpp executable failed to run'
                echo \"Error: \$OUTPUT\"
            fi
        else
            echo 'nostdcpp executable not found'
        fi
    "