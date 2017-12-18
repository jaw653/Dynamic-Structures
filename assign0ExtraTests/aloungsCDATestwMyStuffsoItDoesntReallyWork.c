/* Writen by Alex Luong
 * Test CDA class */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cda.h"
#include "integer.h"

static void displayItems(CDA *);
static void visualizeItems(CDA *);
static void testInsertAndRemove(CDA *);
static void testSetAndGet(CDA *);
static void testUnion(CDA *, CDA *);
static void testExtract(CDA *);

int main(void) {

  CDA *donor = newCDA(displayINTEGER);
  CDA *recipient = newCDA(displayINTEGER);

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

  CDA *items = newCDA(displayINTEGER);

  testInsertAndRemove(items);
  // Currently, items = [][1]
  testSetAndGet(items);

  // Set up recipient and donor
  CDA *recip = newCDA(displayINTEGER);
  for (i = 0; i < 4; i++)
    insertCDAback(recip, newINTEGER(i));

  CDA *don = newCDA(displayINTEGER);
  for (i = 0; i < 5; i++)
    insertCDAback(don, newINTEGER(i));

  // Test union
  testUnion(recip, don);

  testExtract(recip);

  return 0;
}

static void testInsertAndRemove(CDA *items) {
  int i;

  // Display an empty DA
  displayItems(items);

  printf("\n");

  // Put 100 values in the array
  for (i = 0; i < 50; i++)
    insertCDAback(items, newINTEGER(i));
  for (i = 50; i < 100; i++)
    insertCDAfront(items, newINTEGER(i));
  displayItems(items);

  visualizeItems(items);
  printf("\n");

  // Remove the last value
  printf("The value ");
  displayINTEGER(stdout, removeCDAback(items));
  printf(" was removed.\n");
  printf("\n");

  // Remove the first value
  printf("The value ");
  displayINTEGER(stdout, removeCDAfront(items));
  printf(" was removed.\n");
  printf("\n");

  // Remove the rest
  for (i = 0; i < 49; i++)
    removeCDAback(items);
  for (i = 0; i < 49; i++)
    removeCDAfront(items);
  displayItems(items);
  visualizeItems(items);
  printf("\n");

}

static void testSetAndGet(CDA *items) {
  insertCDAback(items, newINTEGER(1));
  visualizeItems(items);
  int x = getINTEGER((INTEGER *) getCDA(items,0));
  printf("The first item is %d.\n", x);
  setCDA(items, 0, newINTEGER(2));
  printf("After set:\n");
  visualizeItems(items);
  printf("\n");
}

static void testUnion(CDA *recipient, CDA *donor) {
  // Union
  unionCDA(recipient, donor);

  // Show donor
  printf("Donor:\n");
  displayItems(donor);
  visualizeItems(donor);
  printf("\n");

  // Show recipient
  printf("Recipient:\n");
  displayItems(recipient);
  visualizeItems(recipient);
  printf("\n");
}

static void testExtract(CDA *items) {
  // Extract
  int size = sizeCDA(items);
  void **array = extractCDA(items);
  printf("Recipient after extracting:\n");
  visualizeItems(items);
  printf("\n");
  printf("The last item in the extracted array is %d\n", getINTEGER((INTEGER *)array[size-1]));
}

static void displayItems(CDA *items) {
  printf("displayItems: ");
  displayCDA(stdout,items);
  printf("\n");
}

static void visualizeItems(CDA *items) {
  printf("visualizeItems: ");
  visualizeCDA(stdout,items);
  printf("\n");
}
