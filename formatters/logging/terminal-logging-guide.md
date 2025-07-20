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
log_title "Spine-C++ Build"
```

### 2. Action + Result (inline format)
- **Purpose**: Individual operations with immediate result
- **Style**: Action on same line as result for density
- **Usage**: `log_action` followed immediately by `log_ok/fail/warn/skip`

```bash
log_action "Building all variants"
log_ok                           # Green ✓ on same line

log_action "Testing headless-test"  
log_fail                         # Red ✗ on same line
```

**Results**:
- `log_ok` - Green ✓ (success)
- `log_fail` - Red ✗ (failure) 
- `log_warn` - Yellow ! (warning)
- `log_skip` - Gray - (skipped)

### 4. Error Output (`log_error_output`)
- **Purpose**: Full error output when operations fail
- **Style**: Normal text (not grayed), prominent
- **Usage**: Show command output after failures

```bash
log_action "Building"
if BUILD_OUTPUT=$(command 2>&1); then
    log_ok
else
    log_fail
    log_error_output "$BUILD_OUTPUT"
fi
```

### 5. Detail (`log_detail`)
- **Purpose**: Secondary information, debug info (not errors)
- **Style**: Gray text, indented
- **Usage**: Additional context, platform info

```bash
log_detail "Platform: Darwin"
log_detail "Branch: main"
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

log_title "Spine-C++ Build"
log_detail "Platform: $(uname)"

log_action "Configuring debug build"
if CMAKE_OUTPUT=$(cmake --preset=debug . 2>&1); then
    log_ok
else
    log_fail
    log_error_output "$CMAKE_OUTPUT"
    exit 1
fi

log_action "Building"
if BUILD_OUTPUT=$(cmake --build --preset=debug 2>&1); then
    log_ok
else
    log_fail
    log_error_output "$BUILD_OUTPUT"
    exit 1
fi

log_summary "✓ Build successful"
```

## Output Preview

**Success case:**
```
Spine-C++ Build
Platform: Darwin

  Configuring debug build... ✓
  Building... ✓

✓ Build successful
```

**Failure case:**
```
Spine-C++ Build
Platform: Darwin

  Configuring debug build... ✗
CMake Error: Could not find cmake file...
(full error output shown prominently)
```

## Error Handling Best Practices

1. **Capture output**: Use `OUTPUT=$(command 2>&1)` to capture both stdout and stderr
2. **Check exit codes**: Always check if critical operations succeeded  
3. **Show errors prominently**: Use `log_error_output` for command failures (not grayed)
4. **Fail fast**: Exit immediately on critical failures
5. **Use inline results**: `log_action` + `log_ok/fail` for dense, scannable output

## Calling Other Scripts

When calling other bash scripts that have their own logging:

1. **Trust their logging**: Don't wrap calls in redundant log actions
2. **Capture output for errors**: Use `OUTPUT=$(script.sh 2>&1)` to capture output and only show on failure
3. **Let them handle success**: Avoid "script completed" messages when the script shows its own status

**Good**:
```bash
# Let the script handle its own logging
../formatters/format.sh cpp

# Or capture output and only show on error
if output=$(./setup.sh 2>&1); then
    log_ok "Setup completed"
else
    log_fail "Setup failed"
    log_detail "$output"
fi
```

**Avoid**:
```bash
# This creates duplicate logging
log_action "Formatting C++ files"
../formatters/format.sh cpp
log_ok "C++ formatting completed"
```

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