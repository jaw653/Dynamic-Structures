#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "da.h"
#include "../integerClass/integer.h"

int main(void) {
  DA *items = newDA(displayINTEGER);
  int i;
  for (i = 0; i < 50; i++) {
    insertDA(items, newINTEGER(i));
  }

  for (i = 0; i < 50; i++) {
    int x = getINTEGER((INTEGER *) getDA(items,i));
    printf("element at index %d is %d\n", i, x);
  }

  displayDA(stdout, items);
  printf("\n");

  return 0;
}
