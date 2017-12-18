/* Test cda prog wrtten by Jake Wachs */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cda.h"
#include "integer.h"

void test1(CDA *, CDA *);
void test2(CDA *);
void test3(CDA *, CDA *);

int main(void) {
  printf("\n*********************** Running test-cda **************************\n");

  CDA *donor = newCDA(displayINTEGER);
  CDA *recipient = newCDA(displayINTEGER);
  CDA *items = newCDA(displayINTEGER);

  test1(donor, recipient);
  test2(items);

  CDA *donor2 = newCDA(displayINTEGER);
  CDA *recipient2 = newCDA(displayINTEGER);

  test3(recipient2, donor2);

  return 0;
}

void test1(CDA *recipient, CDA *donor) {
  int i;
  for (i = 0; i < 10; i++) {
    insertCDAback(recipient, newINTEGER(i));
  }
  for (i = 10; i < 20; i++) {
    insertCDAback(donor, newINTEGER(i));
  }

  printf("recipient: \n");
  displayCDA(stdout, recipient);
  printf("\n");
  visualizeCDA(stdout, recipient);
  printf("\n");

  printf("donor: \n");
  displayCDA(stdout, donor);
  printf("\n");
  visualizeCDA(stdout, donor);
  printf("\n");

  printf("Executing union...\n");
  unionCDA(recipient, donor);
  printf("\n");

  printf("union done, here is donor: \n");
  displayCDA(stdout, donor);
  printf("\n");
  visualizeCDA(stdout, donor);
  printf("\n");

  printf("here is recipient: \n");
  displayCDA(stdout, recipient);
  printf("\n");
  visualizeCDA(stdout, recipient);
  printf("\n");

  printf("extracting recipient...\n");
  void **arr = extractCDA(recipient);

  printf("extracted array is: \n");
  for (i = 0; i < 20; i++) {
    printf("%d\t", getINTEGER(arr[i]));
  }
  printf("\n");

  printf("recipient is now: \n");
  visualizeCDA(stdout, recipient);
  printf("\n");

  printf("now adding more stuff to recipient...\n");
  printf("adding some values at front...\n");
  for (i = 0; i < 50; i++) {
    insertCDAfront(recipient, newINTEGER(i));
  }

  printf("recipient now is: \n");
  visualizeCDA(stdout, recipient);
  printf("\n");

  printf("now adding values at back...\n");
  for (i = 0; i < 73; i++) {
    insertCDAback(recipient, newINTEGER(i));
  }

  printf("recipient is now: \n");
  visualizeCDA(stdout, recipient);
  printf("\n");

  printf("extracting recipient again...\n");
  extractCDA(recipient);
  printf("recipient now is: \n");
  visualizeCDA(stdout, recipient);

  printf("now adding at both front and back...\n");
  for (i = 0; i < 50; i++) {
    insertCDAfront(recipient, newINTEGER(i));
    insertCDAback(recipient, newINTEGER(0-i));
  }

  printf("finally, recipient is: \n");
  visualizeCDA(stdout, recipient);
  printf("\n");
}

void test2(CDA *items) {
  printf("=================================================================\n");
  int i;
  for (i = 0; i < 35; i++) {
    insertCDAback(items, newINTEGER(i));
  }

  printf("removing all but one element from the array...\n");
  for (i = 0; i < 34; i++) {
    removeCDAback(items);
  }
  visualizeCDA(stdout, items);

  printf("\n=================================================================\n");
  printf("removing last element...\n");
  removeCDAback(items);
  visualizeCDA(stdout, items);
  printf("\n");

  printf("adding one element back in...\n");
  insertCDAfront(items, newINTEGER(1));
  visualizeCDA(stdout, items);
  printf("\n");

  printf("removing that element...\n");
  int val = getINTEGER(removeCDAfront(items));
  visualizeCDA(stdout, items);
  printf("\nand the value removed was %d\n", val);


  printf("=================================================================\n\n");
}

void test3(CDA *recip, CDA *don) {
  int i;
  for (i = 0; i < 63; i++) {
    insertCDAback(don, newINTEGER(i));
  }

  printf("before union, recip is: \n");
  visualizeCDA(stdout, recip);
  printf("\n");

  printf("and don is: \n");
  visualizeCDA(stdout, don);
  printf("\n");

  printf("performing union...\n");
  unionCDA(recip, don);

  printf("after union, recip is: \n");
  visualizeCDA(stdout, recip);
  printf("\n");

  printf("and don is: \n");
  visualizeCDA(stdout, don);
  printf("\n");
}
