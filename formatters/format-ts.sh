#!/bin/bash
set -e

# Format TypeScript files with Biome
echo "Formatting TypeScript files..."

dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"

# Check if biome.json files match
if ! cmp -s ../spine-ts/biome.json ../tests/biome.json; then
    echo -e "\033[1;31mERROR: spine-ts/biome.json and tests/biome.json differ!\033[0m"
    echo -e "\033[1;31mPlease sync them to ensure consistent formatting.\033[0m"
    exit 1
fi

# Format TypeScript files
cd ../spine-ts && npx biome format --write . && cd ../formatters
cd ../tests && npx biome format --write --config-path ../spine-ts . && cd ../formatters