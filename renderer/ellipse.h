#pragma once
#include "lib.h"
#include "list.h"

typedef struct Ellipse_ {
    //radii of the ellipsoid
    double a;
    double b;
    double c;
    // x y z coordinates of the center point
    double x;
    double y;
    double z;
} Ellipse;

//Give the point of contact between a line and an ellipse
Point contactEllipseWithLine(Ellipse E, Line L);

// Encode an array as an ellipse structure
Ellipse decodeEllipse(double * ellipse);

//Encode an ellipse as an array
double * encodeEllipse(Ellipse E);

//Test line of sight with light
int testIfLightCutsEllipse(double *object, Light Li, Point C);

// Give the tangente plane of a intersection point between a plane and an ellipse
Plane tangentPlaneEllipse(Ellipse E, Line L);

Element * createElementEllipse(Ellipse E);
