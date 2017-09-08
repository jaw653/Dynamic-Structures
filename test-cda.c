/* Test cda prog wrtten by Jake Wachs */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "cda.h"
#include "integer.h"

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

  return 0;
}
