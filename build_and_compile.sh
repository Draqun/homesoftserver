#!/usr/bin/env bash

docker build -t cmpl . && MSYS_NO_PATHCONV=1 docker run --rm -v ${PWD}:/app cmpl
