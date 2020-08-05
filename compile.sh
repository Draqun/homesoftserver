#!/usr/bin/env bash

CC=x86_64-w64-mingw32-gcc cmake -S . -B build
CC=x86_64-w64-mingw32-gcc cmake --build build
