#!/bin/bash

# Check if "stdafx.h" is already included
header='#include "stdafx.h"'

# Loop through each .cpp file in the directory
for file in *.cpp; do
    # Check if the file exists and is a regular file
    if [ -f "$file" ]; then
        # Check if the file already contains the include directive
        if ! grep -q "$header" "$file"; then
            # Add the include directive to the beginning of the file
            echo "$header" | cat - "$file" > temp && mv temp "$file"
            echo "Added $header to $file"
        else
            echo "$header already exists in $file"
        fi
    fi
done
