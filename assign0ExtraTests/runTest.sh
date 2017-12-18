#!/bin/bash

echo "Running test..."

make

gcc personalCDAtest.c cda.o ../integerClass/integer.o

./a.out
