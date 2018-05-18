#pragma once
#include "lib.h"
#include "list.h"

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

// Check if there is a direct path between the point and light
int testIfLightCutsTetrahedron(double *object, Light Li, Point C);

Element * createElementTetrahedron(Tetrahedron B);
