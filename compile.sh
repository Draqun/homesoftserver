#!/usr/bin/env bash
autoreconf --install
mkdir build
cd build/
../configure && make
