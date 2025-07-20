#!/bin/bash
set -e
cd "$(dirname "$0")"

# Source logging utilities
source ../formatters/logging/logging.sh

log_title "Spine Flutter Setup"

log_detail "CocoaPods requires all source files to be under the same folder hierarchy"
log_detail "as the podspec file resides in. Copying spine-cpp sources to platform folders."

log_section "Copying Spine C++ Sources"

log_action "Copying spine-cpp to iOS Classes"
if cp -r ../spine-cpp/spine-cpp ios/Classes 2>/dev/null; then
    log_ok "iOS Classes updated successfully"
else
    log_fail "Failed to copy spine-cpp to iOS Classes"
    exit 1
fi

log_action "Copying spine-cpp to macOS Classes"
if cp -r ../spine-cpp/spine-cpp macos/Classes 2>/dev/null; then
    log_ok "macOS Classes updated successfully"
else
    log_fail "Failed to copy spine-cpp to macOS Classes"
    exit 1
fi

log_action "Copying spine-cpp to src directory"
if cp -r ../spine-cpp/spine-cpp src 2>/dev/null; then
    log_ok "src directory updated successfully"
else
    log_fail "Failed to copy spine-cpp to src directory"
    exit 1
fi

log_action "Copying spine-cpp-lite to src directory"
if cp -r ../spine-cpp/spine-cpp-lite src 2>/dev/null; then
    log_ok "spine-cpp-lite copied successfully"
else
    log_fail "Failed to copy spine-cpp-lite to src directory"
    exit 1
fi

log_summary "Flutter setup completed successfully"