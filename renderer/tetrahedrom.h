#include "lib.h"

typedef struct Tetrahedrom_ {
    Point a;
    Point b;
    Point c;
    Point d;
} Tetrahedrom;

// Give the point of contact between a line and a tetrahedrom
Point contactTetrahedromWithLine(Tetrahedrom T, Line L);

//Encode a tetrahedrom as an array
double * encodeTetrahedrom(Tetrahedrom T);

//Encode a tetrahedrom's array as a tetrahedrom structure
Tetrahedrom decodeTetrahedrom(double * tetrahedrom);