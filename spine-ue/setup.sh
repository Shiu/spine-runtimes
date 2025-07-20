#!/bin/bash
set -e
cd "$(dirname "$0")"

# Source logging utilities
source ../formatters/logging/logging.sh

log_title "Spine Unreal Engine Setup"

log_section "Updating Spine C++ Sources"
log_action "Removing existing spine-cpp directory"
if rm -rf Plugins/SpinePlugin/Source/SpinePlugin/Public/spine-cpp 2>/dev/null; then
    log_ok "Existing spine-cpp directory removed"
else
    log_warn "No existing spine-cpp directory found"
fi

log_action "Copying updated spine-cpp sources"
if cp -r ../spine-cpp/spine-cpp Plugins/SpinePlugin/Source/SpinePlugin/Public/spine-cpp 2>/dev/null; then
    log_ok "spine-cpp sources copied successfully"
    log_summary "Unreal Engine setup completed successfully"
else
    log_fail "Failed to copy spine-cpp sources"
    exit 1
fi