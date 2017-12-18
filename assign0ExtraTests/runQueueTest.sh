!#/bin/bash

echo "Running other kid's queue test..."

make

gcc test-queue.c cda.o queue.o ../integerClass/integer.o

./a.out
