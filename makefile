#Author: Jake Wachs
#Date: 08/26/17
#University of Alabama
#This is the generic makefile for the data structures created

OPTS = -Wall -Wextra -std=c99
OBJS = da.o cda.o stack.o queue.o integer.o
TESTOBJS = test-da.o test-cda.o test-stack.o test-queue.o failed-test.o failed-test2.o failed-test3.o
TESTEXES = runDATest runCDATest runStackTest runQueueTest runFailedTest1 runFailedTest2 runFailedTest3

all: $(OBJS)

test: $(OBJS) $(TESTOBJS)
	#./runFailedTest1
	#./runFailedTest2
	./runFailedTest3
	#./runDATest
	#./runCDATest
	#./runStackTest
	#./runQueueTest

integer.o: integer.c integer.h
	gcc $(OPTS) -c integer.c

da.o: da.c da.h
	gcc $(OPTS) -c da.c

cda.o: cda.c cda.h
	gcc $(OPTS) -c cda.c

stack.o: stack.c stack.h
	gcc $(OPTS) -c stack.c

queue.o: queue.c queue.h
	gcc $(OPTS) -c queue.c

clean:
	 rm -rf *.o $(TESTEXES)

#******************************************************************************#

failed-test.o: da-test-0-5.c da.o integer.o
	gcc $(OPTS) da-test-0-5.c da.o integer.o -o runFailedTest1

failed-test2.o: cda-test-0-4.c cda.o integer.o
	gcc $(OPTS) cda-test-0-4.c cda.o integer.o -o runFailedTest2

failed-test3.o: cda-test-0-5.c cda.o integer.o
	gcc $(OPTS) cda-test-0-5.c cda.o integer.o -o runFailedTest3

test-da.o: test-da.c da.o integer.o
	gcc $(OPTS) test-da.c da.o integer.o -o runDATest

test-cda.o: test-cda.c cda.o integer.o
	gcc $(OPTS) test-cda.c cda.o integer.o -o runCDATest

test-stack.o: test-stack.c stack.o da.o integer.o
	gcc $(OPTS) test-stack.c stack.o da.o integer.o -o runStackTest

test-queue.o: test-queue.c queue.o cda.o integer.o
	gcc $(OPTS) test-queue.c queue.o cda.o integer.o -o runQueueTest
