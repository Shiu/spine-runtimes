#!/bin/bash

# Script to generate all Spine runtime bindings
# This script regenerates bindings for C, Flutter, and cleans GLFW

# Get the directory containing this script
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

rm -rf "$SCRIPT_DIR/spine-c/codegen/node_modules" "$SCRIPT_DIR/spine-flutter/codegen/node_modules" "$SCRIPT_DIR/test/node_modules"

# Source logging utilities
source "$SCRIPT_DIR/formatters/logging/logging.sh"

log_title "Generating all Spine runtime bindings"

# Generate C bindings and test compilation
log_info "Generating C bindings"
cd "$SCRIPT_DIR/spine-c" && ./build.sh codegen

log_info "Testing C compilation"
cd "$SCRIPT_DIR/spine-c" && ./build.sh clean

# Clean GLFW
log_info "Test GLFW compilation"
cd "$SCRIPT_DIR/spine-glfw" && ./build.sh clean

# Generate Flutter bindings
log_info "Generating Dart bindings"
cd "$SCRIPT_DIR/spine-flutter" && ./generate-bindings.sh

log_info "Testing Dart"
cd "$SCRIPT_DIR/spine-flutter/test" && dart test headless_test.dart

log_summary "All bindings generated successfully"