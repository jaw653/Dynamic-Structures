/*Author: Jake Wachs
 *Date: 08/26/17
 *University of Alabama
 *This file serves as method implementations for the
 *circular dynamic array object
 *
 *Questions:
 *-to fix potential problems, may have accidentally set index = 0 instead of frontIndex or backIndex
 *-for getCDA, if they ask for 0 we should be returning the front of the arr, right?
 *-for removeCDA, should we shrink before or after the element is removed
 *-line 117(ish) if the array is empty, should i just return null?
 *-does removeCDA return the value that was removed?
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
    assert(sizeof(CDA) != 0);

    CDA *arr = malloc( sizeof(CDA) );

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
        assert( items->size * 2 * sizeof(void*) != 0 );
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

void insertCDAback(DA *items, void *value) {
  //If array is empty
  if (items->filledIndices == 0) {
    items->array[0] = value;
    items->filledIndices += 1;
  }
  else {
    if (items->filledIndices == items->size) {
      if (items->frontIndex != 0) {
        assert( items->size * 2 * sizeof(void*) != 0);
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
  if (items->filledIndices == 0) {
    return NULL;
  }
  else {
    void *valToReturn = items->array[items->frontIndex];
    items->array[items->frontIndex] = NULL;
    items->filledIndices -= 1;

    if (items->frontIndex + 1 == size) { items->frontIndex = 0; }
    else { items->frontIndex += 1; }

    if (items->filledIndices < .25 * items->size) {
      /*
       *The following code creates a new tmpArray and fills it with all the non NULL
       *values in the original array. It then cuts the size of the items->array (the
       *actual object) by /2. It then repopulates the resized array with tmpArray, so
       *every resized array will have a frontIndex of 0 and a backIndex of filledIndices
       *minus one. Removing the requested value happens after this "if" code block.
       */
      assert( items->filledIndices != 0 );

      void **tmpArr = malloc( items->filledIndices * sizeof(void*) );
      void *ptr = items->array[items->frontIndex];

      int index = items->frontIndex;
      int tmpIndex = 0;
      while (ptr) {
        tmpArr[tmpIndex] = ptr;
        index += 1;

        if (index == items->size) {
          index = 0;
        }

        ptr = items->array[index];
        tmpIndex += 1;
      }

      items->array = realloc( items->array, (items->size / 2) * sizeof(void*) );
      items->size /= 2;

      int i;
      for (i = 0; i < items->filledIndices; i++) {
        items->array[i] = tmpArr[i];
      }

      items->frontIndex = 0;
      items->backIndex = items->filledIndices - 1;
    }
  }

  return valToReturn;
}
void *removeCDAback(CDA *items) {
  if (items->filledIndices == 0) {
    return NULL;
  }
  else {
    void *valToReturn = items->array[items->backIndex];
    items->array[items->backIndex] = NULL;
    items->filledIndices -= 1;

    if (items->backIndex - 1 < 0) { items->backIndex = items->size - 1; }
    else { items->backIndex -= 1; }

    if (items->filledIndices < .25 * items->size) {
      /*
       *The following code creates a new tmpArray and fills it with all the non NULL
       *values in the original array. It then cuts the size of the items->array (the
       *actual object) by /2. It then repopulates the resized array with tmpArray, so
       *every resized array will have a frontIndex of 0 and a backIndex of filledIndices
       *minus one. Removing the requested value happens after this "if" code block.
       */
      assert( items->filledIndices != 0 );

      void **tmpArr = malloc( items->filledIndices * sizeof(void*) );
      void *ptr = items->array[items->backIndex];

      int index = items->backIndex;
      int tmpIndex = items->filledIndices - 1;
      while (ptr) {
        tmpArr[tmpIndex] = ptr;
        index -= 1;

        if (index < 0) {
          index = items->size - 1;
        }

        ptr = items->array[index];
        tmpIndex -= 1;
      }

      items->array = realloc( items->array, (items->size / 2) * sizeof(void*) );
      items->size /= 2;

      int i;
      for (i = 0; i < items->filledIndices; i++) {
        items->array[i] = tmpArr[i];
      }

      items->frontIndex = 0;
      items->backIndex = items->filledIndices - 1;
    }
  }

  return valToReturn;
}

void unionCDA(CDA *recipient,CDA *donor) {
  int i;
  for (i = donor->frontIndex; i < donor->filledIndices; i++) {
    insertCDAback(recipient, donor->array[i]);
  }

  donor = NULL;
}

void *getCDA(CDA *items,int index) {
  assert(index >= 0 && index < items->filledIndices);
  return items->array[items->frontIndex + index];
}

void *setCDA(CDA *items,int index,void *value) {
  assert(index >= -1 && index <= items->filledIndices);

  void *valToReturn = NULL;
  if (index == items->size) {
    insertCDAback(items, value);
  }
  else if (index == -1) {
    insertCDAfront(items, value);
  }
  else {
    valToReturn = items->array[index];
    items->array[index] = value;
  }

  return valToReturn;
}

void **extractCDA(CDA *items) {
  assert(items->filledIndices * sizeof(void*));
  
  void **tmpArr = malloc( items->filledIndices * sizeof(void*) );
  void *ptr = items->array[items->frontIndex];

  int index = items->frontIndex;
  int tmpIndex = 0;
  while (ptr) {
    tmpArr[tmpIndex] = ptr;
    index += 1;

    if (index == items->size) {
      index = 0;
    }

    ptr = items->array[index];
  }

  items->frontIndex = 0;
  items->backIndex = items->filledIndices - 1;

  items->array = realloc( items->array, sizeof(void*) );
  items->filledIndices = 0;

  return tmpArr;
}

int sizeCDA(CDA *items) {
  return items->filledIndices;
}

void visualizeCDA(FILE *,CDA *items) {
  fprintf(fp, "(");
  void *ptr = items->array[items->frontIndex];

  if (items->filledIndices != 0) {
    int index = items->frontIndex;
    while (ptr) {
      items->display(fp, ptr);
      if (index != backIndex) { fprintf(fp, ","); }

      index += 1;
      if (index == items->size) {
        index = 0;
      }

      ptr = items->array[index];
    }
  }

  fprintf(fp, ")");

  int remainder = items->size - items->filledIndices;

  fprintf(fp, "(%d)", remainder);
}
void displayCDA(FILE *,CDA *items) {
  fprintf(fp, "(");
  void *ptr = items->array[items->frontIndex];

  if (items->filledIndices != 0) {
    int index = items->frontIndex;
    while (ptr) {
      items->display(fp, ptr);
      if (index != backIndex) { fprintf(fp, ","); }

      index += 1;
      if (index == items->size) {
        index = 0;
      }

      ptr = items->array[index];
    }
  }

  fprintf(fp, ")");
}
