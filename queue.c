/*Author: Jake Wachs
 *Date: 08/26/17
 *University of Alabama
 *This file serves as method implementations for the
 *dynamic array object
 *
 *Questions:
 *-peekQUEUE currently removes then replaces. Can i write my own method inside of CDA?
 *-add all assertions
 *-for dequeue, we should be returning the dequeue value, correct?
 */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "queue.h"
#include "cda.h"

struct queue {
  CDA *array;
  void (*display)(FILE *, void *);
};

QUEUE *newQUEUE(void (*d)(FILE *, void *)) {
  QUEUE *newQueue = malloc( sizeof(QUEUE) );
  newQueue->array = newCDA(d);

  return newQueue;
}

void enqueue(QUEUE *items, void *value) {
  insertCDAback(items->array, value);
}

void *dequeue(QUEUE *items) {
  return removeCDAfront(items->array);
}

void *peekQUEUE(QUEUE *items) {
  void *valToReturn = removeCDAfront(items->array);
  insertCDAfront(items->array, valToReturn);
  return valToReturn;
}

int sizeQUEUE(QUEUE *items) {
  return sizeCDA(items->array);
}

void displayQUEUE(FILE* fp, QUEUE *items) {
  fprintf(fp, "<");

  if (sizeCDA(items->array) != 0) {
    int i;
    for (i = 0; i < sizeCDA(items->array); i++) {
      items->display(fp, getCDA(items->array, i) );
    }
  }

  fprintf(fp, ">");
}

void visualizeQUEUE(FILE *fp, QUEUE *items) {
  displayCDA(fp, items->array);
}
