#include "lib.h"

typedef struct Ellipse_ {
    double a;
    double b;
    double c;
} Ellipse;

Point contactEllipseWithLine(Ellipse E, Line L);

