#Author: Jake Wachs
#Date: 08/26/17
#University of Alabama
#This is the generic makefile for the data structures created

#REMEMBER TO REMOVE -C COMPILE FLAG!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
OPTS = -Wall -Wextra -std=c99
OBJS = da.o cda.o stack.o queue.o integer.o

all: $(OBJS)

test: $(OBJS) test-da.o test-cda.o test-stack.o test-queue.o
	./runDATest
	./runCDATest
	./runStackTest
	./runQueueTest

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

#fix files to remove once you find out what all their names will be
clean:
	 rm -rf *.o ./a.out runDATest runCDATest runStackTest runQueueTest

#*************************#
test-da.o: test-da.c da.o integer.o
	gcc $(OPTS) test-da.c da.o integer.o -o runDATest

test-cda.o: test-cda.c cda.o integer.o
	gcc $(OPTS) test-cda.c cda.o integer.o -o runCDATest

test-stack.o: test-stack.c stack.o da.o integer.o
	gcc $(OPTS) test-stack.c stack.o da.o integer.o -o runStackTest

test-queue.o: test-queue.c queue.o cda.o integer.o
	gcc $(OPTS) test-queue.c queue.o cda.o integer.o -o runQueueTest
