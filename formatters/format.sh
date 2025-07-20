#!/bin/bash
set -e
dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"

# Source logging utilities
source "$dir/logging/logging.sh"

# Default: format all languages
FORMAT_JAVA=true
FORMAT_TS=true
FORMAT_CPP=true
FORMAT_CSHARP=true
FORMAT_HAXE=true
FORMAT_DART=true
FORMAT_SWIFT=true

# Parse command line arguments
show_help() {
    log_title "Spine Runtimes Code Formatter"
    echo "Usage: ./format.sh [options]"
    echo ""
    echo "Options:"
    echo "  --help, -h    Show this help message"
    echo "  java          Format only Java files"
    echo "  ts            Format only TypeScript files"
    echo "  cpp           Format only C/C++ files"
    echo "  csharp        Format only C# files"
    echo "  haxe          Format only Haxe files"
    echo "  dart          Format only Dart files"
    echo "  swift         Format only Swift files"
    echo ""
    echo "If no language flags are specified, all languages will be formatted."
    echo "Multiple language flags can be combined, e.g.: ./format.sh java ts"
    echo ""
    echo "Tools used:"
    echo "  Java:       Eclipse formatter (via eclipse-formatter.xml)"
    echo "  TypeScript: tsfmt (typescript-formatter)"
    echo "  C/C++:      clang-format"
    echo "  C#:         dotnet format"
    echo "  Haxe:       haxe formatter"
    echo "  Dart:       dart format"
    echo "  Swift:      swift-format"
    exit 0
}

# If any language flags are specified, disable all by default
if [[ "$*" == *"java"* ]] || [[ "$*" == *"ts"* ]] || [[ "$*" == *"cpp"* ]] || [[ "$*" == *"csharp"* ]] || [[ "$*" == *"haxe"* ]] || [[ "$*" == *"dart"* ]] || [[ "$*" == *"swift"* ]]; then
    FORMAT_JAVA=false
    FORMAT_TS=false
    FORMAT_CPP=false
    FORMAT_CSHARP=false
    FORMAT_HAXE=false
    FORMAT_DART=false
    FORMAT_SWIFT=false
fi

# Parse arguments
while [[ $# -gt 0 ]]; do
    case $1 in
        --help|-h)
            show_help
            ;;
        java)
            FORMAT_JAVA=true
            shift
            ;;
        ts)
            FORMAT_TS=true
            shift
            ;;
        cpp)
            FORMAT_CPP=true
            shift
            ;;
        csharp)
            FORMAT_CSHARP=true
            shift
            ;;
        haxe)
            FORMAT_HAXE=true
            shift
            ;;
        dart)
            FORMAT_DART=true
            shift
            ;;
        swift)
            FORMAT_SWIFT=true
            shift
            ;;
        *)
            log_fail "Unknown option: $1"
            log_detail "Use --help for usage information"
            exit 1
            ;;
    esac
done

log_title "Code Formatting"

# Call individual formatter scripts
if [ "$FORMAT_CPP" = true ]; then
    log_section "C/C++"
    log_action "Formatting C/C++ files"
    "$dir/format-cpp.sh"
    log_ok "C/C++ formatting completed"
fi

if [ "$FORMAT_JAVA" = true ]; then
    log_section "Java"
    log_action "Formatting Java files"
    "$dir/format-java.sh"
    log_ok "Java formatting completed"
fi

if [ "$FORMAT_CSHARP" = true ]; then
    log_section "C#"
    log_action "Formatting C# files"
    "$dir/format-csharp.sh"
    log_ok "C# formatting completed"
fi

if [ "$FORMAT_TS" = true ]; then
    log_section "TypeScript"
    log_action "Formatting TypeScript files"
    "$dir/format-ts.sh"
    log_ok "TypeScript formatting completed"
fi

if [ "$FORMAT_DART" = true ]; then
    log_section "Dart"
    log_action "Formatting Dart files"
    "$dir/format-dart.sh"
    log_ok "Dart formatting completed"
fi

if [ "$FORMAT_HAXE" = true ]; then
    log_section "Haxe"
    log_action "Formatting Haxe files"
    "$dir/format-haxe.sh"
    log_ok "Haxe formatting completed"
fi

if [ "$FORMAT_SWIFT" = true ]; then
    log_section "Swift"
    log_action "Formatting Swift files"
    "$dir/format-swift.sh"
    log_ok "Swift formatting completed"
fi

log_summary "✓ All formatting completed"