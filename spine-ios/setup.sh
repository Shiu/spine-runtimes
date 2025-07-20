#!/bin/bash
set -e
cd "$(dirname "$0")"

# Source logging utilities
source ../formatters/logging/logging.sh

log_title "Spine iOS Setup"

log_section "Generating Swift Bindings"
log_action "Running spine-cpp-lite code generator"
if output=$(python3 ../spine-cpp/spine-cpp-lite/spine-cpp-lite-codegen.py 2>&1); then
    if echo "$output" > Sources/Spine/Spine.Generated.swift; then
        log_ok "Swift bindings generated successfully"
        log_summary "iOS setup completed successfully"
    else
        log_fail "Failed to write generated Swift code"
        exit 1
    fi
else
    log_fail "Failed to run spine-cpp-lite code generator"
    log_detail "$output"
    exit 1
fi
