#!/bin/bash

echo "Running stack test from aloung..."

make

gcc test-stack.c da.o stack.o ../integerClass/integer.o

./a.out
