/*Author: Jake Wachs
 *Date: 08/26/17
 *University of Alabama
 *This file serves as method implementations for the
 *dynamic array object
 *Questions:
 *-add all assertions
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "stack.h"

struct stack {
  DA *vector;
  void (*display)(FILE *, void*);
};

STACK *newSTACK(void (*d)(FILE *, void *)) {
  STACK *myStack = malloc( sizeof(STACK) );
  myStack->vector = newDA(d);

  return myStack;
}

void push(STACK *items, void *value) {
  insertDA(items->vector, value);
}

void *pop(STACK *items) {
  void *popVal = removeDA(items->vector);
  return popVal;
}

void *peekSTACK(STACK *items) {
  int index = sizeDA(items->vector);
  return getDA(items->vector, index);
}

int sizeSTACK(STACK *items) {
  return sizeDA(items->vector);
}

void displaySTACK(FILE *fp, STACK *items) {
  fprintf(fp, "|");

  if (sizeDA(items->vector) != 0) {
    int i;
    for (i = 0; i < sizeDA(items->vector); i++ ) {
      items->display( fp, getDA(items->vector, i) );
      if (i != sizeSTACK(items) - 1) { fprintf(fp, ","); }
    }
  }

  fprintf(fp, "|");
}

void visualizeSTACK(FILE *fp, STACK *items) {
  displayDA(fp, items->vector);
}
