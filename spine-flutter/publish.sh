#!/bin/bash
set -e
cd "$(dirname "$0")"

# Source logging utilities
source ../formatters/logging/logging.sh

log_title "Spine Flutter Publisher"

log_section "Preparation"
log_action "Setting up environment"
if output=$(./setup.sh 2>&1); then
    log_ok "Setup completed successfully"
else
    log_fail "Setup failed"
    log_detail "$output"
    exit 1
fi

log_action "Compiling WASM"
if output=$(./compile-wasm.sh 2>&1); then
    log_ok "WASM compilation completed successfully"
else
    log_fail "WASM compilation failed"
    log_detail "$output"
    exit 1
fi

log_section "Publishing to Dart Pub"
log_action "Running dry-run publish"
if output=$(dart pub publish --dry-run 2>&1); then
    log_ok "Dry-run publish completed successfully"
else
    log_fail "Dry-run publish failed"
    log_detail "$output"
    exit 1
fi

log_action "Publishing to Dart Pub"
if output=$(dart pub publish 2>&1); then
    log_ok "Successfully published to Dart Pub"
    log_summary "Flutter package published successfully"
else
    log_fail "Failed to publish to Dart Pub"
    log_detail "$output"
    exit 1
fi