#!/bin/bash

# Supposed to flatten a directory structure into only 1 layer of depth

# Throws annoying errors
shopt -s globstar
[ -n $1 ] && mv $1/*/** $1/ || rmdir $1/*
shopt -u globstar