/*Author: Jake Wachs
 *Date: 08/26/17
 *University of Alabama
 *This file serves as method implementations for the
 *circular dynamic array object
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
    if (items->frontIndex == 0) {
      //If insert is possible
      if (items->array[items->size-1] == NULL) {
        items->array[items->size-1] == value;
        items->frontIndex = items->size - 1;
        items->filledIndices += 1;
      }
      else {
        assert( items->size * 2 * sizeof(void*) != 0 );
        items->array = realloc(items->array, 2 * items->size * sizeof(void*) );
        items->size *= 2;
        items->array[items->size-1] = value;
        items->frontIndex = items->size - 1;
        items->filledIndices += 1;
      }
    }
    else {
      //If front index is not 0 and insert is possible
      if (items->array[frontIndex-1] == NULL) {
        items->array[frontIndex-1] = value;
        items->frontIndex = items->frontIndex - 1;
        items->filledIndices += 1;
      }
      else {
        //If insert is not possible (array full)
        assert( items->size * 2 * sizeof(void*) != 0 );
        items->array = realloc(items->array, 2 * items->size * sizeof(void*) );
        items->array[items->size] = items->array[items->backIndex];
        items->array[items->backIndex] = NULL;
        items->backIndex = items->size;
        items->size *= 2;
      }
    }
  }
/*
  if (items->array[frontIndex] == 0) {

    if (items->array[items->size-1] == NULL) {
      items->array[items->size-1] = value;
    }
    else {
      items->array = realloc(items->array, 2 * items->size * sizeof(void*) );
      items->array[items->size-1] = value;
      size *= 2;
    }

  }
  else {
    if (items->array[frontIndex - 1])
  }
*/
}

void insertCDAback(DA *items, void *value) {

}
