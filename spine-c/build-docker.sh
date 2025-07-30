#!/bin/bash

set -e

# Get to the script's directory
cd "$(dirname "$0")"

# Build Docker image if it doesn't exist or if Dockerfile changed
IMAGE_NAME="spine-c-build"
if ! docker images | grep -q "$IMAGE_NAME" || [ Dockerfile -nt .docker-built ]; then
    echo "Building Docker image for spine-c..."
    docker build -t "$IMAGE_NAME" .
    touch .docker-built
fi

# Clean build directory to avoid platform conflicts
if [ -d "build" ]; then
    echo "Cleaning build directory to avoid platform conflicts..."
    rm -rf build
fi

# Run the build in Docker
echo "Building spine-c in Docker container..."
docker run --rm \
    -v "$(cd .. && pwd)":/workspace \
    -w /workspace/spine-c \
    "$IMAGE_NAME" \
    ./build.sh "$@"