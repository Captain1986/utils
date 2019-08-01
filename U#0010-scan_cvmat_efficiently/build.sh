#!/bin/bash
g++ main.cpp `pkg-config --libs --cflags opencv` -O0 -std=c++11
