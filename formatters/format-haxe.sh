#!/bin/bash
set -e

# Format Haxe files
echo "Formatting Haxe files..."

dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"

# Store original directory
pushd "$dir" > /dev/null

if command -v haxelib &> /dev/null && haxelib list formatter &> /dev/null; then
    # Format spine-haxe directory
    if [ -d ../spine-haxe ]; then
        haxelib run formatter -s ../spine-haxe
    fi
else
    echo "Warning: haxe formatter not found. Install with: haxelib install formatter"
fi

# Return to original directory
popd > /dev/null