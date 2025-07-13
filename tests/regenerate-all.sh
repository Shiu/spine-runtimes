#!/bin/bash

set -e

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$SCRIPT_DIR/.."

echo "Analyzing Java API..."
npx tsx tests/analyze-java-api.ts

echo "Generating Java SkeletonSerializer..."
npx tsx tests/generate-java-serializer.ts

echo "Generating C++ SkeletonSerializer..."
npx tsx tests/generate-cpp-serializer.ts

echo "Done."