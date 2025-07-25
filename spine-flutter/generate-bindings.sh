#!/bin/bash

set -e

# Get to the script's directory
cd "$(dirname "$0")"

# Source logging utilities
source ../formatters/logging/logging.sh

log_title "spine-dart bindings generation"

# Install dependencies if needed
if [ ! -d "codegen/node_modules" ]; then
    log_action "Installing codegen dependencies"
    if (cd codegen && npm install > /dev/null 2>&1); then
        log_ok
    else
        log_fail
        exit 1
    fi
fi

# Copy spine-c and spine-cpp sources
log_action "Setting up source files"
if ./setup.sh > /dev/null 2>&1; then
    log_ok
else
    log_fail
    exit 1
fi

# Run the codegen
log_action "Generating Dart bindings"
if npx tsx codegen/src/index.ts > /dev/null 2>&1; then
    log_ok
else
    log_fail
    exit 1
fi

# Build test spine_flutter shared library
log_action "Building test library"
if (cd test && ./build.sh > /dev/null 2>&1); then
    log_ok
else
    log_fail
    exit 1
fi

log_summary "✓ Dart bindings generated successfully"