#!/bin/bash
set -e

# Format TypeScript files with tsfmt
echo "Formatting TypeScript files..."

dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"

# Check if tsfmt.json files match
if ! cmp -s ../spine-ts/tsfmt.json ../tests/tsfmt.json; then
    echo -e "\033[1;31mERROR: spine-ts/tsfmt.json and tests/tsfmt.json differ!\033[0m"
    echo -e "\033[1;31mPlease sync them to ensure consistent formatting.\033[0m"
    exit 1
fi

# Format TypeScript files
cd ../spine-ts && npm run format && cd ../formatters
cd ../tests && npm run format -r && cd ../formatters