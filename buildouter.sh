#!/bin/bash

Target=$1||$(pwd)
cd ..
./build.sh
cd $Target
