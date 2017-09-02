/*Author: Jake Wachs
 *Date: 08/26/17
 *University of Alabama
 *This file serves as method implementations for the
 *circular dynamic array object
 *
 *Questions:
 *-make sure that you added in all assertions
 *-can i add my own "private" helper functions into these classes?
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "cda.h"

struct cda {
  void (*display)(FILE *, void*);
  int frontIndex;
  int backIndex;
  int size;
  int filledIndices;
  void **array;
};

CDA *newCDA(void (*d)(FILE *, void *)) {
    CDA *arr = malloc( sizeof(CDA) );
    assert(sizeof(CDA) != 0);

    arr->array = malloc( 1 * sizeof(void*) );
    arr->display = d;
    arr->size = 1;
    arr->filledIndices = 0;
    arr->frontIndex = 0;
    arr->backIndex = 0;

    return arr;
}

void insertCDAfront(CDA *items, void *value) {
  //If array is empty
  if (items->filledIndices == 0) {
    items->array[0] = value;
    items->filledIndices += 1;
  }
  else {
    if (items->filledIndices == items->size) {
      //If array is full
      if (items->frontIndex != 0) {
        assert( items->size * 2 * sizeof(void*) );
        items->array = realloc( items->array, 2 * items->size * sizeof(void*) );
        items->size *= 2;

        int index = 0;
        while (index <= items->backIndex) {
          items->array[(size/2) + index] = items->array[index];
          items->array[(size/2) + index] = NULL;
          index += 1;
        }
        items->backIndex = size/2 + (index - 1);
      }
    }

    if (items->frontIndex - 1 >= 0) {
      //normal case, just insert
      items->array[items->frontIndex - 1] = value;
      items->frontIndex -= 1;
      items->filledIndices += 1;
    }
    else {
      items->array[items->size - 1] = value;
      items->filledIndices += 1;
      items->frontIndex = items->size - 1;
    }
  }
}
/************* need to find all possible input cases for this and previous insert ***********/
void insertCDAback(DA *items, void *value) {
  //If array is empty
  if (items->filledIndices == 0) {
    items->array[0] = value;
    items->filledIndices += 1;
  }
  else {
    if (items->filledIndices == items->size) {
      if (items->frontIndex != 0) {
        assert( items->size * 2 * sizeof(void*) );
        items->array = realloc( items->array, 2 * items->size * sizeof(void*) );
        items->size *= 2;

        int index = 0;
        while (index <= items->backIndex) {
          items->array[(size/2) + index] = items->array[index];
          items->array[(size/2) + index] = NULL;
          index += 1;
        }
        items->backIndex = size/2 + (index - 1);
      }
    }

    if (items->backIndex + 1 < size) {
      items->array[backIndex + 1] = value;
      items->filledIndices += 1;
      items->backIndex += 1;
    }
    else {
      items->array[0] = value;
      items->filledIndices += 1;
      items->backIndex = 0;
    }
  }
}

void *removeCDAfront(CDA *items) {

}
void *removeCDAback(CDA *items);
void unionCDA(CDA *recipient,CDA *donor);
void *getCDA(CDA *items,int index);
void *setCDA(CDA *items,int index,void *value);
void **extractCDA(CDA *items);
int sizeCDA(CDA *items);
void visualizeCDA(FILE *,CDA *items);
void displayCDA(FILE *,CDA *items);
