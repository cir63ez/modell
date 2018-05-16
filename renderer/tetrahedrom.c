#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "tetrahedrom.h"

/**
* Give the point of contact between a line and a tetrahedrom
*
* @param T: Tetrahedrom's name
* @param L: Line's name
*
* @return the closest point of contact between an tetrahedrom and a line if it exists
* @return a point with NaN coordinates if the point doesn't exist
*/
Point contactTetrahedromWithLine(Tetrahedrom T, Line L){
   // TODO: develop the function (with plane with 3 points & point of contact & first plane seen)
}


/**
* Encode an tetrahedrom as an array
*
* @param T: Tetrahedrom's name
*
* @return an array of double which contain the informations about the tetrahedrom
*/
double * encodeTetrahedrom(Tetrahedrom T){
    double tetrahedrom[12];
    tetrahedrom[0] = T.a.x;
    tetrahedrom[1] = T.a.y;
    tetrahedrom[2] = T.a.z;
    tetrahedrom[3] = T.b.x;
    tetrahedrom[4] = T.b.y;
    tetrahedrom[5] = T.b.z;
    tetrahedrom[6] = T.c.x;
    tetrahedrom[7] = T.c.y;
    tetrahedrom[8] = T.c.z;
    tetrahedrom[9] = T.d.x;
    tetrahedrom[10] = T.d.y;
    tetrahedrom[11] = T.d.z;


    return tetrahedrom;
}


/**
* Encode a tetrahedrom's array as a tetrahedrom structure
*
* @param tetrahedrom: Tetrahedrom array
*
* @return a tetrahedrom 
*/
Tetrahedrom decodeTetrahedrom(double * tetrahedrom){
    Tetrahedrom T;
    double tetrahedrom[12];
    T.a.x = tetrahedrom[0];
    T.a.y = tetrahedrom[1];
    T.a.z = tetrahedrom[2];
    T.b.x = tetrahedrom[3];
    T.b.y = tetrahedrom[4];
    T.b.z = tetrahedrom[5];
    T.c.x = tetrahedrom[6];
    T.c.y = tetrahedrom[7];
    T.c.z = tetrahedrom[8];
    T.d.x = tetrahedrom[9];
    T.d.y = tetrahedrom[10];
    T.d.z = tetrahedrom[11];

    return T;
}

