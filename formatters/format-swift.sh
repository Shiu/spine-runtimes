#!/bin/bash
set -e

# Format Swift files
echo "Formatting Swift files..."

dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"

# Store original directory
pushd "$dir" > /dev/null

if command -v swift-format &> /dev/null; then
    find .. -name "*.swift" \
        -not -path "*/.*" \
        -not -path "*/build/*" \
        -not -path "*/DerivedData/*" \
        | xargs swift-format -i
else
    echo "Warning: swift-format not found. Install from https://github.com/apple/swift-format"
fi

# Return to original directory
popd > /dev/null