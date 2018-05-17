#include "lib.h"

#define ELLIPSE_TYPE 0
#define BRICK_TYPE 1
#define TETRAHEDRON 2

typedef struct Element_
{
    char type;
    double *object;
    struct Element_ *next;
} Element;

typedef struct List_
{
    Element *tete;
    double nbElement;
} List;

