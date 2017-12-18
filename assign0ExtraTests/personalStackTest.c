#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include "../integerClass/integer.h"

int main() {
  STACK *items = newSTACK(displayINTEGER);

  int i;
  for (i = 0; i < 500; i++) {
    push(items, newINTEGER(i));
  }

  int x = getINTEGER( (INTEGER*)pop(items) );
  printf("x is %d\n", x);

  displaySTACK(stdout, items);

  return 0;
}
