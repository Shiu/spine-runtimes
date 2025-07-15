#!/bin/bash

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
pushd "$SCRIPT_DIR" > /dev/null

echo "Analyzing Java API..."
npx tsx src/analyze-java-api.ts

echo "Generating serializer IR..."
npx tsx src/generate-serializer-ir.ts

echo "Generating Java SkeletonSerializer..."
npx tsx src/generate-java-serializer.ts

echo "Generating C++ SkeletonSerializer..."
npx tsx src/generate-cpp-serializer.ts

echo "Done."
popd > /dev/null