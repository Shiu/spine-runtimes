#!/bin/bash

set -e
set -o pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
pushd "$SCRIPT_DIR" > /dev/null

echo "Analyzing Java API..."
npx tsx src/analyze-java-api.ts || { echo "Failed to analyze Java API"; exit 1; }

echo "Generating serializer IR..."
npx tsx src/generate-serializer-ir.ts || { echo "Failed to generate IR"; exit 1; }

echo "Generating Java SkeletonSerializer..."
npx tsx src/generate-java-serializer.ts || { echo "Failed to generate Java serializer"; exit 1; }

echo "Generating C++ SkeletonSerializer..."
npx tsx src/generate-cpp-serializer.ts || { echo "Failed to generate C++ serializer"; exit 1; }

echo "Done."
popd > /dev/null