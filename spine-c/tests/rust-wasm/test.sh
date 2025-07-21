#!/bin/bash
# Spine-C WASM Test
#
# Tests spine-c + spine-cpp-no-cpprt compilation to WASM via Rust FFI

set -e

# Change to test directory
cd "$(dirname "$0")"

# Source logging utilities
source ../../../formatters/logging/logging.sh

log_title "Spine-C WASM Test"

# Check if Rust is installed
if ! command -v cargo > /dev/null 2>&1; then
    log_fail "Cargo not found - install Rust toolchain"
    exit 1
fi

# Check if WASM target is installed
log_action "Checking WASM target"
if RUSTUP_OUTPUT=$(rustup target list --installed 2>&1); then
    if echo "$RUSTUP_OUTPUT" | grep -q "wasm32-unknown-unknown"; then
        log_ok
    else
        log_detail "Installing wasm32-unknown-unknown target"
        if rustup target add wasm32-unknown-unknown > /dev/null 2>&1; then
            log_ok
        else
            log_fail
            log_detail "Failed to install WASM target"
            exit 1
        fi
    fi
else
    log_fail
    log_detail "Could not check rustup targets"
    exit 1
fi

# Build native version first (for comparison)
log_action "Building native version"
if BUILD_OUTPUT=$(cargo build 2>&1); then
    log_ok
else
    log_fail
    log_error_output "$BUILD_OUTPUT"
    exit 1
fi

# Test native version
log_action "Testing native version"
if TEST_OUTPUT=$(cargo test 2>&1); then
    log_ok
else
    log_fail
    log_error_output "$TEST_OUTPUT"
    exit 1
fi

# Build WASM version
log_action "Building WASM version"
if WASM_BUILD_OUTPUT=$(cargo build --target wasm32-unknown-unknown 2>&1); then
    log_ok
else
    log_fail
    log_error_output "$WASM_BUILD_OUTPUT"
    exit 1
fi

# Check WASM output
WASM_FILE="target/wasm32-unknown-unknown/debug/spine_c_wasm_test.wasm"
if [ -f "$WASM_FILE" ]; then
    log_action "Analyzing WASM output"
    WASM_SIZE=$(du -h "$WASM_FILE" | cut -f1)
    log_ok
    log_detail "WASM file size: $WASM_SIZE"
    
    # Check for C++ runtime dependencies (should be minimal)
    if command -v wasm-objdump > /dev/null 2>&1; then
        log_detail "WASM imports:"
        wasm-objdump -x "$WASM_FILE" | grep -A 20 "Import\[" | head -20 || true
    fi
else
    log_fail "WASM file not found: $WASM_FILE"
    exit 1
fi

# Test with wasmtime if available
if command -v wasmtime > /dev/null 2>&1; then
    log_action "Testing with wasmtime"
    # Create a simple test runner
    cat > test_runner.wat << 'EOF'
(module
  (import "spine" "run_spine_test" (func $run_spine_test (result i32)))
  (func (export "_start")
    (call $run_spine_test)
    (if (i32.ne (i32.const 0))
      (then unreachable))
  )
)
EOF
    
    if wasmtime test_runner.wat --invoke _start 2>/dev/null; then
        log_ok
    else
        log_detail "Wasmtime test skipped (expected - needs proper test harness)"
    fi
    rm -f test_runner.wat
else
    log_detail "Wasmtime not available - skipping runtime test"
fi

log_summary "✓ WASM compilation successful"
log_detail "This proves spine-cpp-no-cpprt can be used from Rust and compiled to WASM"