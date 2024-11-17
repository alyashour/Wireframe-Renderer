#!/bin/bash

# Get the directory where the script is located
SCRIPT_DIR=$(dirname "$0")

# Navigate to build
cd "$SCRIPT_DIR/../build" || { echo "Failed to change directory."; exit 1; }

# Check if a program name is provided
if [ -z "$1" ]; then
    # No argument provided, make all
    echo "making all"
    make
else
    # A program name is provided, shift and build that specific program
    PROGRAM=$1
    shift
    echo "building $PROGRAM..."
    
    # Run make with the provided program
    make $PROGRAM
fi
