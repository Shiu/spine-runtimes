#!/bin/bash
set -e
cd "$(dirname "$0")"

# Source logging utilities
source ../formatters/logging/logging.sh

log_title "Spine Flutter Setup"

log_detail "CocoaPods requires all source files to be under the same folder hierarchy"
log_detail "as the podspec file resides in. Copying spine-cpp sources to platform folders."

log_action "Copying spine-cpp to iOS Classes"
if CP_OUTPUT=$(rsync -r --exclude='.cache' --exclude='build' ../spine-cpp ../spine-c ios/Classes 2>&1); then
    log_ok
else
    log_fail
    log_error_output "$CP_OUTPUT"
    exit 1
fi

log_action "Copying spine-cpp to macOS Classes"
if CP_OUTPUT=$(rsync -r --exclude='.cache' --exclude='build' ../spine-cpp ../spine-c macos/Classes 2>&1); then
    log_ok
else
    log_fail
    log_error_output "$CP_OUTPUT"
    exit 1
fi

log_action "Copying spine-cpp to src directory"
if CP_OUTPUT=$(rsync -r --exclude='.cache' --exclude='build' ../spine-cpp ../spine-c src 2>&1); then
    log_ok
else
    log_fail
    log_error_output "$CP_OUTPUT"
    exit 1
fi

log_summary "✓ Flutter setup completed successfully"