#!/bin/bash
set -e

cd "$(dirname "$0")"

# Source logging utilities
source ../formatters/logging/logging.sh

if [ -z "$GITHUB_REF" ];
then
	BRANCH=$(git symbolic-ref --short -q HEAD)
else
	BRANCH=${GITHUB_REF#refs/heads/}
fi

log_title "Spine-TS Build"
log_detail "Branch: $BRANCH"

log_section "Setup"
log_action "Installing dependencies"
if npm install > /tmp/npm-install.log 2>&1; then
	log_ok "Dependencies installed"
else
	log_fail "npm install failed"
	log_detail "$(cat /tmp/npm-install.log)"
	exit 1
fi

if ! [ -z "$TS_UPDATE_URL" ] && ! [ -z "$BRANCH" ];
then
	log_section "Deploy"
	log_action "Creating artifacts zip"
	zip -j spine-ts.zip \
		spine-core/dist/iife/* \
		spine-canvas/dist/iife/* \
		spine-webgl/dist/iife/* \
		spine-player/dist/iife/* \
		spine-threejs/dist/iife/* \
		spine-pixi-v7/dist/iife/* \
		spine-pixi-v8/dist/iife/* \
		spine-phaser-v3/dist/iife/* \
		spine-phaser-v4/dist/iife/* \
		spine-webcomponents/dist/iife/* \
		spine-core/dist/esm/* \
		spine-canvas/dist/esm/* \
		spine-webgl/dist/esm/* \
		spine-player/dist/esm/* \
		spine-threejs/dist/esm/* \
		spine-pixi-v7/dist/esm/* \
		spine-pixi-v8/dist/esm/* \
		spine-phaser-v3/dist/esm/* \
		spine-phaser-v4/dist/esm/* \
		spine-webcomponents/dist/esm/* \
		spine-player/css/spine-player.css > /dev/null 2>&1
	
	log_action "Uploading to $TS_UPDATE_URL$BRANCH"
	if curl -f -F "file=@spine-ts.zip" "$TS_UPDATE_URL$BRANCH" > /dev/null 2>&1; then
		log_ok "Artifacts deployed"
	else
		log_fail "Upload failed"
		exit 1
	fi
	
	log_summary "✓ Build and deployment successful"
else
	log_skip "Deployment skipped (TS_UPDATE_URL and/or BRANCH not set)"
	log_summary "✓ Build successful"
fi
