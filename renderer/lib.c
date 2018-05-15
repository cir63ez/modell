#include <math.h>
#include "lib.h"

/**
* Calculate a vector with from two points
*
* @param A: First point's name
* @param B: Second point's name
*                    ->
* @return the vector AB
*/
Vector pointsToVector(Point A, Point B) {
    Vector V;

    V.x = B.x - A.x;
    V.y = B.y - A.y;
    V.z = B.z - A.z;

    return V;
}

/**
* Calculate the sum of two vectors
*
* @param A: First vector's name
* @param B: Second vector's name
*
* @return the sum of the vectors
*/
Vector sumVectors(Vector A, Vector B) {
    Vector V;

	V.x = A.x + B.x;
    V.y = A.y + B.y;
    V.z = A.z + B.z;

    return V;
}

/**
* Calculate the difference of two vectors
*
* @param A: First vector's name
* @param B: Second vector's name
*
* @return the difference between the vectors
*/
Vector differenceVectors(Vector A, Vector B) {
    Vector V;

    V.x = A.x - B.x;
    V.y = A.y - B.y;
    V.z = A.z - B.z;

    return V;
}

/**
* Calculate the scalarProduct of two vectors
*
* @param A: First vector's name
* @param B: Second vector's name
*
* @return the scalar product
*/
double scalarProduct(Vector A, Vector B) {
    double scalar;

    scalar = A.x * B.x + A.y * B.y + A.z * B.z;

    return scalar;
}

/**
* Calculate the norm of a vector
*
* @param A: Vector's name
*
* @return the norm of the vector
*/
double norm(Vector A) {
    return (sqrt(pow(A.x,2) + pow(A.y,2) + pow(A.z,2)));
}


/**
* Calculate the angle between two vectors
*
* @param A: First vector's name
* @param B: Second vector's name
*
* @return the angle between the vector
*/
double angle(Vector AB, Vector AC) {
    double productABAC;
    double normAB;
    double normAC;
    double test;

	productABAC = scalarProduct(AB,AC);
    normAB = norm(AB);
    normAC = norm(AC);

    if(normAB == 0 || normAC == 0) {
    	printf("TODO: Error div by 0");
    	return 0;
    }

    test = productABAC/(normAB * normAC);

    if (test > 1 || test < -1){
        printf("TODO: Fix test not in range (-1,1)");
        return 0;
    }

    return acos(productABAC/(normAB * normAC));
}

/**
* Verify if 3 points are aligned
*
* @param A: First point's name
* @param B: Second point's name
* @param C: Third point's name
*
* @return TRUE if the 3 points are aligned
* @return FALSE if the 3 points are not aligned
*/
char arePointsAligned(Point A, Point B, Point C) {
	Vector AB;
	Vector AC;
	double scalar;
    double angleCos;

    AB = pointsToVector(A,B);
    AC = pointsToVector(A,C);
    scalar = scalarProduct(AB,AC);
    angleCos = scalar/(norm(AB)*norm(AC));

    if(FEQUAL(norm(AB)*norm(AC))) {return FALSE;}

    if(FEQUAL(angleCos, 1) || FEQUAL(angleCos, -1)) {
        return TRUE;
    }

    return FALSE;
}

/**
* Calculate a normal vector with 3 points
*
* @param A: First point's name
* @param B: Second point's name
* @param C: Third point's name
*
* @return a vector normal of a plan if the 3 points are not aligned
* @return the nul vector if the 3 points are aligned
*/
Vector normalVector(Point A, Point B, Point C) {
    Vector V;

    V.x = NaN;
    V.y = NaN;
    V.z = NaN;

    if (arePointsAligned(A,B,C)) {
        printf("We can't make a plan equation with 3 aligned points");
    } else {
        V.x = ((B.y - A.y)*(C.z - A.z)-(B.z - A.z)*(C.y - A.y));
        V.y = -((B.x - A.x)*(C.z - A.z)-(B.z - A.z)*(C.x - A.x));
        V.z = ((B.x - A.x)*(C.y - A.y)-(B.y - A.y)*(C.x - A.x));
    }

    return V;
}

/**
* Calculate a plan equation 3 points
*
* @param A: First point's name
* @param B: Second point's name
* @param C: Third point's name
*
* @return the equation of the plan formed by the 3 points non aligned
* @return a plan with nul coefficient if the 3 points are aligned
*/
Plane planEquationWithPoints(Point A, Point B, Point C) {
    Plane P;
    Vector V;

    P.a = 0;
    P.b = 0;
    P.c = 0;
    P.d = 0;

    if (arePointsAligned(A,B,C)){
        printf("We can't make a plan equation with 3 aligned points");
    } else {
        V = normalVector(A,B,C);
        
        P.a = V.x;
        P.b = V.y;
        P.c = V.z;
        P.d = P.a * A.x + P.b * A.y + P.c * A.z;
    }

    return P;
}

/**
* Calculate a plan equation 3 points
*
* @param O: Observateur point
* @param B: Object point's name
* @param Q: Plane's name
*
* @return the position of the  object's image on a plane*/
Point imagePointOnPlane(Point O, Point B, Plane P, Plane Q) {
    Point I;
    double t;
    double denominator;
    double nominator;

    I.x = 0./0.;
    I.y = 0./0.;
    I.z = 0./0.;

    t = 0;
    denominator = 0;
    nominator = 0;
    nominator = Q.a * B.x + Q.b * O.y + Q.c * O.z + Q.d;
    denominator = Q.a * (B.x - O.x) + Q.b * (B.y - O.y)  + Q.c * (B.z - O.z);

    if(denominator == 0){
        return I;
    } else {
        t = - nominator/denominator;
        if(t < 0){
            return I;
        }
        else {
            I.x = (B.x - O.x) * t + O.x;
            I.y = (B.y - O.y) * t + O.y;
            I.z = (B.z - O.z) * t + O.z;

            return I;
        }
    }
}
