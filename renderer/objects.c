#include "objects.h"

// List.c

/**
 * Initialized the list
 * @param L: list
 *
 * @return list
 */
List * initList() {
    List * L;
    L = (List *)malloc(sizeof(List));
    L->nbElement = 0;
    L->head = NULL;
    return L;
}

/**
* Add an element in the list
* @param e: element
*
* @return void
*/
void addElementList(Element * e, List * L) {
    Element * curElement;

    if(L->head == NULL) {
    Element *current;
    
    if(L->nbElement == 0 || L->head == NULL) {
        L->head = e;
    }
    else {
        curElement = L->head;
        while(curElement->next != NULL) {
            curElement = curElement->next;
    } else {
        current = L->head;
        while(current->next != NULL) {
            current = current->next;
        }
        curElement->next = e;

        current->next = e;
    }

    L->nbElement++;
}

/**
* Delete the last element of the list
* @param B: head's list
*
* @return void
*/
void deleteElementList(List * list) {
    if(list->head != NULL) {
        Element *previous = NULL;
        Element *current = list->head;

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
    Point faceA[4];
    Point faceB[4];
    Point faceC[4];
    Point faceD[4];
    Point faceE[4];
    Point faceF[4];

    intersection = initPointNaN();

    faceA[0] = B.a;
    faceA[1] = B.b;
    faceA[2] = B.c;
    faceA[3] = B.d;

    faceC[0] = B.a;
    faceC[1] = B.b;
    faceC[2] = B.e;
    faceC[3] = B.f;
    faceC[2] = B.f;
    faceC[3] = B.e;

    faceE[0] = B.d;
    faceE[1] = B.c;
    faceE[2] = B.g;
    faceE[3] = B.h;

    faceB[0] = B.b;
    faceB[1] = B.c;
    faceB[2] = B.f;
    faceB[3] = B.g;
    faceB[2] = B.g;
    faceB[3] = B.f;

    faceF[0] = B.e;
    faceF[1] = B.f;
    faceF[2] = B.g;
    faceF[3] = B.h;

    faceD[0] = B.a;
    faceD[1] = B.d;
    faceD[2] = B.e;
    faceD[3] = B.h;
    faceD[2] = B.h;
    faceD[3] = B.e;

    nbPoint = 4;

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

    testA = isOnPolygonLilianMethod(faceA, nbPoint, IA);
    testB = isOnPolygonLilianMethod(faceB, nbPoint, IB);
    testC = isOnPolygonLilianMethod(faceC, nbPoint, IC);
    testD = isOnPolygonLilianMethod(faceD, nbPoint, ID);
    testE = isOnPolygonLilianMethod(faceE, nbPoint, IE);
    testF = isOnPolygonLilianMethod(faceF, nbPoint, IF);

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
        return intersection;
    }
    if(testB != 0 && testC != 0){
        firstPlaneB = firstPlaneSeen(L,PB,PC);
        intersection = pointIntersectionLineAndPlane(L, firstPlaneB);
        return intersection;
    }
    if(testC != 0 && testD != 0){
        firstPlaneC = firstPlaneSeen(L,PC,PD);
        intersection = pointIntersectionLineAndPlane(L, firstPlaneC);
        return intersection;
    }
    if(testC != 0 && testA != 0){
        firstPlaneD = firstPlaneSeen(L,PC,PA);
        intersection = pointIntersectionLineAndPlane(L, firstPlaneD);
        return intersection;
    }
    if(testD != 0 && testA != 0){
        firstPlaneE = firstPlaneSeen(L,PD,PA);
        intersection = pointIntersectionLineAndPlane(L, firstPlaneE);
        return intersection;
    }
    if(testB != 0 && testD != 0){
        firstPlaneF = firstPlaneSeen(L,PB,PD);
        intersection = pointIntersectionLineAndPlane(L, firstPlaneF);
        return intersection;
    }
    if(testE != 0 && testA != 0) {
        firstPlaneF = firstPlaneSeen(L,PA,PE);
        intersection = pointIntersectionLineAndPlane(L, firstPlaneF);
        return intersection;
    }
    if(testE != 0 && testB != 0) {
        firstPlaneF = firstPlaneSeen(L,PB,PE);
        intersection = pointIntersectionLineAndPlane(L, firstPlaneF);
        return intersection;
    }
    if(testE != 0 && testC != 0) {
        firstPlaneF = firstPlaneSeen(L,PE,PC);
        intersection = pointIntersectionLineAndPlane(L, firstPlaneF);
        return intersection;
    }
    if(testE != 0 && testD != 0) {
        firstPlaneF = firstPlaneSeen(L,PE,PD);
        intersection = pointIntersectionLineAndPlane(L, firstPlaneF);
        return intersection;
    }
    if(testE != 0 && testF != 0) {
        firstPlaneF = firstPlaneSeen(L,PE,PF);
        intersection = pointIntersectionLineAndPlane(L, firstPlaneF);
        return intersection;
    }
    if(testA != 0 && testF != 0) {
        firstPlaneF = firstPlaneSeen(L,PA,PF);
        intersection = pointIntersectionLineAndPlane(L, firstPlaneF);
        return intersection;
    }
    if(testB != 0 && testF != 0) {
        firstPlaneF = firstPlaneSeen(L,PB,PF);
        intersection = pointIntersectionLineAndPlane(L, firstPlaneF);
        return intersection;
    }
    if(testC != 0 && testF != 0) {
        firstPlaneF = firstPlaneSeen(L,PB,PF);
        intersection = pointIntersectionLineAndPlane(L, firstPlaneF);
        return intersection;
    }
    if(testD != 0 && testF != 0) {
        firstPlaneF = firstPlaneSeen(L,PB,PF);
        intersection = pointIntersectionLineAndPlane(L, firstPlaneF);
        return intersection;
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
    brick =(double*)malloc(27 * sizeof(double));
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
    brick[24] = B.color.red;
    brick[25] = B.color.green;
    brick[26] = B.color.blue;
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
    B.color.red =   brick[24];
    B.color.green = brick[25];
    B.color.blue =  brick[26];
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
        return FALSE;
    }
    else {
        return TRUE;
    }
}

/**
* Create a brick element for the list
* @param B: brick
*
* @return an element Brick created
*/
Element * createElementBrick(double * B) {
    Element * element = (Element *)malloc(sizeof(Element));
    if (element == NULL) {
        exit(0);
    }
    else {
        element->type = BRICK_TYPE;
        element->object = B;
        element->next = NULL;
    }
    return element;
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
    double B2;
    double C;
    double delta;
    double t;
    double t2;
    double norm1;
    double norm2;
    Point I;
    Point I2;
    Vector V1;
    Vector V2;

    I = initPointNaN();

    A = (pow(L.directionVector.x / E.a, 2) + pow(L.directionVector.y / E.b, 2) + pow(L.directionVector.z / E.c, 2));
    B2 = (L.directionVector.z * (L.pt.z - E.z)) / pow(E.c, 2);
    B = (L.directionVector.x * (L.pt.x - E.x)) / pow(E.a, 2) + (L.directionVector.y * (L.pt.y - E.y))/pow(E.b, 2) + B2;
    B = 2 * B;
    C = pow((L.pt.x - E.x) / E.a, 2) + pow((L.pt.y - E.y) / E.b, 2) + pow((L.pt.z - E.z) / E.c, 2) - 1;

    delta = (pow(B,2) - 4 * A * C);

    if(delta  < 0){
        return I;
    }
    else{
        if (delta >= 0){

            t = (- B - sqrt(delta))/(2 * A);
            t2 = (- B + sqrt(delta))/(2 * A);
            if(t < 0 && t2 < 0) {
                return I;
            }
            if(t < 0) {
                t = t2;
            }

            I.x = L.directionVector.x * t + L.pt.x;
            I.y = L.directionVector.y * t + L.pt.y;
            I.z = L.directionVector.z * t + L.pt.z;

            I2.x = L.directionVector.x * t2 + L.pt.x;
            I2.y = L.directionVector.y * t2 + L.pt.y;
            I2.z = L.directionVector.z * t2 + L.pt.z;

            V1 = pointsToVector(L.pt, I);
            V2 = pointsToVector(L.pt, I2);
            norm1 = norm(V1);
            norm2 = norm(V2);

            if (norm1 > norm2){
                t = t2;
            }

        }

    }

    if(t < 0){
        return I;
    }
    else{
        I.x = L.directionVector.x * t + L.pt.x;
        I.y = L.directionVector.y * t + L.pt.y;
        I.z = L.directionVector.z * t + L.pt.z;
        return I;
    }

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
    ellipse =(double*)malloc(9 * sizeof(double));
    ellipse[0] = E.a;
    ellipse[1] = E.b;
    ellipse[2] = E.c;
    ellipse[3] = E.x;
    ellipse[4] = E.y;
    ellipse[5] = E.z;
    ellipse[6] = E.color.red;
    ellipse[7] = E.color.green;
    ellipse[8] = E.color.blue;
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
    E.color.red   = ellipse[6];
    E.color.green = ellipse[7];
    E.color.blue  = ellipse[8];
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
        return FALSE;
    }
    else{
        return TRUE;
    }
}

/**
* Create an ellipse element for the list
* @param E: Ellipse's name
*
* @return an element ellipse created
*/
Element * createElementEllipse(double * E) {
    Element * element = (Element *)malloc(sizeof(Element));

    if (element == NULL) {
        exit(0);
    }
    else {
        element->type = ELLIPSE_TYPE;
        element->object = E;
        element->next = NULL;
    }

    return element;
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
    Point faceA[3];
    Point faceB[3];
    Point faceC[3];
    Point faceD[3];

    intersection = initPointNaN();

    vertex[0] = T.a;
    vertex[1] = T.b;
    vertex[2] = T.c;
    vertex[3] = T.d;
    faceA[0] = T.a;
    faceA[1] = T.b;
    faceA[2] = T.c;

    faceB[0] = T.d;
    faceB[1] = T.b;
    faceB[2] = T.c;

    faceC[0] = T.a;
    faceC[1] = T.b;
    faceC[2] = T.d;

    faceD[0] = T.a;
    faceD[1] = T.d;
    faceD[2] = T.c;
    
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
    testA = isOnPolygon(faceA, nbPoint, IA);
    testB = isOnPolygon(faceB, nbPoint, IB);
    testC = isOnPolygon(faceC, nbPoint, IC);
    testD = isOnPolygon(faceD, nbPoint, ID);

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
    tetrahedron=(double*)malloc(15 * sizeof(double));
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
    tetrahedron[12] = T.color.red;
    tetrahedron[13] = T.color.green;
    tetrahedron[14] = T.color.blue;
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
    T.color.red   = tetrahedron[12];
    T.color.green = tetrahedron[13];
    T.color.blue  = tetrahedron[14];
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
Element * createElementTetrahedron(double * T) {
    Element * element = (Element *)malloc(sizeof(Element));
    if (element == NULL) {
        exit(0);
    }
    else {
        element->type = TETRAHEDRON_TYPE;
        element->object = T;
        element->next = NULL;
    }
}


//LIGHTS

/**
* Encode a light's array as a light structure
*
* @param light: Light array
*
* @return a light
*/
Light decodeLight(double * light){
    Light L;
    L.lightSource.x = light[0];
    L.lightSource.y = light[1];
    L.lightSource.z = light[2];
    return L;
}

/**
* Encode a light as an array
*
* @param L: Light's name
*
* @return an array of double which contain the informations about the light
*/
double * encodeLight(Light L){
    double *light;
    light = (double*)malloc(3 * sizeof(double));
    light[0] = L.lightSource.x;
    light[1] = L.lightSource.y;
    light[2] = L.lightSource.z;

    return light;
}

/**
* Create a light element for the list
* @param L: light
*
* @return an element Light created
*/
Element * createElementLight(double * L) {
    Element * element = (Element *)malloc(sizeof(Element));
    if (element == NULL) {
        exit(0);
    }
    else {
        element->type = LIGHT_TYPE;
        element->object = L;
        element->next = NULL;
    }
}

/**
* Give the intersection point between two lines
*
* @param L: First line
* @param D: Second line
*
* @return an intersection point
*/
Point pointIntersectionLineAndLine(Line L, Line D) {
    double t;
    double tA;
    double nominator;
    double denominator;
    Point I;

    I = initPointNaN();

    nominator = ((D.directionVector.y *(L.pt.x - D.pt.x) / D.directionVector.x) + D.pt.y - L.pt.y);
    denominator = (L.directionVector.y - (D.directionVector.y * L.directionVector.x) / D.directionVector.x);

    if(denominator == 0 || D.directionVector.x == 0) {
        return I;
    }

    t = nominator / denominator;
    tA = (L.directionVector.x * t + L.pt.x - D.pt.x) / D.directionVector.x;

    if(!FEQUAL((L.directionVector.z * t + L.pt.z), (D.directionVector.z * tA + D.pt.z))) {
        return I;
    }
    else {
        I.x = L.directionVector.x * t + L.pt.x;
        I.y = L.directionVector.y * t + L.pt.y;
        I.z = L.directionVector.z * t + L.pt.z;
        return I;
    }
}

/**
* Test if two points are equal
* @param O: First point
* @param I: Second point
*
* @return 1 if they are equals
* @return 0 if there aren't
*/
int arePointsEqual(Point O, Point I) {
    if(FEQUAL(O.x, I.x) && FEQUAL(O.y, I.y) && FEQUAL(O.z, I.z)) {
        return TRUE;
    }
    else {
        return FALSE;
    if(FEQUAL(O.x, I.x)) {
        if(FEQUAL(O.y, I.y)) {
            if(FEQUAL(O.z, I.z)) {
                return TRUE;
            }
        }
    }

    return FALSE;
}

/**
* Give a vector in a plane
* @param O: Point
* @param P: Plane
*
* @return a vector in the plane
*/
Vector vectorInPlane(Point O, Plane P) {
    Point I;
    Vector V;

    I.x = P.x;
    I.y = P.y;
    I.z = P.z;

    if(arePointsEqual(O,I)) {
        V = pointsToVector(O,I);
        return V;
    }

    V = initVectorNaN();

    if(P.c != 0) {
        I.x = 1;
        I.y = 1;
        I.z = (P.a * (I.x - P.x) + P.b * (I.y - P.y) - P.c * P.z) / P.c;
        V = pointsToVector(O,I);
        return V;
    }
    else if(P.a != 0) {
        I.y = 1;
        I.z = 1;
        I.x = (- P.a * P.x + P.b * (I.y - P.y) + P.c * (I.z - P.z)) / P.a;
        V = pointsToVector(O,I);
        return V;
    }
    else if(P.b != 0) {
        I.x = 1;
        I.z = 1;
        I.y = (P.a * (I.x - P.x) - P.b * P.y + P.c * (I.z - P.z)) / P.b;
        V = pointsToVector(O,I);
        return V;
    }

    return V;

}

/**
* Give the intersection point between a line and a segment
*
* @param A: First point of the segment
* @param A: Second point of the segment
* @param L: Line
*
* @return an intersection point
*/
Point pointIntersectionLineAndSegment(Point A, Point B, Line L) {
    Line D;
    Vector AB;
    Vector IA;
    Vector IB;
    Point I;
    double normIA;
    double normIB;
    double normAB;

    AB = pointsToVector(A, B);

    D.pt = A;
    D.directionVector = AB;

    I = pointIntersectionLineAndLine(L, D);

    if(isPointNaN(I)){
        return I;
    }

    IA = pointsToVector(I, A);
    IB = pointsToVector(I, B);

    normIA = norm(IA);
    normIB = norm(IB);
    normAB = norm(AB);


    if(FEQUAL(normIA + normIB, normAB)) {
        return I;
    }
    else {
        I = initPointNaN();
        return I;
    }
}


/**
* Check if the point is on the polygon
*
* @param list: List of points
* @param numberOfPoint: Number of points
* @param test: Test point
*
* @return void
* @return 1 if the point is on the polygon
* @return 0 if the point is not on the polygon
*/
int isOnPolygon(Point *list, double numberOfPoint, Point test) {
    Vector V;
    //Vector negativeV;
    Plane P;
    Line L;
    //Line LB;
    Point I;
    //Point IB;
    int nbIntersection = 0;
    int cpt = 0;

    P = planeEquationFromPoints(list[0], list[1], list[2]);
    V = vectorInPlane(test, P);

    //negativeV.x = - V.x;
    //negativeV.y = - V.y;
    //negativeV.z = - V.z;

    L.pt = test;
    L.directionVector = V;
    //LB.pt = test;
    //LB.directionVector = negativeV;

    for(int i = 0; i < numberOfPoint; i++) {
        I = pointIntersectionLineAndSegment(list[i], list[i + 1], L);
        //IB = pointIntersectionLineAndSegment(list[i], list[i + 1], LB);

        //if(!isPointNaN(I) || !isPointNaN(IB)) {
        if(!isPointNaN(I)) {
            nbIntersection++;
        }
        cpt++;
    }

    I = pointIntersectionLineAndSegment(list[0], list[cpt - 1], L);
    //IB = pointIntersectionLineAndSegment(list[0], list[cpt - 1], LB);

    //if(!isPointNaN(I) || !isPointNaN(IB)) {
    if(!isPointNaN(I)) {
            nbIntersection++;
    }

    //printf("%d\n", nbIntersection);

    //if(nbIntersection == 2){
    if(nbIntersection % 2 == 1) {
        return TRUE;
    }
    return FALSE;
}



/**
* Check if the point is on the polygon with the angle method
*
* @param list: List of points
* @param numberOfPoint: Number of points
* @param test: Test point
*
* @return void
* @return 1 if the point is on the polygon
* @return 0 if the point is not on the polygon
*/
int isOnPolygonAngleMethod(Point *list, double numberOfPoint, Point I) {
    Vector V;
    Point A;
    Point B;
    Vector VA;
    Vector VB;
    Plane P;
    Line L;
    double teta;
    double sum = 0;
    int cpt = 0;

    double sum;
    
    for(int i = 0; i < numberOfPoint; i++) {
        cpt++;
        A = list[i];
        B = (i == numberOfPoint - 1) ? list[0] : list[i + 1];
        

        if(arePointsEqual(I, A)) {return TRUE;}
        if(arePointsEqual(I, B)) {return TRUE;}


        if(!isPointNaN(I)) {
            V = pointsToVector(I, list[i]);
            VB = pointsToVector(I, list[i + 1]);
            Vector VA = pointsToVector(I, A);
            Vector VB = pointsToVector(I, B);

            teta = angle(V, VB);
            teta = angle(VA, VB);

            if(isnan(teta)) {
                return FALSE;
            }
            else {
                sum = sum + teta;
            }
            if(isnan(teta)) {return FALSE;}

            sum += teta;
        }
    }
    
    if(!isPointNaN(I)) {
        V = pointsToVector(I, list[cpt]);
        VB = pointsToVector(I, list[0]);

        teta = angle(V, VB);
    return (FEQUAL(sum, 2 * _PI)) ? TRUE : FALSE;
}

        if(isnan(teta)) {
            return FALSE;
/**
* Check if the point is on the polygon with the angle method of Lilian
*
* @param list: List of points
* @param numberOfPoint: Number of points
* @param test: Test point
*
* @return 1 if the point is on the polygon
* @return 0 if the point is not on the polygon
*/
int isOnPolygonLilianMethod(Point *list, double numberOfPoint, Point I) {
  Vector A;
  Vector B;
  double sum = 0;
  int nbVertex;
  nbVertex = (int)numberOfPoint;

  if(isPointNaN(I) ==  FALSE) {
    for(int i = 0; i < numberOfPoint; i++){
        A = pointsToVector(I, list[i]);
        
        if(arePointsEqual(I, list[i])) {
            return TRUE;
        }
        else {
            sum = sum + teta;

      if(i == nbVertex - 1){
        A = pointsToVector(I, list[0]);
        
        if(arePointsEqual(I, list[0])) {
            return TRUE;
        }
    }

//    sum = sum/(2 * _PI);
      }
      else{
        B = pointsToVector(I, list[i + 1]);

    if (sum > 0.1) {  //1.0471975511965976
    //if(sum != 0) {
        return TRUE;
    }
    else {
        return FALSE;
        if(arePointsEqual(I, list[i + 1])) {
            return TRUE;
        }

      }
      sum = sum + angle(A,B);
    }
  } 

  if(FEQUAL(sum, 2 * _PI)){
    return TRUE;
  }
  return FALSE;
}
