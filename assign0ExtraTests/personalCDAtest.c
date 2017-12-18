#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cda.h"
#include "../integerClass/integer.h"

void testSmall(CDA *items);
void testLarge(CDA *items);

int main(void) {
  CDA *items = newCDA(displayINTEGER);
  testSmall(items);
  return 0;
}

void testSmall(CDA *items) {
  printf("Adding a few values...\n");
  int i;
  for (i = 1; i < 6; i++) {
    insertCDAfront(items, newINTEGER(i));
  }

  show(items);

  printf("Removing front...\n");
  printf("removing front index, which is: %d\n", getINTEGER(removeCDAfront(items)));

  show(items);

  printf("removing front index, which is: %d\n", getINTEGER(removeCDAfront(items)));
  show(items);

  printf("removing front index, which is: %d\n", getINTEGER(removeCDAfront(items)));
  show(items);

  printf("removing front index, which is: %d\n", getINTEGER(removeCDAfront(items)));
  show(items);

  printf("Now adding more...\n");
  for (i = 0; i < 100; i++) {
    insertCDAfront(items, newINTEGER(i));
  }

  show(items);
}

void testLarge(CDA *items) {
  show(items);

/******************************************************************************/
  printf("Inserting a bunch of values at front...\n");
  int i;
  for (i = 0; i < 100; i++) {
    insertCDAfront(items, newINTEGER(i));
  }
  show(items);

/******************************************************************************/
  printf("Inserting a bunch of values at back...\n");
  CDA *items2 = newCDA(displayINTEGER);
  for (i = 0; i < 100; i++) {
    insertCDAback(items2, newINTEGER(i));
  }
  show(items2);

/******************************************************************************/
  printf("Removing a bunch of values from the front of items...\n");
  for (i = 0; i < 99; i++) {
    removeCDAfront(items);
  }
  show(items);

/******************************************************************************/
    printf("Removing a bunch of values from the back of items2...\n");
    for (i = 0; i < 99; i++) {
      removeCDAfront(items2);
    }
    show(items2);
}

void show(CDA *items) {
  printf("displayCDA: "); displayCDA(stdout, items); printf("\n");
  printf("=============================================================\n");
  printf("visualizeCDA: "); visualizeCDA(stdout, items); printf("\n");
  printf("\n");
}
