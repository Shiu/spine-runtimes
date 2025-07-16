#!/bin/bash
set -e

# Format TypeScript files with tsfmt
echo "Formatting TypeScript files..."

dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"

# Store original directory
pushd "$dir" > /dev/null

# Check if tsfmt.json files match
if ! cmp -s ../spine-ts/tsfmt.json ../tests/tsfmt.json; then
    echo -e "\033[1;31mERROR: spine-ts/tsfmt.json and tests/tsfmt.json differ!\033[0m"
    echo -e "\033[1;31mPlease sync them to ensure consistent formatting.\033[0m"
    popd > /dev/null
    exit 1
fi

# Format TypeScript files
pushd ../spine-ts > /dev/null
if [ ! -d "node_modules" ]; then
    echo "Installing spine-ts dependencies..."
    npm install
fi
npm run format
popd > /dev/null

pushd ../tests > /dev/null
if [ ! -d "node_modules" ]; then
    echo "Installing tests dependencies..."
    npm install
fi
npm run format
popd > /dev/null

# Return to original directory
popd > /dev/null