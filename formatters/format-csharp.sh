#!/bin/bash
set -e

# Format C# files with dotnet-format
echo "Formatting C# files..."

dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"

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