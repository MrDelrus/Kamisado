#!/bin/bash

mkdir -p build
(
cd build || exit
cmake -DASSETS_DIR=assets -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..
make
./Kamisado ../assets
)