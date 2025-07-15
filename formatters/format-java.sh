#!/bin/bash
set -e

# Format Java files with Spotless (keeping this for Eclipse formatter)
echo "Formatting Java files..."

dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"

./formatters/gradlew -p formatters spotlessJavaApply --quiet