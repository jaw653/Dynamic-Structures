!#/bin/bash

echo "Running Jake stack test..."

make

gcc personalStackTest.c da.o stack.o ../integerClass/integer.o

./a.out
