#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "brick.h"

/**
* Give the point of contact between a line and an brick
*
* @param B: Brick's name
* @param L: Line's name
*
* @return the closest point of contact between an brick and a line if it exists
* @return a point with NaN coordinates if the point doesn't exist
*/
Point contactBrickWithLine(Brick B, Line L){
   // TODO: develop the function (with plane with 3 points & point of contact & first plane seen)
}


/**
* Encode an brick as an array
*
* @param B: Brick's name
*
* @return an array of double which contain the informations about the brick
*/
double * encodeBrick(Brick B){
    double brick[6];
    brick[0] = B.a;
    brick[1] = B.b;
    brick[2] = B.c;
    brick[3] = B.d;
    brick[4] = B.e;
    brick[5] = B.f;
    brick[6] = B.g;
    brick[7] = B.h;
    return brick;
}

