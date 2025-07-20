#!/bin/bash
set -e
cd "$(dirname "$0")"

# Source logging utilities
source ../formatters/logging/logging.sh

log_title "Spine Android Publisher"

log_detail "Modern Central Portal Publishing Setup:"
log_detail "1. Set up PGP key for signing: gpg --generate-key"
log_detail "2. Create Central Portal account at https://central.sonatype.com/"
log_detail "3. Generate user token in Central Portal settings"
log_detail "4. Create ~/.gradle/gradle.properties with:"
log_detail "   MAVEN_USERNAME=<central-portal-username>"
log_detail "   MAVEN_PASSWORD=<central-portal-token>"
log_detail "   signing.gnupg.passphrase=<pgp-key-passphrase>"
log_detail ""
log_detail "Version Configuration:"
log_detail "- Edit spine-libgdx/gradle.properties and update the 'version' property (single source of truth)"
log_detail "- For releases: version=4.2.9 (no -SNAPSHOT suffix)"
log_detail "- For snapshots: version=4.2.9-SNAPSHOT (with -SNAPSHOT suffix)"

log_section "Reading Version Configuration"
log_action "Reading version from spine-libgdx gradle.properties"
if VERSION=$(grep '^version=' ../spine-libgdx/gradle.properties | cut -d'=' -f2); then
    log_ok "Version found: $VERSION"
else
    log_fail "Failed to read version from ../spine-libgdx/gradle.properties"
    exit 1
fi

log_section "Publishing to Central Portal"
if echo "$VERSION" | grep -q "SNAPSHOT"; then
    log_detail "Detected SNAPSHOT version"
    log_action "Publishing SNAPSHOT version $VERSION to Central Portal"
    if output=$(./gradlew :spine-android:publishReleasePublicationToSonaTypeRepository --info 2>&1); then
        log_ok "Successfully published SNAPSHOT version $VERSION"
        log_summary "Android SNAPSHOT published successfully to Central Portal"
    else
        log_fail "Failed to publish SNAPSHOT version"
        log_detail "$output"
        exit 1
    fi
else
    log_detail "Detected RELEASE version"
    log_action "Publishing RELEASE version $VERSION to Central Portal via JReleaser"
    
    log_action "Publishing to SonaType repository"
    if output=$(./gradlew :spine-android:publishReleasePublicationToSonaTypeRepository -PRELEASE 2>&1); then
        log_ok "Successfully published to SonaType repository"
    else
        log_fail "Failed to publish to SonaType repository"
        log_detail "$output"
        exit 1
    fi
    
    log_action "Deploying via JReleaser"
    if output=$(./gradlew :spine-android:jreleaserDeploy -PRELEASE --info 2>&1); then
        log_ok "Successfully deployed via JReleaser"
        log_summary "Android RELEASE published successfully to Central Portal"
    else
        log_fail "Failed to deploy via JReleaser"
        log_detail "$output"
        exit 1
    fi
fi