#!/bin/bash
set -e

# Format C/C++ files with clang-format
echo "Formatting C/C++ files..."

dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"

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