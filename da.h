/*Author: Jake Wachs
 *Date: 08/26/17
 *University of Alabama
 *This file serves as method signatures for the
 *dynamic array section
 */
#ifndef __DA_INCLUDED__
#define __DA_INCLUDED__

#include <stdio.h>

typedef struct da DA;

extern DA *newDA(void (*d)(FILE *,void *));
extern void insertDA(DA *items,void *value);
extern void *removeDA(DA *items);
extern void unionDA(DA *recipient,DA *donor);
extern void *getDA(DA *items,int index);
extern void *setDA(DA *items,int index,void *value);
extern void **extractDA(DA *items);
extern int sizeDA(DA *items);
extern void visualizeDA(FILE *fp,DA *items);
extern void displayDA(FILE *fp,DA *items);

#endif
