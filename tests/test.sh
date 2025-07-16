#!/bin/bash

# Change to the script's directory
cd "$(dirname "$0")"

# Check if node/npm is available
if ! command -v npm &> /dev/null; then
    echo "Error: npm is not installed" >&2
    exit 1
fi

# Install dependencies if node_modules doesn't exist
if [ ! -d "node_modules" ]; then
    echo "Installing dependencies..." >&2
    if ! npm install > /tmp/npm-install.log 2>&1; then
        echo "npm install failed! Output:" >&2
        cat /tmp/npm-install.log >&2
        exit 1
    fi
fi

# Run the TypeScript headless test runner with all arguments
npx -y tsx src/headless-test-runner.ts "$@"