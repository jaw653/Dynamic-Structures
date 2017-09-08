/*Author: Jake Wachs
 *The University of Alabama
 *Date: 9/7/2017
 *
 *This test program mimics what is on Dr. John Lusth's test0 submit utility
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cda.h"
#include "integer.h"

int main(void) {
  printf("Making a new array, inserting numbers 0 through 4 inclusive...\n");
  CDA *items = newCDA(displayINTEGER);

  int i;
  for (i = 0; i < 5; ++i) {
    insertCDAback(items, newINTEGER(i));
  }

  displayCDA(stdout, items);

  printf("\nremoving the head item in the array...\n");
  removeCDAfront(items);

  printf("displaying the array...\n");
  displayCDA(stdout, items);

  printf("\n");

  printf("making a new array, inserting numbers 5 through 9, inclusive...\n");
  CDA *items2 = newCDA(displayINTEGER);
  for (i = 5; i <= 9; ++i) {
    insertCDAfront(items2, newINTEGER(i));
  }

  printf("displaying the array...\n");
  displayCDA(stdout, items2);
  printf("\n");

  printf("merging the two arrays...\n");
  unionCDA(items, items2);
  printf("dipslaying the two arrays...\n");
  displayCDA(stdout, items);
  displayCDA(stdout, items2);
  printf("\n");

  printf("removing the tail item in the array...\n");
  removeCDAback(items);
  printf("displaying the array...\n");
  displayCDA(stdout, items);
  printf("\n");

  return 0;
}
