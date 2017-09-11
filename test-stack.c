/* Writen by Alex Luong
 * Test STACK class */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"
#include "integer.h"

static void displayItems(STACK *);
static void visualizeItems(STACK *);
static void testPushPopPeek(STACK *);

int main(void) {
  printf("\n********************** Running test-stack *************************\n");

  STACK *items = newSTACK(displayINTEGER);
  testPushPopPeek(items);
  return 0;
}

static void testPushPopPeek(STACK *items) {
  int i;

  // Display empty STACK
  displayItems(items);
  visualizeItems(items);
  printf("The size is %d.\n", sizeSTACK(items));
  printf("\n");

  // Add 100 values in
  for (i = 0; i < 100; i++)
    push(items, newINTEGER(i));
  displayItems(items);
  visualizeItems(items);
  printf("\n");

  // Show the last value
  int x = getINTEGER((INTEGER *) peekSTACK(items));

  printf("The last item is %d.\n", x);
  printf("The size is %d.\n", sizeSTACK(items));

  // Remove the last value
  printf("The value ");
  displayINTEGER(stdout, pop(items));
  printf(" was removed.\n");
  printf("The size is %d.\n", sizeSTACK(items));

  // Remove the rest
  for (i = 0; i < 99; i++)
    pop(items);
  displayItems(items);
  visualizeItems(items);
  printf("\n");

  // Add 10 values back in
  for (i = 0; i < 10; i++)
    push(items, newINTEGER(i));
  displayItems(items);
  visualizeItems(items);
  printf("\n");
}

static void displayItems(STACK *items) {
  printf("displaySTACK: ");
  displaySTACK(stdout,items);
  printf("\n");
}

static void visualizeItems(STACK *items) {
  printf("visualizeSTACK: ");
  visualizeSTACK(stdout,items);
  printf("\n");
}
