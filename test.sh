#!/bin/bash

cd src

gcc -Wall -O0 $(find . -name "*.c") -lSDL2 -lSDL2_image -o prog  && ./prog && rm prog