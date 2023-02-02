#!/bin/bash

cd build

[ $# -eq 1 ] && cmake ..

make && ./app