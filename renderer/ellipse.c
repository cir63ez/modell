#include "ellipse.h"


/**
* Give the point of contact between a line and an ellipse
*
* @param E: Ellipse's name
* @param B: Line's name
*
* @return the closest point of contact between an ellipse and a line if it exist
* @return a point with NaN coordinates if the point doesn't exist
*/
Point contactEllipseWithLine(Ellipse E, Line L){
    double A;
    double B;
    double C;
    double alpha;
    double beta;
    double delta;
    double gamma;
    double t;

    Point I;

    I.x = NaN;
    I.y = NaN;
    I.z = NaN;

    A = pow(E.a,2);
    B = pow(E.b,2);
    C = pow(E.c,2);

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
