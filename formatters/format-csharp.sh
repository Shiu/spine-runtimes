#!/bin/bash
set -e

# Format C# files with dotnet-format
echo "Formatting C# files..."

dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"

if command -v dotnet &> /dev/null; then
    # Copy .editorconfig to C# directories
    cp .editorconfig ../spine-csharp/ 2>/dev/null || true
    cp .editorconfig ../spine-monogame/ 2>/dev/null || true
    cp .editorconfig ../spine-unity/ 2>/dev/null || true

    # Format spine-csharp
    cd ../spine-csharp && dotnet format spine-csharp.csproj || echo "Warning: Some issues with spine-csharp formatting"
    cd ../formatters
    
    # Format spine-monogame
    cd ../spine-monogame && dotnet format --no-restore || echo "Warning: Some issues with spine-monogame formatting"
    cd ../formatters
    
    # Format spine-unity - look for .cs files directly
    if [ -d ../spine-unity ]; then
        echo "Formatting spine-unity C# files directly..."
        cd ../spine-unity
        # Find all .cs files and format them using dotnet format whitespace
        find . -name "*.cs" -type f -not -path "./Library/*" -not -path "./Temp/*" -not -path "./obj/*" -not -path "./bin/*" | while read -r file; do
            dotnet format whitespace --include "$file" --no-restore 2>/dev/null || true
        done
        cd ../formatters
    fi

    # Clean up .editorconfig files
    rm -f ../spine-csharp/.editorconfig
    rm -f ../spine-monogame/.editorconfig
    rm -f ../spine-unity/.editorconfig
else
    echo "Warning: dotnet not found. Skipping C# formatting."
fi