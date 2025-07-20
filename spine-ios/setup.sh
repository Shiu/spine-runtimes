#!/bin/bash
set -e
cd "$(dirname "$0")"

# Source logging utilities
source ../formatters/logging/logging.sh

log_title "Spine iOS Setup"

log_action "Running spine-cpp-lite code generator"
if PYTHON_OUTPUT=$(python3 ../spine-cpp/spine-cpp-lite/spine-cpp-lite-codegen.py 2>&1); then
    if WRITE_OUTPUT=$(echo "$PYTHON_OUTPUT" > Sources/Spine/Spine.Generated.swift 2>&1); then
        log_ok
        log_summary "✓ iOS setup completed successfully"
    else
        log_fail
        log_error_output "$WRITE_OUTPUT"
        exit 1
    fi
else
    log_fail
    log_error_output "$PYTHON_OUTPUT"
    exit 1
fi
