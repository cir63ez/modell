#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "brick.h"

/**
* Give the point of contact between a line and an brick
*
* @param E: Brick's name
* @param B: Line's name
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
* @param E: Brick's name
*
* @return an array of double which contain the informations about the brick
*/
double * encodeBrick(Brick E){
    double brick[6];
    brick[0] = E.a;
    brick[1] = E.b;
    brick[2] = E.c;
    brick[3] = E.d;
    brick[4] = E.e;
    brick[5] = E.f;
    brick[6] = E.g;
    return brick;
}

