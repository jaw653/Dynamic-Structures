/*
 *Author: Jake Wachs
 *
 *Question: Should set return 0 or NULL if it is added to the to the end of the array?
 *
 *This test will run every case and edge case I
 *can conceive right now on CDA
 *
 *Some of the methods have assertion testing commented out. Scroll down and
 *uncomment to test assertions.
 *
 *If you want the program to print to the console, change fp to
 *fopen(stdout, "w+").
 */

#include <stdio.h>
#include <stdlib.h>
#include "cda.h"
#include "integer.h"

void showResults(FILE *, CDA *);
void testInsertFront(FILE *, CDA *);
void testInsertBack(FILE*, CDA *);
void testRemoveCDAfront(FILE *, CDA *);
void testRemoveCDAback(FILE *,CDA *);
void testUnion(FILE *, CDA *, CDA *);
void testUnionExtra(FILE *, CDA *, CDA *);
void testGet(FILE *, CDA *);
void testSet(FILE *, CDA *);
void testExtract(FILE *, CDA *);
void testSizeCDA(FILE *, CDA *);

int main(void) {
  FILE *fp = fopen("/home/jake/CS201/megaTest.txt", "w+");
  fprintf(fp, "\n");

  /*** Initializing CDA's ***/
  CDA *items = newCDA(displayINTEGER);
  CDA *items2 = newCDA(displayINTEGER);
  CDA *recipient = newCDA(displayINTEGER);
  CDA *donor = newCDA(displayINTEGER);
  CDA *testArr = newCDA(displayINTEGER);
  CDA *testArr2 = newCDA(displayINTEGER);
  CDA *testArr3 = newCDA(displayINTEGER);
  CDA *recip = newCDA(displayINTEGER);
  CDA *don = newCDA(displayINTEGER);

  /*** Adding 100 elements to items and items2 ***/
  testInsertFront(fp, items);
  testInsertBack(fp, items2);

  /*** Removing all 100 items from items (front) ***/
  testRemoveCDAfront(fp, items);
  /*** Removing all 100 items from items2 (back) ***/
  testRemoveCDAback(fp, items2);

  /*** Testing unionCDA (lot of edge cases, look at function definition) ***/
  testUnion(fp, recipient, donor);

  /*** Testing get() function on recipient array ***/
  testGet(fp, recipient);

  /*** Testing set() function on new array ***/
  testSet(fp, testArr);

  /*** Testing extract() function on both full and empty arrays ***/
  testExtract(fp, testArr2);

  /*** Testing sizeCDA() function on both full and empty arrays ***/
  testSizeCDA(fp, testArr3);

  /*** Testing some additional edge cases for union ***/
  testUnionExtra(fp, recip, don);

  return 0;
}

void showResults(FILE *fp, CDA *items) {
  fprintf(fp, "!!!\n\n");

  fprintf(fp, "Displaying CDA: \n");
  displayCDA(fp, items);

  fprintf(fp, "\n\n");

  fprintf(fp, "Visualizing CDA: \n");
  visualizeCDA(fp, items);

  fprintf(fp, "\n\n!!!\n\n");
}

void testInsertFront(FILE *fp, CDA *items) {
  fprintf(fp, "Testing generic insert FRONT (x100)\n");

  fprintf(fp, "*********************************************************************\n");

  int i;
  for (i = 0; i < 100; i++) {
    insertCDAfront(items, newINTEGER(i));
  }

  showResults(fp, items);

  fprintf(fp, "*********************************************************************\n");
}

void testInsertBack(FILE *fp, CDA *items) {
  fprintf(fp, "Testing generic insert BACK (x100)\n");

  fprintf(fp, "*********************************************************************\n");

  int i;
  for (i = 0; i < 100; i++) {
    insertCDAback(items, newINTEGER(i));
  }

  showResults(fp, items);

  fprintf(fp, "*********************************************************************\n");
}

void testRemoveCDAfront(FILE *fp, CDA *items) {
  fprintf(fp, "Testing generic remove FRONT (x100)\n");

  fprintf(fp, "*********************************************************************\n");
  fprintf(fp, "Array should be empty...\n");

  int i;
  for (i = 0; i < 100; i++) {
    removeCDAfront(items);
  }

  showResults(fp, items);

/* NOTE: Use the below code to be sure your assertion is correctly triggered
  fprintf(fp, "Attempting to removeCDAfront from empty array (assertion should trigger)...\n");

  removeCDAfront(items);

  showResults(fp, items);
*/

  fprintf(fp, "*********************************************************************\n");
}

void testRemoveCDAback(FILE *fp, CDA *items) {
  fprintf(fp, "Testing generic remove BACK (x100)\n");

  fprintf(fp, "*********************************************************************\n");
  fprintf(fp, "Array should be empty...\n");

  int i;
  for (i = 0; i < 100; i++) {
    removeCDAback(items);
  }

  showResults(fp, items);

/* NOTE: Use the below code to be sure your assertion is correctly triggered
  fprintf(fp, "Attempting to removeCDAfront from empty array (assertion should trigger)...\n");

  removeCDAback(items);

  showResults(fp, items);
*/

  fprintf(fp, "*********************************************************************\n");
}

void testUnion(FILE *fp, CDA *recipient, CDA *donor) {
  fprintf(fp, "Testing union after inserting 20 values\n");

  fprintf(fp, "*********************************************************************\n");

  int i;
  for (i = 0; i < 10; i++) {
    insertCDAback(recipient, newINTEGER(i));
  }

  for (i = 10; i < 20; i++) {
    insertCDAback(donor, newINTEGER(i));
  }

  fprintf(fp, "Inserted 10 values in recipient and donor...\n");

  fprintf(fp, "unionizing...\n");

  unionCDA(recipient, donor);

  fprintf(fp, "Results for donor: \n");
  showResults(fp, donor);

  fprintf(fp, "Results for recipient: \n");
  showResults(fp, recipient);

  fprintf(fp, "Now inserting a bunch of values to recipient...\n");
  for (i = 0; i < 25; i++) {
    insertCDAfront(recipient, newINTEGER(i));
    insertCDAback(recipient, newINTEGER(i));
  }
  showResults(fp, recipient);

  fprintf(fp, "Attempting to union empty donor array into recipient...\n");
  unionCDA(recipient, donor);

  fprintf(fp, "Recipient is: \n");
  showResults(fp, recipient);

  fprintf(fp, "Donor is: \n");
  showResults(fp, donor);

  fprintf(fp, "Now trying to union recipient array into empty donor...\n");
  unionCDA(donor, recipient);

  fprintf(fp, "Recipient is: \n");
  showResults(fp, recipient);

  fprintf(fp, "Donor is: \n");
  showResults(fp, donor);

  fprintf(fp, "Now recipient should be empty and donor should be full, trying to pass all back to recipient...\n");
  unionCDA(recipient, donor);

  fprintf(fp, "Recipient is: \n");
  showResults(fp, recipient);

  fprintf(fp, "Donor is: \n");
  showResults(fp, donor);

  fprintf(fp, "*********************************************************************\n");
}

void testGet(FILE *fp, CDA *items) {
  fprintf(fp, "Testing get\n");

  fprintf(fp, "*********************************************************************\n");

  fprintf(fp, "Getting front of array...\n");
  int num = getINTEGER( (INTEGER *)getCDA(items, 0) );
  fprintf(fp, "Value at recipient->array[0] is: %d\n", num);

  fprintf(fp, "Getting back of array...\n");
  num = getINTEGER( (INTEGER *)getCDA(items, sizeCDA(items) - 1) );
  fprintf(fp, "Value at back of the array is: %d\n\n", num);

/*NOTE: Use the below code to determine if your assertion is correctly triggered
  fprintf(fp, "Attempting to access out of bounds array index...\n");
  num = getINTEGER( (INTEGER *)getCDA(items, sizeCDA(items)) );
  fprintf(fp, "The program should not get to this point, but somehow it did\n");
*/

  fprintf(fp, "*********************************************************************\n");
}

void testSet(FILE *fp, CDA *items) {

  fprintf(fp, "Testing set\n");

  fprintf(fp, "*********************************************************************\n");

  int i;
  for (i = 0; i < 50; i++) {
    insertCDAback(items, newINTEGER(i));
  }

  fprintf(fp, "Array before set is: \n");
  showResults(fp, items);

  fprintf(fp, "Setting first element of the array with 5...\n");
  int num = getINTEGER( (INTEGER *)setCDA(items, 0, newINTEGER(5)) );

  fprintf(fp, "Value replaced is: %d\n", num);

  fprintf(fp, "Array is now: \n");
  showResults(fp, items);

  fprintf(fp, "Setting last element of the array with 10...\n");
  num = getINTEGER( (INTEGER *)setCDA(items, 49, newINTEGER(10)) );

  fprintf(fp, "Replaced value is: %d\n", num);

  fprintf(fp, "Array is now: \n");
  showResults(fp, items);

  fprintf(fp, "Setting empty element after last element in the array with 69...\n");
  num = getINTEGER( (INTEGER *)setCDA(items, 49, newINTEGER(69)) );
  fprintf(fp, "Replaced value is: %d\n", num);

  fprintf(fp, "Array is now: \n");
  showResults(fp, items);

  fprintf(fp, "Setting the [-1] element to 32...\n");
  setCDA(items, -1, newINTEGER(32));
  fprintf(fp, "Array is now: \n");
  showResults(fp, items);

/*NOTE: Use the following code to determine if your assertion is correctly triggered
  fprintf(fp, "Attempting to set out of bounds index\n");
  num = getINTEGER( (INTEGER *)setCDA(items, 55, newINTEGER(98)) );
  fprintf(fp, "Replaced value is: %d\n", num);

  fprintf(fp, "Array is now: \n");
  showResults(fp, items);
*/

  fprintf(fp, "*********************************************************************\n");
}

void testExtract(FILE *fp, CDA *items) {
  fprintf(fp, "Testing extract\n");

  fprintf(fp, "*********************************************************************\n");

  fprintf(fp, "Inserting a bunch of values into array...\n");
  int i;
  for (i = 0; i < 20; i++) {
    insertCDAback(items, newINTEGER(i));
    insertCDAfront(items, newINTEGER(i*-1));
  }

  fprintf(fp, "Array is: \n");
  showResults(fp, items);

  fprintf(fp, "Now extracting array...\n");
  int **array = extractCDA(items);

  fprintf(fp, "Array is now: \n");
  showResults(fp, items);

  fprintf(fp, "And the extracted array is: \n");
  for (i = 0; i < 40; i++) { fprintf(fp, "%d\t", getINTEGER( (INTEGER *)array[i]) ); }
  fprintf(fp, "\n");

  fprintf(fp, "Attempting to extract from empty array...\n");
  extractCDA(items);
  showResults(fp, items);

  fprintf(fp, "*********************************************************************\n");
}

void testSizeCDA(FILE *fp, CDA *items) {
  fprintf(fp, "Testing sizeCDA...\n");

  fprintf(fp, "*********************************************************************\n");

  fprintf(fp, "Size of array is: %d (it should be 0)\n", sizeCDA(items));

  fprintf(fp, "Adding some values to the array...\n");
  int i;
  for (i = 0; i < 4; i++) {
    insertCDAback(items, newINTEGER(i));
  }

  fprintf(fp, "Size of array is: %d (it should be 4)\n", sizeCDA(items));

  fprintf(fp, "*********************************************************************\n");
}

void testUnionExtra(FILE *fp, CDA* recip, CDA *don) {
  fprintf(fp, "Running extra union test...\n");

  fprintf(fp, "*********************************************************************\n");

  fprintf(fp, "Filling array to size 4 so that there are 0 leftover spaces\n");
  int i;
  for (i = 0; i < 4; i++) {
    insertCDAback(recip, newINTEGER(i));
  }

  fprintf(fp, "Adding 2 values to donor array...\n");
  for (i = 0; i < 2; i++) {
    insertCDAback(don, newINTEGER(i));
  }

  fprintf(fp, "Unionizing...\n");
  unionCDA(recip, don);

  fprintf(fp, "Recip is now: \n");
  showResults(fp, recip);

  fprintf(fp, "Don is now: \n");
  showResults(fp, don);

  fprintf(fp, "Now unionizing into donor...\n");
  unionCDA(don, recip);

  fprintf(fp, "Recip is now: \n");
  showResults(fp, recip);

  fprintf(fp, "Don is now: \n");
  showResults(fp, don);

  fprintf(fp, "*********************************************************************\n");
}
