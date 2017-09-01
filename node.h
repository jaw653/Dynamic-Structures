#ifndef __NODE_INCLUDED__
#define __NODE_INCLUDED__

typedef struct node NODE; /* forward declaration of our structure */

extern char *INTEGER;
extern char *REAL;
extern char *STRING;

extern NODE  *newNODEinteger(int value,NODE *next);
extern NODE  *newNODEreal(double value,NODE *next);
extern NODE  *newNODEstring(char *value,NODE *next);
extern char  *getNODEtype(NODE *n);
extern int    getNODEinteger(NODE *n);
extern double getNODEreal(NODE *n);
extern char  *getNODEstring(NODE *n);
extern NODE  *getNODEnext(NODE *n);

#endif
