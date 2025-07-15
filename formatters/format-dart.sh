#!/bin/bash
set -e

# Format Dart files
echo "Formatting Dart files..."

dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"

# Store original directory
pushd "$dir" > /dev/null

if command -v dart &> /dev/null; then
    find .. -name "*.dart" \
        -not -path "*/.*" \
        -not -path "*/node_modules/*" \
        -not -path "*/build/*" \
        -exec dart format --page-width 120 {} +
else
    echo "Warning: dart not found. Skipping Dart formatting."
fi

# Return to original directory
popd > /dev/null