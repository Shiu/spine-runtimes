# Terminal Logging Style Guide

## Functions

```bash
source ../formatters/logging/logging.sh

log_title "Script Name"           # Bold title
log_action "Doing something"      # Action with inline result
log_ok                           # Green ✓
log_fail                         # Red ✗
log_warn                         # Yellow !
log_skip                         # Gray -
log_error_output "$OUTPUT"       # Show command output on errors
log_detail "Extra info"          # Gray secondary text
log_summary "✓ All done"         # Bold conclusion
```

## Pattern

```bash
log_title "Spine-C++ Build"

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
```

## Output

```
Spine-C++ Build
  Configuring debug build... ✓
  Building... ✓
```

## Rules

- Always capture command output of commands following log_action: `OUTPUT=$(command 2>&1)`
- Show errors prominently with `log_error_output`
- Use inline results: `log_action` + `log_ok/fail`
- Let sub-scripts handle their own logging, e.g. do not log "Building Spine-C++" when calling `spine-cpp/build.sh`
- Do not capture output of sub-scripts like you do for "normal" commands. That would swallow their logging.