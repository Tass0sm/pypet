#!/usr/bin/env bash

g++ -o petpy.so \
    -Wl,--no-undefined \
    -shared pet.o petpy.o \
    -lpython3.10 -lpet -lisl
