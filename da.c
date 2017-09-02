/*Author: Jake Wachs
 *Date: 08/26/17
 *University of Alabama
 *This file serves as method implementations for the
 *dynamic array object
 */

 /*
  *Questions:
  *-to fix potential comma problem in display: if (index != backIndex) print comma
  *-should we initialize array to size 2?
  *-give lusth credit for making node.c, node.h, da.h files
  *-need to add assertions for most functions
  *-can i have all the libraries i imported?
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
  DA *arr = malloc( sizeof(DA) );
  assert( sizeof(DA) != 0 );

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
    items->array = realloc( items->array, 2 * items->size * sizeof(void*) );
    assert(sizeof(void*) * items->size * 2 != 0);

    items->array[items->filledIndices] = value;

    items->size *= 2;
    items->filledIndices += 1;
/*
    void *tmp[items->size*2];

    //Copying values of smaller array to array of twice the size
    int i = 0;
    for (i = 0; i < items->filledIndices; i++) {    //FIXME: might have to change upper bound of this loop to size instead of filledIndices
      tmp[i] = items->array[i];
    }
    tmp[items->filledIndices] = value;

    for (i = 0; i <= items->size*2; i++) {
      items->array[i] = tmp[i];
    }

    //Delete temporary array
    free(tmp);                                      //FIXME: are these free's needed?

    items->size = items->size * 2;
    items->filledIndices += 1;
*/
  }
  return;
}

void *removeDA(DA *items) {
  //FIXME: Add assertion that the size shall be greater than 0
  //FIXME: The rubric says that the array should never shrink below the size of 1...what about initiaizing it to size 0?
  //FIXME: Do we need a certain runtime? Rn, i have it creating a whole new array in order to actually get rid of the value. otherwise, is there a way to simply get rid of one value?

  items->array[items->filledIndices] = NULL;
  items->filledIndices -= 1;

  if ( items->filledIndices < .25 * items->size ) {     //FIXME: < or <= ?

    items->array = realloc( items->array, (items->size/2) * sizeof(void*) );
/*
    void *tmp[items->size/2];

    int i = 0;
    for (i = 0; i < items->filledIndices; i++) {
      tmp[i] = items->array[i];
    }

    for (i = 0; i < items->size/2; i++) {
      items->array[i] = tmp[i];
    }

    free(tmp);

    items->size /= 2;
*/
  }
  return items;
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
/*
  int totalSize = 0;
  int size1 = 0;
  int size2 = 0;

  int i;
  for (i = 0; recipient->array[i]; i++) {
    totalSize += 1;
    size1 += 1;
  }
  for (i = 0; donor->array[i]; i++) {
    totalSize += 1;
    size2 += 1;
  }

  void **tmp = malloc( totalSize * sizeof(void*) );
  memcpy( tmp, recipient->array, size1 * sizeof(void*) );
  memcpy( tmp + size1, donor->array, size2 * sizeof(void*) );

  //ok, now tmp is the array of pointers that you want to put in recipient
  //so, make the recipient array large enough to hold all the necessary values (totalSize)
  //then either set recipient->array = tmp or copy each individual value into recipient

  //is the above method going to be linear? cause every time you will have to create a new array...
  realloc()
*/
}

void *getDA(DA *items, int index) {
  //FIXME: Add assertion that the index shall be greater than or equal to zero and less than the size
  assert(index >= 0 && index < items->size);
  return items->array[index];
}

void *setDA(DA *items, int index, void *value) {
  assert(index >= 0 && index <= items->size);  //FIXME: Add assertion that the index shall be >= 0 and <= size

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
  //FIXME: Add assertion that mem allocated shall not be zero
  /*The extract method returns the underlying C array. The array is shrunk to
   *an exact fit prior to being returned. The DA object gets a new array of
   *capacity one and size zero.
   */
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
