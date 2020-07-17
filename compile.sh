#!/usr/bin/env bash
autoreconf --install
mkdir build
cd build/
CC=x86_64-w64-mingw32-gcc ../configure --host=x86
make
