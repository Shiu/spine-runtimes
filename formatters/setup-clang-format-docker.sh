#!/bin/bash
set -e

echo "Setting up clang-format Docker wrapper..."

# Pull the Docker image with clang-format 18
echo "Pulling Docker image..."
docker pull silkeh/clang:18

# Create a wrapper script that runs clang-format in Docker
echo "Creating wrapper script..."
cat > /tmp/clang-format-wrapper <<'EOF'
#!/bin/bash
exec docker run --rm -i -v "$PWD:$PWD" -w "$PWD" silkeh/clang:18 clang-format "$@"
EOF

# Install the wrapper
sudo mv /tmp/clang-format-wrapper /usr/local/bin/clang-format
sudo chmod +x /usr/local/bin/clang-format

# Verify version and location
echo "Verifying installation..."
which clang-format
clang-format --version