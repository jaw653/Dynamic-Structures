/*Author: Jake Wachs
 *Date: 08/26/17
 *University of Alabama
 *This file serves as method implementations for the
 *dynamic array object
 */

 /*
  *Questions:
  *-remove function in this class returned items instead of tmp, check the other classes for similar mistake...
  *-for setDA, shoudl i make the if statement if it is equal to size - 1 or just size?
  *-to fix potential comma problem in display: if (index != backIndex) print comma
  *-should we initialize array to size 2?
  *-give lusth credit for making node.c, node.h, da.h files
  *-need to add assertions for most functions
  *-can i have all the libraries i imported?
  *-tried to implement this file in stack.c and got compiler error "incomplete type"
  */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "da.h"

struct da {
  void (*display)(FILE *, void*);
  int size;
  int filledIndices;
  void **array;
};

DA *newDA(void (*d)(FILE *, void *)) {
  assert( sizeof(DA) != 0 );

  DA *arr = malloc( sizeof(DA) );

  arr->array = malloc( 1 * sizeof(void*) );
  arr->display = d;
  arr->size = 1;
  arr->filledIndices = 0;

  return arr;
}

void insertDA(DA *items, void *value) {
  //FIXME: Add assertion that mem allocated shall not be zero

  //If there is room in the array for the insert
  if ( items->filledIndices <= items->size ) {
    items->array[items->filledIndices] = value;
    items->filledIndices += 1;
  }

  else {
    assert(sizeof(void*) * items->size * 2 != 0);

    items->array = realloc( items->array, 2 * items->size * sizeof(void*) );

    items->array[items->filledIndices] = value;

    items->size *= 2;
    items->filledIndices += 1;
  }

  return;
}

void *removeDA(DA *items) {
  //FIXME: The rubric says that the array should never shrink below the size of 1...what about initiaizing it to size 0?
  assert(items->filledIndices > 0);

  void *tmp = items->array[items->filledIndices];
  items->array[items->filledIndices] = NULL;
  items->filledIndices -= 1;

  if ( items->filledIndices < .25 * items->size ) {     //FIXME: < or <= ?

    items->array = realloc( items->array, (items->size/2) * sizeof(void*) );
  }

  return tmp;
}


void unionDA(DA *recipient, DA *donor) {
  //FIXME: does what i wrote below actually run in linear time?

  int totalSize = recipient->size + donor->size;
  recipient->array = realloc( recipient->array, totalSize * sizeof(void*) );

  int i;
  for (i = recipient->size; i < totalSize; i++) {
    recipient->array[i] = donor->array[i - donor->size];    //FIXME: check this to see if the logic of the algo is correct. trying to append each element onto the end of the array that is now double the size
  }

  donor = NULL;
}

void *getDA(DA *items, int index) {
  assert(index >= 0 && index < items->filledIndices);
  return items->array[index];
}

void *setDA(DA *items, int index, void *value) {
  assert(index >= 0 && index <= items->filledIndices);  //FIXME: Add assertion that the index shall be >= 0 and <= size

  void *replacedVal;

  if (index <= items->size) {
    replacedVal = items->array[index];
    items->array[index] = value;
  }
  else {
    insertDA(items, value);
    replacedVal = NULL;
  }

  return replacedVal;
}

void **extractDA(DA *items) {
   assert( items->filledIndices * sizeof(void*) != 0 );

   items->array = realloc( items->array, items->filledIndices * sizeof(void*) );
   void **newArr = items->array;
   items->array = realloc( items->array, sizeof(void*) );
   items->size = 1;
   items->filledIndices = 0;

   return newArr;
}

int sizeDA(DA *items) {
  return items->filledIndices;
}

void visualizeDA(FILE *fp, DA *items) {
  int remaining = items->size - items->filledIndices;

  fprintf(fp, "[");

  if (items->filledIndices != 0) {
    int i;
    for (i = 0; i < items->filledIndices; i++) {
      items->display(fp, items->array[i]);
      if (i != items->filledIndices - 1) { fprintf(fp, ","); }
    }
  }

  fprintf(fp, "]");

  fprintf(fp, "[%d]", remaining);
}

void displayDA(FILE *fp, DA *items) {
  fprintf(fp, "[");

  if (items->filledIndices != 0) {
    int i;
    for (i = 0; i < items->filledIndices; i++) {
      items->display(fp, items->array[i]);
      if (i != items->filledIndices - 1) { fprintf(fp, ","); }
    }
  }

  fprintf(fp, "]");
}
