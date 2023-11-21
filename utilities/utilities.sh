#!/bin/bash

# Supposed to call one of the other scripts in this directory
# (This is the only script I will alias in the bashrc)

UPATH=$(dirname "$(realpath $0)")

if [ -z $1 ] || [ $1 == "--help" ] || [ $1 == "-h" ]; then
    echo """usage: utility [-v | --version] [-h | --help] <command> [args]
These are your available utility scripts:

  mkfile    Acts like mkdir and touch in one (Creating the subdirectories needed to create the final file)
  flatten   Flattens a directory so that all subdirectories and files are moved to this directory
            (as long as there are no duplicate filenames)
"""
elif [ $1 == "mkfile" ]; then
    shift
    $UPATH/mkfile.sh "$@"
elif [ $1 == "flatten" ]; then
    shift
    $UPATH/flatten.sh "$@"
else
    echo "'$1' not recognized. See 'utility --help'"
fi