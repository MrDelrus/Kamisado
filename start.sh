#!/bin/bash

mkdir -p build
(
cd build || exit
cmake -DSCRIPTS_DIR=src -DASSETS_DIR=assets ..
make
./Kamisado ../assets
)
rm -r build