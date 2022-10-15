#!/bin/bash

# Step 1
gcc -c -Wall -Werror -fpic random.c

# Step 2
gcc -shared -o librandom.so random.o

# Step 3 ()
gcc -L$PWD -Wall -o main main.c -lrandom
./main
# => error while loading shared libraries: librandom.so cannot open shared object file: No such file or directory

# Step 4
export LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH
./main
