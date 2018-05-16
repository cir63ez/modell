#include "lib.h"

typedef struct Brick_ {
    double a;
    double b;
    double c;
    double d;
    double e;
    double f;
    double g;
    double h;
} Brick;


Point contactBrickWithLine(Brick B, Line L);

//Encode a brick as an array
double * encodeBrick(Brick B);