#pragma once
#include "lib.h"

typedef struct Tetrahedron_ {
    Point a;
    Point b;
    Point c;
    Point d;
} Tetrahedron;

// Give the point of contact between a line and a tetrahedron
Point contactTetrahedronWithLine(Tetrahedron T, Line L);

//Encode a tetrahedron as an array
double * encodeTetrahedron(Tetrahedron T);

//Encode a tetrahedron's array as a tetrahedron structure
Tetrahedron decodeTetrahedron(double *tetrahedron);

int testIfLightCutTetrahedron(double *object, Light li, Point c);
