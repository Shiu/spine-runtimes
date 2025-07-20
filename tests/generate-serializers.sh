#!/bin/bash

set -e
set -o pipefail
cd "$(dirname "$0")"

# Source logging utilities
source ../formatters/logging/logging.sh

log_title "Spine Serializer Generator"

# Check if node/npm is available
if ! command -v npm &> /dev/null; then
    log_fail "npm is not installed"
    exit 1
fi

# Install dependencies if node_modules doesn't exist
if [ ! -d "node_modules" ]; then
    log_action "Installing dependencies"
    if npm install > /tmp/npm-install.log 2>&1; then
        log_ok "Dependencies installed"
    else
        log_fail "npm install failed"
        log_detail "$(cat /tmp/npm-install.log)"
        exit 1
    fi
fi

log_action "Analyzing Java API"
if output=$(npx -y tsx src/analyze-java-api.ts 2>&1); then
    log_ok
else
    log_fail
    log_detail "$output"
    exit 1
fi

log_action "Generating intermediate representation"
if output=$(npx -y tsx src/generate-serializer-ir.ts 2>&1); then
    log_ok
else
    log_fail
    log_detail "$output"
    exit 1
fi

log_action "Generating Java SkeletonSerializer"
if output=$(npx -y tsx src/generate-java-serializer.ts 2>&1); then
    log_ok
else
    log_fail "Failed to generate Java serializer"
    log_detail "$output"
    exit 1
fi
../formatters/format-java.sh

log_action "Generating C++ SkeletonSerializer"
if output=$(npx -y tsx src/generate-cpp-serializer.ts 2>&1); then
    log_ok "C++ serializer generated successfully"
else
    log_fail "Failed to generate C++ serializer"
    log_detail "$output"
    exit 1
fi
../formatters/format-cpp.sh

log_summary "✓ Serializer generation completed successfully"