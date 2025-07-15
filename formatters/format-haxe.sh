#!/bin/bash
set -e

# Format Haxe files
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