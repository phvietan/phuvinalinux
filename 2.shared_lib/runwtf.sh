#!/bin/bash

# Step 1
gcc -c -Wall -Werror -fpic random.c

# Step 2 wtf
mv random.o librandom.so

# Step 3
gcc -L$PWD -Wall -o main main.c -lrandom
./main
