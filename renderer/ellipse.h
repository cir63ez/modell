#pragma once
#include "lib.h"

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

//Encode an ellipse as an array
double * encodeEllipse(Ellipse E);
