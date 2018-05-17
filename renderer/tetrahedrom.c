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
Point contactTetrahedromFromLine(Tetrahedrom T, Line L){
    // TODO: develop the function (with plane with 3 points & on the polygon!!! & point of contact & first plane seen)
    Plane PA;
    Plane PB;
    Plane PC;
    Plane PD;
    Plane firstPlaneA;
    Plane firstPlaneB;
    Plane firstPlaneC;
    Plane firstPlaneD;
    Plane firstPlaneE;
    Plane firstPlaneF;
    Point IA;
    Point IB;
    Point IC;
    Point ID;
    Point intersection;
    int testA;
    int testB;
    int testC;
    int testD;
    double nbPoint;
    double whichPlane;
    Point vertex[4];

    intersection.x = NaN;

    vertex[0] = T.a;
    vertex[1] = T.b;
    vertex[2] = T.c;
    vertex[3] = T.d;
    nbPoint = 4;

    PA = planeEquationFromPoints(T.a,T.b,T.c);
    PB = planeEquationFromPoints(T.b,T.c,T.d);
    PC = planeEquationFromPoints(T.a,T.b,T.c);
    PD = planeEquationFromPoints(T.a,T.c,T.d);

    IA = pointIntersectionLineAndPlane(L,PA);
    IB = pointIntersectionLineAndPlane(L,PB);
    IC = pointIntersectionLineAndPlane(L,PC);
    ID = pointIntersectionLineAndPlane(L,PD);

    testB = isOnPolygon(vertex, nbPoint, IB);
    testC = isOnPolygon(vertex, nbPoint, IC);
    testD = isOnPolygon(vertex, nbPoint, ID);
    
    if(isPointNan(IA)) {
        testA = 0;
    }
    if(isPointNan(IB)) {
        testB = 0;
    }
    if(isPointNan(IC)) {
        testC = 0;
    }
    if(isPointNan(ID)) {
        testD = 0;
    }

    if(testA != 0 && testB != 0){
        firstPlaneA = firstPlaneSeen(L, PA, PB); 
        intersection = pointIntersectionLineAndPlane(L, firstPlaneA);
    } 
    if(testB != 0 && testC != 0){
        firstPlaneB = firstPlaneSeen(L,PB,PC);
        intersection = pointIntersectionLineAndPlane(L, firstPlaneB);
    }
    if(testC != 0 && testD != 0){
        firstPlaneC = firstPlaneSeen(L,PC,PD); 
        intersection = pointIntersectionLineAndPlane(L, firstPlaneC);
    }
    if(testC != 0 && testA != 0){
        firstPlaneD = firstPlaneSeen(L,PC,PA); 
        intersection = pointIntersectionLineAndPlane(L, firstPlaneD);
    }
    if(testD != 0 && testA != 0){
        firstPlaneE = firstPlaneSeen(L,PD,PA);
        intersection = pointIntersectionLineAndPlane(L, firstPlaneE);
    }
    if(testB != 0 && testD != 0){
        firstPlaneF = firstPlaneSeen(L,PB,PD);
        intersection = pointIntersectionLineAndPlane(L, firstPlaneF);
    }
    if(testA){
        intersection = IA;
    }
    if(testB){
        intersection = IB;
    }
    if(testC){
        intersection = IC;
    }
    if(testD){
        intersection = ID;
    }
    return intersection;
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

