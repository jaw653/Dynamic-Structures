!#/bin/bash

echo "Running Jake's da test..."

make

gcc personalDAtest.c da.o ../integerClass/integer.o

./a.out
