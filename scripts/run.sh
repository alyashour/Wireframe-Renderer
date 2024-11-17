#!/bin/bash

# Check if a program name is provided as argument
if [ -z "$1" ]; then
    echo "No program specified, unable to run."
    exit 1
fi

# cd into scripts
cd $(dirname "$0") || { echo "Failed to change directory."; exit 1; }

# Call build.sh to build the program (pass all arguments to build.sh)
APP=$1
./build.sh "$@" || { echo "Build failed."; exit 1; }
PATH="./build/apps/$APP/$APP"
shift

# Navigate to the build
cd ".." || { echo "Failed to change directory."; exit 1; }

# execute the program
if [ -f "$PATH" ]; then
    echo "Running $APP..."
    "$PATH" "$@"  # Pass any additional arguments to the program
else
    echo "Error: Executable '$APP' not found."
    exit 1
fi

echo
