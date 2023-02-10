#!/usr/bin/env bash

g++ \
    -I/usr/include/python3.10 \
    -I/usr/include \
    -x c++ -std=c++11 -c bindings/source/pypet.cpp  \
    -o pypet.o -fPIC

g++ \
    -I/usr/include/python3.10 \
    -I/usr/include \
    -x c++ -std=c++11 -c bindings/source/pet.cpp  \
    -o pet.o -fPIC
