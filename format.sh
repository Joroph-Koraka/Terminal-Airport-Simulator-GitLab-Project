#!/bin/bash

# Spell check
codespell -f -w .

# Format C++
find ./ -iname "*.h" -o -iname "*.cpp" ! -iname "fix*" | xargs clang-format --sort-includes -i
cpplint --recursive --quiet src

# Clean up
find . -name "a.out" -exec /bin/rm -f {} +
find . -name "*.o" -exec /bin/rm -f {} +
