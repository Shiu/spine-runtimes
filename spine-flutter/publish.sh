#!/bin/bash
set -e
cd "$(dirname "$0")"

# Source logging utilities
source ../formatters/logging/logging.sh

log_title "Spine Flutter Publisher"

# Let setup.sh handle its own logging
./setup.sh

# Let compile-wasm.sh handle its own logging
./compile-wasm.sh

log_action "Running dry-run publish"
if DART_OUTPUT=$(dart pub publish --dry-run 2>&1); then
    log_ok
else
    log_fail
    log_error_output "$DART_OUTPUT"
    exit 1
fi

log_action "Publishing to Dart Pub"
if DART_OUTPUT=$(dart pub publish 2>&1); then
    log_ok
    log_summary "✓ Flutter package published successfully"
else
    log_fail
    log_error_output "$DART_OUTPUT"
    exit 1
fi