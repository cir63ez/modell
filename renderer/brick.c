#include "brick.h"
#include "list.h"
/**
* Verify if the brick could exist
*
* @param B: Brick's name
*
* @return 1 if it could exist
* @return 0 if it could not exist
*/
int DoesBrickExist(Brick B) {
    Plane PA;
    Plane PB;
    Plane PC;
    Plane PD;
    Plane PE;
    Plane PF;
    double test;

    PA = planeEquationFromPoints(B.a, B.b, B.c);
    PB = planeEquationFromPoints(B.b, B.c, B.g);
    PC = planeEquationFromPoints(B.a, B.b, B.e);
    PD = planeEquationFromPoints(B.a, B.e, B.d);
    PE = planeEquationFromPoints(B.h, B.g, B.c);
    PF = planeEquationFromPoints(B.e, B.h, B.g);


    if(!isPointOnPlane(B.d, PA)) {
        test++;
    }
    if(!isPointOnPlane(B.f, PB)) {
        test++;
    }
    if(!isPointOnPlane(B.f, PC)) {
        test++;
    }
    if(!isPointOnPlane(B.h, PD)) {
        test++;
    }
    if(!isPointOnPlane(B.d, PE)) {
        test++;
    }
    if(!isPointOnPlane(B.f, PF)) {
        test++;
    }
}



/**
* Give the point of contact between a line and a brick
*
* @param B: Brick's name
* @param L: Line's name
*
* @return the closest point of contact between an brick and a line if it exists
* @return a point with NaN coordinates if the point doesn't exist
*/
Point contactBrickWithLine(Brick B, Line L) {
    Plane PA;
    Plane PB;
    Plane PC;
    Plane PD;
    Plane PE;
    Plane PF;
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
    Point IE;
    Point IF;
    Point intersection;
    int testA;
    int testB;
    int testC;
    int testD;
    int testE;
    int testF;
    double nbPoint;
    double whichPlane;
    Point vertex[8];

    intersection = initPointNaN();

    vertex[0] = B.a;
    vertex[1] = B.b;
    vertex[2] = B.c;
    vertex[3] = B.d;
    vertex[4] = B.e;
    vertex[5] = B.f;
    vertex[6] = B.g;
    vertex[7] = B.h;

    nbPoint = 8;

    PA = planeEquationFromPoints(B.a, B.b, B.c);
    PB = planeEquationFromPoints(B.b, B.c, B.g);
    PC = planeEquationFromPoints(B.a, B.b, B.e);
    PD = planeEquationFromPoints(B.a, B.e, B.d);
    PE = planeEquationFromPoints(B.h, B.g, B.c);
    PF = planeEquationFromPoints(B.e, B.h, B.g);

    IA = pointIntersectionLineAndPlane(L, PA);
    IB = pointIntersectionLineAndPlane(L, PB);
    IC = pointIntersectionLineAndPlane(L, PC);
    ID = pointIntersectionLineAndPlane(L, PD);
    IE = pointIntersectionLineAndPlane(L, PE);
    IF = pointIntersectionLineAndPlane(L, PF);


    testA = isOnPolygon(vertex, nbPoint, IA);
    testB = isOnPolygon(vertex, nbPoint, IB);
    testC = isOnPolygon(vertex, nbPoint, IC);
    testD = isOnPolygon(vertex, nbPoint, ID);
    testE = isOnPolygon(vertex, nbPoint, IE);
    testF = isOnPolygon(vertex, nbPoint, IF);

    if(isPointNaN(IA)) {
        testA = 0;
    }
    if(isPointNaN(IB)) {
        testB = 0;
    }
    if(isPointNaN(IC)) {
        testC = 0;
    }
    if(isPointNaN(ID)) {
        testD = 0;
    }
    if(isPointNaN(IE)) {
        testE = 0;
    }
    if(isPointNaN(IF)) {
        testF = 0;
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
    if(testE != 0 && testA != 0) {
        firstPlaneF = firstPlaneSeen(L,PA,PE);
        intersection = pointIntersectionLineAndPlane(L, firstPlaneF);
    }
    if(testE != 0 && testB != 0) {
        firstPlaneF = firstPlaneSeen(L,PB,PE);
        intersection = pointIntersectionLineAndPlane(L, firstPlaneF);
    }
    if(testE != 0 && testC != 0) {
        firstPlaneF = firstPlaneSeen(L,PE,PC);
        intersection = pointIntersectionLineAndPlane(L, firstPlaneF);
    }
    if(testE != 0 && testD != 0) {
        firstPlaneF = firstPlaneSeen(L,PE,PD);
        intersection = pointIntersectionLineAndPlane(L, firstPlaneF);
    }
    if(testE != 0 && testF != 0) {
        firstPlaneF = firstPlaneSeen(L,PE,PF);
        intersection = pointIntersectionLineAndPlane(L, firstPlaneF);
    }
    if(testA != 0 && testF != 0) {
        firstPlaneF = firstPlaneSeen(L,PA,PF);
        intersection = pointIntersectionLineAndPlane(L, firstPlaneF);
    }
    if(testB != 0 && testF != 0) {
        firstPlaneF = firstPlaneSeen(L,PB,PF);
        intersection = pointIntersectionLineAndPlane(L, firstPlaneF);
    }
    if(testC != 0 && testF != 0) {
        firstPlaneF = firstPlaneSeen(L,PB,PF);
        intersection = pointIntersectionLineAndPlane(L, firstPlaneF);
    }
    if(testD != 0 && testF != 0) {
        firstPlaneF = firstPlaneSeen(L,PB,PF);
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
    if(testE){
        intersection = IE;
    }
    if(testF){
        intersection = IF;
    }
    return intersection;
}



/**
* Encode an brick as an array
*
* @param B: Brick's name
*
* @return an array of double which contain the informations about the brick
*/
double * encodeBrick(Brick B){
    double *brick;
    brick =(double*)malloc(6 * sizeof(double));
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
Brick decodeBrick(double *brick){
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
    free(brick);
    return B;
}

/**
* Checks if a point sees the light
*
* @param A: Object
* @param B: Light source
* @param C: contact points
*
* @return TRUE if the light cut an brick before point c
* @return FALSE if the light doesn't cut a brick before point c
*/

int testIfLightCutsBrick(double *object,Light Li,Point C) {
    Brick B;
    B = decodeBrick(object);
    Line L;
    L.pt = C;
    L.directionVector = pointsToVector(C, Li.lightSource);
    if(isPointNaN(contactBrickWithLine(B, L)) == TRUE) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

/**
* Create an Brick element for the list
* @param B: Brick's name
*
* @return an element Brick created
*/
Element * createElementBrick(Brick B) {
    Element * element = (Element *)malloc(sizeof(Element));
    if (element == NULL) {
       exit(-1);
       return NULL;
    }
    else {
        element->type = BRICK_TYPE;
        element->object = encodeBrick(B);
        element->next = NULL;
    }
}
