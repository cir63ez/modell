#include "lib.h"

typedef struct Ellipse_ {
    double a;
    double b;
    double c;
    double x;
    double y;
    double z;
} Ellipse;

Point contactEllipseWithLine(Ellipse E, Line L);
