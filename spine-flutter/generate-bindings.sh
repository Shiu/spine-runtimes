#!/bin/bash

set -e

# Get to the script's directory
pushd "$(dirname "$0")" > /dev/null

#./setup.sh

# Install dependencies if needed
if [ ! -d "codegen/node_modules" ]; then
    pushd codegen > /dev/null
    npm install
    popd > /dev/null
fi

# Copy spine-c and spine-cpp sources
./setup.sh

# Run the codegen
npx tsx codegen/src/index.ts

popd > /dev/null