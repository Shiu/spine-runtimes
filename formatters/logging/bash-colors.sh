#!/bin/bash
# Bash color and formatting utilities
# Source this file in your bash scripts for colored output

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
MAGENTA='\033[0;35m'
CYAN='\033[0;36m'
WHITE='\033[0;37m'
GRAY='\033[0;90m'

# Bright colors
BRIGHT_RED='\033[0;91m'
BRIGHT_GREEN='\033[0;92m'
BRIGHT_YELLOW='\033[0;93m'
BRIGHT_BLUE='\033[0;94m'
BRIGHT_MAGENTA='\033[0;95m'
BRIGHT_CYAN='\033[0;96m'
BRIGHT_WHITE='\033[0;97m'

# Background colors
BG_RED='\033[41m'
BG_GREEN='\033[42m'
BG_YELLOW='\033[43m'
BG_BLUE='\033[44m'
BG_MAGENTA='\033[45m'
BG_CYAN='\033[46m'
BG_WHITE='\033[47m'

# Text styles
BOLD='\033[1m'
DIM='\033[2m'
UNDERLINE='\033[4m'
BLINK='\033[5m'
REVERSE='\033[7m'
STRIKETHROUGH='\033[9m'

# Reset
NC='\033[0m' # No Color

# Design principles:
# 1. Minimal visual noise - use color sparingly for emphasis
# 2. Clear hierarchy - different levels of information have different treatments  
# 3. Consistent spacing - clean vertical rhythm
# 4. Accessible - readable without colors

# Main header for script/tool name
log_title() {
    echo ""
    echo -e "${BOLD}$1${NC}"
    echo ""
}

# Section headers for major phases
log_section() {
    echo -e "${BOLD}${BLUE}$1${NC}"
}

# Individual actions/steps
log_action() {
    echo -e "  $1..."
}

# Results - success/failure/info
log_ok() {
    echo -e "  ${GREEN}✓${NC} $1"
}

log_fail() {
    echo -e "  ${RED}✗${NC} $1"
}

log_warn() {
    echo -e "  ${YELLOW}!${NC} $1"
}

log_skip() {
    echo -e "  ${GRAY}-${NC} $1"
}

# Final summary
log_summary() {
    echo ""
    echo -e "${BOLD}$1${NC}"
}

# Detailed output (errors, etc.)
log_detail() {
    echo -e "${GRAY}$1${NC}"
}