#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "brick.h"

/**
* Give the point of contact between a line and a brick
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
    double brick[24];
    brick[0] = B.a.x;
    brick[1] = B.a.y;
    brick[2] = B.a.z;
    brick[3] = B.b.x;
    brick[4] = B.b.y;
    brick[5] = B.b.z;
    brick[6] = B.c.x;
    brick[7] = B.c.y;
    brick[8] = B.c.z;
    brick[9] = B.d.x;
    brick[10] = B.d.y;
    brick[11] = B.d.z;
    brick[12] = B.e.x;
    brick[13] = B.e.y;
    brick[14] = B.e.z;
    brick[15] = B.f.x;
    brick[16] = B.f.y;
    brick[17] = B.f.z;
    brick[18] = B.g.x;
    brick[19] = B.g.y;
    brick[20] = B.g.z;
    brick[21] = B.h.x;
    brick[22] = B.h.y;
    brick[23] = B.h.z;
    return brick;
}


/**
* Encode a brick's array as a brick structure
*
* @param brick: Brick array
*
* @return a brick 
*/
Brick decodeBrick(double * brick){
    Brick B;

    B.a.x = brick[0];
    B.a.y = brick[1];
    B.a.z = brick[2];
    B.b.x = brick[3];
    B.b.y = brick[4];
    B.b.z = brick[5];
    B.c.x = brick[6];
    B.c.y = brick[7];
    B.c.z = brick[8];
    B.d.x = brick[9];
    B.d.y = brick[10];
    B.d.z = brick[11];
    B.e.x = brick[12];
    B.e.y = brick[13];
    B.e.z = brick[14];
    B.f.x = brick[15];
    B.f.y = brick[16];
    B.f.z = brick[17];
    B.g.x = brick[18];
    B.g.y = brick[19];
    B.g.z = brick[20];
    B.h.x = brick[21];
    B.h.y = brick[22];
    B.h.z = brick[23];

    return B;
}

