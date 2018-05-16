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
Toint contactTetrahedromWithLine(Tetrahedrom T, Line L){
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
    double tetrahedrom[8];
    tetrahedrom[0] = T.a;
    tetrahedrom[1] = T.b;
    tetrahedrom[2] = T.c;
    tetrahedrom[3] = T.d;

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
    double tetrahedrom[8];

    T.a = tetrahedrom[0];
    T.b = tetrahedrom[1];
    T.c = tetrahedrom[2];
    T.d = tetrahedrom[3];

    return T;
}

