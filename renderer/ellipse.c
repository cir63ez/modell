#include "ellipse.h"
#include "lib.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

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
    double alpha;
    double beta;
    double delta;
    double gamma;
    double t;

    Point I;

    I = initPointNaN();

    A = pow((E.a - E.x),2);
    B = pow((E.b - E.y),2);
    C = pow((E.c - E.z),2);

    alpha = pow(L.directionVector.x,2)/A + pow(L.directionVector.y,2)/B + pow(L.directionVector.z,2)/C;
    beta = (L.directionVector.x * L.pt.x)/A + (L.directionVector.y * L.pt.y)/B + (L.directionVector.z * L.pt.z)/C;
    gamma = (pow(L.pt.x,2)/A + pow(L.pt.y,2)/B + pow(L.pt.z,2)/C) - 1;

    delta = pow(beta,2) - 4 * alpha * gamma;

    if(delta < 0){
        return I;
    }

    if (delta > 0){
        t = (-2 * beta - sqrt(delta))/(2 * alpha);
    }

    if (delta == 0){
        t = - beta / alpha;
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
    ellipse = malloc(6 * sizeof(int));
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


Plane tangentePlaneEllipse(Ellipse E, Line L) {
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

