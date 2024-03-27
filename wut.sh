#!/bin/bash

arg1="in.txt"
arg2="ls"
arg3="wc"
arg4="out"

# Function to compare outputs
compare_outputs() {
    echo "Comparing outputs..."
    if diff "$1" "$2"; then
        echo "Outputs are identical."
    else
        echo "Outputs are different."
    fi
}

# Running the command < arg1 arg2 | arg3 > arg4
echo "Running '< $arg1 $arg2 | $arg3 > $arg4'..."
output_1=$(mktemp)
output_2=$(mktemp)
{
    $arg2 $arg1 | $arg3
} > "$output_1" 2>&1
$arg3 < "$output_1" > "$output_2" 2>&1

# Running the command ./pipex arg1 arg2 arg3 arg4
echo "Running './pipex $arg1 $arg2 $arg3 $arg4'..."
output_3=$(mktemp)
output_4=$(mktemp)
./pipex "$arg1" "$arg2" "$arg3" "$arg4" > "$output_3" 2>&1

# Comparing outputs
compare_outputs "$output_2" "$output_3"

# Clean up temporary files
rm "$output_1" "$output_2" "$output_3" "$output_4"
