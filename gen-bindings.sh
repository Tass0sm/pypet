#!/usr/bin/env bash

binder --root-module petpy \
       --prefix ./bindings/source \
       --bind "" \
       -v \
       all_includes.hpp \
       -- \
       -std=c++11 \
       -I$PWD/../pet/include \
       -iwithsysroot/usr/lib/clang/14.0.6/include


       # -I/usr/include/linux \
       # -I/home/tassos/work/quantum/polyhedral-work/binder/prefix/llvm/libcxx/include/
