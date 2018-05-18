#pragma once
#include "lib.h"
#include "list.h"

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

// Verify if the brick could exist
int DoesBrickExist(Brick B);

// Give the point of contact between a line and a brick
Point contactBrickWithLine(Brick B, Line L);

// Encode a brick as an array
double * encodeBrick(Brick B);

// Encode a brick's array as a brick structure
Brick decodeBrick(double * brick);

// Check if there is a direct path between the point and light
int testIfLightCutsBrick(double *object,Light Li,Point C);

Element * createElementBrick(Brick B);
