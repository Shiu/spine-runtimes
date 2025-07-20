# Terminal Logging Style Guide

This guide defines the terminal output style for all bash scripts in the Spine Runtimes project.

## Design Principles

1. **Minimal visual noise** - Use color sparingly for emphasis, not decoration
2. **Clear hierarchy** - Different levels of information have distinct visual treatments
3. **Consistent spacing** - Clean vertical rhythm throughout output
4. **Accessible** - Readable and meaningful even without colors
5. **Scannable** - Easy to quickly identify successes, failures, and important information

## Visual Hierarchy

### 1. Title (`log_title`)
- **Purpose**: Main script/tool name
- **Style**: Bold with vertical spacing
- **Usage**: Once at the beginning of script execution

```bash
log_title "Spine-C++ Test"
```

### 2. Section (`log_section`)
- **Purpose**: Major phases or groups of operations
- **Style**: Bold blue text, no extra spacing
- **Usage**: Build, Test, Deploy, etc.

```bash
log_section "Build"
log_section "Test"
```

### 3. Action (`log_action`)
- **Purpose**: Individual operations in progress
- **Style**: Indented, followed by "..."
- **Usage**: Before starting an operation

```bash
log_action "Building all variants"
log_action "Testing headless-test"
```

### 4. Results
- **Purpose**: Outcome of operations
- **Style**: Indented with colored symbols

```bash
log_ok "Build completed"          # Green ✓
log_fail "Build failed"           # Red ✗  
log_warn "Deprecated feature"     # Yellow !
log_skip "Not supported on macOS" # Gray -
```

### 5. Detail (`log_detail`)
- **Purpose**: Secondary information, error output, debug info
- **Style**: Gray text, indented
- **Usage**: Additional context, error messages

```bash
log_detail "Platform: Darwin"
log_detail "$ERROR_OUTPUT"
```

### 6. Summary (`log_summary`)
- **Purpose**: Final result or conclusion
- **Style**: Bold with vertical spacing
- **Usage**: End of script execution

```bash
log_summary "✓ All tests passed (5/5)"
log_summary "✗ Tests failed (3/5)"
```

## Complete Example

```bash
#!/bin/bash
source ../formatters/logging/logging.sh

log_title "Spine-C++ Test"
log_detail "Platform: $(uname)"

log_section "Build"
log_action "Building all variants"
if BUILD_OUTPUT=$(./build.sh clean release 2>&1); then
    log_ok "Build completed"
else
    log_fail "Build failed"
    log_detail "$BUILD_OUTPUT"
    exit 1
fi

log_section "Test"
log_action "Testing headless-test"
if test_result; then
    log_ok "headless-test"
else
    log_fail "headless-test - execution failed"
    log_detail "$error_output"
fi

log_summary "✓ All tests passed (2/2)"
```

## Output Preview

```
Spine-C++ Test

Platform: Darwin

Build
  Building all variants...
  ✓ Build completed

Test
  Testing headless-test...
  ✓ headless-test
  Testing headless-test-nostdcpp...
  ✓ headless-test-nostdcpp

✓ All tests passed (2/2)
```

## Error Handling Best Practices

1. **Capture output**: Use `OUTPUT=$(command 2>&1)` to capture both stdout and stderr
2. **Check exit codes**: Always check if critical operations succeeded
3. **Show details on failure**: Use `log_detail` to show error output
4. **Fail fast**: Exit immediately on critical failures
5. **Clear error messages**: Make failure reasons obvious

```bash
if BUILD_OUTPUT=$(./build.sh clean release 2>&1); then
    log_ok "Build completed"
else
    log_fail "Build failed"
    log_detail "$BUILD_OUTPUT"
    exit 1
fi
```

## Usage

1. Source the utilities in your script:
```bash
source ../formatters/logging/logging.sh
```

2. Follow the hierarchy patterns shown above
3. Use appropriate functions for each type of output
4. Test output both with and without color support