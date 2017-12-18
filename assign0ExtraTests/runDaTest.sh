!#/bin/bash

echo "Running other kid's da test..."

make

gcc test-da.c da.o ../integerClass/integer.o

./a.out
