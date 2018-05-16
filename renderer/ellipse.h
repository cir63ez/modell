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

Point contactEllipseWithLine(Ellipse E, Line L);
