#pragma once
#include "lib.h"

typedef struct Brick_ {
    Point a;
    Point b;
    Point c;
    Point d;
    Point e;
    Point f;
    Point g;
    Point h;
} Brick;

// Give the point of contact between a line and a brick
Point contactBrickWithLine(Brick B, Line L);

//Encode a brick as an array
double * encodeBrick(Brick B);

//Encode a brick's array as a brick structure
Brick decodeBrick(double * brick);

int testIfLightCutBrick(double *object,Light li,Point c);
