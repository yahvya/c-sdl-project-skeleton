#!/bin/bash

export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0

cd build

[ $# -eq 1 ] && rm -r * && cmake ..

make && clear && valgrind ./app