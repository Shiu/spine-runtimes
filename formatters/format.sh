#!/bin/bash
set -e
dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"

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
    echo "Spine Runtimes Code Formatter"
    echo ""
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
    echo "  Java:       Spotless with Eclipse formatter"
    echo "  TypeScript: Biome"
    echo "  C/C++:      clang-format"
    echo "  C#:         dotnet-format"
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
            echo "Unknown option: $1"
            echo "Use --help for usage information"
            exit 1
            ;;
    esac
done

# Stay in formatters directory and use relative paths
# cd $dir/..

# Format C/C++ files with clang-format
if [ "$FORMAT_CPP" = true ]; then
    echo "Formatting C/C++ files..."
    if [ ! -f "$dir/.clang-format" ]; then
        echo "Error: .clang-format not found in formatters directory"
        exit 1
    fi

    # Define C/C++ source directories - be specific to avoid engine sources
    cpp_dirs=(
        # spine-cpp
        "../spine-cpp/include/spine"
        "../spine-cpp/src/spine"
        "../spine-cpp/spine-cpp-lite"
        "../spine-cpp/tests"
        
        # spine-c
        "../spine-c/include"
        "../spine-c/src"
        "../spine-c/src/generated"
        "../spine-c/tests"
        
        # spine-godot
        "../spine-godot/spine_godot"
        
        # spine-ue
        "../spine-ue/Source/SpineUE"
        "../spine-ue/Plugins/SpinePlugin/Source/SpinePlugin/Public"
        "../spine-ue/Plugins/SpinePlugin/Source/SpinePlugin/Private"
        "../spine-ue/Plugins/SpinePlugin/Source/SpineEditorPlugin/Public"
        "../spine-ue/Plugins/SpinePlugin/Source/SpineEditorPlugin/Private"
        
        # spine-glfw
        "../spine-glfw/src"
        "../spine-glfw/example"
        
        # spine-sdl
        "../spine-sdl/src"
        "../spine-sdl/example"
        
        # spine-sfml
        "../spine-sfml/c/src/spine"
        "../spine-sfml/c/example"
        "../spine-sfml/cpp/src/spine"
        "../spine-sfml/cpp/example"
        
        # spine-cocos2dx
        "../spine-cocos2dx/spine-cocos2dx/src/spine"
        "../spine-cocos2dx/example/Classes"
        
        # spine-ios
        "../spine-ios/Sources/SpineCppLite"
        "../spine-ios/Sources/SpineCppLite/include"
        "../spine-ios/Sources/SpineShadersStructs"
        "../spine-ios/Example/Spine iOS Example"
        
        # spine-flutter
        "../spine-flutter/ios/Classes"
        "../spine-flutter/macos/Classes"
        "../spine-flutter/src"
    )

    # Collect all C/C++ files from specified directories
    files=()
    for cpp_dir in "${cpp_dirs[@]}"; do
        if [ -d "$cpp_dir" ]; then
            while IFS= read -r -d '' file; do
                files+=("$file")
            done < <(find "$cpp_dir" \( -name "*.c" -o -name "*.cpp" -o -name "*.h" \) \
                     -not -path "*/.*" \
                     -not -path "*/build/*" \
                     -not -path "*/cmake-build-*/*" \
                     -not -path "*/third_party/*" \
                     -not -path "*/external/*" \
                     -not -type l \
                     -print0)
        fi
    done

    echo "Found ${#files[@]} C/C++ files to format"

    # Format each file with progress
    count=0
    errors=0
    for file in "${files[@]}"; do
        count=$((count + 1))
        # Show progress every 10 files or for the last file
        if [ $((count % 10)) -eq 0 ] || [ $count -eq ${#files[@]} ]; then
            printf "\r[$count/${#files[@]}] Formatting: %-80s" "$(basename "$file")"
        fi

        # Format the file and capture any errors
        if ! clang-format -i -style=file:"$dir/.clang-format" "$file" 2>/dev/null; then
            printf "\nError formatting: $file\n"
            errors=$((errors + 1))
        fi
    done

    # Clear the progress line and show completion
    printf "\r%-100s\r" " "
    
    if [ $errors -gt 0 ]; then
        echo "Completed with $errors errors"
    fi

    echo "C/C++ formatting complete"
fi

# Format Java files with Spotless (keeping this for Eclipse formatter)
if [ "$FORMAT_JAVA" = true ]; then
    echo "Formatting Java files..."
    ./formatters/gradlew -p formatters spotlessJavaApply --quiet
fi

# Format C# files with dotnet-format
if [ "$FORMAT_CSHARP" = true ]; then
    echo "Formatting C# files..."
    if command -v dotnet-format &> /dev/null; then
        # Copy .editorconfig to C# directories
        cp .editorconfig ../spine-csharp/ 2>/dev/null || true
        cp .editorconfig ../spine-monogame/ 2>/dev/null || true
        cp .editorconfig ../spine-unity/ 2>/dev/null || true

        dotnet-format ../spine-csharp/spine-csharp.sln || true
        dotnet-format -f ../spine-monogame || true
        dotnet-format -f ../spine-unity || true

        # Clean up .editorconfig files
        rm -f ../spine-csharp/.editorconfig
        rm -f ../spine-monogame/.editorconfig
        rm -f ../spine-unity/.editorconfig
    else
        echo "Warning: dotnet-format not found. Skipping C# formatting."
    fi
fi

# Format TypeScript files with Biome
if [ "$FORMAT_TS" = true ]; then
    echo "Formatting TypeScript files..."
    # Check if biome.json files match
    if ! cmp -s ../spine-ts/biome.json ../tests/biome.json; then
        echo -e "\033[1;31mERROR: spine-ts/biome.json and tests/biome.json differ!\033[0m"
        echo -e "\033[1;31mPlease sync them to ensure consistent formatting.\033[0m"
        exit 1
    fi

    # Format TypeScript files
    cd ../spine-ts && npx biome format --write . && cd ../formatters
    cd ../tests && npx biome format --write --config-path ../spine-ts . && cd ../formatters
fi

# Format Dart files
if [ "$FORMAT_DART" = true ]; then
    echo "Formatting Dart files..."
    if command -v dart &> /dev/null; then
        find .. -name "*.dart" \
            -not -path "*/.*" \
            -not -path "*/node_modules/*" \
            -not -path "*/build/*" \
            -exec dart format {} +
    else
        echo "Warning: dart not found. Skipping Dart formatting."
    fi
fi

# Format Haxe files
if [ "$FORMAT_HAXE" = true ]; then
    echo "Formatting Haxe files..."
    if command -v haxelib &> /dev/null && haxelib list formatter &> /dev/null; then
        find .. -name "*.hx" \
            -not -path "*/.*" \
            -not -path "*/node_modules/*" \
            -not -path "*/build/*" \
            | xargs haxelib run formatter -s
    else
        echo "Warning: haxe formatter not found. Install with: haxelib install formatter"
    fi
fi

# Format Swift files
if [ "$FORMAT_SWIFT" = true ]; then
    echo "Formatting Swift files..."
    if command -v swift-format &> /dev/null; then
        find .. -name "*.swift" \
            -not -path "*/.*" \
            -not -path "*/build/*" \
            -not -path "*/DerivedData/*" \
            | xargs swift-format -i
    else
        echo "Warning: swift-format not found. Install from https://github.com/apple/swift-format"
    fi
fi

echo "Formatting complete!"