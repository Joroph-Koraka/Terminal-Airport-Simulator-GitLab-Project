#!/bin/bash
find ./ -iname "*.h" -o -iname "*.cpp" | xargs clang-format --sort-includes -i -output-replacements-xml | grep "<replacement " >/dev/null
if [ $? -ne 1 ]; then 
    echo "Files did not match clang-format"
    exit 1
fi
