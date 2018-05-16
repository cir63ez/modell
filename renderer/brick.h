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

// Give the point of contact between a line and a brick
Point contactBrickWithLine(Brick B, Line L);

//Encode a brick as an array
double * encodeBrick(Brick B);

//Encode a brick's array as a brick structure
Brick decodeBrick(double * brick);