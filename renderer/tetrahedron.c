#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "tetrahedron.h"

/**
* Give the point of contact between a line and a tetrahedron
*
* @param T: Tetrahedron's name
* @param L: Line's name
*
* @return the closest point of contact between an tetrahedron and a line if it exists
* @return a point with NaN coordinates if the point doesn't exist
*/
Point contactTetrahedronFromLine(Tetrahedron T, Line L){
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

    intersection = initPointNaN();

    vertex[0] = T.a;
    vertex[1] = T.b;
    vertex[2] = T.c;
    vertex[3] = T.d;
    nbPoint = 4;

    PA = planeEquationFromPoints(T.a,T.b,T.c);
    PB = planeEquationFromPoints(T.b,T.c,T.d);
    PC = planeEquationFromPoints(T.a,T.b,T.d);
    PD = planeEquationFromPoints(T.a,T.c,T.d);

    IA = pointIntersectionLineAndPlane(L,PA);
    IB = pointIntersectionLineAndPlane(L,PB);
    IC = pointIntersectionLineAndPlane(L,PC);
    ID = pointIntersectionLineAndPlane(L,PD);

    testA = isOnPolygon(vertex, nbPoint, IA);
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
* Encode an tetrahedron as an array
*
* @param T: Tetrahedron's name
*
* @return an array of double which contain the informations about the tetrahedron
*/
double * encodeTetrahedron(Tetrahedron T){
    double tetrahedron[12];
    tetrahedron[0] = T.a.x;
    tetrahedron[1] = T.a.y;
    tetrahedron[2] = T.a.z;
    tetrahedron[3] = T.b.x;
    tetrahedron[4] = T.b.y;
    tetrahedron[5] = T.b.z;
    tetrahedron[6] = T.c.x;
    tetrahedron[7] = T.c.y;
    tetrahedron[8] = T.c.z;
    tetrahedron[9] = T.d.x;
    tetrahedron[10] = T.d.y;
    tetrahedron[11] = T.d.z;


    return tetrahedron;
}


/**
* Encode a tetrahedron's array as a tetrahedron structure
*
* @param tetrahedron: Tetrahedron array
*
* @return a tetrahedron 
*/
Tetrahedron decodeTetrahedron(double * tetrahedron){
    Tetrahedron T;
    T.a.x = tetrahedron[0];
    T.a.y = tetrahedron[1];
    T.a.z = tetrahedron[2];
    T.b.x = tetrahedron[3];
    T.b.y = tetrahedron[4];
    T.b.z = tetrahedron[5];
    T.c.x = tetrahedron[6];
    T.c.y = tetrahedron[7];
    T.c.z = tetrahedron[8];
    T.d.x = tetrahedron[9];
    T.d.y = tetrahedron[10];
    T.d.z = tetrahedron[11];

    return T;
}

