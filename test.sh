#!/bin/bash

cd build

[ $# -eq 1 ] && cmake ..

make && clear && valgrind ./app