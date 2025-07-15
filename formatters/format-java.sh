#!/bin/bash
set -e

# Format Java files with Spotless (keeping this for Eclipse formatter)
echo "Formatting Java files..."

dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"

# Store original directory
pushd "$dir" > /dev/null

# Run gradle from the formatters directory
./gradlew spotlessJavaApply --quiet

# Return to original directory
popd > /dev/null