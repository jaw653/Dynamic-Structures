#include <stdio.h>
#include <stdlib.h>
#include "../integerClass/integer.h"
#include "da.h"

static void showItemsDA(DA *items) {
    printf("The items are ");
    displayDA(stdout,items);
    printf("\n");
}

int main(void) {
  DA *array = newDA(displayINTEGER);

  return 0;
}
