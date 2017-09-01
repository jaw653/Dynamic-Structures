#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node
    {
    char *type;
    int ival;
    double rval;    /* ival, rval, sval: one will hold the actual value */
    char *sval;
    NODE *next;
    };

static NODE *newNODE(void);

/*************** public interface *************/

char *INTEGER = "integer";
char *REAL = "real";
char *STRING = "string";

/* constructors */

NODE *newNODEinteger(int v,NODE *n)
    {
    NODE *p = newNODE();
    p->type = INTEGER;
    p->ival = v;
    p->next = n;
    return p;
    }

NODE *newNODEreal(double v,NODE *n)
    {
    NODE *p = newNODE();
    p->type = REAL;
    p->rval = v;
    p->next = n;
    return p;
    }

NODE *newNODEstring(char *v,NODE *n)
    {
    NODE *p = newNODE();
    p->type = STRING;
    p->sval = v;
    p->next = n;
    return p;
    }

/* accessors */

char  *getNODEtype(NODE *n)    { return n->type; }
int    getNODEinteger(NODE *n) { return n->ival; }
double getNODEreal(NODE *n)    { return n->rval; }
char  *getNODEstring(NODE *n)  { return n->sval; }
NODE  *getNODEnext(NODE *n)    { return n->next; }

/*************** private methods *************/

static NODE *newNODE()
    {
    NODE *n = (NODE *) malloc(sizeof(NODE));
    if (n == 0) { fprintf(stderr,"out of memory"); exit(-1); }
    return n;
    }
