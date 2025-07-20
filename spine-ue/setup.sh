#!/bin/bash
set -e
cd "$(dirname "$0")"

# Source logging utilities
source ../formatters/logging/logging.sh

log_title "Spine Unreal Engine Setup"

log_action "Removing existing spine-cpp directory"
if RM_OUTPUT=$(rm -rf Plugins/SpinePlugin/Source/SpinePlugin/Public/spine-cpp 2>&1); then
    log_ok
else
    log_warn
fi

log_action "Copying updated spine-cpp sources"
if CP_OUTPUT=$(cp -r ../spine-cpp/spine-cpp Plugins/SpinePlugin/Source/SpinePlugin/Public/spine-cpp 2>&1); then
    log_ok
    log_summary "✓ Unreal Engine setup completed successfully"
else
    log_fail
    log_error_output "$CP_OUTPUT"
    exit 1
fi