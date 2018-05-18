#include "lib.h"
#include "objects.h"

// List.c

/**
* Delete the last element of the list
* @param B: tete's list
*
* @return void
*/
void deleteElementList(List * list) {
    if(list->tete != NULL) {
        Element *previous = NULL;
        Element *current = list->tete;

        while(current->next != NULL) {
            previous = current;
            current = current->next;
        }

        if(previous != NULL) {
            previous->next = NULL;
        }

        free(current);
    }
}

// Brick.c

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
* Create a brick element for the list
* @param B: brick
*
* @return an element Brick created
*/
Element * createElementBrick(Brick B) {
    Element * element = (Element *)malloc(sizeof(Element));
    if (element == NULL) {
        exit(-1);
    }
    else {
        element->type = BRICK_TYPE;
        element->object = encodeBrick(B);
        element->next = NULL;
    }
}

// Ellipse.c

/**
* Give the point of contact between a line and an ellipse
*
* @param E: Ellipse's name
* @param B: Line's name
*
* @return the closest point of contact between an ellipse and a line if it exists
* @return a point with NaN coordinates if the point doesn't exist
*/
Point contactEllipseWithLine(Ellipse E, Line L) {
    double A;
    double B;
    double C;
    double delta;
    double t;

    Point I;

    I = initPointNaN();

    A = (pow(L.directionVector.x / E.a, 2) + pow(L.directionVector.y / E.b, 2) + pow(L.directionVector.z / E.c, 2));
    B = (L.directionVector.x * (L.pt.x - E.x)/pow(E.a,2) + L.directionVector.y * (L.pt.y - E.y)/pow(E.b,2) + L.directionVector.z * (L.pt.z - E.z)/pow(E.c,2));
    C = (pow((L.pt.x - E.x)/E.a,2) + pow((L.pt.y - E.y)/E.b,2)) + pow((L.pt.z - E.z)/E.c,2);

    delta = 4 * (pow(B,2) - A * C);

    if(delta < 0){
        return I;
    }

    if (delta > 0){
        t = (-2 * B - sqrt(delta))/(2 * A);
    }

    if (delta == 0){
        t = - B / A;
    }

    I.x = L.directionVector.x * t + L.pt.x;
    I.y = L.directionVector.y * t + L.pt.y;
    I.z = L.directionVector.z * t + L.pt.z;

    return I;
}


/**
* Encode an ellipse as an array
*
* @param E: Ellipse's name
*
* @return an array of double which contain the informations about the ellipse
*/
double * encodeEllipse(Ellipse E){
    double *ellipse;
    ellipse =(double*)malloc(6 * sizeof(double));
    ellipse[0] = E.a;
    ellipse[1] = E.b;
    ellipse[2] = E.c;
    ellipse[3] = E.x;
    ellipse[4] = E.y;
    ellipse[5] = E.z;
    return ellipse;
}


/**
* Encode an ellipse's array as a ellipse structure
*
* @param ellipse: Ellipse array
*
* @return an ellipse
*/
Ellipse decodeEllipse(double * ellipse){
    Ellipse E;
    E.a = ellipse[0];
    E.b = ellipse[1];
    E.c = ellipse[2];
    E.x = ellipse[3];
    E.y = ellipse[4];
    E.z = ellipse[5];
    free(ellipse);
    return E;
}


/**
* Get the tangent plane at the first point of intersection between a line and an Ellipse
*
*@param E : the Ellipse
*@param L : the Line
*
*@return the tangent plane
*/
Plane tangentPlaneEllipse(Ellipse E, Line L) {
    Point I;
    Vector normal;
    Plane tangent;

    I = contactEllipseWithLine(E, L);

    normal.x = 2 * (I.x - E.x) / (pow(E.a, 2));
    normal.y = 2 * (I.y - E.y) / (pow(E.b, 2));
    normal.z = 2 * (I.z - E.z) / (pow(E.c, 2));

    tangent.a = normal.x;
    tangent.b = normal.y;
    tangent.c = normal.z;
    tangent.x = I.x;
    tangent.y = I.y;
    tangent.z = I.z;

    return tangent;
}

/**
* Check if a point sees the light
*
* @param A: Object
* @param B: point of light
* @param C: contact points
*
* @return TRUE if the light cuts an ellipse before point c
* @return FALSE if the light doesn't cut an ellipse before point c
*/

int testIfLightCutsEllipse(double *object, Light Li, Point C){
    Ellipse E;
    E = decodeEllipse(object);
    Line L;
    L.pt = C;
    L.directionVector = pointsToVector(C, Li.lightSource);
    if(isPointNaN(contactEllipseWithLine(E, L))) {
        return TRUE;
    }
    else{
        return FALSE;
    }
}

/**
* Create an ellipse element for the list
* @param E: Ellipse's name
*
* @return an element ellipse created
*/
Element * createElementEllipse(Ellipse E) {
    Element * element = (Element *)malloc(sizeof(Element));
    if (element == NULL) {
        return NULL; //TODO: exit ?;
    }
    else {
        element->type = ELLIPSE_TYPE;
        element->object = encodeEllipse(E);
        element->next = NULL;
        return element;
    }
}


// Tetrahedron.c

/**
* Give the point of contact between a line and a tetrahedron
*
* @param T: Tetrahedron's name
* @param L: Line's name
*
* @return the closest point of contact between an tetrahedron and a line if it exists
* @return a point with NaN coordinates if the point doesn't exist
*/
Point contactTetrahedronWithLine(Tetrahedron T, Line L){
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
    double *tetrahedron;
    tetrahedron=(double*)malloc(12 * sizeof(double));
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
    free(tetrahedron);
    return T;
}


/**
* Check if a point sees the light
*
* @param A: Object
* @param B: Light source
* @param C: Contact points
*
* @return TRUE if the light cut a tetrahedron before point c
* @return FALSE if the light doesnt cut a tetrahedron before point c
*/

int testIfLightCutsTetrahedron(double *object, Light Li, Point C){
    Tetrahedron T;
    T = decodeTetrahedron(object);
    Line L;
    L.pt = C;
    L.directionVector = pointsToVector(C, Li.lightSource);
    if(isPointNaN(contactTetrahedronWithLine(T, L)) == TRUE) {
        return TRUE;
    }
    else{
        return FALSE;
    }
}

/**
* Create an tetrahedron element for the list
* @param T: tetrahedron's name
*
* @return an element Brick created
*/
Element * createElementTetrahedron(Tetrahedron T) {
    Element * element = (Element *)malloc(sizeof(Element));
    if (element == NULL) {
        return NULL; //TODO: exit ?;
    }
    else {
        element->type = TETRAHEDRON_TYPE;
        element->object = encodeTetrahedron(T);
        element->next = NULL;
    }
}