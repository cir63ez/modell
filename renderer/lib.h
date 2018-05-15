#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Defines

#define TRUE 1
#define FALSE 0
#define NaN 0./0.

#define FEQUAL_LIMIT 0.0000000001
#define FEQUAL(A, B) (fabs(A - B) < FEQUAL_LIMIT) ? TRUE : FALSE

// Structures

typedef struct Point_ {
    double x;
    double y;
    double z;
} Point;

typedef struct Vector_ {
    double x;
    double y;
    double z;
} Vector;

typedef struct Line_ {
    Point pt;
    Vector directionVector;
} Line;

typedef struct Rgb_ {
    int red;
    int green;
    int blue;
} Rgb;

typedef struct Plane_ {
    double a;
    double b;
    double c;
    double d;
} Plane;

typedef struct Pixel_ {
    int x;
    int y;
    Rgb color;
} Pixel;

// Functions
// Calculate a vector with from two points
Vector pointsToVector(Point A, Point B);

// Calculate the sum of two vectors
Vector sumVectors(Vector A, Vector B);

// Calculate the difference of two vectors
Vector differenceVectors(Vector A, Vector B);

// Calculate the scalar product of two vectors
double scalarProduct(Vector A, Vector B);

// Calculate the norm of two vector 
double norm(Vector A);

// Calculate the angle between two vectors
double angle(Vector AB, Vector AC);

// Verify if 3 points are aligned
char arePointsAligned(Point A, Point B, Point C);

// Calculate a normal vector with 3 points
Vector normalVector(Point A, Point B, Point C);

// Calculate the equation of a plane with 3 points
Plane planEquationWithPoints(Point A, Point B, Point C);

// Calculate the image of an  object on a plane
Point imagePointOnPlane(Point O, Point B, Plane P, Plane Q);

// Calculate the intersection point between a line and a plane
Point pointIntersectionLineAndPlane(Line L, Plane P);

// Give the first plan that the observator sees
Point firstPlaneSeen(Point O, vector direction, Plane P, Plane Q);