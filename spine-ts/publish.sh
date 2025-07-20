#!/bin/bash
set -e
cd "$(dirname "$0")"

# Source logging utilities
source ../formatters/logging/logging.sh

log_title "Spine TypeScript Publisher"

# Get current version
currentVersion=$(grep -o '"version": "[^"]*' package.json | grep -o '[^"]*$')
major=$(echo "$currentVersion" | cut -d. -f1)
minor=$(echo "$currentVersion" | cut -d. -f2)
patch=$(echo "$currentVersion" | cut -d. -f3)
newPatch=$((patch + 1))
newVersion="$major.$minor.$newPatch"

log_section "Version Management"
log_detail "Current version: $currentVersion"
log_detail "New version: $newVersion"

log_section "Updating Package Versions"
packages=(
    "package.json"
    "spine-canvas/package.json"
    "spine-canvaskit/package.json"
    "spine-core/package.json"
    "spine-phaser-v3/package.json"
    "spine-phaser-v4/package.json"
    "spine-pixi-v7/package.json"
    "spine-pixi-v8/package.json"
    "spine-player/package.json"
    "spine-threejs/package.json"
    "spine-webgl/package.json"
    "spine-webcomponents/package.json"
)

for package in "${packages[@]}"; do
    log_action "Updating $package"
    if sed -i '' "s/$currentVersion/$newVersion/" "$package" 2>/dev/null; then
        log_ok "Updated $package"
    else
        log_fail "Failed to update $package"
        exit 1
    fi
done

log_section "Preparing for Publish"
log_action "Removing package-lock.json"
if rm package-lock.json 2>/dev/null; then
    log_ok "Removed package-lock.json"
else
    log_warn "package-lock.json not found or already removed"
fi

log_action "Cleaning @esotericsoftware modules"
if rm -rf node_modules/@esotericsoftware 2>/dev/null; then
    log_ok "Cleaned @esotericsoftware modules"
else
    log_warn "@esotericsoftware modules not found or already removed"
fi

log_section "Installing Dependencies"
log_action "Installing workspace dependencies"
if output=$(npm install --workspaces 2>&1); then
    log_ok "Dependencies installed successfully"
else
    log_fail "Failed to install dependencies"
    log_detail "$output"
    exit 1
fi

log_section "Publishing to NPM"
log_action "Publishing all workspaces"
if output=$(npm publish --access public --workspaces 2>&1); then
    log_ok "Successfully published all packages to NPM"
    log_summary "TypeScript packages published successfully with version $newVersion"
else
    log_fail "Failed to publish packages"
    log_detail "$output"
    exit 1
fi