#!/bin/bash

# Change to the script's directory
cd "$(dirname "$0")"

# Source logging utilities
source ../formatters/logging/logging.sh

log_title "Spine Tests"

# Check if node/npm is available
if ! command -v npm &> /dev/null; then
    log_fail "npm is not installed"
    exit 1
fi

# Install dependencies if node_modules doesn't exist
if [ ! -d "node_modules" ]; then
    log_section "Setup"
    log_action "Installing dependencies"
    if npm install > /tmp/npm-install.log 2>&1; then
        log_ok "Dependencies installed"
    else
        log_fail "npm install failed"
        log_detail "$(cat /tmp/npm-install.log)"
        exit 1
    fi
fi

log_section "Test"
log_action "Running TypeScript test runner"

# Run the TypeScript headless test runner with all arguments
npx -y tsx src/headless-test-runner.ts "$@"