#!/bin/bash
set -e

# Format Java files with Eclipse formatter
echo "Formatting Java files..."

dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"

# Store original directory
pushd "$dir" > /dev/null

# Build the Eclipse formatter if needed
jar_file="eclipse-formatter/target/eclipse-formatter-1.0.0-jar-with-dependencies.jar"
src_file="eclipse-formatter/src/main/java/com/esotericsoftware/spine/formatter/EclipseFormatter.java"

if [ ! -f "$jar_file" ] || [ "$src_file" -nt "$jar_file" ]; then
    echo "Building Eclipse formatter..."
    pushd eclipse-formatter > /dev/null
    mvn -q clean package
    popd > /dev/null
fi

# Find all Java files
java_files=$(find ../spine-libgdx ../spine-android -name "*.java" -type f \
    -not -path "*/build/*" \
    -not -path "*/.gradle/*" \
    -not -path "*/bin/*" \
    -not -path "*/gen/*" \
    -not -path "*/target/*")

# Run the formatter
if [ -n "$java_files" ]; then
    echo "Running Eclipse formatter on Java files..."
    java -jar eclipse-formatter/target/eclipse-formatter-1.0.0-jar-with-dependencies.jar \
        eclipse-formatter.xml \
        $java_files
fi

echo "Java formatting complete"

# Return to original directory
popd > /dev/null