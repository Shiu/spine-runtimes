#!/bin/bash
set -e

# Format Swift files
echo "Formatting Swift files..."

if command -v swift-format &> /dev/null; then
    find .. -name "*.swift" \
        -not -path "*/.*" \
        -not -path "*/build/*" \
        -not -path "*/DerivedData/*" \
        | xargs swift-format -i
else
    echo "Warning: swift-format not found. Install from https://github.com/apple/swift-format"
fi