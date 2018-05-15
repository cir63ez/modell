#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NaN 0./0.

typedef struct Ellipse_ {
    double a;
    double b;
    double c;
}Ellipse;

Point contactEllipseWithLine(Ellipse E, Line L);

