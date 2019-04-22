#!/bin/bash

rm -rf build/ insall/ lib/

mkdir build/
cd build/
cmake ..
make -j8
make install
cd ..
