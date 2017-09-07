#Author: Jake Wachs
#Date: 08/26/17
#University of Alabama
#This is the generic makefile for the data structures created

#REMEMBER TO REMOVE -C COMPILE FLAG!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
OPTS = -Wall -Wextra -std=c99

all: da.o cda.o stack.o queue.o

#fix files to be compiled when you figure our what all their names should be
da.o: da.c
	gcc $(OPTS) da.c -c

cda.o: cda.c
	gcc $(OPTS) cda.c -c

stack.o: stack.c
	gcc $(OPTS) stack.c -c

queue.o: queue.c
	gcc $(OPTS) queue.c -c

#fix files to remove once you find out what all their names will be
clean:
	 rm -rf main *.o
