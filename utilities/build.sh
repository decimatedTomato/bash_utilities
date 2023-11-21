#!/bin/sh

set -xe
# I wonder if I am using pedantic correctly
gcc print_clip.c -o print_clip.exe -Wextra -Wall -pedantic
gcc clip.c -o clip.exe -Wextra -Wall -pedantic