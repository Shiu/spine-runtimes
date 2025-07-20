#!/bin/bash
set -e

cd "$(dirname "$0")"

# Source logging utilities
source ../formatters/logging/logging.sh

currentVersion=$(grep -o '"version": "[^"]*' haxelib.json | grep -o '[^"]*$')

major=$(echo "$currentVersion" | cut -d. -f1)
minor=$(echo "$currentVersion" | cut -d. -f2)
patch=$(echo "$currentVersion" | cut -d. -f3)
newPatch=$((patch + 1))
newVersion="$major.$minor.$newPatch"

log_title "Spine-Haxe Publish"

log_section "Version Update"
log_detail "Current version: $currentVersion"
log_detail "New version: $newVersion"

log_action "Updating haxelib.json"
sed -i '' "s/$currentVersion/$newVersion/" haxelib.json
log_ok "Version updated in haxelib.json"

log_section "Confirm"
echo "Write Y if you want to commit and push the new version $newVersion."
echo "This will trigger a pipeline that will publish the new version on esoteric software server."
echo "Do you want to proceed [y/n]?"

read answer
if [ "$answer" = "Y" ] || [ "$answer" = "y" ]; then
    log_section "Publish"
    log_action "Committing changes"
    git add haxelib.json
    git commit -m "[haxe] Release $newVersion"
    log_ok "Changes committed"
    
    log_action "Pushing to origin"
    if git push origin 4.2; then
        log_ok "Changes pushed"
        log_summary "✓ Version $newVersion published successfully"
    else
        log_fail "Push failed"
        exit 1
    fi
else
    log_skip "Commit and push cancelled"
    log_summary "Version updated locally only"
fi