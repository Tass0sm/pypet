#!/usr/bin/env bash

g++ -o pypet.so \
    -Wl,--no-undefined \
    -shared pet.o pypet.o \
    -lpython3.10 -lpet -lisl
