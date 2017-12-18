#!/bin/bash

echo "Running other kid's test..."

make

gcc test-cda.c cda.o ../integerClass/integer.o

./a.out
