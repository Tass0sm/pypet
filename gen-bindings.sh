#!/usr/bin/env bash

binder --root-module pypet \
       --prefix ./bindings/source \
       --bind "" \
       -v \
       ./bindings/source/all_includes.hpp \
       -- \
       -std=c++11 \
       -I$PWD/pet/include \
       -iwithsysroot/usr/lib/clang/15.0.7/include
